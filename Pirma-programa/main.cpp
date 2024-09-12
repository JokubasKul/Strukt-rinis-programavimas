#include <string>
#include <iostream>
using namespace std;
int main()
{
   //pirma uzduotis
    cout<<"------------Pirma uzduotis------------"<<endl;
    string vardas = "Jokubas";
    string pavarde;
    int amzius;
    int grupe;
    string studijų_programos_pavadinimas = "Programu sistemos";

    pavarde = "Kulbokas";
    amzius = 18;
    grupe = 2;

    cout <<"Studento vardas:" <<vardas<<endl;
    cout <<"Studento pavarde:" <<pavarde<<endl;
    cout <<"Studento amzius:" <<amzius<<endl;
    cout <<"Studento grupe:" <<grupe<<endl;
    cout <<"Studiju programos pavadinimas:" <<studijų_programos_pavadinimas<<endl;

   //Antra uzduotis
    cout<<"-----------Antra uzduotis-----------"<<endl;
    string pavadinimas ="Vilniaus rytas";
    string ikurimo_metai ="1997";
    string savininkas ="Daris Gudelis";
    string arena ="Statyba Lietuvos rytas";
    int vietos;

    vietos = 578;

    cout <<"Pavadinimas:" <<pavadinimas<<endl;
    cout <<"Ikurimo metai:" <<ikurimo_metai<<endl;
    cout <<"Savininkas:" <<savininkas<<endl;
    cout <<"Arena:" <<arena<<endl;
    cout <<"Vietu skaicius:" <<vietos<<endl;

   //Trecia uzduotis
    cout<<"------------Trecia uzduotis------------"<<endl;
    string pagaminimometai ="2022";
    string modelis ="Peugeot 408";
    string litrazas ="2.0";
    string spalva ="melyna.";
    cout <<"Automobilio modelis yra " <<modelis;
    cout <<". Automobilio pagaminimo metai yra  " <<pagaminimometai;
    cout <<". Jo litrazo modelis yra " <<litrazas;
    cout <<". Automobilio spalva yra " <<spalva<<endl;

    //Ketvirta uzduotis
    cout<<"------------Ketvirta uzduotis------------"<<endl;
    int a;
    int b;
    float c;
    a=13;
    b=5;
    c=17.5;
      cout <<a+b-c<<endl;
      cout <<15/2+c<<endl;
      cout <<a/static_cast<double>(b)+2*c<<endl;
      cout <<14%3+6.3+b/a<<endl;
      cout <<static_cast<int>(c)%5+a-b<<endl;
      cout <<13.5/2+4*3.5+18<<endl;

    //Penkta uzduotis
    cout<<"-----------Penkta uzduotis-----------"<<endl;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    a1=25;
    a2=20;
    a3=15;
    a4=10;
    a5=5;
    cout <<(a1+a2+a3+a4+a5)/5<<endl;

    //Sesta uzduotis
    cout<<"---------Sesta uzduotis----------"<<endl;
    int b1;
    int b2;
    int b3;
    b1=22;
    b2=10;
    b3=b1%b2;
    
    cout <<"Liekana: "<<b3<<endl;
    cout <<"Skaitmenu suma" <<
    return 0;
}

