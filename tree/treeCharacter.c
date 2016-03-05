#include "treeCharacter.h"

struct node 
{
	link l;
	link r;
	Item item;
};

int treeNodeAllCount(link h)
{
	if(h == NULL)
		return 0;
	return treeNodeAllCount(h->l) + treeNodeAllCount(h->r) + 1;
}

int treeNodeInsideCount(link h)
{
	return (treeNodeAllCount(h) - 1) / 2;
}

int treeNodeOutsideCount(link h)
{
	return treeNodeAllCount(h) - treeNodeInsideCount(h);
}

int treeHeight(link h)
{
	if(h == NULL)
		return -1;
	int lh, rh;
	lh = treeHeight(h->l);
	rh = treeHeight(h->r);
	if(lh > rh)
		return lh + 1;
	else
		return rh + 1;
}

int treeAllPath(link h, int cur)
{
	if(h == NULL)
		return 0;
	return treeAllPath(h->l, cur + 1) + treeAllPath(h->r, cur + 1) + cur;
}

int treeInsidePath(link h, int cur)
{
	if(h == NULL)
		return 0;
	if(h->l == NULL && h->r == NULL)
		return 0;
	if(h->l == NULL)
		return cur + treeInsidePath(h->r, cur + 1);
	if(h->r == NULL)
		return cur + treeInsidePath(h->l, cur + 1);
	return cur + treeInsidePath(h->l, cur + 1) + treeInsidePath(h->r, cur + 1);
}

int treeOutsidePath(link h, int cur)
{
	return treeAllPath(h, cur) - treeInsidePath(h, cur);
}
