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
#include <unordered_map>
#include "Site.h"

//==================================
/**
 * @brief A wrapper class for the nodes of a succession graph. It holds a set of sites.
 *
 * @Require each sequence can have at most one site in each node.
 *
 * @author Joschka Strueber
 * @version 1.0
 */
class SuccessionNode{
private:
    std::unordered_map<unsigned int, Site> sites; /// internal representation of the set of sites of this node

public:
    SuccessionNode(std::unordered_map<unsigned int, Site>& sites);

    /**
     * @brief compares this SuccessionNode with a second one for equality
     *
     * @param rhs the SuccessionNode to compare this to.
     * @return Whether or nor they have the same set of sites.
     */
    bool operator==(const SuccessionNode& rhs) const;

    /**
     * @brief Deletes a site from sites, if it is part of the node.
     *
     * @param site the site that is to be removed from the set of sites of this node.
     * @pre the node contains the site at most once
     * @post sites doesn't contain the deleted site anymore
     */
    void deleteSite(const Site& site);

    /**
     * @brief Deletes the site that belong to the given sequence number.
     *
     * @param sequence the sequence which site is to be removed from this node, if there exists one
     * @pre the node contains at most one site from this sequence
     * @post the node contains no sites from the sequence
     */
    void deleteSiteOfSeq(unsigned int sequence);

    /**
     * @brief Returns this node's set of sites.
     */
    std::unordered_map<unsigned int, Site> getSites() const;
};

#endif //SRC_SUCCESSION_NODE_H
