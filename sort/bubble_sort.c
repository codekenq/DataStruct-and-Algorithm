#include "tool.h"

#define N 5

void bubble_sort(int *a, int l, int r)
{
	int i, j, temp;
	for(i = l; i < r+1; i++)
		for(j = l; j < r+1-i; j++)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
}

void bubbleSymboled(int *a, int l, int r)
{
	int i = r, j, pos, temp;
	while(i > l)
	{
		pos = l;
		for(j = l; j < i; j++)
			if(a[j] > a[j+1])
			{
				pos = j;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		i = pos;
	}
}

int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	bubble_sort(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");

	int b[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	bubbleSymboled(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
}
