#include <iostream>
using namespace std;

int getRandomNumber() {

    srand(time(nullptr));
    int randomNum = rand() % 100 ;
    return randomNum;

}
//-----------------------------------1------------------------------------------

bool balse () {

string raide;
    cout <<"Iveskite viena raide: "<<endl;
    cin>>raide;
    if (raide == "a"||raide == "e"||raide == "i"||raide == "o"||raide == "u") {
        cout <<"True"<<endl;
    } else {
        cout <<"False"<<endl;
    }
    return 0;
}
//------------------------------------2-----------------------------------------


   int bendrasDaliklis(int skaicius1, int skaicius2) {


    cout <<"Irasykite du skaicius"<<endl;
    cin >>skaicius1>>skaicius2;

       while (abs(skaicius1) && abs(skaicius2)) {
           if (abs(skaicius1) > abs(skaicius2)) {
               skaicius1 %= skaicius2;
           } else {
               skaicius2 %= skaicius1;
           }
       }
    int dbd = skaicius1 + skaicius2;
    cout <<"Didziausias bendras daliklis: "<<dbd<<endl;
    return dbd;



}
//------------------------------------3-----------------------------------------
void zaidimas() {

    int num = getRandomNumber();
    int guess;
while (guess!=num) {
    cout <<"Pabandykite astpeti skaiciu nuo 1 iki 100"<<endl;
    cin>>guess;
    if (guess == num) {
        cout <<"Atsakymas teisingas "<<endl;
    } else if (guess < num) {
        cout <<"Atsakymas yra didesnis"<<endl;
    } else if (guess > num) {
        cout <<"Atsakyas yra mazesnis "<<endl;
    }
}
}
//------------------------------------4----------------------------------------------

void fizzbuzz () {

    int n;

cout <<"Irasykite teigiama skaiciu "<<endl;
    cin >>n;

    for(int i=1; i<=n; i++) {

        cout <<"Skaiciai: "<<i<<endl;
        if (i%5 ==0 && i%3 == 0) {
            cout <<"FizzBuzz"<<endl;;
        } else if (i%5 == 0) {
            cout <<"Buzz"<<endl;
        } else if (i%3 == 0) {
            cout <<"Fizz"<<endl;;
        }

    }

}
int main() {
int choice = 0;
    while (choice <5) {
        cout <<"----------Pasirinkite funkcija (1-4)------- "<<endl;
        cout <<"1. Balse"<<endl;
        cout <<"2. Bendras dalmuo"<<endl;
        cout <<"3. Zaidimas"<<endl;
        cout <<"4. FizzBuzz"<<endl;
        cout <<"5. Baigti programa"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
              cout <<"Jus pasirinkote pirma funkcija"<<endl;
            balse();
            break;
            case 2:
                cout <<"Jus pasirinkote antra funkcija"<<endl;
           int sk1,sk2;
            bendrasDaliklis(sk1,sk2);
            break;
            case 3:
                cout <<"Jus pasirinkote trecia funkcija"<<endl;
            zaidimas();
            break;
            case 4:
                cout <<"Jus pasirinkote ketvirta funkcija"<<endl;
            fizzbuzz();
            break;
            default:
                cout <<"Programa baigta"<<endl;
        }
    }



    return 0;
}