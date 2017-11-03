#include<stdio.h>
#include<stdlib.h>

typedef struct SL_Node
{
	char data;
	struct SL_Node* next;
}SL_Node;

typedef struct SL_List
{
	SL_Node* HeadNode;
	SL_Node* TailNode;
}SL_List;

void insert(SL_List* list, SL_Node* node)
{
	node->next = list->HeadNode;
	list->HeadNode = node;
}

void InitA(SL_List* list)
{
	SL_Node* A = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* B = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* C = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* D = (SL_Node*)malloc(sizeof(SL_Node));
	A->data = 'A';
	B->data = 'B';
	C->data = 'C';
	D->data = 'D';
	insert(list, D);
	insert(list, C);
	insert(list, B);
	insert(list, A);
	list->TailNode = D;
}

void InitB(SL_List* list)
{
	SL_Node* E = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* F = (SL_Node*)malloc(sizeof(SL_Node));
	SL_Node* G = (SL_Node*)malloc(sizeof(SL_Node));
	E->data = 'E';
	F->data = 'F';
	G->data = 'G';
	insert(list, G);
	insert(list, F);
	insert(list, E);
	list->TailNode = G;
}

int main(void)
{
	SL_List* a = (SL_List*)malloc(sizeof(SL_List));
	SL_List* b = (SL_List*)malloc(sizeof(SL_List));
	InitA(a);
	InitB(b);
	SL_Node* temp = a->HeadNode;
	a->TailNode->next = b->HeadNode;
	b->TailNode->next = NULL;
	while(temp != NULL)
	{
		printf("%c", temp->data);
		temp = temp->next;
	}
	return 0;
}
