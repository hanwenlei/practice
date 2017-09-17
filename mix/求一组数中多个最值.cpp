#include<stdio.h>

int main(void)
{
	int i = 0, cntMin = 0, cntMax = 0, minNum = 50000, maxNum = -50000;
	int a[10] = {0}, min[10] = {0}, max[10] = {0};
	for(i = 0; i < 10; i++)			//边输入数据，边搜索 
	{
		scanf("%d", &a[i]);
		if(a[i] < minNum)
		{
			minNum = a[i];
			cntMin = 0;
			min[cntMin++] = i;
		}
		else if(a[i] == minNum)
		{
			min[cntMin++] = i;
		}
		if(a[i] > maxNum)
		{
			maxNum = a[i];
			cntMax = 0;
			max[cntMax++] = i;
		}
		else if(a[i] == maxNum)
		{
			max[cntMax++] = i;
		}
	}
	printf("max:");
	for(i = 0; i < cntMax; i++)					//输出最大值，有几个最大值就循环几轮 
	{
		printf("a[%d]=%d ", max[i], maxNum);
	}
	printf("\nmin:");
	for(i = 0; i < cntMin; i++)					//输出最小值，有几个最小值就循环几轮 
	{
		printf("a[%d]=%d ", min[i], minNum);
	}
	return 0;
}
