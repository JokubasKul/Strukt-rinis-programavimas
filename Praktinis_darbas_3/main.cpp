#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char ABECELE[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

void abeceleSifravimas() {

    char tekstas[50];
    char rezultatas[50];
    int poslinkis, tekstoIlgis, rezultatoIndeksas, k = 0;


    cout<<"Parasykite teksta"<<endl;
    cin>>tekstas;

    tekstoIlgis = strlen(tekstas);
    cout<<"Parasykite poslinki "<<"(turi buti nuo 1 iki 25)"<<endl;
    cin>>poslinkis;


    for(int i = 0; i < tekstoIlgis; i++) {
        for(int j=0; j < sizeof(ABECELE); j++) {
            if(toupper(tekstas[i]) == ABECELE[j]) {
                rezultatoIndeksas = (j + poslinkis) % sizeof(ABECELE);
                rezultatas[k] = ABECELE[rezultatoIndeksas];
                k++;
            }
        }
    }
    cout<<endl;
    cout<<rezultatas<<endl;

}

void abeceleDesifravimas() {

    char tekstas[50];
    char rezultatas[50];
    int tekstoIlgis, poslinkis, rezultatoIndeksas, l=0;

    cout<<"Irasykite teksta: "<<endl;
    cin>>tekstas;

    cout<<"Irasykite poslinki: (1-25)"<<endl;
    cin>>poslinkis;

    tekstoIlgis = strlen(tekstas);
    for(int i = 0; i < tekstoIlgis; i++) {
        for(int j=0; j < sizeof(ABECELE); j++) {
            if(toupper(tekstas[i]) == ABECELE[j]) {
                rezultatoIndeksas = (j - poslinkis + sizeof(ABECELE)) % sizeof(ABECELE);
                rezultatas[l] = ABECELE[rezultatoIndeksas];
                l++;
            }
        }
    }
    cout<<endl;
    cout<<"Desifruotas tekstas: "<<rezultatas<<endl;

}

void ASCIIsifravimas() {

    char tekstas[50];
    char rezultatas[50];
    int poslinkis, tekstoIlgis, rezultatoIndeksas, k=0;


    cout<<"Parasykite teksta"<<endl;
    cin>>tekstas;

    tekstoIlgis = strlen(tekstas);

    cout<<"Parasykite poslinki "<<"(turi buti nuo 1 iki 25)"<<endl;
    cin>>poslinkis;

    for(int i = 0; i < tekstoIlgis; i++) {
            rezultatoIndeksas=(int(tekstas[i]) + poslinkis)%26;
            rezultatas[k] = ABECELE[rezultatoIndeksas];
            k++;
    }

cout<<rezultatas<<endl;


}

void ASCIIdesifravimas() {
    char tekstas[50];
    char rezultatas[50];
    int poslinkis, tekstoIlgis, rezultatoIndeksas, k=0;


    cout<<"Parasykite teksta"<<endl;
    cin>>tekstas;

    tekstoIlgis = strlen(tekstas);

    cout<<"Parasykite poslinki "<<"(turi buti nuo 1 iki 25)"<<endl;
    cin>>poslinkis;

    for(int i = 0; i < tekstoIlgis; i++) {
        rezultatoIndeksas=(int(tekstas[i]) - poslinkis + 26)%26;
        rezultatas[k] = ABECELE[rezultatoIndeksas];
        k++;
    }

    cout<<rezultatas<<endl;
}
int main() {
    int choice;
    while(choice != 5) {
        cout<<"----------------------------------------------------------"<<endl;
        cout<<"1. Sifravimas su abecele "<<endl;
        cout<<"2. Desifravimas su abecele "<<endl;
        cout<<"3. Sifravimas su ASCII koduote "<<endl;
        cout<<"4. Desifravimas su ASCII koduote "<<endl;
        cout<<"5. Baigti cikla "<<endl;
        cout<<endl;
        cout<<"Irasykite pasirinkima (1-5)"<<endl;
        cin>>choice;

    switch(choice) {
        case 1:
            cout<<"Jus pasirinkote sifravima su abecele "<<endl;
        abeceleSifravimas();
        break;
        case 2:
            cout<<"Jus pasirinkote desifravima su abecele "<<endl;
        abeceleDesifravimas();
        break;
        case 3:
            cout<<"Jus pasirinkote sifravima su ASCII koduote "<<endl;
        ASCIIsifravimas();
        break;
        case 4:
            cout<<"Jus pasirinkote desifravima su ASCII koduote "<<endl;
        ASCIIdesifravimas();
        break;
        default:
            cout<<"Programa baigta "<<endl;
    }
}

    return 0;
}