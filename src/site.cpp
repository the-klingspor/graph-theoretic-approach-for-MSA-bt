//
// Created by Joschi on 12.05.2018.
//

#include "site.h"

Site::Site(unsigned int seq, unsigned int pos)
        :sequence(seq),
         position(pos)
        {}

unsigned int Site::getSequence() const{
    return sequence;
}
unsigned int Site::getPosition() const{
    return position;
}

bool Site::operator==(const Site& rhs) const{
    return (sequence == rhs.getSequence()) && (position == rhs.getPosition());
}

bool Site::operator<=(const Site& rhs) const{
    return (sequence == rhs.getSequence()) && (position <= rhs.getPosition());
}

