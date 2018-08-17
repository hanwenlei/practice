#include<stdio.h>

int matrix(int p[], int n, int m[][10], int s[][10])
{
	int i = 0, r = 0, k = 0;
	for(i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for(r = 2; r <= n; r++)
	{
		for(i = 1; i <= n-r+1; i++)
		{
			int j = i+r-1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return 0;
}

void print(int s[][10], int i, int j)
{
	if(i == j)
	{
		printf("A%d", i);
	}
	else
	{
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j]+1, j);
		printf(")");
	}
}

int main(void)
{
	int p[10] = {0}, m[10][10] = {0}, s[10][10] = {0};
	int i = 0, n = 0;
	printf("请输入矩阵个数(最大为10) : ");
	scanf("%d", &n);
	printf("请输入矩阵维数 : ");
	for(i = 0; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	matrix(p, n, m, s);
	printf("最少乘法次数为 : %d\n", m[1][n]);
	print(s, 1, 6); 
	return 0;
}
