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
#include "store_inventory_map.h"

using namespace std;

void store() {

    if(input=="e") {

        cout << "Activating store..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        cout << "Loading systems..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));

        storeActive=true;

        while(storeActive) {

            text1="Type 'buy' to buy items";
            text2="Type 'sell' to sell items";
            text3="Type 'exit' to exit the store";

            cout<<"---------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                  STORE                  "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"       >BUY                  >SELL       "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                                  "<<"|"<<endl;

            cout<<"---------------------------------------------------------"<<endl;
            cout<<setw(14)<<" "<<text1<<endl;
            cout<<setw(14)<<" "<<text2<<endl;
            cout<<setw(14)<<" "<<text3<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>storeInput;

            if(storeInput=="buy") {

                text1="You have: ";
                text2="Type 'back' to return to main screen";
                text3=" ";
                text4="Please, select what you would like to buy";

                while(true) {

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   1. 250$ Health pack ("<<healthPacksRemaining<<" remaining)     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   2. 200$ Shields boost ("<<shieldsBoostsRemaining<<" remaining)   "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   3. 200$ Ammo ("<<ammoRemaining<<" remaining)            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                                  "<<"|"<<endl;

                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<credits<<" credits"<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;
                    cout<<setw(14)<<" "<<text3<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>storeInput;

                    if(storeInput=="1") {
                        if (healthPacksRemaining>0) {
                            if (credits>=250) {
                                text4="Bought 1 health pack";
                                healthPacks++;
                                healthPacksRemaining--;
                                credits=credits-250;
                                itemsBought++;
                                cout << "Purchasing..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                            } else {
                                text4="You don't have enough credits";
                            }
                        } else {
                            text4="There are no more health packs in the store";
                        }
                    }
                    if(storeInput=="2") {
                        if (shieldsBoostsRemaining>0) {
                            if (credits>=200) {
                                text4="Bought 1 shield boost";
                                shieldBoosts++;
                                shieldsBoostsRemaining--;
                                credits=credits-200;
                                itemsBought++;
                                cout << "Purchasing..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                            } else {
                                text4="You don't have enough credits";
                            }
                        } else {
                            text4="There are no more shield boosts in the store";
                        }
                    }
                    if(storeInput=="3") {
                        if (ammoRemaining>0) {
                            if (credits>=200) {
                                text4="Bought 5 blaster ammo";
                                ammo=ammo+5;
                                ammoRemaining--;
                                credits=credits-200;
                                itemsBought++;
                                cout << "Purchasing..."<<endl;
                                this_thread::sleep_for(chrono::milliseconds(400));
                            } else {
                                text4="You don't have enough credits";
                            }
                        } else {
                            text4="There is no more ammo in the store";
                        }
                    }
                    if(storeInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        storeInput=" ";
                        input=" ";
                        break;
                    }
                }
            }

            if(storeInput=="sell") {

                text1="You have: ";
                text2="Type 'back' to return to main screen";
                text4="Please, select what you would like to sell";

                while(true) {

                    text3=" ";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"-------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"           ZEBRANIUM INDUSTERIES           "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"-------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   1. 100$ Scrap metal (You have:"<<scrapMetal<<")        "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   2. 250$ Valuable parts (You have:"<<valuableParts<<")     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   3. 30$ Ammo (You have: "<<ammo<<")               "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                           "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  >Back                                    "<<"|"<<endl;

                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<credits<<" credits"<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;
                    cout<<setw(14)<<" "<<text3<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>storeInput;

                    if(storeInput=="1") {
                        if (scrapMetal>0) {
                            text4="1 piece of scrap metal sold for 100 credits";
                            scrapMetal--;
                            credits=credits+100;
                            itemsSold++;
                            cout << "Selling..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));
                        } else {
                            text4="You don't have any scrap metal";
                        }
                    }
                    if(storeInput=="2") {
                        if (valuableParts>0) {
                            text4="1 valuable part sold for 250 credits";
                            valuableParts--;
                            credits=credits+250;
                            itemsSold++;
                            cout << "Selling..."<<endl;
                            this_thread::sleep_for(chrono::milliseconds(400));
                        } else {
                            text4="You don't have any valuable parts";
                        }
                    }
                    if(storeInput=="3") {
                        if (ammo>0) {
                            text4="1 bullet sold for 30 credits";
                            ammo--;
                            credits=credits+30;
                            itemsSold++;
                        } else {
                            text4="You don't have any ammo";
                        }
                    }
                    if(storeInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        storeInput=" ";
                        input=" ";
                        break;
                    }
                }
            }

            if(storeInput=="exit") {
                storeActive=false;
                cout<<"Shutting down store..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                storeInput=" ";
                text1="Press 'e' to open the store";
                text2=" ";
                text3=" ";
                text4=" ";
            }
        }
    }
}//store


