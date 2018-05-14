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
        auto sites = std::vector<Site>();
        for (unsigned int seq = 0; seq < 4; seq++) {
            Site mySite = Site(seq, seq + 2);
            sites.push_back(mySite);
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
        std::deque<unsigned int> longestPath = graphSeqOne.longestPath();
        for(unsigned int i: longestPath){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        return;
    };
    void printNode(SuccessionNode& node){
        std::vector<Site> sitesReturned = node.getSites();
        for (Site s : sitesReturned){
            std::cout << "Sequence: " << s.getSequence() << " ";
            std::cout << "Position: " << s.getPosition() << std::endl;
        }
    }
};

int main() {
    LongestPathRunner* runnerPointer = new LongestPathRunner();
    runnerPointer->run();
    delete runnerPointer;
    return 0;
}