#include <iostream>

using namespace std;

struct sarasas {                           //sukuriamas sarasas
    int duom;
    sarasas *kitas;
};


sarasas* pradzia=nullptr;                 //pradziai ir pabaigai priskiriama nuline reiksme
sarasas* pabaiga=nullptr;

void iterpti_i_pradzia(int elementas) {

    sarasas *el = new sarasas();

    el->duom = elementas;
    el->kitas = pradzia;          // naujas elementas sujungiamas su nauju
    pradzia = el;                 // naujausias elementas tampa pradzia

    if (pabaiga == nullptr) {      //jeigu sarasas yra tuscias pabaiga yra atnaujinama
        pabaiga = el;
    }
}


void iterpti_i_viduri(int elementas, int pries) {

        sarasas *pr = pradzia;

        while (pr!=nullptr && pr->duom!=pries) {   //suranda "pries" elementa, po jo bus iterpiama
            pr=pr->kitas;
        }
        if (pr!=nullptr) {

            sarasas *el = new sarasas();        //naujas elementas yra iterpiamas
            el->duom = elementas;

            el->kitas = pr->kitas;          //naujausias elementas yra sujungtas su elementu po jo
            pr->kitas = el;                 //naujausias elementas yra sujungiamas su elementu pries ji (pr)

        } else {
            cout<<"Elemento "<<pries<<" sarase nera"<<endl;
        }
}


