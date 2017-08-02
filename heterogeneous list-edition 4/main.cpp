#include"test.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	FunctionPoint l_UserFuncPoint = UserFunction;
	FunctionPoint m_UserFuncPoint = MemUserFunc;
	
	test_InitHeadNode();
	test_InsertNode(m_UserFuncPoint);
	test_DeleteNode(m_UserFuncPoint);
	test_GetNodeCount(m_UserFuncPoint);
	test_TraverseList(l_UserFuncPoint, m_UserFuncPoint);
	test_ClearList(m_UserFuncPoint);
	test_InsertElement();
	
	free(l_list);
	
	return 0;
}