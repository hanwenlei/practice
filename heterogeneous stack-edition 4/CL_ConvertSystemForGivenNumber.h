#ifndef _CL_CONVERTSYSTEMFORGIVENNUMBER_H_
#define _CL_CONVERTSYSTEMFORGIVENNUMBER_H_

#include"CL_Stack.h"

class CL_ConvertSystemForGivenNumber
{
private:
	CL_Stack* m_pStack;
	
public:
	CL_ConvertSystemForGivenNumber();
	virtual ~CL_ConvertSystemForGivenNumber();
	int ConvertNumber(int ConvertedNumber, int ConvertSystem);
	int PrintResult();
};

#endif