#include<stdio.h>

int main(void)
{
	FILE* fp = fopen("test.txt", "r");
	if(fp == NULL)
	{
		printf("文件打开失败!");
		return -1;
	}
	int lower = 0, upper = 0, other = 0;
	char ch = 0;
	while(!feof(fp))
	{
		ch = getc(fp);
		if(ch >= 'a' && ch <= 'z')
		{
			lower++;
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			upper++;
		}
		else if(ch != ' ')
		{
			other++;
		}
	}
	printf("小写字符:%d\n大写字符:%d\n其他字符:%d\n", lower, upper, other);
	printf("字符总数:%d", lower+upper+other);
	fclose(fp);
	return 0;
}
