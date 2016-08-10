#include "methods.hpp"

typedef float T;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int q;
	cout << "�������� ��� ������������ �������" << endl << "1. �� ����" << endl << "2. �� �������� ��������� ������" << endl << "3. �� �������" << endl;
	cin >> q;
	system("cls");
	int n;
	cout << "������� ���������� ������" << endl;
	cin >> n;
	cout << "������� ���������� ����" << endl;
	int m;
	cin >> m;
	Graph<T> *graph = new Graph<T>(n, m);
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
		for (int i = 0; i<m;i++)
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

	cout << "���� " << endl << endl;
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
