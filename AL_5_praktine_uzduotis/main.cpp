#include <iostream>

using namespace std;

int dekas[10], dydis=2, choice, duomuo;

struct eile {
    int duom;
    eile *kitas;
};

eile* pradzia=nullptr;
eile* pabaiga=nullptr;

struct stekas {
    int duom;
    stekas *kitas;
};

stekas* pradzia2=nullptr;
stekas* pabaiga2=nullptr;



void iterpti_i_eile(int elementas) {

    eile *el=new eile();

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


void iterpti_i_steka(int elementas) {

    stekas *el=new stekas();

    el->duom=elementas;
    el->kitas=pradzia2;
    pradzia2=el;

    if (pabaiga2==nullptr) {
        pabaiga2=el;
    }
}


void pasalinti_is_deko_pradzios() {

    if (dydis==-1) {
        cout<<"------------------------------"<<endl;
        cout<<"Dekas yra tuscias, negalima daugiau pasalinti"<<endl;
    } else {

        int pasalintas = dekas[0];

        for(int i=0; i<dydis; i++) {
            dekas[i]=dekas[i+1];
        }

        dydis--;

        iterpti_i_eile(pasalintas);

        cout<<"-----------------------------"<<endl;
        cout<<"Elementas: "<<pasalintas<<" iterptas i eile"<<endl;
    }
}


void pasalinti_is_deko_pabaigos() {

    if (dydis==-1) {
        cout<<"------------------------------"<<endl;
        cout<<"Dekas yra tuscias, negalima daugiau pasalinti"<<endl;
    } else {

        int pasalintas = dekas[dydis];

        dydis--;

        iterpti_i_steka(pasalintas);

        cout<<"-----------------------------"<<endl;
        cout<<"Elementas: "<<pasalintas<<" iterptas i steka"<<endl;
    }
}


void pasalinti_is_eiles() {

    if (pradzia==nullptr) {
        cout<<"------------------------------"<<endl;
        cout<<"Eile yra tuscia, negalima daugiau pasalinti"<<endl;
    } else {

        eile *temp = pradzia;

        int pasalintas = temp->duom;

        pradzia = pradzia->kitas;

        if (pradzia==nullptr) {
            pabaiga=nullptr;
        }

        delete temp;

        cout<<"-----------------------------"<<endl;
        cout<<"Elementas: "<<pasalintas<<" iterptas i deko pradzia"<<endl;

        dydis++;

        for(int i=dydis; i>=0; i--) {
            dekas[i+1]=dekas[i];
        }

        dekas[0]=pasalintas;
    }
}


void pasalinti_is_steko() {

    if (pradzia2==nullptr) {
        cout<<"------------------------------"<<endl;
        cout<<"Stekas yra tuscias, negalima daugiau pasalinti"<<endl;
    } else {
        stekas *temp = pradzia2;

        int pasalintas = temp->duom;

        pradzia2 = pradzia2->kitas;

        if (pradzia2==nullptr) {
            pabaiga2=nullptr;
        }

        delete temp;

        cout<<"------------------------------"<<endl;
        cout<<"Elementas: "<<pasalintas<<" iterptas i deko pabaiga"<<endl;

        dydis++;

        dekas[dydis]=pasalintas;
    }
}


void spausdinti_sarasa() {

    eile *pr=pradzia;

    stekas *prr=pradzia2;

    cout<<"Dekas -  | ";
    for (int i = 0; i <= dydis; i++) {
        cout<<dekas[i]<<" ";
    }
    cout<<"|"<<endl;
    cout<<endl;

    cout<<"Eile -   | ";
    while (pr!=nullptr) {
        cout<<pr->duom<<" ";
        pr=pr->kitas;
    }
    cout<<"|"<<endl;
    cout<<endl;

    cout<<"Stekas - | ";
    while (prr!=nullptr) {
        cout<<prr->duom<<" ";
        prr=prr->kitas;
    }
    cout<<"|"<<endl;

}


int main() {

    for (int i=0; i<3; i++) {
        cout<<"Irasykite "<<i+1<<" deko elementa"<<endl;
        cin>>dekas[i];
    }

    cout<<endl;

    for (int i=0; i<3; i++) {
        cout<<"Irasykite "<<i+1<<" eiles elementa"<<endl;
        cin>>duomuo;
        iterpti_i_eile(duomuo);
    }

    cout<<endl;

    for (int i=0; i<3; i++) {
        cout<<"Irasykite "<<i+1<<" steko elementa"<<endl;
        cin>>duomuo;
        iterpti_i_steka(duomuo);
    }

    cout<<endl;

    while (choice!=6) {
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"Ka noretumete daryti?"<<endl;
        cout<<endl;
        cout<<"1. Pasalinti elementa is deko pradzios (bus iterptas i eile)"<<endl;
        cout<<"2. Pasalinti elementa is deko pabaigos (bus iterptas i steka)"<<endl;
        cout<<"3. Pasalinti elementa is eiles         (bus iterptas i deko pradzia)"<<endl;
        cout<<"4. Pasalinti elementa is steko         (bus iterptas i deko pabaiga)"<<endl;
        cout<<endl;
        cout<<"5. Atspausdinti deka, eile ir steka"<<endl;
        cout<<endl;
        cout<<"6. Baigti darba"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"Irasykite 1 - 6"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                pasalinti_is_deko_pradzios();
            break;
            case 2:
                pasalinti_is_deko_pabaigos();
            break;
            case 3:
                pasalinti_is_eiles();
            break;
            case 4:
                pasalinti_is_steko();
            break;
            case 5:
                spausdinti_sarasa();
            break;
            default:
                cout<<"Darbas baigtas"<<endl;
        }
    }
    return 0;
}