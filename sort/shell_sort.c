#include "tool.h"

#define N 5

void shellsort1(int a[], int n)  
{  
	int i, j, gap;  
  
	for (gap = n / 2; gap > 0; gap /= 2) //步长  
		for (i = 0; i < gap; i++)        //直接插入排序  
		{  
			for (j = i + gap; j < n; j += gap)   
				if (a[j] < a[j - gap])  
				{  
					int temp = a[j];  
					int k = j - gap;  
					while (k >= 0 && a[k] > temp)  
					{  
						a[k + gap] = a[k];  
						k -= gap;  
					}  
					a[k + gap] = temp;  
				}  
		}  
}  

void insert_sort(int *a, int l, int r, int step)
{
	int i, j, temp;
	for(i = l; i < r+1; i += step)
		for(j = i; j > l; j -= step)
		{
			if(a[j] < a[j - step])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
				break;
		}
}

void shell_sort(int *a, int l, int r, int step)
{
	insert_sort(a, l, r, step);
	if(step == 1)
		return;
	shell_sort(a, l, r, step/2);
}

int main()
{
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	shell_sort(a, 0, N-1, 8);
	printArray(a, 0, N-1);
	printf("\n");
}
