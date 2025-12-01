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
#include "door.h"
#include "combat_encounters.h"

using namespace std;


void combat_encounter_1() {

    if (enemy[eN].isAlive==true) {

        cout<<"  While walking through the ship"<<endl;
        cout<<"you notice a strange yellow, fungal growth"<<endl;
        cout<<"on the floor. It is moving towards you"<<endl;

        this_thread::sleep_for(chrono::milliseconds(1600));

        cout<<"Prepare for combat...."<<endl;
        this_thread::sleep_for(chrono::milliseconds(1600));



        while (enemy[eN].isAlive==true) {
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<playerName<<setw(40)<<" "<<enemy[eN].name<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"|         _____                                                      |"<<endl;
            cout<<"|         |# #|            _________                                 |"<<endl;
            cout<<"|        _|___|_          /./ ----->                                 |"<<endl;
            cout<<"|       |       |_________|./_                       /  #@           |"<<endl;
            cout<<"|     //|       |---------|.|-                    # (  /$ @  ) /#    |"<<endl;
            cout<<"|    // |       |                               ) # $ /   / & /# /   |"<<endl;
            cout<<"|   //  |       |                              @  /@  / #  ) @ /(  $ |"<<endl;
            cout<<"|  //   |_______|                          /  $  & / &  (  #/ / / /  |"<<endl;
            cout<<"| //     / / | |                               /  @ @ /$  #  @/ ) @  |"<<endl;
            cout<<"|       / /  | |                              ) #/  / #   ) /  /  #/ |"<<endl;
            cout<<"|      / /   | |                             &  /   &  #  (  $ /@    |"<<endl;
            cout<<"|     /_/    |_|                              #  (   /    # &  )     |"<<endl;
            cout<<"|                                                                    |"<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<"       HP: "<<health<<setw(45)<<"HP:"<<enemy[eN].health<<endl;
            cout<<"  SHIELDS: "<<shields<<setw(46)<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"1. Non lethal attack"<<endl;
            cout<<"2. Lethal attack (You have "<<ammo<<" bullets)"<<endl;
            cout<<endl;
            if (firstAttack==true) {
                cout<<" "<<endl;
            } else {
                cout<<setw(14)<<" "<<text4<<damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text5<<enemy[eN].damage<<" damage"<<endl;
            }
            cout<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>combatInput;


            if (combatInput=="1") {

                text6=" ";

                firstAttack=false;

                int crit = rand() % 100;

                if (crit<=critChance) {

                    damage=maxDamage+maxDamage*0.2-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }
                if (crit>critChance) {

                    damage=maxDamage-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }

                if (enemy[eN].health<=0) {
                    cout<<"The fungal growth has been defeated"<<endl;
                    this_thread::sleep_for(chrono::milliseconds(1200));
                    enemy[eN].isAlive=false;
                    firstAttack=true;
                    enemiesKilled++;
                    exp=exp+25;
                    text4=" ";
                    text5=" ";
                    text6=" ";
                    break;
                }

                if (enemy[eN].isAlive==true) {

                    int enemyCrit = rand() % 100;

                    if (enemyCrit<=enemy[eN].critChance) {
                        enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.1;

                        health=health-enemy[eN].damage;

                        text5="The enemy has dealt ";
                    }
                    if (enemyCrit>enemy[eN].critChance) {
                        enemy[eN].damage=enemy[eN].maxDamage-shields*0.1;

                        health=(health-enemy[eN].damage);

                        text5="The enemy has dealt ";
                    }
                }
                if (health<=0) {
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"You have died"<<endl;
                    system("pause");
                    exit(0);
                }
            }
            else if (combatInput=="2") {

                text6=" ";

                if (ammo==0) {
                    text6="You don't have any ammo";
                } else {
                    firstAttack=false;

                    int crit = rand() % 100;

                    if (crit<=critChance) {

                        damage=maxDamage+maxDamage*0.2+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }
                    if (crit>critChance) {

                        damage=maxDamage+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }

                    if (enemy[eN].health<=0) {
                        cout<<"The fungal growth has been defeated"<<endl;
                        this_thread::sleep_for(chrono::milliseconds(1200));
                        enemy[eN].isAlive=false;
                        firstAttack=true;
                        enemiesKilled++;
                        exp=exp+25;
                        text4=" ";
                        text5=" ";
                        text6=" ";
                        break;
                    }

                    if (enemy[eN].isAlive==true) {

                        int enemyCrit = rand() % 100;

                        if (enemyCrit<=enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.1;

                            health=health-enemy[eN].damage;

                            text5="The enemy has dealt ";
                        }
                        if (enemyCrit>enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage-shields*0.1;

                            health=(health-enemy[eN].damage);

                            text5="The enemy has dealt ";
                        }
                    }
                    if (health<=0) {
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"You have died"<<endl;
                        system("pause");
                        exit(0);
                    }
                }
            }
        }
    }
}//combat_encounter_1


