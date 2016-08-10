#include <gtest.h>
#include "bst.hpp"


TEST(Binary_search_tree, can_create_tree)
{
	ASSERT_NO_THROW(Binary_search_tree<int>*tree = new Binary_search_tree<int>());
}

TEST(Binary_search_tree, can_copy_tree)
{
	Binary_search_tree<int>*tree = new Binary_search_tree<int>();
	Node<int> *copytree = new Node<int>();
	copytree->key = 6;
	tree->Insert(tree->root, copytree);
	ASSERT_NO_THROW(Binary_search_tree<int>*copytree = new Binary_search_tree<int>(*tree));
}

TEST(Binary_search_tree, copied_tree_is_equal_to_source_one)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	Binary_search_tree<int>*c = new Binary_search_tree<int>(*a);
	int d = a->operator==(*c);
	EXPECT_EQ(d, 1);
}

TEST(Binary_search_tree, FindKey_works_properly)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b = a->FindKey(a->root, 2);
	EXPECT_EQ(b->key, 2);
}

TEST(Binary_search_tree, FindMin_works_properly)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	Node<int>*c = a->FindMin(a->root);
	EXPECT_EQ(c->key, 0);
}

TEST(Binary_search_tree, throws_when_FindMin_from_empty_tree)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	ASSERT_ANY_THROW(a->FindMin(a->root));
}

TEST(Binary_search_tree, FindMax_works_properly)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	Node<int>*c = a->FindMax(a->root);
	EXPECT_EQ(c->key, 9);
}

TEST(Binary_search_tree, throws_when_FindMax_from_empty_tree)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	ASSERT_ANY_THROW(a->FindMax(a->root));
}

TEST(Binary_search_tree, FindNext_works_properly)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	b->key = 6;
	Node<int>*c = a->FindNext(a->root, b);
	EXPECT_EQ(c->key, 7);
}

TEST(Binary_search_tree, can_find_previous)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	b->key = 6;
	Node<int>*c = a->FindPrevious(a->root, b);
	EXPECT_EQ(c->key, 5);
}

TEST(Binary_search_tree, GetSize_works_properly)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	EXPECT_EQ(a->GetSize(), 9);
}

TEST(Binary_search_tree, GetHeight_works_properly)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	b->key = 6;
	a->Insert(a->root, b);
	b->key = 8;
	a->Insert(a->root, b);
	b->key = 2;
	a->Insert(a->root, b);
	b->key = 4;
	a->Insert(a->root, b);
	b->key = 0;
	a->Insert(a->root, b);
	b->key = 5;
	a->Insert(a->root, b);
	b->key = 1;
	a->Insert(a->root, b);
	b->key = 7;
	a->Insert(a->root, b);
	EXPECT_EQ(a->GetHeight(a->root), 4);
}

TEST(Binary_search_tree, throws_when_no_next)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>;
	Node<int>*b = new Node<int>(1);
	ASSERT_ANY_THROW(a->FindNext(a->root, b));
}

TEST(Binary_search_tree, throws_when_no_previous)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>;
	Node<int>*b = new Node<int>(1);
	ASSERT_ANY_THROW(a->FindPrevious(a->root, b));
}

TEST(Binary_search_tree, throws_when_remove_incorrect_element)
{
	Binary_search_tree<int>*a = new Binary_search_tree<int>();
	Node<int>*b = new Node<int>();
	b->key = 9;
	a->Insert(a->root, b);
	ASSERT_ANY_THROW(a->Remove(a->root, 47));
}