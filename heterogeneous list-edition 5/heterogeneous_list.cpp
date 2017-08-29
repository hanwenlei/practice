#include<stdio.h>
#include"heterogeneous_list.h"

int InitHeadNode(SL_List* l_list)
{
	l_list->HeadNode = NULL;
	l_list->NodeCount = 0;
	return 0;
}

SL_Node* InsertElement(SL_Node* LastNode, void* pElement, SL_List* l_list, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SL_Node* TempNode = (SL_Node*)malloc(sizeof(SL_Node));
	void* lElement = l_CopyFunction(pElement);
	TempNode->m_CopyFunction = l_CopyFunction;
	TempNode->m_FreeFunction = l_FreeFunction;
	TempNode->data = lElement;
	if(l_list->NodeCount == 0)
	{
		l_list->HeadNode = TempNode;
		TempNode->next = TempNode;
		TempNode->prev = TempNode;
		l_list->NodeCount++;
	}
	else
	{
		TempNode->next = LastNode->next;
		TempNode->prev = LastNode;
		LastNode->next = TempNode;
		TempNode->next->prev = TempNode;
		l_list->NodeCount++;
	}
	return TempNode;
}

int DeleteNode(SL_Node* ThisNode, SL_List* l_list)
{
	if(l_list->NodeCount == 1)
	{
		if(l_list->HeadNode == ThisNode)
		{
			l_list->HeadNode = NULL;
			l_list->NodeCount--;
			ThisNode->m_FreeFunction(ThisNode->data);
			free(ThisNode);
		}
		else
		{
			#if _DEBUG
			printf("传入节点错误!\n");
			return -1;
			#else
			return -1;
			#endif
		}
	}
	else
	{
		SL_Node* SL_temppoint = ThisNode;
		SL_temppoint->prev->next = SL_temppoint->next;
		SL_temppoint->next->prev = SL_temppoint->prev;
		SL_temppoint->prev = NULL;
		SL_temppoint->next = NULL;
		l_list->NodeCount--;
		ThisNode->m_FreeFunction(ThisNode->data);
		free(ThisNode);
	}
	return 0;
}

int GetNodeCount(SL_List* l_list)
{
	return l_list->NodeCount;
}

int TraverseList(SL_List* l_list, FunctionPoint l_UserFuncPoint)
{
	int i = 0; 
	if(l_list->NodeCount != 0)
	{
		int TraverseFlag = FLAG_CONTINUE_TRAVERSE;
		SL_Node* SL_temp = l_list->HeadNode->next;
		
		for(i = 0; i < l_list->NodeCount; i++)
		{
			TraverseFlag = l_UserFuncPoint(l_list, SL_temp->prev);
			if(TraverseFlag == FLAG_CONTINUE_TRAVERSE)
			{
				SL_temp = SL_temp->next;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}

int ClearList(SL_List* l_list)
{
	int i = 0;
	if(l_list->HeadNode == NULL)
	{
		#if _DEBUG
		printf("链表为空!\n");
		return -1;
		#else
		return -1;
		#endif
	}
	else if(l_list->NodeCount == 1)
	{
		l_list->HeadNode->m_FreeFunction(l_list->HeadNode->data);
		free(l_list->HeadNode);
	}
	else
	{
		SL_Node* TempNode1 = l_list->HeadNode;
		SL_Node* TempNode2 = l_list->HeadNode;
		
		for(i = 0; i < l_list->NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->next;
			TempNode1->m_FreeFunction(TempNode1->data);
			free(TempNode1);
		}
	}
	l_list->HeadNode = NULL;
	l_list->NodeCount = 0;
	return 0;
}

SL_Node* CopyNode(SL_Node* ThisNode)
{
	SL_Node* TempNode = (SL_Node*)malloc(sizeof(SL_Node));
	void* lElement = ThisNode->m_CopyFunction(ThisNode->data);
	TempNode->data = lElement;
	TempNode->m_CopyFunction = ThisNode->m_CopyFunction;
	TempNode->m_FreeFunction = ThisNode->m_FreeFunction;
	TempNode->next = ThisNode->next;
	TempNode->prev = ThisNode->prev;
	return TempNode;
}