void combat_encounter_2() {

    if (enemy[eN].isAlive==true) {

        cout<<"  While walking through the ship"<<endl;
        cout<<"you notice what appears to be a fellow crewmate"<<endl;
        cout<<"as you are about to greet them, you notice that their"<<endl;
        cout<<"uniform is torn revealing yellowish purple plants growing on them"<<endl;
        cout<<"as you come to the realization of what happened, it notices you."<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;

        this_thread::sleep_for(chrono::milliseconds(3600));

        cout<<"Prepare for combat...."<<endl;
        this_thread::sleep_for(chrono::milliseconds(1600));



        while (enemy[eN].isAlive==true) {
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<playerName<<setw(40)<<" "<<enemy[eN].name<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"|         _____                                       / _____)       |"<<endl;
            cout<<"|         |# #|            _________                   |# @|  @      |"<<endl;
            cout<<"|        _|___|_          /./ ----->                  (@_|__)_|_     |"<<endl;
            cout<<"|       |       |_________|./_                    @ / / |    @   |_  |"<<endl;
            cout<<"|     //|       |---------|.|-                     //|    @ )  |-    |"<<endl;
            cout<<"|    // |       |                                 /@/ |/  (     /|@  |"<<endl;
            cout<<"|   //  |       |                                // / | )  /  /  |  (|"<<endl;
            cout<<"|  //   |_______|                                /  ) |____@___|@    |"<<endl;
            cout<<"| //     / / | |                                    @  / / | |//     |"<<endl;
            cout<<"|       / /  | |                                    / / / @ | (|     |"<<endl;
            cout<<"|      / /   | |                                    / / /  | |       |"<<endl;
            cout<<"|     /_/    |_|                                   /_/    |_|        |"<<endl;
            cout<<"|                                                                    |"<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<"       HP: "<<health<<setw(45)<<"HP:"<<enemy[eN].health<<endl;
            cout<<"  SHIELDS: "<<shields<<setw(46)<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"1. Non lethal attack"<<endl;
            cout<<"2. Lethal attack (You have "<<ammo<<" bullets)"<<endl;
            cout<<endl;
            if (firstAttack==true) {
                cout<<" "<<endl;
            } else {
                cout<<setw(14)<<" "<<text4<<damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text5<<enemy[eN].damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text6<<shieldDamage<<" damage against the shield"<<endl;
            }
            cout<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>combatInput;


            if (combatInput=="1") {

                text6=" ";

                firstAttack=false;

                int crit = rand() % 100;

                if (crit<=critChance) {

                    damage=maxDamage+maxDamage*0.2-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }
                if (crit>critChance) {

                    damage=maxDamage-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }

                if (enemy[eN].health<=0) {
                    cout<<"The corrupted passenger has been defeated"<<endl;
                    this_thread::sleep_for(chrono::milliseconds(1200));
                    enemy[eN].isAlive=false;
                    firstAttack=true;
                    enemiesKilled++;
                    exp=exp+25;
                    text4=" ";
                    text5=" ";
                    text6=" ";
                    break;
                }

                if (enemy[eN].isAlive==true) {

                    int enemyCrit = rand() % 100;

                    if (enemyCrit<=enemy[eN].critChance) {

                        enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.2;

                        health=health-enemy[eN].damage;

                        oldShields=shields;
                        shields-=enemy[eN].damage * 0.8;

                        shieldDamage=oldShields-shields;
                        if (shields<0) {
                            shields=0;
                        }

                        text5="The enemy has dealt ";
                        text6="The enemy has dealt ";
                    }
                    if (enemyCrit>enemy[eN].critChance) {

                        enemy[eN].damage=enemy[eN].maxDamage-shields*0.2;

                        oldShields=shields;
                        shields-=enemy[eN].damage * 0.8;
                        if (shields<0) {
                            shields=0;
                        }

                        shieldDamage=oldShields-shields;

                        health=health-enemy[eN].damage;

                        text5="The enemy has dealt ";
                        text6="The enemy has dealt ";
                    }
                }
                if (health<=0) {
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"You have died"<<endl;
                    system("pause");
                    exit(0);
                }
            }
            else if (combatInput=="2") {

                text6=" ";

                if (ammo==0) {
                    text6="You don't have any ammo";
                } else {
                    firstAttack=false;

                    int crit = rand() % 100;

                    if (crit<=critChance) {

                        damage=maxDamage+maxDamage*0.2+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }
                    if (crit>critChance) {

                        damage=maxDamage+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }

                    if (enemy[eN].health<=0) {
                        cout<<"The corrupted passenger has been defeated"<<endl;
                        this_thread::sleep_for(chrono::milliseconds(1200));
                        enemy[eN].isAlive=false;
                        firstAttack=true;
                        enemiesKilled++;
                        exp=exp+25;
                        text4=" ";
                        text5=" ";
                        text6=" ";
                        break;
                    }

                    if (enemy[eN].isAlive==true) {

                        int enemyCrit = rand() % 100;

                        if (enemyCrit<=enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.2;

                            health=health-enemy[eN].damage;

                            oldShields=shields;
                            shields-=enemy[eN].damage * 0.8;
                            if (shields<0) {
                                shields=0;
                            }

                            shieldDamage=oldShields-shields;

                            text5="The enemy has dealt ";
                            text6="The enemy has dealt ";
                        }
                        if (enemyCrit>enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage-shields*0.2;

                            health=health-enemy[eN].damage;

                            oldShields=shields;
                            shields-=enemy[eN].damage * 0.8;
                            if (shields<0) {
                                shields=0;
                            }

                            shieldDamage=oldShields-shields;

                            text5="The enemy has dealt ";
                            text6="The enemy has dealt ";
                        }
                    }
                    if (health<=0) {
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"You have died"<<endl;
                        system("pause");
                        exit(0);
                    }
                }
            }
        }
    }
}//combat_encounter_2


