#include "tool.h"
#include "linklist.h"

void dealNode(Item item)
{
	printf("%f ", item);
}

int roundDown(float val)
{
	if(val >=0.0 && val < 0.1)
		return 0;
	else if(val >=0.1 && val < 0.2)
		return 1;
	else if(val >=0.2 && val < 0.3)
		return 2;
	else if(val >=0.3 && val < 0.4)
		return 3;
	else if(val >=0.4 && val < 0.5)
		return 4;
	else if(val >=0.5 && val < 0.6)
		return 5;
	else if(val >=0.6 && val < 0.7)
		return 6;
	else if(val >=0.7 && val < 0.8)
		return 7;
	else if(val >=0.8 && val < 0.9)
		return 8;
	else if(val >=0.9 && val < 1.0)
		return 9;
}

void bucketSort(float a[], int size)
{
	int i;
	const int bucketSize = 10;
	Control bucket[bucketSize];
	for(i = 0; i < bucketSize; i++)
		initLinklist(bucket + i);
	for(i = 0; i < size; i++)
		addToLinklist(&bucket[roundDown(a[i])], a[i]);
	for(i = 0; i < bucketSize; i++)
		linklistSortByAscend(bucket + i);
	for(i = 0; i < bucketSize; i++)
		traversalLinklist(bucket + i, dealNode);
//		printf("%d ", (bucket + i)->count);
}

int main()
{
	float a[] = {0.79, 0.13, 0.16, 0.64, 0.39, 0.20, 0.89, 0.53, 0.71, 0.42};
	bucketSort(a, sizeof(a) / sizeof(float));
	printf("\n");
}
