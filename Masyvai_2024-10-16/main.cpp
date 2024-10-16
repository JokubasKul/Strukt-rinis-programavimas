#include <iostream>
using namespace std;

int main() {
//--------------------------Pirma_uzduotis--------------------------------
    cout <<"----------------Pirma uzduotis--------------------------------"<<endl;
    int masyvas [5];

    cout <<"Iveskite masyvo elementus"<<endl;
    for (int i =0; i<5; i++) {
        cout<<i+1<<" -aji masyvo elementa "<<endl;
        cin>> masyvas[i];
        cout<<"Ivestas "<<i+1<<" elementas "<<masyvas[i]<<endl;
    }
    int max = masyvas[0];
    int min = masyvas[0];

    for (int i = 1; i<5; i++) {
        if (masyvas[i] > max) {
            max = masyvas[i];
        }
        if (masyvas[i] < min) {
            min = masyvas[i];
        }
    }
    int suma = masyvas[0] + masyvas[1] + masyvas[2] + masyvas[3] + masyvas[4];
    cout <<"Rezultatai "<<endl;
    cout <<"Didziausias elementas yra: "<<max<<endl;
    cout <<"Maziausias elementas yra: "<<min<<endl;
    cout <<"Masyvu suma: "<<suma<<endl;


//-----------------------------Antra uzduotis-----------------------------
    cout <<"-------------------Antra uzduotis-----------------------------"<<endl;
    int massyvas[40] ={1, 1, 1, 1, 1, 10, 7, 8, 9, 10, 3, 4, 7, 8, 9, 2, 3, 7, 8, 10, 5, 6, 9, 10, 7, 3, 5, 6, 8, 10, 9, 4, 2, 6, 7, 8, 9, 7, 6, 10};
    int q1=0, q2=0, q3=0, q4=0, q5=0, q6=0, q7=0, q8=0, q9=0, q10=0;

    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 1) {
        q1++;
        }
}
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 2) {
            q2++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 3) {
            q3++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 4) {
            q4++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 5) {
            q5++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 6) {
            q6++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 7) {
            q7++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 8) {
            q8++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 9) {
            q9++;
        }
    }
    for (int g = 0; g<40; g++) {
        if (massyvas[g] == 10) {
            q10++;
        }
    }
    cout <<"1 kiekis masyve yra: "<<q1<<endl;
    cout <<"2 kiekis masyve yra: "<<q2<<endl;
    cout <<"3 kiekis masyve yra: "<<q3<<endl;
    cout <<"4 kiekis masyve yra: "<<q4<<endl;
    cout <<"5 kiekis masyve yra: "<<q5<<endl;
    cout <<"6 kiekis masyve yra: "<<q6<<endl;
    cout <<"7 kiekis masyve yra: "<<q7<<endl;
    cout <<"8 kiekis masyve yra: "<<q8<<endl;
    cout <<"9 kiekis masyve yra: "<<q9<<endl;
    cout <<"10 kiekis masyve yra: "<<q10<<endl;
    return 0;
}
