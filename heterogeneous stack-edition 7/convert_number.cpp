#include<stdio.h>
#include<stdlib.h>
#include"convert_number.h"

void* CopyInt(void* pElement)
{
	void* Element = malloc(sizeof(int));
	*(int*)Element = *(int*)pElement;
	return Element;
}

void FreeFunc(void* pElement)
{
	free(pElement);
}

int Convert(SS_IStack* l_stack, int ConvertedNumber, int ResultSystem, CopyFunction l_copy, FreeFunction l_free)
{
	SS_Node* TempNode; 
	int TempInt = 0;
    while(ConvertedNumber != 0)
    {
    	TempInt = ConvertedNumber % ResultSystem;
    	l_stack->m_PushFunction(l_stack, &TempInt, l_copy, l_free);
    	ConvertedNumber /= ResultSystem;
	}

    while(l_stack->m_GetNodeCount(l_stack) != 0)
    { 
    	TempNode = l_stack->m_PopFunction(l_stack);
    	int cnt = *(int*)(TempNode->pdata);
    	if(cnt >= 10)
		{
			cnt += 'A' - 10;
			printf("%c", cnt);
		}  
		else
		{
			printf("%d", cnt);
		}  
    }  
    printf("\n");
    return 0;
}