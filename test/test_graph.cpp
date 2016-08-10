#include <gtest.h>
#include "graph.hpp"

TEST(Graph, can_create_graph)
{
	Graph<int> *g;
	ASSERT_NO_THROW(g = new Graph<int>(5, 10));
}

TEST(Graph, throws_when_number_of_vertices_negative)
{
	ASSERT_ANY_THROW(Graph<int> *g = new Graph<int>(-2, 100));
}

TEST(Graph, throws_when_number_of_edges_negative)
{
	ASSERT_ANY_THROW(Graph<int> *g = new Graph<int>(2, -100));
}

TEST(Graph, can_get_set_of_edges)
{
	Graph<int> g(5, 10);
	ASSERT_NO_THROW(g.GetEdge(1));
}

TEST(Graph, created_graph_is_empty)
{
	Graph<int> g(5, 10);
	EXPECT_EQ(10, g.GetEdgeSize());
}

TEST(Graph, can_fill_rand_graph)
{
	Graph<int> g(5, 10);
	ASSERT_NO_THROW(g.CreateGraph(1, 5));
}

TEST(Graph, can_get_number_of_vertices)
{
	Graph<int> g(5, 10);
	g.CreateGraph(1, 5);
	EXPECT_EQ(g.GetRealSize(), 10);
}

TEST(Graph, can_add_edge_to_graph)
{
	Graph<int> g(5, 10);
	ASSERT_NO_THROW(g.Insert(1, 2, 3));
}

TEST(Graph, throws_when_set_weight_have_incorrect_first_or_second_argument)
{
	Graph<int> g(5, 10);
	ASSERT_ANY_THROW(g.Insert(2, 100, 1));
}

TEST(Graph, can_get_weight)
{
	Graph<int> g(5, 10);
	g.CreateGraph(1, 5);
	ASSERT_NO_THROW(g.GetWeight(1, 2));
}

TEST(Graph, throws_when_get_weight_have_incorrect_first_or_second_argument)
{
	Graph<int> g(5, 10);
	g.CreateGraph(1, 5);
	ASSERT_ANY_THROW(g.GetWeight(1, 20));
}

TEST(Graph, get_weight_works_properly)
{
	Graph<int> g(5, 10);
	g.Insert(1, 2, 1);
	EXPECT_EQ(1, g.GetWeight(1, 2));
}

TEST(Graph, can_remove_edge)
{
	Graph<int> g(5, 10);
	g.CreateGraph(-100, 100);
	ASSERT_NO_THROW(g.Remove(1, 2));
}

//TEST(Graph, throws_when_graph_is_full)
//{
//	Graph<int> g(2, 3);
//	ASSERT_ANY_THROW(g.Insert(1, 2, 3));
//}

TEST(Graph, throws_when_loop)
{
	Graph<int> g(5, 1);
	ASSERT_ANY_THROW(g.Insert(1, 1, 3));
}

TEST(Graph, throws_when_no_vertex)
{
	Graph<int> g(5, 1);
	ASSERT_ANY_THROW(g.Insert(6, 7, 8));
}

TEST(Graph, insertion_inreases_current)
{
	Graph<int> g(5, 1);
	int c = g.GetRealSize();
	g.Insert(1, 3, 4);
	EXPECT_EQ(g.GetRealSize(), c + 1);
}

TEST(Graph, throws_when_distance_incorrect)
{
	Graph<int> g(6, 1);
	ASSERT_ANY_THROW(g.CreateGraph(5, 1));
}

TEST(Graph, throws_when_removing_vertex_not_exist)
{
	Graph<int> g(5, 10);
	ASSERT_ANY_THROW(g.Remove(6, 1));
}

