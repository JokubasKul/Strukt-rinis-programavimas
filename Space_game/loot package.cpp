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
#include "loot_package.h"

using namespace std;

void loot_package_1() {

    if(input=="e") {
        if(lootPackage1Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage1Used==false) {
            text1="Obtained: 250 credits";

            credits=credits+250;

            lootPackage1Used=true;

            lootCratesOpened++;

            area[4][8].text="_";
            area[4][8].status=1;
        }
    }
}


void loot_package_2() {

    if(input=="e") {
        if(lootPackage2Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage2Used==false) {
            text1="Obtained: 3 blaster bullets";

            ammo=ammo+3;

            lootPackage2Used=true;

            lootCratesOpened++;

            area[8][11].text="_";
            area[8][11].status=1;
        }
    }
}


void loot_package_3() {

    if(input=="e") {
        if(lootPackage3Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage3Used==false) {
            text1="Obtained: 300 credits";

            credits=credits+300;

            lootPackage3Used=true;

            lootCratesOpened++;

            area[7][15].text="_";
            area[7][15].status=1;
        }
    }
}


void loot_package_4() {

    if(input=="e") {
        if(lootPackage4Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage4Used==false) {
            text1="Obtained: 1st door keycard and 1 shield boost";

            keycard++;
            shieldBoosts++;

            if (keycard==1) {
                text2="Two keycards remaining";
            } else if (keycard==2) {
                text2="One keycard remaining";
            } else if (keycard==3) {
                text2="All keycards collected, you can now";
                text3="unlock the door to the medbay";
            }

            lootPackage4Used=true;

            lootCratesOpened++;

            area[8][20].text="_";
            area[8][20].status=1;
        }
    }
}


void loot_package_5() {

    if(input=="e") {
        if(lootPackage5Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage5Used==false) {
            text1="Obtained: 2nd door keycard and 3 bullets";

            keycard++;
            ammo=ammo+3;

            if (keycard==1) {
                text2="Two keycards remaining";
            } else if (keycard==2) {
                text2="One keycard remaining";
            } else if (keycard==3) {
                text2="All keycards collected, you can now";
                text3="unlock the door to the medbay";
            }

            lootPackage5Used=true;

            lootCratesOpened++;

            area[18][4].text="_";
            area[18][4].status=1;
        }
    }
}


void loot_package_6() {

    if(input=="e") {
        if(lootPackage6Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage6Used==false) {
            text1="Obtained: 3rd door keycard";

            keycard++;

            if (keycard==1) {
                text2="Two keycards remaining";
            } else if (keycard==2) {
                text2="One keycard remaining";
            } else if (keycard==3) {
                text2="All keycards collected, you can now";
                text3="unlock the door to the medbay";
            }


            lootPackage6Used=true;

            lootCratesOpened++;

            area[12][5].text="_";
            area[12][5].status=1;
        }
    }
}


void loot_package_7() {

    if(input=="e") {
        if(lootPackage7Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage7Used==false) {
            text1="Obtained: 6 blaster bullets";

            ammo=ammo+6;

            lootPackage7Used=true;

            lootCratesOpened++;

            area[13][15].text="_";
            area[13][15].status=1;
        }
    }
}


void loot_package_8() {

    if(input=="e") {
        if(lootPackage8Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage8Used==false) {
            text1="Obtained: 3 pieces of scrap metal.";
            text2="They can be sold at the store for credits";

            scrapMetal=scrapMetal+3;

            lootPackage8Used=true;

            lootCratesOpened++;

            area[14][16].text="_";
            area[14][16].status=1;
        }
    }
}


void loot_package_9() {

    if(input=="e") {
        if(lootPackage9Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage9Used==false) {
            text1="Obtained: 2 valuable parts";
            text2="It can be sold at the store for credits";

            valuableParts=valuableParts+2;

            lootPackage9Used=true;

            lootCratesOpened++;

            area[31][5].text="_";
            area[31][5].status=1;
        }
    }
}


void loot_package_10() {

    if(input=="e") {
        if(lootPackage10Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage10Used==false) {
            text1="Obtained: reactor activation codes and 1 health pack";

            reactorCodes++;

            lootPackage10Used=true;

            lootCratesOpened++;

            area[29][4].text="_";
            area[29][4].status=1;
        }
    }
}


void loot_package_11() {

    if(input=="e") {
        if(lootPackage11Used==true) {
            text1="This loot package is empty";
        }
        if(lootPackage11Used==false) {
            text1="Obtained: 10 ammo, 2 health packs";

            ammo=ammo+10;
            healthPacks=healthPacks+2;

            lootPackage11Used=true;

            lootCratesOpened++;

            area[10][4].text="_";
            area[10][4].status=1;
        }
    }
}

