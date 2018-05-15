//
// Created by Joschi on 12.05.2018.
//

#include "succession_graph_seq.h"

SuccessionGraphSeq::SuccessionGraphSeq(int seq, Graph& data)
        : sequence(seq),
          data(data)
        {}

std::deque<SuccessionNode> SuccessionGraphSeq::longestPath() const{
    /// compute the topological order and store it in a deque
    /// no need to ensure the graph is a DAG
    std::deque<unsigned int> topologicalOrder;
    boost::topological_sort(this->data, std::front_inserter(topologicalOrder));
    /// start with the first vertex v_start, which has no predecessor or distance to the start

    /// compute for every vertex the predecessor and distance according to the topological order

    /// start with the last vertex v_end, which has to be part of the longest path, and add it to the output variable
    std::deque<SuccessionNode> longestPath;
    /// as long as the current vertex has a predecessor, add it to the output

    /// return the deque containing the vertices on a longest path from v_start to v_end

    return longestPath;
}

/**
 * @TODO: mapping der Knoten des Graphen auf die SuccessionNode-Objekte -- permanent
 * @TODO: mapping der Knoten auf Vorgänger und Distanz zum Startknoten -- während des Algorithmus
 */
