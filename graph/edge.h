#ifndef LJANKAI_EDGE_H
#define LJANKAI_EDGE_H

#include "vertex.h"

namespace ljankai
{
    class Vertex;

    class Edge
    {

    public:
        Edge(Vertex& from, const Vertex& to);

        const Vertex& From() const
        {
            return from_;
        }

    private:
        const Vertex& from_;
        const Vertex& to_;
        const double weight_;
    };
}
#endif
