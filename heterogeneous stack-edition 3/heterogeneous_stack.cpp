#include"heterogeneous_stack.h"

int InitStack(SS_Stack* l_stack)
{
	l_stack->pTopNode = NULL;
	l_stack->NodeCount = 0;
	return 0;
}

int PushElement(SS_Stack* l_stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	SS_Node* TempNode = (SS_Node*)malloc(sizeof(SS_Node));
	TempNode->pdata = l_CopyFunction(pElement);
	TempNode->m_CopyFunction = l_CopyFunction;
	TempNode->m_FreeFunction = l_FreeFunction;
	if(l_stack->NodeCount == 0)
	{
		TempNode->next = NULL;
	}
	else
	{
		TempNode->next = l_stack->pTopNode;
	}
	
	l_stack->pTopNode = TempNode;
	l_stack->NodeCount++;
	return 0;
}

SS_Node* PopElement(SS_Stack* l_stack)
{
	SS_Node* TempNode = l_stack->pTopNode;
	if(l_stack->NodeCount <= 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
	}
	else
	{
		l_stack->pTopNode = TempNode->next;
		TempNode->next = NULL;
		l_stack->NodeCount--;
	} 
	return TempNode; 
}

SS_Node* TopElement(SS_Stack* l_stack)
{
	return l_stack->pTopNode;
}

int GetNodeCount(SS_Stack* l_stack)
{
	return l_stack->NodeCount;
}

int ClearStack(SS_Stack* l_stack)
{
	if(l_stack->NodeCount == 0)
	{
		#if _DEBUG
		printf("у╩ря©у!\n");
		#endif
		return -1;
	}
	else if(l_stack->NodeCount == 1)
	{
		l_stack->pTopNode->m_FreeFunction(l_stack->pTopNode->pdata);
	}
	else
	{
		SS_Node* TempNode1 = l_stack->pTopNode;
		SS_Node* TempNode2 = l_stack->pTopNode;
		for(int i = 0; i < l_stack->NodeCount; i++)
		{
			TempNode1 = TempNode2;
			TempNode2 = TempNode2->next;
			TempNode1->m_FreeFunction(TempNode1->pdata);
			free(TempNode1);
		}
	}

	l_stack->pTopNode = NULL;
	l_stack->NodeCount = 0;
	return 0;
}