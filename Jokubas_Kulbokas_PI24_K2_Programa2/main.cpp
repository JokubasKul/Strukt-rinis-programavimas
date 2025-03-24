//2. Sukurti sarasa, realizuojant duomenu ivedima, iterpima pries ir po nurodyto elemento,
//norimo elemento pasalinima bei didziausio elemento radima. Realizuoti funkcijas, kurios:
//a. Pirmus 8 neigiamus skaicius perkelia i vienkrypti ciklini sarasa.
//b. Apskaiciuoja kiek cikliniame sarase esanciu elementu suma pagal absoliucia reiksme
//yra didesne uz pradinio saraso visu elementu suma.
//c. Panaikina ciklinio saraso pirmaji, vidurini ir paskutini elementa ir atspausdina juos
//ekrane.
#include <iostream>

using namespace std;

int kiekis, duomuo, po_ko, pries_ka;

struct sarasas {
    int duom;
    sarasas *kitas;
};

struct ciklinis {
    int duom;
    ciklinis *kitas;
};

sarasas *pradzia=nullptr;
sarasas *pabaiga=nullptr;

ciklinis *pradzia2=nullptr;


void iterpti_i_pabaiga(int elementas) {

    sarasas* el=new sarasas();

    el->duom=elementas;
    el->kitas=nullptr;

    if (pabaiga!=nullptr) {             //pataiso, kad pabaiga teisingai rodytu
        pabaiga->kitas=el;
    }
    pabaiga=el;                       //tas pats
    if (pradzia==nullptr) {         //jeigu sarasas yra tuscias
        pradzia=el;
    }

}


