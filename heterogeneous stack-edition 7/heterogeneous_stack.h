#ifndef _HETEROGENEOUS_STACK_H_
#define _HETEROGENEOUS_STACK_H_

struct SS_Node;

struct SS_IStack;

typedef void* (*CopyFunction)(void*);

typedef void (*FreeFunction)(void*);

typedef int (*InitFunction)(struct SS_IStack*, int);

typedef int (*PushFunction)(struct SS_IStack*, void*, CopyFunction, FreeFunction);

typedef SS_Node* (*PopFunction)(struct SS_IStack*);

typedef SS_Node* (*TopFunction)(struct SS_IStack*);

typedef int (*GetNodeCountFunction)(struct SS_IStack*);

typedef int (*ClearFunction)(struct SS_IStack*);

typedef struct SS_Node
{
	void* pdata;
	struct SS_Node* next;
	CopyFunction m_CopyFunction;
	FreeFunction m_FreeFunction;
}SS_Node;

typedef struct SS_IStack
{
	InitFunction m_InitFunction;
	PushFunction m_PushFunction;
	PopFunction m_PopFunction;
	TopFunction m_TopFunction;
	GetNodeCountFunction m_GetNodeCount;
	ClearFunction m_ClearFunction;
	int NodeCount;
}SS_IStack;

#endif