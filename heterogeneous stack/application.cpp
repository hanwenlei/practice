#include"application.h"

void* CopyOpval(void* pElement)
{
	void* Element = malloc(sizeof(double));
	*(double*)Element = *(double*)pElement;
	return Element;
}

void* CopyOpter(void* pElement)
{
	void* Element = malloc(sizeof(char));
	*(char*)Element = *(char*)pElement;
	return Element;
}

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

int GetIndex(char opter)      
{  
    int index = 0;  
    switch (opter)  
    {  
    	case '+':  
       		index = 0;  
        	break;  
    	case '-':  
        	index = 1;  
        	break;  
    	case '*':  
        	index = 2;  
        	break;  
    	case '/':  
        	index = 3;  
        	break;  
    	case '(':  
        	index = 4;  
        	break;  
    	case ')':  
        	index = 5;  
        	break;  
    	case '#':  
        	index = 6;  
    	default:break;  
    }  
    return index;  
}

char GetPriority(char opter1, char opter2)  
{  
    const char priority[][7] = 
	{ 
        { '>','>','<','<','<','>','>' },  
        { '>','>','<','<','<','>','>' },  
        { '>','>','>','>','<','>','>' },  
        { '>','>','>','>','<','>','>' },  
        { '<','<','<','<','<','=','0' },  
        { '>','>','>','>','0','>','>' },  
        { '<','<','<','<','<','0','=' },  
    };  
    int index1 = GetIndex(opter1);  
    int index2 = GetIndex(opter2);  
    return priority[index1][index2];  
}

double Calculate(double b, char opter, double a)     
{  
    switch (opter)  
    {  
    case '+':  
        return b + a;  
    case '-':  
        return b - a;  
    case '*':  
        return b * a;  
    case '/':  
        return b / a;  
    }  
	return 0;
}

double EvaluateExp(CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)     
{  
	SS_Stack* OpterStack = (SS_Stack*)malloc(sizeof(SS_Stack));
	SS_Stack* OpvalStack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(OpterStack, 40);
	InitStack(OpvalStack, 40);    
    
    double TempDouble = HelpEvaluateExp(OpterStack, OpvalStack, l_opval, l_opter, l_free);
    
    ClearStack(OpterStack);
    ClearStack(OpvalStack);
    free(OpterStack);
    free(OpvalStack);
    return TempDouble;     
}

double HelpEvaluateExp(SS_Stack* OpterStack, SS_Stack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)
{
	int count = 0;         
    char c = getchar();
	char TempChar = '#';
	double TempDouble = 0;
	PushElement(OpterStack, &TempChar, l_opter, l_free);
	
    while (c != '#' || *(char*)(TopElement(OpterStack)->data) != '#')      
    {  
        if (c >= '0' && c <= '9')      
        {  
            if (count == 1)     
            {  
                double temp = *(double*)(PopElement(OpvalStack)->data);
				TempDouble = temp*10+(c-'0');
                PushElement(OpvalStack, &TempDouble, l_opval, l_free);
                count = 1;  
            }  
            else  
            {  
            	TempDouble = c-'0';
            	PushElement(OpvalStack, &TempDouble, l_opval, l_free);      
                count++;  
            }  
            c = getchar();  
        }  
        else  
        {  
            count = 0;     
            TempDouble = PrintExp(&c, OpterStack, OpvalStack, l_opval, l_opter, l_free);  
        }  
    }  
    printf("\n");
    return TempDouble;
}

double PrintExp(char* ch, SS_Stack* OpterStack, SS_Stack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)
{
	char TempChar = 0;
	double TempDouble = 0;
	switch (GetPriority(*(char*)(TopElement(OpterStack)->data), *ch))   
    {  
    	case '<': 
            TempChar = *ch;
			PushElement(OpterStack, &TempChar, l_opter, l_free);
			*ch = getchar();               
            break;  
        case '=':
			PopElement(OpterStack);
			*ch = getchar();                 
            break;  
        case '>':                 
            char opter = *(char*)(PopElement(OpterStack)->data);  
            double opval_a = *(double*)(PopElement(OpvalStack)->data);  
            double opval_b = *(double*)(PopElement(OpvalStack)->data);
			TempDouble = Calculate(opval_b, opter, opval_a);
            PushElement(OpvalStack, &TempDouble, l_opval, l_free);
			if(*ch != '#')
			{
				printf("%.0lf%.0lf%c", opval_b, opval_a, opter); 
			}
			else
			{
				printf("%c", opter);
			}
	}
	return TempDouble;
}

int Convert(int ConvertedNumber, int ResultSystem, CopyFunction l_copy, FreeFunction l_free)
{
	SS_Node* TempNode;
	SS_Stack* l_stack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(l_stack, 40);  
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
    	int cnt = *(int*)(TempNode->data);
    	if(cnt > 9)
		{
			cnt += 55;
			printf("%c", cnt);
		}  
		else
		{
			printf("%d", cnt);
		}  
    }  
    printf("\n");
    ClearStack(l_stack);
    free(l_stack);
    return 0;
}