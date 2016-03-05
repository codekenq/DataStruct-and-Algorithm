#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

void heapify(vector<int> &vec, int i)
{
	int left, right, max, tmp, size;

	left = 2 * i;
	right = 2 * i + 1;
	size = vec.size() - 1;
	max = i;

	if(left > size && right > size)
		return ;
	if(left <= size && vec[max] < vec[left])
		max = left;
	if(right <= size && vec[max] < vec[right])
		max = right;

	if(max == i)
		return ;
	tmp = vec[i];
	vec[i] = vec[max];
	vec[max] = tmp;
	heapify(vec, max);
}

void make_heap(vector<int> &vec)
{
	for(int i = (vec.size() - 1) / 2; i > 0; i--)
		heapify(vec, i);
}

void init_vec(vector<int> &vec)
{
	vec.push_back(0);
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
		vec.push_back(rand() % 100);
}

int main()
{
	vector<int> vec;
	init_vec(vec);
	
	for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	make_heap(vec);
	for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
