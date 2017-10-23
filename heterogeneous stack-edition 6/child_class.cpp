#include"child_class.h"

IStackNode* CL_OpvalNode::CopyFunction()
{
	CL_OpvalNode* TempNode = new CL_OpvalNode(m_opval);
	return TempNode;
}

IStackNode* CL_OpterNode::CopyFunction()
{
	CL_OpterNode* TempNode = new CL_OpterNode(m_opter);
	return TempNode;
}

IStackNode* CL_IntNode::CopyFunction()
{
	CL_IntNode* TempNode = new CL_IntNode(m_data);
	return TempNode;
}

int CL_OpvalNode::SetOpval(double opval)
{
	this->m_opval = opval;
	return 0;
}

int CL_OpterNode::SetOpter(char opter)
{
	this->m_opter = opter;
	return 0;
}

int CL_IntNode::SetInt(int data)
{
	this->m_data = data;
	return 0;
}