#include<stdio.h>
#define N 10

int main(void)
{
	int i = 0, j = 0, t = 0, flag = 0, a[N] = {0};
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 0; i < N-1; i++)
	{
		flag = 0;
		for(j = 0; j < N-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 1;
			}
		}
		if(flag == 0) i = N;
	}
	for(i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
