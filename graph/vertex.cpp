#include "vertex.h"

#include <stdexcept>
#include "edge.h"
#include "../waypoint.h"

namespace ljankai
{
    Vertex::Vertex(const Waypoint &value) : value_(value)
    {
    }

    void Vertex::AddEdge(const Edge &edge) 
    {
        if (edge.From() != *this)
        {
            throw std::invalid_argument("Illegal edge!");
        }
        
        edges_.push_back(edge);
    };



}