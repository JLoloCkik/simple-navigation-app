#include "edge.h"

#include <stdexcept>
#include "vertex.h"

namespace ljankai
{

    Edge::Edge(Vertex &from, const Vertex &to) : from_(from),
                                                 to_(to),
                                                 weight_(from.Value().geo_coordinate.DistanceTo(to.Value().geo_coordinate))
    {
        from.AddEdge(*this);
    }

}