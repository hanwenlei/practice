#include"heterogeneous_stack.h"

int InitStack(SS_Stack* l_stack, int size)
{
	l_stack->HeadNode = (SS_Node*)malloc(size*sizeof(SS_Node));
	l_stack->size = size;
	l_stack->TopNode = l_stack->HeadNode;
	l_stack->NodeCount = 0;
	return 0;
}

int PushElement(SS_Stack* l_stack, void* pElement, CopyFunction l_CopyFunction, FreeFunction l_FreeFunction)
{
	if(l_stack->NodeCount >= l_stack->size)
	{
		#if DEBUG
		printf("Õ»ÒÑÂú!\n");
		#endif
		return -1;
	}
	else
	{ 
		l_stack->TopNode->data = l_CopyFunction(pElement);
		l_stack->TopNode->m_CopyFunction = l_CopyFunction;
		l_stack->TopNode->m_FreeFunction = l_FreeFunction;
		l_stack->TopNode++;
		l_stack->NodeCount++;
	}
	return 0;
}

SS_Node* PopElement(SS_Stack* l_stack)
{
	if(l_stack->NodeCount <= 0)
	{
		#if DEBUG
		printf("Õ»ÒÑ¿Õ!\n");
		#endif
		return NULL;
	}
	else
	{
		l_stack->TopNode--;
		l_stack->NodeCount--;
	} 
	return l_stack->TopNode; 
}

SS_Node* TopElement(SS_Stack* l_stack)
{
	SS_Node* TempNode = l_stack->TopNode - 1;
	return TempNode;
}

int GetNodeCount(SS_Stack* l_stack)
{
	return l_stack->NodeCount;
}

int ClearStack(SS_Stack* l_stack)
{
	SS_Node* TempNode = l_stack->HeadNode;
	int i = 0;
	for(i = 0; i < l_stack->NodeCount; i++)
	{
		TempNode->m_FreeFunction(TempNode->data);
		TempNode++;
	}
	
	free(l_stack->HeadNode);
	l_stack->size = 0;
	l_stack->HeadNode = NULL;
	l_stack->TopNode = NULL;
	l_stack->NodeCount = 0;
	return 0;
}