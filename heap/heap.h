#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>

#define PARENT(i) ((i) / 2)
#define LEFT(i)	(2 * (i))
#define RIGHT(i) (2 * (i) + 1)

void maxHeapify(int *a, int l, int r, int i) //在这里默认为数组的长度就是heap的大小
{
	int differ = l - 1;
	int n = r - differ;
	int index = i - differ;

	int largest, temp;
	int lson = LEFT(index);
	int rson = RIGHT(index);

	if(a[i] < a[lson + differ] && lson <= n)
		largest = lson + differ;
	else
		largest = i;
	if(a[largest] < a[rson + differ] && rson <= n)
		largest = rson + differ;
	if(i != largest)
	{
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		maxHeapify(a, l, r, largest);
	}
}

void maxHeapifyIter(int *a, int l, int r, int i) 
{
	int differ = l - 1;
	int n = r - differ;
	int index = i - differ;
	
	int lson, rson, largest, temp;
	while(1)
	{
		lson = LEFT(index);
		rson = RIGHT(index);
		if(a[i] < a[lson + differ] && lson <= n)
			largest = lson + differ;
		else
			largest = i;
		if(a[largest] < a[rson + differ] && rson <= n)
			largest = rson + differ;
		if(i != largest)
		{
			temp = a[i];
			a[i] = a[largest];
			a[largest] = temp;
			i = largest;
			index = i - differ;
		}
		else
			break;
	}
}

void minHeapify(int *a, int l, int r, int i)
{
	int differ = l - 1;
	int n = r - differ;
	int index = i - differ;
	int min, temp;
	int lson = LEFT(index);
	int rson = RIGHT(index);

	if(a[i] > a[lson + differ] && lson <= n)
		min = lson + differ;
	else
		min = i;
	if(a[min] > a[rson + differ] && rson <= n)
		min = rson + differ;
	if(i != min)
	{
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		minHeapify(a, l, r, min);
	}
}

void minHeapifyIter(int *a, int l, int r, int i)
{
	int differ = l - 1;
	int n = r - differ;
	int index = i - differ;

	int lson, rson, min, temp;
	while(1)
	{
		lson = LEFT(index);
		rson = RIGHT(index);
		if(a[i] > a[lson + differ] && lson <= n)
			min = lson + differ;
		else
			min = i;
		if(a[min] > a[rson + differ] && rson <= n)
			min = rson + differ;
		if(i != min)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			i = min;
			index = i -differ;
		}
		else
			break;
	}
}

void buildMaxHeap(int *a, int l, int r)
{
	int differ = l - 1;
	int n = r - differ;

	int i;
	for(i = n/2 + differ; i >= 1 + differ; i--)
		maxHeapify(a, l, r, i);
}

void buildMinHeap(int *a, int l, int r)
{
	int differ = l - 1;
	int n = r - differ;

	int i;
	for(i = n/2 + differ; i >= 1 + differ; i--)
		minHeapify(a, l, r, i);
}

void buildMaxHeapIter(int *a, int l, int r)
{
	int differ = l - 1;
	int n = r - differ;

	int i;
	for(i = n/2 + differ; i >= 1 + differ; i--)
		maxHeapifyIter(a, l, r, i);
}

void buildMinHeapIter(int *a, int l, int r)
{
	int differ = l - 1;
	int n = r - differ;

	int i;
	for(i = n/2 + differ; i >= 1 + differ; i--)
		minHeapifyIter(a, l, r, i);
}

void heapSortByAscend(int *a, int l, int r)
{
	buildMinHeap(a, l, r);
	
	int i, temp;
	for(i = r; i >= l; --i)
	{
		temp = a[l];
		a[l] = a[i];
		a[i] = temp;
		minHeapify(a, l, i-1, l);
		printf("%d-", a[i]);
	}
}

void heapSortByDescend(int *a, int l, int r)
{
	buildMaxHeap(a, l, r);
	
	int i, temp;
	for(i = r; i >= l; --i)
	{
		temp = a[l];
		a[l] = a[i];
		a[i] = temp;
		maxHeapify(a, l, i-1, l);
		printf("%d-", a[i]);
	}
}
#endif /*_HEAP_H_*/
