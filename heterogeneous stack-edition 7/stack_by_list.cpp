#include<stdio.h>
#include<stdlib.h>
#include"stack_by_list.h"

int InitStackByList(struct SS_IStack* stack, int size)
{
	SS_ListStack* l_stack = (SS_ListStack*)stack;
	l_stack->pHeadNode = NULL;
	l_stack->pTopNode = NULL;
	l_stack->NodeCount = 0;
	return 0;
}

int PushElementToStackByList(struct SS_IStack* stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_ListStack* l_stack = (SS_ListStack*)stack;
	SS_Node* TempNode = (SS_Node*)malloc(sizeof(SS_Node));
	TempNode->pdata = l_CopyFunction(pElement);
	TempNode->m_CopyFunction = l_CopyFunction;
	TempNode->m_FreeFunction = l_FreeFunction;
	if(l_stack->NodeCount == 0)
	{
		TempNode->next = NULL;
	}
	else
	{
		TempNode->next = l_stack->pTopNode;
	}
	
	l_stack->pTopNode = TempNode;
	l_stack->NodeCount++;
	return 0;
}

SS_Node* PopElementToStackByList(struct SS_IStack* stack)
{
	SS_ListStack* l_stack = (SS_ListStack*)stack;
	SS_Node* TempNode = l_stack->pTopNode;
	if(l_stack->NodeCount <= 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
	}
	else
	{
		l_stack->pTopNode = TempNode->next;
		TempNode->next = NULL;
		l_stack->NodeCount--;
	} 
	return TempNode; 
}

SS_Node* TopElementToStackByList(struct SS_IStack* stack)
{
	SS_ListStack* l_stack = (SS_ListStack*)stack;
	return l_stack->pTopNode;
}

int GetNodeCountToStackByList(struct SS_IStack* stack)
{
	SS_ListStack* l_stack = (SS_ListStack*)stack;
	return l_stack->NodeCount;
}

int ClearStackByList(struct SS_IStack* stack)
{
	SS_ListStack* l_stack = (SS_ListStack*)stack;
	if(l_stack->NodeCount == 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
		return -1;
	}
	else if(l_stack->NodeCount == 1)
	{
		l_stack->pTopNode->m_FreeFunction(l_stack->pTopNode->pdata);
	}
	else
	{
		SS_Node* TempNode1 = l_stack->pTopNode;
		SS_Node* TempNode2 = l_stack->pTopNode;
		for(int i = 0; i < l_stack->NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->next;
			TempNode1->m_FreeFunction(TempNode1->pdata);
			free(TempNode1);
		}
	}

	l_stack->pTopNode = NULL;
	l_stack->NodeCount = 0;
	return 0;
}