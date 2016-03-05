#include <stdio.h>

#define N 10000

int main()
{
	int i, j, p, q, id[N];
	for(i = 0; i < N; i++)
		id[i] = i;
	for(; scanf("%d %d", &p, &q); )
	{
		for(i = p; id[i] != i; i = id[i]);
		for(j = q; id[j] != j; j = id[j]);
		if(i == j) continue;
		id[i] = j;
		printf("%d %d is not linked\n", p, q);
	}
	printf("\n");
	for(i = 0; i < 10; i++)
	{
		for(j = i; j != id[j]; j = id[j]);
		printf("%d ", j);
	}
	printf("\n");
}
