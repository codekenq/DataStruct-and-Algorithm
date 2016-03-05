#ifndef _TOOL_H_
#define _TOOL_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void initArray(int *a, int l, int r, int range)
{
	int i;
	srand(time(NULL));
	for(i = l; i < l+r+1; i++)
		a[i] = rand() % range;
}

void printArray(int *a, int l, int r)
{
	int i;
	for(i = l; i < l+r+1; i++)
		printf("%d ",a[i]);
}

#endif /*_TOOL_H_*/

