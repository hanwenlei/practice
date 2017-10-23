#include"CL_Expression.h"
#include"child_class.h"

CL_Expression::CL_Expression(int size):m_result(0)
{
	m_pResult = new char[size];
	OpterStack = new CL_Stack;
	OpvalStack = new CL_Stack;
}

CL_Expression::~CL_Expression()
{
	delete [] m_pResult;
	delete OpterStack;
	delete OpvalStack;
}

double CL_Expression::GetResult()
{
	return m_result;
}

int CL_Expression::GetIndex(char opter)      
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

char CL_Expression::GetPriority(char opter1, char opter2)  
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

double CL_Expression::Calculate(double b, char opter, double a)     
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

char* CL_Expression::EvaluateExp(char* input)     
{
    m_result = HelpEvaluateExp(input);
    return m_pResult;     
}

double CL_Expression::HelpEvaluateExp(char* input)
{
	static int InputCount = 0;
    char c = input[InputCount++];
	char TempChar = '#';
	CL_OpterNode TempOpter(TempChar);
	OpterStack->PushElement(&TempOpter);
	CL_OpterNode* ptemp = (CL_OpterNode*)OpterStack->TopElement();
	int count = 0;
	double TempDouble = 0;
	
    while (c != '#' || ptemp->m_opter != '#')      
    {  
        if (c >= '0' && c <= '9')      
        {  
            if (count == 1)     
            {
            	CL_OpvalNode* temp = NULL;
            	temp = (CL_OpvalNode*)OpvalStack->TopElement();
            	TempDouble = (temp->m_opval)*10 + (c-'0');
                temp->SetOpval(TempDouble);
                count = 1;  
            }  
            else  
            {  
            	TempDouble = c-'0';
            	CL_OpvalNode TempOpval(TempDouble);
            	OpvalStack->PushElement(&TempOpval);      
                count++;  
            }  
            c = input[InputCount++];  
        }  
        else  
        {  
            count = 0;     
            TempDouble = ResultExp(input, &c, &InputCount);  
        }
		ptemp = (CL_OpterNode*)OpterStack->TopElement();  
    }  
    return TempDouble;
}

double CL_Expression::ResultExp(char* input, char* ch, int* index)
{
	double TempDouble = 0;
	CL_OpterNode TempOpter(*ch);
	CL_OpterNode* TempNode = (CL_OpterNode*)OpterStack->TopElement();
	char TempChar = 0;
	
	switch (GetPriority(TempNode->m_opter, *ch))   
    {  
    	case '<': 
            TempChar = *ch;
			OpterStack->PushElement(&TempOpter);
			*ch = input[(*index)++];                
            break;  
        case '=':
			OpterStack->PopElement();
			*ch = input[(*index)++];                  
            break;  
        case '>': 
        	TempDouble = PutResult(ch);
	}
	return TempDouble;
}

double CL_Expression::PutResult(char* ch)
{
	static int ResultCount = 0;
    CL_OpvalNode *temp1, *temp2;
	CL_OpterNode* TempNode = (CL_OpterNode*)OpterStack->PopElement();
	temp1 = (CL_OpvalNode*)OpvalStack->PopElement();
	temp2 = (CL_OpvalNode*)OpvalStack->PopElement();
	                
    char opter = TempNode->m_opter;  
    double opval_a = temp1->m_opval;  
    double opval_b = temp2->m_opval;
	double TempDouble = Calculate(opval_b, opter, opval_a);
	CL_OpvalNode TempOpval(TempDouble);
    OpvalStack->PushElement(&TempOpval);
    
	if(*ch != '#')
	{
		char temp1 = (int)opval_b / 10;
		char temp2 = (int)opval_b % 10;
		if(temp1 != 0)
		{
			m_pResult[ResultCount++] = temp1 + '0';
		}
		m_pResult[ResultCount++] = temp2 + '0';
		temp1 = (int)opval_a / 10;
		temp2 = (int)opval_a % 10;
		if(temp1 != 0)
		{
			m_pResult[ResultCount++] = temp1 + '0';
		}
		m_pResult[ResultCount++] = temp2 + '0';
		m_pResult[ResultCount++] = opter;  
	}
	else
	{
		m_pResult[ResultCount++] = opter;
		m_pResult[ResultCount] = '\0';
	}
	return TempDouble;
}