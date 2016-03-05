#include "heap.h"
#include "tool.h"

#define N 11 

int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	buildMaxHeapIter(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
	buildMaxHeap(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");
	printf("这个是最小堆");
	printf("\n");
	buildMinHeapIter(a, 0, N-1);
	printArray(a, 0, N-1);
	printf("\n");

	printf("这个是最小堆排序");
	heapSortByAscend(a, 0, N-1);
	printf("\n");
	
	printf("这个是最大堆排序");
	heapSortByDescend(a, 0, N-1);
	printf("\n");
}
