#include"test.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	FunctionPoint l_UserFuncPoint = UserFunction; 
	CopyFunction l_CopyFunction = UserCopy;
	FreeFunction l_FreeFunction = UserFree;
	
	test_InitHeadNode();
	test_InsertElement(l_CopyFunction, l_FreeFunction);
	test_DeleteNode(l_CopyFunction, l_FreeFunction);
	test_GetNodeCount(l_CopyFunction, l_FreeFunction);
	test_TraverseList(l_UserFuncPoint, l_CopyFunction, l_FreeFunction);
	test_ClearList(l_CopyFunction, l_FreeFunction);
	
	free(l_list);
	
	return 0;
}