void combat_encounter_3() {

    if (enemy[eN].isAlive==true) {

        cout<<"  While walking through the ship"<<endl;
        cout<<"you notice what appears to be a fellow crewmate"<<endl;
        cout<<"however this time you ready your weapon in advance"<<endl;
        cout<<"and it is good that you did that. This 'crewmate' is also"<<endl;
        cout<<"covered in yellowish fungal growth."<<endl;
        cout<<"It has it's weapon drawn at you."<<endl;
        cout<<endl;

        this_thread::sleep_for(chrono::milliseconds(4000));

        cout<<"Prepare for combat...."<<endl;
        this_thread::sleep_for(chrono::milliseconds(2600));



        while (enemy[eN].isAlive==true) {
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<playerName<<setw(40)<<" "<<enemy[eN].name<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"|         _____                                       / _S___)       |"<<endl;
            cout<<"|         |# #|            _________                   |# @|  @      |"<<endl;
            cout<<"|        _|___|_          /./ ----->                  (@_|__)_|_     |"<<endl;
            cout<<"|       |       |_________|./_         ________^_   @ / / |  @   |_  |"<<endl;
            cout<<"|     //|       |---------|.|-         <---------/.| //|  @ )  |-    |"<<endl;
            cout<<"|    // |       |                                |.| /@/ |/  (  /|@  |"<<endl;
            cout<<"|   //  |       |                                |.|// / | ) /      (|"<<endl;
            cout<<"|  //   |_______|                                /  ) |____@___|@    |"<<endl;
            cout<<"| //     / / | |                                    @  / / | |//     |"<<endl;
            cout<<"|       / /  | |                                    / / / @ | (|     |"<<endl;
            cout<<"|      / /   | |                                    / / /  | |       |"<<endl;
            cout<<"|     /_/    |_|                                   /_/    |_|        |"<<endl;
            cout<<"|                                                                    |"<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<"       HP: "<<health<<setw(45)<<"HP:"<<enemy[eN].health<<endl;
            cout<<"  SHIELDS: "<<shields<<setw(46)<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"1. Non lethal attack"<<endl;
            cout<<"2. Lethal attack (You have "<<ammo<<" bullets)"<<endl;
            cout<<endl;
            if (firstAttack==true) {
                cout<<" "<<endl;
            } else {
                cout<<setw(14)<<" "<<text4<<damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text5<<enemy[eN].damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text6<<enemy[eN].damage-10<<" damage against the shield"<<endl;
            }
            cout<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>combatInput;


            if (combatInput=="1") {

                text6=" ";

                firstAttack=false;

                int crit = rand() % 100;

                if (crit<=critChance) {

                    damage=maxDamage+maxDamage*0.2-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }
                if (crit>critChance) {

                    damage=maxDamage-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }

                if (enemy[eN].health<=0) {
                    cout<<"The corrupted guard has been defeated"<<endl;
                    this_thread::sleep_for(chrono::milliseconds(1200));
                    enemy[eN].isAlive=false;
                    firstAttack=true;
                    enemiesKilled++;
                    exp=exp+25;
                    text4=" ";
                    text5=" ";
                    text6=" ";
                    break;
                }

                if (enemy[eN].isAlive==true) {

                    int enemyCrit = rand() % 100;

                    if (enemyCrit<=enemy[eN].critChance) {

                        enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.2;

                        health=health-enemy[eN].damage;
                        shields=shields-enemy[eN].damage+10;
                        if (shields<=0) {
                            shields=0;
                        }

                        text5="The enemy has dealt ";
                        text6="The enemy has dealt ";
                    }
                    if (enemyCrit>enemy[eN].critChance) {

                        enemy[eN].damage=enemy[eN].maxDamage-shields*0.2;

                        shields=shields-enemy[eN].damage+10;
                        if (shields<=0) {
                            shields=0;
                        }

                        health=health-enemy[eN].damage;

                        text5="The enemy has dealt ";
                        text6="The enemy has dealt ";
                    }
                }
                if (health<=0) {
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"You have died"<<endl;
                    system("pause");
                    exit(0);
                }
            }
            else if (combatInput=="2") {

                text6=" ";

                if (ammo==0) {
                    text6="You don't have any ammo";
                } else {
                    firstAttack=false;

                    int crit = rand() % 100;

                    if (crit<=critChance) {

                        damage=maxDamage+maxDamage*0.2+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }
                    if (crit>critChance) {

                        damage=maxDamage+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }

                    if (enemy[eN].health<=0) {
                        cout<<"The corrupted guard has been defeated"<<endl;
                        this_thread::sleep_for(chrono::milliseconds(1200));
                        enemy[eN].isAlive=false;
                        firstAttack=true;
                        enemiesKilled++;
                        exp=exp+25;
                        text4=" ";
                        text5=" ";
                        text6=" ";
                        break;
                    }

                    if (enemy[eN].isAlive==true) {

                        int enemyCrit = rand() % 100;

                        if (enemyCrit<=enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.2;

                            health=health-enemy[eN].damage;
                            shields=shields-enemy[eN].damage+10;
                            if (shields<=0) {
                                shields=0;
                            }

                            text5="The enemy has dealt ";
                            text6="The enemy has dealt ";
                        }
                        if (enemyCrit>enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage-shields*0.2;

                            health=health-enemy[eN].damage;
                            shields=shields-enemy[eN].damage+10;
                            if (shields<=0) {
                                shields=0;
                            }

                            text5="The enemy has dealt ";
                            text6="The enemy has dealt ";
                        }
                    }
                    if (health<=0) {
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"You have died"<<endl;
                        system("pause");
                        exit(0);
                    }
                }
            }
        }
    }
}//combat_encounter_3


