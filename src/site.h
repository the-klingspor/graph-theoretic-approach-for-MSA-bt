//
// Created by Joschi on 12.05.2018.
//

//==================================
// include guard
#ifndef SRC_SITE_H
#define SRC_SITE_H

//==================================
// forward class references

//==================================
// included dependencies

//==================================
/*
 * A wrapper class representing the sites of the sitespace of a set of sequences.
 */
class Site{
private:
    unsigned int sequence; // the sequence this site belongs to
    unsigned int position; // the position of this site in its sequence

public:
    Site(unsigned int seq, unsigned int pos);

    /**
     * Simple getters for the two member attributes of site class objects.
     */

    unsigned int getSequence();
    unsigned int getPosition();

    /**
     * Operator to compare two sites for equality. Checks if sequence and position are the same.
     *
     * @param rhs the site this current site is compared to
     */
    bool operator==(const Site& rhs) const;
};

#endif //SRC_SITE_H
