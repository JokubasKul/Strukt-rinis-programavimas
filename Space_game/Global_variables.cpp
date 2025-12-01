#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "global_variables.h"

using namespace std;

string playerName, input, computerInput, emailInput, doorInput, storeInput, inventoryInput, combatInput, levelInput;
string text1, text2, text3, text4, text5, text6;
int x=8, y=5, location=0, health=100, maxHealth=100, shields=50, maxShields=50, ammo=0, damage, maxDamage=5, critChance=20, credits=0, healthPacks=0, shieldBoosts=0, eN, keycard=0, reactorCodes, shieldDamage=0, oldShields;
bool computerActive=false, storeActive=false, inventoryActive=false, firstAttack=true, visited0=false, visited1=false, visited2=false, visited3=false, visited4=false, visited5=false, visited6=false;
bool rechargeStation1Used=false, rechargeStation2Used=false;
bool door1Open=false, door1Returning, door2Returning=false, door3Open=false, door3Returning=false, door4Returning=false, door5Open=false, door5Returning=false, door6Open, door6Returning=false;
bool lootPackage1Used=false, lootPackage2Used=false, lootPackage3Used=false, lootPackage4Used=false, lootPackage5Used=false, lootPackage6Used=false, lootPackage7Used=false, lootPackage8Used=false, lootPackage9Used=false, lootPackage10Used=false, lootPackage11Used=false;
char passcode[4];
int healthPacksRemaining=9, shieldsBoostsRemaining=9, ammoRemaining=9;
int scrapMetal=0, valuableParts=0, exoticParts=0;
int itemsBought=0, itemsSold=0, healthPacksUsed=0, shieldsBoostsUsed=0, bulletsUsed=0, enemiesKilled=0, lootCratesOpened=0;
bool levelUp1=false, levelUp2=false, levelUp3=false, levelUp4=false;
int exp;

Area area[100][100];

enemies enemy[50];