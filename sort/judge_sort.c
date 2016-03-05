#include "tool.h"

#define N 5

void judge_sort(int *a, int l, int r)
{
	int i, j, m;
	for(i = l; i < r+1; i++)
	{
		for(j = i; j < r+1; j++)
			if(a[i] > a[j])
			{
				m = a[i];
				a[i] = a[j];
				a[j] = m;
			}
	}
}

void judge_sort_optimize(int *a, int l, int r)
{
	int i, j, min, temp;
	for(i = l; i < r+1; i++)
	{
		min = i;
		for(j = i; j < r+1; j++)
			if(a[j] < a[min]) min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
//	judge_sort(a, 0, N-1);
	judge_sort_optimize(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
}
