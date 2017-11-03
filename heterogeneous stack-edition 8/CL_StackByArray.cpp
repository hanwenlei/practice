#include"CL_StackByArray.h"

CL_ArrayStack::CL_ArrayStack(int size):m_size(size), m_pHeadNode(0), m_pTopNode(0)
{
	m_pHeadNode = new PIStackNode[size];
	m_pTopNode = m_pHeadNode;
}

int CL_ArrayStack::PushElement(IStackNode* pElement)
{
	if(m_NodeCount >= m_size)
	{
		#if _DEBUG
		printf("Õ»ÒÑÂú!\n");
		#endif
		return -1;
	}
	else
	{ 
		*m_pTopNode = pElement->CopyFunction();
		m_pTopNode++;
		m_NodeCount++;
	}
	return 0;
}

IStackNode* CL_ArrayStack::PopElement()
{
	if(m_NodeCount <= 0)
	{
		#if _DEBUG
		printf("Õ»ÒÑ¿Õ!\n");
		#endif
		return NULL;
	}
	else
	{
		m_pTopNode--;
		m_NodeCount--;
	} 
	return *m_pTopNode;
}

IStackNode* CL_ArrayStack::TopElement()
{
	PIStackNode* TempNode = m_pTopNode - 1;
	return *TempNode;
}

int CL_ArrayStack::GetNodeCount()
{
	return m_NodeCount;
}

int CL_ArrayStack::ClearStack()
{
	for(int i = 0; i < m_NodeCount; i++)
	{
		m_pTopNode--;
		delete *m_pTopNode;
	}
	m_pTopNode = m_pHeadNode;
	m_NodeCount = 0;
	return 0;
}

CL_ArrayStack::~CL_ArrayStack()
{
	if(m_NodeCount != 0)
	{
		ClearStack();
	}
	delete [] m_pHeadNode;
}