void inventory() {

    if(input=="inventory") {

        cout << "Opening inventory..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));

        inventoryActive=true;

        while(inventoryActive) {

            text1="Select which item you would like to";
            text2="use/inspect";

            cout<<"---------------------------------------------------------"<<endl;

            cout<<setw(12)           <<"|"<<"-----------------------------------------"<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"                  INVENTORY              "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  1. Mark VIII SE Hazard armour "<<"         |"<<endl;
            cout<<setw(12)           <<"|"<<"  2. A81 blaster "<<"(You have: "<<ammo<<" bullets)   |"<<endl;
            cout<<setw(12)           <<"|"<<"  3. Scrap metal ("<<scrapMetal<<")                     |"<<endl;
            cout<<setw(12)           <<"|"<<"  4. Valuable parts ("<<valuableParts<<")                  |"<<endl;
            cout<<setw(12)           <<"|"<<"  5. Health packs ("<<healthPacks<<")                    |"<<endl;
            cout<<setw(12)           <<"|"<<"  6. Shield boosts ("<<shieldBoosts<<")                   |"<<endl;
            cout<<setw(12)           <<"|"<<"                                         "<<"|"<<endl;
            cout<<setw(12)           <<"|"<<"  >Exit                                  "<<"|"<<endl;

            cout<<setw(14)<<" "<<text4<<endl;

            cout<<"---------------------------------------------------------"<<endl;
            cout<<setw(14)<<" "<<text1<<endl;
            cout<<setw(14)<<" "<<text2<<endl;

            cout<<endl;
            cout<<"Action:"<<endl;
            cin>>inventoryInput;

            if (inventoryInput=="1") {

                while (true) {

                    text1="Type 'back' to return to the";
                    text2="main inventory screen";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                   INVENTORY                "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   The Mark VIII Solar Empire hazard armour "<<"|  HP:      "<<health<<endl;
                    cout<<setw(12)           <<"|"<<"  is commonly worn by the empire's police   "<<"|  SHIELDS: "<<shields  <<endl;
                    cout<<setw(12)           <<"|"<<"  forces. The armour is used in hazardous   "<<"|  AMMO:    "<<ammo<<endl;
                    cout<<setw(12)           <<"|"<<"  environments, such as: the vacuum,        "<<"|  CREDITS: "<<credits<<endl;
                    cout<<setw(12)           <<"|"<<"  radioactive zones, etc. It is also        "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  resistant to bullets and other physical   "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  trauma.                                   "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Back                                  "<<"|"<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>inventoryInput;

                    if(inventoryInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        inventoryInput=" ";
                        text1=" ";
                        break;
                    }
                }
            }
            if(inventoryInput=="2") {

                while (true) {

                    text1="Type 'back' to return to the";
                    text2="main inventory screen";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                    INVENTORY               "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  The A81 blaster is commonly utilized by   "<<"|  HP:      "<<health<<endl;
                    cout<<setw(12)           <<"|"<<"  the Solar Empire's police and rarely by   "<<"|  SHIELDS: "<<shields  <<endl;
                    cout<<setw(12)           <<"|"<<"  the military. The weapon has two modes:   "<<"|  AMMO:    "<<ammo<<endl;
                    cout<<setw(12)           <<"|"<<"  non lethal, which doesn't use up bullets  "<<"|  CREDITS: "<<credits<<endl;
                    cout<<setw(12)           <<"|"<<"  and deals minimal damage. And lethal      "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  which deals damage and uses bullets       "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  (You have: "<<ammo<<" bullets)                     "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Back                                  "<<"|"<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>inventoryInput;

                    if(inventoryInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        inventoryInput=" ";
                        text1=" ";
                        break;
                    }
                }
            }
            if(inventoryInput=="3") {

                while (true) {

                    text1="Type 'back' to return to the";
                    text2="main inventory screen";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                    INVENTORY               "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"   Scrap metal is the term used to describe "<<"|  HP:      "<<health<<endl;
                    cout<<setw(12)           <<"|"<<"  all sorts of broken parts found aboard    "<<"|  SHIELDS: "<<shields  <<endl;
                    cout<<setw(12)           <<"|"<<"  the SE Light Control. These parts can be  "<<"|  AMMO:    "<<ammo<<endl;
                    cout<<setw(12)           <<"|"<<"  sold at the store for credits             "<<"|  CREDITS: "<<credits<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  (You have: "<<scrapMetal<<" scrap metal)                 "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Back                                  "<<"|"<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>inventoryInput;

                    if(inventoryInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        inventoryInput=" ";
                        text1=" ";
                        break;
                    }
                }
            }
            if (inventoryInput=="4") {

                while (true) {

                    text1="Type 'back' to return to the";
                    text2="main inventory screen";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                    INVENTORY               "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     Valuable parts is a term used to       "<<"|  HP:      "<<health<<endl;
                    cout<<setw(12)           <<"|"<<"  describe all sorts of valuable parts of   "<<"|  SHIELDS: "<<shields  <<endl;
                    cout<<setw(12)           <<"|"<<"  machanisms aboard the SE Light Control.   "<<"|  AMMO:    "<<ammo<<endl;
                    cout<<setw(12)           <<"|"<<"  They can be sold at the store for credits "<<"|  CREDITS: "<<credits<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"  (You have: "<<valuableParts<<" valuable parts)              "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Back                                  "<<"|"<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>inventoryInput;

                    if(inventoryInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        inventoryInput=" ";
                        text1=" ";
                        break;
                    }
                }
            }
            if (inventoryInput=="5") {

                while (true) {

                    text1="Type 'back' to return to the";
                    text2="main inventory screen";
                    text3="Type 'use' to use a health pack";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                    INVENTORY               "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     Health packs are used to undo any      "<<"|  HP:      "<<health<<endl;
                    cout<<setw(12)           <<"|"<<"  physical trauma experienced aboard the    "<<"|  SHIELDS: "<<shields  <<endl;
                    cout<<setw(12)           <<"|"<<"  SE Light Control.                         "<<"|  AMMO:    "<<ammo<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|  CREDITS: "<<credits<<endl;
                    cout<<setw(12)           <<"|"<<"     >Use (You have: "<<healthPacks<<" health packs)        "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Back                                  "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;
                    cout<<setw(14)<<" "<<text3<<endl;

                    text4=" ";

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>inventoryInput;

                    if (inventoryInput=="use") {

                        if (healthPacks>0) {
                            if(health==maxHealth) {

                                text4="Your health is already full";
                            } else {
                                health=health+50;

                                healthPacks--;
                                healthPacksUsed++;

                                if (health>maxHealth) {
                                    health-=health-maxHealth;
                                }
                                text4="1 health pack used";
                            }
                        } else {
                            text4="You don't have any health packs";
                        }
                    }

                    if(inventoryInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        inventoryInput=" ";
                        text1=" ";
                        break;
                    }
                }
            }
            if (inventoryInput=="6") {
                while (true) {

                    text1="Type 'back' to return to the";
                    text2="main inventory screen";
                    text3="Type 'use' to use an armour boost";

                    cout<<"---------------------------------------------------------"<<endl;

                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                    INVENTORY               "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"--------------------------------------------"<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     Shield boosts are used to recharge the "<<"|  HP:      "<<health<<endl;
                    cout<<setw(12)           <<"|"<<"  armour's shields. They are rarely found   "<<"|  SHIELDS: "<<shields  <<endl;
                    cout<<setw(12)           <<"|"<<"  aboard research ships for the boosts are  "<<"|  AMMO:    "<<ammo<<endl;
                    cout<<setw(12)           <<"|"<<"  most frequently used by the Empire's      "<<"|  CREDITS: "<<credits<<endl;
                    cout<<setw(12)           <<"|"<<"  military.                                 "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Use (You have: "<<shieldBoosts<<" shield boosts)       "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"     >Back                                  "<<"|"<<endl;
                    cout<<setw(12)           <<"|"<<"                                            "<<"|"<<endl;
                    cout<<setw(14)<<" "<<text4<<endl;

                    cout<<"---------------------------------------------------------"<<endl;
                    cout<<setw(14)<<" "<<text1<<endl;
                    cout<<setw(14)<<" "<<text2<<endl;
                    cout<<setw(14)<<" "<<text3<<endl;

                    text4=" ";

                    cout<<endl;
                    cout<<"Action:"<<endl;
                    cin>>inventoryInput;

                    if (inventoryInput=="use") {

                        if (shieldBoosts>0) {
                            if(shields==maxShields) {

                                text4="Your shields are already full";
                            } else {
                                shields=shields+50;

                                shieldBoosts--;
                                shieldsBoostsUsed++;

                                if (shields>maxShields) {
                                    shields-=shields-maxShields;
                                }
                                text4="1 shield boost used";
                            }
                        } else {
                            text4="You don't have any shield boosts";
                        }
                    }
                    if(inventoryInput=="back") {
                        cout<<"Returning...."<<endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                        inventoryInput=" ";
                        text1=" ";
                        break;
                    }
                }
            }

            if(inventoryInput=="exit") {
                inventoryActive=false;
                cout<<"Closing inventory..."<<endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                inventoryInput=" ";
                text1=" ";
                text2=" ";
                text3=" ";
            }
        }
    }
}//inventory


