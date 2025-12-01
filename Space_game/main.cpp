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
#include "door.h"
#include "combat_encounters.h"
#include "store_inventory_map.h"
#include "loot_package.h"

using namespace std;

int main() {

    enemies_data();

    name();

    opening();

    location=0;
    loading_map_0();

    text1="P is you";
    text2="Type w,a,s,d + ENTER to walk";

    while(input!="end") {

        if (location==0) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;


            movement();

            inventory();


            if (x==6 && y==11) { //computer
                text1="Press 'e' to interact with computer";
                computer1();
            }
            if (x==6 && y==13) { //computer
                text1="Press 'e' to interact with computer";
                computer1();
            }
            if(x==4 && y==6) { //POS
                text1="Press 'e' to interact";
                POS_1();
            }
            if (door1Open==false) {  //door1
                if (x==9 && y==15) {
                    text1="Press 'e' to interact with door panel";
                    text2="You need to know the passcode to unlock the door ( T )";
                    text3="It can be found on the computer ( @ )";
                    door1();
                }
            } else if (door1Open==true) {  //door
                if (x==9 && y==15) {
                    text1="Press 'e' to go to next room";
                    door1();
                }
            }
        }
        if (location==1) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;

            movement();
            inventory();

            if (lootPackage1Used==false) {
                if(x==4 && y==7 || x==4 && y==9 || x==5 && y==8) {
                    text1="Press 'e' to open loot package";
                    loot_package_1();
                }
            }
            if (lootPackage2Used==false) {
                if (x==8 && y==10 || x==7 && y==11 || x==8 && y==12) {
                    text1="Press 'e' to open loot package";
                    loot_package_2();
                }
            }
            if (x==6 && y==6) {
                text1="( L ) is loot packages";
            }
            if (x==6 && y==4) {
                text1="Press 'e' to open to go to room";
                door1();
            }
            if (x==6 && y==15) {
                text1="Press 'e' to open to go to next room";
                door2();
            }
            if(x==4 && y==12 || x==5 && y==12 || x==6 && y==12 || x==7 && y==12 || x==8 && y==12) {
                eN=1;
                combat_encounter_1();
                if (enemy[1].isAlive==false) {
                    area[6][13].text="_";
                    area[6][13].status=1;
                }
            }
        }
        if (location==2) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;

            movement();
            inventory();

            if (x==5 && y==11) {
                text1="Press 'e' to go to room";
                door2();
            }
            if (lootPackage3Used==false) {
                if (x==7 && y==14 || x==6 && y==15 || x==8 && y==15) {
                    text1="Press 'e' to open loot package";
                    loot_package_3();
                }
            }
            if (x==13 && y==11 || x==13 && y==12 || x==13 && y==13 || x==13 && y==14 || x==13 && y==15) {
                text1="Credits can be spent at the store ( S )";
            }
            if (x==14 && y==10 || x==15 && y==10 || x==16 && y==10 || x==17 && y==10 || x==18 && y==10) {
                text1="Type 'inventory' to open your inventory";
                text2="Health packs and shield boosts can be used there";
            }
            if (x==17 && y==13 || x==18 && y==12 || x==18 && y==14) {
                text1="Press 'e' to open the store";
                store();
            }
            if (x==14 && y==7 || x==15 && y==7 || x==16 && y==7 || x==17 && y==7 || x==18 && y==7) {
                eN=2;
                combat_encounter_1();
                if (enemy[2].isAlive==false) {
                    area[16][6].text="_";
                    area[16][6].status=1;
                }
            }
            if (x==16 && y==4) {
                text1="Press 'e' to go to next room";
                door3();
            }
        }
        if (location==3) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;

            movement();
            inventory();

            if (lootPackage4Used==false) {
                if (x==8 && y==19 || x==7 && y==20) {
                    text1="Press 'e' to open loot package";
                    loot_package_4();
                }
            }
            if (lootPackage5Used==false) {
                if (x==18 && y==5 || x==19 && y==4) {
                    text1="Press 'e' to open loot package";
                    loot_package_5();
                }
            }
            if (lootPackage6Used==false) {
                if (x==12 && y==4 || x==12 && y==6 || x==11 && y==5 || x==13 && y==5) {
                    text1="Press 'e' to open loot package";
                    loot_package_6();
                }
            }
            if (lootPackage7Used==false) {
                if (x==13 && y==14 || x==14 && y==15 || x==13 && y==16) {
                    text1="Press 'e' to open loot package";
                    loot_package_7();
                }
            }
            if (x==18 && y==10 || x==19 && y==9 || x==18 && y==8) {
                text1="Press 'e' to use the recharge station";
                recharge_station_1();
            }
            if (x==5 && y==18 || x==5 && y==20) {
                text1="Press 'e' to interact with computer";
                computer2();
            }
            if (x==20 && y==5 || x==20 && y==7) {
                text1="Press 'e' to interact with computer";
                computer3();
            }
            if (x==15 && y==20) {
                text1="Press 'e' to go to room";
                door3();
            }
            if (x==21 && y==13) {
                text1="Press 'e' go to next room";
                door4();
            }
            if (x==4 && y==13) {
                text1="Press 'e' to go to next room";
                door6();
            }
            if (x==10 && y==9 || x==11 && y==9 || x==12 && y==9 || x==13 && y==9 || x==14 && y==9) {
                eN=7;
                combat_encounter_2();
                if (enemy[7].isAlive==false) {
                    area[12][8].text="_";
                    area[12][8].status=1;
                }
            }
            if (x==5 && y==16 || x==6 && y==16) {
                eN=3;
                combat_encounter_1();
                if (enemy[3].isAlive==false) {
                    area[6][17].text="_";
                    area[6][17].status=1;
                }
            }
            if (x==20 && y==12) {
                text1="Press 'e' to interact";
                POS_2();
            }
            if (x==7 && y==14) {
                text1="Press 'e' to interact";
                POS_3();
            }
            if (x==4 && y==12) {
                text1="Press 'e' to interact";
                POS_7();
            }
        }
        if (location==4) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;

            movement();
            inventory();

            if (lootPackage8Used==false) {
                if (x==14 && y==17 || x==14 && y==15 || x==13 && y==16 || x==15 && y==16) {
                    text1="Press 'e' to open loot package";
                    loot_package_8();
                }
            }
            if (lootPackage9Used==false) {
                if (x==31 && y==4 || x==31 && y==6 || x==30 && y==5 || x==32 && y==5) {
                    text1="Press 'e' to open loot package";
                    loot_package_9();
                }
            }
            if (lootPackage10Used==false) {
                if (x==28 && y==4 || x==30 && y==4 || x==29 && y==5) {
                    text1="Press 'e' to open loot package";
                    loot_package_10();
                }
            }
            if (x==6 && y==9 || x==5 && y==10 || x==7 && y==10) {
                text1="Press 'e' to interact";
                POS_4();
            }
            if (x==24 && y==12 || x==24 && y==14 || x==25 && y==13) {
                text1="Press 'e' to interact";
                POS_5();
            }
            if (x==32 && y==8 || x==32 && y==10 || x==31 && y==9) {
                text1="Press 'e' to interact";
                POS_6();
            }
            if (x==18 && y==14 || x==18 && y==16) {
                text1="Press 'e' to interact with computer";
                computer4();
            }
            if (x==30 && y==15 || x==32 && y==15) {
                text1="Press 'e' to interact with computer";
                computer5();
            }
            if (x==26 && y==4 || x==26 && y==6) {
                text1="Press 'e' to interact with computer";
                computer6();
            }
            if (x==4 && y==9) {
                text1="Press 'e' to go to room";
                door4();
            }
            if (x==15 && y==9) {
                text1="Press 'e' to use the elevator";
                door5();
            }
            if (x==22 && y==8 || x==22 && y==9 || x==22 && y==10) {
                eN=4;
                combat_encounter_1();
                if (enemy[4].isAlive==false) {
                    area[23][9].text="_";
                    area[23][9].status=1;
                }
            }
            if (x==25 && y==12 || x==26 && y==12 || x==27 && y==12 || x==28 && y==12 || x==29 && y==12 || x==30 && y==12 || x==31 && y==12 || x==32 && y==12) {
                eN=10;
                combat_encounter_3();
                if (enemy[10].isAlive==false) {
                    area[28][13].text="_";
                    area[28][13].status=1;
                }
            }
            if (x==14 && y==4 || x==16 && y==4 || x==15 && y==5) {
                text1="Press 'e' to interact with the store";
                store();
            }
        }
        if (location==5) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;

            movement();
            inventory();

            if (x==5 && y==7) {
                text1="Press 'e' to interact  with reactor terminal";
                if (reactorCodes==0) {
                    text1="You do not have the reactor codes";
                } else {
                    ending_reactor();
                }
            }
            if (x==9 && y==7) {
                text1="Press 'e' to leave the room";
                door6();
            }
        }
        if (location==6) {
            levelUp();
            map();

            cout<<endl;
            cout<<"Action:";
            cin>>input;

            movement();
            inventory();

            if (x==5 && y==7) {
                text1="Press 'e' to interact  with computer";
                ending_escape();
            }
            if (x==11 && y==7) {
                text1="Press 'e' to use the elevator";
                door5();
            }
            if (x==7 && y==4 || x==7 && y==5 || x==7 && y==6 || x==7 && y==7 || x==7 && y==8 || x==7 && y==9 || x==7 && y==10) {
                eN=15;
                combat_encounter_4();
                if (enemy[15].isAlive==false) {
                    area[6][7].text="_";
                    area[6][7].status=1;
                }
            }
            if (lootPackage11Used==false) {
                if (x==9 && y==4 || x==10 && y==5 || x==11 && y==4) {
                    text1="Press 'e' to open loot package";
                    loot_package_11();
                }
            }
            if (x==9 && y==9 || x==8 && y==10 || x==10 && y==10) {
                text1="Press 'e' to use the recharge station";
                recharge_station_2();
            }
        }


    }


    return 0;
}