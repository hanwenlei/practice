#ifndef _CL_CONVERTSYSTEMFORGIVENNUMBER_H_
#define _CL_CONVERTSYSTEMFORGIVENNUMBER_H_

#include"CL_StackByArray.h"
#include"CL_StackByList.h"
#include"CL_StackByMultiarray.h"

class CL_ConvertSystemForGivenNumber
{
public:
	CL_ConvertSystemForGivenNumber();
	int ConvertNumber(int ConvertedNumber, int ConvertSystem, CL_IStack* pStack);
	int PrintResult(CL_IStack* pStack);
	virtual ~CL_ConvertSystemForGivenNumber();
};

#endif