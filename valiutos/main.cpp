#include <iostream>
using namespace std;
int main() {
    int choice, choice1, choice2, choice3, choice4;
    int gbp1, gbp2, gbp3, usd1, usd2, usd3, eur1, eur2, eur3, inr1, inr2, inr3,gbp1s, gbp2s, gbp3s, usd1s, usd2s, usd3s, inr1s, inr2s, inr3s, eur1s, eur2s, eur3s;
    cout <<"Pasirinkite savo valiuta: "<<endl;
    cout <<"1. EUR"<<endl;
    cout <<"2. GBP"<<endl;
    cout <<"3. INR"<<endl;
    cout <<"4. USD"<<endl;
    cout <<"Jusu valiuta: "<<endl;
    cin >>choice;

    switch (choice) {
        case 1:
            cout <<"Jusu valiuta yra eurai"<<endl;
        cout <<"I ka norite iskeisti eurus? "<<endl;
        cout <<"1. GBP bendras"<<endl;
        cout <<"2. GBP pirkti"<<endl;
        cout <<"3. GBP parduoti"<<endl;
        cout <<"4. USD bendras"<<endl;
        cout <<"5. USD pirkti"<<endl;
        cout <<"6. USD parduoti"<<endl;
        cout <<"7. INR bendras"<<endl;
        cout <<"8. INR prikti"<<endl;
        cout <<"9. INR parduoti"<<endl;
        cout <<"Jusu pasirinkimas: "<<endl;
        cin >>choice1;

        switch (choice1) {
            case 1:
                cout <<"Jus pasirinkote iskeisti eurus i JAV DOLERIUS"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>usd1;
            usd1s=usd1*1.071;
            cout <<"Jus gausite: "<<usd1s<<endl;
            break;

            case 2:
                cout <<"Jus pasirinkote pirkti USD su eurais"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>usd2;
            usd2s=usd2*1.0547;
            cout <<"Jus parduosite: "<<usd2s<<endl;
            break;

            case 3:
                cout <<"Jus pasirinkote parduoti USD "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>usd3;
            usd3s=usd3*1.13;
            cout <<"Jus gausite"<<usd3s<<endl;
            break;

            case 4:
                cout <<"Jus pasirinkote iskeisti eurus i Didziosios Britanijos svara"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>gbp1;
            gbp1s=gbp1*0.859;
            cout <<"Jus gausite: "<<gbp1s<<endl;
            break;

            case 5:
                cout <<"Jus pasirinkote pirkti GBP su eurais"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>gbp2;
            gbp2s=gbp2*0.845;
            cout <<"Jus parduosite: "<<gbp2s<<endl;
            break;

            case 6:
                cout <<"Jus pasirinkote parduoti GBP "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>gbp3;
            gbp3s=gbp3*0.906;
            cout <<"Jus gausite"<<gbp3s<<endl;
            break;

            case 7:
                cout <<"Jus pasirinkote iskeisti eurus i Indijos rupija"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>inr1;
            inr1s=inr1*0.859;
            cout <<"Jus gausite: "<<inr1s<<endl;
            break;

            case 8:
                cout <<"Jus pasirinkote pirkti INR su eurais"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>inr2;
            inr2s=inr2*0.845;
            cout <<"Jus parduosite: "<<inr2s<<endl;
            break;

            case 9:
                cout <<"Jus pasirinkote parduoti INR "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>inr3;
            inr3s=inr3*0.906;
            cout <<"Jus gausite"<<inr3s<<endl;
            break;
        }
        break;
        case 2:
            cout <<"Jusu valiuta yra Didziosios britanijos svarai"<<endl;
        cout <<"I ka norite iskeisti DP svarus? "<<endl;
        cout <<"1. EUR bendras"<<endl;
        cout <<"2. EUR pirkti"<<endl;
        cout <<"3. EUR parduoti"<<endl;
        cout <<"4. USD bendras"<<endl;
        cout <<"5. USD pirkti"<<endl;
        cout <<"6. USD parduoti"<<endl;
        cout <<"7. INR bendras"<<endl;
        cout <<"8. INR prikti"<<endl;
        cout <<"9. INR parduoti"<<endl;
        cout <<"Jusu pasirinkimas: "<<endl;
        cin >>choice2;
        switch (choice2) {
            case 1:
                cout <<"Jus pasirinkote iskeisti GBP i JAV DOLERIUS"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>usd1;
            usd1s=usd1*1.328;
            cout <<"Jus gausite: "<<usd1s<<endl;
            break;

            case 2:
                cout <<"Jus pasirinkote pirkti USD su GBP"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>usd2;
            usd2s=usd2*1.21;
            cout <<"Jus parduosite: "<<usd2s<<endl;
            break;

            case 3:
                cout <<"Jus pasirinkote parduoti GBP "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>usd3;
            usd3s=usd3*1.14;
            cout <<"Jus gausite"<<usd3s<<endl;
            break;

            case 4:
                cout <<"Jus pasirinkote iskeisti Didziosios Britanijos svarus i eurus"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>eur1;
            eur1s=eur1*1.191;
            cout <<"Jus gausite: "<<eur1s<<endl;
            break;

            case 5:
                cout <<"Jus pasirinkote pirkti eurus su GBP"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>eur2;
            eur2s=eur2*1.21;
            cout <<"Jus parduosite: "<<eur2s<<endl;
            break;

            case 6:
                cout <<"Jus pasirinkote parduoti GBP su eurais "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>eur3;
            eur3s=eur3*1.14;
            cout <<"Jus gausite"<<eur3s<<endl;
            break;

            case 7:
                cout <<"Jus pasirinkote iskeisti GBP i Indijos rupija"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>inr1;
            inr1s=inr1*111.163;
            cout <<"Jus gausite: "<<inr1s<<endl;
            break;

            case 8:
                cout <<"Jus pasirinkote pirkti INR su GBP"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>inr2;
            inr2s=inr2*1.21;
            cout <<"Jus parduosite: "<<inr2s<<endl;
            break;

            case 9:
                cout <<"Jus pasirinkote parduoti INR su GBP"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>inr3;
            inr3s=inr3*1.14;
            cout <<"Jus gausite"<<inr3s<<endl;
            break;
        }
        break;
        case 3:
            cout <<"Jusu valiuta yra Indijos rupinai"<<endl;
        cout <<"I ka norite iskeisti Indijos rupinus? "<<endl;
        cout <<"1. USD bendras"<<endl;
        cout <<"2. USD pirkti"<<endl;
        cout <<"3. USD parduoti"<<endl;
        cout <<"4. EUR bendras"<<endl;
        cout <<"5. EUR pirkti"<<endl;
        cout <<"6. EUR parduoti"<<endl;
        cout <<"7. GBP bendras"<<endl;
        cout <<"8. GBP prikti"<<endl;
        cout <<"9. GBP parduoti"<<endl;
        cout <<"Jusu pasirinkimas: "<<endl;
        cin >>choice3;

        switch (choice3) {
            case 1:
                cout <<"Jus pasirinkote iskeisti Indijos rupinus i JAV DOLERIUS"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>usd1;
            usd1s=usd1*1.328;
            cout <<"Jus gausite: "<<usd1s<<endl;
            break;

            case 2:
                cout <<"Jus pasirinkote pirkti USD su INR"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>usd2;
            usd2s=usd2*0.01;
            cout <<"Jus parduosite: "<<usd2s<<endl;
            break;

            case 3:
                cout <<"Jus pasirinkote parduoti USD SU INR "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>usd3;
            usd3s=usd3*0.01;
            cout <<"Jus gausite"<<usd3s<<endl;
            break;

            case 4:
                cout <<"Jus pasirinkote iskeisti Indijos rupinus i eurus"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>eur1;
            eur1s=eur1*0.006;
            cout <<"Jus gausite: "<<eur1s<<endl;
            break;

            case 5:
                cout <<"Jus pasirinkote pirkti eurus su INR"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>eur2;
            eur2s=eur2*0.01;
            cout <<"Jus parduosite: "<<eur2s<<endl;
            break;

            case 6:
                cout <<"Jus pasirinkote parduoti eurus su INR "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>eur3;
            eur3s=eur3*0.01;
            cout <<"Jus gausite"<<eur3s<<endl;
            break;

            case 7:
                cout <<"Jus pasirinkote iskeisti Indijos rupina i GBP"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>gbp1;
            gbp1s=gbp1*0.005;
            cout <<"Jus gausite: "<<gbp1s<<endl;
            break;

            case 8:
                cout <<"Jus pasirinkote pirkti GBP su INR"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>gbp2;
            gbp2s=gbp2*0.01;
            cout <<"Jus parduosite: "<<gbp2s<<endl;
            break;

            case 9:
                cout <<"Jus pasirinkote parduoti GBP su INR"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>gbp3;
            gbp3s=gbp3*0.01;
            cout <<"Jus gausite"<<gbp3s<<endl;
            break;
        }
        break;
        case 4:
            cout <<"Jusu valiuta yra JAV doleriai"<<endl;
        cout <<"I ka norite iskeisti Indijos rupinus? "<<endl;
        cout <<"1. INR bendras"<<endl;
        cout <<"2. INR pirkti"<<endl;
        cout <<"3. INR parduoti"<<endl;
        cout <<"4. EUR bendras"<<endl;
        cout <<"5. EUR pirkti"<<endl;
        cout <<"6. EUR parduoti"<<endl;
        cout <<"7. GBP bendras"<<endl;
        cout <<"8. GBP prikti"<<endl;
        cout <<"9. GBP parduoti"<<endl;
        cout <<"Jusu pasirinkimas: "<<endl;
        cin >>choice4;

        switch (choice4) {
            case 1:
                cout <<"Jus pasirinkote iskeisti JAV dolerius i Indijos rupinus"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>inr1;
            inr1s=inr1*83.5466;
            cout <<"Jus gausite: "<<inr1s<<endl;
            break;

            case 2:
                cout <<"Jus pasirinkote pirkti INR su USD"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>inr2;
            inr2s=inr2*0.01;
            cout <<"Jus parduosite: "<<inr2s<<endl;
            break;

            case 3:
                cout <<"Jus pasirinkote parduoti INR su USD "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>inr3;
            inr3s=inr3*0.01;
            cout <<"Jus gausite"<<inr3s<<endl;
            break;

            case 4:
                cout <<"Jus pasirinkote iskeisti JAV dolerius i eurus"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>eur1;
            eur1s=eur1*0.90;
            cout <<"Jus gausite: "<<eur1s<<endl;
            break;

            case 5:
                cout <<"Jus pasirinkote pirkti eurus su USD"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>eur2;
            eur2s=eur2*0.90;
            cout <<"Jus parduosite: "<<eur2s<<endl;
            break;

            case 6:
                cout <<"Jus pasirinkote parduoti eurus su USD "<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>eur3;
            eur3s=eur3*0.88;
            cout <<"Jus gausite"<<eur3s<<endl;
            break;

            case 7:
                cout <<"Jus pasirinkote iskeisti USD i GBP"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>gbp1;
            gbp1s=gbp1*0.75;
            cout <<"Jus gausite: "<<gbp1s<<endl;
            break;

            case 8:
                cout <<"Jus pasirinkote pirkti GBP su USD"<<endl;
            cout <<"Irasykite kieki:"<<endl;
            cin >>gbp2;
            gbp2s=gbp2*1.25;
            cout <<"Jus parduosite: "<<gbp2s<<endl;
            break;

            case 9:
                cout <<"Jus pasirinkote parduoti GBP su USD"<<endl;
            cout <<"Irasykite kieki: "<<endl;
            cin >>gbp3;
            gbp3s=gbp3*0.90;
            cout <<"Jus gausite"<<gbp3s<<endl;
            break;
        }
        break;
    }







    return 0;
}
