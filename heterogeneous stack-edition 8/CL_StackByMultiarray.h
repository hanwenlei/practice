#ifndef _CL_STACKBYMULTIARRAY_H_
#define _CL_STACKBYMULTIARRAY_H_

#include"CL_List.h"
#include"CL_StackByArray.h"

class CL_MultiarrayStack : public CL_IStack
{
private:
	CL_List* m_plist;
	CL_ArrayStack* m_pCurrentStack;
	const int StackSize;
	
public:
	CL_MultiarrayStack();
	virtual int PushElement(IStackNode* pElement);
	virtual IStackNode* PopElement();
	virtual IStackNode* TopElement();
	virtual int GetNodeCount();
	virtual int ClearStack();
	virtual ~CL_MultiarrayStack();
};

#endif