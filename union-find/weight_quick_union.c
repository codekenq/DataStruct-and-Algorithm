#include <stdio.h>

#define N 10000

int main()
{
	int i, j, p, q, id[N], sz[N] = {0};
	for(i = 0; i < N; i++)
	{
		id[i] = i;
	}

	for(; scanf("%d %d", &p, &q) ;)
	{
		for(i = p; i != id[i]; i = id[i]);
		for(j = q; j != id[j]; j = id[j]);

		if(i == j) continue;
		if(sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
		printf("%d %d is not linked\n", p, q);
	}
	for(i = 0; i < 10; i++)
	{
		for(j = i; id[j] != j; j = id[j]);
		printf("%d ", j);
	}
}
