#include <iostream>
#include <vector>
#include <deque>

#include "succession_node.h"
#include "succession_graph_seq.h"
#include "site.h"
#include "boost/graph/adjacency_list.hpp"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;

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

        Graph graphData(7);

        // Add edges between vertices.
        boost::add_edge(0, 3, graphData);
        boost::add_edge(1, 3, graphData);
        boost::add_edge(1, 4, graphData);
        boost::add_edge(2, 1, graphData);
        boost::add_edge(3, 5, graphData);
        boost::add_edge(4, 6, graphData);
        boost::add_edge(5, 6, graphData);

        SuccessionGraphSeq graphSeqOne(1, graphData);
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