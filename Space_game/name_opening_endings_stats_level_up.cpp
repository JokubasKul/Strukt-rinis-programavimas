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

using namespace std;


void name() {

    cout<<"What is your name?"<<endl;
    cin>>playerName;

}


void opening() {

    cout<<"Name: "<<playerName<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"Occupation: Police officer"<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"Arriving on: SE Search and Rescue"<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"Arriving to: SE Light Control"<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"Objective: Retrieve a sample from the medbay"<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(3200));

}


void levelUp() {

    if (levelUp1==false && exp==50) {
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|          LEVEL UP          |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|    Choose an upgrade       |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|  1. Max health upgrade     |"<<endl;
        cout<<setw(12)<<"|  2. Max shields upgrade    |"<<endl;
        cout<<setw(12)<<"|  3. Damage upgrade         |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;

        cout<<endl;
        cout<<"Action:"<<endl;
        cin>>levelInput;

        if (levelInput=="1") {
            maxHealth=maxHealth+50;
            health=150;
            levelUp1=true;
            cout<<"Upgrading health...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        } else if (levelInput=="2") {
            maxShields=maxShields+25;
            shields=75;
            levelUp1=true;
            cout<<"Upgrading shields...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        } else if (levelInput=="3") {
            maxDamage=maxDamage+4;
            levelUp1=true;
            cout<<"Upgrading damage...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        }
    }
    if (levelUp2==false && exp==100) {
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|          LEVEL UP          |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|    Choose an upgrade       |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|  1. Max health upgrade     |"<<endl;
        cout<<setw(12)<<"|  2. Max shields upgrade    |"<<endl;
        cout<<setw(12)<<"|  3. Damage upgrade         |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;

        cout<<endl;
        cout<<"Action:"<<endl;
        cin>>levelInput;

        if (levelInput=="1") {
            maxHealth=maxHealth+50;
            health=maxHealth;
            levelUp2=true;
            cout<<"Upgrading health...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        } else if (levelInput=="2") {
            maxShields=maxShields+25;
            shields=maxShields;
            levelUp2=true;
            cout<<"Upgrading shields...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        } else if (levelInput=="3") {
            maxDamage=maxDamage+4;
            levelUp2=true;
            cout<<"Upgrading damage...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        }
    }
    if (levelUp3==false && exp==150) {
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|          LEVEL UP          |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|    Choose an upgrade       |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;
        cout<<setw(12)<<"|  1. Max health upgrade     |"<<endl;
        cout<<setw(12)<<"|  2. Max shields upgrade    |"<<endl;
        cout<<setw(12)<<"|  3. Damage upgrade         |"<<endl;
        cout<<setw(12)<<"|----------------------------|"<<endl;

        cout<<endl;
        cout<<"Action:"<<endl;
        cin>>levelInput;

        if (levelInput=="1") {
            maxHealth=maxHealth+50;
            health=maxHealth;
            levelUp3=true;
            cout<<"Upgrading health...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        } else if (levelInput=="2") {
            maxShields=maxShields+25;
            shields=maxShields;
            levelUp3=true;
            cout<<"Upgrading shields...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        } else if (levelInput=="3") {
            maxDamage=maxDamage+4;
            levelUp3=true;
            cout<<"Upgrading damage...."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
        }
    }

}


void stats() {

    cout<<"       CONGRATULATIONS, YOU BEAT THE GAME     "<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<endl;
    cout<<"  Items bought: "<<itemsBought<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"  Items sold: "<<itemsSold<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"  Health packs used: "<<healthPacksUsed<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"  Shield boosts used: "<<shieldsBoostsUsed<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"  Bullets fired: "<<bulletsUsed<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"  Enemies killed: "<<enemiesKilled<<endl;
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"  Loot crates opened: "<<lootCratesOpened<<endl;
    cout<<endl;
    cout<<endl;

    system("pause");
    exit(0);

}


void ending_reactor() {

    if (input=="e") {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<" Taking the advice of Tony Streets"<<endl;
        cout<<"you decide the best course of action"<<endl;
        cout<<"is to blow up the ship."<<endl;
        cout<<"Now none of the aliens can harm earth"<<endl;
        this_thread::sleep_for(chrono::milliseconds(4000));
        cout<<endl;
        cout<<endl;
        stats();
    }

}


void ending_escape() {

    if (input=="e") {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<" Deciding to act on the behest"<<endl;
        cout<<"of the science team, you decide to"<<endl;
        cout<<"take the sample to the SE Search and Rescue."<<endl;
        cout<<"What happens now is in the hands of the researchers on earth."<<endl;
        this_thread::sleep_for(chrono::milliseconds(4000));
        cout<<endl;
        cout<<endl;
        stats();
    }
}
