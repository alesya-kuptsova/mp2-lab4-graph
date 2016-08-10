#include <gtest.h>
#include "priorityqueue.hpp"

TEST(queue_binary_search_tree, can_create_queue_binary_search_tree)
{
	ASSERT_NO_THROW(Queue_on_tree<int> *a = new Queue_on_tree<int>);
}

TEST(queue_binary_search_tree, isempty)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	EXPECT_EQ(a->IsEmpty(), 1);
}

TEST(queue_binary_search_tree, can_Push)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	ASSERT_NO_THROW(a->Insert(1));
}

TEST(queue_binary_search_tree, can_pop)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	a->Insert(1);
	ASSERT_NO_THROW(a->Pop());
}

TEST(queue_binary_search_tree, throw_if_Pop_empty_tree)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	ASSERT_ANY_THROW(a->Pop());
}

TEST(queue_binary_search_tree, can_Top_queue)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	a->Insert(1);
	ASSERT_NO_THROW(a->Top());
}



TEST(queue_binary_search_tree, can_getsize_queue)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	ASSERT_NO_THROW(a->GetSize());
}

TEST(queue_binary_search_tree, can_getsize_queue2)
{
	Queue_on_tree<int> *a = new Queue_on_tree<int>;
	a->Insert(1);
	EXPECT_EQ(1, a->GetSize());
}



TEST(Queue_heap, throws_when_heap_with_negative_arity)
{
	ASSERT_ANY_THROW(Queue_on_heap<int> *a = new Queue_on_heap<int>(-1));
}

TEST(Queue_heap, throws_when_pop_from_empty_heap)
{
	Queue_on_heap<int> *a = new Queue_on_heap<int>(3);
	ASSERT_ANY_THROW(a->Pop());
}

TEST(Queue_heap, throws_when_top_from_empty_heap)
{
	Queue_on_heap<int> *a = new Queue_on_heap<int>(3);
	ASSERT_ANY_THROW(a->Top());
}

TEST(Queue_table, throws_when_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue_on_table<int> *a = new Queue_on_table<int>(-1));
}

TEST(Queue_table, insertion_increases_size)
{
	Queue_on_table<int> *a = new Queue_on_table<int>(2);
	int s = a->GetSize();
	a->Insert(6);
	EXPECT_EQ(a->GetSize(), s + 1);
}

TEST(Queue_table, pop_decreases_size)
{
	Queue_on_table<int> *a = new Queue_on_table<int>(2);	
	a->Insert(6);
	int s = a->GetSize();
	a->Pop();
	EXPECT_EQ(a->GetSize(), s - 1);
}