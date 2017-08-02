#include<stdio.h>
#include"heterogeneous_list.h"

int InitHeadNode(SL_List* l_list)
{
	l_list->HeadNode = NULL;
	l_list->NodeCount = 0;

	return 0;
}

int InsertNode(SL_Node* LastNode, SL_Node* ThisNode, SL_List* l_list)
{
	if(l_list->NodeCount == 0)
	{
		l_list->HeadNode = ThisNode;
		ThisNode->next = ThisNode;
		ThisNode->prev = ThisNode;
		l_list->NodeCount++;
	}
	else
	{
		ThisNode->next = LastNode->next;
		ThisNode->prev = LastNode;
		LastNode->next = ThisNode;
		ThisNode->next->prev = ThisNode;

		l_list->NodeCount++;
	}
	return 0;
}

int DeleteNode(SL_Node* ThisNode, SL_List* l_list)
{
	if(l_list->NodeCount == 1)
	{
		if(l_list->HeadNode == ThisNode)
		{
			l_list->HeadNode = NULL;
			l_list->NodeCount--;
		}
		else
		{
			#if _DEBUG
			return -1;
			#else
			printf("传入节点错误!\n");
			#endif
		}
	}
	else
	{
		SL_Node* SL_temppoint = ThisNode;
		SL_temppoint->prev->next = SL_temppoint->next;
		SL_temppoint->next->prev = SL_temppoint->prev;
		SL_temppoint->prev = NULL;
		SL_temppoint->next = NULL;

		l_list->NodeCount--;
	}
	return 0;
}

int GetNodeCount(SL_List* l_list)
{
	return l_list->NodeCount;
}

int TraverseList(SL_List* l_list, FunctionPoint l_UserFuncPoint)
{
	int i = 0; 
	if(l_list->NodeCount != 0)
	{
		int TraverseFlag = FLAG_CONTINUE_TRAVERSE;
		SL_Node* SL_temp = l_list->HeadNode->next;

		for(i = 0; i < l_list->NodeCount; i++)
		{
			TraverseFlag = l_UserFuncPoint(l_list, SL_temp->prev);
			if(TraverseFlag == FLAG_CONTINUE_TRAVERSE)
			{
				SL_temp = SL_temp->next;
			}
			else
			{
				break;
			}
		}

	}
	return 0;
}
