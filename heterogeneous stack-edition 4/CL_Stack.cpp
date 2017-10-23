#include"CL_Stack.h"

CL_Stack::CL_Stack():m_NodeCount(0), m_pTopNode(NULL){}

CL_Stack::~CL_Stack()
{
	if(m_NodeCount != 0)
	{
		ClearStack();
	}
}

int CL_Stack::PushElement(IStackNode* pElement)
{
	IStackNode* TempNode = pElement->CopyFunction();
	TempNode->SetNext(m_pTopNode);
	m_pTopNode = TempNode;
	m_NodeCount++;
	return 0;
}

IStackNode* CL_Stack::PopElement()
{
	IStackNode* TempNode = m_pTopNode;
	if(m_NodeCount <= 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
	}
	else
	{
		m_pTopNode = m_pTopNode->GetNext();
		TempNode->SetNext(NULL);
		m_NodeCount--;
	} 
	return TempNode; 
}

IStackNode* CL_Stack::TopElement()
{
	return m_pTopNode;
}

int CL_Stack::GetNodeCount()
{
	return m_NodeCount;
}

int CL_Stack::ClearStack()
{
	if(m_NodeCount == 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
		return -1;
	}
	else if(m_NodeCount == 1)
	{
		delete m_pTopNode;
	}
	else
	{
		IStackNode* TempNode1 = m_pTopNode;
		IStackNode* TempNode2 = m_pTopNode;
		for(int i = 0; i < m_NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->GetNext();
			delete TempNode1;
		}
	}

	m_pTopNode = NULL;
	m_NodeCount = 0;
	return 0;
}