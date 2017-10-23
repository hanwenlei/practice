#ifndef _CONVERT_NUMBER_H_
#define _CONVERT_NUMBER_H_

#include"multi_heterogeneous_stack.h"

void* CopyInt(void* pElement);

void FreeFunc(void* pElement);

int Convert(int ConvertedNumber, int ResultSystem, CopyFunction l_copy, FreeFunction l_free);

#endif