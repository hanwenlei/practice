#include"test.h"

int test_InitStack()
{
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 3);
	FAIL_TEST(l_stack->size, 3);
	FAIL_TEST(l_stack->NodeCount, 0);
	ClearStack(l_stack);
	free(l_stack);
	return 0;
}

int test_PushElement(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 2);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	PushElement(l_stack, lElement1, l_CopyFunction, l_FreeFunction);
	FAIL_TEST(l_stack->NodeCount, 1);
	PushElement(l_stack, lElement2, l_CopyFunction, l_FreeFunction);
	PushElement(l_stack, lElement3, l_CopyFunction, l_FreeFunction);
	FAIL_TEST(l_stack->NodeCount, 2);
	
	ClearStack(l_stack);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_stack);
	return 0;
}

int test_PopElement(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 3);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	PushElement(l_stack, lElement1, l_CopyFunction, l_FreeFunction);
	PopElement(l_stack);
	FAIL_TEST(l_stack->NodeCount, 0);
	PopElement(l_stack);
	PushElement(l_stack, lElement2, l_CopyFunction, l_FreeFunction);
	PushElement(l_stack, lElement3, l_CopyFunction, l_FreeFunction);
	PopElement(l_stack);
	FAIL_TEST(l_stack->NodeCount, 1);
	
	ClearStack(l_stack);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_stack);
	return 0;
}

int test_TopElement(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 3);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	SS_Node *test1, *test2;
	
	PushElement(l_stack, lElement1, l_CopyFunction, l_FreeFunction);
	test1 = TopElement(l_stack);
	FAIL_TEST(l_stack->HeadNode, test1);
	PushElement(l_stack, lElement2, l_CopyFunction, l_FreeFunction);
	PushElement(l_stack, lElement3, l_CopyFunction, l_FreeFunction);
	test2 = TopElement(l_stack);
	FAIL_TEST(--l_stack->TopNode, test2);	
	
	ClearStack(l_stack);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_stack);
	return 0;
}

int test_GetNodeCount(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 10);
	test_A* l_test_A[10];
	void* lElement[10];
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		l_test_A[i] = (test_A*)malloc(sizeof(test_A));
		lElement[i] = malloc(sizeof(test_B));
		((test_B*)lElement[i])->test_struct = l_test_A[i];
	}
	
	for(i = 0;i < 10;i++)
	{
		PushElement(l_stack, lElement[i], l_CopyFunction, l_FreeFunction);
		FAIL_TEST(l_stack->NodeCount, i+1);
	} 
	
	ClearStack(l_stack);
	for(i = 0;i < 10;i++)
	{
		l_FreeFunction(lElement[i]);
	}
	free(l_stack);
	return 0;
}

int test_ClearStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 3);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	PushElement(l_stack, lElement1, l_CopyFunction, l_FreeFunction);
	PushElement(l_stack, lElement2, l_CopyFunction, l_FreeFunction);
	PushElement(l_stack, lElement3, l_CopyFunction, l_FreeFunction);	
	ClearStack(l_stack);
	FAIL_TEST(l_stack->NodeCount, 0);
	FAIL_TEST(l_stack->size, 0);
	FAIL_TEST(l_stack->HeadNode, NULL);
	
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
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