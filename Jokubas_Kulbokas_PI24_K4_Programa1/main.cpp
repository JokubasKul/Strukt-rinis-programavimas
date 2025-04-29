//1. Sukurti AVL medi, realizuojant elemento iterpimo, pasalinimo, spausdinimo bei
//paieskos funkcijas. Perkelti to saraso visus elementus i vienkrypti sarasa, realizuojant
//ji kaip deka. Atspausdinti visus vienkrypcio saraso elementus.
#include <iostream>

using namespace std;


struct medis {
    int duom;
    medis *kaire;
    medis *desine;
    int aukstis;
};


struct dekas {
    int duom;
    dekas *kitas;
};

dekas *pradzia=nullptr;
dekas *pabaiga=nullptr;


int aukstis(medis* node) {

    if (node==nullptr) {
        return 0;
    }

    return node->aukstis;
}


int balansas(medis* node) {

    if (node==nullptr) {
        return 0;
    }
    return aukstis(node->kaire) - aukstis(node->desine);
}


medis *naujasElementas(int elementas) {

    medis *el=new medis();
    el->duom=elementas;
    el->kaire=nullptr;
    el->desine=nullptr;
    el->aukstis=1;

    return el;
}


medis *desineRotacija(medis *y) {

    medis *x=y->kaire;
    medis *temp=x->desine;

    x->desine=y;
    y->kaire=temp;

    y->aukstis= max(aukstis(y->kaire), aukstis(y->desine)) + 1;
    x->aukstis= max(aukstis(x->kaire), aukstis(x->desine)) + 1;

    return x;
}


medis *kaireRotacija(medis *x) {

    medis* y=x->desine;
    medis* temp=y->kaire;

    y->kaire=x;
    x->desine=temp;

    x->aukstis= max(aukstis(x->kaire), aukstis(x->desine)) + 1;
    y->aukstis= max(aukstis(y->kaire), aukstis(y->desine)) + 1;

    return y;
}


medis* iterpti(medis* saknis, int elementas) {

    if (saknis==nullptr) {
        return naujasElementas(elementas);
    }

    if (elementas<saknis->duom) {
        saknis->kaire=iterpti(saknis->kaire, elementas);

    } else if (elementas>saknis->duom) {
        saknis->desine=iterpti(saknis->desine, elementas);

    } else {
        return saknis;
    }

    saknis->aukstis=1 + max(aukstis(saknis->kaire), aukstis(saknis->desine));

    int bal=balansas(saknis);

    if (bal>1) {
        if (elementas < saknis->kaire->duom) {
            return desineRotacija(saknis);
        } else {
            saknis->kaire=kaireRotacija(saknis->kaire);
            return desineRotacija(saknis);
        }
    }
    if (bal<-1) {
        if (elementas>saknis->desine->duom) {
            return kaireRotacija(saknis);
        } else {
            saknis->desine=desineRotacija(saknis->desine);
            return kaireRotacija(saknis);
        }
    }


    return saknis;
}


medis* minimum(medis* saknis) {

    while (saknis->kaire != nullptr) {
        saknis = saknis->kaire;
    }
    return saknis;
}


medis* maximum(medis* saknis) {

    while (saknis->desine!=nullptr) {
        saknis=saknis->desine;
    }
    return saknis;
}


medis* pasalinti(medis* saknis, int elementas) {

    if (saknis==nullptr) {
        return saknis;
    }

    if (elementas<saknis->duom) {
        saknis->kaire=pasalinti(saknis->kaire, elementas);
    } else if (elementas>saknis->duom) {
        saknis->desine=pasalinti(saknis->desine, elementas);

    } else {
        if (saknis->kaire==nullptr || saknis->desine==nullptr) {

            medis *salinamas;

            if (saknis->kaire!=nullptr) {
                salinamas=saknis->kaire;
            } else {
                salinamas=saknis->desine;
            }

            delete saknis;
            saknis=salinamas;

        } else {
            medis* salinamas=minimum(saknis->desine);
            saknis->duom=salinamas->duom;
            saknis->desine=pasalinti(saknis->desine, salinamas->duom);
        }
    }

    if (saknis == nullptr)
        return saknis;

    saknis->aukstis = 1 + max(aukstis(saknis->kaire), aukstis(saknis->desine));

    int bal = balansas(saknis);

    if (bal>1) {
        if (balansas(saknis->kaire)>=0) {
            return desineRotacija(saknis);
        } else {
            saknis->kaire=kaireRotacija(saknis->kaire);
            return desineRotacija(saknis);
        }
    }
    if (bal<-1) {
        if (balansas(saknis->desine)<=0) {
            return kaireRotacija(saknis);
        } else {
            saknis->desine=desineRotacija(saknis->desine);
            return kaireRotacija(saknis);
        }
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


void spausdinti_sarasa() {

    dekas* pr=pradzia;

    cout<<"| ";
    while (pr!=nullptr) {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<"|"<<endl;
}


void iterpti_i_deko_pabaiga(int elementas) {

    dekas* el=new dekas();

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


void perkelti_i_deka(medis*& saknis) {

    if (saknis==nullptr) {
        return;
    }

    perkelti_i_deka(saknis->kaire);
    iterpti_i_deko_pabaiga(saknis->duom);
    perkelti_i_deka(saknis->desine);
}

int main() {

    int choice, kiekis, duomuo;

    medis *saknis=nullptr;

    while (choice!=5) {
        cout<<"--------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<"1. Iterpti elementa i medi"<<endl;
        cout<<"2. Pasalinti elementa is medzio"<<endl;
        cout<<"3. Atspausdinti medi"<<endl;
        cout<<"4. Atspausdinti deka"<<endl;
        cout<<endl;
        cout<<"5. Baigti darba"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Irasykite 1 - 5"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Kiek skaiciu norestumete iterpti?"<<endl;
            cin>>kiekis;
            for (int i=0;i<kiekis;i++) {
                cout<<"Irasykite skaiciu"<<endl;
                cin>>duomuo;
                saknis = iterpti(saknis, duomuo);
            }
            break;
            case 2:
                cout<<"Sarasas: "<<endl;
            cout<<"| ";
            spausdinti_medi(saknis);
            cout<<"|"<<endl;
            cout<<endl;
            cout<<"Kuri skaiciu noretumete pasalinti?"<<endl;
            cin>>duomuo;
            pasalinti(saknis, duomuo);
            cout<<"Skaicius "<<duomuo<<" pasalintas"<<endl;
            break;
            case 3:
                cout<<"Sarasas: "<<endl;
            cout<<"| ";
            spausdinti_medi(saknis);
            cout<<"|"<<endl;
            cout<<endl;
            cout<<"Maziausias skaicius:  "<<minimum(saknis)->duom<<endl;
            cout<<endl;
            cout<<"Didziausias skaicius: "<<maximum(saknis)->duom<<endl;
            break;
            case 4:
                perkelti_i_deka(saknis);
            cout<<"Dekas: "<<endl;
            spausdinti_sarasa();
            break;
            case 5:
                cout<<"Darbas baigtas"<<endl;
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
            break;
        }
    }
}