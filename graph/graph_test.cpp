#include "graph.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "edge.h"

namespace ljankai
{
    using ::testing::UnorderedElementsAre;

    TEST(GraphTest, AddVertex)
    {
        Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));

        Vertex vertex1(wp1);
        Graph graph;
        graph.AddVertex(vertex1);
        EXPECT_THAT(graph.Vertices(), UnorderedElementsAre(vertex1));
    }

    TEST(GraphTest, DoesNotAddVertexIfAlreadyExists)
    {
        Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));
        Waypoint wp2("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);

        Graph graph;
        graph.AddVertex(vertex1);

        EXPECT_THROW(graph.AddVertex(vertex2), std::invalid_argument);
    }

    TEST(GraphTest, AddEdge)
    {
        Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));
        Waypoint wp2("Belgium", GeoCoordinate::FromDegrees(50.8503, 4.3517));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);

        Graph graph;

        graph.AddVertex(vertex1);
        graph.AddVertex(vertex2);

        EXPECT_NO_THROW(graph.AddEdge(vertex1, vertex2));
    }

    TEST(GraphTest, DoesNotAddEdgeIfFromNotFound)
    {
        Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));
        Waypoint wp2("Belgium", GeoCoordinate::FromDegrees(50.8503, 4.3517));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);

        Graph graph;

        graph.AddVertex(vertex2);

        EXPECT_THROW(graph.AddEdge(vertex1, vertex2), std::invalid_argument);
    }

    TEST(GraphTest, DoesNotAddEdgeIfToNotFound)
    {
        Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));
        Waypoint wp2("Belgium", GeoCoordinate::FromDegrees(50.8503, 4.3517));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);

        Graph graph;

        graph.AddVertex(vertex1);

        EXPECT_THROW(graph.AddEdge(vertex1, vertex2), std::invalid_argument);
    }

}
