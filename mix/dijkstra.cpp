#include<stdio.h>
#include<stdlib.h>
#define INF 1000000

int arcs[7][7] = 
{
	{0, 15, 2, 12, INF, INF, INF},
	{INF, 0, INF, INF, 6, INF, INF},
	{INF, INF, 0, INF, 8, 4, INF},
	{INF, INF, INF, 0, INF, INF, 3},
	{INF, INF, INF, INF, 0, INF, 9},
	{INF, INF, INF, 5, INF, 0, 10},
	{INF, 4, INF, INF, INF, INF, 0}
};

typedef struct Graph
{
	int VexNumber;
	int distance[7];
	int path[7];
	int s[7];
}Graph;

int dijkstra(Graph* g, int v0)
{
	int n = g->VexNumber, v = 0, i = 0;
	for(v = 0; v < n; v++)
	{
		g->s[v] = 0;
		g->distance[v] = arcs[v0][v];
		if(g->distance[v] < INF)
		{
			g->path[v] = v0;
		}
		else
		{
			g->path[v] = -1;
		}
	}
	g->s[v0] = 1;
	g->distance[v0] = 0;
	for(i = 1; i < n; i++)
	{
		int min = INF, j = 0;
		for(j = 0; j < n; j++)
		{
			if(!g->s[j] && g->distance[j] < min)
			{
				v = j;
				min = g->distance[j];
			}
		}
		g->s[v] = 1;
		for(j = 0; j < n; j++)
		{
			if(!g->s[j] && (g->distance[v] + arcs[v][j] < g->distance[j]))
			{
				g->distance[j] = g->distance[v] + arcs[v][j];
				g->path[j] = v;
			}
		}
	}
	return 0;
}

void print(Graph* g, int i, int j)
{
	if(i == 0)
	{
		printf("%c", j + 'a');
	}
	else
	{
		print(g, g->path[i], j);
		printf("->%c", i + 'a');
	}
}

int main(void)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->VexNumber = 7;
	int i = 0, j = 0, flag = 1;
	char n = 0;
	printf("请输入起始点(例如a) : ");
	scanf("%c", &n);
	j = n - 'a';
	dijkstra(g, j);
	for(i = 0; i < g->VexNumber; i++)
	{
		if(g->distance[i] == INF)
		{
			printf("从此起点出发无法走完所有顶点!");
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		for(i = 0; i < g->VexNumber; i++)
		{
			if(i != j)
			{
				printf("%c->%c : %d ", j + 'a', i + 'a', g->distance[i]);
				print(g, i, j);
				printf("\n");
			}
		}
	}
	free(g);
	return 0;
}
