#include<stdio.h>
#include"test.h"

int test_InitHeadNode()
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	FAIL_TEST(l_list->NodeCount, 0);
	FAIL_TEST(l_list->HeadNode, NULL);
	free(l_list);
	return 0;
}

int test_InsertNode(FunctionPoint m_UserFuncPoint)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	SL_Node* test1 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test2 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test3 = (SL_Node*)malloc(sizeof(SL_Node));
	
	InitHeadNode(l_list);
	InsertNode(l_list->HeadNode, test1, l_list, m_UserFuncPoint);
	FAIL_TEST(l_list->HeadNode, test1);
	FAIL_TEST(test1->next, test1);
	FAIL_TEST(test1->prev, test1);
	InsertNode(test1, test2, l_list, m_UserFuncPoint);
	InsertNode(test2, test3, l_list, m_UserFuncPoint);
	FAIL_TEST(test3->next, test1);
	
	free(l_list);
	free(test1);
	free(test2);
	free(test3);
	return 0;
}

int test_DeleteNode(FunctionPoint m_UserFuncPoint)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	SL_Node* test1 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test2 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test3 = (SL_Node*)malloc(sizeof(SL_Node));
	
	InitHeadNode(l_list);
	InsertNode(l_list->HeadNode, test1, l_list, m_UserFuncPoint);
	DeleteNode(test2, l_list);
	InsertNode(test1, test2, l_list, m_UserFuncPoint);
	InsertNode(test2, test3, l_list, m_UserFuncPoint);
	DeleteNode(test2, l_list);
	FAIL_TEST(test1->next, test3);
	FAIL_TEST(test3->prev, test1);
	
	free(l_list);
	return 0;
}

int test_GetNodeCount(FunctionPoint m_UserFuncPoint)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	SL_Node* test[10];
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		test[i] = (SL_Node*)malloc(sizeof(SL_Node));
	}
	InitHeadNode(l_list);
	InsertNode(l_list->HeadNode, test[0], l_list, m_UserFuncPoint);
	FAIL_TEST(l_list->NodeCount, 1);
	
	for(i = 0;i < 9;i++)
	{
		InsertNode(test[i], test[i+1], l_list, m_UserFuncPoint);
		FAIL_TEST(l_list->NodeCount, i+2);
	} 
	
	for(i = 0;i < 10;i++)
	{
		free(test[i]);
	}
	free(l_list);
	return 0;
}

int test_TraverseList(FunctionPoint l_UserFuncPoint, FunctionPoint m_UserFuncPoint)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	SL_Node* test[10];
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		test[i] = (SL_Node*)malloc(sizeof(SL_Node));
	}
	
	InitHeadNode(l_list);
	int index[10]={1,2,3,4,5,6,7,8,9,10};
	test[0]->data = &index[0];
	InsertNode(l_list->HeadNode, test[0], l_list, m_UserFuncPoint);
	
	for(i = 0; i < 9; i++)
	{
		test[i+1]->data = &index[i+1];
		InsertNode(test[i], test[i+1], l_list, m_UserFuncPoint);
	}
	TraverseList(l_list, l_UserFuncPoint);
	
	for(i = 0; i < 10; i++)
	{
		free(test[i]);
	}
	free(l_list);
	return 0;
}

int UserFunction(SL_List* l_list, SL_Node* ThisNode)
{
	SL_Node* UserNode = (SL_Node*)malloc(sizeof(SL_Node));
	int ConductFlag = 0;
	static int count = 1;
	
	#ifdef _DEBUG
	ConductFlag = FLAG_CONTINUE_TRAVERSE;
	FAIL_TEST(*((int*)(ThisNode->data)), count++);
	
/*	#else
	char get_ch = 0;
	getchar();
	printf("请选择接下来进行的操作(a:在此插入节点;b:删除此节点;c:获得当前链表的节点数;d:继续遍历链表;e:退出链表遍历)\n");
	printf("(请注意大小写!)\n");
	get_ch = getchar();
	switch(get_ch)
	{
		case 'a':
			InsertNode(ThisNode, UserNode, l_list);
			ConductFlag = FLAG_CONTINUE_TRAVERSE;
			break;
		case 'b':
			DeleteNode(ThisNode,l_list);
			ConductFlag = FLAG_CONTINUE_TRAVERSE;
			break;
		case 'c':
			GetNodeCount(l_list);
			ConductFlag = FLAG_CONTINUE_TRAVERSE;
			break;
		case 'd':
			ConductFlag = FLAG_CONTINUE_TRAVERSE;
			break; 
		case 'e':ConductFlag = 0;
	}*/
	#endif
	return ConductFlag;
}

int MemUserFunc(SL_List* l_list, SL_Node* ThisNode)
{
	#ifdef _DEBUG
	free(ThisNode);
	#else
	//用户自行处理
	#endif
	return 0; 
}

int test_ClearList(FunctionPoint m_UserFuncPoint)
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	SL_Node* test1 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test2 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test3 = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* test4 = (SL_Node*)malloc(sizeof(SL_Node));
	
	InitHeadNode(l_list);
	ClearList(l_list);
	FAIL_TEST(l_list->HeadNode, NULL);
	FAIL_TEST(l_list->NodeCount, 0);
	
	InsertNode(l_list->HeadNode, test4, l_list, m_UserFuncPoint);
	ClearList(l_list);
	FAIL_TEST(l_list->HeadNode, NULL);
	FAIL_TEST(l_list->NodeCount, 0);
	
	InsertNode(l_list->HeadNode, test1, l_list, m_UserFuncPoint);
	InsertNode(test1, test2, l_list, m_UserFuncPoint);
	InsertNode(test2, test3, l_list, m_UserFuncPoint);
	ClearList(l_list);
	FAIL_TEST(l_list->HeadNode, NULL);
	FAIL_TEST(l_list->NodeCount, 0);
	
	free(l_list);
	return 0;
}

int test_InsertElement()
{
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	SL_Node* test1 = NULL;
	SL_Node* test2 = NULL;
	SL_Node* test3 = NULL;
	void* element1 = NULL;
	void* element2 = NULL;
	void* element3 = NULL;
	
	InitHeadNode(l_list);
	test1 = InsertElement(l_list->HeadNode, element1, l_list);
	FAIL_TEST(l_list->HeadNode, test1);
	FAIL_TEST(test1->next, test1);
	FAIL_TEST(test1->prev, test1);
	test2 = InsertElement(test1, element2, l_list);
	test3 = InsertElement(test2, element3, l_list);
	FAIL_TEST(test3->next, test1);
	
	ClearList(l_list);
	free(l_list);
	return 0;
}