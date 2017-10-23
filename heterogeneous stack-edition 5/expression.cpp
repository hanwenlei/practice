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
	SL_List* OpterListStack = (SL_List*)malloc(sizeof(SL_List));
	SL_List* OpvalListStack = (SL_List*)malloc(sizeof(SL_List));
	InitHeadNode(OpterListStack);
	InitHeadNode(OpvalListStack);
	InitialStack(OpterListStack);
	InitialStack(OpvalListStack);    
    
    double TempDouble = HelpEvaluateExp(OpterListStack, OpvalListStack, l_opval, l_opter, l_free);
    
    ClearTheStack(OpterListStack);
    ClearTheStack(OpvalListStack);
    free(OpterListStack);
    free(OpvalListStack);
    return TempDouble;     
}

double HelpEvaluateExp(SL_List* OpterListStack, SL_List* OpvalListStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)
{
	int count = 0;         
    char c = getchar();
	char TempChar = '#';
	double TempDouble = 0;
	PushElementToStack(OpterListStack, &TempChar, l_opter, l_free);
	
    while (c != '#' || *(char*)(TopElementFromStack(OpterListStack)->data) != '#')      
    {  
        if (c >= '0' && c <= '9')      
        {  
            if (count == 1)     
            {  
                double temp = *(double*)(PopElementFromStack(OpvalListStack)->data);
				TempDouble = temp*10+(c-'0');
                PushElementToStack(OpvalListStack, &TempDouble, l_opval, l_free);
                count = 1;  
            }  
            else  
            {  
            	TempDouble = c-'0';
            	PushElementToStack(OpvalListStack, &TempDouble, l_opval, l_free);      
                count++;  
            }  
            c = getchar();  
        }  
        else  
        {  
            count = 0;     
            TempDouble = PrintExp(&c, OpterListStack, OpvalListStack, l_opval, l_opter, l_free);  
        }  
    }  
    printf("\n");
    return TempDouble;
}

double PrintExp(char* ch, SL_List* OpterListStack, SL_List* OpvalListStack, CopyFunction l_opval, CopyFunction l_opter, FreeFunction l_free)
{
	char TempChar = 0;
	double TempDouble = 0;
	switch (GetPriority(*(char*)(TopElementFromStack(OpterListStack)->data), *ch))   
    {  
    	case '<': 
            TempChar = *ch;
			PushElementToStack(OpterListStack, &TempChar, l_opter, l_free);
			*ch = getchar();               
            break;  
        case '=':
			PopElementFromStack(OpterListStack);
			*ch = getchar();                 
            break;  
        case '>':                 
            char opter = *(char*)(PopElementFromStack(OpterListStack)->data);  
            double opval_a = *(double*)(PopElementFromStack(OpvalListStack)->data);  
            double opval_b = *(double*)(PopElementFromStack(OpvalListStack)->data);
			TempDouble = Calculate(opval_b, opter, opval_a);
            PushElementToStack(OpvalListStack, &TempDouble, l_opval, l_free);
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