#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include"heterogeneous_stack.h"

void* CopyOpval(void* pElement);

void* CopyOpter(void* pElement);

int GetIndex(char opter);

char GetPriority(char opter1, char opter2);

double Calculate(double b, char opter, double a);

double EvaluateExp(CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

double HelpEvaluateExp(SS_Stack* OpterStack, SS_Stack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

double PrintExp(char* ch, SS_Stack* OpterStack, SS_Stack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

#endif