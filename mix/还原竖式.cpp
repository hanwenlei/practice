#include<stdio.h>

int divided(int n[], int number)
{
	while(number)
	{
		n[number%10] = 1;
		number /= 10;
	}
	return 0;
}

int main(void)
{
	int i = 0, j = 0, k = 0, cnt = 0, count = 0, n[10] = {0};
	int a = 0, b = 0, temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0;
	for(i = 112; i < 1000; i++)
	{
		for(j = 12; j < 100; j++)
		{
			if(i*j < 10000)
			{
				continue;
			}
			temp3 = i;
			temp4 = j;
			divided(n, temp3);
			divided(n, temp4);
			a = i*(j%10);
			temp1 = a;
			if(temp1 < 1000)
			{
				continue;
			}
			else
			{
				divided(n, temp1);
			}
			b = i*(j/10);
			temp2 = b;
			divided(n, temp2);
			temp5 = i*j;
			divided(n, temp5);
			for(k = 0; k < 10; k++)
			{
				if(n[k])
				{
					cnt++;
				}
				n[k] = 0;
			}
			if(cnt == 4)
			{
				printf("%d * %d = %d (%d + %d0) [%d]\n", i, j, i*j, a, b, count);
				count++;
			}
			cnt = 0;
		}
	}
	return 0;
}
