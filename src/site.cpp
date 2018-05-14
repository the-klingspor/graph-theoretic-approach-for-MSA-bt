//
// Created by Joschi on 12.05.2018.
//

#include "site.h"

Site::Site(unsigned int seq, unsigned int pos)
        :sequence(seq),
         position(pos)
        {}

unsigned int Site::getSequence(){
    return sequence;
}
unsigned int Site::getPosition(){
    return position;
}

bool Site::operator==(const Site& rhs) const{
    return (this->position == rhs.position) && (this->sequence == rhs.sequence);
}

