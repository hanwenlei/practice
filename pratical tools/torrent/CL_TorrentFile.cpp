#include<cstdio>
#include<memory.h>
#include<ctype.h>
#include"CL_TorrentFile.h"

CL_TorrentFile::CL_TorrentFile(char* name):m_pFileContent(0), m_position(0), m_FileSize(0), m_ptree(0)
{
	long int i = 0;
    FILE *fp = fopen(name, "rb");
    if(fp == NULL) 
    {
    	#if DEBUG
        printf("文件打开失败!\n");
        #endif
        throw("文件打开失败!\n");
        return;
    }
    
    fseek(fp, 0, SEEK_END);
	m_FileSize = ftell(fp);
	if(m_FileSize < 0)
    {
    	#if DEBUG
        printf("fseek failed!\n");
        #endif
        throw("fseek failed!\n");
        return;
    }

	m_pFileContent = new char[m_FileSize + 1];
	if(m_pFileContent == NULL)
    {
    	#if DEBUG
        printf("malloc failed\n");
        #endif
        throw("malloc failed\n");
        return;
    }

    fseek(fp, 0, SEEK_SET);
	fread(m_pFileContent, sizeof(char), m_FileSize + 1, fp);
	if(fp)
	{
		fclose(fp);
	}
	#ifdef DEBUG
    printf("file size is : %d\n", m_FileSize);
	#endif
}

bool CL_TorrentFile::IsEnd()
{
	if(m_position >= m_FileSize)
	{
		return true;
	}
	else if(m_pFileContent[m_position] == 'e')
	{
		m_position++;
		return true;
	}
	else
	{
		return false;
	}
}

CL_TorrentTree* CL_TorrentFile::AddNode()
{
	if(IsEnd())
	{
		m_ptree = NULL;
	}
	else if(m_pFileContent[m_position] == 'd')
	{
		m_position++;
		m_ptree = AddDirect();
	}
	else if(m_pFileContent[m_position] == 'l')
	{
		m_position++;
		m_ptree = AddList();
	}
	else if(m_pFileContent[m_position] == 'i')
	{
		m_position++;
		m_ptree = AddInt();
	}
	else
	{
		m_ptree = AddString();
	}
	return m_ptree;
}

CL_TorrentTree* CL_TorrentFile::AddDirect()
{
	if(IsEnd())
	{
		return NULL;
	}
	CL_TorrentTree* key = AddNode();
	CL_TorrentTree* value = AddNode();
	CL_TorrentTree* next = AddDirect();
	CL_TorrentTree* ptr = new CL_TorrentTree(*key, *value, *next);
	return ptr;
}

CL_TorrentTree* CL_TorrentFile::AddList()
{
	if(IsEnd())
	{
		return NULL;
	}
	CL_TorrentTree* value = AddNode();
	CL_TorrentTree* next = AddList();
	CL_TorrentTree* ptr = new CL_TorrentTree(*value, *next);
	return ptr;
}

CL_TorrentTree* CL_TorrentFile::AddString()
{
	if(m_position >= m_FileSize)
	{
		return NULL;
	}
	int length = 0;
	CL_TorrentTree* ptr = NULL;
	while(isdigit(m_pFileContent[m_position]))
	{ 
		length = length * 10 + (m_pFileContent[m_position] - '0');
		m_position++;
	}
	if(length != 0)
	{
		m_position++; //跳过冒号
		char* value;
		memcpy(value, (m_pFileContent + m_position), length);
		value[length] = '\0';
		m_position += length;
		ptr = new CL_TorrentTree(value, length);
	}
	return ptr;
}

CL_TorrentTree* CL_TorrentFile::AddInt()
{
	if(m_position >= m_FileSize)
	{
		return NULL;
	}
	int value = 0;			
	while(isdigit(m_pFileContent[m_position]))
	{
		value = value * 10 + (m_pFileContent[m_position] - '0');
		m_position++;
	}
	m_position++; //跳过冒号
	CL_TorrentTree* ptr = new CL_TorrentTree(value);
	return ptr;
}

int CL_TorrentFile::PrintTree()
{
	if(m_ptree == NULL)
	{
		return -1;
	}
	m_ptree->PrintTree();
	return 0;
}

CL_TorrentFile::~CL_TorrentFile()
{
	delete [] m_pFileContent;
	delete m_ptree;
}