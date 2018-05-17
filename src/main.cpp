#include <iostream>
#include <deque>
#include <unordered_map>

#include "boost/graph/adjacency_list.hpp"

#include "succession_graph_seq.h"

class Site;
class SuccessionNode;


/**
 * Helper method for illustrative purposes.
 * @param node
 */
void printNode(SuccessionNode& node){
    std::unordered_map<unsigned int, Site> sitesReturned = node.getSites();
    std::cout << "[";
    for (auto it : sitesReturned){
        std::cout << "Sequence: " << it.second.getSequence() << " ";
        std::cout << "Position: " << it.second.getPosition() << "; ";
    }
    std::cout << "]" << std::endl;
}

/**
 * Main method that constructs the graph of sequence 1 of the example we've seen in my bachelor thesis and computes its
 * longest path.
 */
int main() {
    Graph graphData;

    // Add start and end vertices
    Graph::vertex_descriptor vStart = boost::add_vertex(graphData);
    Graph::vertex_descriptor vEnd   = boost::add_vertex(graphData);
    Graph::vertex_descriptor v0     = boost::add_vertex(graphData);
    Graph::vertex_descriptor v1     = boost::add_vertex(graphData);
    Graph::vertex_descriptor v2     = boost::add_vertex(graphData);
    Graph::vertex_descriptor v3     = boost::add_vertex(graphData);
    Graph::vertex_descriptor v4     = boost::add_vertex(graphData);
    Graph::vertex_descriptor v5     = boost::add_vertex(graphData);
    Graph::vertex_descriptor v6     = boost::add_vertex(graphData);

    // Set SuccessionNodes of vertices:
    // 0. pink node
    Site s1_2(1,2);
    Site s4_1(4,1);

    std::unordered_map<unsigned int, Site> siteSet0;
    siteSet0.insert({s1_2.getSequence(), s1_2});
    siteSet0.insert({s4_1.getSequence(), s4_1});

    graphData[v0].vertex = SuccessionNode(siteSet0);

    // 1. yellow node
    Site s1_3(1,3);
    Site s2_1(2,1);
    Site s4_2(4,2);

    std::unordered_map<unsigned int, Site> siteSet1;
    siteSet1.insert({s1_3.getSequence(), s1_3});
    siteSet1.insert({s2_1.getSequence(), s2_1});
    siteSet1.insert({s4_2.getSequence(), s4_2});

    graphData[v1].vertex = SuccessionNode(siteSet1);

    // 2. first blue node
    Site s1_4(1,4);
    Site s2_2(2,2);
    Site s3_3(3,3);
    Site s4_3(4,3);

    std::unordered_map<unsigned int, Site> siteSet2;
    siteSet2.insert({s1_4.getSequence(), s1_4});
    siteSet2.insert({s2_2.getSequence(), s2_2});
    siteSet2.insert({s3_3.getSequence(), s3_3});
    siteSet2.insert({s4_3.getSequence(), s4_3});

    graphData[v2].vertex = SuccessionNode(siteSet2);

    // 3. first green node
    Site s1_5(1,5);
    Site s2_3(2,3);
    Site s3_4(3,4);
    Site s4_4(4,4);

    std::unordered_map<unsigned int, Site> siteSet3;
    siteSet3.insert({s1_5.getSequence(), s1_5});
    siteSet3.insert({s2_3.getSequence(), s2_3});
    siteSet3.insert({s3_4.getSequence(), s3_4});
    siteSet3.insert({s4_4.getSequence(), s4_4});

    graphData[v3].vertex = SuccessionNode(siteSet3);

    // 4. red node
    Site s1_8(1,8);
    Site s2_4(2,4);
    Site s3_5(3,5);
    Site s4_5(4,5);

    std::unordered_map<unsigned int, Site> siteSet4;
    siteSet4.insert({s1_8.getSequence(), s1_8});
    siteSet4.insert({s2_4.getSequence(), s2_4});
    siteSet4.insert({s3_5.getSequence(), s3_5});
    siteSet4.insert({s4_5.getSequence(), s4_5});

    graphData[v4].vertex = SuccessionNode(siteSet4);

    // 5. second blue node
    Site s1_6(1,6);
    Site s2_7(2,7);
    Site s4_8(4,8);

    std::unordered_map<unsigned int, Site> siteSet5;
    siteSet5.insert({s1_6.getSequence(), s1_6});
    siteSet5.insert({s2_7.getSequence(), s2_7});
    siteSet5.insert({s4_8.getSequence(), s4_8});

    graphData[v5].vertex = SuccessionNode(siteSet5);

    // 6. second green node
    Site s1_7(1,7);
    Site s2_8(2,8);
    Site s4_9(4,9);

    std::unordered_map<unsigned int, Site> siteSet6;
    siteSet6.insert({s1_7.getSequence(), s1_7});
    siteSet6.insert({s2_8.getSequence(), s2_8});
    siteSet6.insert({s4_9.getSequence(), s4_9});

    graphData[v6].vertex = SuccessionNode(siteSet6);

    // Add edges:
    // Edges from v_start:
    boost::add_edge(vStart, v0, graphData);
    boost::add_edge(vStart, v1, graphData);
    boost::add_edge(vStart, v2, graphData);
    boost::add_edge(vStart, v3, graphData);
    boost::add_edge(vStart, v4, graphData);
    boost::add_edge(vStart, v5, graphData);
    boost::add_edge(vStart, v6, graphData);
    boost::add_edge(vStart, vEnd, graphData);

    // Edges from v0 (pink):
    boost::add_edge(v0, v1, graphData);
    boost::add_edge(v0, v2, graphData);
    boost::add_edge(v0, v3, graphData);
    boost::add_edge(v0, v4, graphData);
    boost::add_edge(v0, v5, graphData);
    boost::add_edge(v0, v6, graphData);
    boost::add_edge(v0, vEnd, graphData);

     // Edges from v1(yellow):
    boost::add_edge(v1, v2, graphData);
    boost::add_edge(v1, v3, graphData);
    boost::add_edge(v1, v4, graphData);
    boost::add_edge(v1, v5, graphData);
    boost::add_edge(v1, v6, graphData);
    boost::add_edge(v1, vEnd, graphData);

    // Edges from v2(blue):
    boost::add_edge(v2, v3, graphData);
    boost::add_edge(v2, v4, graphData);
    boost::add_edge(v2, v5, graphData);
    boost::add_edge(v2, v6, graphData);
    boost::add_edge(v2, vEnd, graphData);

     // Edges from v3 (green):
    boost::add_edge(v3, v4, graphData);
    boost::add_edge(v3, v5, graphData);
    boost::add_edge(v3, v6, graphData);
    boost::add_edge(v3, vEnd, graphData);

    // Edges from v4 (red):
    boost::add_edge(v4, vEnd, graphData);

    // Edges from v5 (blue):
    boost::add_edge(v5, v6, graphData);
    boost::add_edge(v5, vEnd, graphData);

    // Edges from v6 (green):
    boost::add_edge(v6, vEnd, graphData);

    // Initialize graph
    SuccessionGraphSeq succGraph(1, graphData, vStart, vEnd);

    // compute longest path
    std::deque<SuccessionNode> longestPath = succGraph.longestPath();

    for (SuccessionNode s : longestPath){
        printNode(s);
    }
}