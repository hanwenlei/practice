#include"test.h"

int test_InitialStack()
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);
	FAIL_TEST(l_list->NodeCount, 1);
	FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->NodeCount, 0);
	ClearTheStack(l_list);
	free(l_list);
	return 0;
}

int test_PushElementToStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	PushElementToStack(l_list, lElement1, l_CopyFunction, l_FreeFunction);
	FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->NodeCount, 1);
	PushElementToStack(l_list, lElement2, l_CopyFunction, l_FreeFunction);
	PushElementToStack(l_list, lElement3, l_CopyFunction, l_FreeFunction);
	FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->NodeCount, 3);
	
	ClearTheStack(l_list);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_list);
	return 0;
}

int test_PopElementFromStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	PushElementToStack(l_list, lElement1, l_CopyFunction, l_FreeFunction);
	PopElementFromStack(l_list);
	FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->NodeCount, 0);
	PopElementFromStack(l_list);
	PushElementToStack(l_list, lElement2, l_CopyFunction, l_FreeFunction);
	PushElementToStack(l_list, lElement3, l_CopyFunction, l_FreeFunction);
	PopElementFromStack(l_list);
	FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->NodeCount, 1);
	
	ClearTheStack(l_list);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_list);
	return 0;
}

int test_TopElementFromStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);
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
	
	PushElementToStack(l_list, lElement1, l_CopyFunction, l_FreeFunction);
	test1 = TopElementFromStack(l_list);
	FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->HeadNode, test1);
	PushElementToStack(l_list, lElement2, l_CopyFunction, l_FreeFunction);
	PushElementToStack(l_list, lElement3, l_CopyFunction, l_FreeFunction);
	test2 = TopElementFromStack(l_list);
	FAIL_TEST(--(((SS_Stack*)(l_list->HeadNode->data))->TopNode), test2);	
	
	ClearTheStack(l_list);
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_list);
	return 0;
}

int test_GetNodeCountForStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);
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
		PushElementToStack(l_list, lElement[i], l_CopyFunction, l_FreeFunction);
		FAIL_TEST(((SS_Stack*)(l_list->HeadNode->data))->NodeCount, i+1);
	} 
	
	ClearTheStack(l_list);
	for(i = 0;i < 10;i++)
	{
		l_FreeFunction(lElement[i]);
	}
	free(l_list);
	return 0;
}

int test_ClearTheStack(CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);
	test_A* l_test_A1 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A2 = (test_A*)malloc(sizeof(test_A));
	test_A* l_test_A3 = (test_A*)malloc(sizeof(test_A));
	void* lElement1 = malloc(sizeof(test_B));
	void* lElement2 = malloc(sizeof(test_B));
	void* lElement3 = malloc(sizeof(test_B));
	((test_B*)lElement1)->test_struct = l_test_A1;
	((test_B*)lElement2)->test_struct = l_test_A2;
	((test_B*)lElement3)->test_struct = l_test_A3;
	
	PushElementToStack(l_list, lElement1, l_CopyFunction, l_FreeFunction);
	PushElementToStack(l_list, lElement2, l_CopyFunction, l_FreeFunction);
	PushElementToStack(l_list, lElement3, l_CopyFunction, l_FreeFunction);	
	ClearTheStack(l_list);
	FAIL_TEST(l_list->NodeCount, 0);
	FAIL_TEST(l_list->HeadNode, NULL);
	
	l_FreeFunction(lElement1);
	l_FreeFunction(lElement2);
	l_FreeFunction(lElement3);
	free(l_list);
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