#include "edge.h"
#include "../geo_coordinate.h"
#include "vertex.h"
#include "../waypoint.h"
#include <gtest/gtest.h>

// Addedge

namespace ljankai
{
    TEST(VertexTest, CreatesEdgeBetweenTwoVertices)
    {
        Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));
        Waypoint wp2("Belgium", GeoCoordinate::FromDegrees(50.8503, 4.3517));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);

        Edge edge(vertex1, vertex2);
        EXPECT_NO_THROW(vertex1.AddEdge(edge));
    }

    TEST(VertexTest, CannotCreateEdgeBetweenThreeVertices)
    {
        Waypoint wp1("Cyprus", GeoCoordinate::FromDegrees(35.1856, 33.3823));
        Waypoint wp2("Czech Republic", GeoCoordinate::FromDegrees(50.0755, 14.4378));
        Waypoint wp3("Denmark", GeoCoordinate::FromDegrees(55.6867, 12.5701));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);
        Vertex vertex3(wp3);

        Edge edge(vertex1, vertex2);
        EXPECT_THROW(vertex3.AddEdge(edge), std::invalid_argument);
    }

    // EqualsTest

    TEST(VertexTest, EqualityOperatorWorks)
    {
        Waypoint wp1("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));
        Waypoint wp2("Finland", GeoCoordinate::FromDegrees(60.1699, 24.9384));
        Waypoint wp3("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);
        Vertex vertex3(wp3);

        EXPECT_TRUE(vertex1 == vertex3);
        EXPECT_TRUE(vertex3 == vertex1);

        EXPECT_TRUE(vertex1 != vertex2);
        EXPECT_TRUE(vertex2 != vertex3);

        EXPECT_FALSE(vertex1 == vertex2);
        EXPECT_FALSE(vertex2 == vertex3);

        EXPECT_FALSE(vertex1 != vertex3);
        EXPECT_FALSE(vertex3 != vertex1);
    }

    TEST(VertexTest, TestHash)
    {
        Waypoint wp1("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));
        Waypoint wp2("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));
        Waypoint wp3("Finland", GeoCoordinate::FromDegrees(60.1699, 24.9384));

        Vertex vertex1(wp1);
        Vertex vertex2(wp2);
        Vertex vertex3(wp3);

        EXPECT_EQ(Vertex::HashFunction()(vertex1), Vertex::HashFunction()(vertex2));
        EXPECT_NE(Vertex::HashFunction()(vertex1), Vertex::HashFunction()(vertex3));
    }
}
