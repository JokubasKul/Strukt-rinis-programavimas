#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

 char ABECELE[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void abeceleSifravimas() {

    char zodis[50];
    char raktas[50];
    char rezultatas[50];
    int zodzioIlgis, raktoIlgis,rezultatoIndeksas,j=0;
    int zodisf[50],raktasf[50];


    cout<<"Irasykite zodi: "<<endl;
    cin>>zodis;

    zodzioIlgis = strlen(zodis);

    cout<<"Irasykite rakta (negali buti ilgesnis nei "<<zodzioIlgis<<")"<<endl;
    cin>>raktas;

    raktoIlgis = strlen(raktas);


    if(raktoIlgis<zodzioIlgis) {
        for(int i=raktoIlgis; i<zodzioIlgis; i++) {
            raktas[i] = raktas[i-raktoIlgis];
        }
    }

    for(int j=0; j < zodzioIlgis; j++) {
        for(int m=0; m < sizeof(ABECELE); m++) {
            if(toupper(zodis[j]) == ABECELE[m] ) {
                zodisf[j]=m;
            }
        }
    }

    for(int j=0; j < zodzioIlgis; j++) {
        for(int m=0; m < sizeof(ABECELE); m++) {
            if(toupper(raktas[j]) == ABECELE[m] ) {
                raktasf[j]=m;
            }
        }
    }

    for(int k=0; k < zodzioIlgis; k++) {
        for(int l=0; l < zodzioIlgis; l++) {
            rezultatoIndeksas=(zodisf[k] + raktasf[k]) % sizeof(ABECELE);
            rezultatas[k]=ABECELE[rezultatoIndeksas];

        }
    }

    cout<<"Uzsifruotas tekstas: "<<rezultatas<<endl;

}

void abeceleDesifravimas() {

    char zodis[50];
    char raktas[50];
    char rezultatas[50];
    int zodzioIlgis, raktoIlgis,rezultatoIndeksas,j=0;
    int zodisf[50],raktasf[50];


    cout<<"Irasykite uzsifruota teksta: "<<endl;
    cin>>zodis;

    zodzioIlgis = strlen(zodis);

    cout<<"Irasykite rakta (negali buti ilgesnis nei "<<zodzioIlgis<<")"<<endl;
    cin>>raktas;

    raktoIlgis = strlen(raktas);


    if(raktoIlgis<zodzioIlgis) {
        for(int i=raktoIlgis; i<zodzioIlgis; i++) {
            raktas[i] = raktas[i-raktoIlgis];
        }
    }

    for(int j=0; j < zodzioIlgis; j++) {
        for(int m=0; m < sizeof(ABECELE); m++) {
            if(toupper(zodis[j]) == ABECELE[m] ) {
                zodisf[j]=m;
            }
        }
    }

    for(int j=0; j < zodzioIlgis; j++) {
        for(int m=0; m < sizeof(ABECELE); m++) {
            if(toupper(raktas[j]) == ABECELE[m] ) {
                raktasf[j]=m;
            }
        }
    }

    for(int k=0; k < zodzioIlgis; k++) {
        for(int l=0; l < zodzioIlgis; l++) {
            rezultatoIndeksas=(zodisf[k] - raktasf[k] + sizeof(ABECELE)) % sizeof(ABECELE);
            rezultatas[k]=ABECELE[rezultatoIndeksas];

        }
    }

    cout<<"Pradinis zodis: "<<rezultatas<<endl;


}

void ASCIIsifravimas() {

    char zodis[50];
    char raktas[50];
    char rezultatas[50];
    int zodzioIlgis, raktoIlgis,rezultatoIndeksas,j=0;


    cout<<"Irasykite zodi: "<<endl;
    cin>>zodis;

    zodzioIlgis = strlen(zodis);

    cout<<"Irasykite rakta (negali buti ilgesnis nei "<<zodzioIlgis<<")"<<endl;
    cin>>raktas;

    raktoIlgis = strlen(raktas);


    if(raktoIlgis<zodzioIlgis) {                       //rakto ilgis
        for(int i=raktoIlgis; i<zodzioIlgis; i++) {
            raktas[i] = raktas[i-raktoIlgis];
        }
    }

    for(int k=0; k < zodzioIlgis; k++) {
            rezultatoIndeksas=((int(zodis[k]) + int(raktas[k])) % 93)+32;
            rezultatas[k]=char(rezultatoIndeksas);
    }

    cout<<"Uzsifruotas tekstas: "<<rezultatas<<endl;


}

void ASCIIdesifravimas() {

    char zodis[50];
    char raktas[50];
    char rezultatas[50];
    int zodzioIlgis, raktoIlgis,rezultatoIndeksas,j=0;


    cout<<"Irasykite desifruota zodi: "<<endl;
    cin>>zodis;

    zodzioIlgis = strlen(zodis);

    cout<<"Irasykite rakta (negali buti ilgesnis nei "<<zodzioIlgis<<")"<<endl;
    cin>>raktas;

    raktoIlgis = strlen(raktas);


    if(raktoIlgis<zodzioIlgis) {                       //rakto ilgis
        for(int i=raktoIlgis; i<zodzioIlgis; i++) {
            raktas[i] = raktas[i-raktoIlgis];
        }
    }

    for(int k=0; k < zodzioIlgis; k++) {
        rezultatoIndeksas=((int(zodis[k]) - int(raktas[k]) + 93) % 93);
        rezultatas[k]=char(rezultatoIndeksas);
    }

    cout<<"Pradinis tekstas: "<<rezultatas<<endl;


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