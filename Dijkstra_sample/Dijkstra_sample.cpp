#include <iostream>
#include "graph.hpp"
#include "priorityqueue.hpp"
#include "methods.hpp"

typedef float T; // вот  тип данных
// и вот в этой вещи смысла вообще не вижу Саш, это Лыков

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите количество вершин:" << endl;
	int n;
	cin >> n;
	cout << "Введите количество рёбер" << endl;
	int m;
	cin >> m;
	Graph<T> *graph = new Graph<T>(n, m);
	T *P = new T[n];



	int type;
	cout << "Выберите тип ввода" << endl << "1. Ввод случайным образом" << endl << "2. Ручной ввод" << endl;
	cin >> type;
	switch (type)
	{
	case 1:
	{
		cout << "Введите минимальное и максимальное значение веса ребра" << endl;
		T min, max;
		cin >> min;
		cin >> max;
		graph->CreateGraph(min, max);
		break;
	}
	case 2:
	{
		for (int i = 0; i<m; i++)
		{
			cout << "Введите номер начальной вершины, конечной и вес для каждого ребра" << endl;
			int f, t;
			T w;
			cin >> f;
			cin >> t;
			cin >> w;
			graph->Insert(f, t, w);
		}
		break;
	}
	}

	system("cls");
	cout << "Граф: " << endl << endl;
	graph->Print();
	cout << "Введи точку входа:" << endl;
	int a;
	cin >> a;
	for (int i = 0; i <= n; i++) // fixed
		P[i] = a;
	T *dist = Algorithm<T>::Dijkstra(a, P, graph);
	cout << "Итог: " << endl << endl;
	for (int i = 0; i<n; i++)
		cout << i << ' ';
	cout << "Вершины " << endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MaxSize)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ';
	cout << "Кратчайшие пути " << endl << endl;
	for (int i = 0; i<n; i++)
		cout << P[i] << ' ';
	cout << "Предыдущие вершины " << endl << endl;
	
}
