//
// Created by Joschi on 12.05.2018.
//

//==================================
//include guard
#ifndef SRC_SUCCESSION_NODE_H
#define SRC_SUCCESSION_NODE_H

//==================================
// forward class references

//==================================
// included dependencies
#include <vector>
#include "Site.h"

//==================================
/**
 * A wrapper class for the nodes of a succession graph. It holds a set of sites.
 *
 * @Require each sequence can have at most one site in each node.
 */
class SuccessionNode{
private:
    std::vector<Site> sites; // internal representation of the set of sites of this node

    SuccessionNode(const SuccessionNode& rhs);
    SuccessionNode&operator=(const SuccessionNode& rhs);
public:
    SuccessionNode(std::vector<Site>& sites);

    /**
     * Deletes a site from sites, if it is part of the node.
     *
     * @param site the site that is to be removed from the set of sites of this node.
     * @pre the node contains the site at most once
     * @post sites doesn't contain the deleted site anymore
     */
    void deleteSite(const Site& site);

    /**
     * Deletes the site that belong to the given sequence number.
     *
     * @param sequence the sequence which site is to be removed from this node, if there exists one
     * @pre the node contains at most one site from this sequence
     * @post the node contains no sites from the sequence
     */
    void deleteSiteOfSeq(unsigned int sequence);

    /**
     * Returns this node's set of sites.
     */
    std::vector<Site> getSites();
};

#endif //SRC_SUCCESSION_NODE_H
