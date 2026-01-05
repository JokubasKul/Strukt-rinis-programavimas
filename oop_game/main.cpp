#include <iostream>
#include <iomanip>
#include <conio.h>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

string input;
int location=0;//0

class Text {

    string text1, text2, text3, text4, text5, text6;

public:

    void setMessage(int line, const string& text) {
        if (line == 1) {
            text1 = text;
        }
        else if (line == 2) {
            text2 = text;
        }
        else if (line == 3) {
            text3 = text;
        }
        else if (line == 4) {
            text4 = text;
        }
        else if (line == 5) {
            text5 = text;
        }
        else if (line == 6) {
            text6 = text;
        }
    }

    void displayMessage(int line) {
        if (line == 1) {
            cout << setw(31) << " " << text1 << endl;
        }
        else if (line == 2) {
            cout << setw(31) << " " << text2 << endl;
        }
        else if (line == 3) {
            cout << setw(31) << " " << text3 << endl;
        }
        else if (line == 4) {
            cout << setw(31) << " " << text4 << endl;
        }
        else if (line == 5) {
            cout << setw(31) << " " << text5 << endl;
        }
        else if (line == 6) {
            cout << setw(31) << " " << text6 << endl;
        }
    }

    void clearMessage() {
        text1 = " ";
        text2 = " ";
        text3 = " ";
        text4 = " ";
        text5 = " ";
        text6 = " ";
    }
};


class Area_Info {

protected:

    Text& UI;

    int x, y;

    struct Area {
        string text;
        int status;
    };


    Area area[100][100];

public:

    Area_Info(Text& t): UI(t) {}

    int X() {
        return this->x;
    }
    int Y() {
        return this->y;
    }

    string getAreaText(int x, int y) {
        return area[x][y].text;
    }
    int getAreaStatus(int x, int y) {
        return area[x][y].status;
    }

    void setArea(int x, int y, string text, int status) {
        this->area[x][y].text=text;
        this->area[x][y].status=status;
    }

    void clearMap() {
        for (int x=0; x < 100; x++) {
            for (int y=0; y < 100; y++) {
                area[x][y].text="_";
                area[x][y].status=1;
            }
        }
        area[50][50].text="P";
        x=50, y=50;
    }

    void setPlayerCharacter(int x1, int y1) {
        area[x1][y1].text="P";

        x=x1, y=y1;
    }


