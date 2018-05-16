#include <iostream>
#include <deque>
#include <unordered_map>

#include "succession_node.h"
#include "succession_graph_seq.h"
#include "site.h"
#include "boost/graph/adjacency_list.hpp"

class LongestPathRunner{
public:
    void run(){
        auto sites = std::unordered_map<unsigned int, Site>();
        for (unsigned int seq = 0; seq < 4; seq++) {
            sites.insert({seq, Site(seq, seq + 2)});
        }

        SuccessionNode myNode(sites);
        printNode(myNode);

        Site siteToDelete = Site(1, 3);
        myNode.deleteSite(siteToDelete);

        std::cout << "Site (1,3) was deleted:" << std::endl;
        printNode(myNode);

        Graph graphData;

        // Add vertices to the graph
        Graph::vertex_descriptor vStart = boost::add_vertex(graphData);
        Graph::vertex_descriptor v0 = boost::add_vertex(graphData);
        Graph::vertex_descriptor v1 = boost::add_vertex(graphData);
        Graph::vertex_descriptor vEnd = boost::add_vertex(graphData);

        Site s1_1(1,2);
        Site s2_2(2,2);
        Site s3_1(3,1);
        Site s4_1(4,1);

        std::unordered_map<unsigned int, Site> sites1;
        sites1.insert({s1_1.getSequence(), s1_1});
        sites1.insert({s2_2.getSequence(), s2_2});
        sites1.insert({s3_1.getSequence(), s3_1});
        sites1.insert({s4_1.getSequence(), s4_1});

        graphData[v0].vertex = SuccessionNode(sites1);

        Site s1_2(1,2);
        Site s2_3(2,3);
        std::unordered_map<unsigned int, Site> sites2;

        graphData[v1].vertex = SuccessionNode(sites2);

        auto emptySites = std::unordered_map<unsigned int, Site>();
        graphData[vStart].vertex = SuccessionNode(emptySites);
        graphData[vEnd].vertex = SuccessionNode(emptySites);

        // Add edges between vertices.
        boost::add_edge(vStart, v0, graphData);
        boost::add_edge(vStart, v1, graphData);
        boost::add_edge(v0, v1, graphData);
        boost::add_edge(v0, vEnd, graphData);
        boost::add_edge(v1, vEnd, graphData);
        SuccessionGraphSeq graphSeqOne(1, graphData, vStart, vEnd);
        std::deque<SuccessionNode> longestPath = graphSeqOne.longestPath();

        for(SuccessionNode s : longestPath){
            std::cout << " @TODO " << std::endl;
        }
        std::cout << std::endl;
        return;
    };

    void printNode(SuccessionNode& node){
        std::unordered_map<unsigned int, Site> sitesReturned = node.getSites();
        for (auto it : sitesReturned){
            std::cout << "Sequence: " << it.second.getSequence() << " ";
            std::cout << "Position: " << it.second.getPosition() << std::endl;
        }
    }
};

int main() {
    LongestPathRunner* runnerPointer = new LongestPathRunner();
    runnerPointer->run();
    delete runnerPointer;
    return 0;
}