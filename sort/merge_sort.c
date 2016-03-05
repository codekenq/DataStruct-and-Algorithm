#include "tool.h"
#include <stdlib.h>

#define N 11

void merge(int *a, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = malloc(n1 * sizeof(int));
	int *R = malloc(n2 * sizeof(int));
	int i, j, k;
	for(i = 0; i < n1; i++)
		L[i] = a[p+i];
	for(i = 0; i < n2; i++)
		R[i] = a[q+1+i];
	for(i = p, j = 0, k = 0; i <= r; i++)
	{
		if(j == n1)
		{
			a[i] = R[k++];
			continue;
		}
		if(k == n2)
		{
			a[i] = L[j++];
			continue;
		}

		if(L[j] <= R[k])
			a[i] = L[j++];
		else
			a[i] = R[k++];
	}

	free(L);
	free(R);
}

void mergeSort(int *a, int l, int r)
{
	if(l >= r)
		return ;
	mergeSort(a, l, (l+r)/2);
	mergeSort(a, (l+r)/2+1, r);
	merge(a, l, (l+r)/2, r);
}

int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	mergeSort(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
}
