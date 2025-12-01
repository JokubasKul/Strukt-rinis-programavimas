#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int choice, subchoice, eil, stulp, eil2, stulp2;
double atsakymas, d1,d2,d3, matrica1[4][4], matrica2[4][4], matrica3[4][4], determinantas[5][7] ,temp[4][7], dauginamasis, B[4], krameris[4], x1, x2, x3, temp1, temp2, temp3, C[4];


void matricos1_sudarymas() {

    cout<<"Kiek matrica tures eiluciu?"<<endl;
    cin>>eil;
    cout<<"Kiek matrica tures stulpeliu?"<<endl;
    cin>>stulp;

    cout<<"--------------------------------------"<<endl;

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<"Irasykite "<<i<<" eilutes, "<<j<<" stulpelio skaiciu:"<<endl;
            cin>>matrica1[i][j];
        }
    }

    cout<<"--------------------------------------"<<endl;
}


void matricos2_sudarymas() {

    cout<<"Kiek matrica tures eiluciu?"<<endl;
    cin>>eil2;
    cout<<"Kiek matrica tures stulpeliu?"<<endl;
    cin>>stulp2;

    cout<<"--------------------------------------"<<endl;

    for(int i=1; i<=eil2; i++) {
        for(int j=1; j<=stulp2; j++) {
            cout<<"Irasykite "<<i<<" eilutes, "<<j<<" stulpelio skaiciu:"<<endl;
            cin>>matrica2[i][j];
        }
    }

    cout<<"--------------------------------------"<<endl;
}


void matricu_sudarymas() {

    cout<<"Sudarykite pirma matrica:"<<endl;
    matricos1_sudarymas();
    cout<<"Sudarykite antra matrica:"<<endl;
    matricos2_sudarymas();
    cout<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Pirma matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<matrica1[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<"--------------------------------------"<<endl;
    cout<<endl;

    cout<<"Antra matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil2; i++) {
        for(int j=1; j<=stulp2; j++) {
            cout<<matrica2[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"--------------------------------------"<<endl;
}


void matricu_sudetis() {

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            matrica3[i][j]=matrica1[i][j]+matrica2[i][j];
        }
    }

    cout<<"Atsakymas:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<matrica3[i][j]<<"  ";
        }
        cout<<endl;
    }
}


void matricu_atimtis() {

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            matrica3[i][j]=matrica1[i][j]-matrica2[i][j];
        }
    }

    cout<<"Atsakymas:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<matrica3[i][j]<<"  ";
        }
        cout<<endl;
    }
}


void daugyba_su_vienu_skaiciumi() {

    matricos1_sudarymas();
    cout<<endl;
    cout<<"Is kokio skaiciaus dauginsite sia matrica?"<<endl;
    cin>>dauginamasis;

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            matrica3[i][j]=matrica1[i][j]*dauginamasis;
        }
    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Atsakymas:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<matrica3[i][j]<<"  ";
        }
        cout<<endl;
    }

}


void matricu_daugyba() {

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp2; j++) {
            for(int a=1; a<=stulp; a++) {
                matrica3[i][j]+=matrica1[i][a]*matrica2[a][j];
            }
        }
    }

    cout<<fixed<<setprecision(2);
    cout<<"Atsakymas:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp2; j++) {
            cout<<setprecision(2)<<matrica3[i][j]<<"  ";
        }
        cout<<endl;
    }
}


void determinanto_sudarymas() {

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<"Irasykite "<<i<<" eilutes, "<<j<<" stulpelio skaiciu:"<<endl;
            cin>>determinantas[i][j];
            matrica1[i][j]=determinantas[i][j];
        }
    }
}


