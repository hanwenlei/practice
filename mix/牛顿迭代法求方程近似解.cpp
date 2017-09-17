#include<stdio.h>
#include<math.h>

double funValue(double x)
{
	double y = ((2*x-4)*x+3)*x-6;
	return y;
}

double funx(double x)
{
	double xValue = x-funValue(x)/((6*x-8)*x+3);
	return xValue;
}

double func(double x)
{
	double xValue = funx(x);
	double y = funValue(xValue);
	while(fabs(y) > 1e-4)
	{
		xValue = funx(xValue);
		y = funValue(xValue);
	}
	return xValue;
}

int main(void)
{
	double x = 0;
	printf("起始x的值:");
	scanf("%lf", &x);
	printf("x = %5.3lf", func(x));
	return 0;
}
