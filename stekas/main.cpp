#include <iostream>

using namespace std;

int stekas[50], dydis=-1, virsutinis, choice, kiekis;


void itraukti_nauja_elementa() {

    if(dydis==kiekis-1) {
        cout<<"-----------------------------------"<<endl;
        cout<<"Stekas yra pilnas"<<endl;
        cout<<"-----------------------------------"<<endl;
    } else {
        dydis++;

        cout<<endl;
        cout<<"Irasykite nauja elementa"<<endl;
        cin>>stekas[dydis];
    }
}


void parodyti_elementus() {

    if(dydis==-1) {
        cout<<"-----------------------------------"<<endl;
        cout<<"Stekas yra tuscias"<<endl;
        cout<<"-----------------------------------"<<endl;
    } else {
        cout<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Elementu kiekis: "<<dydis+1<<endl;

        for(int i=0; i<=dydis; i++) {
            cout<<stekas[i]<<" ";
        }
        cout<<"- Virsune"<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
}


void istrinti_virsutini() {

    if(dydis==-1) {
        cout<<"-----------------------------------"<<endl;
        cout<<"Stekas yra tuscias"<<endl;
        cout<<"-----------------------------------"<<endl;
    } else {
        cout<<"-----------------------------------------"<<endl;
        cout<<"Istrinamas virsutinis elementas: "<<stekas[dydis]<<endl;
        cout<<"-----------------------------------------"<<endl;

        stekas[dydis]=0;
        dydis--;
    }
}


void patikrinti_steka() {

    if(dydis==-1) {
        cout<<"-----------------------------------"<<endl;
        cout<<"Stekas yra tuscias"<<endl;
        cout<<"-----------------------------------"<<endl;
    } else if(dydis==kiekis-1) {
        cout<<"-----------------------------------"<<endl;
        cout<<"Stekas yra pilnas"<<endl;
        cout<<"-----------------------------------"<<endl;
    } else {
        cout<<"-----------------------------------"<<endl;
        cout<<"I steka dar galima ideti "<<kiekis-dydis-1<<" elementu"<<endl;
        cout<<"-----------------------------------"<<endl;
    }
}



int main() {


    cout<<"Kokio dydzio bus stekas?"<<endl;
    cin>>kiekis;


    while(choice!=5) {
        cout<<endl;
        cout<<"Ka noretumete padaryti?"<<endl;
        cout<<endl;
        cout<<"1. Itraukti nauja elementa"<<endl;
        cout<<"2. Parodyti steko elementus ir ju skaiciu"<<endl;
        cout<<"3. Istrinti virsutini elementa"<<endl;
        cout<<"4. Patikrinti ar stekas pilnas/tuscias"<<endl;
        cout<<endl;
        cout<<"5. Baigti darba"<<endl;
        cout<<endl;
        cout<<"Irasykite skaiciu nuo 1-5"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                itraukti_nauja_elementa();
            break;
            case 2:
                parodyti_elementus();
            break;
            case 3:
                istrinti_virsutini();
            break;
            case 4:
                patikrinti_steka();
            break;
            default:
                cout<<"Darbas baigtas"<<endl;
        }
    }

    cout<<string(15, '\n');
    system("pause");

    return 0;
}
