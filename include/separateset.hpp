#pragma once


#include "priorityqueue.hpp"
#include "graph.hpp"
#include "dheap.hpp"
#include <stack>

template <class T>
class Sets
{
private:
	int *parent;
	int *height;
	int n;
public:
	Sets(int);
	~Sets();
	void CreateSet(int);
	int FindSet(int);
	void UnionSet(int, int);
	void Print();
	int* GetSet(int);
};

template <class T>
Sets<T>::Sets(int a)
{
	if (a < 0)
		throw
		exception("Size must be positive"); 
	parent = new int[a];
	for (int i = 0; i < a; i++)
		parent[i] = -1;
	height = new int[a];
	n = a;
}

template <class T>
Sets<T>::~Sets()
{
	delete[] parent;
	delete[] height;
}

template <class T>
void Sets<T>::CreateSet(int a)
{
	if ((a > n) || (a < 0))
		throw
		exception("Incorrect element"); 
	if (parent[a] != -1)
		return;
	parent[a] = a;
	height[a] = 0;
}

template <class T>
int Sets<T>::FindSet(int a)
{
	if ((a > n) || (a < 0))
		throw a; 
	if (parent[a] == -1)
		return -1;
	while (parent[a] != a)
		a = parent[a];
	return a;
}

template <class T>
void Sets<T>::UnionSet(int a, int b)
{
	if ((a > n) || (a < 0) || (b > n) || (b < 0))
		throw a; 
	if ((parent[a] == -1) || (parent[b] == -1))
		throw -1; 
	a = FindSet(a);
	b = FindSet(b);
	if (height[a] > height[b])
		parent[b] = a;
	else if (height[a] < height[b])
		parent[a] = b;
	else
	{
		parent[b] = a;
		height[a]++;
	}
}

template <class T>
int* Sets<T>::GetSet(int a)
{
	if ((a > n) || (a < 0))
		throw a; 
	if (parent[a] != a)
		throw a; 
	stack<int> st;
	int *res = new int;
	for (int i = 0; i<n; i++)
	{
		if (parent[i] == a)
			st.push(i);
	}
	res[0] = st.size();
	int j = 1;
	while (!st.empty())
	{
		res[j] = st.top();
		st.pop();
		j++;
	}
	return res;
}

template <class T>
void Sets<T>::Print()
{
	T*tmp = new T;
	for (int i = 0; i<n;i++)
	{
		if (parent[i] == i)
		{
			tmp = GetSet(i);
			if (tmp[0] > 1)
			{
				cout << '{';
				for (int k = 1; k <= tmp[0]; k++)
					cout << tmp[k] << ' ';
				cout << "} ";
			}
			else
				cout << '{' << tmp[1] << "} ";
		}
	}
	cout << endl;
}

template <class T>
class DataEdge : public Prior<T>
{
public:
	DataEdge(Edge<T>*);
	Edge<T> *e;
};

template <class T>
DataEdge<T>::DataEdge(Edge<T> *a)
{
	e = a;
	pr = e->weight;
}