void determinantai() {

    determinanto_sudarymas();

    if (eil==2 || stulp==2) {
        atsakymas=determinantas[1][1]*determinantas[2][2]-determinantas[1][2]*determinantas[2][1];
        cout<<atsakymas<<endl;

    }
    if (eil==3 || stulp==3) {
        atsakymas=  determinantas[1][1]*determinantas[2][2]*determinantas[3][3]+
                    determinantas[2][1]*determinantas[3][2]*determinantas[1][3]+
                    determinantas[3][1]*determinantas[1][2]*determinantas[2][3]-
                    determinantas[1][3]*determinantas[2][2]*determinantas[3][1]-
                    determinantas[2][3]*determinantas[3][2]*determinantas[1][1]-
                    determinantas[3][3]*determinantas[1][2]*determinantas[2][1];
    }

    if (eil==4 || stulp==4) {
        x1=-determinantas[2][1]/determinantas[1][1];
        x2=-determinantas[3][1]/determinantas[1][1];
        x3=-determinantas[4][1]/determinantas[1][1];

        for (int i=1; i<=stulp; i++) {
            determinantas[2][i]=determinantas[1][i]*x1+determinantas[2][i];
        }
        for (int i=1; i<=stulp; i++) {
            determinantas[3][i]=determinantas[1][i]*x2+determinantas[3][i];
        }
        for (int i=1; i<=stulp; i++) {
            determinantas[4][i]=determinantas[1][i]*x3+determinantas[4][i];
        }

        x1=-determinantas[3][2]/determinantas[2][2];
        x2=-determinantas[4][2]/determinantas[2][2];

        for (int i=2; i<=stulp; i++) {
            determinantas[3][i]=determinantas[2][i]*x1+determinantas[3][i];
        }
        for (int i=2; i<=stulp; i++) {
            determinantas[4][i]=determinantas[2][i]*x2+determinantas[4][i];
        }

        x1=-determinantas[4][3]/determinantas[3][3];

        if (determinantas[3][3]==0) {
            determinantas[4][3]=0;
            determinantas[4][4]=0;
        } else {

            for (int i=3; i<=stulp; i++) {
                determinantas[4][i]=determinantas[3][i]*x1+determinantas[4][i];
            }
        }

        atsakymas=determinantas[1][1]*determinantas[2][2]*determinantas[3][3]*determinantas[4][4];

    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Determinantas:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<determinantas[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"--------------------------------------"<<endl;
    cout<<"Atsakymas:"<<endl;
    cout<<endl;
    cout<<atsakymas<<endl;
}


void atvirkstines_matricos_metodas() {

    determinanto_sudarymas();

    determinantas[1][4]=1, determinantas[1][5]=0, determinantas[1][6]=0;
    determinantas[2][4]=0, determinantas[2][5]=1, determinantas[2][6]=0;
    determinantas[3][4]=0, determinantas[3][5]=0, determinantas[3][6]=1;

    x1=-determinantas[2][1]/determinantas[1][1];
    x2=-determinantas[3][1]/determinantas[1][1];

    for (int i=1; i<=6; i++) {
        determinantas[2][i]=determinantas[1][i]*x1+determinantas[2][i];
    }
    for (int i=1; i<=6; i++) {
        determinantas[3][i]=determinantas[1][i]*x2+determinantas[3][i];
    }

    x1=-determinantas[3][2]/determinantas[2][2];

    for (int i=2; i<=6; i++) {
        determinantas[3][i]=determinantas[2][i]*x1+determinantas[3][i];
    }

    x1=-determinantas[2][3]/determinantas[3][3];
    x2=-determinantas[1][3]/determinantas[3][3];

    for (int i=3; i<=6; i++) {
        determinantas[2][i]=determinantas[3][i]*x1+determinantas[2][i];
    }
    for (int i=3; i<=6; i++) {
        determinantas[1][i]=determinantas[3][i]*x2+determinantas[1][i];
    }

    x1=-determinantas[1][2]/determinantas[2][2];

    for (int i=2; i<=6; i++) {
        determinantas[1][i]=determinantas[2][i]*x1+determinantas[1][i];
    }

    temp1=determinantas[1][1];
    temp2=determinantas[2][2];
    temp3=determinantas[3][3];


    for (int i=1; i<=6; i++) {
        determinantas[1][i]=determinantas[1][i]/temp1;
    }
    for (int i=1; i<=6; i++) {
        determinantas[2][i]=determinantas[2][i]/temp2;
    }
    for (int i=1; i<=6; i++) {
        determinantas[3][i]=determinantas[3][i]/temp3;
    }

    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            temp[i][j]=determinantas[i][j+3];
        }
    }

    for (int i=1; i<=eil; i++)
        for (int j=1; j<=stulp; j++)
            matrica3[i][j] = 0;

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            for(int a=1; a<=stulp; a++) {
                matrica3[i][j]+=matrica1[i][a]*temp[a][j];
                if (fabs(matrica3[i][j])<1e-10) {
                    matrica3[i][j]=0;
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
                cout<<"| "<<setprecision(2)<<determinantas[i][j]<<"  ";
            } else {
                cout<<setprecision(2)<<determinantas[i][j]<<"  ";
            }
        }
        cout<<endl;
    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Po patikrinimo:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<matrica3[i][j]<<"  ";
        }
        cout<<endl;
    }

}


