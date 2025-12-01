#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double matrica[7][7], choice, x1, x2, x3, temp1, temp2, temp3, patirinimas[4][4], eil=3, stulp=3, tempMatrica[4][4], temp[7][4];


void atvirkstines_matricos_radimas() {


    matrica[1][4]=1, matrica[1][5]=0, matrica[1][6]=0;
    matrica[2][4]=0, matrica[2][5]=1, matrica[2][6]=0;
    matrica[3][4]=0, matrica[3][5]=0, matrica[3][6]=1;

    x1=-matrica[2][1]/matrica[1][1];
    x2=-matrica[3][1]/matrica[1][1];

    for (int i=1; i<=6; i++) {
        matrica[2][i]=matrica[1][i]*x1+matrica[2][i];
    }
    for (int i=1; i<=6; i++) {
        matrica[3][i]=matrica[1][i]*x2+matrica[3][i];
    }

    x1=-matrica[3][2]/matrica[2][2];

    for (int i=2; i<=6; i++) {
        matrica[3][i]=matrica[2][i]*x1+matrica[3][i];
    }

    x1=-matrica[2][3]/matrica[3][3];
    x2=-matrica[1][3]/matrica[3][3];

    for (int i=3; i<=6; i++) {
        matrica[2][i]=matrica[3][i]*x1+matrica[2][i];
    }
    for (int i=3; i<=6; i++) {
        matrica[1][i]=matrica[3][i]*x2+matrica[1][i];
    }

    x1=-matrica[1][2]/matrica[2][2];

    for (int i=2; i<=6; i++) {
        matrica[1][i]=matrica[2][i]*x1+matrica[1][i];
    }

    temp1=matrica[1][1];
    temp2=matrica[2][2];
    temp3=matrica[3][3];


    for (int i=1; i<=6; i++) {
        matrica[1][i]=matrica[1][i]/temp1;
    }
    for (int i=1; i<=6; i++) {
        matrica[2][i]=matrica[2][i]/temp2;
    }
    for (int i=1; i<=6; i++) {
        matrica[3][i]=matrica[3][i]/temp3;
    }

    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            temp[i][j]=matrica[i][j+3];
        }
    }

    for (int i=1; i<=eil; i++)
        for (int j=1; j<=stulp; j++)
            patirinimas[i][j] = 0;

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            for(int a=1; a<=stulp; a++) {
                patirinimas[i][j]+=tempMatrica[i][a]*temp[a][j];
                if (fabs(patirinimas[i][j])<1e-10) {
                    patirinimas[i][j]=0;
                }
            }
        }
    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Gauta matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=6; j++) {
            if (j==4) {
                cout<<"| "<<setprecision(2)<<matrica[i][j]<<"  ";
            } else {
                cout<<setprecision(2)<<matrica[i][j]<<"  ";
            }
        }
        cout<<endl;
    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Po patikrinimo:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<patirinimas[i][j]<<"  ";
        }
        cout<<endl;
    }

}


int main() {

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<"Irasykite "<<i<<" eilutes, "<<j<<" stulpelio skaiciu:"<<endl;
            cin>>matrica[i][j];
            tempMatrica[i][j]=matrica[i][j];
        }
    }

    atvirkstines_matricos_radimas();

    return 0;
}