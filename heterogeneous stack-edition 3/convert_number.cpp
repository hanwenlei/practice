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

int Convert(int ConvertedNumber, int ResultSystem, CopyFunction l_copy, FreeFunction l_free)
{
	SS_Node* TempNode;
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack);  
	int TempInt = 0;
	
    while(ConvertedNumber != 0)
    {
    	TempInt = ConvertedNumber % ResultSystem;
    	PushElement(l_stack, &TempInt, l_copy, l_free);
    	ConvertedNumber /= ResultSystem;
	}
	   
    while(l_stack->NodeCount != 0)  
    { 
    	TempNode = PopElement(l_stack);
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
    free(l_stack);
    return 0;
}