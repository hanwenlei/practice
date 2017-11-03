#ifndef _CL_ISTACK_H_
#define _CL_ISTACK_H_

#include"IStackNode.h"

class CL_IStack
{
protected:
	int m_NodeCount;
	
public:
	CL_IStack();
	virtual int PushElement(IStackNode* pElement) = 0;
	virtual IStackNode* PopElement() = 0;
	virtual IStackNode* TopElement() = 0;
	virtual int GetNodeCount() = 0;
	virtual int ClearStack() = 0;
	virtual ~CL_IStack();
};

#endif