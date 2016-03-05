#include <stdio.h>
#include "tool.h"

#define N 5

int partition(int *a, int l, int r)
{
	int i = l - 1;
	int j = l;
	int x = a[r];
	int temp;

	for(;j < r;j++)
	{
		if(a[j] <= x)
		{
			++i;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	temp = a[r];
	a[r] = a[i+1];
	a[i+1] = temp;
	return i+1;
}

int partitionMedian(int *a, int l, int r)//这个是CLRS 2nd 7.1-2的答案
{
	int i = l - 1;
	int j = l;
	int x = a[r];
	int temp;

	for(;j < r;j++)
	{
		if(a[j] <= x)
		{
			++i;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}

	if(i+1 == r)
		return;
	temp = a[r];
	a[r] = a[i+1];
	a[i+1] = temp;
	return i+1;
}

int partitionByDescend(int *a, int l, int r)//这个是CLRS 2nd 7.1-3的答案
{
	int i = l - 1;
	int j = l;
	int x = a[r];
	int temp;

	for(;j < r;j++)
	{
		if(a[j] > x)
		{
			++i;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}

	temp = a[r];
	a[r] = a[i+1];
	a[i+1] = temp;
	return i+1;
}

void quickSort(int *a, int l, int r)
{
	if(l > r)
		return;
	int p = partitionByDescend(a, l, r);
	quickSort(a, l, p-1);
	quickSort(a, p+1, r);
}

int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	quickSort(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
}
