#ifndef _CL_EXPRESSION_H_
#define _CL_EXPRESSION_H_

#include"CL_Stack.h"

class CL_Expression
{
private:
	char* m_pResult;
	double m_result;
	CL_Stack* OpterStack;
	CL_Stack* OpvalStack;
	
	int GetIndex(char opter);

	char GetPriority(char opter1, char opter2);

	double Calculate(double b, char opter, double a);
	
	double HelpEvaluateExp(char* input);

	double ResultExp(char* input, char* ch, int* index);
	
	double PutResult(char* ch);
	
public:
	CL_Expression(int size);
	
	~CL_Expression();
	
	char* EvaluateExp(char* input);
	
	double GetResult();
};

#endif