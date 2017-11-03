#ifndef _CL_STACKBYLIST_H_
#define _CL_STACKBYLIST_H_

#include"CL_IStack.h"
#include"CL_List.h"

class CL_ListStack : public CL_IStack
{
private:
	CL_List* m_plist;
	
public:
	CL_ListStack();
	virtual int PushElement(IStackNode* pElement);
	virtual IStackNode* PopElement();
	virtual IStackNode* TopElement();
	virtual int GetNodeCount();
	virtual int ClearStack();
	virtual ~CL_ListStack();
};

#endif