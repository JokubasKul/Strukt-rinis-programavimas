#include <iostream>
using namespace std;


void uzduotis1() {

    int eilSkaicius,stulpSkaicius;
    int masyvas[50][50];
    int max=masyvas[0][0];

    cout<<"Iveskite eiluciu skaiciu"<<endl;
    cin>>eilSkaicius;
    cout<<"Iveskite stulpeliu skaiciu"<<endl;
    cin>>stulpSkaicius;

//Ivedimas
    for(int i=0;i<eilSkaicius;i++) {
        for(int j=0;j<stulpSkaicius;j++) {
            cout<<"Iveskite "<<i+1<<" eilutes ir "<<j+1<<" stulpelio elementa"<<endl;
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
        cout<<i+1<<" eilutes sudetis = "<<eilSudetis<<endl;
    }
    cout<<"-----------------------------"<<endl;
//stulp suma
    for(int j=0;j<stulpSkaicius;j++) {
        int stulpSudetis=0;
        for(int i=0;i<eilSkaicius;i++) {
            stulpSudetis += masyvas[i][j];
        }
        cout<<j+1<<" Stulpelio sudetis = "<<stulpSudetis<<endl;
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
    cout<<"Didziausias skaicius: "<<max<<endl;

    cout<<"-----------------------------"<<endl;

}

//-----------------------------------------------------------------------------------------------------------------

int infoSkaicius=0, pasirinkimas, pasirinkimas4, pasirinkimas2, pasirinkimas3, choice;
string baigti;

struct informacija {
    string vardas;
    string pavarde;
    int amzius=0;
    string miestas;
};

informacija* zm[50];



int main() {

    system("chcp 1257 >null");

while (choice!=3) {
    cout<<"Ka noretumete perziureti? (1-3)"<<endl;
    cout<<"1. Uzduotis1"<<endl;
    cout<<"2. Uzduotis2"<<endl;
    cout<<"3. Baigti darba"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:
            uzduotis1();
        break;

        case 2:
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
                break;
                case 2:
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
                break;
                case 3:
                    cout<<"Kuri irasa noretumete istrinti: (1-"<<infoSkaicius<<")"<<endl;
                for(int i=1; i<=infoSkaicius; i++) {
                    cout<<i<<". "<<zm[i]->vardas<<" "<<zm[i]->pavarde<<endl;
                }
                cout<<endl;
                cin>>pasirinkimas3;
                delete zm[pasirinkimas3];

                cout<<"Irasas "<<pasirinkimas3<<" Istrintas"<<endl;

                infoSkaicius--;

                for(int i=pasirinkimas3; i<infoSkaicius; i++) {
                    zm[i]->vardas=zm[i+1]->vardas;
                    zm[i]->pavarde=zm[i+1]->pavarde;
                    zm[i]->amzius=zm[i+1]->amzius;
                    zm[i]->miestas=zm[i+1]->miestas;
                }
                break;

                case 4:
                    cout<<"Sarasas:"<<endl;
                for(int i=1; i<=infoSkaicius; i++) {
                    cout<<i<<". "<<zm[i]->vardas<<" "<<zm[i]->pavarde<<endl;
                }
                cout<<endl;
                cout<<"Kuri irasa noretumete perziureti? (1-"<<infoSkaicius<<")"<<endl;
                cin>>pasirinkimas4;
                cout<<"----------------------------------"<<endl;
                cout<<"Vardas: "<<zm[pasirinkimas4]->vardas<<endl;
                cout<<"Pavarde: "<<zm[pasirinkimas4]->pavarde<<endl;
                cout<<"Amzius: "<<zm[pasirinkimas4]->amzius<<endl;
                cout<<"Gyvenamas miestas: "<<zm[pasirinkimas4]->miestas<<endl;
                cout<<"----------------------------------"<<endl;
                break;

                default:
                    cout<<"Darbas baigtas"<<endl;
            }
        }
        default:
            cout<<"Darbas baigtas"<<endl;
    }
}

    return 0;
}