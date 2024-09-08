#include "geo_coordinate.h"
#include "graph/edge.h"
#include "graph/graph.h"
#include "graph/vertex.h"
#include "waypoint.h"
#include <iostream>

using ljankai::GeoCoordinate;
using ljankai::Graph;
using ljankai::Vertex;
using ljankai::Waypoint;

int main()
{
  Waypoint wp1("1", GeoCoordinate::FromDegrees(0, 0));
  Waypoint wp2("2", GeoCoordinate::FromDegrees(0.010833, 0.061944));
  Waypoint wp3("3", GeoCoordinate::FromDegrees(0.040556, 0.07));
  Waypoint wp4("4", GeoCoordinate::FromDegrees(0.045833, 0.168889));
  Waypoint wp5("5", GeoCoordinate::FromDegrees(0.083889, 0.130833));
  Waypoint wp6("6", GeoCoordinate::FromDegrees(0.125, 0.015278));

  Vertex v1(wp1);
  Vertex v2(wp2);
  Vertex v3(wp3);
  Vertex v4(wp4);
  Vertex v5(wp5);
  Vertex v6(wp6);

  Graph g;
  g.AddVertex(v1);
  g.AddVertex(v2);
  g.AddVertex(v3);
  g.AddVertex(v4);
  g.AddVertex(v5);
  g.AddVertex(v6);

  g.AddEdge(v1, v2);
  g.AddEdge(v1, v3);
  g.AddEdge(v1, v6);

  g.AddEdge(v2, v1);
  g.AddEdge(v2, v3);
  g.AddEdge(v2, v4);

  g.AddEdge(v3, v1);
  g.AddEdge(v3, v2);
  g.AddEdge(v3, v4);
  g.AddEdge(v3, v6);

  g.AddEdge(v4, v2);
  g.AddEdge(v4, v3);
  g.AddEdge(v4, v5);

  g.AddEdge(v5, v4);
  g.AddEdge(v5, v6);

  g.AddEdge(v6, v1);
  g.AddEdge(v6, v3);
  g.AddEdge(v6, v5);

  auto shortest_path = g.ShortestPath(v1, v5);

  std::cout << "A legrövidebb út v1 és v5 között:" << std::endl;
  for (const Vertex *v : shortest_path)
  {
    std::cout << v->Value().GetName() << " -> " << std::endl;
  }
  std::cout << std::endl;

  return 0;

}
