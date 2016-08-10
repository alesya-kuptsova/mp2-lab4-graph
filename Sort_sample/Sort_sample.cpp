#include "methods.hpp"
#include "dheap.hpp"
#include <time.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������� ����������� ����" << endl;
	int a;
	cin >> a;
	dKucha<float> *heap = new dKucha <float>(a, 0);
	cout << "������� ���������� ��������� � ����" << endl;
	int b;
	cin >> b;
	int c;
	srand(time(NULL));
	for (int i = 0; i<b; i++)
	{
		c = 1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10 - 1)));
		heap->Insert(c);
	}
	system("cls");
	cout << "�� ����������: " << endl;
	heap->Print();
	cout << endl;
	cout << "����� ����������: " << endl;
	heap->Heapify();
	Algorithm<float>::SortP(heap);
	heap->Print();

}