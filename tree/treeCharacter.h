#ifndef _TREE_CHARACTER_H_
#define _TREE_CHARACTER_H_

#include <stdio.h>

typedef int Item;

typedef struct node *link;

int treeNodeAllCount(link);
int treeNodeInsideCount(link);
int treeNodeOutsideCount(link);
int treeHeight(link);
int treeInsidePath(link, int);
int treeOutsidePath(link, int);
int treeAllPath(link, int);

#endif /*_TREE_CHARACTER_H_*/