void gauso_ir_zordano() {

    determinanto_sudarymas();

    for(int i=1; i<=3; i++) {
        cout<<"Irasykite B"<<i<<":"<<endl;
        cin>>determinantas[i][4];
    }

    x1=-determinantas[2][1]/determinantas[1][1];
    x2=-determinantas[3][1]/determinantas[1][1];

    for (int i=1; i<=4; i++) {
        determinantas[2][i]=determinantas[1][i]*x1+determinantas[2][i];
    }
    for (int i=1; i<=4; i++) {
        determinantas[3][i]=determinantas[1][i]*x2+determinantas[3][i];
    }

    x1=-determinantas[3][2]/determinantas[2][2];

    for (int i=2; i<=4; i++) {
        determinantas[3][i]=determinantas[2][i]*x1+determinantas[3][i];
    }

    x1=-determinantas[2][3]/determinantas[3][3];
    x2=-determinantas[1][3]/determinantas[3][3];

    for (int i=3; i<=4; i++) {
        determinantas[2][i]=determinantas[3][i]*x1+determinantas[2][i];
    }
    for (int i=3; i<=4; i++) {
        determinantas[1][i]=determinantas[3][i]*x2+determinantas[1][i];
    }

    x1=-determinantas[1][2]/determinantas[2][2];

    for (int i=2; i<=4; i++) {
        determinantas[1][i]=determinantas[2][i]*x1+determinantas[1][i];
    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Gauta matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=4; j++) {
            if (j==4) {
                cout<<"| "<<setprecision(2)<<determinantas[i][j]<<"  ";
            } else {
                cout<<setprecision(2)<<determinantas[i][j]<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<endl;

    x1=determinantas[1][4]/determinantas[1][1];
    x2=determinantas[2][4]/determinantas[2][2];
    x3=determinantas[3][4]/determinantas[3][3];

    cout<<"X1: "<<setprecision(2)<<x1<<endl;
    cout<<"X2: "<<setprecision(2)<<x2<<endl;
    cout<<"X3: "<<setprecision(2)<<x3<<endl;

}


void transponacija() {

    matricos1_sudarymas();

    cout<<"--------------------------------------"<<endl;
    cout<<"Matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<matrica1[i][j]<<"  ";
        }
        cout<<endl;
    }

    eil2=eil;
    eil=stulp;
    stulp=eil2;

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            matrica3[i][j]=matrica1[j][i];
        }
    }

    cout<<"--------------------------------------"<<endl;
    cout<<"Transponuota matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<matrica3[i][j]<<"  ";
        }
        cout<<endl;
    }
}


