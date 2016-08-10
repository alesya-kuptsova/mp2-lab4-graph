#include "separateset.hpp"

#include <gtest.h>

TEST(Sets, can_create_disjoint_set)
{
	ASSERT_NO_THROW(Sets<int>set = Sets<int>(5));
}

TEST(Sets, throws_when_set_size_negative)
{
	ASSERT_ANY_THROW(Sets<int>set(-2));
}

TEST(Sets, can_create_singleton)
{
	Sets<int>set(5);
	ASSERT_NO_THROW(set.CreateSet(1));
}

TEST(Sets, throws_when_singleton_size_negative)
{
	Sets<int>set(5);
	ASSERT_ANY_THROW(set.CreateSet(-1));
}


TEST(Sets, can_find_set)
{
	Sets<int>set(5);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_NO_THROW(set.FindSet(0));
}

TEST(Sets, throws_when_find_set_with_negative_size)
{
	Sets<int>set(2);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_ANY_THROW(set.FindSet(-2));
}

TEST(Sets, throws_when_find_nonexisting_element)
{
	Sets<int>set(2);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_ANY_THROW(set.FindSet(20));
}

TEST(Sets, throws_when_find_set_with_size_too_large)
{
	Sets<int>set(4);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_ANY_THROW(set.FindSet(100));
}


TEST(Sets, can_union)
{
	Sets<int>set(6);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_NO_THROW(set.UnionSet(0, 1));
}


TEST(Sets, throws_when_union_with_negative_size)
{
	Sets<int>set(3);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_ANY_THROW(set.UnionSet(0, -1));
}

TEST(Sets, throws_when_union_with_size_too_large)
{
	Sets<int>set(2);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_ANY_THROW(set.UnionSet(0, 10));
}

TEST(Sets, throws_when_get_set_with_incorrect_element_or_size)
{
	Sets<int>set(2);
	set.CreateSet(0);
	set.CreateSet(1);
	ASSERT_ANY_THROW(set.GetSet(47));
	ASSERT_ANY_THROW(set.GetSet(-47));
}