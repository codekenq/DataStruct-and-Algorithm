/*
 *这个程序其实就是一个可以求最大最小值的二叉树，只不过，在这里，作者为了展示递归在二叉树中的应用，用了
 *这个程序做一个示例罢了。
 * */
typedef int Item;
typedef struct node *link;

struct node
{
	link l;
	link r;
	Item item;
};

#include <stdio.h>
#include <stdlib.h>

#include "printTree.h"
#include "treeCharacter.h"

link New(Item item, link l, link r)

{
	link p = malloc(sizeof *p);
	p->item = item;
	p->l = l;
	p->r = r;
	return p;
}

/*
link max(Item a[], int l, int r)
{
	link p = New(a[(l+r)/2], NULL, NULL);
	if(l == r)
		return p;
	p->l = max(a, l, (l+r)/2);
	p->r = max(a, (l+r)/2 + 1, r);
	if(p->l->item > p->r->item)
		p->item = p->l->item;
	else
		p->item = p->r->item;
	return p;
}
*/

link max(Item a[], int l, int r)
{
	int m = (l + r) / 2;
	Item u, v;
	link x = New(a[m], NULL, NULL);
	if(l == r) return x;
	x->l = max(a,  l, m);
	x->r = max(a, m+1, r);
	u = x->l->item; v = x->r->item;
	if(u > v)
		x->item = u;
	else
		x->item = v;
	return x;
}
int main()
{
	Item a[] = {4, 1, 2, 3, 6, 7};
	printf("hehe%ld\n", sizeof(a));
	link tree = max(a, 0, sizeof(a) / sizeof(int) - 1);

	showTree(tree, 0);
	printf("tree`s All node counts are %d\n", treeNodeAllCount(tree));
	printf("tree`s Inside  node counts are %d\n", treeNodeInsideCount(tree));
	printf("tree`s Outside node counts are %d\n", treeNodeOutsideCount(tree));

	printf("tree`s All path counts are %d\n", treeAllPath(tree, 0));
	printf("tree`s Inside path counts are %d\n", treeInsidePath(tree, 0));
	printf("tree`s Outside path counts are %d\n", treeOutsidePath(tree, 0));
}
