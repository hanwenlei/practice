#include<cstdio>
#include<cstring>
#include"CL_StringNode.h"

CL_StringNode::CL_StringNode(char* value, int length):m_length(length)
{
	m_pstring = new char[length + 1];
	strcpy(m_pstring, value);
}

int CL_StringNode::PrintFunc()
{
	printf("string : %d : %s\n", m_length, m_pstring);
	return 0;
}

CL_StringNode::~CL_StringNode()
{
	delete [] m_pstring;
}