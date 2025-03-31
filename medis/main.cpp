#include <iostream>

using namespace std;

int kiekis, duomuo, choice;

struct medis {
    int duom;
    medis *kaire;
    medis *desine;
};


medis* naujasElementas(int elementas) {

    medis* el=new medis();
    el->duom=elementas;
    el->kaire=nullptr;
    el->desine=nullptr;
    return el;
}


medis* iterpti(medis* saknis, int elementas) {

    if (saknis==nullptr) {
        return naujasElementas(elementas);             //jeigu medis yra tuscias, naujasis duomuo yra saknis
    }

    if (elementas<saknis->duom) {                //jeigu skaicius yra mazesnis uz sakni, juda i kaire
        saknis->kaire=iterpti(saknis->kaire, elementas);
    } else {                                     //jeigu skaicius yra didesnis arba lygus sakniaim juda i desine
        saknis->desine=iterpti(saknis->desine, elementas);
    }

    return saknis;
}


medis* pasalinti(medis* saknis, int elementas) {

    if (saknis==nullptr) {      //jeigu sarasas yra tuscias
        cout<<"Elementas nerastas sarase"<<endl;
        return saknis;
    }

    if (elementas<saknis->duom) {             //jeigu skaicius yra mazesnis uz sakni, juda i kaire
        saknis->kaire=pasalinti(saknis->kaire, elementas);

    } else if (elementas>saknis->duom) {      //jeigu skaicius yra didesnis uz sakni, juda i desine
        saknis->desine=pasalinti(saknis->desine, elementas);

    } else {                       //kai suranda skaiciu

        if (saknis->kaire==nullptr) {
            medis* salinamas=saknis->desine;
            delete saknis;
            return salinamas;            //jei nera kairiojo, naikina desini

        } else if (saknis->desine==nullptr) {
            medis* salinamas=saknis->kaire;
            delete saknis;
            return salinamas;            //jei nera desinio, naikina kairiji
        }

        medis* salinamas=saknis->desine;       //jeigu elementas turi ir kairiji ir desiniji elementa, iesko maziausio desineje
        while (salinamas->kaire!=nullptr) {
            salinamas=salinamas->kaire;
        }
        saknis->duom=salinamas->duom;           //salinamam elementui prisikiriamas pakeitinio duomuo
        saknis->desine=pasalinti(saknis->desine, salinamas->duom);        //senasis pakeitinys yra pasalinamas
    }
    return saknis;
}


void spausdinti(medis* saknis) {

    if (saknis!=nullptr) {
        spausdinti(saknis->kaire);      //pirma atspausdina kaire, tada sakni, tada desine
        cout<<saknis->duom<<" ";
        spausdinti(saknis->desine);
    }
}


int minimum(medis* saknis) {

    if (saknis==nullptr) {
        return -1;
    }

    medis* min=saknis;
    while (min->kaire!=nullptr) {
        min=min->kaire;
    }
    return min->duom;
}


int maximum(medis* saknis) {

    if (saknis==nullptr) {
        return -1;
    }

    medis* max=saknis;
    while (max->desine!=nullptr) {
        max=max->desine;
    }
    return max->duom;
}

int main() {

    medis* saknis=nullptr;

    cout<<"Kiek elementu noresite iterpti?"<<endl;
    cin>>kiekis;

    for(int i=0;i<kiekis;i++) {
        cout<<"Irasykite skaiciu"<<endl;
        cin>>duomuo;
        saknis = iterpti(saknis, duomuo);
    }

    while (choice!=4) {
        cout<<"----------------------------------------"<<endl;
        cout<<"Ka noretumete padaryti?"<<endl;
        cout<<"1. Iterpti nauja elementa"<<endl;
        cout<<"2. Pasalinti elementa"<<endl;
        cout<<"3. Atspausdinti medi"<<endl;
        cout<<endl;
        cout<<"4. Baigti darba"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Irasykite 1 - 4"<<endl;
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
                spausdinti(saknis);
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
                    spausdinti(saknis);
                    cout<<"|"<<endl;

                    cout<<"Maziausias: "<<minimum(saknis)<<endl;
                    cout<<"Didziausias: "<<maximum(saknis)<<endl;
                }
            break;
            case 4:
                cout<<"Darbas baigtas"<<endl;
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
            break;
        }
    }

    return 0;
}