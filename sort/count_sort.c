#include <stdlib.h>
#include <memory.h>
#include "tool.h"

void countSort(int *a, int l, int r, int max)
{
	int i;
	int n = r-l+1;
	int *b = malloc(n * sizeof(int));
	int *c = malloc(max * sizeof(int));
	memset(c, 0, max*sizeof(int));

	for(i = l; i <= r; i++)
		c[a[i]]++;
	for(i = 1; i < max; i++)
		c[i] +=c[i-1];
	for(i = l; i <= r; i++)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
	for(i = 0; i < n; i++)
		a[l+i] = b[i];
	free(b);
	free(c);
}

int main(char argc, char *argv[])
{
	if(argc != 2)
		printf("not current argument"), exit(-1);
	const int N = atoi(argv[1]);
	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
	countSort(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");
}
