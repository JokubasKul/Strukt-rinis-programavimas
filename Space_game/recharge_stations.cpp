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

using namespace std;


void recharge_station_1() {

    if (input=="e") {

        if (rechargeStation1Used==true) {

            text1="This recharge station is depleted";
            this_thread::sleep_for(chrono::milliseconds(700));
        }

        if (rechargeStation1Used==false) {

            if(health==maxHealth && shields==maxShields) {
                cout<<"Your health and shields are already full"<<endl;
                this_thread::sleep_for(chrono::milliseconds(700));
            } else {
                health=health+50;

                if (health>maxHealth) {
                    health-=health-maxHealth;
                }

                shields=shields+50;

                if (shields>maxShields) {
                    shields-=shields-maxShields;
                }

                cout<<"Healing...."<<endl;;
                this_thread::sleep_for(chrono::milliseconds(600));

                cout<<"Charging shields ...."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));

                cout<<"Health and shields restored"<<endl;
                this_thread::sleep_for(chrono::milliseconds(700));

                input=" ";

                rechargeStation1Used=true;
            }
        }
    }
}//recharge_station_1


void recharge_station_2() {

    if (input=="e") {

        if (rechargeStation2Used==true) {

            text1="This recharge station is depleted";
            this_thread::sleep_for(chrono::milliseconds(700));
        }

        if (rechargeStation2Used==false) {

            if(health==maxHealth && shields==maxShields) {
                cout<<"Your health and shields are already full"<<endl;
                this_thread::sleep_for(chrono::milliseconds(700));
            } else {
                health=health+50;

                if (health>maxHealth) {
                    health-=health-maxHealth;
                }

                shields=shields+50;

                if (shields>maxShields) {
                    shields-=shields-maxShields;
                }

                cout<<"Healing...."<<endl;;
                this_thread::sleep_for(chrono::milliseconds(600));

                cout<<"Charging shields ...."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));

                cout<<"Health and shields restored"<<endl;
                this_thread::sleep_for(chrono::milliseconds(700));

                input=" ";

                rechargeStation2Used=true;
            }
        }
    }
}//recharge_station_2
