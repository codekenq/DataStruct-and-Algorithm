#include "traversal.h"

void preorderTraversal(link h, void(*visit)(link))
{
	if(h == NULL)
		return;
	visit(h);
	preorderTraversal(h->l, visit);
	preorderTraversal(h->r, visit);
}

/*这里只是调用栈来实现非递归的操作。
void preorderTraversalNonRecursive(link h, void(*visit)(link))
{
	STACKinit(max);
	STACKpush(h);
	while(!STACKempty())
	{
		visit(h = STACKpop());
		if(h->r != NULL) STACKpush(h->r);
		if(h->l != NULL) STACKpush(h->l);
	}
}
*/

void inorderTraversal(link h, void(*visit)(link))
{
	if(h == NULL)
		return;
	preorderTraversal(h->l, visit);
	visit(h);
	preorderTraversal(h->r, visit);
}
void postorderTraversal(link h, void(*visit)(link))
{
	if(h == NULL)
		return;
	preorderTraversal(h->l, visit);
	preorderTraversal(h->r, visit);
	visit(h);
}

