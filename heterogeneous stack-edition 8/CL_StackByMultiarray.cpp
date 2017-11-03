#include"CL_StackByMultiarray.h"

CL_MultiarrayStack::CL_MultiarrayStack():StackSize(100)
{
	m_plist = new CL_List;
	CL_ListNode* TempNode = new CL_ListNode;
	m_plist->InsertNode(m_plist->HeadNode, TempNode);
	TempNode->data = new CL_ArrayStack(StackSize);
	m_pCurrentStack = (CL_ArrayStack*)(TempNode->data);
	m_NodeCount = 1;
}

int CL_MultiarrayStack::PushElement(IStackNode* pElement)
{
	if(m_pCurrentStack->m_NodeCount >= StackSize)
	{
		if(m_plist->HeadNode->prev != m_plist->HeadNode)
		{
			m_plist->HeadNode->prev = m_plist->HeadNode->prev->prev;
			m_pCurrentStack = (CL_ArrayStack*)(m_plist->HeadNode->prev->data);
		}
		else
		{
			CL_ListNode* TempNode = new CL_ListNode;
			m_plist->InsertNode(m_plist->HeadNode, TempNode);
			m_plist->HeadNode->prev = TempNode;
			TempNode->data = new CL_ArrayStack(StackSize);
			if(TempNode->data == NULL)
			{
				return -1;
			}
			else
			{
				m_pCurrentStack = (CL_ArrayStack*)(TempNode->data);
				m_NodeCount++;
			}
		}
	}
	m_pCurrentStack->PushElement(pElement);
	return 0;
}

IStackNode* CL_MultiarrayStack::PopElement()
{
	if(m_pCurrentStack->m_NodeCount <= 0)
	{
		if(m_plist->HeadNode->prev->next == m_plist->HeadNode)
		{
			#if _DEBUG
			printf("у╩ря©у!\n");
			#endif
			return NULL;
		}
		else
		{
			m_plist->HeadNode->prev = m_plist->HeadNode->prev->next;
			m_pCurrentStack = (CL_ArrayStack*)(m_plist->HeadNode->prev->data);
			m_plist->NodeCount--;
		}
	}
	return m_pCurrentStack->PopElement();
}

IStackNode* CL_MultiarrayStack::TopElement()
{
	if(m_pCurrentStack->m_NodeCount <= 0)
	{
		if(m_plist->HeadNode->prev->next == m_plist->HeadNode)
		{
			#if _DEBUG
			printf("у╩ря©у!\n");
			#endif
			return NULL;
		}
		else
		{
			m_plist->HeadNode->prev = m_plist->HeadNode->prev->next;
			m_pCurrentStack = (CL_ArrayStack*)(m_plist->HeadNode->prev->data);
		}
	}
	return m_pCurrentStack->TopElement();
}

int CL_MultiarrayStack::GetNodeCount()
{
	int temp = (m_plist->NodeCount - 1) * 100 + m_pCurrentStack->m_NodeCount;
	return temp;
}

int CL_MultiarrayStack::ClearStack()
{
	CL_ListNode* TempListNode = m_plist->HeadNode;
	CL_ListNode* temp = m_plist->HeadNode;
	
	for(int i = 0; i < m_plist->NodeCount; i++)
	{
		TempListNode = temp;
		temp = temp->next;
		((CL_ArrayStack*)(TempListNode->data))->ClearStack();
		delete (CL_ArrayStack*)(TempListNode->data);
		delete TempListNode;
	}
	
	m_plist->HeadNode = NULL;
	m_plist->NodeCount = 0;
	return 0;
}

CL_MultiarrayStack::~CL_MultiarrayStack()
{
	delete m_plist;
}