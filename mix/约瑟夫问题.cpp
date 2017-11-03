#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node;

typedef struct
{
	node* HeadNode;
}List;

int main(void)
{
	int i = 0, m = 0, n = 0, r = 0, s = 0;
	List list;
	list.HeadNode = NULL;
	node *p, *q;
	printf("n m = ");
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++)
	{
		p = (node*)malloc(sizeof(node));
		p->data = i;
		if(list.HeadNode == NULL)
		{
			list.HeadNode = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	q->next = list.HeadNode;
	q = list.HeadNode;
	do
	{
		if(q->data != 0)
		{
			r++;
			if(r == m)
			{
				printf("%d ", q->data);
				q->data = 0;
				r = 0;
				s++;
			}
		}
		q = q->next;
	}while(s != n);
	p = q = list.HeadNode;
	for(i = 0; i < n; i++)
	{
		p = q;
		q = q->next;
		free(p);
	}
	return 0;
}
