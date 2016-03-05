#include <memory.h>
#include <stdlib.h>
#include "tool.h"

void print(char a[][3], int num)
{
	int i, j;
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < 3; j++)
			printf("%c ", a[i][j]);
		printf("\n");
	}
}

void copy(char s[][3], char o[][3], int num)
{
	int i, j;
	for(i = 0; i < num; i++)
		for(j = 0; j < 3; j++)
			o[i][j] = s[i][j];
}

void copyItem(char *s, char *o)
{
	int i;
	for(i = 0; i < 3; i++)
		o[i] = s[i];
}

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

void countSortStr(char a[][3], int num, int col, int max)
{
	int i;
	char (*b)[3] = malloc(num * 3); //在这里需呀注意二维数组的定义。尤其是数组指针的定义。
//	copy(a, b, num);
	int *c = malloc(max * sizeof(int));
	memset(c, 0, max * sizeof(int));

	for(i = 0; i < num; i++)
		c[a[i][col]]++;
	for(i = 1; i < max; i++)
		c[i] += c[i-1];
	for(i = num-1; i >= 0; i--)
	{
		copyItem(a[i], b[c[a[i][col]]-1]);
		c[a[i][col]]--;
	}
	copy(b, a, num);
	free(b);
	free(c);
}

void radixSort(char a[][3], int num, int max)
{
	int i;
	for(i = 2; i >= 0; i--)
	{
		countSortStr(a, num, i, max);
	}
}

int main()
{
	char a[][3] = {
					{'C', 'O', 'W'},
					{'D', 'O', 'G'},
					{'S', 'E', 'A'},
					{'R', 'U', 'G'},
					{'R', 'O', 'W'},
					{'M', 'O', 'B'},
					{'B', 'O', 'X'},
					{'T', 'A', 'B'},
					{'B', 'A', 'R'},
					{'E', 'A', 'R'},
					{'T', 'A', 'R'},
					{'D', 'I', 'G'},
					{'B', 'I', 'G'},
					{'T', 'E', 'A'},
					{'N', 'O', 'W'},
					{'F', 'O', 'X'}
				};
	int num = sizeof(a) / 3;
	print(a, num);
	radixSort(a, num, 255);
	printf("这个是排序后的\n");
	print(a, num);
}
