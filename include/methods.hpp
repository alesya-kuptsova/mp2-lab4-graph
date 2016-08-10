#pragma once
#include "priorityqueue.hpp"
#include "bst.hpp"
#include "separateset.hpp"
#include "dheap.hpp"
#include "table.hpp"
#include "graph.hpp"

using namespace std;

template <class T>
class Algorithm
{
public:
	static Graph<T>* Kruskal(Graph<T>*&, Priority_queue<T>*&); 
	static T* Dijkstra(int, T *&, Graph<T>*&);
	static void SortP(dKucha<T>*& a);
};

template <class T>
Graph<T>* Algorithm<T>::Kruskal(Graph<T>*& gr, Priority_queue<T>*& queue)
{
	int n = gr->GetCount();//  получили макс. размер графа
	int m = gr->GetRealSize(); // получили текущий размер графа
	Graph<T> *tree = new Graph<T>(n, m); //создан граф
	Sets<T> *set = new Sets<T>(n); // создано разд. множество
	for (int i = 0; i<n; i++)
		set->CreateSet(i); // заполняется множество

	for (int i = 0; i<m;i++) //заполняем очередь весами
		queue->Insert(gr->GetEdge(i)->weight);

	int treeEdgeSize = 0;
	int x = 0;
	T tmp;

	while (treeEdgeSize < n - 1)
	{
		tmp = queue->Top();
		queue->Pop();

		int u = gr->GetEdge(x)->from;
		int v = gr->GetEdge(x)->to;
		T weight = tmp;

		int An = set->FindSet(u);
		int Ak = set->FindSet(v);
		if (An != Ak)
		{
			set->UnionSet(An, Ak);
			tree->Insert(u, v, weight);
			treeEdgeSize++;
		}
		x++;
	}

	return tree;
};

template <class T>
T* Algorithm<T>::Dijkstra(int s, T *&P, Graph<T>*& gr)
{
	int n = gr->GetCount();
	int m = gr->GetRealSize();
	if ((s < 0) || (s >= n))
		throw
		exception("Element doesn't exist"); 
	T **graph = new T*[n];
	for (int i = 0; i < n; i++)
		graph[i] = new T[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if ((gr->GetEdge(j)->from == i) || (gr->GetEdge(j)->to == i)) //граф заполнили
			{
				graph[gr->GetEdge(j)->from][gr->GetEdge(j)->to] = gr->GetEdge(j)->weight;
				graph[gr->GetEdge(j)->to][gr->GetEdge(j)->from] = gr->GetEdge(j)->weight;
			}
		}

	T *distance = new T[n];
	int *vis = new int[n];
	for (int i = 0; i < n; i++)
		vis[i] = -1;
	vis[0] = s;
	int path;
	int w, min;
	for (int i = 0; i < n; i++)
	{
		if (graph[s][i] == -1)
			distance[i] = MaxSize;
		else distance[i] = graph[s][i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		min = MaxSize;
		for (int k = 0; k < n; k++) {
			if (distance[k] < min && k != s && !gr->Scan(k, vis))
			{
				w = k;
				min = distance[k];
			}
		}
		if (min == MaxSize)
			break;
		vis[i] = w;
		for (int j = 0; j < n; j++)
		{
			if (!gr->Scan(j, vis) && graph[w][j] != -1 && (distance[w] + graph[w][j]) <= distance[j])
			{
				P[j] = w;
				distance[j] = distance[w] + graph[w][j];
			}
		}
	}

	distance[s] = 0;
	return distance;
}



template <class T>
void Algorithm<T>::SortP(dKucha<T>*& a)
{
	int tmp = a->count;
	for (int i = a->count - 1; i > 0; i--)
		a->Remove(0);
	a->count = tmp;
	tmp = 0;
	int tmp2 = a->count - 1;
	while (tmp <= tmp2)
	{
		a->Transpos(tmp2, tmp);
		tmp++;
		tmp2--;
	}
}