#ifndef _HETEROGENEOUS_LIST_H_
#define _HETEROGENEOUS_LIST_H_

#include<stddef.h>
#include<stdlib.h>
#define FLAG_CONTINUE_TRAVERSE 1

typedef void (*CopyFunction)(void*, void*);

typedef void (*FreeFunction)(void*);

typedef struct list_head
{
	struct list_head* prev;
	struct list_head* next;
}list_head;

typedef struct list_node
{
	int size;
	CopyFunction m_CopyFunction;
	FreeFunction m_FreeFunction;
	list_head list;
	char data[0];
}list_node;

typedef struct SL_List
{
	list_head* HeadNode;
	int NodeCount;
}SL_List;

const size_t offdata = offsetof(list_node, data[0]);

const size_t offlist = offsetof(list_node, list);

typedef int (*FunctionPoint)(SL_List*, list_node*);

int InitHeadNode(SL_List* l_list);

list_node* InsertElement(SL_List* l_list, list_node* LastNode, void* pElement, int size, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int DeleteNode(list_node* ThisNode, SL_List* l_list);

int GetNodeCount(SL_List* l_list);

int TraverseList(SL_List* l_list, FunctionPoint l_UserFuncPoint);

int ClearList(SL_List* l_list);

#endif