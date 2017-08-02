#ifndef _TEST_H_
#define _TEST_H_

#include"heterogeneous_list.h"

#define FAIL_TEST(EXP1, EXP2)                                  \
do                                                             \
{                                                              \
	if(EXP1 != EXP2)                                           \
	{printf("Fail the test in %s %d!\n",__FILE__, __LINE__); }   \
}while(0)

int test_InitHeadNode();

int test_InsertNode();

int test_DeleteNode();

int test_GetNodeCount();

int test_TraverseList(FunctionPoint l_UserFuncPoint);

int UserFunction(SL_List* l_list, SL_Node* ThisNode);

int test_ClearList();

#endif