#include"test.h"

test_B::test_B(test_A* l_test_A, int l_number):m_ptest_struct(l_test_A), m_number(l_number){}

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

int CL_TestClass::test_push(CL_IStack* l_stack)
{
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	void* lElement1 = new test_B(l_test_A1, 1);
	void* lElement2 = new test_B(l_test_A2, 2);
	void* lElement3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElement((IStackNode*)lElement1);
	FAIL_TEST(l_stack->GetNodeCount(), 1);
	l_stack->PushElement((IStackNode*)lElement2);
	l_stack->PushElement((IStackNode*)lElement3);
	FAIL_TEST(l_stack->GetNodeCount(), 3);
	
	l_stack->ClearStack();
	return 0;
}

int CL_TestClass::test_pop(CL_IStack* l_stack)
{
	test_A* l_test_A1 = new test_A(1);
	test_A* l_test_A2 = new test_A(2);
	test_A* l_test_A3 = new test_A(3);
	void* lElement1 = new test_B(l_test_A1, 1);
	void* lElement2 = new test_B(l_test_A2, 2);
	void* lElement3 = new test_B(l_test_A3, 3);
	
	l_stack->PushElement((IStackNode*)lElement1);
	l_stack->PopElement();
	FAIL_TEST(l_stack->GetNodeCount(), 0);
	l_stack->PopElement();
	l_stack->PushElement((IStackNode*)lElement2);
	l_stack->PushElement((IStackNode*)lElement3);
	l_stack->PopElement();
	FAIL_TEST(l_stack->GetNodeCount(), 1);
	
	l_stack->ClearStack();
	return 0;
}

int CL_TestClass::test_PushElementToStackByArray()
{
	CL_ArrayStack* l_stack = new CL_ArrayStack(3);
	test_push((CL_IStack*)l_stack);
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PopElementToStackByArray()
{
	CL_ArrayStack* l_stack = new CL_ArrayStack(3);
	test_pop((CL_IStack*)l_stack);
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PushElementToStackByList()
{
	CL_ListStack* l_stack = new CL_ListStack;
	test_push((CL_IStack*)l_stack);
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PopElementToStackByList()
{
	CL_ListStack* l_stack = new CL_ListStack;
	test_pop((CL_IStack*)l_stack);
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PushElementToStackByMultiarray()
{
	CL_MultiarrayStack* l_stack = new CL_MultiarrayStack;
	test_push((CL_IStack*)l_stack);
	delete l_stack;
	return 0;
}

int CL_TestClass::test_PopElementToStackByMultiarray()
{
	CL_MultiarrayStack* l_stack = new CL_MultiarrayStack;
	test_pop((CL_IStack*)l_stack);
	delete l_stack;
	return 0;
}