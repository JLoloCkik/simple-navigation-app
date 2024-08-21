#include "edge.h"
#include "../geo_coordinate.h"
#include "vertex.h"
#include "../waypoint.h"
#include <gtest/gtest.h>

using ljankai::Edge;
using ljankai::Vertex;
using ljankai::Waypoint;
using ljankai::GeoCoordinate;


//AddEdge

TEST(VertexTest, AustriaToBelgium) {
    Waypoint wp1("Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738));
    Waypoint wp2("Belgium", GeoCoordinate::FromDegrees(50.8503, 4.3517));

    Vertex vertex1(wp1);
    Vertex vertex2(wp2);

    Edge edge(vertex1, vertex2);
    EXPECT_NO_THROW(vertex1.AddEdge(edge));
}