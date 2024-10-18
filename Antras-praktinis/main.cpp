#include <iostream>
<<<<<<< HEAD
#include <cmath>
=======
>>>>>>> d0c4352624424259200d32b8dbfaa2213bd0e910
using namespace std;

int getRandomNumber() {

    srand(time(nullptr));
    int randomNum = rand() % 100 ;
    return randomNum;

}
//-----------------------------------1------------------------------------------

<<<<<<< HEAD
bool balse (string raide) {

    if (raide == "a"||raide == "e"||raide == "i"||raide == "o"||raide == "u") {
        return true;
    }
        return false;
=======
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
>>>>>>> d0c4352624424259200d32b8dbfaa2213bd0e910
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
<<<<<<< HEAD
    string raide;
    string result;
=======
>>>>>>> d0c4352624424259200d32b8dbfaa2213bd0e910
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
<<<<<<< HEAD
            cout <<"Iveskite viena raide: "<<endl;
            cin>>raide;
            result = balse(raide) == 1 ? "True" : "False";
            cout<<result <<endl;
=======
            balse();
>>>>>>> d0c4352624424259200d32b8dbfaa2213bd0e910
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
<<<<<<< HEAD
//a
=======

>>>>>>> d0c4352624424259200d32b8dbfaa2213bd0e910


    return 0;
}