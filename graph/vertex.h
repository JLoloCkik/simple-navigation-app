#ifndef LJANKAI_VERTEX_H
#define LJANKAI_VERTEX_H

#include <vector>
#include "edge.h"
#include "../waypoint.h"

namespace ljankai
{
    class Edge;
    class Vertex
    {
    public:
        explicit Vertex(const Waypoint &value);

        const Waypoint &Value() const
        {
            return value_;
        }

        void AddEdge(const Edge &edge);

        const std::vector<Edge> &Edges() const
        {
            return edges_;
        }

        bool operator==(const Vertex &other) const
        {
            return value_ == other.value_;
        };

        bool operator!=(const Vertex &other) const
        {
            return !(*this == other);
        };

        struct HashFunction
        {
            size_t operator()(const Vertex &vertex) const
            {
                return 7 * (17 + Waypoint::HashFunction()(vertex.value_));
            }

            size_t operator()(const Vertex *vertex) const
            {
                return 7 * (17 + Waypoint::HashFunction()(vertex->value_));
            }
        };

        struct EqualsFunction
        {
            bool operator()(const Vertex *lhs, const Vertex *rhs) const
            {
                return *lhs == *rhs;
            }
        };

    private:
        const Waypoint value_;
        std::vector<Edge> edges_;
    };

}

#endif
