//1. Sukurti dvejetaini medi, kurio elementai sveiki skaiciai. Realizuoti iterpimo, paieskos,
//spausdinimo ir salinimo operacijas bei atlikti siuos veiksmus:
//a. Irasyti is medzio visus skaicius, kurie priklauso intervalui [a;b], irasyti i eile,
//realizuota kaip sarasas.
//b. Panaikinti is medzio visus skaicius, kurie priklauso intervalui [0;a] irasant juos i deko,
//realizuota kaip sarasas, i pradzia.
//c. Panaikinti is medzio visus skaicius, kurie priklauso intervalui [b;c] irasant juos i deko,
//realizuota kaip sarasas, i pabaiga.
//d. Spausdinti deka ir eile.

#include <iostream>

using namespace std;

int kiekis, duomuo, choice;

struct medis {
    int duom;
    medis *kaire;
    medis *desine;
};


struct eile {
    int duom;
    eile* kitas;
};

eile* pradzia=nullptr;
eile* pabaiga=nullptr;

struct dekas {
    int duom;
    dekas* kitas;
};

dekas* pradzia2=nullptr;
dekas* pabaiga2=nullptr;


medis* naujasElementas(int elementas) {

    medis* el=new medis();
    el->duom=elementas;
    el->kaire=nullptr;
    el->desine=nullptr;
    return el;
}


medis* iterpti(medis* saknis, int elementas) {

    if (saknis==nullptr) {
        return naujasElementas(elementas);
    }

    if (elementas<saknis->duom) {
        saknis->kaire=iterpti(saknis->kaire, elementas);
    } else {
        saknis->desine=iterpti(saknis->desine, elementas);
    }

    return saknis;
}


medis* pasalinti(medis* saknis, int elementas) {

    if (saknis==nullptr) {
        cout<<"Elementas nerastas sarase"<<endl;
        return saknis;
    }

    if (elementas<saknis->duom) {
        saknis->kaire=pasalinti(saknis->kaire, elementas);

    } else if (elementas>saknis->duom) {
        saknis->desine=pasalinti(saknis->desine, elementas);

    } else {

        if (saknis->kaire==nullptr) {
            medis* salinamas=saknis->desine;
            delete saknis;
            return salinamas;

        } else if (saknis->desine==nullptr) {
            medis* salinamas=saknis->kaire;
            delete saknis;
            return salinamas;
        }

        medis* salinamas=saknis->desine;
        while (salinamas->kaire!=nullptr) {
            salinamas=salinamas->kaire;
        }
        saknis->duom=salinamas->duom;
        saknis->desine=pasalinti(saknis->desine, salinamas->duom);
    }
    return saknis;
}


void spausdinti_medi(medis* saknis) {

    if (saknis!=nullptr) {
        spausdinti_medi(saknis->kaire);
        cout<<saknis->duom<<" ";
        spausdinti_medi(saknis->desine);
    }
}


void iterpti_i_eile(int elementas) {

    eile* el=new eile();

    el->duom=elementas;
    el->kitas=nullptr;

    if (pabaiga!=nullptr) {
        pabaiga->kitas=el;
    }
    pabaiga=el;
    if (pradzia==nullptr) {
        pradzia=el;
    }
}


void iterpti_i_deko_pradzia(int elementas) {

    dekas *el = new dekas();

    el->duom = elementas;
    el->kitas = pradzia2;
    pradzia2 = el;

    if (pabaiga2 == nullptr) {
        pabaiga2 = el;
    }
}


void iterpti_i_deko_pabaiga(int elementas) {

    dekas* el=new dekas();

    el->duom=elementas;
    el->kitas=nullptr;

    if (pabaiga2!=nullptr) {
        pabaiga2->kitas=el;
    }
    pabaiga2=el;
    if (pradzia2==nullptr) {
        pradzia2=el;
    }
}


void aaaa(medis*& saknis, int a, int b) {

    if (saknis==nullptr) {
        return;
    }

    aaaa(saknis->kaire, a, b);
    if (saknis->duom>=a && saknis->duom<=b) {
        iterpti_i_eile(saknis->duom);
    }
    aaaa(saknis->desine, a, b);
}


