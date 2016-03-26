#ifndef __HUFFMAN_H_
#define __HUFFMAN_H_

typedef struct Node  
{  
	    int weight;                //权值  
		int parent;                //父节点的序号，为-1的是根节点  
		int lchild,rchild;         //左右孩子节点的序号，为-1的是叶子节点  
}HTNode,*HuffmanTree;          //用来存储赫夫曼树中的所有节点  
typedef char **HuffmanCode;    //用来存储每个叶子节点的赫夫曼编码  

HuffmanTree create_HuffmanTree(int *wet,int n);
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n);

#endif /* __HUFFMAN_H_ */