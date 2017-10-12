#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
char wybor;
int piny [5];
unsigned int kasa [5];
int pomocnik=0;
int PIN;
int captcha;
int sprawdzacz;
long double kasaa;
int proby;
int main()
{
    for(;;){
    cout << "Czy chcesz uruchomic Bankomat PKO Bank Polski?" << endl<<"1. Tak"<<endl<<"2. Nie"<<endl<<"Wybierz opcje: ";
    wybor = getch();
    cout<<endl;
    switch(wybor){
        case'1':{
            cout<<"Wloz karte";
            wybor = getch();
            cout<<endl;
            cout<<"Wybierz tryb:"<<endl<<"1. Bankomat"<<endl<<"2. Wplatomat"<<endl;
            wybor = getch();
            cout<<endl;
            switch(wybor){
                case'1':{
                    fstream plik;
                    plik.open("dane.txt",ios::in);
                    string linia;
                    int nr_linii=1;
                        while (getline(plik, linia))
                        {
                            switch (nr_linii)
                            {
                                case 1: piny[0]=atoi(linia.c_str()); break;
                                case 2: kasa[0]=atoi(linia.c_str()); break;
                                case 3: proby=atoi(linia.c_str()); break;
                            }
                            if(nr_linii == 3)nr_linii=0;
                        nr_linii++;
                        pomocnik++;
                        }
                        plik.close();
                        if(proby == 3){
                            cout<<"Konto zablokowane!"<<endl;
                        }else{
                        cout<<"Wpisz PIN:";
                        cin>>PIN;
                        }
                        if (PIN == piny [0]){
                            cout<<"Poprawny PIN!"<<endl;
                            Sleep(2000);
                            system("cls");
                            cout<<"CAPTCHA: ";
                            srand (time(NULL));
                            captcha = rand()%999999+100000;
                            cout<<captcha<<endl<<"Przepisz kod: ";
                            cin>>sprawdzacz;
                            if (sprawdzacz == captcha){
                                cout<<"CAPTCHA poprawna!"<<endl;
                                Sleep(2000);
                                system("cls");
                                cout<<"Stan konta: "<<kasa[0]<<" zl"<<endl;
                                cout<<"Ile pieniedzy chcesz wyplacic? ";
                                cin>>kasaa;
                                if(kasa[0]<kasaa){
                                    cout<<"Masz za malo pieniedzy!"<<endl;
                                }else{
                                kasa[0] -= kasaa;
                                plik.open("dane.txt",ios::out);
                                plik<<piny[0]<<endl<<kasa[0]<<proby<<endl;
                                cout<<"Stan konta: "<<kasa[0]<<" zl"<<endl;
                                }
                            }else{
                                cout<<"CAPTCHA niepoprawna!"<<endl;
                            }
                        }else{
                            cout<<"PIN niepoprawny!"<<endl;
                            fstream plik;
                            plik.open("dane.txt",ios::out);
                            plik<<piny[0]<<endl;
                            plik<<kasa[0]<<endl;
                            plik<<proby<<endl;
                            proby++;
                        }
                }
                break;
                case'2':{
                  fstream plik;
                    plik.open("dane.txt",ios::in);
                    string linia;
                    int nr_linii=1;
                        while (getline(plik, linia))
                        {
                            switch (nr_linii)
                            {
                                case 1: piny[0]=atoi(linia.c_str()); break;
                                case 2: kasa[0]=atoi(linia.c_str()); break;
                                case 3: proby=atoi(linia.c_str()); break;
                            }
                            if(nr_linii == 3)nr_linii=0;
                        nr_linii++;
                        pomocnik++;
                        }
                        plik.close();
                        if(proby == 3){
                            cout<<"Konto zablokowane!"<<endl;
                        }else{
                        cout<<"Wpisz PIN:";
                        cin>>PIN;
                        }
                        if (PIN == piny [0]){
                            cout<<"Poprawny PIN!"<<endl;
                            Sleep(2000);
                            system("cls");
                            cout<<"CAPTCHA: ";
                            srand (time(NULL));
                            captcha = rand()%999999+100000;
                            cout<<captcha<<endl<<"Przepisz kod: ";
                            cin>>sprawdzacz;
                            if (sprawdzacz == captcha){
                                cout<<"CAPTCHA poprawna!"<<endl;
                                Sleep(2000);
                                system("cls");
                                cout<<"Stan konta: "<<kasa[0]<<" zl"<<endl;
                                cout<<"Ile pieniedzy chcesz wplacic? ";
                                cin>>kasaa;
                                kasa[0] += kasaa;
                                plik.open("dane.txt",ios::out);
                                plik<<piny[0]<<endl<<kasa[0]<<proby<<endl;
                                cout<<"Stan konta: "<<kasa[0]<<" zl"<<endl;

                            }else{
                                cout<<"CAPTCHA niepoprawna!"<<endl;
                            }
                        }else{
                            cout<<"PIN niepoprawny!"<<endl;
                            fstream plik;
                            plik.open("dane.txt",ios::out);
                            plik<<piny[0]<<endl;
                            plik<<kasa[0]<<endl;
                            plik<<proby<<endl;
                            proby++;
                        }
                }


        }
        break;
        case'2':{
            exit(0);
        }
        break;
        default:{
            cout<<"Sprobuj jeszcze raz!"<<endl;
        }
    }
    }

}
    return 0;
}
