#include"multi_heterogeneous_stack.h"

int InitialStack(SL_List* l_list)
{
	SL_Node* TempNode = (SL_Node*)malloc(sizeof(SL_Node));
	InsertNode(l_list->HeadNode, TempNode, l_list);
	
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	int flag = InitStack(l_stack, 100);
	if(flag != 0)
	{
		return -1;
	}
	l_list->HeadNode->data = l_stack;
	return 0;
}

int PushElementToStack(SL_List* l_list, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	if(((SS_Stack*)(l_list->HeadNode->prev->data))->NodeCount >= 100)
	{
		if(l_list->HeadNode->prev->next != l_list->HeadNode)
		{
			l_list->HeadNode->prev = l_list->HeadNode->prev->next;
		}
		else
		{
			SL_Node* TempNode = (SL_Node*)malloc(sizeof(SL_Node));
			InsertNode(l_list->HeadNode->prev, TempNode, l_list);
			
			SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
			int flag = InitStack(l_stack, 100);
			
			if(flag != 0)
			{
				#if _DEBUG
				printf("Õ»ÒÑÂú!\n");
				#endif
				return -1;
			}
			else
			{
				l_stack->TopNode = l_stack->HeadNode;
				l_stack->NodeCount = 0;
				TempNode->data = l_stack;
			}
		}
	}
	PushElement((SS_Stack*)l_list->HeadNode->prev->data, pElement, l_CopyFunction, l_FreeFunction);
	return 0;
}

SS_Node* PopElementFromStack(SL_List* l_list)
{
	SL_Node* TempNode = l_list->HeadNode->prev;
	if(((SS_Stack*)(l_list->HeadNode->data))->NodeCount <= 0)
	{
		#if _DEBUG
		printf("Õ»ÒÑ¿Õ!\n");
		#endif
		return NULL;
	}
	else if(((SS_Stack*)(l_list->HeadNode->prev->data))->NodeCount <= 0)
	{
		TempNode = TempNode->prev;
		l_list->NodeCount--;
	}
	return PopElement((SS_Stack*)TempNode->data);
}

SS_Node* TopElementFromStack(SL_List* l_list)
{
	if(((SS_Stack*)(l_list->HeadNode->data))->NodeCount <= 0)
	{
		#if _DEBUG
		printf("Õ»ÒÑ¿Õ!\n");
		#endif
		return NULL;
	}
	else if(((SS_Stack*)(l_list->HeadNode->prev->data))->NodeCount <= 0)
	{
		l_list->HeadNode->prev = l_list->HeadNode->prev->prev;
	}
	return TopElement((SS_Stack*)(l_list->HeadNode->prev->data));
}

int GetNodeCountForStack(SL_List* l_list)
{
	int temp = (l_list->NodeCount - 1) * 100 + ((SS_Stack*)(l_list->HeadNode->prev->data))->NodeCount;
	return temp;
}

int ClearTheStack(SL_List* l_list)
{
	SL_Node* TempListNode = l_list->HeadNode;
	SL_Node* temp = l_list->HeadNode;
	for(int i = 0; i < l_list->NodeCount; i++)
	{
		TempListNode = temp;
		temp = temp->next;
		SS_Node* TempStackNode = ((SS_Stack*)(TempListNode->data))->HeadNode;
		
		for(int j = 0; j < ((SS_Stack*)(TempListNode->data))->NodeCount; j++)
		{
			TempStackNode->m_FreeFunction(TempStackNode->data);
			TempStackNode++;
		}
		
		free(((SS_Stack*)(TempListNode->data))->HeadNode);
		free(TempListNode->data);
		free(TempListNode);
	}
	
	l_list->HeadNode = NULL;
	l_list->NodeCount = 0;
	return 0;
}