//
// Created by Joschi on 12.05.2018.
//

#include "succession_graph_seq.h"
#include <iostream>

SuccessionGraphSeq::SuccessionGraphSeq(unsigned int seq, Graph& data, vertex_t startVertex, vertex_t endVertex)
        : sequence(seq),
          data(data),
          vStart(startVertex),
          vEnd(endVertex)
        {}

vertex_t SuccessionGraphSeq::getStartVertex() const{
    return vStart;
}

vertex_t SuccessionGraphSeq::getEndVertex() const{
    return vEnd;
}

std::deque<SuccessionNode> SuccessionGraphSeq::longestPath() const{
    /// compute the topological order and store it in a deque
    /// no need to check if the graph is a DAG, this had to be ensured by the object that build this object
    std::deque<vertex_t> topologicalOrder;
    boost::topological_sort(data, std::front_inserter(topologicalOrder));

    /// declare and initialize the maps for storing the distances and predecessors
    std::unordered_map<vertex_t, vertex_t> predecessors;
    std::unordered_map<vertex_t, unsigned int> distances;

    for(const auto& vertex : topologicalOrder){
        predecessors.emplace(vertex, 0);
        distances.emplace(vertex, 0);
    }

    /// compute for every vertex the predecessor and distance according to the topological order
    typedef boost::graph_traits <Graph>::adjacency_iterator adjacency_iterator;

    for(const auto& vertex : topologicalOrder){
        unsigned int currentDistance = distances.at(vertex);
        /// retrieve edges of current vertex
        std::pair<adjacency_iterator, adjacency_iterator> neighbors = boost::adjacent_vertices(vertex, data);

        while(neighbors.first != neighbors.second){
            vertex_t currentNeighbor = *neighbors.first;
            if (currentDistance + 1 > distances.at(currentNeighbor)){ /// longer path to neighbor found -> edit entries
                distances.erase(currentNeighbor);
                distances.emplace(currentNeighbor, currentDistance + 1);
                predecessors.erase(currentNeighbor);
                predecessors.emplace(currentNeighbor, vertex);
            }
            neighbors.first++;
        }
    }

    /// start with the last vertex v_end, which has to be part of the longest path, and add it to the output variable
    std::deque<SuccessionNode> longestPath;
    vertex_t longestPathVertex = vEnd;

    /// as long as the current vertex is valid, add its SuccessionNode to the output and set the current vertex to its
    /// predecessor
    while (longestPathVertex != vStart){
        longestPath.emplace_front(data[longestPathVertex].vertex);
        longestPathVertex = predecessors.at(longestPathVertex);
    }
    longestPath.emplace_front(data[vStart].vertex);

    /// return the deque containing the vertices on a longest path from v_start to v_end
    return longestPath;
}
