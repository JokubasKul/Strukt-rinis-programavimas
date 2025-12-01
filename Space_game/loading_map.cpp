#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#include "global_variables.h"
#include "loading_map.h"

using namespace std;

void loading_map_0() {


    for(int x=1; x<=3; x++) {
        for(int y=1; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int x=1; x<=15; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int x=13; x<=15; x++) {
        for(int y=1; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int x=4; x<=12; x++) {
        for(int y=16; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }

    for(int x=4; x<=12; x++) {
        for(int y=4; y<=15; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    for(int x=5; x<=6; x++) {
        for(int y=8; y<=9; y++) {
            area[x][y].text="C";
            area[x][y].status=2;
        }
    }
    for(int x=10; x<=11; x++) {
        for(int y=8; y<=9; y++) {
            area[x][y].text="C";
            area[x][y].status=2;
        }
    }

    if (visited0==false) {
        area[8][5].text="P";
    }

    area[5][12].text="D";
    area[5][12].status=4;
    area[7][12].text="D";
    area[7][12].status=4;

    area[6][12].text="@";
    area[6][12].status=5;

    area[9][16].text="T";
    area[9][16].status=6;

    area[3][6].text="?";
    area[3][6].status=11;

} //loading_map_0


void loading_map_1() {

    x=6, y=5;

    for(int x=1; x<=11; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int x=1; x<=3; x++) {
        for(int y=1; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int x=4; x<=11; x++) {
        for(int y=16; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int x=9; x<=11; x++) {
        for(int y=4; y<=15; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }

    for(int x=4; x<=8; x++) {
        for(int y=4; y<=15; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    if (visited1==false) {
        area[6][5].text="P";
    }

    area[5][6].text="C"; area[7][6].text="C"; area[5][10].text="C"; area[7][10].text="C"; area[4][14].text="C"; area[5][14].text="C"; area[7][14].text="C"; area[8][14].text="C";
    area[5][6].status=2; area[7][6].status=2; area[5][10].status=2; area[7][10].status=2; area[4][14].status=2; area[5][14].status=2; area[7][14].status=2; area[8][14].status=2;

    if (lootPackage1Used==false) {
        area[4][8].text="L";
        area[4][8].status=9;
    }
    if (lootPackage2Used==false) {
        area[8][11].text="L";
        area[8][11].status=9;
    }

    if (enemy[1].isAlive==true) {
        area[6][13].text="#";
        area[6][13].status=10;
    }

    area[6][3].text="T";
    area[6][3].status=6;

    area[6][16].text="T";
    area[6][16].status=6;


}//loading_map_1


void loading_map_2() {


    for (int x=1; x<=13; x++) {
        for(int y=8; y<=10; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=11; x<=13; x++) {
        for(int y=1; y<=7; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=14; x<=21; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=19; x<=21; x++) {
        for(int y=4; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=18; x++) {
        for(int y=16; y<=18; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=3; x++) {
        for(int y=11; y<=15; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }

    for (int x=4; x<=18; x++) {
        for(int y=11; y<=15; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }
    for (int x=14; x<=18; x++) {
        for(int y=4; y<=10; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    if (lootPackage3Used==false) {
        area[7][15].text="L";
        area[7][15].status=9;
    }

    area[18][13].text="S";
    area[18][13].status=7;

    area[5][10].text="T";  area[16][3].text="T";
    area[5][10].status=6;  area[16][3].status=6;

    if (enemy[2].isAlive==true) {
        area[16][6].text="#";
        area[16][6].status=10;
    }

    if (visited2==false) {
        x=5, y=12;
        area[5][12].text="P";
    }

}


void loading_map_3() {


    for (int x=4; x<=21; x++) {
        for(int y=4; y<=20; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    for (int x=1; x<=20; x++) {
        for(int y=21; y<=23; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=18; x<=20; x++) {
        for(int y=15; y<=20; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for(int y=15; y<=17; y++) {
        area[21][y].text="+";
        area[21][y].status=3;
    }
    for (int x=22; x<=24; x++) {
        for(int y=1; y<=17; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=7; x<=21; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=7; x<=9; x++) {
        for(int y=4; y<=11; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=6; x++) {
        for(int y=9; y<=11; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=3; x++) {
        for(int y=12; y<=20; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=9; x<=12; x++) {
        for(int y=15; y<=20; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=15; x<=17; x++) {
        for(int y=4; y<=11; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }

    if (lootPackage7Used==false) {
        area[13][15].text="L";
        area[13][15].status=9;
    }

    if (lootPackage5Used==false) {
        area[18][4].text="L";
        area[18][4].status=9;
    }

    if (lootPackage6Used==false) {
        area[12][5].text="L";
        area[12][5].status=9;
    }

    if (lootPackage4Used==false) {
        area[8][20].text="L";
        area[8][20].status=9;
    }

    area[15][21].text="T";  area[3][13].text="T";  area[22][13].text="T";
    area[15][21].status=6;  area[3][13].status=6;  area[22][13].status=6;

    area[4][15].text="C";  area[8][15].text="C";  area[10][11].text="C";  area[14][11].text="C";  area[18][11].text="C";  area[21][11].text="C";
    area[4][15].status=2;  area[8][15].status=2;  area[10][11].status=2;  area[14][11].status=2;  area[18][11].status=2;  area[21][11].status=2;

    area[4][19].text="D";  area[6][19].text="D";  area[19][6].text="D";  area[21][6].text="D";
    area[4][19].status=4;  area[6][19].status=4;  area[19][6].status=4;  area[21][6].status=4;

    area[20][11].text="?";  area[7][15].text="?";  area[3][12].text="?";
    area[20][11].status=11; area[7][15].status=11; area[3][12].status=11;

    if (enemy[3].isAlive==true) {
        area[6][17].text="#";
        area[6][17].status=10;
    }

    if (enemy[7].isAlive==true) {
        area[12][8].text="#";
        area[12][8].status=10;
    }

    area[18][9].text="R";
    area[18][9].status=8;

    area[5][19].text="@";  area[20][6].text="@";
    area[5][19].status=5;  area[20][6].status=5;

    if (visited3==false) {
        x=15; y=19;
        area[15][19].text="P";
    }

}


void loading_map_4() {

    for (int x=1; x<=32; x++) {
        for(int y=4; y<=17; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    for (int x=1; x<=12; x++) {
        for(int y=4; y<=6; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=10; x<=35; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=33; x<=35; x++) {
        for(int y=4; y<=20; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=10; x<=32; x++) {
        for(int y=18; y<=20; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=10; x<=12; x++) {
        for(int y=12; y<=17; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=9; x++) {
        for(int y=12; y<=14; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=3; x++) {
        for(int y=7; y<=11; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=16; x<=18; x++) {
        for(int y=8; y<=10; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=21; x<=23; x++) {
        for(int y=4; y<=6; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=21; x<=23; x++) {
        for(int y=12; y<=17; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }


    area[3][9].text="T";  area[16][9].text="T";
    area[3][9].status=6;  area[16][9].status=6;

    area[6][7].text="C";  area[12][7].text="C";  area[6][11].text="C";  area[12][11].text="C";  area[22][11].text="C";  area[22][7].text="C";
    area[6][7].status=2;  area[12][7].status=2;  area[6][11].status=2;  area[12][11].status=2;  area[22][11].status=2; area[22][7].status=2;

    area[17][15].text="D";  area[19][15].text="D";  area[25][5].text="D";  area[27][5].text="D";  area[31][14].text="D";  area[31][16].text="D";
    area[17][15].status=4;  area[19][15].status=4;  area[25][5].status=4;  area[27][5].status=4;  area[31][14].status=4;  area[31][16].status=4;

    if (lootPackage8Used==false) {
        area[14][16].text="L";
        area[14][16].status=9;
    }
    if (lootPackage9Used==false) {
        area[31][5].text="L";
        area[31][5].status=9;
    }
    if (lootPackage10Used==false) {
        area[29][4].text="L";
        area[29][4].status=9;
    }

    area[18][15].text="@";  area[26][5].text="@";  area[31][15].text="@";
    area[18][15].status=5;  area[26][5].status=5;  area[31][15].status=5;

    if (enemy[4].isAlive==true) {
        area[23][9].text="#";
        area[23][9].status=10;
    }
    if (enemy[10].isAlive==true) {
        area[28][13].text="#";
        area[28][13].status=10;
    }

    area[6][10].text="?";  area[24][13].text="?";  area[32][9].text="?";
    area[6][10].status=11; area[24][13].status=11; area[32][9].status=11;

    if (visited4==false) {
        x=5; y=9;
        area[5][9].text="P";
    }

    area[15][4].text="S";
    area[15][4].status=7;


}//loading_map_4


void loading_map_5() {

    for (int x=4; x<=9; x++) {
        for(int y=4; y<=10; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    for (int x=1; x<=12; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=10; x<=12; x++) {
        for(int y=4; y<=13; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=9; x++) {
        for(int y=11; y<=13; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=3; x++) {
        for(int y=4; y<=10; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }

    for(int y=6; y<=8; y++) {
        area[3][y].text="3";
        area[3][y].status=12;
    }

    area[10][7].text="T";
    area[10][7].status=6;

    area[4][7].text="@";
    area[4][7].status=5;

    if (visited5==false) {
        area[8][7].text="P";
        x=8, y=7;
    }

}//loading_map_5


void loading_map_6() {
    for (int x=4; x<=11; x++) {
        for(int y=4; y<=10; y++) {
            area[x][y].text="_";
            area[x][y].status=1;
        }
    }

    for (int x=1; x<=14; x++) {
        for(int y=1; y<=3; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=12; x<=14; x++) {
        for(int y=4; y<=13; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=11; x++) {
        for(int y=11; y<=13; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }
    for (int x=1; x<=3; x++) {
        for(int y=4; y<=10; y++) {
            area[x][y].text="+";
            area[x][y].status=3;
        }
    }

    if (lootPackage11Used==false) {
        area[10][4].text="L";
        area[10][4].status=9;
    }

    area[12][7].text="T";
    area[12][7].status=6;

    area[4][7].text="@";
    area[4][7].status=5;

    if (enemy[15].isAlive==true) {
        area[6][7].text="#";
        area[6][7].status=10;
    }

    if (visited6==false) {
        area[10][7].text="P";
        x=10, y=7;
    }

    area[4][8].text="D";  area[4][6].text="D";
    area[4][8].status=4;  area[4][6].status=4;

    area[9][10].text="R";
    area[9][10].status=8;

}//loading_map_6


