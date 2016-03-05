#ifndef _TRIE_H_
#define _TRIE_H_

#define MAX 26

typedef struct trie
{
	struct trie *node[26];
	int count;
}TrieNode, *TrieTree;

TrieTree trieTreeCreate();
void trieTreeInsert(TrieTree tree, char *str);
int trieTreeCount(TrieTree tree, char *str);
void trieTreeDestroy(TrieTree tree);

#endif /* _TRIE_H_*/