void map() {

    cout<<right<<setw(17)              <<area[x-3][y+3].text<<"|"<<area[x-2][y+3].text<<"|"<<area[x-1][y+3].text<<"|"<<area[x][y+3].text<<"|"<<area[x+1][y+3].text<<"|"<<area[x+2][y+3].text<<"|"<<area[x+3][y+3].text<<endl;
    cout<<right<<setw(17)              <<area[x-3][y+2].text<<"|"<<area[x-2][y+2].text<<"|"<<area[x-1][y+2].text<<"|"<<area[x][y+2].text<<"|"<<area[x+1][y+2].text<<"|"<<area[x+2][y+2].text<<"|"<<area[x+3][y+2].text<<"    HP:      "<<health<<endl;
    cout<<right<<setw(17)              <<area[x-3][y+1].text<<"|"<<area[x-2][y+1].text<<"|"<<area[x-1][y+1].text<<"|"<<area[x][y+1].text<<"|"<<area[x+1][y+1].text<<"|"<<area[x+2][y+1].text<<"|"<<area[x+3][y+1].text<<"    SHIELDS: "<<shields  <<endl;
    cout<<right<<setw(17)              <<area[x-3][y].text  <<"|"<<area[x-2][y].text  <<"|"<<area[x-1][y].text  <<"|"<<area[x][y].text  <<"|"<<area[x+1][y].text  <<"|"<<area[x+2][y].text  <<"|"<<area[x+3][y].text <<endl;
    cout<<right<<setw(17)              <<area[x-3][y-1].text<<"|"<<area[x-2][y-1].text<<"|"<<area[x-1][y-1].text<<"|"<<area[x][y-1].text<<"|"<<area[x+1][y-1].text<<"|"<<area[x+2][y-1].text<<"|"<<area[x+3][y-1].text<<"    AMMO:    "<<ammo<<endl;
    cout<<right<<setw(17)              <<area[x-3][y-2].text<<"|"<<area[x-2][y-2].text<<"|"<<area[x-1][y-2].text<<"|"<<area[x][y-2].text<<"|"<<area[x+1][y-2].text<<"|"<<area[x+2][y-2].text<<"|"<<area[x+3][y-2].text<<"    CREDITS: "<<credits<<endl;

    cout<<"-------------------------------------------------------"<<endl;
    cout<<setw(12)<<" "<<text1<<endl;
    cout<<setw(12)<<" "<<text2<<endl;
    cout<<setw(12)<<" "<<text3<<endl;
    cout<<setw(12)<<" "<<text4<<endl;
    cout<<setw(12)<<" "<<text5<<endl;
    cout<<setw(12)<<" "<<text6<<endl;

}// map
