#ifndef LJANKAI_GRAPH_H
#define LJANKAI_GRAPH_H

#include <unordered_set>
#include "vertex.h"

namespace ljankai
{
    class Graph
    {
    public:
        Graph();
        void AddVertex(const Vertex &vertex);
        void AddEdge(const Vertex &from, const Vertex &to);

    private:
        std::unordered_set<Vertex> vertices_;
    };
}
#endif