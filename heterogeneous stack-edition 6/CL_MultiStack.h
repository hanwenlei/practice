#ifndef _CL_MULTI_STACK_H_
#define _CL_MULTI_STACK_H_

#include"CL_Stack.h"
#include"CL_List.h"

class CL_MultiStack
{
private:
	CL_List* m_plist;
	CL_Stack* m_pCurrentStack;
	const int StackSize;
	
	int ExpandStack();

	bool IsEmpty();
	
public:
	CL_MultiStack();
	
	virtual ~CL_MultiStack();

	int PushElementToStack(void* pElement);

	IStackNode* PopElementFromStack();

	IStackNode* TopElementFromStack();

	int GetNodeCountForStack();

	int ClearTheStack();
};

#endif