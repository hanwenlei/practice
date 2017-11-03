#ifndef _TEST_H_
#define _TEST_H_

#include"CL_StackByArray.h"
#include"CL_StackByList.h"
#include"CL_StackByMultiarray.h"

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
	int test_push(CL_IStack* l_stack);

	int test_pop(CL_IStack* l_stack);

	int test_PushElementToStackByArray();

	int test_PopElementToStackByArray();

	int test_PushElementToStackByList();

	int test_PopElementToStackByList();

	int test_PushElementToStackByMultiarray();

	int test_PopElementToStackByMultiarray();
};

#endif