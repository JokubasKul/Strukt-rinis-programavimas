#include <iostream>

using namespace std;

int dekas[50], kiekis, choice, dydis=-1;

void iterpimas_i_pradzia() {

    dydis++;

    if (dydis == kiekis-1) {
        cout<<"Daugiau skaiciu nebegalima prideti, nes dekas yra pilnas"<<endl;
    } else {
        cout<<"Jus pasirinkote iterpima i pradzia"<<endl;

        for(int i=dydis; i>=0; i--) {
            dekas[i+1]=dekas[i];
        }

        cout<<"Koki skaiciu noretumete iterpti?"<<endl;
        cin>>dekas[0];
    }
}

void iterpimas_i_pabaiga() {

    if (dydis == kiekis-1) {
        cout<<"Daugiau skaiciu nebegalima prideti, nes dekas yra pilnas"<<endl;
    } else {
        cout<<"Jus pasirinkote iterpima i pabaiga"<<endl;
        cout<<endl;

        dydis++;

        cout<<"Koki skaiciu noretumete iterpti?"<<endl;
        cin>>dekas[dydis];
    }
}

void pasalinimas_is_pradzios() {

    if (dydis==-1) {
        cout<<"Deke dar nera elementu"<<endl;
    } else {
        cout<<"Jus pasirinkote pasalinima is pradzios"<<endl;
        cout<<endl;

        for(int i=0; i<dydis; i++) {
            dekas[i]=dekas[i+1];
        }

        cout<<"Pirmasis elementas pasalintas"<<endl;

        dydis--;
    }
}

void pasalinimas_is_pabaigos() {

    if (dydis==-1) {
        cout<<"Deke dar nera elementu"<<endl;
    } else {
        cout<<"Jus pasirinkote pasalinti is pabaigos"<<endl;

        dydis--;
    }
}

void perziureti_deka() {

    cout<<"------------------------"<<endl;
    for(int i=0; i<=dydis; i++) {
        cout<<dekas[i]<<" ";
    }
    cout<<endl;
    cout<<"------------------------"<<endl;
    cout<<endl;
}

int main() {

    do {
        cout<<"Irasykite deko dydi"<<endl;
        cin>>kiekis;
        if (kiekis>50) {
            cout<<"Dekas negali buti didesnis uz 50"<<endl;
        }
    } while(kiekis>50);

    do {
        cout<<endl;
        cout<<"Ka noretumete padaryti?"<<endl;
        cout<<endl;
        cout<<"1. Iterpti skaiciu i pradzia"<<endl;
        cout<<"2. Iterpti skaiciu i pabaiga"<<endl;
        cout<<"3. Pasalinti skaiciu is pradzios"<<endl;
        cout<<"4. Pasalinti skaiciu is pabaigos"<<endl;
        cout<<"5. Perziureti deka"<<endl;
        cout<<endl;
        cout<<"6. Baigti darba"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                iterpimas_i_pradzia();
            break;
            case 2:
                iterpimas_i_pabaiga();
            break;
            case 3:
                pasalinimas_is_pradzios();
            break;
            case 4:
                pasalinimas_is_pabaigos();
            break;
            case 5:
                perziureti_deka();
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
        }
    } while(choice != 6);

    cout<<string(15, '\n');
    system("pause");

    return 0;
}