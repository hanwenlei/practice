#ifndef _CL_STACKBYARRAY_H_
#define _CL_STACKBYARRAY_H_

#include"CL_IStack.h"

class CL_ArrayStack : public CL_IStack
{
private:
	int m_size;
	PIStackNode* m_pHeadNode;
	PIStackNode* m_pTopNode;
	
public:
	CL_ArrayStack(int size);
	virtual int PushElement(IStackNode* pElement);
	virtual IStackNode* PopElement();
	virtual IStackNode* TopElement();
	virtual int GetNodeCount();
	virtual int ClearStack();
	virtual ~CL_ArrayStack();
	friend class CL_MultiarrayStack;
};

#endif