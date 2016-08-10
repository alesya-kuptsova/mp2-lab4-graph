#pragma once

#include <iostream>
#include <queue>
#include <stack>

using namespace std;


template <class T>
class Node
{
public:
	int balance;
	T key;
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;
	Node() { left = NULL; right = NULL; parent = NULL; balance = 0; };
	Node(const T& k) { key = k; left = NULL; right = NULL; parent = NULL; balance = 0; };
};

template <class T>
class Binary_search_tree
{
public:
	int size;
	Node<T> *root;
	Binary_search_tree();
	~Binary_search_tree();
	Binary_search_tree(const Binary_search_tree<T> &);
	Node<T>* Copy(Node<T> *);
	virtual void Insert (Node<T>*&, const Node<T> *);
	virtual void Remove(Node<T>*&, const T &);
	Node<T>* FindKey(Node<T>*, const T &);
	Node<T>* FindMax(Node<T>*);
	Node<T>* FindMin(Node<T>*);
	Node<T>* FindNext(Node<T>*, Node<T>*);
	Node<T>* FindPrevious(Node<T>*, Node<T>*);
	void WorkAroundWidth(Node<T>*); //на очереди
	void WorkAroundForward(Node<T>*);
	void WorkAroundReverse(Node<T>*);
	void WorkAroundSymmetric(Node<T>*);
	void WorkAroundDepth(Node<T>*); //на стеке
	int operator==(const Binary_search_tree<T>&) const;
	int GetSize();
	int GetHeight(Node<T>*);
};

template <class T>
Binary_search_tree<T>::Binary_search_tree()
{
	root = NULL;
	size = 0;
};

template <class T>
Binary_search_tree<T>::~Binary_search_tree()
{
	delete root;
};

template <class T>
Binary_search_tree<T>::Binary_search_tree(const Binary_search_tree<T> &tree)
{
	root = Copy(tree.root);
	size = tree.size;
};

template <class T>
Node<T>* Binary_search_tree<T>::Copy(Node<T> *newroot)
{
	if (newroot == NULL)
		return NULL;
	Node<T>* l = Copy(newroot->left);
	Node<T>* r = Copy(newroot->right);
	Node<T>* newtree = new Node<T>;
	newtree->key = newroot->key;
	newtree->left = l;
	newtree->right = r;
	root = newtree;
	return newtree;
};

template <class T>
void Binary_search_tree<T>::Insert(Node<T>* &tree, const Node<T> *node)
{
	T newkey = node->key;
	if (tree == NULL)
	{
		tree = new Node<T>;
		tree->key = newkey;
		size++;
		return;
	}
	Node<T>* tmp = tree;
	Node<T>* previous = new Node<T>;
	while (tmp != NULL)
	{
		previous = tmp;
		if (tmp->key <= newkey)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (previous->key <= newkey)
		previous->right = new Node<T>(newkey);
	else
		previous->left = new Node<T>(newkey);
	size++;
};

template <class T>
void Binary_search_tree<T>::Remove(Node<T>*& tree, const T &k)
{
	Node<T>* x = FindKey(tree, k);
	if (x == NULL)
		//return;
		throw
		exception("Key doesn't exist"); 
	if ((x->left == NULL) && (x->right == NULL))
	{
		delete x;
		return;
	}
	if ((x->left == NULL) && (x->right != NULL))
	{
		Node<T>* y = x->right;
		y->parent = x->parent;
		if (x->parent == NULL)
		{
			tree = y;
			return;
		}
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		tree = y;
		return;
	}
	if ((x->left != NULL) && (x->right == NULL))
	{
		Node<T>* y = x->left;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	Node<T>* y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	if (y->right != NULL)
		y->right->parent = y->parent;
	delete y;
};

template <class T>
Node<T>* Binary_search_tree<T>::FindKey(Node<T> *tree, const T &k)
{
	while ((tree != NULL) && (tree->key != k))
	{
		if (k < tree->key)
			tree = tree->left;
		if (k > tree->key)
			tree = tree->right;
	}
	return tree;
};

template <class T>
Node<T>* Binary_search_tree<T>::FindMin(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
};

template <class T>
Node<T>* Binary_search_tree<T>::FindMax(Node<T> *tree)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
};

template <class T>
Node<T>* Binary_search_tree<T>::FindNext(Node<T> *tree, Node<T> *node)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	if (node == NULL)
		throw
		exception("Node is empty"); 
	node = FindKey(tree, node->key);
	if (node->right != NULL)
		return FindMin(node->right);
	while ((node->parent != NULL) && (node->parent->right == node))
		node = node->parent;
	if (node->parent == NULL)
		throw
		exception("Parent doesn't exist"); 
	return node->parent;
};

