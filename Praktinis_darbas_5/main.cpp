#include <iostream>
using namespace std;


void uzduotis1() {

    int eilSkaicius,stulpSkaicius;
    int masyvas[50][50];
    int max=masyvas[0][0];

    cout<<"Áveskite eiluèiø skaièiø"<<endl;
    cin>>eilSkaicius;
    cout<<"Áveskite stulpeliø skaièiø"<<endl;
    cin>>stulpSkaicius;

//Ivedimas
    for(int i=0;i<eilSkaicius;i++) {
        for(int j=0;j<stulpSkaicius;j++) {
            cout<<"Áveskite "<<i+1<<" eilutës ir "<<j+1<<" stulpelio elementà"<<endl;
            cin>>masyvas[i][j];
        }
    }
    cout<<"-----------------------------"<<endl;
//spausdinimas
    for(int i=0;i<eilSkaicius;i++) {
        for(int j=0;j<stulpSkaicius;j++) {
            cout<<masyvas[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<"-----------------------------"<<endl;
//eil suma
    for(int i=0;i<eilSkaicius;i++) {
        int eilSudetis=0;
        for(int j=0;j<stulpSkaicius;j++) {
            eilSudetis += masyvas[i][j];
        }
        cout<<i+1<<" eilutës sudëtis = "<<eilSudetis<<endl;
    }
    cout<<"-----------------------------"<<endl;
//stulp suma
    for(int j=0;j<stulpSkaicius;j++) {
        int stulpSudetis=0;
        for(int i=0;i<eilSkaicius;i++) {
            stulpSudetis += masyvas[i][j];
        }
        cout<<j+1<<" Stulpelio sudëtis = "<<stulpSudetis<<endl;
    }
    cout<<"-----------------------------"<<endl;
//max
    for (int i=0;i<eilSkaicius;i++) {
        for (int j=0;j<stulpSkaicius;j++) {
            if (masyvas[i][j]>max) {
                max = masyvas[i][j];
            }
        }
    }
    cout<<"Didşiausias skaièius: "<<max<<endl;

    cout<<"-----------------------------"<<endl;

}

//-----------------------------------------------------------------------------------------------------------------

int infoSkaicius=0, pasirinkimas, pasirinkimas1, pasirinkimas2, pasirinkimas3;
string baigti;

struct informacija {
    string vardas;
    string pavarde;
    int amzius=0;
    string miestas;
};

informacija* zm[50];

void case1() {

    zm[infoSkaicius] = new informacija();

    cout<<"Irasykite varda:"<<endl;
    cin>>zm[infoSkaicius]->vardas;
    cout<<"Irasykite pavarde:"<<endl;
    cin>>zm[infoSkaicius]->pavarde;
    cout<<"Irasykite amziu:"<<endl;
    cin>>zm[infoSkaicius]->amzius;
    cout<<"Irasykite gyvenama miesta:"<<endl;
    cin>>zm[infoSkaicius]->miestas;

    cout<<"----------------------------------"<<endl;
    cout<<"Vardas: "<<zm[infoSkaicius]->vardas<<endl;
    cout<<"Pavarde: "<<zm[infoSkaicius]->pavarde<<endl;
    cout<<"Amzius: "<<zm[infoSkaicius]->amzius<<endl;
    cout<<"Miestas: "<<zm[infoSkaicius]->miestas<<endl;
    cout<<"----------------------------------"<<endl;
}

void case2() {
    cout<<"Kuri irasa noretumete redaguoti (1-"<<infoSkaicius<<")"<<endl;
    for(int i=1; i<=infoSkaicius; i++) {
        cout<<i<<". "<<zm[i]->vardas<<" "<<zm[i]->pavarde<<endl;
    }
    cin>>pasirinkimas2;
    cout<<endl;
    cout<<"Irasykite varda:"<<endl;
    cin>>zm[pasirinkimas2]->vardas;
    cout<<"Irasykite pavarde:"<<endl;
    cin>>zm[pasirinkimas2]->pavarde;
    cout<<"Irasykite amziu:"<<endl;
    cin>>zm[pasirinkimas2]->amzius;
    cout<<"Irasykite gyvenama miesta:"<<endl;
    cin>>zm[pasirinkimas2]->miestas;

    cout<<"----------------------------------"<<endl;
    cout<<"Vardas: "<<zm[pasirinkimas2]->vardas<<endl;
    cout<<"Pavarde: "<<zm[pasirinkimas2]->pavarde<<endl;
    cout<<"Amzius: "<<zm[pasirinkimas2]->amzius<<endl;
    cout<<"Miestas: "<<zm[pasirinkimas2]->miestas<<endl;
    cout<<"----------------------------------"<<endl;
}

void case3() {
    cout<<"Kuri irasa noretumete istrinti:"<<endl;
    for(int i=1; i<=infoSkaicius; i++) {
        cout<<i<<". "<<zm[i]->vardas<<" "<<zm[i]->pavarde<<endl;
    }
    cout<<endl;
    cin>>pasirinkimas3;
    delete zm[pasirinkimas3];
    cout<<"Irasas "<<pasirinkimas3<<" Istrintas"<<endl;
}

void case4() {

        cout<<"Sarasas:"<<endl;
        for(int i=1; i<=infoSkaicius; i++) {
            if (zm[i]->amzius==0) {
                cout<<endl;
            } else {
                cout<<i<<". "<<zm[i]->vardas<<" "<<zm[i]->pavarde<<endl;
            }
        }
        cout<<endl;
        cout<<"Kuri irasa noretumete perziureti?"<<endl;
        cin>>pasirinkimas1;
        cout<<"----------------------------------"<<endl;
        cout<<"Vardas: "<<zm[pasirinkimas1]->vardas<<endl;
        cout<<"Pavarde: "<<zm[pasirinkimas1]->pavarde<<endl;
        cout<<"Amzius: "<<zm[pasirinkimas1]->amzius<<endl;
        cout<<"Gyvenamas miestas: "<<zm[pasirinkimas1]->miestas<<endl;
        cout<<"----------------------------------"<<endl;
}

void uzduotis2() {


    while (pasirinkimas < 5) {
        cout<<endl;
        cout<<"Irasykite savo pasirinkima (1-5)"<<endl;
        cout<<"1. Prideti nauja irasa"<<endl;
        cout<<"2. Redaguoti irasus"<<endl;
        cout<<"3. Istrinti irasus"<<endl;
        cout<<"4. Perziureti irasus"<<endl;
        cout<<"5. Baigti darba"<<endl;
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                infoSkaicius++;
                case1();
            break;
            case 2:
                case2();
            break;
            case 3:
                case3();
            break;
            case 4:
                case4();
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
        }
    }

}



int main() {

    system("chcp 1257 >null");
    uzduotis2();



    return 0;
}
