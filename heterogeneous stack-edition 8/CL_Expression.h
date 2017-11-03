#ifndef _CL_EXPRESSION_H_
#define _CL_EXPRESSION_H_

#include"CL_StackByArray.h"
#include"CL_StackByList.h"
#include"CL_StackByMultiarray.h"

class CL_Expression
{
private:
	char* m_pResult;
	double m_result;
	
	int GetIndex(char opter);

	char GetPriority(char opter1, char opter2);

	double Calculate(double b, char opter, double a);

	double ResultExp(char* input, char* ch, int* index, CL_IStack* OpterStack, CL_IStack* OpvalStack);
	
	double PutResult(char* ch, CL_IStack* OpterStack, CL_IStack* OpvalStack);
	
public:
	CL_Expression(int size);
	
	char* EvaluateExp(char* input, CL_IStack* OpterStack, CL_IStack* OpvalStack);
	
	double GetResult();
	
	virtual ~CL_Expression();
};

#endif