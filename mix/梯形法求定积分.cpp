#include<stdio.h>
#define N 10000000

typedef double (*function)(double x);

double f1(double x)
{
	return x*x + 1;
}

double f2(double x)
{
	double temp = x*x;
	return temp*x + temp + x + 1; 
}

double f3(double x)
{
	return x / (x*x + 1);
}

double s(double a, double b, function f)
{
	double h = (b - a) / N;
	double sum = (f(a) + f(b)) / 2;
	double result = 0;
	int i = 0;
	for(i = 1; i < N; i++)
	{
		sum += f(a + i*h);
	}
	result = sum * h;
	return result;
}

int main(void)
{
	printf("%.8lf\n%.8lf\n%.8lf", s(0, 1, f1), s(0, 2, f2), s(0, 3.5, f3));
	return 0;
}
