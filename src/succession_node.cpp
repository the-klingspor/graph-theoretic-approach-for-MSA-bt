//
// Created by Joschi on 12.05.2018.
//

#include "succession_node.h"

SuccessionNode::SuccessionNode(std::vector<Site>& sites)
        : sites(sites)
{}

void SuccessionNode::deleteSite(const Site& site){
    unsigned int size = sites.size();
    unsigned int removeIndex = 0;
    // iterate over all sites until the site to delete is found
    for (unsigned int i = 0; i < size; i++){
        if (sites.at(i) == site){
            removeIndex = i;
            break;
        }
    }
    // erase found site from the set of sites
    if (removeIndex < size) {
        sites.erase(sites.begin() + removeIndex);
    }
}

void SuccessionNode::deleteSiteOfSeq(unsigned int sequence){
    unsigned int size = sites.size();
    unsigned int removeIndex = 0;
    // iterate over all sites until the site to delete is found
    for (unsigned int i = 0; i < size; i++){
        if (sites.at(i).getSequence() == sequence){
            removeIndex = i;
            break;
        }
    }
    // erase found site from the set of sites
    if (removeIndex < size) {
        sites.erase(sites.begin() + removeIndex);
    }
}

std::vector<Site> SuccessionNode::getSites(){
    return sites;
}
