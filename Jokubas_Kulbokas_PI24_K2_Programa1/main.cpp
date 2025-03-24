//1. Sukurti ciklini vienkrypti sąrasa, realizuojant duomenu ivedima, įterpima pries ir po nurodyto
//elemento, norimo elemento pasalinima bei didziausio elemento radima. Realizuoti funkcijas,
//kurios:
//a. Visus skaicius nuo maziausio perkelia is ciklinio saraso i steka, realizuota kaip
//vienkryptis sarasas.
//b. Iterpia skaicius is ciklinio saraso nuo pirmojo nelyginio iki antrojo nelyginio i steka;
//c. Panaikina visus steko elementus, juos atspausdinant ekrane.
#include <iostream>

using namespace std;

int kiekis, duomuo, po_ko, pries_ka;

struct sarasas {
    int duom;
    sarasas *kitas;
};

struct stekas {
    int duom;
    stekas *kitas;
};

sarasas *pradzia=nullptr;

stekas *pradzia2=nullptr;
stekas *pabaiga2=nullptr;


void iterpti_i_pabaiga(int elementas) {

    sarasas *el = new sarasas();
    el->duom=elementas;

    if (pradzia==nullptr) {          //jeigu sarasas yra tuscias
        pradzia=el;
        el->kitas=el;
    } else {
        sarasas *paskutinis=pradzia;
        while (paskutinis->kitas!=pradzia) {        //suranda paskutini
            paskutinis=paskutinis->kitas;
        }
        paskutinis->kitas=el;      //iterpiama i pabaiga
        el->kitas=pradzia;
    }

}


void iterpti_pries(int pries_ka,int elementas) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;
    sarasas *ankstesnis = nullptr;

    do {
        if (pr->duom==pries_ka) {
            sarasas *el = new sarasas();
            el->duom=elementas;          //naujas elementas yra pries pr
            el->kitas=pr;

            if (ankstesnis!=nullptr) {    //ankstesnis yra pries pr
                ankstesnis->kitas=el;    //iterpiama po ankstesnis

            } else {       //jeigu nori iterpti prie pirma elementa

                sarasas *paskutinis=pradzia;

                while (paskutinis->kitas!=pradzia) {    //paskutinis yra paskutinis saraso elementas
                    paskutinis=paskutinis->kitas;
                }
                paskutinis->kitas = el;
                el->kitas=pradzia;
                pradzia=el;
            }
            return;
        }
        ankstesnis=pr;    //ankstesnis juda kartu su pr
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

            if (pr==pradzia) {      //jeigu nori iterpti i pabaiga
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
            if (pr==pradzia) {           //jeigu nori pasalinti pradzia

                sarasas *paskutinis=pradzia;

                while (paskutinis->kitas!=pradzia) {    //suranda paskutini elementa sarase
                    paskutinis=paskutinis->kitas;
                }

                if (pradzia==pradzia->kitas) {          //jeigu yra tik vienas elementas
                    cout<<"Elementas: "<<pr->duom<<" pasalintas"<<endl;

                    delete pradzia;
                    pradzia=nullptr;
                } else {                 //jeigu salinamas paskutinis elementas
                    pradzia=pr->kitas;
                    paskutinis->kitas=pradzia;

                    cout<<"Elementas: "<<pr->duom<<" pasalintas"<<endl;

                    delete pr;
                }
            } else {
                ankstesnis->kitas=pr->kitas;

                cout<<"Elementas: "<<pr->duom<<" pasalintas"<<endl;

                delete pr;
            }
            return;
        }
        ankstesnis=pr;
        pr=pr->kitas;
    } while (pr!=pradzia);

    cout<<"Elemento "<<elementas<<" nera sarase"<<endl;
}


void spausdinti_sarasa() {

    sarasas *pr=pradzia;

    cout<<"| ";
    do {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while (pr!=pradzia);
    cout<<"|";
    cout<<endl;

}


int maximum() {

    sarasas* pr=pradzia;

    int max=pr->duom;

    do {
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

    do {
        if (pr->duom < min) {
            min=pr->duom;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);

    return min;
}


void perkelti_maziausius() {

    if (pradzia==nullptr) {
        return;
    }

    int min=minimum();
    sarasas *pr=pradzia;

    do {
        if (pr->duom==min) {             //suranda maziausia
            do {
                stekas *el=new stekas();
                el->duom=pr->duom;
                el->kitas=pradzia2;      //iterpia i pradzia ir juos visus iki pabaigos iterpia i steka
                pradzia2=el;

                pr=pr->kitas;

            } while (pr!=pradzia);

            return;
        }
        pr=pr->kitas;
    } while (pr!=pradzia);
}


void perkelti_nelyginius() {

    int nelyginiai=0;

    if (pradzia==nullptr) {
        return;
    }

    sarasas *pr=pradzia;

    do {
        if (pr->duom%2!=0) {         //suranda nelygini skaiciu
            nelyginiai++;

            if (nelyginiai <= 2) {          //daro tai iki tol kol nelyginiu yra nedaugiau 2
                stekas *el = new stekas(); //jie iterpiami i steka
                el->duom = pr->duom;
                el->kitas = pradzia2;
                pradzia2 = el;
            }
        }
        pr=pr->kitas;
    } while (pr!=pradzia && nelyginiai<2);
}


void spausdinti_steka() {

    stekas *pr=pradzia2;

    cout<<"| ";
    do {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while (pr!=nullptr);
    cout<<"|";
    cout<<endl;
}


void isvalyti_steka() {

    stekas *temp;

    while (pradzia2 != nullptr) {      //steko visi elementai pasalinami
        temp = pradzia2;
        pradzia2 = pradzia2->kitas;
        delete temp;
    }
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

    while (choice!=7) {
        cout<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<"1. Iterpti i pabaiga"<<endl;
        cout<<"2. Iterpti pries elementa"<<endl;
        cout<<"3. Iterpti po elemento"<<endl;
        cout<<"4. Pasalinti elementa"<<endl;
        cout<<"5. Atspausdinti ciklini sarasa"<<endl;
        cout<<"6. Atspausdinti ir pasalinti steka"<<endl;
        cout<<endl;
        cout<<"7. Baigti darba"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Irasykite 1 - 7"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Kiek elementu noresite iterpti i sarasa?"<<endl;
                cin>>kiekis;

                for (int i=0; i<kiekis; i++) {
                    cout<<"Iterpkite elementa"<<endl;
                    cin>>duomuo;
                    iterpti_i_pabaiga(duomuo);
                }
            break;
            case 2:
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
            case 3:
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
            case 4:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<"Kuri elementa noretumete pasalinti?"<<endl;
                cout<<endl;
                cin>>duomuo;
                pasalinti_elementa(duomuo);
            break;
            case 5:
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<endl;
                cout<<"Didziausias skaicius: "<<maximum()<<endl;
            break;
            case 6:
                perkelti_maziausius();
                perkelti_nelyginius();
                cout<<"Stekas: "<<endl;
                spausdinti_steka();
                isvalyti_steka();
                cout<<endl;
                cout<<"Stekas yra pasalintas"<<endl;
            break;
            case 7:
                cout<<"Darbas baigtas"<<endl;
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
            break;
        }
    }

    return 0;
}