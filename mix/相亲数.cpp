#include<stdio.h>
#define N 30000

int main(void)
{
	int i = 0, j = 0, k = 0;
	unsigned int s[N];
	for(i = 2; i < N; i++)
	{
		for(j = 1, s[i] = 0; j < i; j++)
		{
			if(i % j == 0)
			{
				s[i] += j;
			}
		}
	}
	for(i = 2; i < N; i++)
	{
		if(s[i] < N && i == s[s[i]] && i != s[i])
		{
			printf("%d:", i);
			for(k = 1; k < i; k++)
			{
				if(i % k ==0)
				{
					printf("%d ", k);
				}
			}
			printf("\n%d:", s[i]);
			for(k = 1; k < s[i]; k++)
			{
				if(s[i] % k == 0)
				{
					printf("%d ", k);
				}
			}
			printf("\n\n");
		}
		s[i] = 0;
	}
	return 0;
}
