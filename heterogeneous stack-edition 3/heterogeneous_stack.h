#ifndef _HETEROGENEOUS_STACK_H_
#define _HETEROGENEOUS_STACK_H_

#include<stdio.h>
#include<stdlib.h>

typedef void* (*CopyFunction)(void*);

typedef void (*FreeFunction)(void*);

typedef struct SS_Node
{
	void* pdata;
	struct SS_Node* next;
	CopyFunction m_CopyFunction;
	FreeFunction m_FreeFunction;
}SS_Node;

typedef struct SS_Stack
{
	int NodeCount;
	SS_Node* pTopNode;
}SS_Stack;

int InitStack(SS_Stack* l_stack);

int PushElement(SS_Stack* l_stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

SS_Node* PopElement(SS_Stack* l_stack);

SS_Node* TopElement(SS_Stack* l_stack);

int GetNodeCount(SS_Stack* l_stack);

int ClearStack(SS_Stack* l_stack);

#endif