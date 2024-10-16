#include <iostream>
using namespace std;

int getRandomNumber() {

        srand(time(nullptr));
        int randomNum = rand() % 100 ;
        return randomNum;

}

void zaidimas() {

    int num = getRandomNumber();
    int guess;
    cout <<"Pabandykite astpeti skaiciu nuo 1 iki 100"<<endl;
    cin>>guess;

    if (guess == num) {
        cout <<"Atsakymas teisingas "<<endl;
    } else if (guess < num) {
        cout <<"Atsakymas yra mazesnis"<<endl;
    } else if (guess > num) {
        cout <<"Atsakyas yra didenis "<<endl;
    }






}
int main() {


zaidimas();


    return 0;
}
