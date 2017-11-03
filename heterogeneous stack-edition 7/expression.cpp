#include<stdio.h>
#include<stdlib.h>
#include"expression.h"

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

double EvaluateExp(SS_IStack* OpterStack, SS_IStack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)
{
	int count = 0;         
    char c = getchar();
	char TempChar = '#';
	double TempDouble = 0;
	OpterStack->m_PushFunction(OpterStack, &TempChar, l_opter, l_free);
	
    while (c != '#' || *(char*)(OpterStack->m_TopFunction(OpterStack)->pdata) != '#')      
    {  
        if (c >= '0' && c <= '9')      
        {  
            if (count == 1)     
            {  
                double temp = *(double*)(OpvalStack->m_PopFunction(OpvalStack)->pdata);
				TempDouble = temp*10+(c-'0');
                OpvalStack->m_PushFunction(OpvalStack, &TempDouble, l_opval, l_free);
                count = 1;  
            }  
            else  
            {  
            	TempDouble = c-'0';
            	OpvalStack->m_PushFunction(OpvalStack, &TempDouble, l_opval, l_free);      
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

double PrintExp(char* ch, SS_IStack* OpterStack, SS_IStack* OpvalStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)
{
	char TempChar = 0;
	double TempDouble = 0;
	switch (GetPriority(*(char*)(OpterStack->m_TopFunction(OpterStack)->pdata), *ch))   
    {  
    	case '<': 
            TempChar = *ch;
			OpterStack->m_PushFunction(OpterStack, &TempChar, l_opter, l_free);
			*ch = getchar();               
            break;  
        case '=':
			OpterStack->m_PopFunction(OpterStack);
			*ch = getchar();                 
            break;  
        case '>':                 
            char opter = *(char*)(OpterStack->m_PopFunction(OpterStack)->pdata);  
            double opval_a = *(double*)(OpvalStack->m_PopFunction(OpvalStack)->pdata);  
            double opval_b = *(double*)(OpvalStack->m_PopFunction(OpvalStack)->pdata);
			TempDouble = Calculate(opval_b, opter, opval_a);
            OpvalStack->m_PushFunction(OpvalStack, &TempDouble, l_opval, l_free);
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