void atvirkstine_matrica() {

    eil=3, stulp=3;

    determinanto_sudarymas();

    atsakymas= determinantas[1][1]*(determinantas[2][2]*determinantas[3][3] -
               determinantas[2][3]*determinantas[3][2]) -
               determinantas[1][2]*(determinantas[2][1]*determinantas[3][3] -
               determinantas[2][3]*determinantas[3][1]) +
               determinantas[1][3]*(determinantas[2][1]*determinantas[3][2] -
               determinantas[2][2]*determinantas[3][1]);

    if (atsakymas==0) {
        cout<<"Atvirkstine matrica yra neteisinga, nes determinantas yra = 0"<<endl;
        return;
    }

    atsakymas=1.0/atsakymas;

    temp[1][1] =determinantas[2][2]*determinantas[3][3] - determinantas[2][3]*determinantas[3][2];
    temp[1][2] =-(determinantas[2][1]*determinantas[3][3] - determinantas[2][3]*determinantas[3][1]);
    temp[1][3] =determinantas[2][1]*determinantas[3][2] - determinantas[2][2]*determinantas[3][1];
    temp[2][1] =-(determinantas[1][2]*determinantas[3][3] - determinantas[1][3]*determinantas[3][2]);
    temp[2][2] =determinantas[1][1]*determinantas[3][3] - determinantas[1][3]*determinantas[3][1];
    temp[2][3] =-(determinantas[1][1]*determinantas[3][2] - determinantas[1][2]*determinantas[3][1]);
    temp[3][1] =determinantas[1][2]*determinantas[2][3] - determinantas[1][3]*determinantas[2][2];
    temp[3][2] =-(determinantas[1][1]*determinantas[2][3] - determinantas[1][3]*determinantas[2][1]);
    temp[3][3] =determinantas[1][1]*determinantas[2][2] - determinantas[1][2]*determinantas[2][1];

    cout<<"--------------------------------------"<<endl;
    cout<<"Atvirkstine matrica:"<<endl;
    cout<<endl;
    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<setprecision(2)<<temp[j][i]*atsakymas<<"  ";
        }
        cout<<endl;
    }
}


