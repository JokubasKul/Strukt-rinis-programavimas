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

using namespace std;

void movement() {

    if(input=="w") {
        area[x][y].text="_";
        y++;
        area[x][y].text="P";
        if(area[x][y].status==11) {
            area[x][y].text="?";
            y--;
            area[x][y].text="P";
            text1="This is a point of interest";
            return;
        }
        if(area[x][y].status==9) {
            area[x][y].text="L";
            y--;
            area[x][y].text="P";
            text1="This is a loot package";
            return;
        }
        if(area[x][y].status==8) {
            area[x][y].text="R";
            y--;
            area[x][y].text="P";
            text1="This is a recharge station";
            return;
        }
        if(area[x][y].status==7) {
            area[x][y].text="S";
            y--;
            area[x][y].text="P";
            text1="This is the store";
            return;
        }
        if(area[x][y].status==6) {
            area[x][y].text="T";
            y--;
            area[x][y].text="P";
            text1="This is a door";
            return;
        }
        if(area[x][y].status==5) {
            area[x][y].text="@";
            y--;
            area[x][y].text="P";
            text1="This is a computer";
            return;
        }
        if(area[x][y].status==4) {
            area[x][y].text="D";
            y--;
            area[x][y].text="P";
            text1="This is a desk";
            return;
        }
        if(area[x][y].status==3) {
            area[x][y].text="+";
            y--;
            area[x][y].text="P";
            text1="This is a wall";
            return;
        }
        if(area[x][y].status==2) {
            area[x][y].text="C";
            y--;
            area[x][y].text="P";
            text1="This is a background object";
            return;
        }
        if(area[x][y].status==1) {
            text1=" ";
            text2=" ";
            text3=" ";
            text4=" ";
            text5=" ";
            text6=" ";
        }
    }
    if(input=="d") {
        area[x][y].text="_";
        x++;
        area[x][y].text="P";
        if(area[x][y].status==11) {
            area[x][y].text="?";
            x--;
            area[x][y].text="P";
            text1="This is a point of interest";
            return;
        }
        if(area[x][y].status==9) {
            area[x][y].text="L";
            x--;
            area[x][y].text="P";
            text1="This is a loot package";
            return;
        }
        if(area[x][y].status==8) {
            area[x][y].text="R";
            x--;
            area[x][y].text="P";
            text1="This is a recharge station";
            return;
        }
        if(area[x][y].status==7) {
            area[x][y].text="S";
            x--;
            area[x][y].text="P";
            text1="This is the store";
            return;
        }
        if(area[x][y].status==6) {
            area[x][y].text="T";
            x--;
            area[x][y].text="P";
            text1="This is a door";
            return;
        }
        if(area[x][y].status==5) {
            area[x][y].text="@";
            x--;
            area[x][y].text="P";
            text1="This is a computer";
            return;
        }
        if(area[x][y].status==4) {
            area[x][y].text="D";
            x--;
            area[x][y].text="P";
            text1="This is a desk";
            return;
        }
        if(area[x][y].status==3) {
            area[x][y].text="+";
            x--;
            area[x][y].text="P";
            text1="This is a wall";
            return;
        }
        if(area[x][y].status==2) {
            area[x][y].text="C";
            x--;
            area[x][y].text="P";
            text1="This is a background object";
            return;
        }
        if(area[x][y].status==1) {
            text1=" ";
            text2=" ";
            text3=" ";
            text4=" ";
            text5=" ";
            text6=" ";
        }
    }
    if(input=="a") {
        area[x][y].text="_";
        x--;
        area[x][y].text="P";
        if(area[x][y].status==12) {
            area[x][y].text="3";
            x++;
            area[x][y].text="P";
            text1="Beyond the railing you can see the ship's reactor";
            return;
        }
        if(area[x][y].status==11) {
            area[x][y].text="?";
            x++;
            area[x][y].text="P";
            text1="This is a point of interest";
            return;
        }
        if(area[x][y].status==9) {
            area[x][y].text="L";
            x++;
            area[x][y].text="P";
            text1="This is a loot package";
            return;
        }
        if(area[x][y].status==8) {
            area[x][y].text="R";
            x++;
            area[x][y].text="P";
            text1="This is a recharge station";
            return;
        }
        if(area[x][y].status==7) {
            area[x][y].text="S";
            x++;
            area[x][y].text="P";
            text1="This is the store";
            return;
        }
        if(area[x][y].status==6) {
            area[x][y].text="T";
            x++;
            area[x][y].text="P";
            text1="This is a door";
            return;
        }
        if(area[x][y].status==5) {
            area[x][y].text="@";
            x++;
            area[x][y].text="P";
            text1="This is a computer";
            return;
        }
        if(area[x][y].status==4) {
            area[x][y].text="D";
            x++;
            area[x][y].text="P";
            text1="This is a desk";
            return;
        }
        if(area[x][y].status==3) {
            area[x][y].text="+";
            x++;
            area[x][y].text="P";
            text1="This is a wall";
            return;
        }
        if(area[x][y].status==2) {
            area[x][y].text="C";
            x++;
            area[x][y].text="P";
            text1="This is a background object";
            return;
        }
        if(area[x][y].status==1) {
            text1=" ";
            text2=" ";
            text3=" ";
            text4=" ";
            text5=" ";
            text6=" ";
        }
    }
    if(input=="s") {
        area[x][y].text="_";
        y--;
        area[x][y].text="P";
        if(area[x][y].status==11) {
            area[x][y].text="?";
            y++;
            area[x][y].text="P";
            text1="This is a point of interest";
            return;
        }
        if(area[x][y].status==9) {
            area[x][y].text="L";
            y++;
            area[x][y].text="P";
            text1="This is a loot package";
            return;
        }
        if(area[x][y].status==8) {
            area[x][y].text="R";
            y++;
            area[x][y].text="P";
            text1="This is a recharge station";
            return;
        }
        if(area[x][y].status==7) {
            area[x][y].text="S";
            y++;
            area[x][y].text="P";
            text1="This is the store";
            return;
        }
        if(area[x][y].status==6) {
            area[x][y].text="T";
            y++;
            area[x][y].text="P";
            text1="This is a door";
            return;
        }
        if(area[x][y].status==5) {
            area[x][y].text="@";
            y++;
            area[x][y].text="P";
            text1="This is a computer";
            return;
        }
        if(area[x][y].status==4) {
            area[x][y].text="D";
            y++;
            area[x][y].text="P";
            text1="This is a desk";
            return;
        }
        if(area[x][y].status==3) {
            area[x][y].text="+";
            y++;
            area[x][y].text="P";
            text1="This is a wall";
            return;
        }
        if(area[x][y].status==2) {
            area[x][y].text="C";
            y++;
            area[x][y].text="P";
            text1="This is a background object";
            return;
        }
        if(area[x][y].status==1) {
            text1=" ";
            text2=" ";
            text3=" ";
            text4=" ";
            text5=" ";
            text6=" ";
        }
    }
}// movement