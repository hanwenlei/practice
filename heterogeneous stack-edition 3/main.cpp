#include"expression.h"
#include"convert_number.h"
#include"test.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CopyFunction opval = CopyOpval;
	CopyFunction opter = CopyOpter;
	CopyFunction lInt = CopyInt;
	CopyFunction test_copy = UserCopy;
	FreeFunction lFree = FreeFunc;
	FreeFunction test_free = UserFree;
	
	int ConvertedNumber = 0, ResultSystem = 0;
	double answer = 0;
	
	test_InitStack();

	test_PushElement(test_copy, test_free);

	test_PopElement(test_copy, test_free);

	test_TopElement(test_copy, test_free);

	test_GetNodeCount(test_copy, test_free);

	test_ClearStack(test_copy, test_free);
	
	answer = EvaluateExp(opval, opter, lFree);//输入的表达式以#为结束标志 
	printf("%.0lf\n", answer);
	
	scanf("%d%d", &ConvertedNumber, &ResultSystem);
	Convert(ConvertedNumber, ResultSystem, lInt, lFree);
	
	return 0;
}