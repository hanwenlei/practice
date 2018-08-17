#include<stdio.h>
#define N 100

int main(void)
{
	int i = 0, m = 0, n = 0, r = 0, s = 0;
	int a[N] = {0};
	printf("«Î“¿¥Œ ‰»În£¨m = ");
	scanf("%d%d", &n, &m);
	for(i = 0; i < N; i++)
	{
		a[i] = i + 1;
	}
	for(i = 0; i < n; i++)
	{
		do
		{
			if(a[i] != 0)
			{
				r++;
				if(r == m)
				{
					printf("%d ",a[i]);
					a[i] = 0;
					r = 0;
					s++;
				}
			}
			i++;
			if(i == n)
			{
				i = 0;
			}
		}while(s != n);
	}
	printf("\n");
	return 0;
}
