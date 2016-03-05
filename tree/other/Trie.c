#include <string.h>
#include <stdlib.h>
#include "Trie.h"

TrieTree trieTreeCreate()
{
	int i;
	TrieTree tree = malloc(sizeof(TrieNode));
	for(i = 0; i < MAX; i++)
		tree->node[i] = NULL;
	tree->count = 0;
}

void trieTreeInsert(TrieTree tree, char *str)
{
	int i, j;
	char c;
	int len = strlen(str);
	TrieNode *cur = tree;
	
	for(i = 0; i < len; i++)
	{
		c = str[i] - 'a';
		if(!cur->node[c])
		{
			TrieNode *temp = malloc(sizeof(TrieNode));
			for(j = 0; j < MAX; j++)
				temp->node[j] = NULL;
			temp->count = 1;

			cur->node[c] = temp;
			cur = cur->node[c];
		}
		else
		{
			cur = cur->node[c];
			cur->count++;
		}
	}
}

int trieTreeCount(TrieTree tree, char *str)
{
	int i, count;
	char c;
	int len = strlen(str);
	TrieNode *cur = tree;
	for(i = 0; i < len; i++)
	{
		c = str[i] - 'a';
		if(!cur->node[c])
			return 0;
		else
			cur = cur->node[c];
	}
	return cur->count;
}

void trieTreeDestroy(TrieTree tree)
{
	int i;
	for(i = 0; i < MAX; i++)
		if(tree->node[i])
			trieTreeDestroy(tree->node[i]);
	free(tree);
}
