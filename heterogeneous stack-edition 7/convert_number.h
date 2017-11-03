#ifndef _CONVERT_NUMBER_H_
#define _CONVERT_NUMBER_H_

#include"stack_by_array.h"
#include"stack_by_list.h"
#include"stack_by_multiarray.h"

void* CopyInt(void* pElement);

void FreeFunc(void* pElement);

int Convert(SS_IStack* l_stack, int ConvertedNumber, int ResultSystem, CopyFunction l_copy, FreeFunction l_free);

#endif