void leontjevo() {

    for(int i=1; i<=eil; i++) {
        for(int j=1; j<=stulp; j++) {
            cout<<"Irasykite "<<i<<" eilutes, "<<j<<" stulpelio skaiciu:"<<endl;
            cin>>determinantas[i][j];
        }
    }

    temp[1][1]=1, temp[1][2]=0, temp[1][3]=0;
    temp[2][1]=0, temp[2][2]=1, temp[2][3]=0;
    temp[3][1]=0, temp[3][2]=0, temp[3][3]=1;

    if (eil==2 || stulp==2) {

        cout<<endl;
        for(int i=1; i<=2; i++) {
            cout<<"Irasykite C"<<i<<":"<<endl;
            cin>>C[i];
        }

        for(int i=1; i<=eil; i++) {
            for(int j=1; j<=stulp; j++) {
                determinantas[i][j]=temp[i][j]-determinantas[i][j];
            }
        }

        atsakymas= determinantas[1][1]*determinantas[2][2]-determinantas[1][2]*determinantas[2][1];
        atsakymas=1.0/atsakymas;

        temp[1][1]=determinantas[2][2]*atsakymas;
        temp[1][2]=-determinantas[2][1]*atsakymas;
        temp[2][1]=-determinantas[1][2]*atsakymas;
        temp[2][2]=determinantas[1][1]*atsakymas;

        determinantas[1][1]=0;
        determinantas[2][1]=0;
        determinantas[1][1]=temp[1][1]*C[1]+temp[1][2]*C[1];
        determinantas[2][1]=temp[2][1]*C[2]+temp[2][2]*C[2];

        cout<<"--------------------------------------"<<endl;
        cout<<"Atvirkstine matrica:"<<endl;
        cout<<endl;
        for(int i=1; i<=eil; i++) {
            for(int j=1; j<=stulp; j++) {
                cout<<setprecision(2)<<temp[i][j]<<"  ";
            }
            cout<<endl;
        }

        cout<<fixed<<setprecision(2);
        cout<<"--------------------------------------"<<endl;
        cout<<"Gauta matrica:"<<endl;
        cout<<endl;
        cout<<determinantas[1][1]<<endl;
        cout<<determinantas[2][1]<<endl;

    }

    if (eil==3 || stulp==3) {

        cout<<endl;
        for(int i=1; i<=3; i++) {
            cout<<"Irasykite C"<<i<<":"<<endl;
            cin>>C[i];
        }

        for(int i=1; i<=eil; i++) {
            for(int j=1; j<=stulp; j++) {
                determinantas[i][j]=temp[i][j]-determinantas[i][j];
            }
        }

        atsakymas= determinantas[1][1]*(determinantas[2][2]*determinantas[3][3] -
                   determinantas[2][3]*determinantas[3][2]) -
                   determinantas[1][2]*(determinantas[2][1]*determinantas[3][3] -
                   determinantas[2][3]*determinantas[3][1]) +
                   determinantas[1][3]*(determinantas[2][1]*determinantas[3][2] -
                   determinantas[2][2]*determinantas[3][1]);

        atsakymas=1.0/atsakymas;

        temp[1][1]= determinantas[2][2]*determinantas[3][3] - determinantas[2][3]*determinantas[3][2];
        temp[1][2]= -(determinantas[2][1]*determinantas[3][3] - determinantas[2][3]*determinantas[3][1]);
        temp[1][3]= determinantas[2][1]*determinantas[3][2] - determinantas[2][2]*determinantas[3][1];
        temp[2][1]= -(determinantas[1][2]*determinantas[3][3] - determinantas[1][3]*determinantas[3][2]);
        temp[2][2]= determinantas[1][1]*determinantas[3][3] - determinantas[1][3]*determinantas[3][1];
        temp[2][3]= -(determinantas[1][1]*determinantas[3][2] - determinantas[1][2]*determinantas[3][1]);
        temp[3][1]= determinantas[1][2]*determinantas[2][3] - determinantas[1][3]*determinantas[2][2];
        temp[3][2]= -(determinantas[1][1]*determinantas[2][3] - determinantas[1][3]*determinantas[2][1]);
        temp[3][3]= determinantas[1][1]*determinantas[2][2] - determinantas[1][2]*determinantas[2][1];

        for(int i=1; i<=eil; i++) {
            for(int j=1; j<=stulp; j++) {
                temp[i][j]=temp[i][j]*atsakymas;
            }
        }
        determinantas[1][1]= temp[1][1]*C[1]+temp[2][1]*C[1]+temp[3][1]*C[1];
        determinantas[2][1]= temp[1][2]*C[2]+temp[2][2]*C[2]+temp[3][2]*C[2];
        determinantas[3][1]= temp[1][3]*C[3]+temp[2][3]*C[3]+temp[3][3]*C[3];

        cout<<"--------------------------------------"<<endl;
        cout<<"Atvirkstine matrica:"<<endl;
        cout<<endl;
        for(int i=1; i<=eil; i++) {
            for(int j=1; j<=stulp; j++) {
                cout<<setprecision(2)<<temp[j][i]<<"  ";
            }
            cout<<endl;
        }

        cout<<fixed<<setprecision(2);
        cout<<"--------------------------------------"<<endl;
        cout<<"Gauta matrica:"<<endl;
        cout<<endl;
        cout<<determinantas[1][1]<<endl;
        cout<<determinantas[2][1]<<endl;
        cout<<determinantas[3][1]<<endl;

    }

}