void iterpti_pries(int pries_ka,int elementas) {

    if (pradzia==nullptr) {
        cout<< "Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;

    if (pr->duom==pries_ka) {               //jeigu norima iterpti pries pirmaji elementa
        sarasas *el = new sarasas();
        el->duom=elementas;
        el->kitas=pradzia;
        pradzia=el;
        return;
    }

    do {
        if (pr->kitas!=nullptr && pr->kitas->duom==pries_ka) {        //suranda vieta kur nori iterpti (pries pries_ka)
            sarasas *el = new sarasas();
            el->duom=elementas;
            el->kitas=pr->kitas;          //iterpiamas naujas elementas
            pr->kitas=el;

            return;
        }
        pr=pr->kitas;
    } while (pr!=nullptr);

    cout<<"Elemento "<<pries_ka<<" sarase nera"<<endl;

}


void iterpti_po(int po_ko, int elementas) {

    sarasas *pr=pradzia;

    while (pr!=nullptr && pr->duom!=po_ko) {           //surandamas po_ko
        pr=pr->kitas;
    }
    if (pr!=nullptr) {

        sarasas *el = new sarasas();
        el->duom = elementas;

        el->kitas = pr->kitas;                 //itepriamas elementas po po_ko
        pr->kitas=el;

    } else {
        cout<<"Elemento "<<po_ko<<" sarase nera"<<endl;
    }
}


void pasalinti_elementa(int elementas) {

    if (pradzia==nullptr) {
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    if (pradzia->duom==elementas) {                  //jeigu pirmasis elementas yra salinamas
        sarasas *temp=pradzia;
        pradzia=pradzia->kitas;
        delete temp;

        cout<<"Elementas "<<elementas<<" pasalintas is saraso"<<endl;

        return;
    }

    sarasas *pr = pradzia;
    while (pr->kitas != nullptr) {
        if (pr->kitas->duom==elementas) {          //randamas elementas pries salinamaji
            sarasas *temp=pr->kitas;           //temp yra salinamas
            pr->kitas=pr->kitas->kitas;     //uzpildoma skyle
            delete temp;

            cout<<"Elementas "<<elementas<<" pasalintas is saraso"<<endl;

            return;
        }
        pr=pr->kitas;
    }

    cout<<"Elemento "<<elementas<<" nera sarase"<<endl;
}


void spausdinti_sarasa() {

    sarasas *pr=pradzia;

    cout<<"| ";
    do {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while (pr!=nullptr);
    cout<<"|";
    cout<<endl;
}


void spausdinti_ciklini_sarasa() {

    ciklinis *pr=pradzia2;

    cout<<"| ";
    do {                      //do while naudojama cikliniuose sarasuose
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while (pr!=pradzia2);
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
    } while (pr!=nullptr);

    return max;
}


void perkelti_neigiamus() {

    if (pradzia==nullptr) {
        return;
    }

    sarasas *pr=pradzia;

    int neigiami=0;

    while (pr!=nullptr && neigiami<8) {
        if (pr->duom<0) {                   //suranda neigiama

            ciklinis *el = new ciklinis();
            el->duom=pr->duom;                //el yra pr->duom

            if (pradzia2==nullptr) {          //jeigu ciklinis sarasas yra tuscias
                pradzia2=el;
                pradzia2->kitas=pradzia2;
            } else {
                ciklinis *temp=pradzia2;
                while (temp->kitas!=pradzia2) {      //temp yra paskutinis elementas
                    temp=temp->kitas;
                }
                temp->kitas=el;                 //iterpiama i pradzia
                el->kitas=pradzia2;
                pradzia2=el;
            }
            neigiami++;
        }
        pr=pr->kitas;
    }
}


int suma() {

    int suma=0;

    sarasas *pr=pradzia;

    while (pr!=nullptr) {

        suma=suma+pr->duom;

        pr=pr->kitas;
    }

    return suma;
}


int abs_suma() {

    int abs_suma=0;

    ciklinis *pr=pradzia2;

    do {
        abs_suma=abs_suma+abs(pr->duom);

        pr=pr->kitas;
    } while (pr!=pradzia2);

    return abs_suma;
}


int surasti_pradzia() {

    ciklinis *pr=pradzia2;

    int pirmasis=pr->duom;

    do {
        if (pr->kitas==pradzia2) {             //nueina i paskutini elementa
            ciklinis *temp=pradzia2;         //temp yra pradzia
            pr->kitas=pradzia2->kitas;     //uzpildoma skyle
            pradzia2=pradzia2->kitas;

            delete temp;           //elementas panaikinamas
            break;
        }
        pr=pr->kitas;
    } while (pr!=pradzia2);

    return pirmasis;
}


int surasti_viduri() {

    ciklinis *pr=pradzia2;

    int skaicius=0;

    do {                    //apskaiciuoja elementu skaiciu cikliniame sarase
        skaicius++;
        pr=pr->kitas;
    } while (pr!=pradzia2);

    if (skaicius<=2) {      //jeigu yra maziau uz du
        return -1;
    }

    int vidurio_poz=(skaicius/2);        //randamas vidurys
    pr=pradzia2;

    for (int i=0; i<vidurio_poz-2; i++) {    //surandamas tinkamas pr (pries vidurini)
        pr=pr->kitas;
    }

    ciklinis *temp = pr->kitas;         //temp yra vidurinis
    pr->kitas = temp->kitas;           //uzpildoma skyle
    int vidurinis = temp->duom;       //vidurinis yra temp->duom

    delete temp;
    return vidurinis;
}


int surasti_pabaiga() {

    ciklinis *pr=pradzia2;

    while (pr->kitas!=pradzia2) {        //suranda paskutini elementa
        pr=pr->kitas;
    }

    ciklinis *temp=pr;           //temp yra paskutinis elementas
    int pabaiga=temp->duom;

    pr=pradzia2;

    while (pr->kitas != temp) {       //uzpildoma skyle
        pr = pr->kitas;
    }

    pr->kitas = pradzia2;

    delete temp;        //elementas panaikinamas

    return pabaiga;
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
        cout<<"5. Atspausdinti sarasa"<<endl;
        cout<<"6. Atspausdinti ciklini sarasa"<<endl;
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
                if (pradzia==nullptr) {
                    cout<<"Sarasas yra tuscias"<<endl;
                } else {
                    cout<<"Sarasas: "<<endl;
                    spausdinti_sarasa();
                    cout<<endl;
                    cout<<"Didziausias skaicius: "<<maximum()<<endl;
                }
            break;
            case 6:
                    cout<<"Ciklinis sarasas: "<<endl;
                    perkelti_neigiamus();
                    spausdinti_ciklini_sarasa();
                    cout<<endl;
                    cout<<"Absoliuti suma yra "<<abs_suma()-suma()<<" didesne uz suma"<<endl;
                    cout<<endl;
                    if (pradzia2==nullptr) {
                        cout<<endl;
                    } else if (pradzia2->kitas==pradzia2) {
                        cout<<"Pirmasis elementas: "<<surasti_pradzia()<<endl;
                    } else if (pradzia2->kitas->kitas==pradzia2) {
                        cout<<"Pirmasis elementas:   "<<surasti_pradzia()<<endl;
                        cout<<"Paskutinis elementas: "<<surasti_pabaiga()<<endl;
                    } else {
                        cout<<"Pirmasis elementas:   "<<surasti_pradzia()<<endl;
                        cout<<"Vidurinis elementas:  "<<surasti_viduri()<<endl;
                        cout<<"Paskutinis elementas: "<<surasti_pabaiga()<<endl;
                    }
                    cout<<endl;
                    cout<<"Sarasas po panaikinimo: "<<endl;
                    spausdinti_ciklini_sarasa();
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