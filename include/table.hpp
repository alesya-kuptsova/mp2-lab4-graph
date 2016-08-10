#pragma once

#include <iostream>

using namespace std;


template<class T>
class TabRecord
{
public:
	int key;
	T data;
	TabRecord(int k, T d) { key = k; data = d; }
	int GetKey() { return key; }
	T GetData() { return data; }
};


template<class T>
class Table
{
protected:
	int size;
	int count;
	int pos;
public:
	Table(int);
	virtual TabRecord<T>* FindKey(int) = 0;
	virtual void Insert(int, T) = 0;
	virtual void Remove(int) = 0;
	int	IsEmpty();
	int	IsFull();
	virtual int GetCount();
	virtual void Reset();
	virtual int	GoNext();
	virtual int IsTabEnded();
};

template <class T>
Table<T>::Table(int s)
{
	size = s;
	count = 0;
	pos = 0;
}

template <class T>
int Table<T>::IsEmpty()
{
	if (count == 0)
		return 1;
	return 0;
}

template <class T>
int Table<T>::IsFull()
{
	if (count == size)
		return 1;
	return 0;
}

template <class T>
int Table<T>::GetCount()
{
	return count;
}

template <class T>
void Table<T>::Reset()
{
	pos = 0;
}

template <class T>
int Table<T>::GoNext()
{
	if (!IsTabEnded())
	{
		pos++;
		return 1;
	}
	return 0;
}

template <class T>
int Table<T>::IsTabEnded()
{
	if (pos == count)
		return 1;
	return 0;
}


template<class T>
class ScanTable : public Table<T>
{
protected:
	TabRecord<T>** recs;
public:
	ScanTable(int size) : Table<T>(size)
	{
		recs = new TabRecord<T>*[size];
		for (int i = 0; i < size; i++)
			recs[i] = NULL;
	}
	virtual ~ScanTable()
	{
		for (int i = 0; i < size; i++)
			delete recs[i];
		delete[]recs;
	}

	virtual TabRecord<T>* FindKey(int k)
	{
		for (int i = 0; i < count; i++)
			if (k == recs[i]->GetKey())
			{
				pos = i;
				return recs[i];
			}
		return NULL;
	}
	virtual void Insert(int k, T d)
	{
		if (IsFull())
			throw
			exception("Table is empty");
		recs[count] = new TabRecord<T>(k, d);
		count++; 
	}
	virtual void Remove(int k)
	{
		if (IsEmpty())
			return;
		if (FindKey(k) == NULL)
			return;
		delete recs[pos];
		recs[pos] = recs[count - 1];
		count--; 
	}
	void Print();
	virtual int GetCount()
	{
		return count;
	}
	int GetSize();
	TabRecord<T>** GetRecs();
};

template <class T>
void ScanTable<T>::Print()
{
	for (int i = 0; i < count; i++)
		cout << recs[i]->GetKey() << " " << recs[i]->GetData() << endl;
}

template <class T>
int ScanTable<T>::GetSize()
{
	return size;
}

template <class T>
TabRecord<T>** ScanTable<T>::GetRecs()
{
	return recs;
}

template<class T>
class Sort_table : public ScanTable<T>
{
public:
	Sort_table(int size) : ScanTable<T>(size) {};
	Sort_table(ScanTable<T>& table) : ScanTable<T>(table) { Sorting(); }
	virtual ~Sort_table()
	{
		for (int i = 0; i < size; i++)
			delete recs[i];
		delete[]recs;
	}

	virtual TabRecord<T>* FindKey(int key)
	{
		int left = 0;
		int right = count - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (key < recs[mid]->GetKey())
			{
				right = mid - 1;
				pos = left;
			}
			else if (key > recs[mid]->GetKey())
			{
				left = mid + 1;
				pos = left;
			}
			else
			{
				pos = mid;
				return recs[mid];
			}
		}
		return 0;
	}
	virtual void Insert(int k, T d)
	{
		if (IsFull())
			throw
			exception("Table is full"); 
		TabRecord<T> *tmp;
		tmp = FindKey(k);
		for (int i = count + 1; i >= pos + 1; i--)
			recs[i] = recs[i - 1];
		recs[pos] = new TabRecord<T>(k, d);
		count++; 
	};
	virtual void Remove(int k)
	{
		if (IsEmpty())
			return;
		if (FindKey(k) == NULL)
			throw
			exception("Such element doesn't exist");

		for (int i = pos; i < count - 1; i++)
			recs[i] = recs[i + 1];
		recs[count] = NULL;
		count--; 
	}

	void Sorting();
	TabRecord<T>* Min();
};

template <class T>
void Sort_table<T>::Sorting()
{
	TabRecord<T> *tmp;
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
			if (recs[i]->GetKey() > recs[j]->GetKey())
			{
				tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
}

template <class T>
TabRecord<T>* Sort_table<T>::Min()
{
	return recs[0];
}

