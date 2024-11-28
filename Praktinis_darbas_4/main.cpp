#include <iostream>
#include <fstream>

using namespace std;

int choice[50];
int dishKiekis[50];
int patiekaluKiekis;
string menuItem[50];
double menuPrice[50];

void showMenu() {

for(int i=1; i<=patiekaluKiekis; i++) {
    while( choice[i]!=9) {
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
                //insert receipt
        }
    }
  }
}

int getData() {

   for(int i=1; i<=patiekaluKiekis; i++) {
       if(choice[i]=1) {
           menuItem[i]={"Kiausiniene"}
       }
   }

}

int main() {


    cout<<"------Sveiki atvyke i restorana „Pavadinimas“------"<<endl;
    cout<<"------------------------MENU-----------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Kiek is viso patiekalu uzsisakysite?"<<endl;
    cin>>patiekaluKiekis;


    return 0;
}
