#ifndef HARTA_H
#define HARTA_H
#include<iostream>
using namespace std;

class Harta
{
    char **a;
    int xh,yh;
    int q,w;
    /*
    a = tabloul bidimensional ce contine harta
    xh= coordonata x a stopului
    yh=coordonata y a stopului
    q=inaltimea hartii
    w=latimea hartii
    */
    public:
        Harta(const Harta &b);                  //constructorul de copiere
        Harta();                                //constructorul fara parametri
        Harta(int i,int j);                     //constructorul cu doi parametrii
        Arata_Harta_Cu_Robot(int,int);          //functie ce arata harta cu robotul
        Modifica_Harta(int,int,char);           //functie ce modifica harta
        char Pozitia_x_y(int,int);              //functie ce extrage caracterul de pe pozitia x si y
        int Coord_xh();                         //functie ce extrage coordonata x a stopului
        int Coord_yh();                         //functie ce extrage coordonata x a stopului
        int Q();                                //funtie ce extrage inaltimea hartii
        int W();                                //functie ce extrage latimea hartii
        Harta operator =(const Harta& op2);     //supraincarcarea operatorului = pentru atribuirea unui obiect altui obiect
        friend ostream& operator<<(ostream& os, const Harta& dt); //functie de afisare a hartii
        ~Harta();                               //destructorul hartii
};

#endif // HARTA_H