void combat_encounter_4() {

    if (enemy[eN].isAlive==true) {

        cout<<"  Upon entering the lab storage"<<endl;
        cout<<"you don't see anything out of the ordinary,"<<endl;
        cout<<"but then something moves in the dark."<<endl;
        cout<<"an fleshy abomination, its fingers are made of hands,"<<endl;
        cout<<"instead of eyes it has heads."<<endl;
        cout<<"It is rapidly approaching"<<endl;
        cout<<endl;

        this_thread::sleep_for(chrono::milliseconds(4000));

        cout<<"Prepare for combat...."<<endl;
        this_thread::sleep_for(chrono::milliseconds(2600));



        while (enemy[eN].isAlive==true) {
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<playerName<<setw(40)<<" "<<enemy[eN].name<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"|         _____                        - %  -  /- /  / _%___) -      |"<<endl;
            cout<<"|         |# #|            _________  2    @- %%-  / @   |# @$| $ @  |"<<endl;
            cout<<"|        _|___|_          /./ ----->  @ % -  $/ /  @   (@_|__)_%|_   |"<<endl;
            cout<<"|       |       |_________|./_                 - @ / / | / @%-   |_  |"<<endl;
            cout<<"|     //|       |---------|.|-              @  / $  /HEY  $@ ) - |$- |"<<endl;
            cout<<"|    // |       |                      -/ /  @  -   /@/ -|/  (%  /|@ |"<<endl;
            cout<<"|   //  |       |                           %  //% / |$$ ) //      ( |"<<endl;
            cout<<"|  //   |_______|                     $ @/ -  / @ ) |____@%___-|@    |"<<endl;
            cout<<"| //     / / | |               %/- /-@/ %  -  -/$ - % @  / /- | |//  |"<<endl;
            cout<<"|       / /  | |                 /-    % / $  @- / / / %@ |/- (|     |"<<endl;
            cout<<"|      / /   | |                 /   $  L -/  % / / // - | 5|  %     |"<<endl;
            cout<<"|     /_/    |_|                        $    @   /    /_/  $  |_|  / |"<<endl;
            cout<<"|                                      L   - L     L       L     L   |"<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<"       HP: "<<health<<setw(45)<<"HP:"<<enemy[eN].health<<endl;
            cout<<"  SHIELDS: "<<shields<<setw(46)<<endl;
            cout<<"|--------------------------------------------------------------------|"<<endl;
            cout<<endl;
            cout<<"1. Non lethal attack"<<endl;
            cout<<"2. Lethal attack (You have "<<ammo<<" bullets)"<<endl;
            cout<<endl;
            if (firstAttack==true) {
                cout<<" "<<endl;
            } else {
                cout<<setw(14)<<" "<<text4<<damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text5<<enemy[eN].damage<<" damage"<<endl;
                cout<<setw(14)<<" "<<text6<<enemy[eN].damage-10<<" damage against the shield"<<endl;
            }
            cout<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>combatInput;


            if (combatInput=="1") {

                text6=" ";

                firstAttack=false;

                int crit = rand() % 100;

                if (crit<=critChance) {

                    damage=maxDamage+maxDamage*0.2-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }
                if (crit>critChance) {

                    damage=maxDamage-2;

                    enemy[eN].health=enemy[eN].health-damage;

                    text4="You have dealt ";
                }

                if (enemy[eN].health<=0) {
                    cout<<"The fungal abomination has been defeated"<<endl;
                    this_thread::sleep_for(chrono::milliseconds(1200));
                    enemy[eN].isAlive=false;
                    firstAttack=true;
                    enemiesKilled++;
                    text4=" ";
                    text5=" ";
                    text6=" ";
                    break;
                }

                if (enemy[eN].isAlive==true) {

                    int enemyCrit = rand() % 100;

                    if (enemyCrit<=enemy[eN].critChance) {

                        enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.2;

                        health=health-enemy[eN].damage;
                        shields=shields-enemy[eN].damage+10;
                        if (shields<=0) {
                            shields=0;
                        }

                        text5="The enemy has dealt ";
                        text6="The enemy has dealt ";
                    }
                    if (enemyCrit>enemy[eN].critChance) {

                        enemy[eN].damage=enemy[eN].maxDamage-shields*0.2;

                        shields=shields-enemy[eN].damage+10;
                        if (shields<=0) {
                            shields=0;
                        }

                        health=health-enemy[eN].damage;

                        text5="The enemy has dealt ";
                        text6="The enemy has dealt ";
                    }
                }
                if (health<=0) {
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"You have died"<<endl;
                    system("pause");
                    exit(0);
                }
            }
            else if (combatInput=="2") {

                text6=" ";

                if (ammo==0) {
                    text6="You don't have any ammo";
                } else {
                    firstAttack=false;

                    int crit = rand() % 100;

                    if (crit<=critChance) {

                        damage=maxDamage+maxDamage*0.2+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }
                    if (crit>critChance) {

                        damage=maxDamage+6;

                        enemy[eN].health=enemy[eN].health-damage;

                        ammo--;
                        bulletsUsed++;

                        text4="You have dealt ";
                    }

                    if (enemy[eN].health<=0) {
                        cout<<"The fungal abomination has been defeated"<<endl;
                        this_thread::sleep_for(chrono::milliseconds(1200));
                        enemy[eN].isAlive=false;
                        firstAttack=true;
                        enemiesKilled++;
                        text4=" ";
                        text5=" ";
                        text6=" ";
                        break;
                    }

                    if (enemy[eN].isAlive==true) {

                        int enemyCrit = rand() % 100;

                        if (enemyCrit<=enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage+enemy[eN].maxDamage*0.2-shields*0.2;

                            health=health-enemy[eN].damage;
                            shields=shields-enemy[eN].damage+10;
                            if (shields<=0) {
                                shields=0;
                            }

                            text5="The enemy has dealt ";
                            text6="The enemy has dealt ";
                        }
                        if (enemyCrit>enemy[eN].critChance) {
                            enemy[eN].damage=enemy[eN].maxDamage-shields*0.2;

                            health=health-enemy[eN].damage;
                            shields=shields-enemy[eN].damage+10;
                            if (shields<=0) {
                                shields=0;
                            }

                            text5="The enemy has dealt ";
                            text6="The enemy has dealt ";
                        }
                    }
                    if (health<=0) {
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"You have died"<<endl;
                        system("pause");
                        exit(0);
                    }
                }
            }
        }
    }
}//combat_encounter_4
