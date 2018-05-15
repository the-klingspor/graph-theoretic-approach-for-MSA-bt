//
// Created by Joschi on 15.05.2018.
//
#include "catch.hpp"
#include "site.h"

TEST_CASE("Test == operator for equality of sites", "[Site==operator]"){
    Site s1(1,2);
    Site s2(1,2);
    Site s3(1,1);
    Site s4(2,1);

    // Sites with equal seq and pos are equal
    REQUIRE(s1 == s2);

    // Reflexivity test
    REQUIRE(s1 == s1);

    // Sites with same seq but different pos are not equal
    REQUIRE_FALSE(s1 == s3);

    // Sites with same pos but different seq are not equal
    REQUIRE_FALSE(s3 == s4);

    // Sites with different pos and seq are not equal
    REQUIRE_FALSE(s1 == s4);
}

TEST_CASE("Test <= operator for natural order of sites", "[Site<=operator]"){
    Site s1(2,2);
    Site s2(2,2);
    Site s3(2,3);
    Site s4(3,2);
    Site s5(3,3);
    Site s6(3,1);

    // <= true for sites with equal seq and pos
    REQUIRE(s1 <= s2);

    // Reflexivity test
    REQUIRE(s1 <= s1);

    // <= true for sites with equal seq and smaller pos
    REQUIRE(s1 <= s3);

    // <= false for sites with larger seq and smaller pos
    REQUIRE_FALSE(s6 == s1);

    // <= false for sites with larger seq and equal pos
    REQUIRE_FALSE(s4 == s1);

    // <= false for sites with larger seq and pos
    REQUIRE_FALSE(s5 == s1);

    // <= false for sites with smaller seq and pos
    REQUIRE_FALSE(s1 == s5);

    // <= false for sites with smaller seq and equal pos
    REQUIRE_FALSE(s1 == s4);

    // <= false for sites with smaller seq and larger pos
    REQUIRE_FALSE(s1 == s6);
}
