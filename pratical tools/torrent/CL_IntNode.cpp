#include<cstdio>
#include"CL_IntNode.h"

CL_IntNode::CL_IntNode(int value):m_value(value){}

int CL_IntNode::PrintFunc()
{
	printf("int : %d\n", m_value);
	return 0;
}

CL_IntNode::~CL_IntNode(){}