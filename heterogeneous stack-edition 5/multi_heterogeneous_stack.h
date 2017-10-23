#ifndef _MULTI_HETEROGENEOUS_STACK_H_
#define _MULTI_HETEROGENEOUS_STACK_H_

#include<stdio.h>
#include"heterogeneous_stack.h"
#include"heterogeneous_list.h"

int InitialStack(SL_List* l_list);

int PushElementToStack(SL_List* l_list, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

SS_Node* PopElementFromStack(SL_List* l_list);

SS_Node* TopElementFromStack(SL_List* l_list);

int GetNodeCountForStack(SL_List* l_list);

int ClearTheStack(SL_List* l_list);

#endif