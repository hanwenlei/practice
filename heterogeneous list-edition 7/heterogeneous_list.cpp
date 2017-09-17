#include<stdio.h>
#include"heterogeneous_list.h"

int InitHeadNode(SL_List* l_list)
{
	l_list->HeadNode = NULL;
	l_list->NodeCount = 0;
	return 0;
}

list_node* InsertElement(SL_List* l_list, list_node* LastNode, void* pElement, int size, CopyFunction l_CopyFunction)
{
	list_node* TempNode = (list_node*)malloc(sizeof(list_node) + size);
	l_CopyFunction(pElement, (void*)(&TempNode+offdata));
	if(l_list->NodeCount == 0)
	{
		l_list->HeadNode = &TempNode->list;
		TempNode->list.next = &TempNode->list;
		TempNode->list.prev = &TempNode->list;
		l_list->NodeCount++;
	}
	else
	{
		TempNode->list.next = LastNode->list.next;
		TempNode->list.prev = &LastNode->list;
		LastNode->list.next = &TempNode->list;
		LastNode->list.next->prev = &TempNode->list;
		l_list->NodeCount++;
	}
	return TempNode;
}

int DeleteNode(list_node* ThisNode, SL_List* l_list)
{
	if(l_list->NodeCount == 1)
	{
		if(l_list->HeadNode == &ThisNode->list)
		{
			l_list->HeadNode = NULL;
			l_list->NodeCount--;
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
		list_node* TempNode = ThisNode;
		TempNode->list.prev->next = TempNode->list.next;
		TempNode->list.next->prev = TempNode->list.prev;
		TempNode->list.prev = NULL;
		TempNode->list.next = NULL;
		l_list->NodeCount--;
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
		list_head* TempNode = l_list->HeadNode->next;
		
		for(i = 0; i < l_list->NodeCount; i++)
		{
			TraverseFlag = l_UserFuncPoint(l_list, (list_node*)((size_t)(TempNode->prev)-offlist));
			if(TraverseFlag == FLAG_CONTINUE_TRAVERSE)
			{
				TempNode = TempNode->next;
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
	else
	{
		list_head* TempNode1 = l_list->HeadNode;
		list_head* TempNode2 = l_list->HeadNode;
		list_node* temp = NULL;
		
		for(i = 0; i < l_list->NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->next;
			temp = (list_node*)((size_t)TempNode1-offlist);
			free(temp);
		}
		
	}
	l_list->HeadNode = NULL;
	l_list->NodeCount = 0;
	return 0;
}