template <class T>
Node<T>* Binary_search_tree<T>::FindPrevious(Node<T> *tree, Node<T> *node)
{
	if (tree == NULL)
		throw
		exception("Tree is empty"); 
	if (node == NULL)
		throw
		exception("Node is empty"); 
	node = FindKey(tree, node->key);
	if (node->right != NULL)
		return FindMax(node->left);
	while ((node->parent != NULL) && (node->parent->left == node))
		node = node->parent;
	if (node->parent == NULL)
		throw
		exception("Parent doesn't exist");
	return node->parent;
}

template <class T>
void Binary_search_tree<T>::WorkAroundWidth(Node<T> *tree)
{
	if (tree == NULL)
		return;
	queue <Node<T>*> q;
	q.push(tree);
	while (q.empty() == 0)
	{
		Node<T>* tmp = q.front();
		cout << tmp->key << '(' << tmp->balance << ')';
		q.pop();
		if (tmp->left != NULL)
			q.push(tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
	}
}

template <class T>
void Binary_search_tree<T>::WorkAroundDepth(Node<T> *tree)
{
	if (tree == NULL)
		return;
	stack<Node<T>*> s;
	s.push(tree);
	while (!s.empty())
	{
		Node<T>* tmp = s.top();
		cout << tmp->key << '(' << tmp->balance << ')';
		s.pop();
		if (tmp->right != NULL)
			s.push(tmp->right);
		if (tmp->left != NULL)
			s.push(tmp->left);
	}
}

template <class T>
void Binary_search_tree<T>::WorkAroundForward(Node<T> *tree)
{
	if (tree == NULL)
		return;
	cout << tree->key << '(' << tree->balance << ')';
	WorkAroundForward(tree->left);
	WorkAroundForward(tree->right);
}

template <class T>
void Binary_search_tree<T>::WorkAroundSymmetric(Node<T> *tree)
{
	if (tree == NULL)
		return;
	WorkAroundSymmetric(tree->left);
	cout << tree->key << '(' << tree->balance << ')';
		workAroundSymmetr(tree->right);
}

template <class T>
void Binary_search_tree<T>::WorkAroundReverse(Node<T> *tree)
{
	if (tree == NULL)
		return;
	WorkAroundReverse(tree->left);
	WorkAroundReverse(tree->right);
	cout << tree->key << '(' << tree->balance << ')';
}

template <class T>
int Binary_search_tree<T>::operator==(const Binary_search_tree<T>& tree)const
{
	if ((root == NULL) && (tree.root == NULL))
		return 1;
	if (size != tree.size)
		return 0;
	int *z = new int[size];
	int *b = new int[tree.size];
	queue <Node<T>*> q;
	queue <Node<T>*> p;
	q.push(root);
	int tmp1 = 0;
	int tmp2 = 0;
	while (q.empty() == 0)
	{
		Node<T>* tmp = q.front();
		z[tmp1] = tmp->key;
		q.pop();
		if (tmp->left != NULL)
			q.push(tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
		tmp1++;
	}
	p.push(root);
	while (p.empty() == 0)
	{
		Node<T>* tmp3 = p.front();
		b[tmp2] = tmp3->key;
		p.pop();
		if (tmp3->left != NULL)
			p.push(tmp3->left);
		if (tmp3->right != NULL)
			p.push(tmp3->right);
		tmp2++;
	}
	for (int i = 0; i<size; i++)
		if (z[i] != b[i])
			return 0;
	return 1;
}




template <class T>
int Binary_search_tree<T>::GetSize()
{
	return size;
}

template <class T>
int Binary_search_tree<T>::GetHeight(Node<T> *tree)
{
	if (tree == NULL)
		return 0;
		int l, r;
	if (tree->left != NULL)
	{
		l = GetHeight(tree->left);
	}
	else
		l = -1;
	if (tree->right != NULL)
	{
		r = GetHeight(tree->right);
	}
	else
		r = -1;
	int max = l > r ? l : r;
	return max + 1;
};