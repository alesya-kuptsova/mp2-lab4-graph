#pragma once 

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


template <class T>
class Edge
{
public:
	Edge(int, int, T);
	int from;
	int to;
	T weight;
};

template <class T>
class Graph
{
private:
	int n; //number of vertices
	int m; //number of edges
	Edge<T>** edges;
	int current;
public:
	Graph(int, int);
	~Graph();
	void CreateGraph(T, T);
	void Insert(int, int, T);
	void Remove(int, int);
	int GetCount(); //vertices
	int GetEdgeSize();
	int GetRealSize();
	Edge<T>*  GetEdge(int);
	T GetWeight(int, int);
	void Print();
	int FindEdge(int, int);
	void Create(int&, int&);
	bool Scan(int, int*);
	void Sorting();
};

template <class T>
Edge<T>::Edge(int f, int t, T w)
{
	from = f;
	to = t;
	weight = w;
}

template <class T>
Graph<T>::Graph(int v, int e)
{
	if (v < 0)
		throw -1; 
	else
		n = v;
	if ((e < 0) || (e > n * (n - 1) / 2))
		throw -1;
	else
		m = e;
	current = 0;
	edges = new Edge<T>*[m];
}

template <class T>
Graph<T>::~Graph()
{
	for (int i = 0; i < current; i++)
		delete edges[i];
	delete[] edges;
}

template <class T>
void Graph<T>::Insert(int f, int t, T w)
{
	if (current == m)
		throw -1; 
	if (f == t)
		throw -1;
	if ((f > n) || (t > n))
		throw -1; 
	edges[current] = new Edge<T>(f, t, w);
	current++; //test
}

template <class T>
void Graph<T>::Create(int &f, int &t)
{
	do
	{
		f = rand() % n;
		t = rand() % n;
	} while ((f == t) || (FindEdge(f, t) != -1));
}

template <class T>
void Graph<T>::CreateGraph(T f, T t)
{
	if (f > t)
		throw -1; 
	int u, v;
	T newweight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		Create(u, v);
		newweight = f + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (t - f)));
		edges[i] = new Edge<T>(u, v, newweight);
		current++;
	}
}

template <class T>
int Graph<T>::GetCount()
{
	return n;
}

template <class T>
int Graph<T>::GetEdgeSize()
{
	return m;
}

template <class T>
int Graph<T>::GetRealSize()
{
	return current;
}

template <class T>
T Graph<T>::GetWeight(int f, int t)
{
	if ((f < 0) || (f > n) || (t < 0) || (t > n))
		throw -1; 
	for (int i = 0; i < current; i++)
		if ((edges[i]->from == f) && (edges[i]->to == t) || (edges[i]->from == t) && (edges[i]->to == f))
			return edges[i]->weight;
	return 0;
}

template <class T>
void Graph<T>::Print()
{
	cout << "От  до " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < current; j++)
			if (edges[j]->from == i)
				cout << edges[j]->from << " " << edges[j]->to << "(" << edges[j]->weight << ")" << endl;
}

template <class T>
Edge<T>* Graph<T>::GetEdge(int x)
{
	return edges[x];
}

template <class T>
void Graph<T>::Remove(int f, int t)
{
	int tmp = FindEdge(f, t);
	if (tmp == -1)
		throw -1; 
	delete edges[tmp];
	edges[tmp] = edges[current - 1];
	current--; //test
}

template <class T>
int Graph<T>::FindEdge(int f, int t)
{
	for (int i = 0; i < current; i++)
	{
		if ((edges[i]->from == f) && (edges[i]->to == f) || (edges[i]->from == t) && (edges[i]->to == t))
			return -1;
		if ((edges[i]->from == f) && (edges[i]->to == t) || (edges[i]->to == f) && (edges[i]->from == t))
			return i;
	}
	return -1;

}

template <class T>
bool Graph<T>::Scan(int f, int* b)
{
	bool res = false;
	for (int i = 0;i < n; i++)
		if (b[i] == f)
			res = true;
	return res;
}

