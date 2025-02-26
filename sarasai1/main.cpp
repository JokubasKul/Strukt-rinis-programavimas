#include <iostream>

using namespace std;

struct sarasas {                           //sukuriamas sarasas
    int duom;
    sarasas *kitas;
};


sarasas* pradzia=nullptr;

sarasas* pabaiga=nullptr;


void iterpti(int elementas) {

    sarasas* el=new sarasas();

    el->duom=elementas;
    el->kitas=nullptr;

    if (pabaiga!=nullptr) {
        pabaiga->kitas=el;                 //sujungia dabartini elementa su nauju
    }
    pabaiga=el;
    if (pradzia==nullptr) {                //jeigu sarasas tuscias sujungia pradzia su nauju elementu
        pradzia=el;
    }
}


void spausdinti_sarasa() {

    sarasas* pr=pradzia;          //pradeda nuo pradzios

    while (pr!=nullptr) {         //kartos kol pasieks pabaiga
        cout<<pr->duom<<" ";
        pr=pr->kitas;             //juda i kita elementa
    }
    cout<<endl;
}

void pasalinti_po_8() {                                      //Pasalina visus skaicius po 8

    sarasas* pr=pradzia;

    while (pr!=nullptr && pr->duom!=8) {
        pr=pr->kitas;
    }

    if (pr!=nullptr) {
        pr->kitas=nullptr;         //visus po 8 panaikina
    }
}


int minimum() {                                               //randa maziausia skaiciu

    sarasas* pr=pradzia;

    int min=pr->duom;

    while (pr!=nullptr) {
        if (pr->duom < min) {
            min=pr->duom;
        }
        pr=pr->kitas;
    }
return min;
}

int main() {

    int kiekis, duomuo;

    cout<<"Kiek skaiciu noresite irasyti?"<<endl;
    cin>>kiekis;

    for(int i=0;i<kiekis;i++) {
        cout<<"Irasykite skaiciu"<<endl;
        cin>>duomuo;
        iterpti(duomuo);
    }

    cout<<"Sarasas"<<endl;

    spausdinti_sarasa();

    cout<<endl;

    int min=minimum();
    cout<<"Maziausias skaicius: "<<min<<endl;
    cout<<endl;

    pasalinti_po_8();

    cout<<"Sarasas kai panaikinti elementai po 8"<<endl;

    spausdinti_sarasa();

    return 0;
}