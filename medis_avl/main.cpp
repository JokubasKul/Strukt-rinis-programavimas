#include <iostream>

using namespace std;


struct medis {
    int duom;
    medis *kaire;
    medis *desine;
    int aukstis;
};


struct sarasas {
    int duom;
    sarasas *kitas;
};

sarasas *pradzia=nullptr;


int aukstis(medis* node) {

    if (node==nullptr) {
        return 0;             //nuliniai nodes yra = 0
    }

    return node->aukstis;
}


int balansas(medis* node) {

    if (node==nullptr) {
        return 0;           //yra balansuotas
    }
    return aukstis(node->kaire) - aukstis(node->desine);
}


medis *naujasElementas(int elementas) {

    medis *el=new medis();
    el->duom=elementas;
    el->kaire=nullptr;
    el->desine=nullptr;
    el->aukstis=1;         //nauji elementai prasideda su 1

    return el;
}


medis *desineRotacija(medis *y) {

    medis *x=y->kaire;           //kairinis
    medis *temp=x->desine;      //trumpam issaugo desiniji

    x->desine=y;             //x desininis yra y
    y->kaire=temp;          //y kaire yra x desine

    y->aukstis= max(aukstis(y->kaire), aukstis(y->desine)) + 1;     //po pasukimo aukstis yra pakeiciamas
    x->aukstis= max(aukstis(x->kaire), aukstis(x->desine)) + 1;

    return x;    //x tampa naujoji saknis
}


medis *kaireRotacija(medis *x) {

    medis* y=x->desine;          //desininis
    medis* temp=y->kaire;       //issaugo y kaire

    y->kaire=x;             //y kaire yra x
    x->desine=temp;        //x desine yra y kaire

    x->aukstis= max(aukstis(x->kaire), aukstis(x->desine)) + 1;     //po pasukimo aukstis yra pakeiciamas
    y->aukstis= max(aukstis(y->kaire), aukstis(y->desine)) + 1;

    return y;       //y tampa naujoji saknis
}


medis* iterpti(medis* saknis, int elementas) {

    if (saknis==nullptr) {                      //jeigu sarasas yra tuscias
        return naujasElementas(elementas);
    }

    if (elementas<saknis->duom) {
        saknis->kaire=iterpti(saknis->kaire, elementas);

    } else if (elementas>saknis->duom) {
        saknis->desine=iterpti(saknis->desine, elementas);

    } else {
        return saknis;
    }

    saknis->aukstis=1 + max(aukstis(saknis->kaire), aukstis(saknis->desine));  //pakeicia auksti (max suranda kuris is tu dvieju skaiciu yra didesnis)

    int bal=balansas(saknis); //gaunamas balansas

    if (bal>1) {        //jeigu desine per didele
        if (elementas < saknis->kaire->duom) {          //kaire kaire situacija
            return desineRotacija(saknis);
        } else {
            saknis->kaire=kaireRotacija(saknis->kaire);    //kaire desine situacija
            return desineRotacija(saknis);
        }
    }
    if (bal<-1) {           //jeigu kaire per didele
        if (elementas>saknis->desine->duom) {             //desine desine situacija
            return kaireRotacija(saknis);
        } else {
            saknis->desine=desineRotacija(saknis->desine);     //desine kaire situacija
            return kaireRotacija(saknis);
        }
    }


    return saknis;          //nepakeista saknis
}


medis* minimum(medis* saknis) {

    while (saknis->kaire != nullptr) {        //suranda maziausia einant i pati kairiausia elementa
        saknis = saknis->kaire;
    }
    return saknis;
}


medis* maximum(medis* saknis) {

    while (saknis->desine!=nullptr) {      //suranda didziausia einant i pati desiniausia elementa
        saknis=saknis->desine;
    }
    return saknis;
}


medis* pasalinti(medis* saknis, int elementas) {

    if (saknis==nullptr) {
        return saknis;                  //jeigu sarasas tuscias
    }

    if (elementas<saknis->duom) {                          //iesko tinkamo elemento
        saknis->kaire=pasalinti(saknis->kaire, elementas);
    } else if (elementas>saknis->duom) {
        saknis->desine=pasalinti(saknis->desine, elementas);

    } else {                     //surado
        if (saknis->kaire==nullptr || saknis->desine==nullptr) {

            medis *salinamas;

            if (saknis->kaire!=nullptr) {
                salinamas=saknis->kaire;          //jeigu turi tik kairyji vaika
            } else {
                salinamas=saknis->desine;         //jeigu turi tik desiniji vaika
            }

            delete saknis;                    //atmintis atlaisvinama
            saknis=salinamas;

        } else {                     //jeigu turi abu vaikus, iesko maziausio desineje
            medis* salinamas=minimum(saknis->desine);       //iesko maziausio desineje nuo salinamojo
            saknis->duom=salinamas->duom;             //salinamajam duoda desiniojio maziausio skaciu
            saknis->desine=pasalinti(saknis->desine, salinamas->duom);         //pasalina desiniji maziausia
        }
    }

    if (saknis == nullptr)          //jeigu turejo viena elementa
        return saknis;

    saknis->aukstis = 1 + max(aukstis(saknis->kaire), aukstis(saknis->desine)); //atnaujina auksti

    int bal = balansas(saknis);
                               //subalansuoja medi
    if (bal>1) {                    //desine per didele
        if (balansas(saknis->kaire)>=0) {                 //kaire kaire situacija
            return desineRotacija(saknis);
        } else {
            saknis->kaire=kaireRotacija(saknis->kaire);     //kaire desine situacija
            return desineRotacija(saknis);
        }
    }
    if (bal<-1) {                //kaire per didele
        if (balansas(saknis->desine)<=0) {          //desine desine situacija
            return kaireRotacija(saknis);
        } else {
            saknis->desine=desineRotacija(saknis->desine);   //desine kaire situacija
            return kaireRotacija(saknis);
        }
    }

    return saknis;           //naujoji saknis
}


void spausdinti_medi(medis* saknis) {

    if (saknis!=nullptr) {
        spausdinti_medi(saknis->kaire);      //pirma atspausdina kaire, tada sakni, tada desine
        cout<<saknis->duom<<" ";
        spausdinti_medi(saknis->desine);
    }
}


void perkelti_mazesnius_nei_10(medis*& saknis, sarasas*& pradzia) {

    if (saknis == nullptr) return;

    perkelti_mazesnius_nei_10(saknis->kaire, pradzia);
    perkelti_mazesnius_nei_10(saknis->desine, pradzia);

    if (saknis->duom < 10) {
        sarasas* el = new sarasas();
        el->duom = saknis->duom;
        el->kitas = pradzia;
        pradzia = el;

        saknis = pasalinti(saknis, el->duom);
    }
}


void spausdinti_sarasa() {

    sarasas *pr=pradzia;

    cout<<"| ";
    while (pr!=nullptr) {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<"|"<<endl;
}


int main() {

    int choice, kiekis, duomuo;

    medis *saknis=nullptr;

    while (choice!=5) {
        cout<<"--------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<"1. Iterpti elementa"<<endl;
        cout<<"2. Pasalinti elementa"<<endl;
        cout<<"3. Atspausdinti medzio sarasa"<<endl;
        cout<<"4. Atspausdinti sarasa"<<endl;
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
                perkelti_mazesnius_nei_10(saknis, pradzia);
                cout<<"Visi mazesni uz 10 perkelti i sarasa"<<endl;
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

    return 0;
}