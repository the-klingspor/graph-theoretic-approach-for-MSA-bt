//
// Created by Joschi on 15.05.2018.
//
#include <unordered_map>
#include <iostream>

class Site;

#include "catch.hpp"
#include "succession_node.h"

TEST_CASE("Test == operator for equality of succession nodes", "[SuccessionNode==operator"){
    /**
     * The == operator does not have to be further tested, because the SuccessionNode is only a wrapper of
     * std::unordered_map<unsigned int, Site> and its == operator merely calls the == operator of the hidden type, which
     * has been previously tested.
     */
}

TEST_CASE("Test deleting sites per sequence from succession nodes", "[SNodeDeleteSeq]"){
    std::unordered_map<unsigned int, Site> emptySiteSet1;
    std::unordered_map<unsigned int, Site> emptySiteSet2;

    Site s1_1(1,2);
    Site s2_2(2,2);
    Site s3_1(3,1);
    Site s4_1(4,1);

    SuccessionNode emptyNode(emptySiteSet1);

    emptyNode.deleteSiteOfSeq(1);
    // trying to delete sites from empty nodes doesn't change the node's status
    REQUIRE(emptyNode.getSites() == emptySiteSet1);

    std::unordered_map<unsigned int, Site> smallSiteSet1;
    smallSiteSet1.insert({s1_1.getSequence(),s1_1});
    std::unordered_map<unsigned int, Site> smallSiteSet2;
    smallSiteSet2.insert({s1_1.getSequence(),s1_1});
    SuccessionNode smallNode(smallSiteSet1);

    smallNode.deleteSiteOfSeq(2);
    // deleting site from different sequence doesn't change status
    REQUIRE(smallNode.getSites() == smallSiteSet2);

    smallNode.deleteSiteOfSeq(1);
    // after deletion the Node has to be empty
    REQUIRE(smallNode == emptyNode);

    std::unordered_map<unsigned int, Site> sites1;
    sites1.insert({s1_1.getSequence(), s1_1});
    sites1.insert({s2_2.getSequence(), s2_2});
    sites1.insert({s3_1.getSequence(), s3_1});
    sites1.insert({s4_1.getSequence(), s4_1});

    std::unordered_map<unsigned int, Site> sites2;
    sites2.insert({s1_1.getSequence(), s1_1});
    sites2.insert({s2_2.getSequence(), s2_2});
    sites2.insert({s3_1.getSequence(), s3_1});
    sites2.insert({s4_1.getSequence(), s4_1});

    SuccessionNode node1(sites1);
    SuccessionNode node2(sites2);
    // two nodes with the same sites must be equal
    REQUIRE(node1 == node2);

    node1.deleteSiteOfSeq(4);
    std::unordered_map<unsigned int, Site> sites3 = node1.getSites();
    // number of sites must decrease by one
    REQUIRE(node1.getSites().size() == 3);

    // nodes must not be the same anymore
    REQUIRE_FALSE(node1 == node2);

    node2.deleteSiteOfSeq(4);
    // if we remove the sites from the same sequence, the nodes must stay the same
    REQUIRE(node1 == node2);

    node1.deleteSiteOfSeq(2);
    node2.deleteSiteOfSeq(3);
    // if we remove sites from different sequences, the nodes must differ
    REQUIRE_FALSE(node1 == node2);
}

TEST_CASE("Test deleting sites from succession nodes", "[SNodeDelete]"){
    std::unordered_map<unsigned int, Site> emptySiteSet1;
    std::unordered_map<unsigned int, Site> emptySiteSet2;

    Site s1_1(1,1);
    Site s1_2(1,2);
    Site s2_2(2,2);
    Site s2_1(2,1);

    SuccessionNode emptyNode(emptySiteSet1);

    emptyNode.deleteSite(s1_1);
    // trying to delete sites from empty nodes doesn't change the node's status
    REQUIRE(emptyNode.getSites() == emptySiteSet1);

    std::unordered_map<unsigned int, Site> smallSiteSet1;
    smallSiteSet1.insert({s1_1.getSequence(),s1_1});
    std::unordered_map<unsigned int, Site> smallSiteSet2;
    smallSiteSet2.insert({s1_1.getSequence(),s1_1});
    SuccessionNode smallNode(smallSiteSet1);

    smallNode.deleteSite(s1_2);
    smallNode.deleteSite(s2_1);
    smallNode.deleteSite(s2_2);
    // deleting a site that's not part of the node doesn't change its status
    REQUIRE(smallNode.getSites() == smallSiteSet2);

    smallNode.deleteSite(s1_1);
    // after deletion the Node has to be empty
    REQUIRE(smallNode == emptyNode);

    Site s2_3(2,3);
    Site s3_4(3,4);
    Site s4_5(4,5);

    std::unordered_map<unsigned int, Site> sites1;
    sites1.insert({s1_1.getSequence(), s1_1});
    sites1.insert({s2_3.getSequence(), s2_3});
    sites1.insert({s3_4.getSequence(), s3_4});
    sites1.insert({s4_5.getSequence(), s4_5});

    std::unordered_map<unsigned int, Site> sites2;
    sites2.insert({s1_1.getSequence(), s1_1});
    sites2.insert({s2_3.getSequence(), s2_3});
    sites2.insert({s3_4.getSequence(), s3_4});
    sites2.insert({s4_5.getSequence(), s4_5});

    SuccessionNode node1(sites1);
    SuccessionNode node2(sites2);

    node1.deleteSite(s1_2);
    node1.deleteSite(s2_1);
    node1.deleteSite(s2_2);
    // deleting a site that's not part of the node doesn't change its status
    REQUIRE(node1 == node2);

    node1.deleteSite(s1_1);
    std::unordered_map<unsigned int, Site> sites3 = node1.getSites();
    // number of sites must decrease by one
    REQUIRE(node1.getSites().size() == 3);

    // nodes must not be the same anymore
    REQUIRE_FALSE(node1 == node2);

    node2.deleteSite(s1_1);
    // if we remove the same sites from two nodes, they must be the same
    REQUIRE(node1 == node2);

    node1.deleteSite(s2_2);
    node2.deleteSite(s3_4);
    // if we remove sites from different sequences, the nodes must differ
    REQUIRE_FALSE(node1 == node2);
}