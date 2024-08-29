#include "graph.h"

#include <stdexcept>
#include "edge.h"
#include "vertex.h"


namespace ljankai
{
	void Graph::AddVertex(const Vertex &vertex)
	{
		if (vertices_.find(vertex) != vertices_.end())
		{
			throw std::invalid_argument("Vertex already exists!");
		}
		Graph::vertices_.insert(vertex);
	};

	void Graph::AddEdge(Vertex &from, const Vertex &to)
	{        struct HashFunction
        {
            size_t operator()(const Vertex &vertex) const
            {
                return 7 * (17 + Waypoint::HashFunction()(vertex.value_));
            }
        };
		if (vertices_.find(from) == vertices_.end() || vertices_.find(to) == vertices_.end())
		{
			throw std::invalid_argument("One or both vertices not found!");
		}

		Edge( from, to);
	};
}
