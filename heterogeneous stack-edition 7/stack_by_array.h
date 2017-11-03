#ifndef _STACK_BY_ARRAY_
#define _STACK_BY_ARRAY_

#include"heterogeneous_stack.h"

typedef struct SS_ArrayStack
{
	InitFunction m_InitFunction;
	PushFunction m_PushFunction;
	PopFunction m_PopFunction;
	TopFunction m_TopFunction;
	GetNodeCountFunction m_GetNodeCount;
	ClearFunction m_ClearFunction;
	
	int NodeCount;
	int size;
	SS_Node* pHeadNode;
	SS_Node* pTopNode;
}SS_ArrayStack;

int InitStackByArray(struct SS_IStack* stack, int size);

int PushElementToStackByArray(struct SS_IStack* stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

SS_Node* PopElementToStackByArray(struct SS_IStack* stack);

SS_Node* TopElementToStackByArray(struct SS_IStack* stack);

int GetNodeCountToStackByArray(struct SS_IStack* stack);

int ClearStackByArray(struct SS_IStack* stack);

#endif