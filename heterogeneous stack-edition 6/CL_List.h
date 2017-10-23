#ifndef _CL_LIST_H_
#define _CL_LIST_H_

#define FLAG_CONTINUE_TRAVERSE 1

class CL_List;

class CL_ListNode
{
private:
	CL_ListNode* prev;
	CL_ListNode* next;
	void* data;
	
public:
	CL_ListNode();
	virtual ~CL_ListNode();
	friend class CL_List;
	friend class CL_MultiStack;
};

class func_class
{
public:
	virtual int operator() (CL_List* l_list, CL_ListNode* ThisNode) const {return 0;}
};

class CL_List
{
private:
	int NodeCount;
	CL_ListNode* HeadNode;
	
public:
	CL_List();
	
	virtual ~CL_List();
	
	int InsertNode(CL_ListNode* LastNode, CL_ListNode* ThisNode);

	int DeleteNode(CL_ListNode* ThisNode);

	int GetNodeCount();

	int TraverseList(func_class& func);

	int ClearList();
	friend class CL_MultiStack;
};

#endif