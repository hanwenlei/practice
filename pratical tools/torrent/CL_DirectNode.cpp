#include<cstdio>
#include"CL_DirectNode.h"

CL_DirectNode::CL_DirectNode(CL_TorrentTree key, CL_TorrentTree value, CL_TorrentTree next):m_pkey(key), m_pvalue(value), m_pnext(next){}

int CL_DirectNode::PrintFunc()
{
	printf("----------direct start----------\n");
	m_pkey.PrintTree();
	m_pvalue.PrintTree();
	m_pnext.PrintTree();
	printf("----------direct end----------\n");
	return 0;
}

CL_DirectNode::~CL_DirectNode(){}