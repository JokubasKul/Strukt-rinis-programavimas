//2. Duotas vienkryptis ciklinis sarasas, kurio elementai yra simboliai. Rasti trumpiausio zodzio
//ilgi.
#include <iostream>
#include <cstring>

using namespace std;


struct sarasas {
    char duom;
    int id;
    int tarpas;
    sarasas* kitas;
};

sarasas* pradzia=nullptr;


struct zodziu_dydis {
    int ilgis;
    int portal;
    zodziu_dydis* kitas;
};

zodziu_dydis* pradzia2=nullptr;
zodziu_dydis* pabaiga2=nullptr;


void iterpti_i_pabaiga(char elementas, int id, int tarpas) {

    sarasas *el = new sarasas();
    el->duom=elementas;
    el->id=id;
    el->tarpas=tarpas;

    if (pradzia==nullptr) {
        pradzia=el;
        el->kitas=el;
    } else {
        sarasas *paskutinis=pradzia;
        while (paskutinis->kitas!=pradzia) {
            paskutinis=paskutinis->kitas;
        }
        paskutinis->kitas=el;
        el->kitas=pradzia;
    }
}


void dydzio_sarasas(int ilgis, int portal) {

    zodziu_dydis *el=new zodziu_dydis();

    el->ilgis=ilgis;
    el->portal=portal;

    if (pabaiga2!=nullptr) {
        pabaiga2->kitas=el;
    }
    pabaiga2=el;
    if (pradzia2==nullptr) {
        pradzia2=el;
    }

}


void rasti_trumpiausia() {

    if (pradzia2==nullptr) {
        return;
    }

    zodziu_dydis* pr=pradzia2;

    int min=pr->ilgis;
    int portal=pr->portal;

    while (pr!=nullptr) {
        if (pr->ilgis < min) {
            min=pr->ilgis;
            portal=pr->portal;
        }
        pr=pr->kitas;
    }

    sarasas* zodzioPradzia=pradzia;

    do {
        if (zodzioPradzia->kitas->id==portal) {
            break;
        }
        zodzioPradzia=zodzioPradzia->kitas;
    } while (zodzioPradzia!=pradzia);

    sarasas* prr=zodzioPradzia;

    cout<<"Trumpiausias zodis: ";

    do {
        cout<<prr->duom<<" ";
        prr=prr->kitas;
    } while (prr->tarpas!=1);

    cout<<prr->duom<<endl;

    cout<<"Zodzio ilgis: "<<min<<endl;
}


void spausdinti_sarasa() {

    sarasas *pr=pradzia;

    cout<<"Zodziu sarasas: "<<endl;
    cout<<"| ";
    do{
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    } while(pr!=pradzia);
    cout<<"|"<<endl;
}


int main() {

   int choice, zodzioIlgis, simboliuIlgis=0;
   char zodis[50];


    cout<<"Irasykite zodi"<<endl;
    cin>>zodis;

    zodzioIlgis=strlen(zodis);

    simboliuIlgis+=zodzioIlgis;

    for(int i=0; i<zodzioIlgis; i++) {
        iterpti_i_pabaiga(zodis[i],i+1, 0);
    }

    iterpti_i_pabaiga(*" ",zodzioIlgis, 1);
    dydzio_sarasas(zodzioIlgis, simboliuIlgis-zodzioIlgis+1);


   while (choice!=3) {
       cout<<"--------------------------------"<<endl;
       cout<<"Ka noretumete daryti?"<<endl;
       cout<<"1. Iterpti nauja zodi"<<endl;
       cout<<"2. Atspausdinti zodzius"<<endl;
       cout<<endl;
       cout<<"3. Baigti darba"<<endl;
       cout<<"--------------------------------"<<endl;
       cout<<"Irasykite nuo 1-3"<<endl;
       cin>>choice;

      switch(choice) {
           case 1:
               cout<<"Irasykite zodi"<<endl;
               cin>>zodis;

               zodzioIlgis=strlen(zodis);

               simboliuIlgis+=zodzioIlgis;

               for(int i=0; i<zodzioIlgis; i++) {
                   iterpti_i_pabaiga(zodis[i],simboliuIlgis-zodzioIlgis+i, 0);
               }

               iterpti_i_pabaiga(*" ",zodzioIlgis, 1);
               dydzio_sarasas(zodzioIlgis, simboliuIlgis-zodzioIlgis+1);
           break;
           case 2:
               spausdinti_sarasa();
               cout<<endl;
               rasti_trumpiausia();
           break;
           case 3:
               cout<<"Darbas baigtas"<<endl;
           break;
           default:
               cout<<"Tokio pasirinkimo nera"<<endl;
           break;
       }
   }

    return 0;
}