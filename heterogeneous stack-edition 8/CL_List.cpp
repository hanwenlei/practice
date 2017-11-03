#include<cstdio>
#include"CL_List.h"

CL_ListNode::CL_ListNode():prev(0), next(0), data(0){}

CL_ListNode::~CL_ListNode(){}

CL_List::CL_List():HeadNode(NULL), NodeCount(0){}
	
CL_List::~CL_List(){}

int CL_List::InsertNode(CL_ListNode* LastNode, CL_ListNode* ThisNode)
{
	if(NodeCount == 0)
	{
		HeadNode = ThisNode;
		ThisNode->next = ThisNode;
		ThisNode->prev = ThisNode;
		NodeCount++;
	}
	else
	{
		ThisNode->next = LastNode->next;
		ThisNode->prev = LastNode;
		LastNode->next = ThisNode;
		ThisNode->next->prev = ThisNode;
		NodeCount++;
	}
	return 0;
}

int CL_List::DeleteNode(CL_ListNode* ThisNode)
{
	if(NodeCount == 1)
	{
		if(HeadNode == ThisNode)
		{
			HeadNode = NULL;
			NodeCount--;
		}
		else
		{
			#if _DEBUG
			printf("传入节点错误!\n");
			#endif
			return -1;
		}
	}
	else
	{
		CL_ListNode* CL_temppoint = ThisNode;
		CL_temppoint->prev->next = CL_temppoint->next;
		CL_temppoint->next->prev = CL_temppoint->prev;
		CL_temppoint->prev = NULL;
		CL_temppoint->next = NULL;
		NodeCount--;
	}
	return 0;
}

int CL_List::GetNodeCount()
{
	return NodeCount;
}

int CL_List::TraverseList(func_class& func)
{
	int i = 0; 
	if(NodeCount != 0)
	{
		int TraverseFlag = FLAG_CONTINUE_TRAVERSE;
		CL_ListNode* TempNode = HeadNode->next;
		
		for(i = 1; i < NodeCount; i++)
		{
			TraverseFlag = func(this, TempNode->prev);
			if(TraverseFlag == FLAG_CONTINUE_TRAVERSE)
			{
				TempNode = TempNode->next;
			}
			else
			{
				break;
			}
		}
		
	}
	return 0;
}

int CL_List::ClearList()
{
	int i = 0;
	if(HeadNode == NULL)
	{
		#if _DEBUG
		printf("链表为空!\n");
		#endif
		return -1;
	}
	else if(NodeCount == 1)
	{
		delete HeadNode;
	}
	else
	{
		CL_ListNode* TempNode1 = HeadNode;
		CL_ListNode* TempNode2 = HeadNode;
		
		for(i = 0; i < NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->next;
			delete TempNode1;
		}
	}
	HeadNode = NULL;
	NodeCount = 0;
	return 0;
}