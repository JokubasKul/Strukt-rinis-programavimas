#include <iostream>

using namespace std;

int kiekis, duomuo, choice, po_ko;

struct sarasas {
    int duom;
    sarasas *kitas;
    sarasas *ankstesnis;
};

sarasas *pradzia=nullptr;            //pabaiga nera nullptr


void iterpti_i_pradzia(int elementas) {

    sarasas *el = new sarasas;
    el->duom=elementas;

    if (pradzia==nullptr) {           //jeigu sarasas yra tuscias, tada elementas rodo i save

        el->kitas=el;
        el->ankstesnis=el;
        pradzia=el;
    } else {
        sarasas *pabaiga=pradzia->ankstesnis;      //pabaiga yra pradzios atgalinis

        el->kitas=pradzia;                    //naujas elementas iterpiamas pries pradzia
        el->ankstesnis=pabaiga;

        pabaiga->kitas=el;                //senieji elementai yra atnaujinami
        pradzia->ankstesnis=el;

        pradzia=el;                       //dabar naujasis elementas yra naujoji pradzia
    }
}


void iterpti_i_pabaiga(int elementas) {

    sarasas *el= new sarasas;
    el->duom=elementas;

    if (pradzia==nullptr) {                  //jeigu sarasas yra tuscias naujas elementas rodo i save
        el->kitas=el;
        el->ankstesnis=el;
        pradzia=el;
    } else {
        sarasas *pabaiga=pradzia->ankstesnis;

        el->kitas=pradzia;                    //naujas elementas iterpiamas po pabaigos
        el->ankstesnis=pabaiga;

        pabaiga->kitas=el;                  //senieji pradzia ir pabaiga atnaujinami
        pradzia->ankstesnis=el;
    }
}


void iterpti_i_viduri(int elementas, int po_ko) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;

    do {                                 //cikliniame sarase reikia naudoti do
        if (pr->duom==po_ko) {
            sarasas *el=new sarasas;
            el->duom=elementas;            //naujasis elementas surisamas su aplinkiniais
            el->ankstesnis=pr;
            el->kitas=pr->kitas;

            pr->kitas->ankstesnis=el;     //sekantis pripazista el kaip elementa kuris yra jo ankstesnis
            pr->kitas=el;
            return;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);               //vietoj (pr!=nullptr) reikia naudoti (pr!=pradzia), kad ciklas stotu kai pereina sarasa viena karta

    cout<<"Elemento "<<po_ko<<" nera sarase"<<endl;
}


void pasalinti_elementa(int elementas) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;
    sarasas *pabaiga=pradzia->ankstesnis;

    do {
        if (pr->duom==elementas) {
            if (pr==pradzia && pr==pabaiga) {            //jeigu yra tik vienas elementas
                delete pr;
                pradzia=nullptr;
                return;
            } else if (pr==pradzia) {              //jeigu pirmas elementas yra naikinamas
                pradzia=pr->kitas;
            }

            pr->ankstesnis->kitas=pr->kitas;       //pasirupina, kad nebutu tarpo
            pr->kitas->ankstesnis=pr->ankstesnis;

            cout<<"Elementas "<<pr->duom<<" pasalintas"<<endl;
            delete pr;
            return;
        }
        pr=pr->kitas;
    }while (pr!=pradzia);

    cout<<"Elemento "<<elementas<<" nera sarase"<<endl;
}


void spausdinti_sarasa() {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;
    cout<<"| ";
    do {                             //reikia naudoti do while
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while (pr!=pradzia);
    cout<<"|"<<endl;
    cout<<endl;
}


int maximum() {

    sarasas* pr=pradzia;

    int max=pr->duom;

    do {                            //cikliniame sarase reikia naudoti do while ir while(pr!=pradzia), o ne nullptr
        if (pr->duom > max) {
            max=pr->duom;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);

    return max;
}


int minimum() {

    sarasas* pr=pradzia;

    int min=pr->duom;

    do {                               //cikliniame sarase reikia naudoti do while ir while(pr!=pradzia), o ne nullptr
        if (pr->duom < min) {
            min=pr->duom;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);

    return min;
}


int main() {

    cout<<"Kiek elementu noresite iterpti i sarasa?"<<endl;
    cin>>kiekis;

    for(int i=0;i<kiekis;i++) {
        cout<<"Irasykite elementa: "<<endl;
        cin>>duomuo;
        iterpti_i_pabaiga(duomuo);
    }

    while (choice!=6) {
        cout<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<"1. Iterpti i pradzia"<<endl;
        cout<<"2. Iterpti i pabaiga"<<endl;
        cout<<"3. Iterpti i viduri"<<endl;
        cout<<"4. Pasalinti elementa"<<endl;
        cout<<"5. Atspausdinti sarasa"<<endl;
        cout<<endl;
        cout<<"6. Baigti darba"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"Irasykite 1 - 6"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Kiek elementu noresite iterpti i saraso pradzia?"<<endl;
                cin>>kiekis;

                for(int i=0;i<kiekis;i++) {
                    cout<<"Irasykite elementa: "<<endl;
                    cin>>duomuo;
                    iterpti_i_pradzia(duomuo);
                }
            break;
            case 2:
                cout<<"Kiek elementu noresite iterpti i saraso pabaiga?"<<endl;
                cin>>kiekis;

               for(int i=0;i<kiekis;i++) {
                    cout<<"Irasykite elementa: "<<endl;
                    cin>>duomuo;
                    iterpti_i_pabaiga(duomuo);
                }
            break;
            case 3:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Po kurio elemento noresite iterpti?"<<endl;
                cin>>po_ko;
                cout<<"Kiek elementu noresite iterpti po "<<po_ko<<"?"<<endl;
                cin>>kiekis;

                for(int i=0;i<kiekis;i++) {
                    cout<<"Irasykite elementa: "<<endl;
                    cin>>duomuo;
                    iterpti_i_viduri(duomuo, po_ko);
                }
            break;
            case 4:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Kuri elementa noretumete pasalinti?"<<endl;
                cin>>duomuo;
                pasalinti_elementa(duomuo);
            break;
            case 5:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Didziausias skaicius: "<<maximum()<<endl;
                cout<<"Maziausias skaicius:  "<<minimum()<<endl;
            break;
            case 6:
                cout<<"Darbas baigtas"<<endl;
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
            break;
        }
    }
    return 0;
}