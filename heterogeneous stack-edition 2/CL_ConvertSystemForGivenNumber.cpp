#include"CL_ConvertSystemForGivenNumber.h"
#include"child_class.h"

CL_ConvertSystemForGivenNumber::CL_ConvertSystemForGivenNumber(int size)
{
	m_pStack = new CL_Stack(size);
}

CL_ConvertSystemForGivenNumber::~CL_ConvertSystemForGivenNumber()
{
	delete m_pStack;
}

int CL_ConvertSystemForGivenNumber::ConvertNumber(int ConvertedNumber, int ConvertSystem)
{
	if(ConvertSystem < 2)
	{
		#if _DEBUG
		printf("进制参数传入错误！");
		#endif
		return -1;
	}
	
	int TempInt = 0;
	CL_IntNode TempNode(TempInt);
	
	while(ConvertedNumber != 0)
    {
    	TempInt = ConvertedNumber % ConvertSystem;
    	TempNode.SetInt(TempInt);
    	m_pStack->PushElement(&TempNode);
    	ConvertedNumber /= ConvertSystem;
	}
	
	return 0;
}

int CL_ConvertSystemForGivenNumber::PrintResult()
{
	CL_IntNode* temp = NULL;
	int count = m_pStack->GetNodeCount();
	
	while(count != 0)  
    { 
    	temp = (CL_IntNode*)m_pStack->PopElement();
    	int cnt = temp->m_data;
    	if(cnt >= 10)
		{
			cnt += 'A' - 10;
			printf("%c", cnt);
		}  
		else
		{
			printf("%d", cnt);
		}
		count--;
    }  
    printf("\n");
    return 0;
}