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

using namespace std;

void computer1() {

    if (input=="e") {

        cout<<"Turning on computer..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout<<"Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        computerActive=true;

        while (computerActive) {
            text1="Type 'emails' to access the emails";
            text2="Type 'exit' to exit the computer";

            cout<<"------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Emails(2)                    "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                         "<<"|"<<endl;

            cout<<"------------------------------------------------------"<<endl;
            cout<<setw(12)<<" "<<text1<<endl;
            cout<<setw(12)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>computerInput;

            if (computerInput=="emails") {
                while (true) {
                    cout << "Accessing emails..."<<endl;
                    this_thread::sleep_for(chrono::milliseconds(400));

                    text1="Type 1 or 2 to access emails";
                    text2="Type 'back' to return to main screen";

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >1. EMERGENCY ALERT           "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >2. Door access code          "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                         "<<"|"<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>emailInput;

                    if (emailInput=="1") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  From: Captain Flowers                   "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"    This is a ship-wide emergency         "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  announcement. Everyone must evacuate the"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  ship at once. Move towards the escape   "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  pods. If they are already full, don't   "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  panic, hide somewhere and wait for      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  rescue. We apologize for not being able "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  to help more.                           "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }
                        }
                    } else if (emailInput=="2") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to the email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"            ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  From: James Sahara                      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"     There are rumours going around that  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  a ship-wide emergency will soon be      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  announced. If that happens, the shuttle "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  bay doors will lock, so here is the     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  code for the doors: 2552                "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                           -J. Sahara     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }

                        }
                    } else if (emailInput=="back") {
                        emailInput=" ";
                        cout << "Exiting emails..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        break;
                    }
                }
            }
            if (computerInput=="exit") {
                computerActive=false;
                cout << "Shutting down computer..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                computerInput=" ";
                emailInput=" ";
                text1="Press 'e' to interact";
                text2=" ";
            }
        }
    }
}// computer1


void computer2() {

    if (input=="e") {

        cout<<"Turning on computer..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout<<"Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        computerActive=true;

        while (computerActive) {
            text1="Type 'emails' to access the emails";
            text2="Type 'exit' to exit the computer";

            cout<<"------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Emails(1)                    "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                         "<<"|"<<endl;

            cout<<"------------------------------------------------------"<<endl;
            cout<<setw(12)<<" "<<text1<<endl;
            cout<<setw(12)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>computerInput;

            if (computerInput=="emails") {
                while (true) {
                    cout << "Accessing emails..."<<endl;
                    this_thread::sleep_for(chrono::milliseconds(400));

                    text1="Type 1 to access emails";
                    text2="Type 'back' to return to main screen";

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >1. More problems from the    "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  medbay                        "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                         "<<"|"<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>emailInput;

                    if (emailInput=="1") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  To: Captain Flowers                     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"    Recently we've been getting a lot of  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  technical problems. Nearly all of them  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  are from the medbay.                    "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"    Please investigate this situation     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  or else I will go there myself to find  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  out what is going on there              "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                         -Jenny Smith     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }
                        }
                    } else if (emailInput=="back") {
                        emailInput=" ";
                        cout << "Exiting emails..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        break;
                    }
                }
            }
            if (computerInput=="exit") {
                computerActive=false;
                cout << "Shutting down computer..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                computerInput=" ";
                emailInput=" ";
                text1="Press 'e' to interact";
                text2=" ";
            }
        }
    }
}


void computer3() {

    if (input=="e") {

        cout<<"Turning on computer..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout<<"Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        computerActive=true;

        while (computerActive) {
            text1="Type 'emails' to access the emails";
            text2="Type 'exit' to exit the computer";

            cout<<"------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Emails(2)                    "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                         "<<"|"<<endl;

            cout<<"------------------------------------------------------"<<endl;
            cout<<setw(12)<<" "<<text1<<endl;
            cout<<setw(12)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>computerInput;

            if (computerInput=="emails") {
                while (true) {
                    cout << "Accessing emails..."<<endl;
                    this_thread::sleep_for(chrono::milliseconds(400));

                    text1="Type 1 or 2 to access emails";
                    text2="Type 'back' to return to main screen";

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >1. Reply: Request to         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  investigate the medbay        "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >2. Request to investigate    "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  the medbay                    "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                         "<<"|"<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>emailInput;

                    if (emailInput=="1") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  From: James Sahara                      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"   Your request to investigate the medbay "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<" has been denied, please keep continue    "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<" to report any problems that are on this  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<" ship. Don't worry the situation will soon"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<" be fixed.                                "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                       -James Sahara      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                                          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }
                        }
                    } else if (emailInput=="2") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to the email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"            ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  To: James Sahara                        "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"   Problems are emerging from the medbay  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  again, originaly it was just science    "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  personnel who were calling in sick      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  now people from the other side of the   "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  ship are experiencing the same problems."<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  I would like to investigate, so I can   "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  find the source of these problems.      "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                     -Sam Johnston        "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }

                        }
                    } else if (emailInput=="back") {
                        emailInput=" ";
                        cout << "Exiting emails..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        break;
                    }
                }
            }
            if (computerInput=="exit") {
                computerActive=false;
                cout << "Shutting down computer..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                computerInput=" ";
                emailInput=" ";
                text1="Press 'e' to interact";
                text2=" ";
            }
        }
    }

}


