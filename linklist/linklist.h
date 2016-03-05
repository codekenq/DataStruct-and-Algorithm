#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef float Item;
typedef void(*Function)(Item);

typedef struct Node
{
	Item node;
	struct Node *next;
}Node;

typedef struct
{
	Node *head;
	Node *tail;
	int count;
}Control;

void initLinklist(Control *);
void addToLinklist(Control *, Item);
void destroyLinklist(Control *);
void traversalLinklist(Control *, Function);
void reTraversalLinklist(Control *, Function);
void deleteNode(Control *, Node *);
void copyLinklist(Control *, Control *);
void linklistSortByAscend(Control *);

#endif /*_LINK_LIST_H_*/