    void loading_map_0() {

        for (int x = 1; x <= 11; x++) {
            for (int y = 1; y <= 3; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 1; x <= 3; x++) {
            for (int y = 1; y <= 20; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 4; x <= 11; x++) {
            for (int y = 18; y <= 20; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 9; x <= 11; x++) {
            for (int y = 4; y <= 17; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }

        for (int x = 4; x <= 8; x++) {
            for (int y = 4; y <= 17; y++) {
                area[x][y].text = "_";
                area[x][y].status = 1;
            }
        }

        area[4][10].text="0";
        area[4][10].status=3;
        area[5][10].text="0";
        area[5][10].status=3;
        area[7][10].text="0";
        area[7][10].status=3;
        area[8][10].text="0";
        area[8][10].status=3;
    }

    void loading_map_1() {

        for (int x = 1; x <= 19; x++) {
            for (int y = 1; y <= 4; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 1; x <= 6; x++) {
            for (int y = 1; y <= 19; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 5; x <= 19; x++) {
            for (int y = 16; y <= 19; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 14; x <= 19; x++) {
            for (int y = 5; y <= 15; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }

        for (int x = 7; x <= 13; x++) {
            for (int y = 5; y <= 15; y++) {
                area[x][y].text = "_";
                area[x][y].status = 1;
            }
        }

        for (int x = 12; x <= 13; x++) {
            for (int y = 7; y <= 8; y++) {
                area[x][y].text = "0";
                area[x][y].status = 3;
            }
        }
        for (int x = 7; x <= 8; x++) {
            for (int y = 11; y <= 12; y++) {
                area[x][y].text = "0";
                area[x][y].status = 3;
            }
        }
    }

    void loading_map_2() {
        for (int x = 1; x <= 11; x++) {
            for (int y = 1; y <= 3; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 1; x <= 3; x++) {
            for (int y = 4; y <= 19; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 4; x <= 11; x++) {
            for (int y = 17; y <= 19; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 9; x <= 15; x++) {
            for (int y = 13; y <= 15; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 13; x <= 15; x++) {
            for (int y = 7; y <= 12; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 9; x <= 12; x++) {
            for (int y = 7; y <= 9; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 9; x <= 11; x++) {
            for (int y = 4; y <= 6; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        area[9][16].text = "+";
        area[9][16].status = 2;
        area[10][16].text = "+";
        area[10][16].status = 2;
        area[11][16].text = "+";
        area[11][16].status = 2;

        area[9][10].text = "+";
        area[9][10].status = 2;
        area[9][12].text = "+";
        area[9][12].status = 2;

        for (int x = 4; x <= 8; x++) {
            for (int y = 4; y <= 16; y++) {
                area[x][y].text = "_";
                area[x][y].status = 1;
            }
        }
        for (int x = 10; x <= 12; x++) {
            for (int y = 10; y <= 12; y++) {
                area[x][y].text = "_";
                area[x][y].status = 1;
            }
        }
    }

    void loading_map_3() {

        clearMap();

        for (int x = 1; x <= 24; x++) {
            for (int y = 1; y <= 3; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 1; x <= 3; x++) {
            for (int y = 4; y <= 19; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 4; x <= 6; x++) {
            for (int y = 17; y <= 19; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 7; x <= 9; x++) {
            for (int y = 6; y <= 24; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 10; x <= 24; x++) {
            for (int y = 22; y <= 24; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 22; x <= 24; x++) {
            for (int y = 1; y <= 21; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 19; x <= 21; x++) {
            for (int y = 16; y <= 18; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 10; x <= 20; x++) {
            for (int y = 10; y <= 12; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 15; x <= 17; x++) {
            for (int y = 6; y <= 21; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        area[4][6].text = "0";
        area[4][6].status = 3;
        area[6][6].text = "0";
        area[6][6].status = 3;
        area[10][6].text = "0";
        area[10][6].status = 3;
        area[14][6].text = "0";
        area[14][6].status = 3;

        area[12][10].text = "_";
        area[12][10].status = 1;
        area[12][11].text = "_";
        area[12][11].status = 1;
        area[12][12].text = "_";
        area[12][12].status = 1;
    }

    void loading_map_4() {
        clearMap();
        for (int x = 1; x <= 9; x++) {
            for (int y = 1; y <= 3; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 1; x <= 3; x++) {
            for (int y = 4; y <= 21; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 4; x <= 20; x++) {
            for (int y = 19; y <= 21; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 18; x <= 20; x++) {
            for (int y = 16; y <= 18; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 7; x <= 20; x++) {
            for (int y = 13; y <= 15; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 7; x <= 9; x++) {
            for (int y = 4; y <= 12; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
    }

    void loading_map_5() {
        clearMap();
        for (int x = 1; x <= 15; x++) {
            for (int y = 1; y <= 3; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 1; x <= 3; x++) {
            for (int y = 4; y <= 15; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 7; x <= 9; x++) {
            for (int y = 7; y <= 15; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 4; x <= 6; x++) {
            for (int y = 13; y <= 24; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 7; x <= 18; x++) {
            for (int y = 22; y <= 24; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 16; x <= 18; x++) {
            for (int y = 13; y <= 21; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }
        for (int x = 13; x <= 15; x++) {
            for (int y = 4; y <= 15; y++) {
                area[x][y].text = "+";
                area[x][y].status = 2;
            }
        }

    }

    void movement() {                             //1 = walkable
                                                  //2 = + wall
        if (input == "w") {                       //3 = 0 wall
            area[x][y].text = "_";                //4 = door
            y++;                                  //5 = loot
            area[x][y].text = "P";                //6 = POI
            if (area[x][y].status == 6) {
                area[x][y].text = "?";
                y--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a point of interest");
                return;
            }
            if (area[x][y].status == 5) {
                area[x][y].text = "L";
                y--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a loot crate");
                return;
            }
            if (area[x][y].status == 4) {
                area[x][y].text = "D";
                y--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a door");
                return;
            }
            if (area[x][y].status == 3) {
                area[x][y].text = "0";
                y--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 2) {
                area[x][y].text = "+";
                y--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 1) {
                UI.clearMessage();
            }
        }
        if (input == "d") {
            area[x][y].text = "_";
            x++;
            area[x][y].text = "P";
            if (area[x][y].status == 6) {
                area[x][y].text = "?";
                x--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a point of interest");
                return;
            }
            if (area[x][y].status == 5) {
                area[x][y].text = "L";
                x--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a loot crate");
                return;
            }
            if (area[x][y].status == 4) {
                area[x][y].text = "D";
                x--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a door");
                return;
            }
            if (area[x][y].status == 3) {
                area[x][y].text = "0";
                x--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 2) {
                area[x][y].text = "+";
                x--;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 1) {
                UI.clearMessage();
            }
        }
        if (input == "a") {
            area[x][y].text = "_";
            x--;
            area[x][y].text = "P";
            if (area[x][y].status == 6) {
                area[x][y].text = "?";
                x++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a point of interest");
                return;
            }
            if (area[x][y].status == 5) {
                area[x][y].text = "L";
                x++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a loot crate");
                return;
            }
            if (area[x][y].status == 4) {
                area[x][y].text = "D";
                x++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a door");
                return;
            }
            if (area[x][y].status == 3) {
                area[x][y].text = "0";
                x++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 2) {
                area[x][y].text = "+";
                x++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 1) {
                UI.clearMessage();
            }
        }
        if (input == "s") {
            area[x][y].text = "_";
            y--;
            area[x][y].text = "P";
            if (area[x][y].status == 6) {
                area[x][y].text = "?";
                y++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a point of interest");
                return;
            }
            if (area[x][y].status == 5) {
                area[x][y].text = "L";
                y++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a loot crate");
                return;
            }
            if (area[x][y].status == 4) {
                area[x][y].text = "D";
                y++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a door");
                return;
            }
            if (area[x][y].status == 3) {
                area[x][y].text = "0";
                y++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 2) {
                area[x][y].text = "+";
                y++;
                area[x][y].text = "P";
                UI.setMessage(1, "This is a wall");
                return;
            }
            if (area[x][y].status == 1) {
                UI.clearMessage();
            }
        }
    }
};


class Player_Info {

    string playerName="";
    int playerHealth = 100;     //100
    int playerMaxHealth = 100;  //100
    int coins = 0;
    int playerDefense = 20;     //20
    int playerMaxDefense = 20;  //20
    int playerMana = 50;        //50
    int playerMaxMana = 80;     //80

public:

    void setPlayerName(string name) {
        this->playerName = name;
    }
    void setPlayerHealth(int health) {
        this->playerHealth = health;
    }
    void setPlayerMaxHealth(int maxHealth) {
        this->playerMaxHealth = maxHealth;
    }
    void setCoins(int coins) {
        this->coins = coins;
    }
    void setPlayerDefense(int playerDefense) {
        this->playerDefense = playerDefense;
    }
    void setPlayerMaxDefense(int playerMaxDefense) {
        this->playerMaxDefense = playerMaxDefense;
    }
    void setPlayerMana(int playerMana) {
        this->playerMana = playerMana;
    }
    void setPlayerMaxMana(int playerMaxMana) {
        this->playerMaxMana = playerMaxMana;
    }

    string getPlayerName() {
        return this->playerName;
    }
    int getPlayerHealth() {
        return this->playerHealth;
    }
    int getPlayerMaxHealth() {
        return this->playerMaxHealth;
    }
    int getCoins() {
        return this->coins;
    }
    int getPlayerDefense() {
        return this->playerDefense;
    }
    int getPlayerMaxDefense() {
        return this->playerMaxDefense;
    }
    int getPlayerMana() {
        return this->playerMana;
    }
    int getPlayerMaxMana() {
        return this->playerMaxMana;
    }
};


class Enemy_Info {

    string enemyName;
    int enemyHealth=0;
    int enemyDamage=0;
    int enemyDefense=0;

    public:

    string getEnemyName() {
        return this->enemyName;
    }
    int getEnemyHealth() {
        return this->enemyHealth;
    }
    int getEnemyDamage() {
        return this->enemyDamage;
    }
    int getEnemyDefense() {
        return this->enemyDefense;
    }

    void setEnemyName(string a) {
        this->enemyName=a;
    }
    void setEnemyHealth(int a) {
        this->enemyHealth=a;
    }
    void setEnemyDamage(int a) {
        this->enemyDamage=a;
    }
    void setEnemyDefense(int a) {
        this->enemyDefense=a;
    }
};


class Opening {

    protected:

    Player_Info& playerR;

    string name;

    public:

    Opening(Player_Info& p): playerR(p) {}

    void playOpening() {
        cout<<"                    Long ago The Kingdom of Generica was prosperous,"<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout<<"                    the kingdom was home to many great wizards who guarded its borders."<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout<<"                    But one night a group of twisted individuals opened the portal to the abyss,"<<endl;
        this_thread::sleep_for(chrono::milliseconds(3500));
        cout<<"                    an unspeakable abomination rose from the portal, corrupted the minds of all who heard its calling."<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(4000));
        cout<<"                    First it corrupted The Fire King and his armies. The king's mad soldiers"<<endl;
        cout<<"                    began capturing wizards and feeding them to their master"<<endl;
        this_thread::sleep_for(chrono::milliseconds(4500));
        cout<<endl;
        cout<<"                    You are next"<<endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        whatIsYourName();
    }
    void whatIsYourName() {
        system("cls");
        cout<<"                      What is your name?"<<endl;
        cin>>name;
        playerR.setPlayerName(name);
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout<<"                "<<name<<", escape your fate"<<endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
    }
};


class Epilogue {

    protected:

    Player_Info& playerR;

    public:

    Epilogue(Player_Info& p): playerR(p) {}

    void playEpilogue() {
        cout<<"                    At long last, the abyss creature has been defeated"<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout<<"                    The legend of "<<playerR.getPlayerName()<<" shall live on for eons ahead"<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout<<"                    Even though the creature has caused terrible damage upon this once beautiful land"<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(4000));
        cout<<"                    We can rebuild"<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(8000));
        exit(0);
    }
};


class skeletonAnimation {

protected:

    Player_Info& playerR;
    Enemy_Info& enemyR;

public:

    skeletonAnimation(Player_Info& p, Enemy_Info& e): playerR(p), enemyR(e) {}

    void idle() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                        |-----|         |"<<endl;
        cout<<"|       /____\\                               |       |*  * |         |"<<endl;
        cout<<"|       |     |                              |       |_____|         |"<<endl;
        cout<<"|       |-----|                              |      ____|____        |"<<endl;
        cout<<"|         /|\\                                |     | ___|___ |       |"<<endl;
        cout<<"|        / | \\                              _|_    |  __|__  |       |"<<endl;
        cout<<"|       /  |  \\                              |_____|    |    |       |"<<endl;
        cout<<"|      /   |   \\                             o       ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }

    void enemyAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                |                        |"<<endl;
        cout<<"|        /  \\                               |        |-----|         |"<<endl;
        cout<<"|       /____\\                              |        |*  * |         |"<<endl;
        cout<<"|       |     |                             |        |_____|         |"<<endl;
        cout<<"|       |-----|                            _|_      ____|____        |"<<endl;
        cout<<"|         /|\\                               |      | ___|___ |       |"<<endl;
        cout<<"|        / | \\                              o______|  __|__  |       |"<<endl;
        cout<<"|       /  |  \\                                         |    |       |"<<endl;
        cout<<"|      /   |   \\                                     ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                     /                   |"<<endl;
        cout<<"|        /  \\                                   /    |-----|         |"<<endl;
        cout<<"|       /____\\                                 /     |*  * |         |"<<endl;
        cout<<"|       |     |                               /      |_____|         |"<<endl;
        cout<<"|       |-----|                              /      ____|____        |"<<endl;
        cout<<"|         /|\\                              -/-     | ___|___ |       |"<<endl;
        cout<<"|        / | \\                             o-______|  __|__  |       |"<<endl;
        cout<<"|       /  |  \\                                         |    |       |"<<endl;
        cout<<"|      /   |   \\                                     ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                |                        |"<<endl;
        cout<<"|        /  \\                               |        |-----|         |"<<endl;
        cout<<"|       /____\\                              |        |*  * |         |"<<endl;
        cout<<"|       |     |                             |        |_____|         |"<<endl;
        cout<<"|       |-----|                            _|_      ____|____        |"<<endl;
        cout<<"|         /|\\                               |      | ___|___ |       |"<<endl;
        cout<<"|        / | \\                              o______|  __|__  |       |"<<endl;
        cout<<"|       /  |  \\                                         |    |       |"<<endl;
        cout<<"|      /   |   \\                                     ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                          \\                              |"<<endl;
        cout<<"|        /  \\                          \\             |-----|         |"<<endl;
        cout<<"|       /____\\                          \\            |*  * |         |"<<endl;
        cout<<"|       |     |                          \\           |_____|         |"<<endl;
        cout<<"|       |-----|                           \\         ____|____        |"<<endl;
        cout<<"|         /|\\                             -\\-      | ___|___ |       |"<<endl;
        cout<<"|        / | \\                              o______|  __|__  |       |"<<endl;
        cout<<"|       /  |  \\                                         |    |       |"<<endl;
        cout<<"|      /   |   \\                                     ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\  x                       \\                              |"<<endl;
        cout<<"|        /  \\ x                        \\             |-----|         |"<<endl;
        cout<<"|       /____\\ x                        \\            |*  * |         |"<<endl;
        cout<<"|       | x    | x                       \\           |_____|         |"<<endl;
        cout<<"|      x|-x----|x                         \\         ____|____        |"<<endl;
        cout<<"|      x  /|\\  x                          -\\-      | ___|___ |       |"<<endl;
        cout<<"|      x /|x \\ x                            o______|  __|__  |       |"<<endl;
        cout<<"|    x  /x|x  \\                                         |    |       |"<<endl;
        cout<<"|      /  x|   \\x                                    ___|___         |"<<endl;
        cout<<"|        x |___                                      |     |         |"<<endl;
        cout<<"|         / x  |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\  x                       \\                              |"<<endl;
        cout<<"|     x  /x \\ x                        \\             |-----|         |"<<endl;
        cout<<"|       /____\\ x                        \\            |*  * |         |"<<endl;
        cout<<"|     x | x   x| x                       \\           |_____|         |"<<endl;
        cout<<"|      x|-x----|x  x                      \\         ____|____        |"<<endl;
        cout<<"|      x  /|\\  x                          -\\-      | ___|___ |       |"<<endl;
        cout<<"|      x / |x \\ xx                          o______|  __|__  |       |"<<endl;
        cout<<"|    x  / x|x  \\                                        |    |       |"<<endl;
        cout<<"|      /  x| x  \\x                                   ___|___         |"<<endl;
        cout<<"|      x  x|___                                      |     |         |"<<endl;
        cout<<"|         / x  |                                     |     |         |"<<endl;
        cout<<"|        /  x  |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\  x                       \\                              |"<<endl;
        cout<<"|        /  \\                          \\             |-----|         |"<<endl;
        cout<<"|       /____\\ x                        \\            |*  * |         |"<<endl;
        cout<<"|       |      | x                       \\           |_____|         |"<<endl;
        cout<<"|       |-x----|                          \\         ____|____        |"<<endl;
        cout<<"|      x  /|\\  x                          -\\-      | ___|___ |       |"<<endl;
        cout<<"|       /  | \\ x                            o______|  __|__  |       |"<<endl;
        cout<<"|    x  /  |  \\                                         |    |       |"<<endl;
        cout<<"|      /  x|   \\x                                    ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                     \\                              |"<<endl;
        cout<<"|      x      x                        \\             |-----|         |"<<endl;
        cout<<"|       x   x   x                       \\            |*  * |         |"<<endl;
        cout<<"|     x | x   x| x x                     \\           |_____|         |"<<endl;
        cout<<"|      x|-xx----|x  x                     \\         ____|____        |"<<endl;
        cout<<"|    x  x  x/|\\  x  x                     -\\-      | ___|___ |       |"<<endl;
        cout<<"|    x  x / |x \\ xx                         o______|  __|__  |       |"<<endl;
        cout<<"|    x  / x|x x \\x                                      |    |       |"<<endl;
        cout<<"|      /  x| x  \\x                                   ___|___         |"<<endl;
        cout<<"|      x  x|___ x                                    |     |         |"<<endl;
        cout<<"|      x   / x  |  x                                 |     |         |"<<endl;
        cout<<"|        /  x  |                                     |     |         |"<<endl;
        cout<<"|       / x     |                                    |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                     \\                              |"<<endl;
        cout<<"|        x     x                       \\             |-----|         |"<<endl;
        cout<<"|                                       \\            |*  * |         |"<<endl;
        cout<<"|      x   x                             \\           |_____|         |"<<endl;
        cout<<"|               x                         \\         ____|____        |"<<endl;
        cout<<"|       x                                 -\\-      | ___|___ |       |"<<endl;
        cout<<"|         x     x                           o______|  __|__  |       |"<<endl;
        cout<<"|    x  / x|x x \\x                                      |    |       |"<<endl;
        cout<<"|      /  x| x  \\x                                   ___|___         |"<<endl;
        cout<<"|    x  x  x|___ x x                                 |     |         |"<<endl;
        cout<<"|     x x   / x  x|  x                               |     |         |"<<endl;
        cout<<"| x    xx   / x xxx  | x                             |     |         |"<<endl;
        cout<<"|       / x   x  |        x                          |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                     \\                              |"<<endl;
        cout<<"|                                      \\             |-----|         |"<<endl;
        cout<<"|              x                        \\            |*  * |         |"<<endl;
        cout<<"|                                        \\           |_____|         |"<<endl;
        cout<<"|     x                                   \\         ____|____        |"<<endl;
        cout<<"|                                         -\\-      | ___|___ |       |"<<endl;
        cout<<"|         x                                 o______|  __|__  |       |"<<endl;
        cout<<"|           x                                           |    |       |"<<endl;
        cout<<"|      x         x                                   ___|___         |"<<endl;
        cout<<"|   x    x  x    x                                   |     |         |"<<endl;
        cout<<"|     x   x     x     x                              |     |         |"<<endl;
        cout<<"| x  x  xx x  / x xxx  | xx                          |     |         |"<<endl;
        cout<<"| x  x   x / xx   xx  | x  x     x                   |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                         |-----|        |"<<endl;
        cout<<"|       /____\\                                |      x|*  * | x      |"<<endl;
        cout<<"|       |     |                               |     x |_____|        |"<<endl;
        cout<<"|       |-----|                               |      ____|___x_      |"<<endl;
        cout<<"|         /|________                          |  x  | ___|___ |      |"<<endl;
        cout<<"|        / |                                 _|_    |  __|__ x |     |"<<endl;
        cout<<"|       /  |                                  |_____| x   |   x | x  |"<<endl;
        cout<<"|      /   |                                  o      x ___|___       |"<<endl;
        cout<<"|          |___                                       |     |        |"<<endl;
        cout<<"|         /    |                                    x  |     |       |"<<endl;
        cout<<"|        /     |                                      |    x |  x    |"<<endl;
        cout<<"|       /      |                                      |     |        |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                               x         |"<<endl;
        cout<<"|        /  \\                                       x  |-----|       |"<<endl;
        cout<<"|       /____\\                                |      x |*  * | x     |"<<endl;
        cout<<"|       |     |                               |     x  |___x__|x     |"<<endl;
        cout<<"|       |-----|                               |    x  ____|___x_     |"<<endl;
        cout<<"|         /|________                          |  x x  | ___|_x__ |   |"<<endl;
        cout<<"|        / |                                 _|_    |  __|__ x |     |"<<endl;
        cout<<"|       /  |                                  |_____| x   |x   x | x |"<<endl;
        cout<<"|      /   |                                  o      x ___|___x      |"<<endl;
        cout<<"|          |___                                       |     |        |"<<endl;
        cout<<"|         /    |                                  x  x  | x    |     |"<<endl;
        cout<<"|        /     |                                      x|    x |  x   |"<<endl;
        cout<<"|       /      |                                      |     |        |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       x  |-----|       |"<<endl;
        cout<<"|       /____\\                                |       |*  * |        |"<<endl;
        cout<<"|       |     |                               |     x  |___x__|x     |"<<endl;
        cout<<"|       |-----|                               |      ____|___x_      |"<<endl;
        cout<<"|         /|________                          |  x   | ___|_ __ |    |"<<endl;
        cout<<"|        / |                                 _|_    |  __|__ x |     |"<<endl;
        cout<<"|       /  |                                  |_____| x   |x    |    |"<<endl;
        cout<<"|      /   |                                  o       ___|___        |"<<endl;
        cout<<"|          |___                                       |     |        |"<<endl;
        cout<<"|         /    |                                  x  x  | x    |     |"<<endl;
        cout<<"|        /     |                                      x|     |  x    |"<<endl;
        cout<<"|       /      |                                      |     |        |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                       x       x         |"<<endl;
        cout<<"|        /  \\                                         x     x        |"<<endl;
        cout<<"|       /____\\                                       x     x  x      |"<<endl;
        cout<<"|       |     |                               |     x  |___x__|xx    |"<<endl;
        cout<<"|       |-----|                              x |  x  xx  ____|___x_  |"<<endl;
        cout<<"|         /|________                          |  x x  | ___|_xx__ |  |"<<endl;
        cout<<"|        / |                                 _x|_    |  __|__ x |    |"<<endl;
        cout<<"|       /  |                                  |__x___| x x  |x   x |x|"<<endl;
        cout<<"|      /   |                                  o      x ___|___x      |"<<endl;
        cout<<"|          |___                                     x  |     |       |"<<endl;
        cout<<"|         /    |                                x  x  x  | x x   |   |"<<endl;
        cout<<"|        /     |                                      x| x   x |  x  |"<<endl;
        cout<<"|       /      |                                      |     |        |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                                        |"<<endl;
        cout<<"|       /____\\                                      x                |"<<endl;
        cout<<"|       |     |                                            x         |"<<endl;
        cout<<"|       |-----|                                    x          x      |"<<endl;
        cout<<"|         /|________                                      x          |"<<endl;
        cout<<"|        / |                                        x      x   x     |"<<endl;
        cout<<"|       /  |                                  |__x___| x x  |x   x |x|"<<endl;
        cout<<"|      /   |                                  o    x  x ___|___x x   |"<<endl;
        cout<<"|          |___                                     xx  |   x  |x    |"<<endl;
        cout<<"|         /    |                                xx  x  x  | x x   |  |"<<endl;
        cout<<"|        /     |                                  x    x| xx   x | x |"<<endl;
        cout<<"|       /      |                                      |     |        |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                                        |"<<endl;
        cout<<"|       /____\\                                      x                |"<<endl;
        cout<<"|       |     |                                            x         |"<<endl;
        cout<<"|       |-----|                                    x          x      |"<<endl;
        cout<<"|         /|________                                   x   x         |"<<endl;
        cout<<"|        / |                                        x      x   x     |"<<endl;
        cout<<"|       /  |                                          x             x|"<<endl;
        cout<<"|      /   |                                        x       x        |"<<endl;
        cout<<"|          |___                                 x   x    x      x    |"<<endl;
        cout<<"|         /    |                                  x        x         |"<<endl;
        cout<<"|        /     |                               x   x  x  x|x xx x |x |"<<endl;
        cout<<"|       /      |                                x    x  | x   |   x  |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       |-----|          |"<<endl;
        cout<<"|       /____\\                              |       |*  * |          |"<<endl;
        cout<<"|       |     |     \\                       |       |_____|          |"<<endl;
        cout<<"|       |-----|      \\                      |      ____|____         |"<<endl;
        cout<<"|         /|________  \\                     |     | ___|___ |        |"<<endl;
        cout<<"|        / |          /                    _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |         /                      |_____|    |    |        |"<<endl;
        cout<<"|      /   |        /                       o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       |-----|          |"<<endl;
        cout<<"|       /____\\                              |       |*  * |          |"<<endl;
        cout<<"|       |     |          \\                  |       |_____|          |"<<endl;
        cout<<"|       |-----|           \\                 |      ____|____         |"<<endl;
        cout<<"|         /|________       \\                |     | ___|___ |        |"<<endl;
        cout<<"|        / |               /               _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |              /                 |_____|    |    |        |"<<endl;
        cout<<"|      /   |             /                  o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       |-----|          |"<<endl;
        cout<<"|       /____\\                              |       |*  * |          |"<<endl;
        cout<<"|       |     |                    \\        |       |_____|          |"<<endl;
        cout<<"|       |-----|                     \\       |      ____|____         |"<<endl;
        cout<<"|         /|________                 \\      |     | ___|___ |        |"<<endl;
        cout<<"|        / |                         /     _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |                        /       |_____|    |    |        |"<<endl;
        cout<<"|      /   |                       /        o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       |-----|          |"<<endl;
        cout<<"|       /____\\                              |       |*  * |          |"<<endl;
        cout<<"|       |     |       o o  o                |       |_____|          |"<<endl;
        cout<<"|       |-----|      o o  oo                |      ____|____         |"<<endl;
        cout<<"|         /|________o o o o o o             |     | ___|___ |        |"<<endl;
        cout<<"|        / |        o  o  o o              _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |          o o   o               |_____|    |    |        |"<<endl;
        cout<<"|      /   |                                o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       |-----|          |"<<endl;
        cout<<"|       /____\\                              |       |*  * |          |"<<endl;
        cout<<"|       |     |            o o  o           |       |_____|          |"<<endl;
        cout<<"|       |-----|           o o  oo           |      ____|____         |"<<endl;
        cout<<"|         /|________     o o o o o o        |     | ___|___ |        |"<<endl;
        cout<<"|        / |             o  o  o o         _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |               o o   o          |_____|    |    |        |"<<endl;
        cout<<"|      /   |                                o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                       |-----|          |"<<endl;
        cout<<"|       /____\\                              |       |*  * |          |"<<endl;
        cout<<"|       |     |                 o o  o      |       |_____|          |"<<endl;
        cout<<"|       |-----|                o o  oo      |      ____|____         |"<<endl;
        cout<<"|         /|________          o o o o o o   |     | ___|___ |        |"<<endl;
        cout<<"|        / |                  o  o  o o    _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |                    o o   o     |_____|    |    |        |"<<endl;
        cout<<"|      /   |                                o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\             |                         |-----|          |"<<endl;
        cout<<"|       /____\\            |                 |       |*  * |          |"<<endl;
        cout<<"|       |     |       /=----\\               |       |_____|          |"<<endl;
        cout<<"|       |-----|         \\    \\             |      ____|____         |"<<endl;
        cout<<"|         /|________          \\             |     | ___|___ |        |"<<endl;
        cout<<"|        / |                               _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |                                |_____|    |    |        |"<<endl;
        cout<<"|      /   |                                o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\               /                                         |"<<endl;
        cout<<"|        /  \\             |                         |-----|          |"<<endl;
        cout<<"|       /____\\            |                 |       |*  * |          |"<<endl;
        cout<<"|       |     |       /-----\\               |       |_____|          |"<<endl;
        cout<<"|       |-----|         \\    \\       /      |      ____|____         |"<<endl;
        cout<<"|         /|________          \\_=__/--      |     | ___|___ |        |"<<endl;
        cout<<"|        / |                  /            _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |                 /              |_____|    |    |        |"<<endl;
        cout<<"|      /   |                /               o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\            -- /                                         |"<<endl;
        cout<<"|        /  \\             |                         |-----|          |"<<endl;
        cout<<"|       /____\\            |            /----|       |*  * |          |"<<endl;
        cout<<"|       |     |       /-===--\\        /     |       |_____|          |"<<endl;
        cout<<"|       |-----|         \\    \\       /      |      ____|____         |"<<endl;
        cout<<"|         /|________          \\ ____/-=----=|     | ___|___ |        |"<<endl;
        cout<<"|        / |                  /            _|_    |  __|__  |        |"<<endl;
        cout<<"|       /  |                 /              |_____|    |    |        |"<<endl;
        cout<<"|      /   |                /               o       ___|___          |"<<endl;
        cout<<"|          |___                                     |     |          |"<<endl;
        cout<<"|         /    |                                    |     |          |"<<endl;
        cout<<"|        /     |                                    |     |          |"<<endl;
        cout<<"|       /      |                                    |     |          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                        |-----|         |"<<endl;
        cout<<"|       /____\\                               |       |*  * |         |"<<endl;
        cout<<"|       |     |                              |       |_____|         |"<<endl;
        cout<<"|       |-----|                              |      ____|____        |"<<endl;
        cout<<"|         /|\\                                |     | ___|___ |       |"<<endl;
        cout<<"|        / | \\                              _|_    |  __|__  |       |"<<endl;
        cout<<"|       /  |  \\___O                          |_____|    |    |       |"<<endl;
        cout<<"|      /   |                                 o       ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                        |-----|         |"<<endl;
        cout<<"|       /____\\                               |       |*  * |         |"<<endl;
        cout<<"|       |     |                              |       |_____|         |"<<endl;
        cout<<"|       |-----|                              |      ____|____        |"<<endl;
        cout<<"|         /|\\                                |     | ___|___ |       |"<<endl;
        cout<<"|        / | \\____O                         _|_    |  __|__  |       |"<<endl;
        cout<<"|       /  |                                 |_____|    |    |       |"<<endl;
        cout<<"|      /   |                                 o       ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                        |-----|         |"<<endl;
        cout<<"|       /____\\                               |       |*  * |         |"<<endl;
        cout<<"|       |     |                              |       |_____|         |"<<endl;
        cout<<"|       |-----|   O                          |      ____|____        |"<<endl;
        cout<<"|         /|\\    |                           |     | ___|___ |       |"<<endl;
        cout<<"|        / | \\___|                          _|_    |  __|__  |       |"<<endl;
        cout<<"|       /  |                                 |_____|    |    |       |"<<endl;
        cout<<"|      /   |                                 o       ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                        |-----|         |"<<endl;
        cout<<"|       /____\\                               |       |*  * |         |"<<endl;
        cout<<"|       |     |                              |       |_____|         |"<<endl;
        cout<<"|       |-----|  O                           |      ____|____        |"<<endl;
        cout<<"|         /|\\     \\                          |     | ___|___ |       |"<<endl;
        cout<<"|        / | \\___|                          _|_    |  __|__  |       |"<<endl;
        cout<<"|       /  |                                 |_____|    |    |       |"<<endl;
        cout<<"|      /   |                                 o       ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable5() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                        |-----|         |"<<endl;
        cout<<"|       /____\\                               |       |*  * |         |"<<endl;
        cout<<"|       |     |  w                           |       |_____|         |"<<endl;
        cout<<"|       |-----| www                          |      ____|____        |"<<endl;
        cout<<"|         /|\\    w\\                          |     | ___|___ |       |"<<endl;
        cout<<"|        / | \\___|                          _|_    |  __|__  |       |"<<endl;
        cout<<"|       /  |                                 |_____|    |    |       |"<<endl;
        cout<<"|      /   |                                 o       ___|___         |"<<endl;
        cout<<"|          |___                                      |     |         |"<<endl;
        cout<<"|         /    |                                     |     |         |"<<endl;
        cout<<"|        /     |                                     |     |         |"<<endl;
        cout<<"|       /      |                                     |     |         |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
};


class soldierAnimation {

protected:

    Player_Info& playerR;
    Enemy_Info& enemyR;

public:

    soldierAnimation(Player_Info& p, Enemy_Info& e): playerR(p), enemyR(e) {}

    void idle() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |                                |      |      |       |"<<endl;
        cout<<"|       |-----|                                |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                                  |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\                                 | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |  \\                                |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |   \\                                    [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }

    void enemyAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                         |      |       |"<<endl;
        cout<<"|       /____\\                          ^             |&   & |       |"<<endl;
        cout<<"|       |     |                          \\            |      |       |"<<endl;
        cout<<"|       |-----|                           \\        /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                              \\      / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\                              \\   /  [][][][][][]  |   |"<<endl;
        cout<<"|       /  |  \\                              \\ /   [][][][][][]  |   |"<<endl;
        cout<<"|      /   |   \\                                    [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                         |      |       |"<<endl;
        cout<<"|       /____\\                                        |&   & |       |"<<endl;
        cout<<"|       |     |                    <\\                 |      |       |"<<endl;
        cout<<"|       |-----|                       \\            /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                           \\         / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\                            \\      /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |  \\                             \\  /   [][][][][][]  |   |"<<endl;
        cout<<"|      /   |   \\                                    [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                         |      |       |"<<endl;
        cout<<"|       /____\\                                        |&   & |       |"<<endl;
        cout<<"|       |     |                 <\\                    |      |       |"<<endl;
        cout<<"|       |-----|                     \\              /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                          \\          / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\                            \\      /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |  \\                              \\ /   [][][][][][]  |   |"<<endl;
        cout<<"|      /   |   \\                                    [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                         |      |       |"<<endl;
        cout<<"|       /____\\                                        |&   & |       |"<<endl;
        cout<<"|       |     |                                       |      |       |"<<endl;
        cout<<"|       |-----|                                    /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                                     / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\                                   /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |  \\                 <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |   \\                                    [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\   x                                      +------+       |"<<endl;
        cout<<"|        /  \\  x                                      |      |       |"<<endl;
        cout<<"|       /____\\  x                                     |&   & |       |"<<endl;
        cout<<"|       | x    | x                                    |      |       |"<<endl;
        cout<<"|      x|-x----|x                                  /[][][][][][]\\    |"<<endl;
        cout<<"|      x  /|\\   x                                 / [][][][][][] \\   |"<<endl;
        cout<<"|      x /|x \\  x                                /  [][][][][][]  |  |"<<endl;
        cout<<"|    x  /x|x  \\                 <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      /  x|   \\ x                                  [][][][][][]     |"<<endl;
        cout<<"|        x |___                                       ||     ||      |"<<endl;
        cout<<"|         / x  |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\   x                                      +------+       |"<<endl;
        cout<<"|     x  /x \\  x                                      |      |       |"<<endl;
        cout<<"|       /____\\  x                                     |&   & |       |"<<endl;
        cout<<"|     x | x   x| x                                    |      |       |"<<endl;
        cout<<"|      x|-x----|x  x                               /[][][][][][]\\    |"<<endl;
        cout<<"|      x  /|\\   x                                 / [][][][][][] \\   |"<<endl;
        cout<<"|      x / |x \\  xx                              /  [][][][][][]  |  |"<<endl;
        cout<<"|    x  / x|x  \\                <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      /  x| x  \\ x                                 [][][][][][]     |"<<endl;
        cout<<"|      x  x|___                                       ||     ||      |"<<endl;
        cout<<"|         / x  |                                      ||     ||      |"<<endl;
        cout<<"|        /  x  |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\   x                                      +------+       |"<<endl;
        cout<<"|        /  \\                                         |      |       |"<<endl;
        cout<<"|       /____\\  x                                     |&   & |       |"<<endl;
        cout<<"|       |      | x                                    |      |       |"<<endl;
        cout<<"|       |-x----|                                   /[][][][][][]\\    |"<<endl;
        cout<<"|      x  /|\\   x                                 / [][][][][][] \\   |"<<endl;
        cout<<"|       /  | \\  x                                /  [][][][][][]  |  |"<<endl;
        cout<<"|    x  /  |  \\                 <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      /  x|   \\ x                                  [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                     +------+       |"<<endl;
        cout<<"|      x      x                                       |      |       |"<<endl;
        cout<<"|       x   x   x                                     |&   & |       |"<<endl;
        cout<<"|     x | x   x| x x                                  |      |       |"<<endl;
        cout<<"|      x|-xx----|x  x                              /[][][][][][]\\    |"<<endl;
        cout<<"|    x  x  x/|\\   x  x                            / [][][][][][] \\   |"<<endl;
        cout<<"|    x  x / |x \\  xx                             /  [][][][][][]  |  |"<<endl;
        cout<<"|    x  / x|x x \\ x             <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      /  x| x  \\ x                                 [][][][][][]     |"<<endl;
        cout<<"|      x  x|___ x                                     ||     ||      |"<<endl;
        cout<<"|      x   / x  |  x                                  ||     ||      |"<<endl;
        cout<<"|        /  x  |                                      ||     ||      |"<<endl;
        cout<<"|       / x     |                                     ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                     +------+       |"<<endl;
        cout<<"|        x     x                                      |      |       |"<<endl;
        cout<<"|                                                     |&   & |       |"<<endl;
        cout<<"|      x   x                                          |      |       |"<<endl;
        cout<<"|               x                                  /[][][][][][]\\    |"<<endl;
        cout<<"|       x                                         / [][][][][][] \\   |"<<endl;
        cout<<"|         x     x                                /  [][][][][][]  |  |"<<endl;
        cout<<"|    x  / x|x x \\x              <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      /  x| x  \\x                                   [][][][][][]    |"<<endl;
        cout<<"|    x  x  x|___ x x                                  ||     ||      |"<<endl;
        cout<<"|     x x   / x  x|  x                                ||     ||      |"<<endl;
        cout<<"| x    xx   / x xxx  | x                              ||     ||      |"<<endl;
        cout<<"|       / x   x  |        x                           ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                     +------+       |"<<endl;
        cout<<"|                                                     |      |       |"<<endl;
        cout<<"|              x                                      |&   & |       |"<<endl;
        cout<<"|                                                     |      |       |"<<endl;
        cout<<"|     x                                            /[][][][][][]\\    |"<<endl;
        cout<<"|                                                 / [][][][][][] \\   |"<<endl;
        cout<<"|         x                                      /  [][][][][][]  |  |"<<endl;
        cout<<"|           x                   <---------------/   [][][][][][]  |  |"<<endl;
        cout<<"|      x         x                                  [][][][][][]     |"<<endl;
        cout<<"|   x    x  x    x                                    ||     ||      |"<<endl;
        cout<<"|     x   x     x     x                               ||     ||      |"<<endl;
        cout<<"| x  x  xx x  / x xxx  | xx                           ||     ||      |"<<endl;
        cout<<"| x  x   x / xx   xx  | x  x   x                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           +------+      |"<<endl;
        cout<<"|        /  \\                                   ^      |x xx    |    |"<<endl;
        cout<<"|       /____\\                                x | x     |&   & |     |"<<endl;
        cout<<"|       |     |                                |      |      |    x  |"<<endl;
        cout<<"|       |-----|                                | x /[][][][][][]     |"<<endl;
        cout<<"|         /|________                           x|  / []xx][][x]xx[][]|"<<endl;
        cout<<"|        / |                                   | /  [][][xx][][x[] x |"<<endl;
        cout<<"|       /  |                                   |/   [][x][x][][][]  ||"<<endl;
        cout<<"|      /   |                                        [][]x[][][]x[]   |"<<endl;
        cout<<"|          |___                               x        ||x     ||    |"<<endl;
        cout<<"|         /    |                                   x  ||     |x      |"<<endl;
        cout<<"|        /     |                                      ||  x   ||     |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           +------+      |"<<endl;
        cout<<"|        /  \\                                   ^      |x xx    |    |"<<endl;
        cout<<"|       /____\\                                x | x  xx   x|x&   x& ||"<<endl;
        cout<<"|       |     |                                |x      |     x |    x|"<<endl;
        cout<<"|       |-----|                                | x /[]x[][][][]x[]   |"<<endl;
        cout<<"|         /|________                          x x|  / [x]xx][][x]xxx[|"<<endl;
        cout<<"|        / |                                   | /  [][][xx]x[][x[x] |"<<endl;
        cout<<"|       /  |                                   |x/ x  []x[x][x][][][]|"<<endl;
        cout<<"|      /   |                                    x    [][]x[][][x]x[] |"<<endl;
        cout<<"|          |___                               x   xx     x||x     |xx|"<<endl;
        cout<<"|         /    |                                  x x  ||     |xx    |"<<endl;
        cout<<"|        /     |                                x     x ||  x   ||   |"<<endl;
        cout<<"|       /      |                                      ||     || x    |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                          +------+      |"<<endl;
        cout<<"|       /____\\                                  ^      |x x    |     |"<<endl;
        cout<<"|       |     |                               | x  xx   x|x&   & |   |"<<endl;
        cout<<"|       |-----|                                |      |     x |      |"<<endl;
        cout<<"|         /|________                           | x /[]x[][][][]x[]   |"<<endl;
        cout<<"|        / |                                  x |  / [x]][][x]x[     |"<<endl;
        cout<<"|       /  |                                   | /  [][][x]x[][[x]   |"<<endl;
        cout<<"|      /   |                                   |/ x  [][x][x][][][]  |"<<endl;
        cout<<"|          |___                                 x    [][]x[][][x][]  |"<<endl;
        cout<<"|         /    |                              x  xx     x||x     |xx |"<<endl;
        cout<<"|        /     |                                  x   ||     |x      |"<<endl;
        cout<<"|       /      |                                x     x ||  x   ||   |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                        x      x    x    |"<<endl;
        cout<<"|        /  \\                                         x      x       |"<<endl;
        cout<<"|       /____\\                                            x     x    |"<<endl;
        cout<<"|       |     |                                    x    x    x x     |"<<endl;
        cout<<"|       |-----|                                 | x /[]x[][][][]x[]  |"<<endl;
        cout<<"|         /|________                           x x|  / [x]xx][][x]xxx|"<<endl;
        cout<<"|        / |                                    | /  [][][xx]x[][x[x]|"<<endl;
        cout<<"|       /  |                                    |x/ x  []x[x][x][][][|"<<endl;
        cout<<"|      /   |                                     x    [][]x[][][x]x[]|"<<endl;
        cout<<"|          |___                                x   xx     x||x     |x|"<<endl;
        cout<<"|         /    |                                   x x  ||     |xx   |"<<endl;
        cout<<"|        /     |                                 x     x ||  x   ||  |"<<endl;
        cout<<"|       /      |                                       ||     || x   |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                x        |"<<endl;
        cout<<"|        /  \\                                            x   x   x   |"<<endl;
        cout<<"|       /____\\                                                  x    |"<<endl;
        cout<<"|       |     |                                            x    x    |"<<endl;
        cout<<"|       |-----|                                       x    x x x     |"<<endl;
        cout<<"|         /|________                                    x x  x x  x  |"<<endl;
        cout<<"|        / |                                       x   x  x  x  xx   |"<<endl;
        cout<<"|       /  |                                         x   x   x  x    |"<<endl;
        cout<<"|      /   |                                     xx   [][]x[][][x]x[]|"<<endl;
        cout<<"|          |___                                x   xx     x||x     |x|"<<endl;
        cout<<"|         /    |                                   x x  ||     |xx   |"<<endl;
        cout<<"|        /     |                                 x     x ||  x   ||  |"<<endl;
        cout<<"|       /      |                                       ||     || x   |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                                  x     |"<<endl;
        cout<<"|       /____\\                                                       |"<<endl;
        cout<<"|       |     |                                          x           |"<<endl;
        cout<<"|       |-----|                                                      |"<<endl;
        cout<<"|         /|________                                     x           |"<<endl;
        cout<<"|        / |                                                         |"<<endl;
        cout<<"|       /  |                                        x           x    |"<<endl;
        cout<<"|      /   |                                             x        x  |"<<endl;
        cout<<"|          |___                                                      |"<<endl;
        cout<<"|         /    |                                     x      x   x x  |"<<endl;
        cout<<"|        /     |                                 x     x ||  x   ||  |"<<endl;
        cout<<"|       /      |                                       ||     || x   |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |     \\                          |      |      |       |"<<endl;
        cout<<"|       |-----|      \\                         |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________  \\                        |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |          /                        | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |         /                         |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |        /                              [][][][][][]      |"<<endl;
        cout<<"|          |___                                      ||     ||       |"<<endl;
        cout<<"|         /    |                                     ||     ||       |"<<endl;
        cout<<"|        /     |                                     ||     ||       |"<<endl;
        cout<<"|       /      |                                     ||     ||       |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |          \\                     |      |      |       |"<<endl;
        cout<<"|       |-----|           \\                    |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________       \\                   |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |               /                   | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |              /                    |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |             /                          [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                         +------+       |"<<endl;
        cout<<"|       /____\\                                 ^      |      |       |"<<endl;
        cout<<"|       |     |                    \\           |      |&   & |       |"<<endl;
        cout<<"|       |-----|                     \\          |      |      |       |"<<endl;
        cout<<"|         /|________                 \\         |   /[][][][][][]\\    |"<<endl;
        cout<<"|        / |                         /         |  / [][][][][][] \\   |"<<endl;
        cout<<"|       /  |                        /          | /  [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                       /           |/   [][][][][][]  |  |"<<endl;
        cout<<"|          |___                                     [][][][][][]     |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |       o o  o                   |      |      |       |"<<endl;
        cout<<"|       |-----|      o o  oo                   |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________o o o o o o                |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |        o  o  o o                  | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |          o o   o                  |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |            o o  o              |      |      |       |"<<endl;
        cout<<"|       |-----|           o o  oo              |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________     o o o o o o           |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |             o  o  o o             | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |               o o   o             |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |                 o o  o         |      |      |       |"<<endl;
        cout<<"|       |-----|                o o  oo         |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________          o o o o o o      |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |                  o  o  o o        | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                    o o   o        |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\              |                   ^      |      |       |"<<endl;
        cout<<"|       /____\\             |                   |      |&   & |       |"<<endl;
        cout<<"|       |     |       /=----\\                  |      |      |       |"<<endl;
        cout<<"|       |-----|         \\     \\                |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________          \\                |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |                                   | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                                   |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                /                         +------+       |"<<endl;
        cout<<"|        /  \\              |                   ^      |      |       |"<<endl;
        cout<<"|       /____\\             |                   |      |&   & |       |"<<endl;
        cout<<"|       |     |       /-----\\                  |      |      |       |"<<endl;
        cout<<"|       |-----|         \\     \\        /       |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________          \\_=__/--         |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / |                  /                | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                 /                 |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                /                       [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\             -- /                         +------+       |"<<endl;
        cout<<"|        /  \\              |                   ^      |      |       |"<<endl;
        cout<<"|       /____\\             |            /----  |      |&   & |       |"<<endl;
        cout<<"|       |     |       /-===--\\         /       |      |      |       |"<<endl;
        cout<<"|       |-----|         \\     \\        /       |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|________          \\ ____/-=----=  |  / [][][][][][] \\    |"<<endl;
        cout<<"|        / |                  /                | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                 /                 |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                /                       [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |                                |      |      |       |"<<endl;
        cout<<"|       |-----|                                |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                                  |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\                                 | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |  \\___O                            |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |                                |      |      |       |"<<endl;
        cout<<"|       |-----|                                |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\                                  |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\____O                            | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                                   |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |                                |      |      |       |"<<endl;
        cout<<"|       |-----|   O                            |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\    |                             |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\___|                             | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                                   |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |                                |      |      |       |"<<endl;
        cout<<"|       |-----|  O                             |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\     \\                            |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\___|                             | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                                   |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable5() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                          +------+       |"<<endl;
        cout<<"|        /  \\                                  ^      |      |       |"<<endl;
        cout<<"|       /____\\                                 |      |&   & |       |"<<endl;
        cout<<"|       |     |  w                             |      |      |       |"<<endl;
        cout<<"|       |-----| www                            |   /[][][][][][]\\    |"<<endl;
        cout<<"|         /|\\    w\\                            |  / [][][][][][] \\   |"<<endl;
        cout<<"|        / | \\___|                             | /  [][][][][][]  |  |"<<endl;
        cout<<"|       /  |                                   |/   [][][][][][]  |  |"<<endl;
        cout<<"|      /   |                                        [][][][][][]     |"<<endl;
        cout<<"|          |___                                       ||     ||      |"<<endl;
        cout<<"|         /    |                                      ||     ||      |"<<endl;
        cout<<"|        /     |                                      ||     ||      |"<<endl;
        cout<<"|       /      |                                      ||     ||      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
};


class fireKingAnimation {

protected:

    Player_Info& playerR;
    Enemy_Info& enemyR;

public:

    fireKingAnimation(Player_Info& p, Enemy_Info& e): playerR(p), enemyR(e) {}

    void idle() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                                   +____|    |____+   |"<<endl;
        cout<<"|       |-----|                                  /|_            _|\\  |"<<endl;
        cout<<"|         /|\\                                   /   |          |   | |"<<endl;
        cout<<"|        / | \\                                 /    |          |   | |"<<endl;
        cout<<"|       /  |  \\                             __/     |          |   | |"<<endl;
        cout<<"|      /   |   \\                                    |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }

    void enemyAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                         o         +____|    |____+   |"<<endl;
        cout<<"|       |-----|                        o         /|_            _|\\  |"<<endl;
        cout<<"|         /|\\                            o      /   |          |   | |"<<endl;
        cout<<"|        / | \\                          o   o  /    |          |   | |"<<endl;
        cout<<"|       /  |  \\                      o     o__/     |          |   | |"<<endl;
        cout<<"|      /   |   \\                       o            |__________|   | |"<<endl;
        cout<<"|          |___                      o               | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                 o       o                |_ _ |        |"<<endl;
        cout<<"|       /____\\             o      o       o            |    |        |"<<endl;
        cout<<"|       |     |                   o      o        +____|    |____+   |"<<endl;
        cout<<"|       |-----|                        o         /|_            _|\\  |"<<endl;
        cout<<"|         /|\\                      o      o     /   |          |   | |"<<endl;
        cout<<"|        / | \\                  o    o    o o  /    |          |   | |"<<endl;
        cout<<"|       /  |  \\                      o     o__/     |          |   | |"<<endl;
        cout<<"|      /   |   \\                   o    o           |__________|   | |"<<endl;
        cout<<"|          |___                 o    o o             | |    | |      |"<<endl;
        cout<<"|         /    |                      o              | |    | |      |"<<endl;
        cout<<"|        /     |                 o                   | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\          o                   o            |\\__/|        |"<<endl;
        cout<<"|        /  \\                 o       o     o          |_ _ |        |"<<endl;
        cout<<"|       /____\\          o   o      o     o  oo         |    |        |"<<endl;
        cout<<"|       |     |                 o  o  o    o      +____|    |____+   |"<<endl;
        cout<<"|       |-----|             o           o  o     /|_            _|\\  |"<<endl;
        cout<<"|         /|\\                 o    o o   o   o  /   |          |   | |"<<endl;
        cout<<"|        / | \\            o     o    o    o o  /    |          |   | |"<<endl;
        cout<<"|       /  |  \\                     o o o  o__/     |          |   | |"<<endl;
        cout<<"|      /   |   \\           o        o  o  o         |__________|   | |"<<endl;
        cout<<"|          |___                 o   o oo   o   o     | |    | |      |"<<endl;
        cout<<"|         /    |           o        o o     o        | |    | |      |"<<endl;
        cout<<"|        /     |               o  o     o     o      | |    | |      |"<<endl;
        cout<<"|       /      |                 o   o      o      <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\     o     o   o                o          |\\__/|        |"<<endl;
        cout<<"|        /  \\      o  o         o       o     o        |_ _ |        |"<<endl;
        cout<<"|       /____\\     o     o   o      o     o  oo        |    |        |"<<endl;
        cout<<"|       |     |     o      o      o  o  o    o    +____|    |____+   |"<<endl;
        cout<<"|       |-----|   o   o       o           o  o   /|_            _|\\  |"<<endl;
        cout<<"|         /|\\            o     o    o o   o   o /   |          |   | |"<<endl;
        cout<<"|        / | \\     o       o     o    o    o o /    |          |   | |"<<endl;
        cout<<"|       /  |  \\      o   o    o      o o o o__/     |          |   | |"<<endl;
        cout<<"|      /   |   \\           o        o  o  o         |__________|   | |"<<endl;
        cout<<"|          |___     o  o    o   o   o oo   o   o     | |    | |      |"<<endl;
        cout<<"|         /    |         o o        o o     o        | |    | |      |"<<endl;
        cout<<"|        /     |      o        o  o     o     o      | |    | |      |"<<endl;
        cout<<"|       /      |    o      o     o   o      o      <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\    x     o                   o            |\\__/|        |"<<endl;
        cout<<"|        /  \\   x             o       o     o          |_ _ |        |"<<endl;
        cout<<"|       /____\\   x      o   o      o     o  oo         |    |        |"<<endl;
        cout<<"|       | x    | x              o  o  o    o      +____|    |____+   |"<<endl;
        cout<<"|      x|-x----|x           o           o  o     /|_            _|\\  |"<<endl;
        cout<<"|      x  /|\\    x            o    o o   o   o  /   |          |   | |"<<endl;
        cout<<"|      x /|x \\   x        o     o    o    o o  /    |          |   | |"<<endl;
        cout<<"|    x  /x|x  \\                    o o o  o__/     |          |   | |"<<endl;
        cout<<"|      /  x|   \\  x        o        o  o  o         |__________|   | |"<<endl;
        cout<<"|        x |___                 o   o oo   o   o     | |    | |      |"<<endl;
        cout<<"|         / x  |           o        o o     o        | |    | |      |"<<endl;
        cout<<"|        /     |               o  o     o     o      | |    | |      |"<<endl;
        cout<<"|       /      |                 o   o      o      <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\    x                                      |\\__/|        |"<<endl;
        cout<<"|     x  /x \\   x             o       o                |_ _ |        |"<<endl;
        cout<<"|       /____\\   x         o      o       o            |    |        |"<<endl;
        cout<<"|     x | x   x| x                o      o        +____|    |____+   |"<<endl;
        cout<<"|      x|-x----|x  x                   o         /|_            _|\\  |"<<endl;
        cout<<"|      x  /|\\    x                 o      o     /   |          |   | |"<<endl;
        cout<<"|      x / |x \\   xx            o    o    o o  /    |          |   | |"<<endl;
        cout<<"|    x  / x|x  \\                     o     o__/     |          |   | |"<<endl;
        cout<<"|      /  x| x  \\  x               o    o           |__________|   | |"<<endl;
        cout<<"|      x  x|___                 o    o o             | |    | |      |"<<endl;
        cout<<"|         / x  |                      o              | |    | |      |"<<endl;
        cout<<"|        /  x  |                 o                   | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\    x                                      |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\   x                                     |    |        |"<<endl;
        cout<<"|       |      | x                      o         +____|    |____+   |"<<endl;
        cout<<"|       |-x----|                       o         /|_            _|\\  |"<<endl;
        cout<<"|      x  /|\\    x                       o      /   |          |   | |"<<endl;
        cout<<"|       /  | \\   x                      o   o  /    |          |   | |"<<endl;
        cout<<"|    x  /  |  \\                      o     o__/     |          |   | |"<<endl;
        cout<<"|      /  x|   \\  x                    o            |__________|   | |"<<endl;
        cout<<"|          |___                      o               | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                      |\\__/|        |"<<endl;
        cout<<"|      x      x                                        |_ _ |        |"<<endl;
        cout<<"|       x   x   x                                      |    |        |"<<endl;
        cout<<"|     x | x   x| x x                              +____|    |____+   |"<<endl;
        cout<<"|      x|-xx----|x  x                            /|_            _|\\  |"<<endl;
        cout<<"|    x  x  x/|\\   x  x                          /   |          |   | |"<<endl;
        cout<<"|    x  x / |x \\  xx                           /    |          |   | |"<<endl;
        cout<<"|    x  / x|x x \\ x                         __/     |          |   | |"<<endl;
        cout<<"|      /  x| x  \\ x                                 |__________|   | |"<<endl;
        cout<<"|      x  x|___ x                                    | |    | |      |"<<endl;
        cout<<"|      x   / x  |  x                                 | |    | |      |"<<endl;
        cout<<"|        /  x  |                                     | |    | |      |"<<endl;
        cout<<"|       / x     |                                  <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                      |\\__/|        |"<<endl;
        cout<<"|        x     x                                       |_ _ |        |"<<endl;
        cout<<"|                                                      |    |        |"<<endl;
        cout<<"|      x   x                                      +____|    |____+   |"<<endl;
        cout<<"|               x                                /|_            _|\\  |"<<endl;
        cout<<"|       x                                       /   |          |   | |"<<endl;
        cout<<"|         x     x                              /    |          |   | |"<<endl;
        cout<<"|    x  / x|x x \\x                          __/     |          |   | |"<<endl;
        cout<<"|      /  x| x  \\x                                  |__________|   | |"<<endl;
        cout<<"|    x  x  x|___ x x                                 | |    | |      |"<<endl;
        cout<<"|     x x   / x  x|  x                               | |    | |      |"<<endl;
        cout<<"| x    xx   / x xxx  | x                             | |    | |      |"<<endl;
        cout<<"|       / x   x  |        x                        <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                      |\\__/|        |"<<endl;
        cout<<"|                                                      |_ _ |        |"<<endl;
        cout<<"|              x                                       |    |        |"<<endl;
        cout<<"|                                                 +____|    |____+   |"<<endl;
        cout<<"|     x                                          /|_            _|\\  |"<<endl;
        cout<<"|                                               /   |          |   | |"<<endl;
        cout<<"|         x                                    /    |          |   | |"<<endl;
        cout<<"|           x                               __/     |          |   | |"<<endl;
        cout<<"|      x         x                                  |__________|   | |"<<endl;
        cout<<"|   x    x  x    x                                   | |    | |      |"<<endl;
        cout<<"|     x   x     x     x                              | |    | |      |"<<endl;
        cout<<"| x  x  xx x  / x xxx  | xx                          | |    | |      |"<<endl;
        cout<<"| x  x   x / xx   xx  | x  x   x                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\x__/|       |"<<endl;
        cout<<"|        /  \\                                   x    x   |_ _ |      |"<<endl;
        cout<<"|       /____\\                                         | x   |       |"<<endl;
        cout<<"|       |     |                                   +____|    x|____+  |"<<endl;
        cout<<"|       |-----|                                  /|_     x       _|\\ |"<<endl;
        cout<<"|         /|________                         x   /  x |          |  ||"<<endl;
        cout<<"|        / |                                   /    |         x |   ||"<<endl;
        cout<<"|       /  |                                __/     |   x      x |  ||"<<endl;
        cout<<"|      /   |                                        x|__________|  | |"<<endl;
        cout<<"|          |___                             x         | |    | |     |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                  x   | x|    | |    |"<<endl;
        cout<<"|       /      |                               x    <(x|_|  <(|_| x  |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\x__/|  x    |"<<endl;
        cout<<"|        /  \\                                   x    x   |_ x_ |     |"<<endl;
        cout<<"|       /____\\                                     x    | x   |  x   |"<<endl;
        cout<<"|       |     |                                   +____|    x|____+  |"<<endl;
        cout<<"|       |-----|                                  /|_     xx  x   _|\\ |"<<endl;
        cout<<"|         /|________                         x   /  x |      x    | ||"<<endl;
        cout<<"|        / |                                   /  x  |   x      x | ||"<<endl;
        cout<<"|       /  |                                __/ x    |   x     xx | ||"<<endl;
        cout<<"|      /   |                                      x  x|__________| | |"<<endl;
        cout<<"|          |___                             x       x  | |    | |    |"<<endl;
        cout<<"|         /    |                                    x | |  x  | |  x |"<<endl;
        cout<<"|        /     |                                  x  x | x|    |  x  |"<<endl;
        cout<<"|       /      |                               x    <(x|_| x <(|_| x |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\x__/|  x    |"<<endl;
        cout<<"|        /  \\                                       x   |_ x_ |      |"<<endl;
        cout<<"|       /____\\                                         | x   |       |"<<endl;
        cout<<"|       |     |                                   +____|    x|____+  |"<<endl;
        cout<<"|       |-----|                                  /|_     x     _|\\   |"<<endl;
        cout<<"|         /|________                            /  x |      x    | | |"<<endl;
        cout<<"|        / |                                   /  x  |   x       | | |"<<endl;
        cout<<"|       /  |                                __/     |        xx | |  |"<<endl;
        cout<<"|      /   |                                      x  x|__________| | |"<<endl;
        cout<<"|          |___                             x       x  | |    | |    |"<<endl;
        cout<<"|         /    |                                     | |    | |  x   |"<<endl;
        cout<<"|        /     |                                  x  x | x|    |     |"<<endl;
        cout<<"|       /      |                               x    <(x|_| x <(|_| x |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           x             |"<<endl;
        cout<<"|        /  \\                                      x          x      |"<<endl;
        cout<<"|       /____\\                                           x x   x     |"<<endl;
        cout<<"|       |     |                                 x       x     x    x |"<<endl;
        cout<<"|       |-----|                                  /|_     xx  x   _|\\ |"<<endl;
        cout<<"|         /|________                         x   /  x |  x x   x   |||"<<endl;
        cout<<"|        / |                                   /  x  |   x  x   x | ||"<<endl;
        cout<<"|       /  |                                __/ x    |  x x    xx | ||"<<endl;
        cout<<"|      /   |                                  x  x  x|_____x_____| | |"<<endl;
        cout<<"|          |___                             x     x  | |  x  | |  x  |"<<endl;
        cout<<"|         /    |                               x     x | xxx  | |  x |"<<endl;
        cout<<"|        /     |                              x    x  x | x| x | xx  |"<<endl;
        cout<<"|       /      |                          x x  x  <(xx|_| xx <(|_| x |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           x             |"<<endl;
        cout<<"|        /  \\                                                        |"<<endl;
        cout<<"|       /____\\                                           x    x      |"<<endl;
        cout<<"|       |     |                                 x      x         x   |"<<endl;
        cout<<"|       |-----|                                                 xx   |"<<endl;
        cout<<"|         /|________                             x     x    x        |"<<endl;
        cout<<"|        / |                                           x     xxx     |"<<endl;
        cout<<"|       /  |                                   x  x    x         x x |"<<endl;
        cout<<"|      /   |                                      x        x    x    |"<<endl;
        cout<<"|          |___                                   x              x   |"<<endl;
        cout<<"|         /    |                               x     x | xxx  | |  x |"<<endl;
        cout<<"|        /     |                              x    x  x | x| x | xx  |"<<endl;
        cout<<"|       /      |                          x x  x  <(xx|_| xx <(|_| x |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                                  x     |"<<endl;
        cout<<"|       /____\\                                                       |"<<endl;
        cout<<"|       |     |                                          x           |"<<endl;
        cout<<"|       |-----|                                                      |"<<endl;
        cout<<"|         /|________                                     x           |"<<endl;
        cout<<"|        / |                                                         |"<<endl;
        cout<<"|       /  |                                        x           x    |"<<endl;
        cout<<"|      /   |                                             x        x  |"<<endl;
        cout<<"|          |___                                                      |"<<endl;
        cout<<"|         /    |                                     x      x   x x  |"<<endl;
        cout<<"|        /     |                                 x     x ||  x   ||  |"<<endl;
        cout<<"|       /      |                                       ||     || x   |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |     \\                             +____|    |____+   |"<<endl;
        cout<<"|       |-----|      \\                           /|_            _|\\  |"<<endl;
        cout<<"|         /|________  \\                         /   |          |   | |"<<endl;
        cout<<"|        / |          /                        /    |          |   | |"<<endl;
        cout<<"|       /  |         /                      __/     |          |   | |"<<endl;
        cout<<"|      /   |        /                               |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |          \\                        +____|    |____+   |"<<endl;
        cout<<"|       |-----|           \\                      /|_            _|\\  |"<<endl;
        cout<<"|         /|________       \\                    /   |          |   | |"<<endl;
        cout<<"|        / |               /                   /    |          |   | |"<<endl;
        cout<<"|       /  |              /                 __/     |          |   | |"<<endl;
        cout<<"|      /   |             /                          |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                    \\              +____|    |____+   |"<<endl;
        cout<<"|       |-----|                     \\            /|_            _|\\  |"<<endl;
        cout<<"|         /|________                 \\          /   |          |   | |"<<endl;
        cout<<"|        / |                         /         /    |          |   | |"<<endl;
        cout<<"|       /  |                        /       __/     |          |   | |"<<endl;
        cout<<"|      /   |                       /                |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |       o o  o                      +____|    |____+   |"<<endl;
        cout<<"|       |-----|      o o  oo                     /|_            _|\\  |"<<endl;
        cout<<"|         /|________o o o o o o                 /   |          |   | |"<<endl;
        cout<<"|        / |        o  o  o o                  /    |          |   | |"<<endl;
        cout<<"|       /  |          o o   o               __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |            o o  o                 +____|    |____+   |"<<endl;
        cout<<"|       |-----|           o o  oo                /|_            _|\\  |"<<endl;
        cout<<"|         /|________     o o o o o o            /   |          |   | |"<<endl;
        cout<<"|        / |             o  o  o o             /    |          |   | |"<<endl;
        cout<<"|       /  |               o o   o          __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                 o o  o            +____|    |____+   |"<<endl;
        cout<<"|       |-----|                o o  oo           /|_            _|\\  |"<<endl;
        cout<<"|         /|________          o o o o o o       /   |          |   | |"<<endl;
        cout<<"|        / |                  o  o  o o        /    |          |   | |"<<endl;
        cout<<"|       /  |                    o o   o     __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\              |                           |_ _ |        |"<<endl;
        cout<<"|       /____\\             |                           |    |        |"<<endl;
        cout<<"|       |     |       /=----\\                     +____|    |____+   |"<<endl;
        cout<<"|       |-----|         \\     \\                  /|_            _|\\  |"<<endl;
        cout<<"|         /|________          \\                 /   |          |   | |"<<endl;
        cout<<"|        / |                                   /    |          |   | |"<<endl;
        cout<<"|       /  |                                __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                /                          |\\__/|        |"<<endl;
        cout<<"|        /  \\              |                           |_ _ |        |"<<endl;
        cout<<"|       /____\\             |                           |    |        |"<<endl;
        cout<<"|       |     |       /-----\\                     +____|    |____+   |"<<endl;
        cout<<"|       |-----|         \\     \\        /         /|_            _|\\  |"<<endl;
        cout<<"|         /|________          \\_=__/--         /   |          |   | |"<<endl;
        cout<<"|        / |                  /                /    |          |   | |"<<endl;
        cout<<"|       /  |                 /              __/     |          |   | |"<<endl;
        cout<<"|      /   |                /                       |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\             -- /                          |\\__/|        |"<<endl;
        cout<<"|        /  \\              |                           |_ _ |        |"<<endl;
        cout<<"|       /____\\             |            /----          |    |        |"<<endl;
        cout<<"|       |     |       /-===--\\         /          +____|    |____+   |"<<endl;
        cout<<"|       |-----|         \\     \\        /         /|_            _|\\  |"<<endl;
        cout<<"|         /|________          \\ ____/-=----=    /   |          |   | |"<<endl;
        cout<<"|        / |                  /                /    |          |   | |"<<endl;
        cout<<"|       /  |                 /              __/     |          |   | |"<<endl;
        cout<<"|      /   |                /                       |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                                   +____|    |____+   |"<<endl;
        cout<<"|       |-----|                                  /|_            _|\\  |"<<endl;
        cout<<"|         /|\\                                   /   |          |   | |"<<endl;
        cout<<"|        / | \\                                 /    |          |   | |"<<endl;
        cout<<"|       /  |  \\___O                         __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                                   +____|    |____+   |"<<endl;
        cout<<"|       |-----|                                  /|_            _|\\  |"<<endl;
        cout<<"|         /|\\                                   /   |          |   | |"<<endl;
        cout<<"|        / | \\____O                            /    |          |   | |"<<endl;
        cout<<"|       /  |                                __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                                   +____|    |____+   |"<<endl;
        cout<<"|       |-----|   O                              /|_            _|\\  |"<<endl;
        cout<<"|         /|\\    |                              /   |          |   | |"<<endl;
        cout<<"|        / | \\___|                             /    |          |   | |"<<endl;
        cout<<"|       /  |                                __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |                                   +____|    |____+   |"<<endl;
        cout<<"|       |-----|  O                               /|_            _|\\  |"<<endl;
        cout<<"|         /|\\     \\                             /   |          |   | |"<<endl;
        cout<<"|        / | \\___|                             /    |          |   | |"<<endl;
        cout<<"|       /  |                                __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable5() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                           |\\__/|        |"<<endl;
        cout<<"|        /  \\                                          |_ _ |        |"<<endl;
        cout<<"|       /____\\                                         |    |        |"<<endl;
        cout<<"|       |     |  w                                +____|    |____+   |"<<endl;
        cout<<"|       |-----| www                              /|_            _|\\  |"<<endl;
        cout<<"|         /|\\    w\\                             /   |          |   | |"<<endl;
        cout<<"|        / | \\___|                             /    |          |   | |"<<endl;
        cout<<"|       /  |                                __/     |          |   | |"<<endl;
        cout<<"|      /   |                                        |__________|   | |"<<endl;
        cout<<"|          |___                                      | |    | |      |"<<endl;
        cout<<"|         /    |                                     | |    | |      |"<<endl;
        cout<<"|        /     |                                     | |    | |      |"<<endl;
        cout<<"|       /      |                                   <(|_|  <(|_|      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
};


class abyssCreatureAnimation {

protected:

    Player_Info& playerR;
    Enemy_Info& enemyR;

public:

    abyssCreatureAnimation(Player_Info& p, Enemy_Info& e): playerR(p), enemyR(e) {}

    void idle() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|                         @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\                           @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\                         @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |  \\                          @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |   \\                           @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }

    void enemyAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                             *           |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                  *            @     @    @ @      *   |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|                     *   @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\                           @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\                    *    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |  \\                          @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /   |   \\                           @   @   @    @            |"<<endl;
        cout<<"|          |___                      *         @   @         *       |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                *                    |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                          *        *         *           |"<<endl;
        cout<<"|        /  \\                                    @     @     *       |"<<endl;
        cout<<"|       /____\\                  *    *       @     @    @ @      *   |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|           *         *   @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\                           @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\                    *    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |  \\                          @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /   |   \\           *               @   @   @    @            |"<<endl;
        cout<<"|          |___                      *         @   @         *       |"<<endl;
        cout<<"|         /    |                                      *              |"<<endl;
        cout<<"|        /     |          *                     *        *           |"<<endl;
        cout<<"|       /      |                      *                              |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\           *              *        *     *   *           |"<<endl;
        cout<<"|        /  \\            *       *         *     @     @     *    *  |"<<endl;
        cout<<"|       /____\\                  *    *       @     @    @ @      *   |"<<endl;
        cout<<"|       |     |       *          *         @     @  @   @  @  *      |"<<endl;
        cout<<"|       |-----|           *         *   @     @    &   @   @ @   *   |"<<endl;
        cout<<"|         /|\\             *    *        @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\     *              *    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |  \\                *         @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /   |   \\           *       *       @   @   @    @            |"<<endl;
        cout<<"|          |___                      *         @   @         *   *   |"<<endl;
        cout<<"|         /    |    *           *           *         *              |"<<endl;
        cout<<"|        /     |          *            *        *        *    *   *  |"<<endl;
        cout<<"|       /      |                      *              *       *       |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyAttack4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\           *    %         *  %     *     *   *     %     |"<<endl;
        cout<<"|        /  \\            *       *   &     *     @     @     *    *  |"<<endl;
        cout<<"|       /____\\    %      &      *    *   %   @     @    @ @      *   |"<<endl;
        cout<<"|       |     |       *     %    *   %     @     @  @   @  @  *  %   |"<<endl;
        cout<<"|       |-----|           *         *   @     @    &   @   @ @   *   |"<<endl;
        cout<<"|         /|\\             *    *        @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\     *       &      *    @    @  @   &   @  @   @     &|"<<endl;
        cout<<"|       /  |  \\        %       *      %  @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /   |   \\           *       *       @   @   @    @       %    |"<<endl;
        cout<<"|          |___                %     *         @   @         *   *   |"<<endl;
        cout<<"|         /    |    *           *           *         *   %      &   |"<<endl;
        cout<<"|        /     |          *     &       *  %    *        *    *   *  |"<<endl;
        cout<<"|       /      |      %               *          &   *  %    *       |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\    x      *              *        *     *   *           |"<<endl;
        cout<<"|        /  \\   x        *       *         *     @     @     *    *  |"<<endl;
        cout<<"|       /____\\   x              *    *       @     @    @ @      *   |"<<endl;
        cout<<"|       | x    | x    *          *         @     @  @   @  @  *      |"<<endl;
        cout<<"|      x|-x----|x         *         *   @     @    &   @   @ @   *   |"<<endl;
        cout<<"|      x  /|\\    x        *    *        @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|      x /|x \\   x                *    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|    x  /x|x  \\                *         @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /  x|   \\  x        *       *       @   @   @    @            |"<<endl;
        cout<<"|        x |___                      *         @   @         *   *   |"<<endl;
        cout<<"|         / x  |                *           *         *              |"<<endl;
        cout<<"|        /     |          *            *        *        *    *   *  |"<<endl;
        cout<<"|       /      |                      *              *       *       |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\    x                     *        *         *           |"<<endl;
        cout<<"|     x  /x \\   x                                @     @     *       |"<<endl;
        cout<<"|       /____\\   x              *    *       @     @    @ @      *   |"<<endl;
        cout<<"|     x | x   x| x                         @     @  @   @  @         |"<<endl;
        cout<<"|      x|-x----|x  x      *         *   @     @    &   @   @ @       |"<<endl;
        cout<<"|      x  /|\\    x                      @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|      x / |x \\   xx              *    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|    x  / x|x  \\                         @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /  x| x  \\  x       *               @   @   @    @            |"<<endl;
        cout<<"|      x  x|___                      *         @   @         *       |"<<endl;
        cout<<"|         / x  |                                      *              |"<<endl;
        cout<<"|        /  x  |          *                     *        *           |"<<endl;
        cout<<"|       /      |                      *                              |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|       x /\\   x                                         *           |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\  x               *            @     @    @ @      *   |"<<endl;
        cout<<"|       |      | x                         @     @  @   @  @         |"<<endl;
        cout<<"|       |-x----|                    *   @     @    &   @   @ @       |"<<endl;
        cout<<"|      x  /|\\   x                       @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|       /  | \\  x                 *    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|    x  /  |  \\                          @  @    @   @   @  @    *   |"<<endl;
        cout<<"|      /  x|   \\ x                         @   @   @    @            |"<<endl;
        cout<<"|          |___                      *         @   @         *       |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                *                    |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                                    |"<<endl;
        cout<<"|      x      x                                  @     @             |"<<endl;
        cout<<"|       x   x   x                            @     @    @ @          |"<<endl;
        cout<<"|     x | x   x| x x                       @     @  @   @  @         |"<<endl;
        cout<<"|      x|-xx----|x  x                   @     @    &   @   @ @       |"<<endl;
        cout<<"|    x  x  x/|\\   x  x                  @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|    x  x / |x \\  xx                   @    @  @   &   @  @   @      |"<<endl;
        cout<<"|    x  / x|x x \\ x                      @  @    @   @   @  @        |"<<endl;
        cout<<"|      /  x| x  \\ x                        @   @   @    @            |"<<endl;
        cout<<"|      x  x|___ x                              @   @                 |"<<endl;
        cout<<"|      x   / x  |  x                                                 |"<<endl;
        cout<<"|        /  x  |                                                     |"<<endl;
        cout<<"|       / x     |                                                    |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                                    |"<<endl;
        cout<<"|        x     x                                 @     @             |"<<endl;
        cout<<"|                                            @     @    @ @          |"<<endl;
        cout<<"|      x   x                               @     @  @   @  @         |"<<endl;
        cout<<"|               x                       @     @    &   @   @ @       |"<<endl;
        cout<<"|       x                               @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|         x     x                      @    @  @   &   @  @   @      |"<<endl;
        cout<<"|    x  / x|x x \\x                       @  @    @   @   @  @        |"<<endl;
        cout<<"|      /  x| x  \\x                         @   @   @    @            |"<<endl;
        cout<<"|    x  x  x|___ x x                           @   @                 |"<<endl;
        cout<<"|     x x   / x  x|  x                                               |"<<endl;
        cout<<"| x    xx   / x xxx  | x                                             |"<<endl;
        cout<<"|       / x   x  |        x                                          |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|                                                                    |"<<endl;
        cout<<"|                                                @     @             |"<<endl;
        cout<<"|              x                             @     @    @ @          |"<<endl;
        cout<<"|                                          @     @  @   @  @         |"<<endl;
        cout<<"|     x                                 @     @    &   @   @ @       |"<<endl;
        cout<<"|                                       @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|         x                            @    @  @   &   @  @   @      |"<<endl;
        cout<<"|           x                            @  @    @   @   @  @        |"<<endl;
        cout<<"|      x         x                         @   @   @    @            |"<<endl;
        cout<<"|   x    x  x    x                             @   @                 |"<<endl;
        cout<<"|     x   x     x     x                                              |"<<endl;
        cout<<"| x  x  xx x  / x xxx  | xx                                          |"<<endl;
        cout<<"| x  x   x / xx   xx  | x  x   x                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                   x                     |"<<endl;
        cout<<"|        /  \\                               x     @ x    @x          |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                            @ x    @  @ x  @  @       |"<<endl;
        cout<<"|       |-----|                         @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________                 x   @   @    #&*&#   @ x   @ @  |"<<endl;
        cout<<"|        / |                           @    @ x @   &   @  @   @     |"<<endl;
        cout<<"|       /  |                             @  @    @   @ x x @  @      |"<<endl;
        cout<<"|      /   |                               @   x@   @    @           |"<<endl;
        cout<<"|          |___                         x     x  @   @     x x       |"<<endl;
        cout<<"|         /    |                                      x              |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                   x    x                |"<<endl;
        cout<<"|        /  \\                             x  x   x  @ x    @x        |"<<endl;
        cout<<"|       /____\\                            x   @ x    @    @ @  x     |"<<endl;
        cout<<"|       |     |                           x @ x   x @  @ x  @  @     |"<<endl;
        cout<<"|       |-----|                         @ x    @    &   @  x @ x@    |"<<endl;
        cout<<"|         /|________                 x   @   @   x #&*&#  x @ x   @ @|"<<endl;
        cout<<"|        / |                           @    x@ x @   &   @  @  x @   |"<<endl;
        cout<<"|       /  |                             @  @ x   @x   x@ x x @  @   |"<<endl;
        cout<<"|      /   |                               @   x@   @x    @    x     |"<<endl;
        cout<<"|          |___                         x     x  @x   @     x x      |"<<endl;
        cout<<"|         /    |                                      x              |"<<endl;
        cout<<"|        /     |                                  x                  |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyHit3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                   x                     |"<<endl;
        cout<<"|        /  \\                               x   x  @ x               |"<<endl;
        cout<<"|       /____\\                               @ x    @    @ @  x      |"<<endl;
        cout<<"|       |     |                            @ x    @  @x  @  @        |"<<endl;
        cout<<"|       |-----|                         @ x    @    &   @   @ @      |"<<endl;
        cout<<"|         /|________                 x   @   @    #&*&#  x @    @ @  |"<<endl;
        cout<<"|        / |                           @    @ x @   &   @  @   @     |"<<endl;
        cout<<"|       /  |                             @  @ x   @   x@ x x @  @    |"<<endl;
        cout<<"|      /   |                               @   x@   @x    @    x     |"<<endl;
        cout<<"|          |___                                @x   @     x x        |"<<endl;
        cout<<"|         /    |                                      x              |"<<endl;
        cout<<"|        /     |                                  x                  |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                       x                 |"<<endl;
        cout<<"|        /  \\                                 x     x      x         |"<<endl;
        cout<<"|       /____\\                                   x     x   x         |"<<endl;
        cout<<"|       |     |                                x     x  x   x  x     |"<<endl;
        cout<<"|       |-----|                         @ x x   @    &   @  x @ x@   |"<<endl;
        cout<<"|         /|________                 x   @   @   x #&*&#  x @ x   @ @|"<<endl;
        cout<<"|        / |                           @    x@ x @   &   @  @  x @   |"<<endl;
        cout<<"|       /  |                             @  @ x   @x   x@ x x @  @   |"<<endl;
        cout<<"|      /   |                               @   x@   @x    @    x     |"<<endl;
        cout<<"|          |___                         x     x  @x   @     x x      |"<<endl;
        cout<<"|         /    |                                      x              |"<<endl;
        cout<<"|        /     |                                  x                  |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                         x               |"<<endl;
        cout<<"|        /  \\                                      x                 |"<<endl;
        cout<<"|       /____\\                                x    x    x            |"<<endl;
        cout<<"|       |     |                                    x     x           |"<<endl;
        cout<<"|       |-----|                               x  x    x              |"<<endl;
        cout<<"|         /|________                          x     x    x x         |"<<endl;
        cout<<"|        / |                                x  x     x   x x         |"<<endl;
        cout<<"|       /  |                             @  @ x   @x   x@ x x @  @   |"<<endl;
        cout<<"|      /   |                               @   x@   @x    @    x     |"<<endl;
        cout<<"|          |___                         x     x  @x   @     x x      |"<<endl;
        cout<<"|         /    |                                      x              |"<<endl;
        cout<<"|        /     |                                  x                  |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void enemyDeath3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                                        |"<<endl;
        cout<<"|       /____\\                                        x              |"<<endl;
        cout<<"|       |     |                                       x              |"<<endl;
        cout<<"|       |-----|                                                      |"<<endl;
        cout<<"|         /|________                             x     x             |"<<endl;
        cout<<"|        / |                                          x              |"<<endl;
        cout<<"|       /  |                                                         |"<<endl;
        cout<<"|      /   |                                       x     x x         |"<<endl;
        cout<<"|          |___                               x                      |"<<endl;
        cout<<"|         /    |                                  x    x    x        |"<<endl;
        cout<<"|        /     |                             x           x           |"<<endl;
        cout<<"|       /      |                                    x                |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                          |"<<endl;
        cout<<"|        /  \\                                     @     @             |"<<endl;
        cout<<"|       /____\\                                @     @    @ @          |"<<endl;
        cout<<"|       |     |     \\                       @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|      \\                   @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________  \\                  @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / |          /                 @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |         /                    @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |        /                       @   @   @    @            |"<<endl;
        cout<<"|          |___                                 @   @                 |"<<endl;
        cout<<"|         /    |                                                      |"<<endl;
        cout<<"|        /     |                                                      |"<<endl;
        cout<<"|       /      |                                                      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |          \\                 @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|           \\             @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________       \\            @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / |               /           @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |              /              @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |             /                 @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerWindBlastAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                    \\      @     @  @   @  @          |"<<endl;
        cout<<"|       |-----|                     \\  @     @    &   @   @ @        |"<<endl;
        cout<<"|         /|________                 \\ @   @    #&*&#   @    @ @     |"<<endl;
        cout<<"|        / |                         / @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                        /    @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                       /       @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |       o o  o               @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|      o o  oo            @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________o o o o o o         @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / |        o  o  o o          @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |          o o   o            @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |            o o  o          @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|           o o  oo       @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________     o o o o o o    @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / |             o  o  o o     @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |               o o   o       @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerFireBallAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                      @     @           |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |               o o  o       @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|              o o  oo    @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________        o o o o o o @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / |                o  o  o o  @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                  o o   o    @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                  @   @               |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\              |                     @     @             |"<<endl;
        cout<<"|       /____\\             |                 @     @    @ @          |"<<endl;
        cout<<"|       |     |       /=----\\              @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|         \\     \\         @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________          \\         @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / |                           @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                             @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                /                                        |"<<endl;
        cout<<"|        /  \\              |                     @     @             |"<<endl;
        cout<<"|       /____\\             |                 @     @    @ @          |"<<endl;
        cout<<"|       |     |       /-----\\              @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|         \\     \\         @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________          \\_=__/-- @   @    #&*&#   @    @ @     |"<<endl;
        cout<<"|        / |                  /        @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                 /           @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                /              @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerLightningStrikeAttack3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\             -- /                                         |"<<endl;
        cout<<"|        /  \\              |                      @     @             |"<<endl;
        cout<<"|       /____\\             |                  @     @    @ @          |"<<endl;
        cout<<"|       |     |       /-===--\\         /-=-=-@     @  @   @  @        |"<<endl;
        cout<<"|       |-----|         \\     \\        / @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|________          \\ ____/-=--@- @    #&*&#   @    @ @     |"<<endl;
        cout<<"|        / |                  /         @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                 /            @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                /               @   @   @    @            |"<<endl;
        cout<<"|          |___                                 @   @                 |"<<endl;
        cout<<"|         /    |                                                      |"<<endl;
        cout<<"|        /     |                                                      |"<<endl;
        cout<<"|       /      |                                                      |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable1() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|                         @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\                           @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\                         @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |  \\___O                      @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable2() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|                         @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\                           @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\____O                    @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                             @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable3() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|   O                     @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\    |                      @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\___|                     @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                             @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable4() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |                            @     @  @   @  @         |"<<endl;
        cout<<"|       |-----|  O                      @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\     \\                     @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\___|                     @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                             @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
    void playerUseConsumable5() {
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<"         "<<playerR.getPlayerName()<<"                                 "<<enemyR.getEnemyName()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        cout<<endl;
        cout<<"|         /\\                                                         |"<<endl;
        cout<<"|        /  \\                                    @     @             |"<<endl;
        cout<<"|       /____\\                               @     @    @ @          |"<<endl;
        cout<<"|       |     |  w                         @     @  @   @  @         |"<<endl;
        cout<<"|       |-----| www                     @     @    &   @   @ @       |"<<endl;
        cout<<"|         /|\\    w\\                     @   @    #&*&#   @    @ @    |"<<endl;
        cout<<"|        / | \\___|                     @    @  @   &   @  @   @      |"<<endl;
        cout<<"|       /  |                             @  @    @   @   @  @        |"<<endl;
        cout<<"|      /   |                               @   @   @    @            |"<<endl;
        cout<<"|          |___                                @   @                 |"<<endl;
        cout<<"|         /    |                                                     |"<<endl;
        cout<<"|        /     |                                                     |"<<endl;
        cout<<"|       /      |                                                     |"<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }
};



class Map_Display {

protected:

    Player_Info& playerR;
    Text& UI;
    Area_Info& areaR;

public:

    Map_Display(Player_Info& p, Text& t, Area_Info& a) : playerR(p), UI(t), areaR(a) {}

    void map() {

        int x=areaR.X();
        int y=areaR.Y();

        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << right << setw(34) << areaR.getAreaText(x - 3, y + 3)<< "|" << areaR.getAreaText(x - 2, y + 3) << "|" << areaR.getAreaText(x - 1, y + 3) << "|" << areaR.getAreaText(x, y + 3) << "|" << areaR.getAreaText(x+1, y + 3) << "|" << areaR.getAreaText(x + 2, y + 3) << "|" << areaR.getAreaText(x + 3, y + 3) << endl;
        cout << right << setw(34) << areaR.getAreaText(x -3, y + 2) << "|" << areaR.getAreaText(x - 2, y + 2) << "|" << areaR.getAreaText(x - 1, y + 2) << "|" << areaR.getAreaText(x, y + 2) << "|" << areaR.getAreaText(x +1, y + 2) << "|" << areaR.getAreaText(x + 2, y + 2) << "|" << areaR.getAreaText(x + 3, y + 2) << "   HP:      " << playerR.getPlayerHealth() << endl;
        cout << right << setw(34) << areaR.getAreaText(x -3, y + 1) << "|" << areaR.getAreaText(x - 2, y + 1) << "|" << areaR.getAreaText(x - 1, y + 1) << "|" << areaR.getAreaText(x, y + 1) << "|" << areaR.getAreaText(x +1, y + 1) << "|" << areaR.getAreaText(x + 2, y + 1) << "|" << areaR.getAreaText(x + 3, y + 1) << "   DEFENSE: " << playerR.getPlayerDefense() << endl;
        cout << right << setw(34) << areaR.getAreaText(x -3, y) << "|" << areaR.getAreaText(x - 2, y) << "|" << areaR.getAreaText(x - 1, y) << "|" << areaR.getAreaText(x, y) << "|" << areaR.getAreaText(x +1, y) << "|" << areaR.getAreaText(x + 2, y) << "|" << areaR.getAreaText(x + 3, y) << "   MANA:    " << playerR.getPlayerMana() << endl;
        cout << right << setw(34) << areaR.getAreaText(x -3, y-1) << "|" << areaR.getAreaText(x - 2, y - 1) << "|" << areaR.getAreaText(x - 1, y - 1) << "|" << areaR.getAreaText(x, y - 1) << "|" << areaR.getAreaText(x +1, y - 1) << "|" << areaR.getAreaText(x + 2, y - 1) << "|" << areaR.getAreaText(x + 3, y - 1) << endl;
        cout << right << setw(34) << areaR.getAreaText(x -3, y - 2) << "|" << areaR.getAreaText(x - 2, y - 2) << "|" << areaR.getAreaText(x - 1, y - 2) << "|" << areaR.getAreaText(x, y - 2) << "|" << areaR.getAreaText(x +1, y - 2) << "|" << areaR.getAreaText(x + 2, y - 2) << "|" << areaR.getAreaText(x + 3, y - 2) << endl;

        UI.displayMessage(1);
        UI.displayMessage(2);
        UI.displayMessage(3);
        UI.displayMessage(4);
        UI.displayMessage(5);
        UI.displayMessage(6);
    }

};


class Inventory_Info {

protected:

    int itemID;
    string itemName;
    int itemQuantity;
    bool hasItem = false;
    string itemDescription;
    string itemDescription2;
    bool itemNeedsDescription2;
    bool itemNeedsQuantity = false;
    string itemType;

public:

    Inventory_Info() {}
    Inventory_Info(int a, string b, int c, bool d, string e, string h, bool l, bool f, string g) : itemID(a), itemName(b), itemQuantity(c), hasItem(d), itemDescription(e), itemDescription2(h), itemNeedsDescription2(l), itemNeedsQuantity(f), itemType(g) {}

    int getItemID() {
        return itemID;
    }
    string getItemName() {
        return itemName;
    }
    int getItemQuantity() {
        return itemQuantity;
    }
    bool getHasItem() {
        return hasItem;
    }
    string getItemDescription() {
        return itemDescription;
    }
    string getItemDescription2() {
        return itemDescription2;
    }
    bool getItemNeedsDescription2() {
        return itemNeedsDescription2;
    }
    bool getNeedsQuantity() {
        return itemNeedsQuantity;
    }
    string getItemType() {
        return itemType;
    }


    void setItemID(int i) {
        itemID = i;
    }
    void setItemName(string i) {
        itemName = i;
    }
    void setItemQuantity(int i) {
        itemQuantity = i;
    }
    void setHasItem(bool b) {
        hasItem = b;
    }
    void setItemDescription(string i) {
        itemDescription = i;
    }
    void setItemDescription2(string i) {
        itemDescription2 = i;
    }
    void setItemNeedsDescription2(bool b) {
        itemNeedsDescription2 = b;
    }
    void setNeedsQuantity(bool b) {
        itemNeedsQuantity = b;
    }
    void setItemType(string i) {
        itemType = i;
    }
};


class Inventory {

public:

    vector<Inventory_Info> inventoryItems;

    Inventory() : inventoryItems{ //itemID, itemName, itemQuantity, hasItem, itemDescription, itemDescription2, needsItemDescription2, needsQuantity, itemType
        Inventory_Info(0, "Basic robe", 0, true, "Basic ragged robe worn by ordinary folks", "", false, false, "armour"),
        Inventory_Info(1, "Knight armour", 0, false, "Well made armour made for battle against", "elemental creatures. Taken from a knight", true, false, "armour"),
        Inventory_Info(2, "Wizard armour", 0, false, "Magical armour worn by experienced wizards,", "provides a great amount of defense", true, false, "armour"),
        Inventory_Info(3, "Cell key", 0, false, "A rusty key found in a dark prison cell, it has a note attached to it", "'Find the One In The Abyss, do what we could not, save us all'", true, false, "other"),
        Inventory_Info(4, "Fire key", 0, false, "An ornamental, metal key,", "it may open the door to the fire fortress", true, false, "other"),
        Inventory_Info(5, "Lightning key", 0,false, "An ornamental, metal key,", "it may open the door to the Sky Tower", true, false, "other"),
        Inventory_Info(6, "Manor key", 0, false, "A decorated key,", "will open the door to the manor", true, false, "other"),
        Inventory_Info(7, "Wind scroll", 0, false, "A scroll containing the Wind Blast a basic", "spell known by all wizards, from apprentices to masters", true, false, "spell"),
        Inventory_Info(8, "Fire scroll", 0, false, "A scroll containing the Fire Ball,", "a more advanced spell", true, false, "spell"),
        Inventory_Info(9, "Lightning scroll", 0, false, "A scroll containing the Lightning Strike,", "a spell mastered only by the best", true, false, "spell"),
        Inventory_Info(10, "Healing herb", 0, false, "A herb known for its healing properties,", "restores 45 health", true, true, "consumable"),
        Inventory_Info(11, "Repair kit", 0, false, "A repair kit capable of repairing armour,", "temporarily grants 20 defense for the duration of a combat encounter", true, true, "consumable"),
        Inventory_Info(12, "Mana potion", 0, false, "A potion capable of restoring 60 mana", "", false, true, "consumable"),
    } {}

};



class Manage_Consumables {

protected:

    Player_Info& playerR;
    Inventory& invR;

public:

    Manage_Consumables(Player_Info& a, Inventory& b) : playerR(a), invR(b) {}

    virtual void addItem(int amountToAdd) {}

    virtual void removeItem() {}

    virtual void consumeItem() {}

};


class Manage_Healing_Herb : public Manage_Consumables {

public:

    Manage_Healing_Herb(Player_Info& a, Inventory& b) : Manage_Consumables(a, b) {}

    void addItem(int amountToAdd) override {
        if (invR.inventoryItems[10].getHasItem() == false) {
            invR.inventoryItems[10].setHasItem(true);
        }
        invR.inventoryItems[10].setItemQuantity(invR.inventoryItems[10].getItemQuantity() + amountToAdd);
    }
    void removeItem() override {
        invR.inventoryItems[10].setItemQuantity(invR.inventoryItems[10].getItemQuantity() - 1);
        if (invR.inventoryItems[10].getItemQuantity() == 0) {
            invR.inventoryItems[10].setHasItem(false);
        }
    }
    void consumeItem() override {
        if (playerR.getPlayerHealth() + 45 > playerR.getPlayerMaxHealth()) {
            playerR.setPlayerHealth(playerR.getPlayerMaxHealth());
        }
        else {
            playerR.setPlayerHealth(playerR.getPlayerHealth() + 45);
        }
    }
};


class Manage_Repair_Kit : public Manage_Consumables {

public:

    Manage_Repair_Kit(Player_Info& a, Inventory& b) : Manage_Consumables(a, b) {}

    void addItem(int amountToAdd) override {
        if (invR.inventoryItems[11].getHasItem() == false) {
            invR.inventoryItems[11].setHasItem(true);
        }
        invR.inventoryItems[11].setItemQuantity(invR.inventoryItems[11].getItemQuantity() + amountToAdd);
    }
    void removeItem() override {
        invR.inventoryItems[11].setItemQuantity(invR.inventoryItems[11].getItemQuantity() - 1);
        if (invR.inventoryItems[11].getItemQuantity() == 0) {
            invR.inventoryItems[11].setHasItem(false);
        }
    }
    void consumeItem() override {
        playerR.setPlayerDefense(playerR.getPlayerDefense() + 20);
    }
};


class Manage_Mana_Potion : public Manage_Consumables {

public:

    Manage_Mana_Potion(Player_Info& a, Inventory& b) : Manage_Consumables(a, b) {}

    void addItem(int amountToAdd) override {
        if (invR.inventoryItems[12].getHasItem() == false) {
            invR.inventoryItems[12].setHasItem(true);
        }
        invR.inventoryItems[12].setItemQuantity(invR.inventoryItems[12].getItemQuantity() + amountToAdd);
    }
    void removeItem() override {
        invR.inventoryItems[12].setItemQuantity(invR.inventoryItems[12].getItemQuantity() - 1);
        if (invR.inventoryItems[12].getItemQuantity() == 0) {
            invR.inventoryItems[12].setHasItem(false);
        }
    }
    void consumeItem() override {
        playerR.setPlayerMana(playerR.getPlayerMana() + 60);
        if (playerR.getPlayerMana() > playerR.getPlayerMaxMana()) {
            playerR.setPlayerMana(playerR.getPlayerMaxMana());
        }
    }
};



class Manage_keys {

protected:

    Inventory& invR;
    Text& UI;

public:

    Manage_keys(Inventory& a, Text& t) : invR(a), UI(t) {}

    virtual void addItem() {}

    virtual void useItem() {}
};


class Manage_Cell_Key : public Manage_keys {

public:

    Manage_Cell_Key(Inventory& a, Text& t) : Manage_keys(a, t) {}

    void addItem() override {
        if (invR.inventoryItems[3].getHasItem() == false) {
            invR.inventoryItems[3].setHasItem(true);
        }
    }

    void useItem() override {
        UI.setMessage(1, "Used cell key");
    }
};


class Manage_Fire_Key : public Manage_keys {

public:

    Manage_Fire_Key(Inventory& a, Text& t) : Manage_keys(a, t) {}

    void addItem() override {
        if (invR.inventoryItems[4].getHasItem() == false) {
            invR.inventoryItems[4].setHasItem(true);
        }
    }

    void useItem() override {
        UI.setMessage(1, "Used fire key");
    }
};


class Manage_Lightning_Key : public Manage_keys {

public:

    Manage_Lightning_Key(Inventory& a, Text& t) : Manage_keys(a, t) {}

    void addItem() override {
        if (invR.inventoryItems[5].getHasItem() == false) {
            invR.inventoryItems[5].setHasItem(true);
        }
    }

    void useItem() override {
        UI.setMessage(1, "Used lighting key");
    }
};


class Manage_Manor_Key : public Manage_keys {

public:

    Manage_Manor_Key(Inventory& a, Text& t) : Manage_keys(a, t) {}

    void addItem() override {
        if (invR.inventoryItems[6].getHasItem() == false) {
            invR.inventoryItems[6].setHasItem(true);
        }
    }

    void useItem() override {
        UI.setMessage(1, "Used manor key");
    }
};



class Manage_Coins {

protected:

    Player_Info& playerR;

public:

    Manage_Coins(Player_Info& a) : playerR(a) {}

    void addCoins(int amountToAdd) {
        playerR.setCoins(playerR.getCoins() + amountToAdd);
    }

    void removeCoins(int amountToRemove) {
        playerR.setCoins(playerR.getCoins() - amountToRemove);
        if (playerR.getCoins() < 0) {
            playerR.setCoins(0);
        }
    }
};



class Manage_Spells {

protected:

    Inventory& invR;
    Player_Info& playerR;

public:

    Manage_Spells(Inventory& a, Player_Info& b) : invR(a), playerR(b) {}

    virtual void addItem() {}

    virtual void useSpell() {}

    virtual int getDamage() {}
};


class Manage_Wind_Blast : public Manage_Spells {

private:

    int damage=20;

public:

    Manage_Wind_Blast(Inventory& a, Player_Info& b) : Manage_Spells(a, b) {}

    void addItem() override {
        if (invR.inventoryItems[7].getHasItem() == false) {
            invR.inventoryItems[7].setHasItem(true);
        }
    }

    void useSpell() override {
        playerR.setPlayerMana(playerR.getPlayerMana() - 20);
        if (playerR.getPlayerMana() < 0) {
            playerR.setPlayerMana(0);
        }
    }

    int getDamage() override {
        return this->damage;
    }
};


class Manage_Fire_Ball : public Manage_Spells {

private:

    int damage = 40;

public:

    Manage_Fire_Ball(Inventory& a, Player_Info& b) : Manage_Spells(a, b) {}

    void addItem() override {
        if (invR.inventoryItems[8].getHasItem() == false) {
            invR.inventoryItems[8].setHasItem(true);
        }
    }

    void useSpell() override {
        playerR.setPlayerMana(playerR.getPlayerMana() - 30);
        if (playerR.getPlayerMana() < 0) {
            playerR.setPlayerMana(0);
        }
    }

    int getDamage() override {
        return this->damage;
    }
};


class Manage_Lightning_Strike : public Manage_Spells {

private:

    int damage = 60;

public:

    Manage_Lightning_Strike(Inventory& a, Player_Info& b) : Manage_Spells(a, b) {}

    void addItem() override {
        if (invR.inventoryItems[9].getHasItem() == false) {
            invR.inventoryItems[9].setHasItem(true);
        }
    }

    void useSpell() override {
        playerR.setPlayerMana(playerR.getPlayerMana() - 40);
        if (playerR.getPlayerMana() < 0) {
            playerR.setPlayerMana(0);
        }
    }

    int getDamage() override {
        return this->damage;
    }
};



class Manage_Armour {

protected:

    Player_Info& playerR;
    Inventory& invR;

public:

    Manage_Armour(Player_Info& p, Inventory& i) : playerR(p), invR(i) {}

    virtual void equipArmour() {}

    virtual void addItem() {}
};


class Manage_Basic_Robes : public Manage_Armour {

public:

    Manage_Basic_Robes(Player_Info& a, Inventory& i) : Manage_Armour(a, i) {}

    void equipArmour() override {
        playerR.setPlayerMaxDefense(20);
        playerR.setPlayerDefense(20);
    }
};


class Manage_Knight_Armour : public Manage_Armour {

public:

    Manage_Knight_Armour(Player_Info& a, Inventory& i) : Manage_Armour(a, i) {}

    void equipArmour() override {
        playerR.setPlayerMaxDefense(40);
        playerR.setPlayerDefense(40);
    }

    void addItem() override {
        invR.inventoryItems[1].setHasItem(true);
    }
};


class Manage_Wizard_Armour : public Manage_Armour {

public:

    Manage_Wizard_Armour(Player_Info& a, Inventory& i) : Manage_Armour(a, i) {}

    void equipArmour() override {
        playerR.setPlayerMaxDefense(60);
        playerR.setPlayerDefense(60);
    }

    void addItem() override {
        invR.inventoryItems[2].setHasItem(true);
    }

};



enum class CombatState {
    idle,
    playerTurn,
    enemyTurn,

    windBlast,
    fireBall,
    lightningStrike,
    usingConsumable,

    playerDodged,
    enemyDodged,

    enemyAttacking,
    enemyHit,
    playerHit,

    enemyDeath,
    playerDeath
};


class Combat_Encounter {

protected:

    Player_Info& playerR;
    Enemy_Info& enemyR;
    Area_Info& areaR;
    Text& UI;
    Inventory& invR;

    CombatState combatState = CombatState::idle;

    bool encounterComplete=false;

    int playerDamage=0;
    int enemyDamage=0;

    int applyDefense(int damage, int defensePercent) {
        return damage * (100 - defensePercent) / 100;
    }

public:

    Combat_Encounter(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): enemyR(e), playerR(p), areaR(a), UI(t), invR(i) {}

    virtual void setEnemydata() {}

    virtual bool inActivationArea() {return false;}


    virtual void victory() {}

    void death() {
        combatState = CombatState::playerDeath;
        displayAnimation();
        this_thread::sleep_for(chrono::milliseconds(2000));
        UI.setMessage(1, "You died");
        this_thread::sleep_for(chrono::milliseconds(2000));
        exit(0);
    }


    virtual void displayAnimation() {}

    void displayUI() {
        cout<<endl;
        cout<<"Health: "<<playerR.getPlayerHealth()<<endl;
        cout<<"                                               Enemy health: "<<enemyR.getEnemyHealth()<<endl;
        cout<<"Mana: "<<playerR.getPlayerMana()<<endl;
        cout<<"|--------------------------------------------------------------------|"<<endl;
        UI.displayMessage(1);
        UI.displayMessage(2);
        cout<<"|--------------------------------------------------------------------|"<<endl;
        if(invR.inventoryItems[7].getHasItem() == true) {cout<<"1. Attack with wind blast (20 mana)"<<endl;}
        if(invR.inventoryItems[8].getHasItem() == true) {cout<<"2. Attack with fire ball (30 mana)"<<endl;}
        if(invR.inventoryItems[9].getHasItem() == true) {cout<<"3. Attack with lightning strike (40 mana)"<<endl;}
        cout<<endl;
        if(invR.inventoryItems[10].getHasItem() == true) {cout<<"4. Use healing herb. You have: "<<invR.inventoryItems[10].getItemQuantity()<<endl;}
        if(invR.inventoryItems[11].getHasItem() == true) {cout<<"5. Use repair kit. You have: "<<invR.inventoryItems[11].getItemQuantity()<<endl;}
        if(invR.inventoryItems[12].getHasItem() == true) {cout<<"6. Drink mana potion. You have: "<<invR.inventoryItems[12].getItemQuantity()<<endl;}
        cout<<"|--------------------------------------------------------------------|"<<endl;
    }


    void combat() {
        if(inActivationArea() && encounterComplete==false) {
            setEnemydata();
            encounterComplete = false;

            while (!encounterComplete) {
                combatState=CombatState::idle;
                displayAnimation();
                displayUI();


                cout<<"Action: "<<endl;
                char key = _getch();

                switch(key) {
                    case '1': input="1"; break;
                    case '2': input="2"; break;
                    case '3': input="3"; break;
                    case '4': input="4"; break;
                    case '5': input="5"; break;
                    case '6': input="6"; break;
                    default: input="other"; break;
                }

                bool playerActed=false;

                if      (invR.inventoryItems[7].getHasItem()==true && input=="1") playerActed=useWindBlast();
                else if (invR.inventoryItems[8].getHasItem()==true && input=="2") playerActed=useFireBall();
                else if (invR.inventoryItems[9].getHasItem()==true && input=="3") playerActed=useLightningStrike();
                else if (invR.inventoryItems[10].getHasItem()==true && input=="4") playerActed=useHealingHerb();
                else if (invR.inventoryItems[11].getHasItem()==true && input=="5") playerActed=useRepairKit();
                else if (invR.inventoryItems[12].getHasItem()==true && input=="6") playerActed=useManaPotion();
                else {UI.setMessage(1, "There is no such choice");}

                if (enemyR.getEnemyHealth()<=0) {
                    victory();
                    break;
                }

                if(!playerActed) {
                    continue;
                }

                this_thread::sleep_for(chrono::milliseconds(1500));
                enemyAttack();

                if (playerR.getPlayerHealth()<=0) {
                    death();
                    break;
                }
            }
        }
    }

    bool useWindBlast() {
        Manage_Wind_Blast spell(invR, playerR);

        if (playerR.getPlayerMana() < 20) {
            UI.setMessage(1, "Not enough mana");
            return false;
        }

        combatState = CombatState::windBlast;
        displayAnimation();

        spell.useSpell();

        playerDamage = applyDefense(spell.getDamage(), enemyR.getEnemyDefense());
        enemyR.setEnemyHealth(enemyR.getEnemyHealth() - playerDamage);

        combatState = CombatState::enemyHit;
        displayAnimation();

        return true;
    }

    bool useFireBall() {
        Manage_Fire_Ball spell(invR, playerR);

        if (playerR.getPlayerMana() < 30) {
            UI.setMessage(1, "Not enough mana");
            return false;
        }

        combatState = CombatState::fireBall;
        displayAnimation();

        spell.useSpell();

        playerDamage = applyDefense(spell.getDamage(), enemyR.getEnemyDefense());
        enemyR.setEnemyHealth(enemyR.getEnemyHealth() - playerDamage);

        combatState = CombatState::enemyHit;
        displayAnimation();

        return true;
    }

    bool useLightningStrike() {
        Manage_Lightning_Strike spell(invR, playerR);

        if (playerR.getPlayerMana() < 40) {
            UI.setMessage(1, "Not enough mana");
            return false;
        }

        combatState = CombatState::lightningStrike;
        displayAnimation();

        spell.useSpell();

        playerDamage = applyDefense(spell.getDamage(), enemyR.getEnemyDefense());
        enemyR.setEnemyHealth(enemyR.getEnemyHealth() - playerDamage);

        combatState = CombatState::enemyHit;
        displayAnimation();

        return true;
    }

    bool useHealingHerb() {
        Manage_Healing_Herb consumable(playerR, invR);

        combatState = CombatState::usingConsumable;
        displayAnimation();

        consumable.consumeItem();
        consumable.removeItem();

        return true;
    }

    bool useRepairKit() {
        Manage_Repair_Kit consumable(playerR, invR);

        combatState = CombatState::usingConsumable;
        displayAnimation();

        consumable.consumeItem();
        consumable.removeItem();

        return true;
    }

    bool useManaPotion() {
        Manage_Mana_Potion consumable(playerR, invR);

        combatState = CombatState::usingConsumable;
        displayAnimation();

        consumable.consumeItem();
        consumable.removeItem();

        return true;
    }


    void enemyAttack() {
        combatState = CombatState::enemyAttacking;
        displayAnimation();

        enemyDamage = applyDefense(enemyR.getEnemyDamage(), playerR.getPlayerDefense());

        playerR.setPlayerHealth(playerR.getPlayerHealth() - enemyDamage);

        combatState = CombatState::playerHit;
        displayAnimation();
    }
};


class Combat_Encounter1 : public Combat_Encounter {

public:

    Combat_Encounter1(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("Skeleton");
        enemyR.setEnemyHealth(50);
        enemyR.setEnemyDefense(0);
        enemyR.setEnemyDamage(10);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==9 && y==13) ||
            (x==10 && y==13) ||
            (x==11 && y==13) ||
            (x==12 && y==13) ||
            (x==13 && y==13);
        if(!encounterComplete && near) {
            UI.setMessage(1, "Press 1 - 6 to perform an action");
            cout<<"Something moves in the dark"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();

        Manage_Healing_Herb healingHerb(playerR, invR);
        Manage_Mana_Potion manaPotion(playerR, invR);
        healingHerb.addItem(2);
        manaPotion.addItem(2);

        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "Enemy defeated!");
        UI.setMessage(2, "You got: 2 healing herbs");
        UI.setMessage(3, "You got: 2 mana potions");
        UI.setMessage(4, "Press 'i' to access the inventory");
        encounterComplete = true;
    }

    void displayAnimation() override {
        skeletonAnimation skeleton(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"The enemy attacks");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                skeleton.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerDeath3();
                displayUI();
                break;

            default:
                skeleton.idle();
            break;
        }
    }

};


class Combat_Encounter2 : public Combat_Encounter {

public:

    Combat_Encounter2(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("Wandering soldier");
        enemyR.setEnemyHealth(60);
        enemyR.setEnemyDefense(20);
        enemyR.setEnemyDamage(15);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==4 && y==14) ||
            (x==5 && y==14) ||
            (x==6 && y==14) ||
            (x==7 && y==14) ||
            (x==8 && y==14);
        if(!encounterComplete && near) {
            cout<<"You notice a humanoid figure walking towards you"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();

        Manage_Repair_Kit repairKit(playerR, invR);
        Manage_Healing_Herb healingHerb(playerR, invR);
        Manage_Fire_Ball fireScroll(invR, playerR);
        repairKit.addItem(2);
        healingHerb.addItem(3);
        fireScroll.addItem();

        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "Enemy defeated!");
        UI.setMessage(2, "You got: the fire scroll");
        UI.setMessage(3, "          2 repair kits");
        UI.setMessage(4, "          3 healing herbs");
        encounterComplete = true;
    }

    void displayAnimation() override {
        soldierAnimation soldier(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"The enemy attacks");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                soldier.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath3();
                displayUI();
                break;

            default:
                soldier.idle();
            break;
        }
    }

};


class Combat_Encounter3 : public Combat_Encounter {

public:

    Combat_Encounter3(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("Burnt skeleton");
        enemyR.setEnemyHealth(60);
        enemyR.setEnemyDefense(15);
        enemyR.setEnemyDamage(15);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==4 && y==12) ||
            (x==5 && y==12) ||
            (x==6 && y==12);
        if(!encounterComplete && near) {
            cout<<"A skeleton approaches"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();

        Manage_Repair_Kit repairKit(playerR, invR);
        Manage_Healing_Herb healingHerb(playerR, invR);
        repairKit.addItem(1);
        healingHerb.addItem(1);

        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "Enemy defeated!");
        UI.setMessage(2, "You got 1 repair kit");
        UI.setMessage(3, "You got 1 healing herb");
        encounterComplete = true;
    }

    void displayAnimation() override {
        skeletonAnimation skeleton(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"The enemy attacks");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                skeleton.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                skeleton.playerDeath3();
                displayUI();
                break;

            default:
                skeleton.idle();
            break;
        }
    }

};


class Combat_Encounter4 : public Combat_Encounter {

public:

    Combat_Encounter4(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("Soldier");
        enemyR.setEnemyHealth(60);
        enemyR.setEnemyDefense(25);
        enemyR.setEnemyDamage(10);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==18 && y==4) ||
            (x==18 && y==5);

        if(!encounterComplete && near) {
            cout<<"You are ambushed by a soldier"<<endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();

        Manage_Mana_Potion manaPotions(playerR, invR);
        manaPotions.addItem(2);

        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "Enemy defeated!");
        UI.setMessage(2, "You got 2 mana potions");
        encounterComplete = true;
    }

    void displayAnimation() override {
        soldierAnimation soldier(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"The enemy attacks");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                soldier.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath3();
                displayUI();
                break;

            default:
                soldier.idle();
            break;
        }
    }

};


class Combat_Encounter5 : public Combat_Encounter {

public:

    Combat_Encounter5(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("The Fire King");
        enemyR.setEnemyHealth(80);
        enemyR.setEnemyDefense(35);
        enemyR.setEnemyDamage(20);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==10 && y==16) ||
            (x==11 && y==16) ||
            (x==12 && y==16) ||
            (x==13 && y==16) ||
            (x==14 && y==16);

        if(!encounterComplete && near) {
            cout<<"Before you the fire king stand up from his throne"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();

        Manage_Manor_Key manorKey(invR, UI);
        Manage_Healing_Herb healingHerb(playerR, invR);
        Manage_Mana_Potion manaPotion(playerR, invR);
        manorKey.addItem();
        healingHerb.addItem(2);
        manaPotion.addItem(2);

        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "The fire king is slain!");
        UI.setMessage(2, "You got: the manor key");
        UI.setMessage(3, "             2 healing herbs");
        UI.setMessage(4, "             2 mana potions");
        encounterComplete = true;
    }

    void displayAnimation() override {
        fireKingAnimation soldier(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"The enemy attacks");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                soldier.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath3();
                displayUI();
                break;

            default:
                soldier.idle();
            break;
        }
    }

};


class Combat_Encounter6 : public Combat_Encounter {

public:

    Combat_Encounter6(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("Soldier captain");
        enemyR.setEnemyHealth(70);
        enemyR.setEnemyDefense(30);
        enemyR.setEnemyDamage(18);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==6 && y==16) ||
            (x==5 && y==17) ||
            (x==4 && y==18);

        if(!encounterComplete && near) {
            cout<<"You are ambushed by a soldier"<<endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();

        Manage_Lightning_Key lightningKey(invR, UI);
        Manage_Mana_Potion manaPotion(playerR, invR);
        lightningKey.addItem();
        manaPotion.addItem(2);

        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "Enemy defeated!");
        UI.setMessage(2, "You got: the lighting key");
        UI.setMessage(3, "           2 mana potions");
        encounterComplete = true;
    }

    void displayAnimation() override {
        soldierAnimation soldier(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"The enemy attacks");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                soldier.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath3();
                displayUI();
                break;

            default:
                soldier.idle();
            break;
        }
    }

};


class Combat_Encounter7 : public Combat_Encounter {

public:

    Combat_Encounter7(Enemy_Info& e, Player_Info& p, Area_Info& a, Text& t, Inventory& i): Combat_Encounter(e, p, a, t, i) {}

    void setEnemydata() override {
        enemyR.setEnemyName("@hYrn&s#Sq");
        enemyR.setEnemyHealth(150);
        enemyR.setEnemyDefense(25);
        enemyR.setEnemyDamage(25);
    }

    bool inActivationArea() override {

        int x=areaR.X();
        int y=areaR.Y();

        bool near=
            (x==10 && y==19) ||
            (x==11 && y==19) ||
            (x==12 && y==19) ||
            (x==9 && y==20) ||
            (x==13 && y==20);

        if(!encounterComplete && near) {
            cout<<"Something terrible emerges from the floor"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Prepare for combat"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        return near;

    }

    void victory() override {
        combatState = CombatState::enemyDeath;
        displayAnimation();


        if(playerR.getPlayerDefense()>playerR.getPlayerMaxDefense()) {
            playerR.setPlayerDefense(playerR.getPlayerMaxDefense());
        }

        UI.setMessage(1, "It has fallen!");
        encounterComplete = true;
        this_thread::sleep_for(chrono::milliseconds(4000));

        Epilogue epilogue(playerR);
        epilogue.playEpilogue();
    }

    void displayAnimation() override {
        abyssCreatureAnimation soldier(playerR, enemyR);

        switch(combatState) {

            case CombatState::enemyAttacking:
                UI.setMessage(1,"it conjures an attack");
                this_thread::sleep_for(chrono::milliseconds(800));
                system("cls");
                soldier.enemyAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyAttack4();
                displayUI();

                break;

            case CombatState::playerHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerHit3();
                displayUI();

                UI.setMessage(1,"You were hit for "+to_string(enemyDamage)+" damage");
                break;

            case CombatState::enemyHit:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyHit3();
                UI.setMessage(1,"You dealt "+to_string(playerDamage)+" damage");
                displayUI();

                break;

            case CombatState::enemyDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.enemyDeath3();
                displayUI();
                break;

            case CombatState::windBlast:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerWindBlastAttack3();
                displayUI();
                break;

            case CombatState::fireBall:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerFireBallAttack3();
                displayUI();
                break;

            case CombatState::lightningStrike:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerLightningStrikeAttack3();
                displayUI();
                break;

            case CombatState::usingConsumable:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable3();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable4();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerUseConsumable5();
                if(input=="4") {
                    UI.setMessage(1, "Recovered 45 HP");
                }
                if(input=="5") {
                    UI.setMessage(1, "Added 20 defense");
                }
                if(input=="6") {
                    UI.setMessage(1, "Recovered 60 mana");
                }
                displayUI();
                break;

            case CombatState::playerDeath:
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath1();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath2();
                displayUI();

                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                soldier.playerDeath3();
                displayUI();
                break;

            default:
                soldier.idle();
            break;
        }
    }

};



class Door {

protected:

    Inventory& invR;
    Area_Info& areaR;
    Text& UI;

    bool doorUnlocked = false;

public:

    Door(Inventory& i, Area_Info& a, Text& t) : invR(i), areaR(a), UI(t) {}

    bool inActivationArea(int x, int y, bool needsUnlock) {

        bool near = (x == areaR.X() && y == areaR.Y());

        if (near && !doorUnlocked) {
            if (needsUnlock == true) {
                UI.setMessage(1, "Press 'e' to unlock ");
            }
            else {
                UI.setMessage(1, "Press 'e' to open");
            }
        }
        return near;
    }

    void createDoor(int x, int y, int map) {
        if(location==map && !doorUnlocked) {
            areaR.setArea(x, y, "D", 4);
        }
    }

    virtual void openDoor() {}

    void initialize(int x, int y, int map) {
        createDoor(x, y, map);
        openDoor();
    }
};


class Door_Key: public Door {

public:

    Door_Key(Inventory& i, Area_Info& a, Text& t): Door(i, a, t) {}

    bool hasKey(int keyID) {
        if (invR.inventoryItems[keyID].getHasItem() == true) {
            return true;
        }
        else {
            return false;
        }
    }

    void unlockDoor(string text) {
        doorUnlocked = true;
        UI.setMessage(1, text);
    }

    void removeDoor(int x, int y) {
        areaR.setArea(x, y, "_", 1);
    }

};


class Door1key: public Door_Key {

public:

    Door1key(Inventory& i, Area_Info& a, Text& t): Door_Key(i, a, t) {}


    void openDoor() override {
        if(inActivationArea(6, 9, true) && input == "e" && hasKey(3)) {
            this_thread::sleep_for(chrono::milliseconds(600));
            removeDoor(6, 10);
            unlockDoor("Used cell key");
        }
        else if(inActivationArea(6, 9, true) && input == "e" && !hasKey(3)) {
            UI.setMessage(1, "The door is locked");
        }
    }
};


class Door2 : public Door {

public:

    Door2(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(8, 16, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_1();
            areaR.setPlayerCharacter(10, 6);
            UI.clearMessage();
            location=1;
        }
    }
};


class Door2back : public Door {

public:

    Door2back(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(10, 5, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_0();
            areaR.setPlayerCharacter(7, 16);
            UI.clearMessage();
            location=0;
        }
    }
};


class Door3 : public Door {

public:

    Door3(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(10, 15, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_2();
            areaR.setPlayerCharacter(6, 5);
            UI.clearMessage();
            location=2;
        }
    }
};


class Door3back : public Door {

public:

    Door3back(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(6, 4, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_1();
            areaR.setPlayerCharacter(10, 14);
            UI.clearMessage();
            location=1;
        }
    }
};


class Door4key: public Door_Key {

public:

    Door4key(Inventory& i, Area_Info& a, Text& t): Door_Key(i, a, t) {}


    void openDoor() override {
        if(inActivationArea(8, 11, true) && input == "e" && hasKey(5)) {
            this_thread::sleep_for(chrono::milliseconds(600));
            removeDoor(9, 11);
            unlockDoor("Used lightning key");
        }
        else if(inActivationArea(8, 11, true) && input == "e" && !hasKey(5)) {
            UI.setMessage(1, "You need the lightning key to unlock this door");
        }
    }
};


class Door5 : public Door {

public:

    Door5(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(6, 16, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_3();
            areaR.setPlayerCharacter(12, 5);
            UI.clearMessage();
            location=3;
        }
    }
};


class Door5back : public Door {

public:

    Door5back(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(12, 4, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_2();
            areaR.setPlayerCharacter(6, 15);
            UI.clearMessage();
            location=2;
        }
    }
};


class Door6key: public Door_Key {

public:

    Door6key(Inventory& i, Area_Info& a, Text& t): Door_Key(i, a, t) {}


    void openDoor() override {
        if(inActivationArea(12, 9, true) && input == "e" && hasKey(4)) {
            this_thread::sleep_for(chrono::milliseconds(600));
            removeDoor(12, 10);
            unlockDoor("Used fire key");
        }
        else if(inActivationArea(12, 9, true) && input == "e" && !hasKey(4)) {
            UI.setMessage(1, "You need the fire key to unlock this door");
        }
    }
};


class Door7 : public Door {

public:

    Door7(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(12, 21, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_4();
            areaR.setPlayerCharacter(5, 5);
            UI.clearMessage();
            location=4;
        }
    }
};


class Door7back : public Door {

public:

    Door7back(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(5, 4, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_3();
            areaR.setPlayerCharacter(12, 20);
            UI.clearMessage();
            location=3;
        }
    }
};


class Door8: public Door {

public:

    Door8(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(17, 17, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_5();
            areaR.setPlayerCharacter(11, 5);
            UI.clearMessage();
            location=5;
        }
    }
};


class Door8back: public Door {

public:

    Door8back(Inventory& i, Area_Info& a, Text& t) : Door(i, a, t) {}

    void openDoor() override {
        if (inActivationArea(11, 4, false) && input == "e") {
            this_thread::sleep_for(chrono::milliseconds(600));
            areaR.clearMap();
            this_thread::sleep_for(chrono::milliseconds(400));
            areaR.loading_map_4();
            areaR.setPlayerCharacter(16, 17);
            UI.clearMessage();
            location=4;
        }
    }
};



class LootCrate {

protected:

    Inventory& invR;
    Area_Info& areaR;
    Text& UI;
    Player_Info& playerR;

    bool lootCrateOpened = false;

public:

    LootCrate(Inventory& i, Area_Info& a, Text& t, Player_Info& p): invR(i), areaR(a), UI(t), playerR(p) {}

    virtual bool inActivationArea(int x, int y, string text) {
        if (lootCrateOpened) {
        return false;
    }

        bool near =
                (x==areaR.X() && y==areaR.Y()+1) ||
                (x==areaR.X() && y==areaR.Y()-1) ||
                (x==areaR.X()-1 && y==areaR.Y()) ||
                (x==areaR.X()+1 && y==areaR.Y());

        if (near) {
            UI.setMessage(1, text);
            return true;
        }
        return false;
    }

    virtual void addLoot() {}

    void createLootCrate(int x, int y) {
        if (!lootCrateOpened) {
            areaR.setArea(x, y, "L", 5);
        }
    }

    void removeLootCrate(int x, int y) {
        areaR.setArea(x, y, "_", 1);
    }

    virtual void openLootCrate(int x, int y) {}

    void initialize(int x, int y) {
        createLootCrate(x, y);
        openLootCrate(x, y);
    }

};


class LootCrate1 : public LootCrate {

public:

    LootCrate1(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}

    void addLoot() override {
        Manage_Cell_Key cellKey(invR, UI);

        cellKey.addItem();
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to look through the garbage")) {
            if (input == "e") {
                addLoot();
                UI.setMessage(1, "Among the mud you find a rusty key");
                removeLootCrate(x, y);
                lootCrateOpened = true;
            }
        }
    }
};


class LootCrate2 : public LootCrate {

public:

    LootCrate2(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Wind_Blast windBlast(invR, playerR);
        windBlast.addItem();
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open the chest")) {
            if (input == "e") {
                addLoot();
                UI.setMessage(1, "In the chest you find a leftover magic scroll");
                removeLootCrate(x, y);
                lootCrateOpened = true;
            }
        }
    }
};


class LootCrate3 : public LootCrate {

public:

    LootCrate3(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Mana_Potion manaPotion(playerR, invR);

        manaPotion.addItem(2);
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open the chest")) {
            if(input=="e") {
            addLoot();
            UI.setMessage(1, "You found 2 mana potions");
            removeLootCrate(x, y);
            lootCrateOpened=true;
            }
        }
    }
};


class LootCrate4 : public LootCrate {

public:

    LootCrate4(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Mana_Potion manaPotion(playerR, invR);

        manaPotion.addItem(2);
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open the chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found 2 mana potions");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate5 : public LootCrate {

public:

    LootCrate5(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Lightning_Strike lightningStrike(invR, playerR);

        lightningStrike.addItem();
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open the chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found the lightning scroll");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate6 : public LootCrate {

public:

    LootCrate6(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Knight_Armour knightArmour(playerR, invR);

        knightArmour.addItem();
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to inspect corpse")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found a suit of armour");
                UI.setMessage(2, "it can be equipped in the inventory (i)");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate7 : public LootCrate {

public:

    LootCrate7(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Mana_Potion manaPotion(playerR, invR);
        Manage_Healing_Herb healingHerb(playerR, invR);

        manaPotion.addItem(2);
        healingHerb.addItem(2);
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found: 2 mana potions,");
                UI.setMessage(2, "           2 healing herbs");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate8 : public LootCrate {

public:

    LootCrate8(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Fire_Key fireKey(invR, UI);

        fireKey.addItem();
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found the fire key");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate9 : public LootCrate {

public:

    LootCrate9(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Wizard_Armour wizardAmour(playerR, invR);

        wizardAmour.addItem();
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found a valuable suit of wizard armour");
                UI.setMessage(2, "it can be equipped in the inventory (i)");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate10 : public LootCrate {

public:

    LootCrate10(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Mana_Potion manaPotion(playerR, invR);
        Manage_Healing_Herb healingHerb(playerR, invR);

        manaPotion.addItem(3);
        healingHerb.addItem(3);
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found: 3 mana potions,");
                UI.setMessage(2, "           3 healing herbs");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};


class LootCrate11 : public LootCrate {

public:

    LootCrate11(Inventory& i, Area_Info& a, Text& t, Player_Info& p) : LootCrate(i, a, t, p) {}


    void addLoot() override {
        Manage_Repair_Kit repairKit(playerR, invR);

        repairKit.addItem(3);
    }

    void openLootCrate(int x, int y) override {
        if (lootCrateOpened == false && inActivationArea(x, y, "Press 'e' to open chest")) {
            if(input=="e") {
                addLoot();
                UI.setMessage(1, "You found 3 repair kits");
                removeLootCrate(x, y);
                lootCrateOpened=true;
            }
        }
    }
};



class Point_Of_Interest {

protected:

    Text& UI;
    Area_Info& areaR;

public:

    Point_Of_Interest(Text& t, Area_Info& a): UI(t), areaR(a) {}

    virtual void setupMessage() {}

    bool inActivationArea(int x, int y) {
        bool near = (x == areaR.X() && y == areaR.Y());

        if (near) {
            UI.setMessage(1, "Press 'e' to inspect");
        }
        return near;
    }

    void setupArea(int x, int y) {
        areaR.setArea(x, y, "?", 6);
    }

    void initialize(int x, int y, int x1, int y1, int map) {
        if(location==map) {
            setupArea(x, y);
        }
        if(inActivationArea(x1, y1) && input=="e") {
            setupMessage();
        }
    }
};


class Point_Of_Interest1: public Point_Of_Interest{

public:

    Point_Of_Interest1(Text& t, Area_Info& a): Point_Of_Interest(t, a) {}

    void setupMessage() override {
        UI.setMessage(1, "There are many scratch marks on the wall,");
        UI.setMessage(2, "counting the many days spent here");
    }
};


class Point_Of_Interest3: public Point_Of_Interest{

public:

    Point_Of_Interest3(Text& t, Area_Info& a): Point_Of_Interest(t, a) {}

    void setupMessage() override {
        UI.setMessage(1, "There is a written message on the stone wall,");
        UI.setMessage(2, "'Any prisoners escaping think twice before proceeding");
        UI.setMessage(3, "your return to the cell will not be so nice if you're caught again'");
    }
};


class Point_Of_Interest4: public Point_Of_Interest{

public:

    Point_Of_Interest4(Text& t, Area_Info& a): Point_Of_Interest(t, a) {}

    void setupMessage() override {
        UI.setMessage(1, "There is a bunch of messy writing on the wall,");
        UI.setMessage(2, "it speaks of some dangerous abomination deep in the manor");
        UI.setMessage(3, "outside the castle.");
        UI.setMessage(4, "Whatever it is. It appears to have affected the king's mind");
    }
};


class Point_Of_Interest5: public Point_Of_Interest{

public:

    Point_Of_Interest5(Text& t, Area_Info& a): Point_Of_Interest(t, a) {}

    void setupMessage() override {
        UI.setMessage(1, "There is a strange glowing blue slime on the grass");
    }
};



class Inventory_Page {

protected:

    Inventory& invR;
    Player_Info& playerR;
    Text& UI;

    string subchoice;
    int selectedItem = 0;

public:

    Inventory_Page(Player_Info& p, Inventory& i, Text& t) : invR(i), playerR(p), UI(t) {}

    virtual void openInventoryPage() {}

};


class Inventory_Page1 : public Inventory_Page {

public:

    Inventory_Page1(Player_Info& p, Inventory& i, Text& t) : Inventory_Page(p, i, t) {}

    void openInventoryPage() override {
        while (true) {
            UI.setMessage(1, "Type in the item ID + ENTER to inspect them");
            UI.setMessage(2, "Type 'b' to go back");

            system("cls");

            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            cout << setw(31) << "|" << "      CONSUMABLES      " << "|" << endl;
            cout << setw(31) << "|" << "-----------------------" << "|" << endl;
            cout << setw(31) << "|" << "                       " << endl;
            for (int i = 0; i < invR.inventoryItems.size(); i++) {
                if (invR.inventoryItems[i].getItemType() == "consumable" && invR.inventoryItems[i].getHasItem() == true) {
                    cout << setw(31) << "|" << "   " << invR.inventoryItems[i].getItemID() << ". " << invR.inventoryItems[i].getItemName() << endl;
                }
            }
            cout << setw(31) << "|" << "                       " << endl;
            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            UI.displayMessage(1);
            UI.displayMessage(2);

            cout << endl;
            cout << "Action:" << endl;
            cin >> subchoice;

            if (subchoice == "b") {
                cout << "Returning..." << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                UI.clearMessage();
                subchoice = "";
                break;
            }

            bool isNumber = true;
            for (char c : subchoice) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (!isNumber) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }

            selectedItem = stoi(subchoice);

            if (selectedItem<0 || selectedItem>invR.inventoryItems.size()) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            if (invR.inventoryItems[selectedItem].getItemType() != "consumable" || invR.inventoryItems[selectedItem].getHasItem() == false) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            while (true) {
                UI.setMessage(1, "Type in 'b' to return");
                UI.setMessage(2, "");


                system("cls");

                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                cout << setw(31) << "|" << "      CONSUMABLES      " << "|" << endl;
                cout << setw(31) << "|" << "-----------------------" << "|" << endl;
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemName() << endl;
                if (invR.inventoryItems[selectedItem].getNeedsQuantity() == true) { cout << setw(31) << "|" << "   You have: " << invR.inventoryItems[selectedItem].getItemQuantity() << endl; }
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription() << endl;
                if(invR.inventoryItems[selectedItem].getItemNeedsDescription2()==true) {cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription2() << endl;}
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                UI.displayMessage(1);
                UI.displayMessage(2);

                cout << endl;
                cout << "Action:" << endl;
                cin >> subchoice;

                if (subchoice == "b") {
                    cout << "Returning..." << endl;
                    this_thread::sleep_for(chrono::milliseconds(400));
                    UI.clearMessage();
                    subchoice = "";
                    break;
                }
                else {
                    cout << "There is no such choice" << endl;
                    subchoice = to_string(selectedItem + 1);
                    this_thread::sleep_for(chrono::milliseconds(400));
                }
            }
        }
    }

};


class Inventory_Page2 : public Inventory_Page {

public:

    Inventory_Page2(Player_Info& p, Inventory& i, Text& t) : Inventory_Page(p, i, t) {}

    void openInventoryPage() override {
        while (true) {
            UI.setMessage(1, "Type in the item ID + ENTER to inspect them");
            UI.setMessage(2, "Type 'b' to go back");

            system("cls");

            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            cout << setw(31) << "|" << "         SPELLS        " << "|" << endl;
            cout << setw(31) << "|" << "-----------------------" << "|" << endl;
            cout << setw(31) << "|" << "                       " << endl;
            for (int i = 0; i < invR.inventoryItems.size(); i++) {
                if (invR.inventoryItems[i].getItemType() == "spell" && invR.inventoryItems[i].getHasItem() == true) {
                    cout << setw(31) << "|" << "   " << invR.inventoryItems[i].getItemID() << ". " << invR.inventoryItems[i].getItemName() << endl;
                }
            }
            cout << setw(31) << "|" << "                       " << endl;
            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            UI.displayMessage(1);
            UI.displayMessage(2);

            cout << endl;
            cout << "Action:" << endl;
            cin >> subchoice;

            if (subchoice == "b") {
                cout << "Returning..." << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                UI.clearMessage();
                subchoice = "";
                break;
            }
            bool isNumber = true;
            for (char c : subchoice) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            if (!isNumber) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }

            selectedItem = stoi(subchoice);

            if (selectedItem<0 || selectedItem>invR.inventoryItems.size()) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            if (invR.inventoryItems[selectedItem].getItemType() != "spell" || invR.inventoryItems[selectedItem].getHasItem() == false) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            while (true) {
                UI.setMessage(1, "Type in 'b' to return");
                UI.setMessage(2, "");


                system("cls");

                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                cout << setw(31) << "|" << "         SPELLS        " << "|" << endl;
                cout << setw(31) << "|" << "-----------------------" << "|" << endl;
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemName() << endl;
                if (invR.inventoryItems[selectedItem].getNeedsQuantity() == true) { cout << setw(31) << "|" << "   You have: " << invR.inventoryItems[selectedItem].getItemQuantity() << endl; }
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription() << endl;
                if(invR.inventoryItems[selectedItem].getItemNeedsDescription2()==true) {cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription2() << endl;}
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                UI.displayMessage(1);
                UI.displayMessage(2);

                cout << endl;
                cout << "Action:" << endl;
                cin >> subchoice;

                if (subchoice == "b") {
                    cout << "Returning..." << endl;
                    this_thread::sleep_for(chrono::milliseconds(400));
                    UI.clearMessage();
                    subchoice = "";
                    break;
                }
                else {
                    cout << "There is no such choice" << endl;
                    subchoice = to_string(selectedItem + 1);
                    this_thread::sleep_for(chrono::milliseconds(400));
                }
            }
        }
    }
};


class Inventory_Page3 : public Inventory_Page {

public:

    Inventory_Page3(Player_Info& p, Inventory& i, Text& t) : Inventory_Page(p, i, t) {}

    void openInventoryPage() override {

        Manage_Basic_Robes basicRobes(playerR, invR);
        Manage_Knight_Armour knightArmour(playerR, invR);
        Manage_Wizard_Armour wizardArmour(playerR, invR);

        while (true) {
            UI.setMessage(1, "Type in the item ID + ENTER to inspect them");
            UI.setMessage(2, "Type 'b' to go back");

            system("cls");

            cout<<setw(31)<<"+" << "-----------------------" << "+" << endl;
            cout<<setw(31)<<"|" << "         ARMOUR        " << "|" << endl;
            cout<<setw(31)<<"|" << "-----------------------" << "|" << endl;
            cout<<setw(31)<<"|" << "                       " << endl;
            for (int i = 0; i < invR.inventoryItems.size(); i++) {
                if (invR.inventoryItems[i].getItemType() == "armour" && invR.inventoryItems[i].getHasItem() == true) {
                    cout << setw(31) << "|" << "   " << invR.inventoryItems[i].getItemID() << ". " << invR.inventoryItems[i].
                        getItemName() << endl;
                }
            }
            cout << setw(31) << "|" << "                       " << endl;
            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            UI.displayMessage(1);
            UI.displayMessage(2);

            cout << endl;
            cout << "Action:" << endl;
            cin >> subchoice;

            if (subchoice == "b") {
                cout << "Returning..." << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                UI.clearMessage();
                subchoice = "";
                break;
            }

            bool isNumber = true;
            for (char c : subchoice) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (!isNumber) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }

            selectedItem = stoi(subchoice);

            if (selectedItem<0 || selectedItem>invR.inventoryItems.size()) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            if (invR.inventoryItems[selectedItem].getItemType() != "armour" || invR.inventoryItems[selectedItem].getHasItem() == false) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            while (true) {
                UI.setMessage(1, "Type in 'e' to equip");
                UI.setMessage(2, "Type in 'b' to return");


                system("cls");

                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                cout << setw(31) << "|" << "         ARMOUR        " << "|" << endl;
                cout << setw(31) << "|" << "-----------------------" << "|" << endl;
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemName() << endl;
                if (invR.inventoryItems[selectedItem].getNeedsQuantity() == true) {
                    cout << setw(31) << "|" << "   You have: " << invR.inventoryItems[selectedItem].getItemQuantity() <<
                        endl;
                }
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription() << endl;
                if(invR.inventoryItems[selectedItem].getItemNeedsDescription2()==true) {cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription2() << endl;}
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                UI.displayMessage(1);
                UI.displayMessage(2);

                cout << endl;
                cout << "Action:" << endl;
                cin >> subchoice;

                if (subchoice == "b") {
                    cout << "Returning..." << endl;
                    this_thread::sleep_for(chrono::milliseconds(400));
                    UI.clearMessage();
                    subchoice = "";
                    break;
                }
                if (subchoice == "e") {
                    if (selectedItem == 0) {
                        basicRobes.equipArmour();
                        cout << "Ordinary robes equiped" << endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                    }
                    else if (selectedItem == 1) {
                        knightArmour.equipArmour();
                        cout << "Knight armour equiped" << endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                    }
                    else if (selectedItem == 2) {
                        wizardArmour.equipArmour();
                        cout << "Wizard armour equiped" << endl;
                        this_thread::sleep_for(chrono::milliseconds(400));
                    }
                }
                else {
                    cout<<"There is no such choice"<<endl;
                    subchoice = to_string(selectedItem + 1);
                    this_thread::sleep_for(chrono::milliseconds(400));
                }
            }
        }
    }

};


class Inventory_Page4 : public Inventory_Page {

public:

    Inventory_Page4(Player_Info& p, Inventory& i, Text& t) : Inventory_Page(p, i, t) {}

    void openInventoryPage() override {
        while (true) {
            UI.setMessage(1, "Type in the item ID + ENTER to inspect them");
            UI.setMessage(2, "Type 'b' to go back");

            system("cls");

            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            cout << setw(31) << "|" << "         OTHER         " << "|" << endl;
            cout << setw(31) << "|" << "-----------------------" << "|" << endl;
            cout << setw(31) << "|" << "                       " << endl;
            for (int i = 0; i < invR.inventoryItems.size(); i++) {
                if (invR.inventoryItems[i].getItemType() == "other" && invR.inventoryItems[i].getHasItem() == true) {
                    cout << setw(31) << "|" << "   " << invR.inventoryItems[i].getItemID() << ". " << invR.inventoryItems[i].getItemName() << endl;
                }
            }
            cout << setw(31) << "|" << "                       " << endl;
            cout << setw(31) << "+" << "-----------------------" << "+" << endl;
            UI.displayMessage(1);
            UI.displayMessage(2);

            cout << endl;
            cout << "Action:" << endl;
            cin >> subchoice;

            if (subchoice == "b") {
                cout << "Returning..." << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                UI.clearMessage();
                subchoice = "";
                break;
            }

            bool isNumber = true;
            for (char c : subchoice) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (!isNumber) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }

            selectedItem = stoi(subchoice);

            if (selectedItem<0 || selectedItem>invR.inventoryItems.size()) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            if (invR.inventoryItems[selectedItem].getItemType() != "other" || invR.inventoryItems[selectedItem].getHasItem() == false) {
                cout << "There is no such choice" << endl;
                this_thread::sleep_for(chrono::milliseconds(400));
                continue;
            }
            while (true) {
                UI.setMessage(1, "Type in 'b' to return");
                UI.setMessage(2, "");


                system("cls");

                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                cout << setw(31) << "|" << "         OTHER         " << "|" << endl;
                cout << setw(31) << "|" << "-----------------------" << "|" << endl;
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemName() << endl;
                if (invR.inventoryItems[selectedItem].getNeedsQuantity() == true) {
                    cout << setw(31) << "|" << "   You have: " << invR.inventoryItems[selectedItem].getItemQuantity() << endl;
                }
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription() << endl;
                if(invR.inventoryItems[selectedItem].getItemNeedsDescription2()==true) {cout << setw(31) << "|" << "   " << invR.inventoryItems[selectedItem].getItemDescription2() << endl;}
                else { cout << setw(31) << "|" << "                       " << endl; }
                cout << setw(31) << "|" << "                       " << endl;
                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                UI.displayMessage(1);
                UI.displayMessage(2);

                cout << endl;
                cout << "Action:" << endl;
                cin >> subchoice;


                if (subchoice == "b") {
                    cout << "Returning..." << endl;
                    this_thread::sleep_for(chrono::milliseconds(400));
                    UI.clearMessage();
                    subchoice = "";
                    break;
                }
                else {
                    cout << "There is no such choice" << endl;
                    subchoice = to_string(selectedItem + 1);
                    this_thread::sleep_for(chrono::milliseconds(400));
                }
            }
        }
    }
};


class Inventory_Display {

protected:

    Player_Info& playerR;
    Inventory& invR;
    Text& UI;

    bool inventoryActive = false;
    string subchoice;
    int selectedItem = 0;

    Inventory_Page1 page1;
    Inventory_Page2 page2;
    Inventory_Page3 page3;
    Inventory_Page4 page4;

public:

    Inventory_Display(Player_Info& p, Inventory& i, Text& t) : playerR(p), invR(i), UI(t), page1(p, i, t), page2(p, i, t), page3(p, i, t), page4(p, i, t) {}

    void inventoryMenu() {

        if (input == "i") {

            inventoryActive = true;

            while (inventoryActive == true) {

                UI.setMessage(1, "Type 1 - 4 to select a category");
                UI.setMessage(2, "Type in 'b' to exit");

                system("cls");

                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                cout << setw(31) << "|" << "       INVENTORY       " << "|" << endl;
                cout << setw(31) << "|" << "-----------------------" << "|" << endl;
                cout << setw(31) << "|" << "                       " << "|" << endl;
                cout << setw(31) << "|" << "   1. Consumables      " << "|  HP:      " << playerR.getPlayerHealth() << endl;
                cout << setw(31) << "|" << "   2. Spells           " << "|  DEFENSE: " << playerR.getPlayerDefense() << endl;
                cout << setw(31) << "|" << "   3. Armour           " << "|  MANA:    " << playerR.getPlayerMana() << endl;
                cout << setw(31) << "|" << "   4. Other            " << "|" << endl;
                cout << setw(31) << "|" << "                       " << "|" << endl;
                cout << setw(31) << "+" << "-----------------------" << "+" << endl;
                UI.displayMessage(1);
                UI.displayMessage(2);

                cout << endl;
                cout << "Action:" << endl;
                char key = _getch();

                switch(key) {
                    case '1': input="1"; break;
                    case '2': input="2"; break;
                    case '3': input="3"; break;
                    case '4': input="4"; break;
                    case 'b': input="b"; break;
                    default: input="other"; break;
                }

                if (input == "1") {
                    this_thread::sleep_for(chrono::milliseconds(400));
                    page1.openInventoryPage();
                }
                if (input == "2") {
                    this_thread::sleep_for(chrono::milliseconds(400));
                    page2.openInventoryPage();
                }
                if (input == "3") {
                    this_thread::sleep_for(chrono::milliseconds(400));
                    page3.openInventoryPage();
                }
                if (input == "4") {
                    this_thread::sleep_for(chrono::milliseconds(400));
                    page4.openInventoryPage();
                }
                if (input == "b") {
                    cout << "Exiting inventory..." << endl;
                    this_thread::sleep_for(chrono::milliseconds(600));
                    UI.clearMessage();
                    inventoryActive = false;
                }
                if(input=="other") {
                    UI.setMessage(1, "There is no such choice");
                }
            }
        }
    }
};


int main() {

    Text UI;
    Player_Info playerR;
    Enemy_Info enemyR;
    Inventory invR;
    Area_Info areaR(UI);

    LootCrate1 lootCrate1(invR, areaR, UI, playerR);
    LootCrate2 lootCrate2(invR, areaR, UI, playerR);
    LootCrate3 lootCrate3(invR, areaR, UI, playerR);
    LootCrate4 lootCrate4(invR, areaR, UI, playerR);
    LootCrate5 lootCrate5(invR, areaR, UI, playerR);
    LootCrate6 lootCrate6(invR, areaR, UI, playerR);
    LootCrate7 lootCrate7(invR, areaR, UI, playerR);
    LootCrate8 lootCrate8(invR, areaR, UI, playerR);
    LootCrate9 lootCrate9(invR, areaR, UI, playerR);
    LootCrate10 lootCrate10(invR, areaR, UI, playerR);
    LootCrate11 lootCrate11(invR, areaR, UI, playerR);

    Door1key door1(invR, areaR, UI);
    Door2 door2(invR, areaR, UI);
    Door2back door2back(invR, areaR, UI);
    Door3 door3(invR, areaR, UI);
    Door3back door3back(invR, areaR, UI);
    Door4key door4key(invR, areaR, UI);
    Door5 door5(invR, areaR, UI);
    Door5back door5back(invR, areaR, UI);
    Door6key door6key(invR, areaR, UI);
    Door7 door7(invR, areaR, UI);
    Door7back door7back(invR, areaR, UI);
    Door8 door8(invR, areaR, UI);
    Door8back door8back(invR, areaR, UI);

    Point_Of_Interest1 POI1(UI, areaR);

    Point_Of_Interest3 POI3(UI, areaR);
    Point_Of_Interest4 POI4(UI, areaR);
    Point_Of_Interest5 POI5(UI, areaR);

    Combat_Encounter1 combat1(enemyR, playerR, areaR, UI, invR);
    Combat_Encounter2 combat2(enemyR, playerR, areaR, UI, invR);
    Combat_Encounter3 combat3(enemyR, playerR, areaR, UI, invR);
    Combat_Encounter4 combat4(enemyR, playerR, areaR, UI, invR);
    Combat_Encounter5 combat5(enemyR, playerR, areaR, UI, invR);
    Combat_Encounter6 combat6(enemyR, playerR, areaR, UI, invR);
    Combat_Encounter7 combat7(enemyR, playerR, areaR, UI, invR);

    Map_Display Map(playerR, UI, areaR);
    Inventory_Display Inventory(playerR, invR, UI);

    Opening Opening(playerR);

    Opening.playOpening();
    areaR.loading_map_0();//0
    areaR.setPlayerCharacter(6, 5);//6 5
    UI.setMessage(1, "Press W, A, S, D to walk");

    while (input != "end") {

        this_thread::sleep_for(chrono::milliseconds(200));

        system("cls");

        Map.map();

        cout << endl;
        cout << "Action:";
        cout << endl;
        char key = _getch();

        switch (key) {
        case 'w': input = "w"; break;
        case 'a': input = "a"; break;
        case 's': input = "s"; break;
        case 'd': input = "d"; break;
        case 'e': input = "e"; break;
        case 'q': input = "end"; break;
        case 'i': input = "i"; break;
        default: input = ""; break;
        }

        areaR.movement();

        Inventory.inventoryMenu();


        if (location==0) {
            lootCrate1.initialize(4, 8);
            lootCrate2.initialize(8, 13);

            door1.initialize(6, 10, 0);
            door2.initialize(9, 16, 0);

            POI1.initialize(9, 5, 8, 5, 0);
        }
        if(location==1){
            lootCrate3.initialize(9, 8);

            door2back.initialize(10, 4, 1);
            door3.initialize(10, 16, 1);

            combat1.combat();
        }
        if(location==2) {
            lootCrate4.initialize(4, 8);
            lootCrate5.initialize(11, 11);

            door3back.initialize(6, 3, 2);
            door4key.initialize(9, 11, 2);
            door5.initialize(6, 17, 2);

            POI3.initialize(4, 17, 4, 16, 2);

            combat2.combat();
        }
        if(location==3) {
            lootCrate6.initialize(5, 15);
            lootCrate7.initialize(18, 14);
            lootCrate8.initialize(20, 20);

            door5back.initialize(12, 3, 3);
            door6key.initialize(12, 10, 3);
            door7.initialize(12, 22, 3);

            POI4.initialize(9, 19, 10, 19, 3);

            combat3.combat();
            combat4.combat();
            combat5.combat();
        }
        if(location==4) {
            door7back.initialize(5, 3, 4);
            door8.initialize(18, 17, 4);

            POI5.initialize(3, 11, 4, 11, 4);

            combat6.combat();
        }
        if(location==5) {
            lootCrate9.initialize(5, 11);
            lootCrate10.initialize(10, 8);
            lootCrate11.initialize(10, 12);

            door8back.initialize(11, 3, 5);

            combat7.combat();
        }
    }

    return 0;
}