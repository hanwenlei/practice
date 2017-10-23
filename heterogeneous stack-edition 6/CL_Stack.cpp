#include"CL_Stack.h"

CL_Stack::CL_Stack(int l_size):m_size(l_size), m_NodeCount(0)
{
	m_pHeadNode = new PIStackNode[l_size];
	m_pTopNode = m_pHeadNode;
	if(m_pHeadNode == NULL)
	{
		#if _DEBUG
		printf("·ÖÅäÊ§°Ü!\n");
		#endif
	}
}

CL_Stack::~CL_Stack()
{
	if(m_NodeCount != 0)
	{
		ClearStack();
	}
	delete [] m_pHeadNode;
}

int CL_Stack::PushElement(IStackNode* pElement)
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

IStackNode* CL_Stack::PopElement()
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

IStackNode* CL_Stack::TopElement()
{
	PIStackNode* TempNode = m_pTopNode - 1;
	return *TempNode;
}

int CL_Stack::GetNodeCount()
{
	return m_NodeCount;
}

int CL_Stack::ClearStack()
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