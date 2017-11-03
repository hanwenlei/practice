#include<stdlib.h>
#include"test.h"

int test_push(SS_IStack* l_stack, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	l_stack->m_PushFunction(l_stack, lElement1, l_CopyFunction, l_FreeFunction);
	FAIL_TEST(l_stack->NodeCount, 1);
	l_stack->m_PushFunction(l_stack, lElement2, l_CopyFunction, l_FreeFunction);
	l_stack->m_PushFunction(l_stack, lElement3, l_CopyFunction, l_FreeFunction);
	FAIL_TEST(l_stack->NodeCount, 3);
	
	l_stack->m_ClearFunction(l_stack);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	return 0;
}

int test_pop(SS_IStack* l_stack, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	l_stack->m_PushFunction(l_stack, lElement1, l_CopyFunction, l_FreeFunction);
	l_stack->m_PopFunction(l_stack);
	FAIL_TEST(l_stack->NodeCount, 0);
	l_stack->m_PopFunction(l_stack);
	l_stack->m_PushFunction(l_stack, lElement2, l_CopyFunction, l_FreeFunction);
	l_stack->m_PushFunction(l_stack, lElement3, l_CopyFunction, l_FreeFunction);
	l_stack->m_PopFunction(l_stack);
	FAIL_TEST(l_stack->NodeCount, 1);
	
	l_stack->m_ClearFunction(l_stack);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	return 0;
}

int test_PushElementToStackByArray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)malloc(sizeof(SS_ArrayStack));
	InitStackByArray((SS_IStack*)l_stack, 3);
	l_stack->m_PushFunction = PushElementToStackByArray;
	l_stack->m_ClearFunction = ClearStackByArray;
	test_push((SS_IStack*)l_stack, l_CopyFunction, l_FreeFunction);
	free(l_stack);
	return 0;
}

int test_PopElementToStackByArray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_ArrayStack* l_stack = (SS_ArrayStack*)malloc(sizeof(SS_ArrayStack));
	InitStackByArray((SS_IStack*)l_stack, 3);
	l_stack->m_PushFunction = PushElementToStackByArray;
	l_stack->m_PopFunction = PopElementToStackByArray;
	l_stack->m_ClearFunction = ClearStackByArray;
	test_pop((SS_IStack*)l_stack, l_CopyFunction, l_FreeFunction);
	free(l_stack);
	return 0;
}

int test_PushElementToStackByList(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_ListStack* l_stack = (SS_ListStack*)malloc(sizeof(SS_ListStack));
	InitStackByList((SS_IStack*)l_stack, 3);
	l_stack->m_PushFunction = PushElementToStackByList;
	l_stack->m_ClearFunction = ClearStackByList;
	test_push((SS_IStack*)l_stack, l_CopyFunction, l_FreeFunction);
	free(l_stack);
	return 0;
}

int test_PopElementToStackByList(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_ListStack* l_stack = (SS_ListStack*)malloc(sizeof(SS_ListStack));
	InitStackByList((SS_IStack*)l_stack, 3);
	l_stack->m_PushFunction = PushElementToStackByList;
	l_stack->m_PopFunction = PopElementToStackByList;
	l_stack->m_ClearFunction = ClearStackByList;
	test_pop((SS_IStack*)l_stack, l_CopyFunction, l_FreeFunction);
	free(l_stack);
	return 0;
}

int test_PushElementToStackByMultiarray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)malloc(sizeof(SS_MultiarrayStack));
	InitStackByMultiarray((SS_IStack*)l_stack, 3);
	l_stack->m_PushFunction = PushElementToStackByMultiarray;
	l_stack->m_ClearFunction = ClearStackByMultiarray;
	test_push((SS_IStack*)l_stack, l_CopyFunction, l_FreeFunction);
	free(l_stack);
	return 0;
}

int test_PopElementToStackByMultiarray(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)malloc(sizeof(SS_MultiarrayStack));
	InitStackByMultiarray((SS_IStack*)l_stack, 3);
	l_stack->m_PushFunction = PushElementToStackByMultiarray;
	l_stack->m_PopFunction = PopElementToStackByMultiarray;
	l_stack->m_ClearFunction = ClearStackByMultiarray;
	test_pop((SS_IStack*)l_stack, l_CopyFunction, l_FreeFunction);
	free(l_stack);
	return 0;
}

void* UserCopy(void* pElement)
{
	test_A* l_test_A = (test_A*)malloc(sizeof(test_A));
	test_B* l_test_B = (test_B*)malloc(sizeof(test_B));
	l_test_A->number = ((test_B*)pElement)->test_struct->number;
	l_test_B->test_struct = l_test_A;
	l_test_B->number = ((test_B*)pElement)->number;
	return l_test_B;
}

void UserFree(void* pElement)
{
	free(((test_B*)pElement)->test_struct);
	free(pElement);
}