#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Node
{
	int value;
	Node *parent;
	char color;
	int deepth;
	vector<Node *> adj;

	Node(const int &val):value(val), parent(NULL), color(WHITE), deepth(), adj() {}
};

int index(vector<Node> &vec, int value)
{
	int size = vec.size();
	for(int i = 0; i < size; i++)
		if(vec[i].value == value)
			return i;
	return -1;
}

void initGraphicV(vector<Node> &vec)
{
	int value;
	cout << "请输入图中节点的值" << endl;
	cin >> value;
	while(value != -1)
	{
		vec.push_back(Node(value));
		cin >> value;
	}
}

void initGraphicE(vector<Node> &vec)
{
	cout << "这是目前已有的节点" << endl;
	for(vector<Node>::iterator iter = vec.begin();
			iter != vec.end(); iter++)
		cout <<iter->value << " ";
	cout << endl;

	int u, v;
	cout << "请输入节点关系信息, 输入q结束" << endl;
	cin >> u >> v;
	while(u != -1 && v != -1)
	{
		int i = index(vec, u);
		int j = index(vec, v);
		vec[i].adj.push_back(&vec[j]);
		cin >> u >> v;
	}
}

void adjInfo(vector<Node> &vec)
{
	cout << "这个是节点信息" << endl;
	for(vector<Node>::iterator iter = vec.begin();
			iter != vec.end(); iter++)
		cout << iter->value << " ";

	cout << "这个是连接信息" << endl;
	for(vector<Node>::iterator iter = vec.begin();
			iter != vec.end(); iter++)
	{
		cout << iter->value << ":" << endl;
		for(vector<Node *>::iterator i = iter->adj.begin();
			i != iter->adj.end(); i++)
			cout << (*i)->value << " ";
		cout << endl;
	}
}

void bfs(vector<Node> &vec, Node &s)
{
	queue<Node*> q;

	s.color = GRAY;
	s.deepth = 0;

	q.push(&s);
	while(!q.empty())
	{
		Node &u = *(q.front());
		q.pop();
		for(vector<Node *>::iterator iter = u.adj.begin();
				iter != u.adj.end(); iter++)
		{
			if((*iter)->color == WHITE)
			{
				(*iter)->color = GRAY;
				(*iter)->deepth = u.deepth + 1;
				(*iter)->parent = &u;
				q.push(*iter);
			}
		}
		u.color = BLACK;
	}
}

int main()
{
	vector<Node> vec;
	initGraphicV(vec);
	initGraphicE(vec);
	adjInfo(vec);
	bfs(vec, vec[0]);
}
