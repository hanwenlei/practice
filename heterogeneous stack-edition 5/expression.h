#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include"multi_heterogeneous_stack.h"

void* CopyOpval(void* pElement);

void* CopyOpter(void* pElement);

int GetIndex(char opter);

char GetPriority(char opter1, char opter2);

double Calculate(double b, char opter, double a);

double EvaluateExp(CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

double HelpEvaluateExp(SL_List* OpterListStack, SL_List* OpvalListStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

double PrintExp(char* ch, SL_List* OpterListStack, SL_List* OpvalListStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

#endif