void kramerio_metodas() {

    eil=3, stulp=3;

    determinanto_sudarymas();

    cout<<endl;
    for(int i=1; i<=3; i++) {
        cout<<"Irasykite B "<<i<<"-aji skaiciu"<<endl;
        cin>>B[i];
    }


    atsakymas=  determinantas[1][1]*determinantas[2][2]*determinantas[3][3]
              + determinantas[1][2]*determinantas[2][3]*determinantas[3][1]
              + determinantas[1][3]*determinantas[2][1]*determinantas[3][2]
              - determinantas[1][3]*determinantas[2][2]*determinantas[3][1]
              - determinantas[1][2]*determinantas[2][1]*determinantas[3][3]
              - determinantas[1][1]*determinantas[2][3]*determinantas[3][2];

    d1=         B[1]*determinantas[2][2]*determinantas[3][3]
              + determinantas[1][2]*determinantas[2][3]*B[3]
              + determinantas[1][3]*B[2]*determinantas[3][2]
              - determinantas[1][3]*determinantas[2][2]*B[3]
              - determinantas[1][2]*B[2]*determinantas[3][3]
              - B[1]*determinantas[2][3]*determinantas[3][2];

    d2=         determinantas[1][1]*B[2]*determinantas[3][3]
              + B[1]*determinantas[2][3]*determinantas[3][1]
              + determinantas[1][3]*determinantas[2][1]*B[3]
              - determinantas[1][3]*B[2]*determinantas[3][1]
              - B[1]*determinantas[2][1]*determinantas[3][3]
              - determinantas[1][1]*determinantas[2][3]*B[3];

    d3=         determinantas[1][1]*determinantas[2][2]*B[3]
              + determinantas[1][2]*B[2]*determinantas[3][1]
              + B[1]*determinantas[2][1]*determinantas[3][2]
              - B[1]*determinantas[2][2]*determinantas[3][1]
              - determinantas[1][2]*determinantas[2][1]*B[3]
              - determinantas[1][1]*B[2]*determinantas[3][2];

    double x1=d1/atsakymas;
    double x2=d2/atsakymas;
    double x3=d3/atsakymas;

    cout<<"--------------------------------------"<<endl;
    cout<<"X1: "<<setprecision(2)<<x1<<endl;
    cout<<"X2: "<<setprecision(2)<<x2<<endl;
    cout<<"X3: "<<setprecision(2)<<x3<<endl;
}


