#include"test.h"

IStackNode* test_B::CopyFunction()
{
	test_A* l_test_A = new test_A(m_ptest_struct->m_number);
	test_B* TempNode = new test_B(l_test_A, m_number);
	return TempNode;
}

test_B::~test_B()
{
	delete m_ptest_struct;
}

int CL_TestClass::test_PushElementToStack()
{
	CL_MultiStack* l_stack = new CL_MultiStack();
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	void* lElement1 = new test_B(l_test_A1, 1);
	void* lElement2 = new test_B(l_test_A2, 2);
	void* lElement3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElementToStack(lElement1);
	FAIL_TEST(l_stack->GetNodeCountForStack(), 1);
	l_stack->PushElementToStack(lElement2);
	l_stack->PushElementToStack(lElement3);
	FAIL_TEST(l_stack->GetNodeCountForStack(), 3);
	
	l_stack->ClearTheStack();
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PopElementFromStack()
{
	CL_MultiStack* l_stack = new CL_MultiStack();
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	void* lElement1 = new test_B(l_test_A1, 1);
	void* lElement2 = new test_B(l_test_A2, 2);
	void* lElement3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElementToStack(lElement1);
	l_stack->PopElementFromStack();
	FAIL_TEST(l_stack->GetNodeCountForStack(), 0);
	l_stack->PopElementFromStack();
	l_stack->PushElementToStack(lElement2);
	l_stack->PushElementToStack(lElement3);
	l_stack->PopElementFromStack();
	FAIL_TEST(l_stack->GetNodeCountForStack(), 1);
	
	l_stack->ClearTheStack();
	delete l_stack;
	return 0;
}

int CL_TestClass::test_TopElementFromStack()
{
	CL_MultiStack* l_stack = new CL_MultiStack();
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	void* lElement1 = new test_B(l_test_A1, 1);
	void* lElement2 = new test_B(l_test_A2, 2);
	void* lElement3 = new test_B(l_test_A3, 3);
	IStackNode *test1, *test2;
	
	l_stack->PushElementToStack(lElement1);
	test1 = l_stack->TopElementFromStack();
	FAIL_TEST(l_stack->GetNodeCountForStack(), 1);
	l_stack->PushElementToStack(lElement2);
	l_stack->PushElementToStack(lElement3);
	test2 = l_stack->TopElementFromStack();
	FAIL_TEST(l_stack->GetNodeCountForStack(), 3);	
	
	l_stack->ClearTheStack();
	delete l_stack;
	return 0;
}

int CL_TestClass::test_GetNodeCountForStack()
{
	CL_MultiStack* l_stack = new CL_MultiStack();
	test_A* l_test_A[10];
	test_B* Element[10];
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		l_test_A[i] = new test_A(i+1);
		Element[i] = new test_B(l_test_A[i], i+1);
	}
	
	for(i = 0;i < 10;i++)
	{
		l_stack->PushElementToStack(Element[i]);
		FAIL_TEST(l_stack->GetNodeCountForStack(), i+1);
	}
	
	l_stack->ClearTheStack();
	delete l_stack;
	return 0;
}

int CL_TestClass::test_ClearTheStack()
{
	CL_MultiStack* l_stack = new CL_MultiStack();
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	void* lElement1 = new test_B(l_test_A1, 1);
	void* lElement2 = new test_B(l_test_A2, 2);
	void* lElement3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElementToStack(lElement1);
	l_stack->PushElementToStack(lElement2);
	l_stack->PushElementToStack(lElement3);	
	l_stack->ClearTheStack();
	
	delete l_stack;
	return 0;
}