void bbbb(medis*& saknis, int a) {

    if (saknis==nullptr) {
        return;
    }

    bbbb(saknis->kaire, a);
    if (saknis->duom>=0 && saknis->duom<=a) {
        iterpti_i_deko_pradzia(saknis->duom);

        saknis = pasalinti(saknis, saknis->duom);
    }
    bbbb(saknis->desine, a);
}


void cccc(medis*& saknis, int b, int c) {

    if (saknis==nullptr) {
        return;
    }

    cccc(saknis->kaire, b, c);
    if (saknis->duom>=b && saknis->duom<=c) {
        iterpti_i_deko_pabaiga(saknis->duom);

        saknis = pasalinti(saknis, saknis->duom);
    }
    cccc(saknis->desine, b, c);
}


void spausdinti_deka_ir_eile() {

    eile* pr=pradzia;

    cout<<"Eile: "<<endl;
    cout<<"| ";
    while (pr!=nullptr) {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<"|"<<endl;

    cout<<endl;

    dekas *prr=pradzia2;

    cout<<"Dekas: "<<endl;
    cout<<"| ";
    while (prr!=nullptr) {
        cout<<prr->duom<<" ";
        prr=prr->kitas;
    }
    cout<<"|"<<endl;
}


int main() {

    int a=0,b=0,c=0;

    medis* saknis=nullptr;

    cout<<"Kiek elementu noresite iterpti?"<<endl;
    cin>>kiekis;

    for(int i=0;i<kiekis;i++) {
        cout<<"Irasykite skaiciu"<<endl;
        cin>>duomuo;
        saknis = iterpti(saknis, duomuo);
    }

    while (choice!=6) {
        cout<<"----------------------------------------"<<endl;
        cout<<"Ka noretumete padaryti?"<<endl;
        cout<<"1. Iterpti nauja elementa i medi"<<endl;
        cout<<"2. Pasalinti elementa is medzio"<<endl;
        cout<<"3. Atspausdinti medi"<<endl;
        cout<<"4. Sukurti intervalus"<<endl;
        cout<<"5. Atspausdinti eile ir deka"<<endl;
        cout<<endl;
        cout<<"6. Baigti darba"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Irasykite 1 - 6"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Kiek elementu noresite iterpti?"<<endl;
                cin>>kiekis;

                for(int i=0;i<kiekis;i++) {
                    cout<<"Irasykite skaiciu"<<endl;
                    cin>>duomuo;
                    saknis = iterpti(saknis, duomuo);
                }
            break;
            case 2:
                cout<<"Sarasas:"<<endl;
                cout<<"| ";
                spausdinti_medi(saknis);
                cout<<"|"<<endl;
                cout<<"Kuri elementa noresite pasalinti?"<<endl;
                cin>>duomuo;
                saknis=pasalinti(saknis, duomuo);
            break;
            case 3:
                if (saknis==nullptr) {
                    cout<<"Sarasas yra tuscias"<<endl;
                } else {
                    cout<<"Sarasas:"<<endl;
                    cout<<"| ";
                    spausdinti_medi(saknis);
                    cout<<"|"<<endl;
                }
            break;
            case 4:
                cout<<"Sarasas:"<<endl;
                cout<<"| ";
                spausdinti_medi(saknis);
                cout<<"|"<<endl;
                cout<<"Kuris bus pirmasis intervalo elementas?(a)"<<endl;
                cin>>a;
                do {
                    cout<<"Kuris bus antrasis intervalo elementas?(b)"<<endl;
                    cin>>b;
                } while (a==b || b<a);
                do {
                    cout<<"Kuris bus treciasis intervalo elementas?(c)"<<endl;
                    cin>>c;
                }while (b==c || c<b);
            break;
            case 5:
                if (a==0 && b==0 && c==0) {
                    cout<<"Intervalai dar nesudaryti"<<endl;
                } else {
                    aaaa(saknis, a, b);
                    bbbb(saknis, a);
                    cccc(saknis, b, c);
                    spausdinti_deka_ir_eile();
                }
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