#include<stdio.h>
#define N 50

int main(void)
{
	int i = 0, j = 0, n = 0;
	int a[N][N][N] = {0, 0, 0};
	printf("n = ");
	scanf("%d", &n);
	j = n*(n+1) / 2;
	for(i = 1; i <= j; i++)
	{
		scanf("%d", &a[0][0][i]);
		a[0][i][0] = a[0][0][i];
		a[i][0][0] = 0;
	}
	for(i = n-1; i >= 0; i--)
	{
		int temp1 = i*(i-1)/2 + 1;
		int temp2 = i*(i+1)/2 + 1;
		for(j = 1; j <= i; j++)
		{
			if(a[0][temp2][0] > a[0][temp2+1][0])
			{
				a[0][temp1][0] += a[0][temp2][0];
				a[temp2][0][0] = -1;
			}
			else
			{
				a[0][temp1][0] += a[0][temp2+1][0];
				a[temp2+1][0][0] = 1;
			}
			temp1++;
			temp2++;
		}
	}
	printf("max = %d\n", a[0][1][0]);
	for(j = i = 1; i < n; i++)
	{
		printf("%d->", a[0][0][j]);
		if(a[i+j][0][0] == -1)
		{
			j = i + j;
		}
		else
		{
			j = i + j + 1;
		}
	}
	printf("%d", a[0][0][j]);
	return 0;
}
