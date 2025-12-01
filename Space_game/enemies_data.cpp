#include "enemies_data.h"
#include "Global_variables.h"

void enemies_data() {

    enemy[1].status=1;
    enemy[2].status=1;
    enemy[3].status=1;
    enemy[4].status=1;
    enemy[5].status=1;
    enemy[6].status=2;
    enemy[7].status=2;
    enemy[8].status=2;
    enemy[9].status=2;
    enemy[10].status=3;
    enemy[11].status=3;
    enemy[12].status=3;
    enemy[13].status=3;
    enemy[14].status=4;
    enemy[15].status=5;

    for(int i=1; i<=20; i++) {
        if(enemy[i].status==1) {
            enemy[i].name="Fungal growth";
            enemy[i].health=20;
            enemy[i].maxDamage=10;
            enemy[i].critChance=20;
            enemy[i].isAlive=true;
        }
        if(enemy[i].status==2) {
            enemy[i].name="Corrupted passenger";
            enemy[i].health=40;
            enemy[i].maxDamage=16;
            enemy[i].critChance=20;
            enemy[i].isAlive=true;
        }
        if(enemy[i].status==3) {
            enemy[i].name="Corrupted guard";
            enemy[i].health=60;
            enemy[i].maxDamage=22;
            enemy[i].critChance=30;
            enemy[i].isAlive=true;
        }
        if(enemy[i].status==4) {
            enemy[i].name="Mad scientist";
            enemy[i].health=50;
            enemy[i].maxDamage=10;
            enemy[i].critChance=20;
            enemy[i].isAlive=true;
        }
        if(enemy[i].status==5) {
            enemy[i].name="Fungal abomination";
            enemy[i].health=70;
            enemy[i].maxDamage=25;
            enemy[i].critChance=20;
            enemy[i].isAlive=true;
        }
    }
}