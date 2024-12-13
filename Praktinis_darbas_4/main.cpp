#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int choice[40];
int dishKiekis[50];
int patiekaluKiekis=1;
int dishAmount[50];

struct menuItemType {
    string menuItem;
    double menuPrice;
};

menuItemType pasirinkimas[50];



void showMenu() {
    for(int i=1; i <= patiekaluKiekis; i++) {                                            //WHILE ir FOR viename neveikia
            cout<<endl;
            cout<<"Pasirinkite kà norëtumëte uþsisakyti (1-8)"<<endl;
            cout<<endl;
            cout<<"1. Kiauðinienë                            1.45€"<<endl;
            cout<<"2. Kiaulienos ðoninë su keptu kiauðiniu   2.45€"<<endl;
            cout<<"3. Keksiukas su vyðnia                    0.99€"<<endl;
            cout<<"4. Prancûziðkas skrebutis                 1.99€"<<endl;
            cout<<"5. Vaisiø salotos                         2.49€"<<endl;
            cout<<"6. Pusryèiu dribsniai                     0.69€"<<endl;
            cout<<"7. Kava                                   0.50€"<<endl;
            cout<<"8. Arbata                                 0.75€"<<endl;
            cout<<"9. Apskaièiuoti sàskaità"<<endl;
            cout<<endl;
            cout<<"----------------------------------------------"<<endl;
            cin>>choice[i];

            switch (choice[i]) {                                                            //nereikia WHILE dël SWITCH
                case 1:
                    cout<<"Jus pasirinkote kiauðinienæ"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[1];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 2:
                    cout<<"Jus pasirinkote kiaulienos ðoninæ su keptu kiauðiniu"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[2];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 3:
                    cout<<"Jus pasirinkote keksiukà su vyðnia"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[3];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 4:
                    cout<<"Jus pasirinkote prancûziskà skrebutá"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[4];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 5:
                    cout<<"Jus pasirinkote vaisiø salotas"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[5];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 6:
                    cout<<"Jus pasirinkote pusryèiø dribsnius"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[6];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 7:
                    cout<<"Jus pasirinkote kavà"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[7];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                case 8:
                    cout<<"Jus pasirinkote arbatà"<<endl;
                cout<<"Kiek vienetø uþsisakysite?"<<endl;
                cin>>dishKiekis[8];
                patiekaluKiekis=patiekaluKiekis+1;
                if(patiekaluKiekis==9) {
                    patiekaluKiekis=patiekaluKiekis-1;
                }
                break;

                default:
                    cout<<"Ciklas baigtas"<<endl;
            }
        }
    }



void getData() {

    for(int j=1; j<=patiekaluKiekis; j++) {                                           //Norint kazka irasyti i masyva reikia naudoti {} skliaustus
               if(choice[j]==1) {
            pasirinkimas[j].menuItem = {"Kiausiniene"};
            pasirinkimas[j].menuPrice = {1.45};
                   dishAmount[j] = dishKiekis[1];
        } else if(choice[j]==2) {
            pasirinkimas[j].menuItem = {"Kiaulienos sonine su keptu kiausiniu"};
            pasirinkimas[j].menuPrice = {2.45};
              dishAmount[j] = dishKiekis[2];
        } else if(choice[j]==3) {
            pasirinkimas[j].menuItem = {"Keksiukas su vysnia"};
            pasirinkimas[j].menuPrice = {0.99};
            dishAmount[j] = dishKiekis[3];
        } else if(choice[j]==4) {
            pasirinkimas[j].menuItem = {"Prancuziskas skrebutis"};
            pasirinkimas[j].menuPrice = {1.99};
              dishAmount[j] = dishKiekis[4];
        } else if(choice[j]==5) {
            pasirinkimas[j].menuItem = {"Vaisiu salotos"};
            pasirinkimas[j].menuPrice = {2.49};
              dishAmount[j] = dishKiekis[5];
        } else if(choice[j]==6) {
            pasirinkimas[j].menuItem = {"Pusryciu dribsniai"};
            pasirinkimas[j].menuPrice = {0.69};
              dishAmount[j] = dishKiekis[6];
        } else if(choice[j]==7) {
            pasirinkimas[j].menuItem = {"Kava"};
            pasirinkimas[j].menuPrice = {0.50};
              dishAmount[j] = dishKiekis[7];
        } else if(choice[j]==8) {
            pasirinkimas[j].menuItem = {"Arbata"};
            pasirinkimas[j].menuPrice = {0.75};
              dishAmount[j] = dishKiekis[8];
        }
    }
}

void printCheck () {
    double mokesciai, suma, galsuma;

    if(patiekaluKiekis==1) {                                                       //IF sàlygoje du ==
        suma = pasirinkimas[1].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==2) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==3) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice + pasirinkimas[3].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==4) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice + pasirinkimas[3].menuPrice + pasirinkimas[4].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==5) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice + pasirinkimas[3].menuPrice + pasirinkimas[4].menuPrice + pasirinkimas[5].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==6) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice + pasirinkimas[3].menuPrice + pasirinkimas[4].menuPrice + pasirinkimas[5].menuPrice + pasirinkimas[6].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==7) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice + pasirinkimas[3].menuPrice + pasirinkimas[4].menuPrice + pasirinkimas[5].menuPrice + pasirinkimas[6].menuPrice + pasirinkimas[7].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    } else if (patiekaluKiekis==8) {
        suma = pasirinkimas[1].menuPrice + pasirinkimas[2].menuPrice + pasirinkimas[3].menuPrice + pasirinkimas[4].menuPrice + pasirinkimas[5].menuPrice + pasirinkimas[6].menuPrice + pasirinkimas[7].menuPrice + pasirinkimas[8].menuPrice;
        mokesciai=(suma/100)*21;
        galsuma=suma+mokesciai;
    }

    for(int i=1; i<patiekaluKiekis; i++) {

        cout<<dishAmount[i]<<" "<<pasirinkimas[i].menuItem<<setw(40)<<right<<pasirinkimas[i].menuPrice<<right<<"€"<<endl;
    }
    cout<<"Mokesciai"<<setw(34)<<setprecision(2)<<right<<mokesciai<<right<<"€"<<endl;            //setprecision pasako kiek skaiciu buna po kablelio
    cout<<"Galutine suma"<<setw(30)<<setprecision(2)<<right<<galsuma<<right<<"€"<<endl;

    ofstream file;                                                                     // IFSTREAM jeigu áðimti ið failo, OFSTREAM jeigu ádëti á failà

    file.open("check");
    for(int i=1; i<patiekaluKiekis; i++) {
        file<<dishAmount[i]<<" "<<pasirinkimas[i].menuItem<<setw(30)<<pasirinkimas[i].menuPrice<<"€"<<endl;
    }
    file<<"Mokesèiai"<<setw(34)<<setprecision(2)<<mokesciai<<"€"<<endl;
    file<<"Galûtinë suma"<<setw(30)<<setprecision(2)<<galsuma<<"€"<<endl;

    file.close();
}

int main() {

    system("chcp 1257 >null");                                                 //Leidþia lietuviðkas raides, bet reikia ir apacioje pasirinkti windows-1257

    cout<<"------Sveiki atvyke i restoranà „Le restorane“------"<<endl;
    cout<<"------------------------MENU------------------------"<<endl;
    cout<<endl;

                                                                                    //while ir if sàlygos turi bûti skirtingos jeigu yra tame paèiame


    showMenu();


    getData();

    cout<<endl;
    cout<<endl;

    printCheck();



    return 0;
}


