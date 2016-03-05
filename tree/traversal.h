#ifndef _TRAVERSAL_H_
#define _TRAVERSAL_H_

/*
 *这里，link为树的节点的指针的类型，此时，我们还没有定义link的类型
 * */

void preorderTraversal(link, void(*visit)(link));
void inorderTraversal(link, void(*visit)(link));
void postorderTraversal(link, void(*visit)(link));

void sequenceTraversal(link, void(*visit)(link));

#endif /*_TRAVERSAL_H_*/