void iterpti_i_pabaiga(int elementas) {

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


int pasalinti_is_pradzios() {

    if (pradzia==nullptr) {                //jeigu sarasas yra tuscias
        cout<<"---------------------"<<endl;
        cout<<"Sarasas yra tuscias"<<endl;
        cout<<"---------------------"<<endl;
        return -1;
    }

        sarasas *temp=pradzia;             //issaugomas pirmasis elementas
        int naikinamas = temp->duom;       //cia kad veliau butu galima parasyti koks elementas bus panaikinamas

        pradzia=pradzia->kitas;

        if (pradzia==nullptr) {           //jeigu dabar sarasas yra tuscias, pabaiga yra atnaujinama
            pabaiga=nullptr;
        }

        delete temp;                     //atmintis atlaisvinama
        return naikinamas;               //grazina pasalinta elementa

}


void pasalinti_is_vidurio(int elementas) {

    if (pradzia==nullptr) {
        cout<<"----------------------"<<endl;
        cout<<"Sarasas yra tuscias"<<endl;
        cout<<"----------------------"<<endl;
        return;
    }

    if (pradzia->duom==elementas) {            //jeigu pasirenkamas pradzios elementas
        pasalinti_is_pradzios();
        return;
    }

    sarasas *pr = pradzia;

    while (pr->kitas!=nullptr && pr->kitas->duom != elementas) {   //surandamas pasirinktas elementas, dabartinis "pr" yra pries ji
        pr=pr->kitas;
    }

    if (pr->kitas!=nullptr) {       //pr->kitas rodo i elementa kuri norime panaikinti

        sarasas *temp = pr->kitas;   //issaugomas elementas kuri norime panaikinti "temp" kintamajame
        pr->kitas = temp->kitas;     //sujungiami elementai pries temp ir po kad nebutu skyles sarase

        if (temp==pabaiga) {       //jeigu paskutinis elementas yra naikinamas, tada pabaiga yra atnaujinama
            pabaiga=pr;
        }

        delete temp;     //elementas panaikintas

    } else {
        cout<<"Elemento "<<elementas<<" nera sarase"<<endl;
    }
}


int pasalinti_is_pabaigos() {

    if (pradzia==nullptr) {                //jeigu sarasas yra tuscias
        cout<<"---------------------"<<endl;
        cout<<"Sarasas yra tuscias"<<endl;
        cout<<"---------------------"<<endl;
        return 0;
    }

    if (pradzia==pabaiga) {              //jeigu yra tik vienas elementas sarase

        int pasalintas=pradzia->duom;
        delete pradzia;
        pradzia=pabaiga=nullptr;        //pradziai ir pabaigai priskiriama nuline reiksme

        return pasalintas;
    }

    sarasas *pr = pradzia;

    while (pr->kitas != pabaiga) {     //suranda pries paskutini indeksa
        pr=pr->kitas;
    }

    int pasalintas = pabaiga->duom;
    delete pabaiga;
    pr->kitas = nullptr;              //dabartinis pr yra buves pries paskutinis, sekantis yra nulis
    pabaiga = pr;                     //pries paskutinis paverciamas paskutiniu

    return pasalintas;
}


void spausdinti_sarasa() {

    sarasas* pr=pradzia;          //pradeda nuo pradzios

    cout<<"| ";
    while (pr!=nullptr) {         //kartos kol pasieks pabaiga
        cout<<pr->duom<<" ";
        pr=pr->kitas;             //juda i kita elementa
    }
    cout<<"|"<<endl;
}


void pasalinti_po_8() {              //Pasalina visus skaicius po 8

    sarasas* pr=pradzia;

    while (pr!=nullptr && pr->duom!=8) {
        pr=pr->kitas;
    }

    if (pr!=nullptr) {
        pr->kitas=nullptr;         //visus po 8 panaikina
    }
}


int minimum() {                       //randa maziausia skaiciu

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


int maximum() {

    sarasas* pr=pradzia;

    int max=pr->duom;

    while (pr!=nullptr) {
        if (pr->duom > max) {
            max=pr->duom;
        }
        pr=pr->kitas;
    }
    return max;
}

int main() {

    int kiekis, duomuo, choice, po_kurio;

    while (choice!=9) {
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<endl;
        cout<<"ITERPTI:                          PASALINTI:  "<<endl;
        cout<<"1. I pradzia                      4. Is pradzios"<<endl;
        cout<<"2. I viduri                       5. Is vidurio"<<endl;
        cout<<"3. I pabaiga                      6. Is pabaigos"<<endl;
        cout<<endl;
        cout<<"7. Rasti maziausia ir didziausia skaiciu"<<endl;
        cout<<endl;
        cout<<"8. Spausdinti sarasa"<<endl;
        cout<<endl;
        cout<<"9. Baigti darba"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        cout<<"Parasykite 1 - 9"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Kiek skaiciu noresite irasyti?"<<endl;
            cin>>kiekis;

            for(int i=0;i<kiekis;i++) {
                cout<<"Irasykite skaiciu"<<endl;
                cin>>duomuo;
                iterpti_i_pradzia(duomuo);
            }
            break;
            case 2:
                if (pradzia==nullptr) {
                    cout<<"Kiek skaiciu noretumete iterpti?"<<endl;
                    cin>>kiekis;

                    for(int i=0;i<kiekis;i++) {
                        cout<<"Irasykite skaiciu"<<endl;
                        cin>>duomuo;
                        iterpti_i_pradzia(duomuo);
                    }
                } else {
                    cout<<"Po kurio elemento noretumete iterpti?"<<endl;
                    cout<<endl;
                    spausdinti_sarasa();
                    cout<<endl;
                    cin>>po_kurio;

                    cout<<"Kiek skaiciu noretumete iterpti?"<<endl;
                    cin>>kiekis;

                    for(int i=0;i<kiekis;i++) {
                        cout<<"Irasykite skaiciu"<<endl;
                        cin>>duomuo;
                        iterpti_i_viduri(duomuo, po_kurio);
                    }
                }
            break;
            case 3:
                cout<<"Kiek skaiciu noresite irasyti?"<<endl;
            cin>>kiekis;

            for(int i=0;i<kiekis;i++) {
                cout<<"Irasykite skaiciu"<<endl;
                cin>>duomuo;
                iterpti_i_pabaiga(duomuo);
            }
            break;
            case 4:
                cout<<"-----------------------------"<<endl;
                cout<<"Panaikinas elementas: "<<pasalinti_is_pradzios()<<endl;
            break;
            case 5:
                cout<<"Kuri elementa noretumete istrinti?"<<endl;
                cout<<endl;
                spausdinti_sarasa();
                cout<<endl;
                cin>>duomuo;
                pasalinti_is_vidurio(duomuo);
                cout<<"-----------------------------"<<endl;
                cout<<"Panaikinas elementas: "<<duomuo<<endl;
            break;
            case 6:
                cout<<"-----------------------------"<<endl;
                cout<<"Panaikinas elementas: "<<pasalinti_is_pabaigos()<<endl;
            break;
            case 7:
                cout<<"-----------------------------"<<endl;
                cout<<"Maziausias skaicius: "<<minimum()<<endl;
                cout<<"Didziausias skaicius: "<<maximum()<<endl;
            break;
            case 8:
                cout<<"-----------------------------"<<endl;
                cout<<"Sarasas:"<<endl;
                spausdinti_sarasa();
            break;
            default:
                cout<<"Darbas baigtas"<<endl;
            break;
        }
    }

    return 0;
}