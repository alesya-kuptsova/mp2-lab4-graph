#include <gtest.h>
#include "dheap.hpp"

TEST(dKucha, can_create_heap)
{
	ASSERT_NO_THROW(dKucha<int> *a = new dKucha<int>(3, 10));
}

TEST(dKucha, throws_when_size_negative)
{
	ASSERT_ANY_THROW(dKucha<int> * heap = new dKucha<int>(3, -10));
}

TEST(dKucha, throws_when_arity_is_negative)
{
	ASSERT_ANY_THROW(dKucha<int> *heap = new dKucha<int>(-3, 10));
}

TEST(dKucha, can_copy_heap)
{
	dKucha<int> *a = new dKucha<int>(3, 10);
	ASSERT_NO_THROW(dKucha<int> *b = new dKucha<int>(*a));
}

TEST(dKucha, GetParent_works_properly)
{
	dKucha<int>*a = new dKucha<int>(3, 11);
	int c = a->GetPar(6);
	EXPECT_EQ(c, 1);
}

TEST(dKucha, Swap_works_properly)
{
	int c;
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	dKucha<int>*b = new dKucha<int>(3, 0);
	b->Insert(8);
	b->Insert(5);

	b->Transpos(0, 1);
	c = a->operator==(*b);
	EXPECT_EQ(c, 1);
}

TEST(dKucha, throws_when_swap_wrong_elements)
{
	dKucha<int>*a = new dKucha<int>(3, 13);
	ASSERT_ANY_THROW(a->Transpos(15, 17));
}

TEST(dKucha, can_sift_up)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	ASSERT_NO_THROW(a->Pop(1));
}

TEST(dKucha, SiftUp_works_properly)
{
	int c;
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	a->Insert(7);
	a->Insert(14);
	a->Insert(15);
	a->Insert(12);
	a->Insert(18);
	a->Insert(8);
	a->Insert(10);
	a->Insert(12);
	a->Insert(14);
	a->Insert(15);
	a->Insert(13);
	a->Pop(12);

	dKucha<int>*b = new dKucha<int>(3, 0);
	b->Insert(5);
	b->Insert(8);
	b->Insert(7);
	b->Insert(13);
	b->Insert(15);
	b->Insert(12);
	b->Insert(18);
	b->Insert(8);
	b->Insert(10);
	b->Insert(12);
	b->Insert(14);
	b->Insert(15);
	b->Insert(14);
	c = a->operator==(*b);
	EXPECT_EQ(c, 1);
}

TEST(dKucha, throws_when_SiftUp_nonexisting_element)
{
	dKucha<int>*a = new dKucha<int>(3, 13);
	ASSERT_ANY_THROW(a->Pop(16));
}

TEST(dKucha, MinChild_works_properly)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	a->Insert(7);
	a->Insert(14);
	a->Insert(15);
	a->Insert(12);
	a->Insert(18);
	a->Insert(8);
	a->Insert(10);
	a->Insert(12);
	a->Insert(14);
	a->Insert(15);
	a->Insert(13);
	int b = a->MinChild(0);
	EXPECT_EQ(b, 2);
}



TEST(dKucha, SiftDown_works_properly)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(30);
	a->Insert(7);
	a->Insert(12);
	a->Insert(15);
	a->Insert(12);
	a->Insert(18);
	a->Insert(8);
	a->Insert(10);
	a->Insert(12);
	a->Insert(14);
	a->Insert(15);
	a->Insert(13);
	a->Deep(1);

	dKucha<int>*b = new dKucha<int>(3, 0);
	b->Insert(5);
	b->Insert(12);
	b->Insert(7);
	b->Insert(12);
	b->Insert(15);
	b->Insert(30);
	b->Insert(18);
	b->Insert(8);
	b->Insert(10);
	b->Insert(12);
	b->Insert(14);
	b->Insert(15);
	b->Insert(13);
	int c = a->operator==(*b);
	EXPECT_EQ(c, 1);
}




TEST(dKucha, throws_when_SiftDown_nonexisting_elements)
{
	dKucha<int>*a = new dKucha<int>(3, 13);
	ASSERT_ANY_THROW(a->Deep(20));
}

TEST(dKucha, RemiveMin_works_properly)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	a->Insert(7);
	a->Insert(12);
	a->Insert(15);
	a->Insert(12);
	a->Insert(18);
	a->Insert(8);
	a->Insert(10);
	a->Insert(12);
	a->Insert(14);
	a->Insert(15);
	a->Insert(13);
	a->RemoveMin();

	dKucha<int>*b = new dKucha<int>(3, 0);
	b->Insert(7);
	b->Insert(8);
	b->Insert(8);
	b->Insert(12);
	b->Insert(15);
	b->Insert(12);
	b->Insert(18);
	b->Insert(13);
	b->Insert(10);
	b->Insert(12);
	b->Insert(14);
	b->Insert(15);
	int c = a->operator==(*b);
	EXPECT_EQ(c, 1);
}

TEST(dKucha, Remove_works_properly)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	a->Insert(7);
	a->Insert(12);
	a->Insert(15);
	a->Insert(12);
	a->Insert(18);
	a->Insert(8);
	a->Insert(10);
	a->Insert(12);
	a->Insert(14);
	a->Insert(15);
	a->Insert(13);
	a->Remove(2);

	dKucha<int>*b = new dKucha<int>(3, 0);
	b->Insert(5);
	b->Insert(8);
	b->Insert(8);
	b->Insert(12);
	b->Insert(15);
	b->Insert(12);
	b->Insert(18);
	b->Insert(13);
	b->Insert(10);
	b->Insert(12);
	b->Insert(14);
	b->Insert(15);
	int c = a->operator==(*b);
	EXPECT_EQ(c, 1);
}

TEST(dKucha, throws_when_remove_nonexisting_element)
{
	dKucha<int>*a = new dKucha<int>(3, 13);
	ASSERT_ANY_THROW(a->Remove(16));
}

TEST(dKucha, removing_decreases_count)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	int c = a->GetCount();
	a->Remove(1);
	EXPECT_EQ(a->GetCount(),c-1);
}

TEST(dKucha, Heapify_works_properly)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	a->Insert(5);
	a->Insert(8);
	a->Insert(7);
	a->Insert(12);
	a->Insert(15);
	a->Insert(12);
	a->Insert(18);
	a->Insert(8);
	a->Insert(10);
	a->Insert(12);
	a->Insert(14);
	a->Insert(15);
	a->Insert(13);
	a->Heapify();
	int c = a->operator==(*a);
	EXPECT_EQ(c, 1);
}

TEST(dKucha, throws_when_heap_is_empty)
{
	dKucha<int>*a = new dKucha<int>(3, 0);
	ASSERT_ANY_THROW(a->Heapify());
}


TEST(dKucha, insertion_increases_count)
{
	dKucha<int>*a = new dKucha<int>(3, 13);
	int c = a->GetCount();
	a->Insert(15);
	EXPECT_EQ(a->GetCount(), c + 1);
}

