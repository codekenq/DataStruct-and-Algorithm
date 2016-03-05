#include <stdio.h>
#include "Trie.h"

int main()
{
	char data[20];
	TrieTree tree = trieTreeCreate();

	printf("请输入要处理的字符串\n");
	while(scanf("%s", data) == 1)
	{
		if(data[0] == '-')
			break;
		trieTreeInsert(tree, data);
	}
	printf("请输入要最大子串\n");
	while(scanf("%s", data) == 1)
	{
		if(data[0] == '-')
			break;
		printf("%s 的最大子串是%d\n", data, trieTreeCount(tree, data)); 
	}
	trieTreeDestroy(tree);
}
