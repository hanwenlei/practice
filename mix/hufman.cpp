#include<stdio.h>
#include<stdlib.h>
#define N 50

typedef struct node
{
	int data;
	int parent;
	int lchild;
	int rchild;
}node;

void select(node a[], int n, int& s1, int& s2)
{
	int i = 0, j = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i].parent == -1)
		{
			s1 = i;
			break;
		}
	}
	for(j = i+1; j < n; j++)
	{
		if(a[j].parent == -1 && a[j].data < a[s1].data)
		{
			s1 = j;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(a[i].parent == -1 && i != s1)
		{
			s2 = i;
			break;
		}
	}
	for(j = i+1; j < n; j++)
	{
		if(a[j].parent == -1 && a[j].data < a[s2].data && j != s1)
		{
			s2 = j;
		}
	}
}

int hufman(node* a, int n)
{
	int i = 0, s1 = 0, s2 = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i].data);
		a[i].parent = -1;
		a[i].lchild = -1;
		a[i].rchild = -1;
	}
	for(; i < 2*n-1; i++)
	{
		a[i].parent = -1;
		a[i].lchild = -1;
		a[i].rchild = -1;
	}
	for(i = n; i < 2*n-1; i++)
	{
		select(a, i, s1, s2);
		a[i].data = a[s1].data + a[s2].data;
		a[i].lchild = s1;
		a[i].rchild = s2;
		a[s1].parent = i;
		a[s2].parent = i;
	}
	return 0;
}

void print(node a[], int n, int len)
{
	static int code[N];
	if(a[n].lchild == -1 && a[n].rchild == -1)
	{
		printf("%d : ", a[n].data);
		int i = 0;
		for(i = 0; i < len; i++)
		{
			printf("%d", code[i]);
		}
		printf("\n");
	}
	else
	{
		code[len] = 0;
		print(a, a[n].lchild, len+1);
		code[len] = 1;
		print(a, a[n].rchild, len+1);
	}
}

int main(void)
{
	int n = 0, i = 0, index = 0;
	printf("ÇëÊäÈën = ");
	scanf("%d", &n);
	node* a = (node*)malloc((2*n-1)*sizeof(node));
	hufman(a, n);
	for(i = 0; i < 2*n-1; i++)
	{
		if(a[i].parent == -1)
		{
			index = i;
			break;
		}
	}
	print(a, index, 0);
	free(a);
	return 0;
}
