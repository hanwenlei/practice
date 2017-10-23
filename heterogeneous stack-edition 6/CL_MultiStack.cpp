#include"CL_MultiStack.h"

CL_MultiStack::CL_MultiStack():StackSize(100)
{
	m_plist = new CL_List;
	CL_ListNode* TempNode = new CL_ListNode;
	m_plist->InsertNode(m_plist->HeadNode, TempNode);
	CL_Stack* l_stack = new CL_Stack(StackSize);
	m_plist->HeadNode->data = l_stack;
	m_pCurrentStack = l_stack;
}

CL_MultiStack::~CL_MultiStack()
{
	if(m_plist->NodeCount != 0)
	{
		ClearTheStack();
	}
	delete m_plist->HeadNode;
	delete m_plist;
}

int CL_MultiStack::PushElementToStack(void* pElement)
{
	if(m_pCurrentStack->m_NodeCount >= StackSize)
	{
		if(m_plist->HeadNode->prev != m_plist->HeadNode)
		{
			m_plist->HeadNode->prev = m_plist->HeadNode->prev->prev;
			m_pCurrentStack = (CL_Stack*)m_plist->HeadNode->prev->data;
		}
		else
		{
			int flag = ExpandStack();
			if(flag == -1)
			{
				return -1;
			}
		}
	}
	m_pCurrentStack->PushElement((IStackNode*)pElement);
	return 0;
}

int CL_MultiStack::ExpandStack()
{
	CL_ListNode* TempNode = new CL_ListNode;
	m_plist->InsertNode(m_plist->HeadNode, TempNode);
	CL_Stack* l_stack = new CL_Stack(StackSize);
	
	if(l_stack == NULL)
	{
		#if _DEBUG
		printf("ÄÚ´æÒÑºÄ¾¡!\n");
		#endif
		return -1;
	}
	else
	{
		l_stack->m_NodeCount = 0;
		TempNode->data = l_stack;
		m_pCurrentStack = (CL_Stack*)TempNode->data;
	}
	return 0;
}

IStackNode* CL_MultiStack::PopElementFromStack()
{
	if(m_pCurrentStack->m_NodeCount <= 0)
	{
		if(IsEmpty())
		{
			return NULL;
		}
		else
		{
			m_plist->HeadNode->prev = m_plist->HeadNode->prev->prev;
			m_pCurrentStack = (CL_Stack*)m_plist->HeadNode->prev->data;
			m_plist->NodeCount--;
		}
	}
	return m_pCurrentStack->PopElement();
}

IStackNode* CL_MultiStack::TopElementFromStack()
{
	if(m_pCurrentStack->m_NodeCount <= 0)
	{
		if(IsEmpty())
		{
			return NULL;
		}
		else
		{
			m_plist->HeadNode->prev = m_plist->HeadNode->prev->prev;
			m_pCurrentStack = (CL_Stack*)m_plist->HeadNode->prev->data;
		}
	}
	return m_pCurrentStack->TopElement();
}

bool CL_MultiStack::IsEmpty()
{
	if(m_plist->HeadNode->prev->next == m_plist->HeadNode)
	{
		#if _DEBUG
		printf("Õ»ÒÑ¿Õ!\n");
		#endif
		return true;
	}
	else
	{
		return false;
	}
}

int CL_MultiStack::GetNodeCountForStack()
{
	int temp = (m_plist->NodeCount - 1) * StackSize + m_pCurrentStack->m_NodeCount;
	return temp;
}

int CL_MultiStack::ClearTheStack()
{
	CL_ListNode* TempListNode = m_plist->HeadNode;
	CL_ListNode* temp = m_plist->HeadNode;
	for(int i = 0; i < m_plist->NodeCount; i++)
	{
		TempListNode = temp;
		temp = temp->next;
		((CL_Stack*)(TempListNode->data))->ClearStack();
		
		delete (CL_Stack*)TempListNode->data;
		delete TempListNode;
	}
	
	m_plist->HeadNode = NULL;
	m_plist->NodeCount = 0;
	return 0;
}