#include<stdlib.h>
#include"expression.h"
#include"convert_number.h"
#include"test.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CopyFunction opval = CopyOpval;
	CopyFunction opter = CopyOpter;
	CopyFunction l_int = CopyInt;
	CopyFunction test_copy = UserCopy;
	
	FreeFunction l_free = FreeFunc;
	FreeFunction test_free = UserFree;
	
	SS_ArrayStack* array_stack = (SS_ArrayStack*)malloc(sizeof(SS_ArrayStack));
	SS_ListStack* list_stack = (SS_ListStack*)malloc(sizeof(SS_ListStack));
	SS_MultiarrayStack* multiarray_stack = (SS_MultiarrayStack*)malloc(sizeof(SS_MultiarrayStack));
	
	InitStackByArray((SS_IStack*)array_stack, 50);
	InitStackByList((SS_IStack*)list_stack, 50);
	InitStackByMultiarray((SS_IStack*)multiarray_stack, 50);
	
	array_stack->m_InitFunction = InitStackByArray;
	list_stack->m_InitFunction = InitStackByList;
	multiarray_stack->m_InitFunction = InitStackByMultiarray;
	
	array_stack->m_PushFunction = PushElementToStackByArray;
	list_stack->m_PushFunction = PushElementToStackByList;
	multiarray_stack->m_PushFunction = PushElementToStackByMultiarray;
	
	array_stack->m_PopFunction = PopElementToStackByArray;
	list_stack->m_PopFunction = PopElementToStackByList;
	multiarray_stack->m_PopFunction = PopElementToStackByMultiarray;
	
	array_stack->m_TopFunction = TopElementToStackByArray;
	list_stack->m_TopFunction = TopElementToStackByList;
	multiarray_stack->m_TopFunction = TopElementToStackByMultiarray;
	
	array_stack->m_GetNodeCount = GetNodeCountToStackByArray;
	list_stack->m_GetNodeCount = GetNodeCountToStackByList;
	multiarray_stack->m_GetNodeCount = GetNodeCountToStackByMultiarray;
	
	array_stack->m_ClearFunction = ClearStackByArray;
	list_stack->m_ClearFunction = ClearStackByList;
	multiarray_stack->m_ClearFunction = ClearStackByMultiarray;
	
	test_PushElementToStackByArray(test_copy, test_free);

	test_PopElementToStackByArray(test_copy, test_free);

	test_PushElementToStackByList(test_copy, test_free);

	test_PopElementToStackByList(test_copy, test_free);
	
	int ConvertedNumber = 0, ResultSystem = 0;
	double answer = 0;
	
	answer = EvaluateExp((SS_IStack*)array_stack, (SS_IStack*)list_stack, opval, opter, l_free);//输入的表达式以#为结束标志 
	printf("%.0lf\n", answer);
	
	scanf("%d%d", &ConvertedNumber, &ResultSystem);
	Convert((SS_IStack*)multiarray_stack, ConvertedNumber, ResultSystem, l_int, l_free);
	
	ClearStackByArray((SS_IStack*)array_stack);
	ClearStackByList((SS_IStack*)list_stack);
	ClearStackByMultiarray((SS_IStack*)multiarray_stack);
	
	free(array_stack);
	free(list_stack);
	free(multiarray_stack);
	return 0;
}