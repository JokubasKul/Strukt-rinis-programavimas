#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void task1 () {

   string vardas = "Jokubas";
    string pasirinkimas = "Pasirinkau programu sistemas nes mane domina programavimas.";

   cout <<"Vardas: "<<vardas<<endl;
    cout <<pasirinkimas<<endl;
}

void task2 () {

   string kolegija = "Vilniaus kolegija";

    cout <<"Kolegija: "<<kolegija<<endl;


}

void task22 () {

    string fakultetas = "Elektronikos ir infromatikos fakultetas";
    cout <<"Fakultetas: "<<fakultetas<<endl;

}

int task3() {
    srand(time(nullptr));
    int randomNum = rand() % 100 ;
    return randomNum;

}

int num1, num2, nmb1, nmb2;

int math1 () {

int sumats;
    sumats=num1+num2;
    cout <<"Sumos atsakymas: "<<sumats<<endl;
    return sumats;
}
int math2 () {

    int atmats;
    atmats=num1-num2;
    cout <<"Atimties atsakymas: "<<atmats<<endl;
    return  atmats;
}
int math3 () {

    int dauats;
    dauats=num1*num2;
    cout <<"Daugybos atsakymas: "<<dauats<<endl;
    return dauats;
}
int math4 () {

    int dalats;
    dalats=num1/num2;
    cout <<"Dalybos atsakymas: "<<dalats<<endl;
    return dalats;
}




}
int main() {

   task1 ();
   task1 ();
   task2 ();
    task22 ();
   cout <<"Atsitiktinis skacius: "<<task3<<endl;
    cout <<"Irasyktite du skaicius: "<<endl;;
    cin >>num1>>num2;
    math1 ();
    math2 ();
    math3 ();
    math4 ();
    cout <<"Iveskite du skaicius: "<<endl;
    cin >> nmb1>>nmb2;
    return 0;
}
