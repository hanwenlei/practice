#include"CL_TorrentTree.h"
#include"CL_IntNode.h"
#include"CL_StringNode.h"
#include"CL_ListNode.h"
#include"CL_DirectNode.h"

CL_TorrentTree::CL_TorrentTree(int value)
{
	m_pnode = new CL_IntNode(value);
}

CL_TorrentTree::CL_TorrentTree(char* value, int length)
{
	m_pnode = new CL_StringNode(value, length);
}

CL_TorrentTree::CL_TorrentTree(CL_TorrentTree value, CL_TorrentTree next)
{
	m_pnode = new CL_ListNode(value, next);
}

CL_TorrentTree::CL_TorrentTree(CL_TorrentTree key, CL_TorrentTree value, CL_TorrentTree next)
{
	m_pnode = new CL_DirectNode(key, value, next);
}

CL_TorrentTree::CL_TorrentTree(const CL_TorrentTree& temp)
{
	m_pnode = temp.m_pnode;
	++m_pnode->m_UseCount;
}

CL_TorrentTree& CL_TorrentTree::operator = (const CL_TorrentTree& temp)
{
	temp.m_pnode->m_UseCount++;
	--m_pnode->m_UseCount;
	if(m_pnode->m_UseCount == 0)
	{
		delete m_pnode;
	}
	m_pnode = temp.m_pnode;
	return *this;
}

int CL_TorrentTree::PrintTree()
{
	m_pnode->PrintFunc();
	return 0;
}

CL_TorrentTree::~CL_TorrentTree()
{
	--m_pnode->m_UseCount;
	if(m_pnode->m_UseCount == 0)
	{
		delete m_pnode;
	}
}