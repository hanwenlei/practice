#ifndef _TEST_H_
#define _TEST_H_

#include"heterogeneous_stack.h"

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

int test_InitStack();

int test_PushElement(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PopElement(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_TopElement(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_GetNodeCount(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_ClearStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

void* UserCopy(void* pElement);

void UserFree(void* pElement);

#endif