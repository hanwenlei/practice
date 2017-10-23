#ifndef _CL_STACK_H_
#define _CL_STACK_H_

#include<stdio.h>
#include"IStackNode.h"

class CL_Stack
{
private:
	int m_NodeCount;
	IStackNode* m_pTopNode;
	
public:
	CL_Stack();
	
	virtual ~CL_Stack(); 

	int PushElement(IStackNode* pElement);

	IStackNode* PopElement();

	IStackNode* TopElement();

	int GetNodeCount();
	
	int ClearStack();	
};

#endif