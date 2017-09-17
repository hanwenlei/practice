#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define N 1000000

double max(double a, double b)
{
	double aa = a*a;
	double bb = b*b;
	if(aa > bb)
	{
		return aa;
	}
	else
	{
		return bb;
	}
}

double min(double a, double b)
{
	if(a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main(void)
{
	double a = 0, b = 0, x = 0, y = 0, h = 0, result = 0;
	int i = 0, cnt = 0;
	srand(time(0));
	printf("a b = ");
	scanf("%lf%lf", &a, &b);
	h = max(a, b);
	for(i = 0; i < N; i++)
	{
		if(a*b > 0)
		{
			a = fabs(a);
			b = fabs(b);
		}
		x = rand()%((int)fabs(a-b)*1000)/1000.0+min(a, b);
		y = rand()%((int)h*1000)/1000.0;
		if(y < x*x)
		{
			cnt++;
		}
	}
	result = cnt*fabs(a-b)*h/N;
	printf("%.6lf", result);
	return 0;
}
