#include "tool.h"

#define N	5

void insert_sort(int *a, int l, int r)
{
	int i, j, temp;
	for(i = l; i < r+1; i++)
		for(j = i; j > l; j--)
			if(a[j] > a[j-1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
			else
				break;
}

int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	insert_sort(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
}
