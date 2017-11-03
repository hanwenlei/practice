#include<stdio.h>
#include<stdlib.h>
#include"stack_by_array.h"

int InitStackByArray(struct SS_IStack* stack, int size)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)stack;
	l_stack->pHeadNode = (SS_Node*)malloc(size*sizeof(SS_Node));
	l_stack->size = size;
	l_stack->pTopNode = l_stack->pHeadNode;
	l_stack->NodeCount = 0;
	return 0;
}

int PushElementToStackByArray(struct SS_IStack* stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)stack;
	if(l_stack->NodeCount >= l_stack->size)
	{
		#if _DEBUG
		printf("Õ»ÒÑÂú!\n");
		#endif
		return -1;
	}
	else
	{ 
		l_stack->pTopNode->pdata = l_CopyFunction(pElement);
		l_stack->pTopNode->m_CopyFunction = l_CopyFunction;
		l_stack->pTopNode->m_FreeFunction = l_FreeFunction;
		l_stack->pTopNode++;
		l_stack->NodeCount++;
	}
	return 0;
}

SS_Node* PopElementToStackByArray(struct SS_IStack* stack)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)stack;
	if(l_stack->NodeCount <= 0)
	{
		#if _DEBUG
		printf("Õ»ÒÑ¿Õ!\n");
		#endif
		return NULL;
	}
	else
	{
		l_stack->pTopNode--;
		l_stack->NodeCount--;
	} 
	return l_stack->pTopNode; 
}

SS_Node* TopElementToStackByArray(struct SS_IStack* stack)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)stack;
	SS_Node* TempNode = l_stack->pTopNode - 1;
	return TempNode;
}

int GetNodeCountToStackByArray(struct SS_IStack* stack)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)stack;
	return l_stack->NodeCount;
}

int ClearStackByArray(struct SS_IStack* stack)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)stack;
	SS_Node* TempNode = l_stack->pHeadNode;
	int i = 0;
	for(i = 0; i < l_stack->NodeCount; i++)
	{
		TempNode->m_FreeFunction(TempNode->pdata);
		TempNode++;
	}
	
	free(l_stack->pHeadNode);
	l_stack->size = 0;
	l_stack->pHeadNode = NULL;
	l_stack->pTopNode = NULL;
	l_stack->NodeCount = 0;
	return 0;
}