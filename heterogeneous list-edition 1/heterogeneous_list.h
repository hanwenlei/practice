#ifndef _HETEROGENEOUS_LIST_H_
#define _HETEROGENEOUS_LIST_H_

#include<stdlib.h>
#define FLAG_CONTINUE_TRAVERSE 1

typedef struct SL_Node
{
	struct SL_Node* prev;
	struct SL_Node* next;
	void* data;
}SL_Node;

typedef struct SL_List
{
	int NodeCount;
	SL_Node* HeadNode;
}SL_List;

typedef int (*FunctionPoint)(SL_List*, SL_Node*);

int InitHeadNode(SL_List* l_list);

int InsertNode(SL_Node* LastNode, SL_Node* ThisNode, SL_List* l_list);

int DeleteNode(SL_Node* ThisNode, SL_List* l_list);

int GetNodeCount(SL_List* l_list);

int TraverseList(SL_List* l_list, FunctionPoint l_UserFuncPoint);

#endif