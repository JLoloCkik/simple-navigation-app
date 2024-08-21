#include "graph.h"
#include <stdexcept>

namespace ljankai
{
    Vertex::Vertex(const Waypoint& value) : value_(value)
    {
    }

    void Vertex::AddEdge(const Edge& edge)
    {
        if (edge.From() != *this)
        {
            throw std::invalid_argument("Illegal edge!");
        }

        edges_.push_back(edge);
    };

    Edge::Edge(Vertex& from, const Vertex& to) : from_(from),
                                                 to_(to),
                                                 weight_(from.Value().geo_coordinate.DistanceTo(
                                                     to.Value().geo_coordinate))
    {
        from.AddEdge(*this);
    }
}
