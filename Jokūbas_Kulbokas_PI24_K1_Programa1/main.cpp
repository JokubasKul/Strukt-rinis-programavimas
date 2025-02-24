#include <iostream>

using namespace std;

int random;

void pirma_uzduotis() {

    int kiekis, masyvas[50], abs_mas[50], suma = 0, teigiamasindex=-1, a, b;

    cout<<endl;
    cout<<"1. Vienmaciame masyve, sudarytame is n elementu, raskite: "<<endl;
    cout<<"   a) Didziausia pagal absoliucia reiksmę elementą; "<<endl;
    cout<<"   b) Suma pagal absoliucia reiksme elementu, esanciu po pirmojo teigiamo elemento. "<<endl;
    cout<<"   c) Pakeisti masyva taip, kad pirmiausia eitu visi elementai is intervalo [a;b], o paskui visi like. "<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Irasykite kiek elementu tures masyvas: "<<endl;
    cin>>kiekis;

    for(int i=0; i<kiekis; i++) {
        cout<<"Irasykite "<<i+1<<" -aji elementa: "<<endl;
        cin>>masyvas[i];
    }

    for(int i=0; i<kiekis; i++) {
        abs_mas[i] = abs(masyvas[i]);
    }
    int max = masyvas[0];

    for(int i = 0; i<kiekis; i++) {
        if(abs_mas[i] > max) {
            max = abs_mas[i];
        }
    }

    for(int i = 0; i<kiekis; i++) {
        if(masyvas[i]>0) {
            teigiamasindex = i;
            break;
        }
    }

    for (int i=teigiamasindex+1; i<kiekis; i++) {
        suma+=abs_mas[i];
    }

    cout<<"Sukurkite intervala siame masyve "<<endl;
    cout<<"  Indexai - |";
    for (int i=0; i<kiekis; i++) {
        cout<<i+1<<"  ";
    }
    cout<<"|";
    cout<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Elementai - (";
    for(int i=0; i<kiekis; i++) {
        cout<<masyvas[i]<<"; ";
    }
    cout<<")";

    cout<<endl;

    do {
        cout<<"Irasykite pirma intervalo indexa: (1-"<<kiekis-1<<")"<<endl;
        cin>>a;
    } while (a==kiekis || a<1);
    do {
        cout<<"Irasykite paskutini intervalo indexa: ("<<a+1<<"-"<<kiekis<<")"<<endl;
        cin>>b;
    } while (b<a || b>kiekis);

    int index_mas[50], index_kiekis = 0;

    for(int i = a - 1; i < b; i++) {
        index_mas[index_kiekis++] = masyvas[i];
    }

    for(int i=0; i<kiekis; i++) {
        if (i<a-1 || i>=b) {
            index_mas[index_kiekis++] = masyvas[i];
        }
    }

    for(int i=0; i<kiekis; i++) {
        masyvas[i] = index_mas[i];
    }

    cout<<endl;
    cout<<"a) Didziausias pagal absoliucia reiksme elementas: "<<max<<endl;
    cout<<endl;
    if (teigiamasindex == -1) {
        cout<<"b) Masyve nera teigiamu elementu"<<endl;
    } else if (teigiamasindex==kiekis-1) {
        cout<<"b) Masyvo paskutinis elementas yra teigiamas, todel negalima suskaiciuoti sumos"<<endl;
    } else {
        cout<<"b) Absoliuciu elementu suma po pirmo teigiamo skaiciaus: "<<suma<<endl;
    }
    cout<<endl;
    cout << "c) Masyvas po pertvarkymo: (";
    for (int i = 0; i < kiekis; i++) {
        cout << masyvas[i] << "; ";
    }
    cout << ")" << endl;
}

void antra_uzduotis() {

    cout<<"-------------------------------------"<<endl;
    cout<<"Deja antra uzduotis yra neatlikta"<<endl;
    cout<<"-------------------------------------"<<endl;

}

int main() {

int choice;

    do {
        cout<<endl;
        cout<<"Kuria uzduoti noretumete perziureti?"<<endl;
        cout<<endl;
        cout<<"1. Pirma uzduotis"<<endl;
        cout<<"2. Antra uzduotis"<<endl;
        cout<<"3. Baigti perziura"<<endl;
        cout<<endl;
        cout<<"Irasykite 1 - 3"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                pirma_uzduotis();
            break;
            case 2:
                antra_uzduotis();
            break;
            default:
                cout<<"Tokio pasirinkimo nera reikia irasyti arba 1 arba 2"<<endl;
        }
    } while (choice!=3);

    cout << string(15, '\n');
    cout<<"Perziura baigta"<<endl;

    return 0;
}