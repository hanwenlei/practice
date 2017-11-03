#include<stdio.h>
#include<stdlib.h>
#include"stack_by_multiarray.h"

int InitStackByMultiarray(struct SS_IStack* stack, int size)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)stack;
	l_stack->m_plist = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_stack->m_plist);
	SL_Node* TempNode = (SL_Node*)malloc(sizeof(SL_Node));
	InsertNode(l_stack->m_plist->HeadNode, TempNode, l_stack->m_plist);
	
	SS_ArrayStack* TempStack = (SS_ArrayStack*)malloc(sizeof(SS_ArrayStack));
	int flag = InitStackByArray((SS_IStack*)TempStack, StackSize);
	if(flag != 0)
	{
		return -1;
	}
	l_stack->m_plist->HeadNode->data = TempStack;
	l_stack->m_pCurrentStack = TempStack;
	l_stack->NodeCount = 1;
	return 0;
}

int PushElementToStackByMultiarray(struct SS_IStack* stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)stack;
	SL_List* TempList = l_stack->m_plist;
	if(l_stack->m_pCurrentStack->NodeCount >= StackSize)
	{
		if(TempList->HeadNode->prev != TempList->HeadNode)
		{
			TempList->HeadNode->prev = TempList->HeadNode->prev->prev;
			l_stack->m_pCurrentStack = (SS_ArrayStack*)(TempList->HeadNode->prev->data);
		}
		else
		{
			SL_Node* TempNode = (SL_Node*)malloc(sizeof(SL_Node));
			InsertNode(TempList->HeadNode->prev, TempNode, TempList);
			SS_ArrayStack* TempStack = (SS_ArrayStack*)malloc(sizeof(SS_ArrayStack));
			
			int flag = InitStackByArray((SS_IStack*)TempStack, StackSize);
			if(flag != 0)
			{
				return -1;
			}
			else
			{
				TempStack->NodeCount = 0;
				TempNode->data = TempStack;
				l_stack->m_pCurrentStack = TempStack;
			}
		}
	}
	PushElementToStackByArray((SS_IStack*)l_stack->m_pCurrentStack, pElement, l_CopyFunction, l_FreeFunction);
	return 0;
}

SS_Node* PopElementToStackByMultiarray(struct SS_IStack* stack)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)stack;
	SL_Node* TempNode = l_stack->m_plist->HeadNode->prev;
	if(l_stack->m_pCurrentStack->NodeCount <= 0)
	{
		if(l_stack->m_plist->HeadNode->prev->next == l_stack->m_plist->HeadNode)
		{
			#if DEBUG
			printf("у╩ря©у!\n");
			#endif
			return NULL;
		}
		else
		{
			TempNode = TempNode->next;
			l_stack->m_pCurrentStack = (SS_ArrayStack*)(l_stack->m_plist->HeadNode->prev->data);
			l_stack->m_plist->NodeCount--;
		}
	}
	return PopElementToStackByArray((SS_IStack*)l_stack->m_pCurrentStack);
}

SS_Node* TopElementToStackByMultiarray(struct SS_IStack* stack)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)stack;
	SL_Node* TempNode = l_stack->m_plist->HeadNode->prev;
	if(l_stack->m_pCurrentStack->NodeCount <= 0)
	{
		if(l_stack->m_plist->HeadNode->prev->next == l_stack->m_plist->HeadNode)
		{
			#if DEBUG
			printf("у╩ря©у!\n");
			#endif
			return NULL;
		}
		else
		{
			TempNode = TempNode->next;
			l_stack->m_pCurrentStack = (SS_ArrayStack*)(l_stack->m_plist->HeadNode->prev->data);
		}
	}
	return TopElementToStackByArray((SS_IStack*)l_stack->m_pCurrentStack);
}

int GetNodeCountToStackByMultiarray(struct SS_IStack* stack)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)stack;
	int temp = (l_stack->m_plist->NodeCount - 1) * 100 + l_stack->m_pCurrentStack->NodeCount;
	return temp;
}

int ClearStackByMultiarray(struct SS_IStack* stack)
{
	SS_MultiarrayStack* l_stack = (SS_MultiarrayStack*)stack;
	SL_Node* TempListNode = l_stack->m_plist->HeadNode;
	SL_Node* temp = l_stack->m_plist->HeadNode;
	for(int i = 0; i < l_stack->m_plist->NodeCount; i++)
	{
		TempListNode = temp;
		temp = temp->next;
		ClearStackByArray((SS_IStack*)TempListNode->data);
		
		free(TempListNode->data);
		free(TempListNode);
	}
	
	l_stack->m_plist->HeadNode = NULL;
	l_stack->m_plist->NodeCount = 0;
	return 0;
}