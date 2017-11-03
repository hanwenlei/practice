#ifndef _STACK_BY_MULTIARRAY_
#define _STACK_BY_MULTIARRAY_

#include"heterogeneous_list.h"
#include"stack_by_array.h"

const int StackSize = 100;

typedef struct SS_MultiarrayStack
{
	InitFunction m_InitFunction;
	PushFunction m_PushFunction;
	PopFunction m_PopFunction;
	TopFunction m_TopFunction;
	GetNodeCountFunction m_GetNodeCount;
	ClearFunction m_ClearFunction;
	
	int NodeCount;
	SL_List* m_plist;
	SS_ArrayStack* m_pCurrentStack;
}SS_MultiarrayStack;

int InitStackByMultiarray(struct SS_IStack* stack, int size);

int PushElementToStackByMultiarray(struct SS_IStack* stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

SS_Node* PopElementToStackByMultiarray(struct SS_IStack* stack);

SS_Node* TopElementToStackByMultiarray(struct SS_IStack* stack);

int GetNodeCountToStackByMultiarray(struct SS_IStack* stack);

int ClearStackByMultiarray(struct SS_IStack* stack);

#endif