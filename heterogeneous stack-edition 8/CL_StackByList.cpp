#include"CL_StackByList.h"

CL_ListStack::CL_ListStack()
{
	m_plist = new CL_List;
}

int CL_ListStack::PushElement(IStackNode* pElement)
{
	IStackNode* temp = pElement->CopyFunction();
	CL_ListNode* TempNode = new CL_ListNode;
	TempNode->data = temp;
	m_plist->InsertNode(m_plist->HeadNode, TempNode);
	m_NodeCount++;
	return 0;
}

IStackNode* CL_ListStack::PopElement()
{
	if(m_NodeCount <= 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
		return NULL;
	}
	else
	{
		IStackNode* TempNode = (IStackNode*)(m_plist->HeadNode->data);
		CL_ListNode* temp = m_plist->HeadNode;
		m_plist->HeadNode = m_plist->HeadNode->next;
		delete temp;
		m_plist->NodeCount--;
		m_NodeCount--;
		return TempNode;
	}
}

IStackNode* CL_ListStack::TopElement()
{
	return (IStackNode*)(m_plist->HeadNode->data);
}

int CL_ListStack::GetNodeCount()
{
	return m_NodeCount;
}

int CL_ListStack::ClearStack()
{
	if(m_NodeCount <= 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
		return -1;
	}
	else if(m_NodeCount == 1)
	{
		delete (IStackNode*)m_plist->HeadNode->data;
		delete m_plist->HeadNode;
	}
	else
	{
		CL_ListNode* TempNode1 = m_plist->HeadNode;
		CL_ListNode* TempNode2 = m_plist->HeadNode;
		for(int i = 0; i < m_NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->next;
			delete (IStackNode*)TempNode1->data;
			delete TempNode1;
		}
	}
	m_NodeCount = 0;
	return 0;
}

CL_ListStack::~CL_ListStack()
{
	delete m_plist;
}