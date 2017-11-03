#include"CL_ConvertSystemForGivenNumber.h"
#include"CL_ChildrenNode.h"

CL_ConvertSystemForGivenNumber::CL_ConvertSystemForGivenNumber(){}

CL_ConvertSystemForGivenNumber::~CL_ConvertSystemForGivenNumber(){}

int CL_ConvertSystemForGivenNumber::ConvertNumber(int ConvertedNumber, int ConvertSystem, CL_IStack* pStack)
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
    	pStack->PushElement(&TempNode);
    	ConvertedNumber /= ConvertSystem;
	}
	
	return 0;
}

int CL_ConvertSystemForGivenNumber::PrintResult(CL_IStack* pStack)
{
	CL_IntNode* temp = NULL;
	int count = pStack->GetNodeCount();
	
	while(count != 0)  
    { 
    	temp = (CL_IntNode*)pStack->PopElement();
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