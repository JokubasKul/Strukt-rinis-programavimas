
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

extern string playerName, input, computerInput, emailInput, doorInput, storeInput, inventoryInput, combatInput, levelInput;
extern string text1, text2, text3, text4, text5, text6;

extern int x, y, location, health, maxHealth, shields, maxShields, ammo, damage, maxDamage, critChance, credits, healthPacks, shieldBoosts, eN, keycard, reactorCodes, shieldDamage, oldShields;
extern bool computerActive, storeActive, inventoryActive, firstAttack, visited0, visited1, visited2, visited3, visited4, visited5, visited6;
extern bool rechargeStation1Used, rechargeStation2Used;
extern bool door1Open, door1Returning, door2Returning, door3Open, door3Returning, door4Returning, door5Open, door5Returning, door6Open, door6Returning;
extern bool lootPackage1Used, lootPackage2Used, lootPackage3Used, lootPackage4Used, lootPackage5Used, lootPackage6Used, lootPackage7Used, lootPackage8Used, lootPackage9Used, lootPackage10Used, lootPackage11Used;
extern char passcode[4];
extern int healthPacksRemaining, shieldsBoostsRemaining, ammoRemaining;
extern int scrapMetal, valuableParts, exoticParts;
extern int itemsBought, itemsSold, healthPacksUsed, shieldsBoostsUsed, bulletsUsed, enemiesKilled, lootCratesOpened;
extern bool levelUp1, levelUp2, levelUp3, levelUp4;
extern int exp;

struct Area {
    string text;
    int status;
};

extern Area area[100][100];

struct enemies {
    string name;
    int health;
    int maxDamage;
    int critChance;
    int damage;
    int status;
    bool isAlive;
};

extern enemies enemy[50];


#endif
