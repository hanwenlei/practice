#ifndef _TEST_H_
#define _TEST_H_

#include"multi_heterogeneous_stack.h"

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

int test_InitialStack();

int test_PushElementToStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PopElementFromStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_TopElementFromStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_GetNodeCountForStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_ClearTheStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

void* UserCopy(void* pElement);

void UserFree(void* pElement);

#endif