void computer4() {

    if (input=="e") {

        cout<<"Turning on computer..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout<<"Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        computerActive=true;

        while (computerActive) {
            text1="Type 'emails' to access the emails";
            text2="Type 'exit' to exit the computer";

            cout<<"------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Emails(1)                    "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                         "<<"|"<<endl;

            cout<<"------------------------------------------------------"<<endl;
            cout<<setw(12)<<" "<<text1<<endl;
            cout<<setw(12)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>computerInput;

            if (computerInput=="emails") {
                while (true) {
                    cout << "Accessing emails..."<<endl;
                    this_thread::sleep_for(chrono::milliseconds(400));

                    text1="Type 1 to access emails";
                    text2="Type 'back' to return to main screen";

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >1. More about the aliens     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                         "<<"|"<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>emailInput;

                    if (emailInput=="1") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  To: Peter Quin                          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"   We have done a lot of research on the  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  aliens. Here's what we know so far:     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  They infect the air and cause sickness, "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  this sickness causes the victims to go  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  mad and transform into those monsters.  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"   I believe we should halt the research  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  for if an outbreak is to happen, we do  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  not have access to earths technology    "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  that could stop it.                     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                                          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }
                        }
                    } else if (emailInput=="back") {
                        emailInput=" ";
                        cout << "Exiting emails..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        break;
                    }
                }
            }
            if (computerInput=="exit") {
                computerActive=false;
                cout << "Shutting down computer..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                computerInput=" ";
                emailInput=" ";
                text1="Press 'e' to interact";
                text2=" ";
            }
        }
    }
}


void computer5() {

    if (input=="e") {

        cout<<"Turning on computer..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout<<"Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        computerActive=true;

        while (computerActive) {
            text1="Type 'emails' to access the emails";
            text2="Type 'exit' to exit the computer";

            cout<<"------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Emails(1)                    "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                         "<<"|"<<endl;

            cout<<"------------------------------------------------------"<<endl;
            cout<<setw(12)<<" "<<text1<<endl;
            cout<<setw(12)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>computerInput;

            if (computerInput=="emails") {
                while (true) {
                    cout << "Accessing emails..."<<endl;
                    this_thread::sleep_for(chrono::milliseconds(400));

                    text1="Type 1 to access emails";
                    text2="Type 'back' to return to main screen";

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >1. Announce an evacuation    "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                         "<<"|"<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>emailInput;

                    if (emailInput=="1") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  To: Captain Flowers                     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"   We need to evacuate the ships          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  personnel. Despite out best efforts     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  we could not halt the outbreak.         "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  Earth will still find the samples       "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  necessary to continue the research on   "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  the aliens. I hid the sample in the     "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  medbay's storeroom, the passcode is 1234"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                                          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }
                        }
                    } else if (emailInput=="back") {
                        emailInput=" ";
                        cout << "Exiting emails..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        break;
                    }
                }
            }
            if (computerInput=="exit") {
                computerActive=false;
                cout << "Shutting down computer..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                computerInput=" ";
                emailInput=" ";
                text1="Press 'e' to interact";
                text2=" ";
            }
        }
    }

}


void computer6() {

    if (input=="e") {

        cout<<"Turning on computer..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout<<"Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        computerActive=true;

        while (computerActive) {
            text1="Type 'emails' to access the emails";
            text2="Type 'exit' to exit the computer";

            cout<<"------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Emails(1)                    "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                         "<<"|"<<endl;

            cout<<"------------------------------------------------------"<<endl;
            cout<<setw(12)<<" "<<text1<<endl;
            cout<<setw(12)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>computerInput;

            if (computerInput=="emails") {
                while (true) {
                    cout << "Accessing emails..."<<endl;
                    this_thread::sleep_for(chrono::milliseconds(400));

                    text1="Type 1 to access emails";
                    text2="Type 'back' to return to main screen";

                    cout<<"------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"      ZEBRANIUM INDUSTERIES     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >1. Note to self              "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                         "<<"|"<<endl;

                    cout<<"------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>emailInput;

                    if (emailInput=="1") {
                        while (true) {
                            cout << "Accessing email..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));

                            text1="Type 'back' to return to email screen";
                            text2=" ";

                            cout<<"------------------------------------------------------"<<endl;

                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"------------------------------------------"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  To: Tony Streets                        "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"   The ship must be destroyed. If a single"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  alien makes it back to earth it is all  "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  over. Next to the desk I hid reactor    "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  codes necessary to blow up the ship.    "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  The passcode to the reactor room is 1410"<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"                                          "<<"|"<<endl;
                            cout<<setw(12)           <<"|"<<"  >Back                                   "<<"|"<<endl;

                            cout<<"------------------------------------------------------"<<endl;
                            cout<<setw(14)<<" "<<text1<<endl;
                            cout<<setw(14)<<" "<<text2<<endl;

                            cout<<endl;
                            cout<<"Action:"<<endl;
                            cin>>emailInput;

                            if (emailInput=="back") {
                                emailInput=" ";
                                cout << "Returning..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                                break;
                            }
                        }
                    } else if (emailInput=="back") {
                        emailInput=" ";
                        cout << "Exiting emails..."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        break;
                    }
                }
            }
            if (computerInput=="exit") {
                computerActive=false;
                cout << "Shutting down computer..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                computerInput=" ";
                emailInput=" ";
                text1="Press 'e' to interact";
                text2=" ";
            }
        }
    }
}
