//
// Created by Joschi on 12.05.2018.
//

//==================================
// include guard
#ifndef SRC_SUCCESSION_GRAPH_SEQ_H
#define SRC_SUCCESSION_GRAPH_SEQ_H

//==================================
// forward class references

//==================================
// included dependencies
#include <deque>
#include <iterator>

#include "succession_node.h"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/topological_sort.hpp"

//==================================

/// Define a bidirectional type of graph that allows accessing the in-edges of every node.
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

/**
 * \brief A class representing the succession graph limited to the nodes and edges corresponding to a single sequence.
 *
 * @Require Objects of this class must have start and end nodes v_start and v_end.
 * @Require They have to consist of a single connected component.
 * @Require All nodes have to be on a path from v_start to v_end.
 * @Require All nodes have to contain a site from the corresponding sequence.
 * @Require All edges preserve the natural order of the sequence.
 * @Require Has to be a directed acyclic graph (DAG).
 *
 * These previous requirements have to be ensured by the object, that created the SuccesionGraphSeq object. In a full
 * implementation of the alignment algorithm this would be the succession graph after computing the connected component
 * and becoming a DAG, but prior to deleting nodes to compute consistent alignment columns.
 * The main purpose of this class is to be able to compute longestPaths for each sequence to decide which sites from
 * which nodes can be deleted to construct consistent partial alignment columns in the algorithm of Pitschi.
 *
 * @author Joschka Strueber
 * @version 1.0
 */
class SuccessionGraphSeq{
private:
    int sequence;       /// number of the sequence this graph belongs to
    Graph& data;        /// the actual data of the succession graph restricted on this sequence

    SuccessionGraphSeq(SuccessionGraphSeq& rhs);                    // prevent copy constructor to be called
    SuccessionGraphSeq& operator=(const SuccessionGraphSeq& rhs);   // prevent assignments

public:
    SuccessionGraphSeq(int seq, Graph& data);

    /**
     *  Computes the longest path..
     *
     *  This method computes the longest chain of SuccessionNodes on any path from v_start to v_end. All nodes on this
     *  path including both v_start and v_end are returned as part of a double ended queue (deque). If several longest
     *  paths exist, any of these might be returned.
     *
     * @return a double ended queue that contains the nodes on the longest path
     */
    std::deque<SuccessionNode> longestPath() const;
};

#endif //SRC_SUCCESSION_GRAPH_SEQ_H
