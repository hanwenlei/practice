#include"test.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	FunctionPoint l_UserFuncPoint = UserFunction; 
	
	test_InitHeadNode();
	test_InsertNode();
	test_DeleteNode();
	test_GetNodeCount();
	test_TraverseList(l_UserFuncPoint);
	test_ClearList();
	
	free(l_list);
	
	return 0;
}