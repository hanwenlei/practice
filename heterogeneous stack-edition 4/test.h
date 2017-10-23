#ifndef _TEST_H_
#define _TEST_H_

#include"CL_Stack.h"

#define FAIL_TEST(EXP1, EXP2)                                  \
do                                                             \
{                                                              \
	if(EXP1 != EXP2)                                           \
	{printf("Fail the test in %s %d!\n",__FILE__, __LINE__); }   \
}while(0)

typedef struct test_A
{
	int m_number;
	test_A(int l_number):m_number(l_number){}
}test_A;

class test_B : public IStackNode
{
private:
	test_A* m_ptest_struct;
	int m_number;
	
public:
	test_B(test_A* l_test_A, int l_number);
	virtual IStackNode* CopyFunction();
	virtual ~test_B();
};

class CL_TestClass
{
public:
	int test_PushElement();

	int test_PopElement();

	int test_TopElement();

	int test_GetNodeCount();

	int test_ClearStack();
};

#endif