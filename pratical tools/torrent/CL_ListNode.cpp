#include<cstdio>
#include"CL_ListNode.h"

CL_ListNode::CL_ListNode(CL_TorrentTree value, CL_TorrentTree next):m_pvalue(value), m_pnext(next){}

int CL_ListNode::PrintFunc()
{
	printf("----------list start----------\n");
	m_pvalue.PrintTree();
	m_pnext.PrintTree();
	printf("----------list end----------\n");
	return 0;
}

CL_ListNode::~CL_ListNode(){}