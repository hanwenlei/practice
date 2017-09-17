#include<stdio.h>

int gcd(int a, int b)
{
	int r = 0;
	while(b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int gcdThree(int a, int b, int c)
{
	return gcd(gcd(a, b), c);
}

int main(void)
{
	int a = 0, b = 0, c = 0;
	int gcdNum = 0, lcmNum = 0, temp = 0;
	printf("a b c = ");
	scanf("%d%d%d", &a, &b, &c);
	temp = gcd(a, b);
	gcdNum = gcdThree(a, b, c);
	lcmNum = (a*b*c)/(temp*gcd(a*b/temp, c));
	printf("最大公约数:%d\n", gcdNum);
	printf("最小公倍数:%d\n", lcmNum);
	return 0;
}
