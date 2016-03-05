#include "linklist.h"

/*
void dealNode(Item node)
{
	printf("%d ", node);
}
*/

void initLinklist(Control *list)
{
	list->head = list->tail = NULL;
	list->count = 0;
}

void addToLinklist(Control *list, Item val)
{
	Node *p = malloc(sizeof *p);
	p->node = val;
	p->next = NULL;
	list->count++;
	if(list->head == NULL)
	{
		list->head = list->tail = p;
		return;
	}
	list->tail->next = p;
	list->tail = p;
}

void destroyLinklist(Control *list)
{
	Node *cur = list->head;
	Node *p;
	while(cur)
	{
		p = cur->next;
		free(cur);
		cur = p;
	}
}

void traversalLinklist(Control *list, Function deal)
{
//	printf("%d ", list->head->node);
	if(list->head == NULL)
		return;
	deal(list->head->node);
	if(list->head->next == NULL)
		return;
	Control cur;
	cur.head = list->head->next;
	cur.tail = list->tail;
	traversalLinklist(&cur, deal);
}

void reTraversalLinklist(Control *list, Function deal)
{
	if(list->head == NULL)
		return;
	if(list->head->next == NULL)
	{
//		printf("%d-", list->head->node);
		deal(list->head->node);
		return;
	}
	Control cur;
	cur.head = list->head->next;
	cur.tail = list->tail;
	reTraversalLinklist(&cur, deal);
//	printf("%d-", list->head->node);
	deal(list->head->node);
}


/*
void linklistSortByAscend(Control *list)		//一段失败的代码，本想在原链表中使用选择排序进行链表
{													
	Node *i, *j, *iPrecursor, *iSuccessor, *min, *minPrecursor, *minSuccessor, *jPrecursor, 
		 *jSuccessor;
	for(i = list->head, iPrecursor = list->head, iSuccessor = list->head->next; 
			i != NULL;							//奈何情况比较复杂，自己前期的分析准备也是不足。
			iPrecursor = i, i = i->next			//代码底子也不是特别好，所以出了问题。
			)
	{											//其实问题可以简化的，那就是不在原链表排序，而是
		iSuccessor = i->next;					//产生一个新的链表。
		if(iSuccessor == NULL)
			break;
		for(j = min = i, jPrecursor = minPrecursor = iPrecursor, 
					jSuccessor = minSuccessor = iSuccessor;
				j != NULL; 
				jPrecursor = j, j = j->next
				)
		{
			jSuccessor = j->next;
			if(j->node < min->node)
			{
				min = j;
				minPrecursor = jPrecursor;
				minSuccessor = jSuccessor;
			}
		}
		if(min != i)
		{
			if(i == list->head)
			{
				if(iSuccessor == minPrecursor)
				{
					list->head = min;
					i->next = minSuccessor;
					min->next = i;
				}
				else
				{
					list->head = min;
					min->next = iSuccessor;
					minPrecursor->next = i;
					i->next = minSuccessor;
				}
			}
			else
			{
				if(iSuccessor == minPrecursor)
				{
					iPrecursor->next = min;
					i->next = minSuccessor;
					min->next = i;
				}
				else
				{
					iPrecursor->next = min;
					min->next = iSuccessor;
					minPrecursor->next = i;
					i->next = minSuccessor;
				}
			}
		}
	}
}
*/

void deleteNode(Control *list, Node *cur)
{
	Node *i;
	if(cur == list->head)
	{
		list->head = cur->next;
		free(cur);
		list->count--;
		return ;
	}
	for(i = list->head; i != NULL; i = i->next)
		if(i->next == cur)
			break;
	if(i != NULL)
	{
		i->next = cur->next;
		free(cur);
		list->count--;
	}
}

void copyLinklist(Control *s, Control *o)
{
	Node *i, *j;
	
	for(i = s->head; i != NULL; i = i->next)
		addToLinklist(o, i->node);
}

void linklistSortByAscend(Control *list)
{
	Node *i, *j, *min;
	Control sortList;

	initLinklist(&sortList);
	while(list->count != 0)
	{
		for(j = min = list->head; j != NULL; j = j->next)
			if(min->node > j->node)
				min = j;
		addToLinklist(&sortList, min->node);
		deleteNode(list, min);
	}
	copyLinklist(&sortList, list);
	destroyLinklist(&sortList);
}
