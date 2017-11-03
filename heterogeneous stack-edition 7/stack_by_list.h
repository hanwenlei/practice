#ifndef _STACK_BY_LIST_H_
#define _STACK_BY_LIST_H_

#include"heterogeneous_stack.h"

typedef struct SS_ListStack
{
	InitFunction m_InitFunction;
	PushFunction m_PushFunction;
	PopFunction m_PopFunction;
	TopFunction m_TopFunction;
	GetNodeCountFunction m_GetNodeCount;
	ClearFunction m_ClearFunction;
	
	int NodeCount;
	SS_Node* pHeadNode;
	SS_Node* pTopNode;
}SS_ListStack;

int InitStackByList(struct SS_IStack* stack, int size);

int PushElementToStackByList(struct SS_IStack* stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

SS_Node* PopElementToStackByList(struct SS_IStack* stack);

SS_Node* TopElementToStackByList(struct SS_IStack* stack);

int GetNodeCountToStackByList(struct SS_IStack* stack);

int ClearStackByList(struct SS_IStack* stack);

#endif