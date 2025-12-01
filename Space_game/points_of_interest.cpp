//
// Created by User on 2025-09-11.
//
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#include "global_variables.h"
#include "enemies_data.h"
#include "loading_map.h"
#include "movement.h"
#include "computer.h"
#include "name_opening_endings_stats_level_up.h"
#include "recharge_stations.h"
#include "points_of_interest.h"

using namespace std;


void POS_1() {

    if(input=="e") {
        text1=" There is a sign on the wall.";
        text2="it says: ";
        text3="Welcome to the SE Light Control";
        text4="Hope you enjoy your stay";
    }
}


void POS_2() {

    if(input=="e") {
        text1=" There is a sign on the wall.";
        text2="it says: ";
        text3="   Sam Johnston";
        text4=" Head of security ";
    }
}


void POS_3() {

    if(input=="e") {
        text1=" There is a sign on the wall.";
        text2="it says: ";
        text3="   Jenny Smith";
        text4=" Head of engineering ";
    }
}


void POS_4() {

    if(input=="e") {
        text1=" There is a large poster on the wall.";
        text2="it says: ";
        text3="  Welcome to the medbay";
    }
}


void POS_5() {

    if(input=="e") {
        text1=" In a large glass tank";
        text2="there is some yellow foliage";
    }
}


void POS_6() {

    if(input=="e") {
        text1=" A broken glass tank.";
        text2="next to it is a pool of blood.";
        text3="There is no body.";
    }
}


void POS_7() {

    if(input=="e") {
        text1=" There is a sign on the wall.";
        text2="it says: ";
        text3="     Reactor access  ";
    }
}
