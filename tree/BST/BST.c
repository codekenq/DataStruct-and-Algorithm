#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

/*
 * 虽然目前这个程序在数据合理的操作下，不会出现什么问题，但是用户是调皮的，他们可不会按照规矩来
 * 所以说，这个程序还是缺少一定的鲁棒性，要是想投入到实用的地步，还得在外部加一些封装
 * */

static void swap(link lhs, link rhs)
{
	Item temp;
	temp = lhs->data;
	lhs->data = rhs->data;
	rhs->data = temp;
}

static link NEW(Item key, link parent, link left, link right)
{
	link p = malloc(sizeof *p);
	p->data = key;
	p->parent = parent;
	p->left = left;
	p->right = right;
}

void traversal(link tree)
{
	if(tree == NULL)
		return ;
	traversal(tree->left);
	printf("%d ", tree->data);
	traversal(tree->right);
}

/*当合法操作的时候，这个是正确的*/

link search(link tree, Item key)
{
	if(tree == NULL)
		return NULL;
	if(tree->data == key)
		return tree;
	else if(key > tree->data)
		return search(tree->right, key);
	else if(key < tree->data)
		return search(tree->left, key);
}

/* 
 * 当tree只有一个节点的时候，直接返回tree。
 * 当有很多个节点的时候，那么也是正确的
 * */

link min(link tree)
{
	if(tree==NULL)
		return NULL;
	if(tree->left == NULL)
		return tree;
	return min(tree->left);
}

/* 
 * 当tree只有一个节点的时候，直接返回tree。
 * 当有很多个节点的时候，那么也是正确的
 * */

link max(link tree)
{
	if(tree == NULL)
		return NULL;
	if(tree->right == NULL)
		return tree;
	return max(tree->right);
}

/* 
 * 当tree为空时，即没有一个节点，然后查找node，node就是一个假地址，这个肯定会出错的
 * 在这里我们只讨论正确的查找
 * 当tree只有一个节点，然后查找的就是这个节点，则返回为空，说明没有这个节点的前驱
 * */

link predecessor(link tree, link node)
{
	if(node->left != NULL)
		return max(node->left);
	link x;
	x = node->parent;
	while(x != NULL && node == x->left)
	{
		node = x;
		x = node->parent;
	}
	return x;
}

/* 
 * 当tree为空时，即没有一个节点，然后查找node，node就是一个假地址，这个肯定会出错的
 * 在这里我们只讨论正确的查找
 * 当tree只有一个节点，然后查找的就是这个节点，则返回为空，说明没有这个节点的前驱
 * */

link successor(link tree, link node)
{
	if(node->right != NULL)
		return min(node->right);
	link x;
	x = node->parent;
	while( x != NULL && node == x->right)
	{
		node = x;
		x = node->parent;
	}
	return x;
}

/* 
 * insert在树为空时，和在树有节点的时候，都能正常的工作
 * */

void insert(link *tree, Item key)
{
	link node = NEW(key, NULL, NULL, NULL);
	if( *tree == NULL)
	{	
		*tree = node;
		return ;
	}
	link x = *tree;
	link p = NULL;
	while(x != NULL)
	{
		if(key == x->data)
		{
			printf("The key was inserted\n");
			return ;
		}
		if(key > x->data)
		{
			p = x;
			x = x->right;
		}
		if(key < x->data)
		{
			p = x;
			x = x->left;
		}
	}
	node->parent = p;
	if(p == NULL)
		*tree = node;
	else if(key > p->data)
		p->right = node;
	else
		p->left = node;
}

void delete(link *tree, link z)
{
	link x, y;

	/*
	 * 算法确定要删除的节点y，这个节点要么是z，或者是z的后继。
	 * */
	if(z->left == NULL || z->right == NULL)
		y = z;
	else 
		y = successor(*tree, z);

	/*
	 * x被置为y的非空子女，或者当y没有子女时，它被置为NULL
	 * */
	if(y->left != NULL)
		x = y->left;
	else
		x = y->right;

	/*
	 * 将子节点到父节点的指向关系连通
	 * */
	if(x != NULL)
		x->parent = y->parent;

	/*
	 * 将父节点到子节点的关系连通
	 * */
	if(y->parent == NULL)
		*tree = x;
	else if(y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	/*
	 * 在删除y之前，看看是不是删除了y，如果是它的后继，记得要把后继和y调换。
	 * */
	if(y != z)
		swap(y, z);
	free(y);
}
