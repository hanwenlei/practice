#include<stdio.h>

float f(float a[], int n, float* max, float* min)
{
	int i = 0;
	float s = 0, p = 0;
	*max = *min = a[0];
	for(i = 0; i < n; i++)
	{
		if(a[i] > *max)
		{
			*max = a[i];
		}
		else if(a[i] < *min)
		{
			*min = a[i];
		}
		s += a[i];
	}
	p = s / n;
	return p;
}

int main(void)
{
	float max = 0, min = 0;
	float t, a1[] = {98.5, 97, 91.5, 60, 55};
	float a2[] = {100, 56, 78, 98.5, 76, 87, 99, 67.5, 75, 97};
	t = f(a1, 5, &max, &min);
	printf("max = %5.1f min = %5.1f p = %5.2f\n", max, min, t);
	t = f(a2, 10, &max, &min);
	printf("max = %5.1f min = %5.1f p = %5.2f\n", max, min, t);
	return 0;
}
