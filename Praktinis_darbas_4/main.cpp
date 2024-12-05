#include <iostream>
#include <fstream>

using namespace std;

int choice[50];
int dishKiekis[50];
int patiekaluKiekis;


struct menuItemType {
    string menuItem;
    double menuPrice;
};

menuItemType pasirinkimas[50];



void showMenu() {

    cout<<"Kiek is viso skirtingu patiekalu uzsisakysite?"<<endl;
    cin>>patiekaluKiekis;

    for(int i=1; i<=patiekaluKiekis; i++) {
    while(choice[patiekaluKiekis] != patiekaluKiekis) {

        cout<<"Liko "<<patiekaluKiekis-i+1<<" pasirinkimai"<<endl;
        cout<<endl;
        cout<<i;
        cout<<endl;
        cout<<"Pasirinkite ka noretumete uzsisakyti (1-8)"<<endl;
        cout<<"1. Kiausiniene                            1.45€"<<endl;
        cout<<"2. Kiaulienos sonine su keptu kiausiniu   2.45€"<<endl;
        cout<<"3. Keksiukas su vysnia                    0.99€"<<endl;
        cout<<"4. Prancuziskas skrebutis                 1.99€"<<endl;
        cout<<"5. Vaisiu salotos                         2.49€"<<endl;
        cout<<"6. Pusryciu dribsniai                     0.69€"<<endl;
        cout<<"7. Kava                                   0.50€"<<endl;
        cout<<"8. Arbata                                 0.75€"<<endl;
        cout<<"9. Apskaiciuoti saskaita"<<endl;
        cin>>choice[i];

        switch (choice[i]) {
            case 1:
                cout<<"Jus pasirinkote kiausiniene"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[1];
            break;

            case 2:
                cout<<"Jus pasirinkote kiaulienos sonine su keptu kiausiniu"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[2];
            break;

            case 3:
                cout<<"Jus pasirinkote keksiuka su vysnia"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[3];
            break;

            case 4:
                cout<<"Jus pasirinkote prancuziska skrebuti"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[4];
            break;

            case 5:
                cout<<"Jus pasirinkote vaisiu salotas"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[5];
            break;

            case 6:
                cout<<"Jus pasirinkote pusryciu dribsnius"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[6];
            break;

            case 7:
                cout<<"Jus pasirinkote kava"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[7];
            break;

            case 8:
                cout<<"Jus pasirinkote arbata"<<endl;
            cout<<"Kiek vienetu uzsisakysite?"<<endl;
            cin>>dishKiekis[8];
            break;
            default:
                cout<<"Ciklas baigtas"<<endl;
        }
    }
  }
}



void getData() {

    for(int j=1; j<=patiekaluKiekis; j++) {
               if(choice[j]==1) {
            pasirinkimas[j].menuItem = {"Kiausiniene"};
            pasirinkimas[j].menuPrice = {1.45};
        } else if(choice[j]==2) {
            pasirinkimas[j].menuItem = {"Kiaulienos sonine su keptu kiausiniu"};
            pasirinkimas[j].menuPrice = {2.45};
        } else if(choice[j]==3) {
            pasirinkimas[j].menuItem = {"Keksiukas su vysnia"};
            pasirinkimas[j].menuPrice = {0.99};
        } else if(choice[j]==4) {
            pasirinkimas[j].menuItem = {"Prancuziskas skrebutis"};
            pasirinkimas[j].menuPrice = {1.99};
        } else if(choice[j]==5) {
            pasirinkimas[j].menuItem = {"Vaisiu salotos"};
            pasirinkimas[j].menuPrice = {2.49};
        } else if(choice[j]==6) {
            pasirinkimas[j].menuItem = {"Pusryciu dribsniai"};
            pasirinkimas[j].menuPrice = {0.69};
        } else if(choice[j]==7) {
            pasirinkimas[j].menuItem = {"Kava"};
            pasirinkimas[j].menuPrice = {0.50};
        } else if(choice[j]==8) {
            pasirinkimas[j].menuItem = {"Arbata"};
            pasirinkimas[j].menuPrice = {0.75};
        }
    }
}

int main() {

    system("chcp 1257 >null");

    cout<<"------Sveiki atvyke i restoranà „Pavadinimas“------"<<endl;
    cout<<"------------------------MENU-----------------------"<<endl;
    cout<<endl;
    cout<<endl;


    showMenu();


    getData();

    cout<<"Pasirinkimas 1"<<endl;
    cout<<pasirinkimas[1].menuItem<<endl;
    cout<<pasirinkimas[1].menuPrice<<endl;

    cout<<"Pasirinkimas 2"<<endl;
    cout<<pasirinkimas[2].menuItem<<endl;
    cout<<pasirinkimas[2].menuPrice<<endl;

    cout<<"Pasirinkimas 3"<<endl;
    cout<<pasirinkimas[3].menuItem<<endl;
    cout<<pasirinkimas[3].menuPrice<<endl;

    cout<<"Pasirinkimas 4"<<endl;
    cout<<pasirinkimas[4].menuItem<<endl;
    cout<<pasirinkimas[4].menuPrice<<endl;


    return 0;
}
