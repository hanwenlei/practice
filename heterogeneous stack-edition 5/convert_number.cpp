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
	SL_List* l_list = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(l_list);
	InitialStack(l_list);  
	int TempInt = 0;
	
    while(ConvertedNumber != 0)
    {
    	TempInt = ConvertedNumber % ResultSystem;
    	PushElementToStack(l_list, &TempInt, l_copy, l_free);
    	ConvertedNumber /= ResultSystem;
	}
	   
    while(((SS_Stack*)(l_list->HeadNode->data))->NodeCount != 0)  
    { 
    	TempNode = PopElementFromStack(l_list);
    	int cnt = *(int*)(TempNode->data);
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
    ClearTheStack(l_list);
    free(l_list);
    return 0;
}