#include <iostream>

using namespace std;

void pirma_uzduotis() {

    int kiekis, masyvas[50],neigiami[50],neigsud=0,daugyba=0;

    cout<<"Kiek elementu tures masyvas?"<<endl;                               //Masyvo elementu irasymas
    cin>>kiekis;

    cout<<"Surasykite masyvo elementus: (turi buti didejimo tvarka) "<<endl;

    for(int i=1; i<=kiekis; i++) {
        cout<<"Irasykite "<<i<<" -aji elementa"<<endl;
        cin>>masyvas[i];
        cout<<"Masyvo "<<i<<" -as elementas yra: "<<masyvas[i]<<endl;
    }

    int max = masyvas[0];
    int min = masyvas[0];

    for (int i = 1; i<=kiekis; i++) {
        if (masyvas[i] > max) {
            max = masyvas[i];
        }
        if (masyvas[i] < min) {
            min = masyvas[i];
        }
    }

    masyvas[1]=min;
    masyvas[kiekis]=max;



    for(int i=1; i<=kiekis; i++) {
        if(masyvas[i]<0) {
            neigiami[i]=masyvas[i];
        }
    }

    for (int i = 1; i<=kiekis; i++) {
        neigsud=neigsud+neigiami[i];
    }

    cout<<"Neigiamu skaiciu sudetis: "<<neigsud<<endl;


    for(int i=1; i<kiekis;i++) {
    daugyba=daugyba*masyvas[i+1];
    }
    cout<<endl;
    cout<<"Daugyba tarp maziausio ir didziausio skaiciu: "<<daugyba<<endl;
}

int main() {

    pirma_uzduotis();

    return 0;
}
