#include <stdio.h>

#define N 10000

int main()
{
	int i, p, q, t, id[N];
	for(i = 0; i < N; i++)
		id[i] = i;
	for(; scanf("%d %d", &p, &q); )
	{
		if(id[p] == id[q])	continue;
		for(t = id[p], i = 0; i < N; i++)
			if(id[i] == id[q])	id[i] = t;
		printf("%d %d not linked\n", p, q);
	}
}
