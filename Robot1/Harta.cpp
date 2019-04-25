#include "Harta.h"
#include <random>
#include<iostream>
using namespace std;
Harta::Harta()
{
    a=new char*[15];                //se aloca spatiu pentru linii
    for(int i = 0; i < 15; ++i)
        a[i] = new char[15];        // se aloca spatiu pentru coloane
    int n=rand()%120;               // se ia o valuare random ce ilustreaza numarul de capcane
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            a[i][j]='0';            // harta se initializeaza cu 0, aceastea reprezentand spatiile libere
    for(int i=0; i<n ;i++)          // sunt puse capcanele in numar de n(ales random)
    {
        int xh = rand() % 15;       // se initializeaza variabila xh pe care o vom folosi pentru a alege coordonata x pentru capcana
        int yh = rand()%15;         // se initializeaza variabila yh pe care o vom folosi pentru a alege coordonata y pentru capcana
        a[xh][yh] = 'C';            // harta ia pe pozitia xh yh valoarea C deoarece in acel loc este pusa o capcana
    }
    n=rand()%60+1;                  // in variabila n se pune o valoare random de iteme
    for(int i=0;i<n;i++)            // pentru iteme se procedeaza la fel ca in cazul capcanelor
    {
        int xh = rand() % 15;
        int yh=rand() % 15;
        a[xh][yh] = 'I';
    }
    n=rand()%3+10;                  // se gaseste o valoare random pentru S care va fi stopul (destinatia) astfel incat coodonata x(linia) a acestuia
                                    // sa o plaseze partea de jos a hartii
    int z=rand()%3+10;              // se procedeaza la fel pentru y(coloana), astfel incat aceasta sa fie in jumatatea dreapta a hartii
    a[n][z]='S';                    // se scrie pe harta S in locul destinat
    xh=n;                           // inaltimii lui S i se atribuie n care este coord x a acestuia
    yh=z;                           // latimii lui S i se atribuie n care este coord y a acestuia
    a[0][0]='0';                    // pozitiei din care incepe robotul sa inainteze i se atribuie 0 ca sa nu existe probleme inca din prima
    q=15;                           // inaltimea devine 15 care este default in cazul in care nu exista parametrii
    w=15;                           // latimea devine 15 care este default in cazul in care nu exista parametrii
}
Harta::Harta(int b, int c)          //acelasi lucru ca la constructorul fara parametrii, numai ca in loc de 15 si 15 se lucreaza cu valorile date de catre utilizator
{
    q=b;
    w=c;
    a=new char*[q];
    for(int i = 0; i < q; ++i)
        a[i] = new char[w];
    int n=rand()%200;
    for(int i=0;i<q;i++)
        for(int j=0;j<w;j++)
            a[i][j]='0';
    for(int i=0; i<n ; i++)
    {
        int xh = rand()%q;
        int yh = rand()%w;
        if(xh != w-1 && yh != 13 && yh !=0 )
            a[xh][yh]='C';
    }
    n=rand()%60+1;
    for(int i=0;i<n;i++)
    {
        int xh=rand()%q;
        int yh=rand()%w;
        a[xh][yh]='I';
    }
    n=rand()%(q/2)-1+q/2;
    int z=rand()%(w/2)-1+w/2;
    a[n][z]='S';
    xh=n;
    yh=z;
    a[0][0]='0';
}
Harta::Harta(const Harta &b)
{
    q=b.q;
    w=b.w;
    a=new char*[q];
    for(int i = 0; i < q; ++i)
        a[i] = new char[w];
    for(int i=0;i<q;i++)
        for(int j=0;j<w;j++)
            a[i][j]=b.a[i][j];
    xh=b.xh;
    yh=b.yh;
}
Harta::Arata_Harta_Cu_Robot(int x,int y)    //se afiseaza harta cu robotul
{
    cout<<endl;
    for(int i=0;i<=w+1;i++)                 //se construieste o bordura(cea de sus) a hartii formata din X-uri pentru a contribui la estetica acesteia
        cout<<"X ";
    cout<<endl;
    for(int i=0;i<q;i++)
    {
         cout<<"X ";                        //bordura din stanga
        for(int j=0;j<w;j++)
            if(i==x&&y==j)                  //daca s-a ajuns la coordonate egale cu cele ale robotului se afiseaza R(pozitia acestuia)
                cout<<"R ";
            else if(a[i][j]=='0')           //in cazul in care pozitia de pe harta contine 0, inseamna ca spatiul e liber, asa ca se afiseaza " "
               cout<<"  ";
            else cout<<a[i][j]<<" ";        // altfel se afiseaza ce exte in casuta i si j
        cout<<"X ";                         // bordura din dreapta
        cout<<endl;
    }
    for(int i=0;i<=w+1;i++)
        cout<<"X ";
    cout<<endl;
}
Harta::Modifica_Harta(int x,int y,char c)   //metoda ce modifica un caracter din harta
{
    a[x][y]=c;                              // modificarea unui caracter aflat pe o anumita pozitie
}
char Harta::Pozitia_x_y(int x,int y)        //metoda ce returneaza caracterul de pe o anumita pozitie
{
    return a[x][y];                         //returnarea caracterului
}
int Harta::Coord_xh()                       // metoda ce returneaza coordonata x
{
    return xh;                              //returnarea coordonatei x
}
int Harta::Coord_yh()                       // metoda ce returneaza coordonata y
{
    return yh;                              // returnarea coordonatei y
}
Harta Harta:: operator=(const Harta &op2)   //supraincarcarea operatorului =
{
    char **u=new char*[op2.q];              // de la linia 122 pana la 124 se aloca dinamic o matrice
    for(int i = 0; i < op2.q; ++i)
        u[i] = new char[op2.w];
     for(int i = 0; i < op2.q; ++i) {       //de la linia 125 pana la 128 se dezaloca tabloul precedent
        delete[] a[i];
    }
    delete[] a;
    for(int i=0;i<op2.q;i++)
        for(int j=0;j<op2.w;j++)
            u[i][j]=op2.a[i][j];            // in tabloul u se pun valorile din a
    q=op2.q;                                // inaltimea orimului tablou devine egala cu cea a celui de-al doilea
    w=op2.w;                                // latimea orimului tablou devine egala cu cea a celui de-al doilea
    a=u;                                    // a a pointeaza spre u
    xh=op2.xh;                              //  se copiaza inaltimea S a op2 in xh-ul obiectului
    yh=op2.yh;                              //  se copiaza latimea S a op2 in yh-ul obiectului
    return *this;
}
int Harta::Q()                              // metoda ce returneaza inaltimea hartii
{
    return q;                               // inaltimea este returnata
}
int Harta::W()                              // metoda ce returneaza latimea hartii
{
    return w;                               // latimea este returnata
}
Harta::~Harta()                             // este distrusa harta
{
    for(int i = 0; i < q; ++i)              //se dezaloca liniile
        delete[] a[i];
    delete []a;                             // dezalocarea finala
    q=w=xh=yh=0;                            // toate variabilele devin 0
}
ostream& operator<<(ostream& os, const Harta& dt) // suprainacarcarea afisarii
{
    for(int i=0;i<dt.q;i++)                 //se parcurge linia
    {
        for(int j=0;j<dt.w;j++)             //se parcurge coloana
            cout<<dt.a[i][j]<<" ";          // se afiseaza ce se afla in pozitia i j
        cout<<endl;                         // se lasa spatiu intre linii
    }
    cout<<endl;
    return os;
}
