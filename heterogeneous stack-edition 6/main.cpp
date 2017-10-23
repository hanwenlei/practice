#include<string.h>
#include"test.h"
#include"CL_Expression.h"
#include"CL_ConvertSystemForGivenNumber.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CL_TestClass TempTest;

	TempTest.test_PushElementToStack();

	TempTest.test_PopElementFromStack();

	TempTest.test_TopElementFromStack();

	TempTest.test_GetNodeCountForStack();

	TempTest.test_ClearTheStack();
	
	char* temp = new char[40];
	gets(temp);
	CL_Expression TempExp(strlen(temp)+1);
	char* result = TempExp.EvaluateExp(temp);
	printf("%s\n%.0lf\n", result, TempExp.GetResult());
	
	int ConvertedNumber = 0, ConvertSystem = 0;
	CL_ConvertSystemForGivenNumber TempConvert(40);
	
	scanf("%d%d", &ConvertedNumber, &ConvertSystem);
	TempConvert.ConvertNumber(ConvertedNumber, ConvertSystem);
	TempConvert.PrintResult();
	
	delete [] temp;
	return 0;
}