int main() {

    while(choice!=7) {
        subchoice=0;

        cout<<"--------------------------------------"<<endl;
        cout<<"Koki veiksma noretumete atlikti?"<<endl;
        cout<<"1. Veiksmai su matricomis"<<endl;
        cout<<endl;
        cout<<"2. Determinantu skaiciavimai"<<endl;
        cout<<endl;
        cout<<"3. X1, X2, X3 radimas"<<endl;
        cout<<endl;
        cout<<"4. Gauso metodas atvirkstines matricos radimui"<<endl;
        cout<<"5. Leontjevo modelis"<<endl;
        cout<<"6. Atvirkstine matrica"<<endl;
        cout<<endl;
        cout<<"7. Baigti darba"<<endl;
        cout<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Irasykite nuo 1 iki 7"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                while (subchoice!=6) {
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Koki veiksma noretumete atlikti?"<<endl;
                    cout<<"1. Sudeti matricas"<<endl;
                    cout<<"2. Atimti matricas"<<endl;
                    cout<<"3. Sudauginti matrica su skaiciu"<<endl;
                    cout<<"4. Dauginti matricas"<<endl;
                    cout<<"5. Matricos transponacija"<<endl;
                    cout<<endl;
                    cout<<"6. Grizti atgal"<<endl;
                    cout<<endl;
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Irasykite nuo 1 iki 6"<<endl;
                    cin>>subchoice;
                    switch (subchoice) {
                        case 1:
                            matricu_sudarymas();
                            if(eil!=eil2 || stulp!=stulp2) {
                                cout<<"Kad butu galima atlikti veiksma, matricu eilutes ir stulpeliai turi buti tokie patys"<<endl;
                            } else {
                                matricu_sudetis();
                            }
                        break;
                        case 2:
                            matricu_sudarymas();
                            if(eil!=eil2 || stulp!=stulp2) {
                                cout<<"Kad butu galima atlikti veiksma, matricu eilutes ir stulpeliai turi buti tokie patys"<<endl;
                            } else {
                                matricu_atimtis();
                            }
                        break;
                        case 3:
                            daugyba_su_vienu_skaiciumi();
                        break;
                        case 4:
                            matricu_sudarymas();
                            if(stulp!=eil2) {
                                cout<<"Kad butu galima atlikti veiksma, pirmos matricos stulpeliu skaicius"<<endl;
                                cout<<"ir antros matricos eiluciu skaicius turi buti tokie patys"<<endl;
                            } else {
                                matricu_daugyba();
                            }
                        break;
                        case 5:
                            transponacija();
                        break;
                        case 6:
                            cout<<"Griztama atgal"<<endl;
                        break;
                        default:
                            cout<<"Tokio pasirinkimo nera"<<endl;
                        break;
                    }
                }
            break;
            case 2:
                while (subchoice!=5) {
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Koki veiksma noretumete atlikti?"<<endl;
                    cout<<"2. 2-eilis determinantas"<<endl;
                    cout<<"3. 3-eilis determinantas"<<endl;
                    cout<<"4. 4-eilis determinantas"<<endl;
                    cout<<endl;
                    cout<<"5. Grizti atgal"<<endl;
                    cout<<endl;
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Irasykite nuo 2 iki 5"<<endl;
                    cin>>subchoice;
                    switch (subchoice) {
                        case 2:
                            eil=2, stulp=2;
                            determinantai();
                        break;
                        case 3:
                            eil=3, stulp=3;
                            determinantai();
                        break;
                        case 4:
                            eil=4, stulp=4;
                            determinantai();
                        case 5:
                            cout<<"Griztama atgal"<<endl;
                        break;
                        default:
                            cout<<"Tokio pasirinkimo nera"<<endl;
                        break;
                    }
                }
            break;
            case 3:
                while (subchoice!=3) {
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Koki veiksma noretumete atlikti?"<<endl;
                    cout<<"1. Kramerio metodas"<<endl;
                    cout<<"2. Gauso ir Zordano metodas"<<endl;
                    cout<<endl;
                    cout<<"3. Grizti atgal"<<endl;
                    cout<<endl;
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Irasykite nuo 1 iki 3"<<endl;
                    cin>>subchoice;
                    switch (subchoice) {
                        case 1:
                            kramerio_metodas();
                        break;
                        case 2:
                            eil=3, stulp=3;
                            gauso_ir_zordano();
                        break;
                        case 3:
                            cout<<"Griztama atgal"<<endl;
                        break;
                        default:
                            cout<<"Tokio pasirinkimo nera"<<endl;
                        break;
                    }
                }
            break;
            case 4:
                eil=3, stulp=3;
                atvirkstines_matricos_metodas();
            break;
            case 5:
                while (subchoice!=3) {
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Koki veiksma noretumete atlikti?"<<endl;
                    cout<<"2. 2-eiles Leontjevo modelis"<<endl;
                    cout<<"3. 3-eiles Leontjevo modelis"<<endl;
                    cout<<endl;
                    cout<<"4. Grizti atgal"<<endl;
                    cout<<endl;
                    cout<<"--------------------------------------"<<endl;
                    cout<<"Irasykite nuo 2 iki 4"<<endl;
                    cin>>subchoice;
                    switch (subchoice) {
                        case 1:
                            eil=2, stulp=2;
                            leontjevo();
                        break;
                        case 2:
                            eil=3, stulp=3;
                            leontjevo();
                        break;
                        case 3:
                            cout<<"Griztama atgal"<<endl;
                        break;
                        default:
                            cout<<"Tokio pasirinkimo nera"<<endl;
                        break;
                    }
                }
            break;
            case 6:
                atvirkstine_matrica();
            break;
            case 7:
                cout<<"Darbas baigtas"<<endl;
            break;
            default:
                cout<<"Tokio pasirinkimo nera"<<endl;
            break;
        }
    }

    return 0;
}