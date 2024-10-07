#include "graph.h"

#include <stdexcept>
#include "edge.h"
#include "vertex.h"

#include <limits>
#include <list>
#include <queue>
#include <unordered_map>
#include <map>

#include <iostream>

namespace ljankai
{
	namespace
	{
		const double INFINITY = std::numeric_limits<double>::infinity();
	}

	void Graph::AddVertex(const Vertex &vertex)
	{
		if (vertices_.find(vertex) != vertices_.end())
		{
			throw std::invalid_argument("Vertex already exists!");
		}
		vertices_.insert(vertex);
	};

	void Graph::AddEdge(Vertex &from, const Vertex &to)
	{
		if (vertices_.find(from) == vertices_.end() || vertices_.find(to) == vertices_.end())
		{
			throw std::invalid_argument("One or both vertices not found!");
		}

		// Edge(from, to);

		Edge edge(from, to); // Create the Edge object
		from.AddEdge(edge); // Add the edge to the 'from' vertex
		std::cout << "Added edge from " << from.Value().GetName() << " to " << to.Value().GetName() << std::endl;
	};

	const std::list<const Vertex *> Graph::ShortestPath(const Vertex &from, const Vertex &to) const
	{
		std::unordered_map<const Vertex *, const Vertex *, Vertex::HashFunction, Vertex::EqualsFunction> prev;
		std::unordered_map<const Vertex *, double, Vertex::HashFunction, Vertex::EqualsFunction> dist;
		std::map<double, std::unordered_set<const Vertex *, Vertex::HashFunction>>
			unprocessed_vertices_by_dist;
		std::unordered_map<const Vertex *, double, Vertex::HashFunction, Vertex::EqualsFunction> unprocessed_vertices;

		for (const Vertex &v : Graph::Vertices())
		{
			prev[&v] = nullptr;
			dist[&v] = from == v ? 0 : INFINITY;
			unprocessed_vertices_by_dist[dist[&v]].insert(&v);
			unprocessed_vertices[&v] = dist[&v];
		}

		while (!unprocessed_vertices_by_dist.empty())
		{
			auto vertices_it = unprocessed_vertices_by_dist.begin();
			auto &vertices_with_shortest_dist = vertices_it->second;

			const Vertex &v = **vertices_with_shortest_dist.begin();
			vertices_with_shortest_dist.erase(vertices_with_shortest_dist.begin());
			unprocessed_vertices.erase(unprocessed_vertices.find(&v));

			if (vertices_with_shortest_dist.empty())
			{
				unprocessed_vertices_by_dist.erase(vertices_it);
			}

			for (auto &e : v.Edges())
			{
				auto *neighbor = &e.To();
				if (unprocessed_vertices.find(neighbor) == unprocessed_vertices.end())
				{
					continue;
				}

				double distance = dist[&v] + e.Weight();

				if (distance < dist[neighbor])
				{
					dist[neighbor] = distance;
					prev[neighbor] = &v;

					auto vertices_with_similar_distance_it =
						unprocessed_vertices_by_dist.find(unprocessed_vertices[neighbor]);
					auto &vertices = vertices_with_similar_distance_it->second;
					auto it = vertices.find(neighbor);

					vertices.erase(it);

					if (vertices.empty())
					{
						unprocessed_vertices_by_dist.erase(vertices_with_similar_distance_it);
					}

					unprocessed_vertices_by_dist[distance].insert(neighbor);
					unprocessed_vertices[neighbor] = distance;
				}
			}
		}

		std::list<const Vertex *> result;

		
		auto it = prev.find(&to);
		if (it == prev.end())
		{
			std::cout << "falid";
			return {};
		}
		while (it != prev.end() && it->second != nullptr)
		{
			result.push_front(it->first);
			it = prev.find(it->second);
		}
		result.push_front(&from);

		if (result.front() != &from)
		{
			return {};
		}

		if (!result.empty()) {
			std::cout << "Shortest path from " << from.Value().GetName() << " to " << to.Value().GetName() << ": ";
			for (const auto &vertex : result) {
				std::cout << vertex->Value().GetName() << " ";
			}
			std::cout << std::endl;
		} else {
			std::cout << "No path found." << std::endl;
		}

		for (const auto &pair : prev) {
			std::cout << "Vertex: " << pair.first->Value().GetName() 
					<< ", Previous: " << (pair.second ? pair.second->Value().GetName() : "nullptr") << std::endl;
		}


		return result;


		// 	for (auto it = prev.find(&to); it->second != &from; it = prev.find(it->second))  ha az it->second nem található akkor end() itherátort ad vissza
		// {
		// 	result.push_front(it->first);
		// }
		// result.push_front(&from);
		// return result;
	}
}
