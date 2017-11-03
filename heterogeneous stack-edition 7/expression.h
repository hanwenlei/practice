#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include"stack_by_array.h"
#include"stack_by_list.h"
#include"stack_by_multiarray.h"

void* CopyOpval(void* pElement);

void* CopyOpter(void* pElement);

int GetIndex(char opter);

char GetPriority(char opter1, char opter2);

double Calculate(double b, char opter, double a);

double EvaluateExp(SS_IStack* OpterStack, SS_IStack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

double PrintExp(char* ch, SS_IStack* OpterStack, SS_IStack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free);

#endif