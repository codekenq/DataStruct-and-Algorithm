#include "linklist.h"

void dealNode(Item node)
{
	printf("%f ", node);
}

int main()
{
	Item val;
	Control list1;
	initLinklist(&list1);
	while(scanf("%f", &val) == 1)
	{
		addToLinklist(&list1, val);
	}
	printf("traversal\n");
	traversalLinklist(&list1, &dealNode);
	printf("OK\n");
	
	printf("reTraversal\n");
	reTraversalLinklist(&list1, &dealNode);
	printf("OK\n");

	printf("sorted\n");
	linklistSortByAscend(&list1);
	traversalLinklist(&list1, &dealNode);
	printf("OK\n");
	
	destroyLinklist(&list1);
}
