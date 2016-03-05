#include "tool.h"
#include <memory.h>
#include <stdlib.h>

int rangeNumber(int *a, int l, int r, int max, int lVal, int rVal)
{
	int i;
	int n = l-r+1;
	int *c = malloc(max * sizeof(int));
	memset(c, 0, max * sizeof(int));
	
	for(i = l; i <= r; i++)
		c[a[i]]++;
	for(i = 1; i < max; i++)
		c[i] += c[i-1];
	if(lVal == 0)				//在这里尤为注意，当lVal为0时的特殊处理。
		return c[rVal];
	return c[rVal] - c[lVal-1];
}

int main(char argc, char *argv[])
{
	int lVal, rVal;
	if(argc != 2)
		printf("not current argument"), exit(-1);
	const int N = atoi(argv[1]);

	int a[N];
	initArray(a, 0, N-1, 100);
	printArray(a, 0, N-1);
	printf("\n");

	while(scanf("%d %d", &lVal, &rVal) == 2)
	{
		printf("The Num is %d\n", rangeNumber(a, 0, N-1, 100, lVal, rVal));
	}
}
