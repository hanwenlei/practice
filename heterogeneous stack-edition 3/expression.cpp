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

double EvaluateExp(CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)     
{  
	SS_Stack* OpterStack = (SS_Stack*)malloc(sizeof(SS_Stack));
	SS_Stack* OpvalStack = (SS_Stack*)malloc(sizeof(SS_Stack));
	InitStack(OpterStack);
	InitStack(OpvalStack);    
    
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
	
    while (c != '#' || *(char*)(TopElement(OpterStack)->pdata) != '#')      
    {  
        if (c >= '0' && c <= '9')      
        {  
            if (count == 1)     
            {  
                double temp = *(double*)(PopElement(OpvalStack)->pdata);
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
	switch (GetPriority(*(char*)(TopElement(OpterStack)->pdata), *ch))   
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
            char opter = *(char*)(PopElement(OpterStack)->pdata);  
            double opval_a = *(double*)(PopElement(OpvalStack)->pdata);  
            double opval_b = *(double*)(PopElement(OpvalStack)->pdata);
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