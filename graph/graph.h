#ifndef LJANKAI_GRAPH_H
#define LJANKAI_GRAPH_H

#include <list>
#include <unordered_set>
#include "vertex.h"

namespace ljankai
{
    class Graph
    {
    public:
        void AddVertex(const Vertex &vertex);
        void AddEdge(Vertex &from, const Vertex &to);
        const std::unordered_set<Vertex, Vertex::HashFunction> &Vertices() const
        {
            return vertices_;
        }

        const std::list<const Vertex *> ShortestPath(const Vertex &from, const Vertex &to) const;

    private:
        std::unordered_set<Vertex, Vertex::HashFunction> vertices_;
    };
}
#endif
