#include <iostream>

using namespace std;

int kiekis, duomuo, po_ko, pries_ka;

struct sarasas {
    int duom;
    sarasas *kitas;
    sarasas *ankstesnis;
};

sarasas *pradzia=nullptr;
sarasas *pabaiga=nullptr;



void iterpti_i_pabaiga(int elementas) {

    sarasas *el= new sarasas();

    el->duom=elementas;
    el->kitas=nullptr;         //kadangi dabar tai yra paskutinis elementas, jo sekantis yra nullptr
    el->ankstesnis=pabaiga;    //ankstesnis rodo i praeita pabaiga

    if (pabaiga!=nullptr) {     //jeigu pabaiga dar nera naujausias
        pabaiga->kitas=el;
    }
    pabaiga=el;                //dabar pabaiga yra naujausias elementas

    if (pradzia==nullptr) {    //jeigu sarasas yra tuscias pradzia sujungiama su nauju elementu
        pradzia=el;
    }
}


void iterpti_pries(int pries_ka,int elementas) {

    sarasas *pr = pradzia;

    while (pr!=nullptr && pr->duom!=pries_ka) {      //suranda pries_ka
        pr=pr->kitas;
    }

    if (pr!=nullptr) {                      //jeigu elementas surastas
        sarasas *el = new sarasas();

        el->duom = elementas;
        el->kitas = pr;                     //naujas elementas rodys i pries_ka elementa
        el->ankstesnis = pr->ankstesnis;      //pasirupina kad naujo ankstesnis yra toks pat kaip seno ankstesnis

        if (pr->ankstesnis!=nullptr) {       //ankstesnis elementas pries naujaji dabar rodo i naujaji
            pr->ankstesnis->kitas=el;
        } else {
            pradzia=el;                //jeigu iterpiama i pradzia, pradzia atnaujinama
        }
        pr->ankstesnis=el;           //pries_ka pripazista naujaji elementa kaip ta kuris yra prie ji
    } else {
        cout<<"Elemento: "<<pries_ka<<" nera sarase"<<endl;
    }
}


void iterpti_po(int po_ko, int elementas) {

    sarasas *pr =pradzia;

    while (pr!=nullptr && pr->duom!=po_ko) {
        pr=pr->kitas;
    }

    if (pr!=nullptr) {
        sarasas *el = new sarasas();

        el->duom=elementas;
        el->ankstesnis=pr;             //naujasis elementas supranta, kad po_ko yra pries ji
        el->kitas=pr->kitas;         //padaro, kad nebutu tarpo

        if (pr->kitas!=nullptr) {
            pr->kitas->ankstesnis=el;       //pasirupina kad pr kitas elementas butu el kitas elementas
        } else {
            pabaiga=el;            //jeigu ideda i pabaiga tada atnaujina pabaiga
        }
        pr->kitas=el;             //po_ko elementas pripazista el kaip ta kuris yra po jo
    } else {
        cout<<"Elemento: "<<po_ko<<" nera sarase"<<endl;
    }
}


void pasalinti_elementa(int elementas) {

    if (pradzia==nullptr) {
        cout<<"--------------------------"<<endl;
        cout<<"Sarasas yra tuscias"<<endl;
        return;
    }

    sarasas *pr=pradzia;

    while (pr!=nullptr && pr->duom!=elementas) {           //suranda elementa kuri nori pasalinti
        pr=pr->kitas;
    }

    if (pr==nullptr) {
        cout<<"Elemento: "<<elementas<<" nera sarase"<<endl;
        return;
    }

    if (pr->ankstesnis!=nullptr) {
        pr->ankstesnis->kitas=pr->kitas;                //sujungia grandines pries ir po pasalinto elemento
    } else {
        pradzia=pr->kitas;                         //jeigu pirmasis elementas yra pasalinamas pradzia sujungiama su kitu
    }

    if (pr->kitas!=nullptr) {
        pr->kitas->ankstesnis=pr->ankstesnis;       //sujungia grandines pries ir po pasalinto elemento
    } else {
        pabaiga=pr->ankstesnis;               //jeigu paskutinysis elementas yra naikinamas jis atnaujinamas
    }

    cout<<"Elementas: "<<elementas<<" pasalintas"<<endl;

    delete pr;
}


void spausdinti_sarasa() {

    sarasas *pr=pradzia;

    cout<<"| ";
    while (pr!=nullptr) {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<"|";
    cout<<endl;
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


void sukeisti_pirma_ir_paskutini() {

    if (pradzia == nullptr || pabaiga == nullptr || pradzia == pabaiga) {
        cout<<"Negalima sukeisti elementu (sarasas tuscias arba turi tik viena elementa)"<<endl;
        return;
    }
    if (pradzia->duom<0 && pabaiga->duom>0) {           //vykdoma jeigu pradzia yra neigiama ir pabaiga teigiama
        int temp=pradzia->duom;
        pradzia->duom=pabaiga->duom;                    //pradzia=pabaiga
        pabaiga->duom=temp;                             //pabaiga=pradzia
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

    while (choice!=6) {
        cout<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<"1. Iterpti i pabaiga"<<endl;
        cout<<"2. Iterpti pries elementa"<<endl;
        cout<<"3. Iterpti po elemento"<<endl;
        cout<<"4. Pasalinti elementa"<<endl;
        cout<<"5. Atspausdinti sarasa"<<endl;
        cout<<endl;
        cout<<"6. Baigti darba"<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"Irasykite 1 - 6"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Kiek elementu noresite iterpti i pabaiga?"<<endl;
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
                sukeisti_pirma_ir_paskutini();
                cout<<"Sarasas: "<<endl;
                spausdinti_sarasa();
                cout<<endl;
                cout<<"Didziausias skaicius: "<<maximum()<<endl;
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