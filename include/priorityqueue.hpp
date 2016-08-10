#pragma once

#include "dheap.hpp"
#include "bst.hpp"
#include "table.hpp"

template <class T>
class Priority_queue
{
public:
	Priority_queue(void) {};
	virtual ~Priority_queue() {};
	virtual void Insert(const T) = 0;
	virtual void Pop() = 0;
	virtual int IsEmpty() = 0;
	virtual int GetSize() = 0;
	virtual T Top() = 0;
};

template <class T>
class Queue_on_heap : public Priority_queue<T>
{
private:
	dKucha<T> *heap;
public:
	Queue_on_heap(int);
	virtual ~Queue_on_heap() { delete heap; }
	void Insert(const T);
	void Pop();
	T Top();
	int IsEmpty();
	virtual int GetSize() { return heap->GetCount(); };
};

template <class T>
Queue_on_heap<T>::Queue_on_heap(int arity)
{
	if (arity < 0)
		throw
		exception("Arity must be positive");
	heap = new dKucha<T>(arity, 0);
}

template <class T>
void Queue_on_heap<T>::Pop()
{
	if (IsEmpty())
		throw
		exception("Queue is empty"); 
	heap->RemoveMin();
}

template <class T>
int Queue_on_heap<T>::IsEmpty()
{
	return heap->GetCount() == 0;
};

template <class T>
void Queue_on_heap<T>::Insert(const T x)
{
	heap->Insert(x);
	heap->Sorting();
}

template <class T>
T Queue_on_heap<T>::Top()
{
	if (IsEmpty())
		throw
		exception("Queue is empty");
	return heap->GetKey(0)->pr;
}



template <class T>
class Queue_on_tree : public Priority_queue <T>
{
private:
	Binary_search_tree<T> *tree;
public:
	Queue_on_tree();
	virtual ~Queue_on_tree() { delete tree; };
	virtual void Insert(const T x)
	{
		Node<T> *tmp = new Node<T>(x);
		tree->Insert(tree->root, tmp);
	}
	virtual void Pop()
	{
		tree->Remove(tree->root, tree->root->key);
	}
	virtual int IsEmpty() { return tree->GetSize() == 0; };
	virtual T Top() { return tree->root->key; };
	virtual int GetSize() { return tree->GetSize(); };
	int operator==(const Queue_on_tree<T>&)const;
};

template <class T>
Queue_on_tree<T>::Queue_on_tree()
{
	tree = new Binary_search_tree<T>;
}

template <class T>
int Queue_on_tree<T>::operator==(const Queue_on_tree<T>& newtree)const
{
	return *tree == *newtree.tree;
}


template <class T>
class Queue_on_table : public Priority_queue <T>
{
private:
	Sort_table<T>* table;
	int s;
public:
	Queue_on_table(int);
	~Queue_on_table();
	void Insert(T);
	void Pop();
	T Top();
	int IsEmpty();
	int GetSize();
};

template <class T>
Queue_on_table<T>::Queue_on_table(int x)
{
	if (x < 0)
		throw
		exception("Error"); 
	table = new Sort_table<T>(x);
	s = 0;
}

template <class T>
Queue_on_table<T>::~Queue_on_table()
{
	delete table;
}

template <class T>
void Queue_on_table<T>::Insert(T x)
{
	table->Insert(s, x);
	s++; 
}

template <class T>
void Queue_on_table<T>::Pop()
{
	if (IsEmpty())
		throw
		exception("Table is empty");
	table->Remove(table->Min()->GetKey());
	s--;
}

template <class T>
T Queue_on_table<T>::Top()
{
	return table->Min()->GetData();
}

template <class T>
int Queue_on_table<T>::GetSize()
{
	return table->GetCount();
}

template <class T>
int Queue_on_table<T>::IsEmpty()
{
	if (table->GetCount() == 0)
		return 1;
	return 0;
}

template <class T>
class Create_queue
{
public:
	static bool CreateQueue(Priority_queue<T>*&, const int, const int);
};

template <class T>
bool Create_queue<T>::CreateQueue(Priority_queue<T>*& q, const int a, const int b)
{
	if (a == 1)
	{
		q = new Queue_on_heap<T>(b);
		return true;
	}
	if (a == 2)
	{
		q = new Queue_on_tree<T>();
		return true;
	}
	if (a == 3)
	{
		q = new Queue_on_table<T>(b);
		return true;
	}
	return false;
}

