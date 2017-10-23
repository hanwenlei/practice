#include"IStackNode.h"

IStackNode::IStackNode(){}

IStackNode::~IStackNode(){}

IStackNode* IStackNode::GetNext()
{
	return m_pnext;
}

int IStackNode::SetNext(IStackNode* pNode)
{
	m_pnext = pNode;
	return 0;
}