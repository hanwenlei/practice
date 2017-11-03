#include<stdio.h>
#include<math.h>

double f(double x)
{
	double temp = x*x;
	double result = 2*temp*x - 4*temp + 3*x - 6;
	return result; 
}

int main(void)
{
	double a = 1, b = 3, mid = 0, result = 1;
	while(fabs(result) >= 1e-4)
	{
		mid = (a + b) / 2;
		result = f(mid);
		if(result < 0)
		{
			a = mid;
		}
		else
		{
			b = mid;
		}
	}
	printf("%.8lf", mid);
	return 0;
}
