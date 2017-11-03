#include<stdio.h>
#include<string.h>
#define N 100
#define SWAP(x,y,t) t=x;x=y;y=t

int f(char* a, int i, int n, long int* k)
{
	int j = 0, temp = 0;
	if(i == n)
	{
		for(j = 0; j <= n; j++)
		{
			printf("%4c", a[j]);
		}
		(*k)++;
		printf("\n");
	}
	else
	{
		for(j = i; j <= n; j++)
		{
			SWAP(a[i],a[j],temp);
			f(a, i+1, n, k);
			SWAP(a[i], a[j], temp);
		}
	}
	return 0;
}

int main(void)
{
	char a[N];
	long int k = 0;
	scanf("%s", a);
	int n = strlen(a);
	f(a, 0, n-1, &k);
	printf("perm(%s) = %ld\n", a, k);
	return 0;
}
