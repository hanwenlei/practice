#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include"stack_by_array.h"
#include"stack_by_list.h"
#include"stack_by_multiarray.h"

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

int test_push(SS_IStack* l_stack, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_pop(SS_IStack* l_stack, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PushElementToStackByArray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PopElementToStackByArray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PushElementToStackByList(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PopElementToStackByList(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PushElementToStackByMultiarray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

int test_PopElementToStackByMultiarray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction);

void* UserCopy(void* pElement);

void UserFree(void* pElement);

#endif