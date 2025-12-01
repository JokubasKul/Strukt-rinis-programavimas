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

using namespace std;


void door1() {

    if (input=="e") {

        if (door1Returning==false) {

            if (door1Open==false) {

                text3="Please type in the passcode";
                text1="Type 'exit' to exit the panel";
                text2=" ";

                passcode[0]=*"0"; passcode[1]=*"0"; passcode[2]=*"0"; passcode[3]=*"0";

                while (true) {

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"         Please enter the passcode       "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           |"<<passcode[0]<<"|  |"<<passcode[1]<<"|  |"<<passcode[2]<<"|  |"<<passcode[3]<<"|            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Exit                                  "<<"|"<<endl;

                    cout<<setw(14)<<" "<<text3<<endl;
                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>doorInput;

                    if (doorInput=="exit") {
                        cout << "Exiting panel..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        doorInput=" ";
                        text1="Press 'e' to go to next room";
                        text2=" ";
                        text3=" ";
                        text4=" ";
                        break;
                    }
                    if (doorInput=="2552") {
                        passcode[0]=*"2"; passcode[1]=*"5"; passcode[2]=*"5"; passcode[3]=*"2";
                        cout << "Please wait..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        text3="Passcode is correct, the door is unlocked";
                        text4="You may exit the panel";
                        door1Open=true;
                        doorInput=" ";
                    }
                    else {
                        text3="Passcode is incorrect, please try again";
                    }

                }
            } else if (door1Open==true) {
                text1=" ";
                cout << "Building room..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                loading_map_1();
                cout << "Done..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                location=1;
                door1Returning=true;
                visited0=true;
            }
        } else if (door1Returning==true) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_0();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=0;
            door1Returning=false;
            x=9; y=14;
            area[9][14].text="P";
        }
    }
} // door1


void door2() {

    if (input=="e") {

        if (door2Returning==false) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_2();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=2;
            door2Returning=true;
            visited1=true;
        } else if (door2Returning==true) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_1();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=1;
            door2Returning=false;
            x=6; y=14;
            area[6][14].text="P";
        }
    }
}//door2


void door3() {

    if (input=="e") {

        if (door3Returning==false) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_3();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=3;
            door3Returning=true;
            visited2=true;
        } else if (door3Returning==true) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_2();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=2;
            door3Returning=false;
            x=16; y=5;
            area[16][5].text="P";
        }
    }
}//door3


void door4() {

    if (input=="e") {

        if (keycard==3) {
            door3Open=true;
        }

        if (door3Open==false) {

            text1="  You need 3 keycards to unlock the door to the medbay";
        } else {
            if (door4Returning==false) {
                text1=" ";
                cout << "Building room..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                loading_map_4();
                cout << "Done..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                location=4;
                door4Returning=true;
                visited3=true;
            }
            else if (door4Returning==true) {
                text1=" ";
                cout << "Building room..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                loading_map_3();
                cout << "Done..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                location=3;
                door4Returning=false;
                x=20; y=13;
                area[20][13].text="P";
            }
        }
    }
}//door4


void door5() {

    if (input=="e") {

        if (door5Returning==false) {

            if (door5Open==false) {

                text3="Please type in the passcode";
                text1="Type 'exit' to exit the panel";

                passcode[0]=*"0"; passcode[1]=*"0"; passcode[2]=*"0"; passcode[3]=*"0";

                while (true) {

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"         Please enter the passcode       "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           |"<<passcode[0]<<"|  |"<<passcode[1]<<"|  |"<<passcode[2]<<"|  |"<<passcode[3]<<"|            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Exit                                  "<<"|"<<endl;

                    cout<<setw(14)<<" "<<text3<<endl;
                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>doorInput;

                    if (doorInput=="exit") {
                        cout << "Exiting panel..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        doorInput=" ";
                        text1="Press 'e' to use the elevator";
                        text2=" ";
                        text3=" ";
                        text4=" ";
                        break;
                    }
                    if (doorInput=="1234") {
                        passcode[0]=*"1"; passcode[1]=*"2"; passcode[2]=*"3"; passcode[3]=*"4";
                        cout << "Please wait..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        text3="Passcode is correct, the elevator is unlocked";
                        text4="You may exit the panel";
                        door5Open=true;
                        doorInput=" ";
                    }
                    else {
                        text3="Passcode is incorrect, please try again";
                    }

                }
            } else if (door5Open==true) {
                text1=" ";
                cout << "Building room..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                loading_map_6();
                cout << "Done..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                location=6;
                door5Returning=true;
                visited4=true;
            }
        } else if (door5Returning==true) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_4();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=4;
            door5Returning=false;
            x=14; y=9;
            area[14][9].text="P";
        }
    }

}//door5


void door6() {

    if (input=="e") {

        if (door6Returning==false) {

            if (door6Open==false) {

                text3="Please type in the passcode";
                text1="Type 'exit' to exit the panel";

                passcode[0]=*"0"; passcode[1]=*"0"; passcode[2]=*"0"; passcode[3]=*"0";

                while (true) {

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"         Please enter the passcode       "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           |"<<passcode[0]<<"|  |"<<passcode[1]<<"|  |"<<passcode[2]<<"|  |"<<passcode[3]<<"|            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Exit                                  "<<"|"<<endl;

                    cout<<setw(14)<<" "<<text3<<endl;
                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>doorInput;

                    if (doorInput=="exit") {
                        cout << "Exiting panel..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        doorInput=" ";
                        text1="Press 'e' to use open the door";
                        text2=" ";
                        text3=" ";
                        text4=" ";
                        break;
                    }
                    if (doorInput=="1410") {
                        passcode[0]=*"1"; passcode[1]=*"4"; passcode[2]=*"1"; passcode[3]=*"0";
                        cout << "Please wait..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        text3="Passcode is correct, the door is unlocked";
                        text4="You may exit the panel";
                        door6Open=true;
                        doorInput=" ";
                    }
                    else {
                        text3="Passcode is incorrect, please try again";
                    }

                }
            } else if (door6Open==true) {
                text1=" ";
                cout << "Building room..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                loading_map_5();
                cout << "Done..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                location=5;
                door6Returning=true;
                visited3=true;
            }
        } else if (door6Returning==true) {
            text1=" ";
            cout << "Building room..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            loading_map_3();
            cout << "Done..."<<endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            location=3;
            door6Returning=false;
            x=5; y=13;
            area[5][13].text="P";
        }
    }

}