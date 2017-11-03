#include<string.h>
#include"CL_Expression.h"
#include"CL_ConvertSystemForGivenNumber.h"
#include"test.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CL_TestClass TempTest;
	
	TempTest.test_PushElementToStackByArray();
	
	TempTest.test_PushElementToStackByList();
	
	TempTest.test_PopElementToStackByArray();
	
	TempTest.test_PopElementToStackByList();
	
	CL_ArrayStack* array_stack = new CL_ArrayStack(40);
	CL_ArrayStack* l_stack = new CL_ArrayStack(40);
	CL_ListStack* list_stack = new CL_ListStack;
	CL_MultiarrayStack* multiarray_stack = new CL_MultiarrayStack;
	
	char* temp = new char[40];
	gets(temp);
	CL_Expression TempExp(strlen(temp)+1);
	char* result = TempExp.EvaluateExp(temp, array_stack, l_stack);
	printf("%s\n%.0lf\n", result, TempExp.GetResult());
	
	int ConvertedNumber = 0, ConvertSystem = 0;
	CL_ConvertSystemForGivenNumber TempConvert;
	
	scanf("%d%d", &ConvertedNumber, &ConvertSystem);
	TempConvert.ConvertNumber(ConvertedNumber, ConvertSystem, (CL_IStack*)multiarray_stack);
	TempConvert.PrintResult((CL_IStack*)multiarray_stack);
	
	delete array_stack;
	delete list_stack;
	delete multiarray_stack;
	return 0;
}