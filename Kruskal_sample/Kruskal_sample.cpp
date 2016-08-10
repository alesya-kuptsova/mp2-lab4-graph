#include "methods.hpp"

typedef float T;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int q;
	cout << "Выберите тип приоритетной очереди" << endl << "1. На куче" << endl << "2. На бинарном поисковом дереве" << endl << "3. На таблице" << endl;
	cin >> q;
	system("cls");
	int n;
	cout << "Введите количество вершин" << endl;
	cin >> n;
	cout << "Введите количество рёбер" << endl;
	int m;
	cin >> m;
	Graph<T> *graph = new Graph<T>(n, m);
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
		for (int i = 0; i<m;i++)
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

	cout << "Граф " << endl << endl;
	graph->Print();
	Graph<T> *res = new Graph<T>(n, m);
	graph->Sorting();
	Priority_queue<T>* queue;
	int tmp2 = 0;
	if (q == 1)
		tmp2 = n;
	if (q == 3)
		tmp2 = m;
	Create_queue<T>::CreateQueue(queue, q, tmp2);
	res = Algorithm<T>::Kruskal(graph, queue);
	cout << endl << endl;
	res->Print();
}
