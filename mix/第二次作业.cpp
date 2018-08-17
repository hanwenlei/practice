int solve(int a[], int n)
{
	int low = 1, high = n, mid = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(a[mid] == mid)
		{
			return mid;
		}
		else if(a[mid] < mid)
		{
			low = mid + 1; 
		}
		else
		{
			high = mid - 1;
		}
	}
	return 0;
}

int SelectSort(SqList& L)
{
	int i = 1, j = 0;
	ElementType *min = L.HeadNode, *travel = L.HeadNode->next;
	for(i = 1; i < L.length; i++)
	{
		for(j = i + 1; j < L.length; j++)
		{
			if(travel->key < min->key)
			{
				min = travel;
			}
			travel = travel->next;
		}
		travel = L.HeadNode;
		for(j = 1; j < i; j++)
		{
			travel = travel->next;
		}
		swap(travel, min);
	}
	return 0;
}

T(n)=4T(n/2)+n;      O(n*n)
T(n)=4T(n/2)+n*n;    O(n*n*logn)
T(n)=4T(n/2)+n*n*n;  O(n*n*n)
