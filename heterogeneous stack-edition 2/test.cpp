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

int CL_TestClass::test_PushElement()
{
	CL_Stack* l_stack = new CL_Stack(2);
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	test_B* Element1 = new test_B(l_test_A1, 1);
	test_B* Element2 = new test_B(l_test_A2, 2);
	test_B* Element3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElement(Element1);
	FAIL_TEST(l_stack->GetNodeCount(), 1);
	l_stack->PushElement(Element2);
	l_stack->PushElement(Element3);
	FAIL_TEST(l_stack->GetNodeCount(), 2);
	
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PopElement()
{
	CL_Stack* l_stack = new CL_Stack(2);
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	test_B* Element1 = new test_B(l_test_A1, 1);
	test_B* Element2 = new test_B(l_test_A2, 2);
	test_B* Element3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElement(Element1);
	l_stack->PopElement();
	FAIL_TEST(l_stack->GetNodeCount(), 0);
	l_stack->PopElement();
	l_stack->PushElement(Element2);
	l_stack->PushElement(Element3);
	l_stack->PopElement();
	FAIL_TEST(l_stack->GetNodeCount(), 1);
	
	delete Element1;
	delete Element2;
	delete Element3;
	delete l_stack;
	return 0;
}

int CL_TestClass::test_TopElement()
{
	CL_Stack* l_stack = new CL_Stack(3);
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	test_B* Element1 = new test_B(l_test_A1, 1);
	test_B* Element2 = new test_B(l_test_A2, 2);
	test_B* Element3 = new test_B(l_test_A3, 3);
	IStackNode *test1, *test2;
	
	l_stack->PushElement(Element1);
	test1 = l_stack->TopElement();
	FAIL_TEST(l_stack->GetNodeCount(), 1);
	l_stack->PushElement(Element2);
	l_stack->PushElement(Element3);
	test2 = l_stack->TopElement();
	FAIL_TEST(l_stack->GetNodeCount(), 3);	
	
	delete Element1;
	delete Element2;
	delete Element3;
	delete l_stack;
	return 0;
}

int CL_TestClass::test_GetNodeCount()
{
	CL_Stack* l_stack = new CL_Stack(10);
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
		l_stack->PushElement(Element[i]);
		FAIL_TEST(l_stack->GetNodeCount(), i+1);
	} 
	
	for(i = 0;i < 10;i++)
	{
		delete Element[i];
	}
	delete l_stack;
	return 0;
}

int CL_TestClass::test_ClearStack()
{
	CL_Stack* l_stack = new CL_Stack(3);
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	test_B* Element1 = new test_B(l_test_A1, 1);
	test_B* Element2 = new test_B(l_test_A2, 2);
	test_B* Element3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElement(Element1);
	l_stack->PushElement(Element2);
	l_stack->PushElement(Element3);	
	
	delete Element1;
	delete Element2;
	delete Element3;
	delete l_stack;
	return 0;
}