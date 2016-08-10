#include <iostream>
#include "graph.hpp"
#include "priorityqueue.hpp"
#include "methods.hpp"

typedef float T; // ���  ��� ������
// � ��� � ���� ���� ������ ������ �� ���� ���, ��� �����

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������� ���������� ������:" << endl;
	int n;
	cin >> n;
	cout << "������� ���������� ����" << endl;
	int m;
	cin >> m;
	Graph<T> *graph = new Graph<T>(n, m);
	T *P = new T[n];



	int type;
	cout << "�������� ��� �����" << endl << "1. ���� ��������� �������" << endl << "2. ������ ����" << endl;
	cin >> type;
	switch (type)
	{
	case 1:
	{
		cout << "������� ����������� � ������������ �������� ���� �����" << endl;
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
			cout << "������� ����� ��������� �������, �������� � ��� ��� ������� �����" << endl;
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
	cout << "����: " << endl << endl;
	graph->Print();
	cout << "����� ����� �����:" << endl;
	int a;
	cin >> a;
	for (int i = 0; i <= n; i++) // fixed
		P[i] = a;
	T *dist = Algorithm<T>::Dijkstra(a, P, graph);
	cout << "����: " << endl << endl;
	for (int i = 0; i<n; i++)
		cout << i << ' ';
	cout << "������� " << endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MaxSize)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ';
	cout << "���������� ���� " << endl << endl;
	for (int i = 0; i<n; i++)
		cout << P[i] << ' ';
	cout << "���������� ������� " << endl << endl;
	
}
