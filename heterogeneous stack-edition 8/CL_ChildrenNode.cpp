#include"CL_ChildrenNode.h"

CL_OpvalNode::CL_OpvalNode(double opval):m_opval(opval){}

IStackNode* CL_OpvalNode::CopyFunction()
{
	CL_OpvalNode* TempNode = new CL_OpvalNode(m_opval);
	return TempNode;
}

int CL_OpvalNode::SetOpval(double opval)
{
	m_opval = opval;
	return 0;
}

CL_OpvalNode::~CL_OpvalNode(){}

CL_OpterNode::CL_OpterNode(char opter):m_opter(opter){}

IStackNode* CL_OpterNode::CopyFunction()
{
	CL_OpterNode* TempNode = new CL_OpterNode(m_opter);
	return TempNode;
}

int CL_OpterNode::SetOpter(char opter)
{
	m_opter = opter;
	return 0;
}

CL_OpterNode::~CL_OpterNode(){}

CL_IntNode::CL_IntNode(int data):m_data(data){}

IStackNode* CL_IntNode::CopyFunction()
{
	CL_IntNode* TempNode = new CL_IntNode(m_data);
	return TempNode;
}

int CL_IntNode::SetInt(int data)
{
	m_data = data;
	return 0;
}

CL_IntNode::~CL_IntNode(){}