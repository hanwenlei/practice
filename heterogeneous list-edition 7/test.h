#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include"heterogeneous_list.h"

#define FAIL_TEST(EXP1, EXP2)                                  \
do                                                             \
{                                                              \
	if(EXP1 != EXP2)                                           \
	{printf("Fail the test in %s %d!\n",__FILE__, __LINE__); }   \
}while(0)

typedef struct test_A
{
	int number;
}test_A;

typedef struct test_B
{
	test_A* test_struct;
	int number;
}test_B;

int test_InitHeadNode();

int test_InsertElement(CopyFunction l_CopyFunction);

int test_DeleteNode(CopyFunction l_CopyFunction);

int test_GetNodeCount(CopyFunction l_CopyFunction);

int test_TraverseList(FunctionPoint l_UserFuncPoint, CopyFunction l_CopyFunction);

int UserFunction(SL_List* l_list, list_node* ThisNode);

void UserCopy(void* Element, void* p);

int test_ClearList(CopyFunction l_CopyFunction);

#endif