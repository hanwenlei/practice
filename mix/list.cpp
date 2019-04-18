ListNode* max(List& L)
{
	if(L.FirstNode == NULL)
	{
		return ERROR;
	}
	ListNode* MaxNode = L.FirstNode;
	ListNode* temp = MaxNode->next;
	while(temp)
	{
		if(MaxNode->data < temp->data)
		{
			MaxNode = temp;
		}
		temp = temp->next;
	}
	return MaxNode;
}

List* reverse(List& L)
{
	if(L.FirstNode == NULL)
	{
		return ERROR;
	}
	ListNode* p = L.FirstNode->next;
	ListNode* q = p->next;
	while(p)
	{
		p = q->next;
		q->next = L.FirstNode;
		L.FirstNode = q;
		q = p;
	}
	return L;
}

typedef struct
{
	int top[2], bot[2];
	SElemType* V;
	int m;
}DblStack;

void DblInit(DblStack& s)
{
	s.V = new SElemType[MAXSIZE];
	top[0] = -1;
	top[1] = m;
	bot[0] = 0;
	bot[1] = m-1;
	m = MAXSIZE;
}

void Dblpush(DblStack& s, SElemType x, int i)
{
	if(IsFull(s))
	{
		return;
	}
	if(i == 0)
	{
		s.V[++top[i]] = x;
	}
	else
	{
		s.V[--top[i]] = x;
	}
}

int Dblpop(DblStack& s, int i, SElemType& x)
{
	if(IsEmpty(s, i))
	{
		return ERROR;
	}
	if(i == 0)
	{
		x = s.V[top[i]--];
	}
	else
	{
		x = s.V[top[i]++];
	}
	return 0;
}

int IsEmpty(DblStack s, int i)
{
	if(i == 0)
	{
		if(top[i] == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(top[i] == m)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int IsFull(DblStack s)
{
	if(top[1] - top[0] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
