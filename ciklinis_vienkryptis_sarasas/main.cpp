#include <iostream>

using namespace std;

int kiekis, duomuo, po_ko, pries_ka;

struct sarasas {
    int duom;
    sarasas *kitas;
};

sarasas *pradzia=nullptr;


void iterpti_i_pabaiga(int elementas) {

    sarasas *el = new sarasas();
    el->duom=elementas;

    if (pradzia==nullptr) {              //jeigu sarasas yra tuscias elementas rodo i save
        pradzia=el;
        el->kitas=el;
    } else {
        sarasas *paskutinis=pradzia;
        while (paskutinis->kitas!=pradzia) {       //surandama pabaiga
            paskutinis=paskutinis->kitas;
        }
        paskutinis->kitas=el;         //paskutinis elementas atnaujinamas
        el->kitas=pradzia;
    }

}


void iterpti_pries(int pries_ka,int elementas) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;
    sarasas *ankstesnis = nullptr;               //sitas elementas yra pries pr

    do {
        if (pr->duom==pries_ka) {              //pries_ka surastas
            sarasas *el = new sarasas();
            el->duom=elementas;
            el->kitas=pr;

            if (ankstesnis!=nullptr) {         //jeigu rastas skaicius viduri saraso ankstesnis pripazista naujaji elementa
                ankstesnis->kitas=el;

            } else {

                sarasas *paskutinis=pradzia;            //jeigu elementas yra paskutinis/pries pradzia

                while (paskutinis->kitas!=pradzia) {    //suranda paskutini elementa
                    paskutinis=paskutinis->kitas;
                }
                paskutinis->kitas = el;
                el->kitas=pradzia;
                pradzia=el;
            }
            return;
        }
        ankstesnis=pr;                    //while cikle ankstesnis ir pr vis juda per sarasa
        pr=pr->kitas;
    } while (pr!=pradzia);

    cout<<"Elemento "<<pries_ka<<" sarase nera"<<endl;

}


void iterpti_po(int po_ko, int elementas) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;

    do {
        if (pr->duom==po_ko) {
            sarasas *el= new sarasas();
            el->duom=elementas;
            el->kitas=pr->kitas;
            pr->kitas=el;

            if (pr==pradzia) {           //jeigu elementas yra pradzia
                pradzia=el;
            }

            return;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);

    cout<<"Elementas "<<po_ko<<" nerastas sarase"<<endl;
}


void pasalinti_elementa(int elementas) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia, *ankstesnis=nullptr;

    do {
        if (pr->duom==elementas) {
            if (pr==pradzia) {         //jeigu norima pasalinti pradzia

                sarasas *paskutinis=pradzia;

                while (paskutinis->kitas!=pradzia) {      //surandamas paskutinis elementas
                    paskutinis=paskutinis->kitas;
                }

                if (pradzia==pradzia->kitas) {          //jeigu yra tik vienas skaicius
                    delete pradzia;
                    pradzia=nullptr;
                } else {                        //jeigu yra daugiau nei vienas skaicius
                    pradzia=pr->kitas;
                    paskutinis->kitas=pradzia;  //pabaiga->kitas=pradzia

                    cout<<"Elementas: "<<pr->duom<<" pasalintas"<<endl;

                    delete pr;
                }
            } else {
                ankstesnis->kitas=pr->kitas;      //pasirupina, kad nebutu skyles

                cout<<"Elementas: "<<pr->duom<<" pasalintas"<<endl;

                delete pr;
            }
            return;
        }
        ankstesnis=pr;             //ankstesnis ir pr vis juda per sarasa
        pr=pr->kitas;
    } while (pr!=pradzia);

    cout<<"Elemento "<<elementas<<" nera sarase"<<endl;
}


void spausdinti_sarasa() {

    sarasas *pr=pradzia;

    cout<<"| ";
    do {                                 //naudojamas do while ir while yra pr!=pradzia, o ne nullptr
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while (pr!=pradzia);
    cout<<"|";
    cout<<endl;
}


int maximum() {

    sarasas* pr=pradzia;

    int max=pr->duom;

    do {                                //naudojamas do while ir while yra pr!=pradzia, o ne nullptr
        if (pr->duom > max) {
            max=pr->duom;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);
    return max;
}


int main() {

    int choice;

    cout<<"Kiek elementu noresite iterpti i sarasa?"<<endl;
    cin>>kiekis;

    for (int i=0; i<kiekis; i++) {
        cout<<"Iterpkite elementa"<<endl;
        cin>>duomuo;
        iterpti_i_pabaiga(duomuo);
    }

    while (choice!=5) {
        cout<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<"1. Iterpti pries elementa"<<endl;
        cout<<"2. Iterpti po elemento"<<endl;
        cout<<"3. Pasalinti elementa"<<endl;
        cout<<"4. Atspausdinti sarasa"<<endl;
        cout<<endl;
        cout<<"5. Baigti darba"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Irasykite 1 - 5"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Pries kuri elementa noresite iterpti?"<<endl;
                cout<<endl;
                cin>>pries_ka;
                cout<<endl;
                cout<<"Kiek elementu noresite iterpti?"<<endl;
                cin>>kiekis;
                for (int i=0; i<kiekis; i++) {
                    cout<<"Iterpkite elementa"<<endl;
                    cin>>duomuo;
                    iterpti_pries(pries_ka,duomuo);
                }
            break;
            case 2:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Po kurio elemento noresite iterpti?"<<endl;
                cout<<endl;
                cin>>po_ko;
                cout<<endl;
                cout<<"Kiek elementu noresite iterpti?"<<endl;
                cin>>kiekis;
                for (int i=0; i<kiekis; i++) {
                    cout<<"Iterpkite elementa"<<endl;
                    cin>>duomuo;
                    iterpti_po(po_ko, duomuo);
                }
            break;
            case 3:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Kuri elementa noretumete pasalinti?"<<endl;
                cout<<endl;
                cin>>duomuo;
                pasalinti_elementa(duomuo);
            break;
            case 4:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<endl;
                cout<<"Didziausias skaicius: "<<maximum()<<endl;
            break;
            case 5:
                cout<<"Darbas baigtas"<<endl;
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
            break;
        }
    }

    return 0;
}