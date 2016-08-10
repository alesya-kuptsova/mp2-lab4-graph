#pragma once

#include <iostream>
#include <cmath>

#define MaxSize 10000 // - максимальный размер кучи

using namespace std;

template <class T>
class Prior
{
public:
	T pr;
};

template <class T>
class Dist : public Prior<T>
{
public:
	int vertice;
	Dist(int, T);
};

template <class T>
class dKucha
{
public:
	int d;
	Prior<T>** keys;
	int count;
public:
	dKucha(int, int);
	dKucha(const dKucha<T>&);
	~dKucha();
	int GetPar(int);
	void Transpos(const int, const int); // - перестановка
	void Pop(int); // - всплытие
	void Deep(int); // - погружение
	int MinChild(int);// - поиск минимального эл-та (его позиции)
	void RemoveMin();// - удаление минимального эл-та
	void Remove(int);//- удаление 
	void Insert(T);// - вставка
	void Heapify();// - окучивание
	void GetH();
	int operator==(const dKucha<T>&) const;
	dKucha& operator=(const dKucha<T>&);
	int GetCount();
	Prior<T>* GetKey(int);
	void Sorting();
	void Print();
	void СhangeKey(int pos, int newkey);
	T GetKeyPr(int);
};

template <class T>
Dist<T>::Dist(int v, T w)
{
	vertice = v;
	pr = w;
}

template <class T>
dKucha<T>::dKucha(const int len, const int s)// len - длина (арность)
{
	if (len <= 0)
		throw -1; 
	if ((s < 0) || (s > MaxSize))
		throw -1; 
	d = len;
	count = s;
	keys = new Prior<T>*[MaxSize];
};

template <class T>
dKucha<T>::dKucha(const dKucha &h)
{
	d = h.d;
	count = h.count;
	keys = new Prior<T>*[MaxSize];
	for (int i = 0; i <= count - 1; i++)
		keys[i] = h.keys[i];
};

template <class T>
dKucha<T>::~dKucha()
{
	delete[]keys;
}

template <class T>
int dKucha<T>::GetPar(int x)
{
	int p;
	return p = (x - 1) / d;
}

template <class T>
void dKucha<T>::Transpos(const int x, const int y)  
{
	if ((x > count - 1) || (y > count - 1))
		throw -1;
	Prior<T> *tmp = new Prior<T>;
	tmp->pr = keys[x]->pr;
	keys[x]->pr = keys[y]->pr;
	keys[y]->pr = tmp->pr;
}

template <class T>
void dKucha<T>::Pop(int x)
{
	if (x > count - 1)
		throw -1; 
	int p = GetPar(x);
	while ((p >= 0) && (keys[p]->pr > keys[x]->pr))
	{
		if (p == 0)
		{
			Transpos(x, p);
			return;
		}
		Transpos(x, p);
		x = p;
		p = GetPar(x);
	}
}

template <class T>
int dKucha<T>::MinChild(int x)
{
	if (x * d + 1 > count - 1)
		return -1;
	int minch = x * d + 1;
	int maxch;
	if (x * d + d < count - 1)
		maxch = x * d + d;
	else
		maxch = count - 1;
	for (int i = minch; i <= maxch; i++)
		if (keys[i]->pr < keys[minch]->pr)
			minch = i;
	return minch;
}

template <class T>
void dKucha<T>::Deep(int x)
{
	if (x > count)
		throw -1;
	int c = MinChild(x);
	while ((c != -1) && (keys[c]->pr < keys[x]->pr))
	{
		Transpos(c, x);
		x = c;
		c = MinChild(x);
	}
}

template <class T>
void dKucha<T>::RemoveMin()
{
	keys[0] = keys[count - 1];
	count--;
	Deep(0);
}

template <class T>
void dKucha<T>::Remove(int x)
{
	if (x >= count)
		throw -1; 
	Transpos(x, count - 1);
	count--; 
	if (keys[x]->pr < keys[GetPar(x)]->pr)
		Pop(x);
	else Deep(x);
}

template <class T>
void dKucha<T>::Insert(T x)
{
	Prior<T>* tmp2 = new Prior<T>;
	tmp2->pr = x;
	count++; 
	if (count > MaxSize) //- типо проверили на полноту
		throw -1; 
	Prior<T>** tmp = new Prior<T>*[MaxSize];
	for (int i = 0; i < count - 1; i++)
		tmp[i] = keys[i];
	tmp[count - 1] = tmp2;
	keys = tmp;
}

template <class T>
void dKucha<T>::Heapify()
{
	if (count == 0)//- типо проверили на пустоту
		throw -1; 
	for (int i = count - 1; i >= 0; i--)
		Deep(i);
}

template <class T>
int dKucha<T>::operator==(const dKucha<T>& h) const
{
	if (h.count != count)
		return 0;
	for (int i = 0; i < h.count; i++)
		if (keys[i]->pr != h.keys[i]->pr)
			return 0;
	return 1;
}

template <class T>
void dKucha<T>::GetH()
{
	int level = 0;
	int tmp = 0;
	while (tmp < count)
	{
		tmp += pow(d, level);
		level++;
	}
	int k = 1, z = 0;
	cout << ' ' << keys[0]->pr << endl;
	for (int i = 1; i < level; i++)
	{
		for (int j = k; (j < k + pow(d, i)) && (j < count); j++)
			cout << keys[j]->pr << ' ';
		cout << endl;
		if (k + pow(d, i) > count)
			k = count;
		else
			k += pow(d, i);
	}
}

template <class T>
dKucha<T>& dKucha<T>::operator=(const dKucha<T>& h)
{
	d = h.d;
	count = h.count;
	for (int i = 0; i < count; i++)
		keys[i] = h.keys[i];
	return *this;
}

template <class T>
int dKucha<T>::GetCount()
{
	return count;
}

template <class T>
Prior<T>* dKucha<T>::GetKey(int x)
{
	return keys[x];
}

template <class T>
void dKucha<T>::Print()
{
	int level = 0, tmp = 0;
	while (tmp < count)
	{
		tmp += pow(d, level);
		level++;
	}
	int k = 1, z = 0;
	cout << " " << keys[0]->pr << " ";
	for (int i = 1; i < level; i++)
	{
		for (int j = k; (j < k + pow(d, i)) && (j < count); j++)
			cout << keys[j]->pr << " ";
		if (k + pow(d, i) > count)
			k = count;
		else k += pow(d, i);
	}
}

template<class T>
void dKucha<T>::СhangeKey(int pos, int newkey)
{
	if (pos >= count || pos < 0)
		throw pos;
	keys[pos]->pr = newkey;
}

template<class T>
T dKucha<T>::GetKeyPr(int a)
{
	return keys[a]->pr;
}
