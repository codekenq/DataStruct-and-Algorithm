#ifndef _BST_H_
#define _BST_H_

typedef int Item;

typedef struct node
{
	Item data;
	struct node *left;
	struct node *right;
	struct node *parent;
}Node;

typedef Node *link;
typedef Node *BSTtree;

void traversal(link);
link search(link, Item);
link max(link);
link min(link);
link predecessor(link, link);
link successor(link, link);
void insert(link *, Item);
void delete(link *, link);

#endif /*_BST_H_*/
