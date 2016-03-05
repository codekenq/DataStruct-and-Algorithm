#include <stdio.h>
#include "BST.h"

int main()
{
	BSTtree tree = NULL;
	int i;
	for(i = 10; i > 0; i--)
		insert(&tree, i);
	traversal(tree);
	printf("\n");
	link p = search(tree, 10);
	if(p)
	{
		printf("search 10 success\n");
		delete(&tree,p);
	}
	traversal(tree);
	printf("\n");
}
