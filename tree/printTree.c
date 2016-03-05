#include "printTree.h"
#include <stdio.h>

struct node 
{
	link l;
	link r;
	Item item;
};

void printNode(Item item, int h)
{
	int i;
	for(i = 0; i < h; i++)
		printf(" ");
	printf("%d", item);
	printf("\n");
}

void showTree(link x, int h)
{
	if(x == NULL)
		return;
	printNode(x->item, h);
	showTree(x->l, h + 1);
	showTree(x->r, h + 1);
}
