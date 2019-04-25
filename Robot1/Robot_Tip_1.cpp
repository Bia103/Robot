#include "Robot_Tip_1.h"
#include"Harta.h"
#include<cmath>
#include <iostream>
using namespace std;
Robot_Tip_1::Robot_Tip_1():Roboti()         //constructorul fara parametri
{

}
Robot_Tip_1::Robot_Tip_1(int x):Roboti(x)   //constructorul cu paramatrii ce il trimite pe x care este tipul spre clasa de baza
{

}
Harta Robot_Tip_1::Abilitate(const Harta &h,int xh,int yh) // abilitatea robotului 1
{
    int u=0,p=0,mix=INT_MAX;
    /*
    u si p reprezinta pozitia capcanei care va fi stearsa
    mix trebuie sa aiba la final o valoarea cat mai mica ce va indica apropierea lui u si p de robot
    */
    Harta t(h);                                             // se construieste o noua harta egala cu prima
    int x=Coordonata_x();                                   // se initializeaza x care va avea coordonata x a robotului
    int y=Coordonata_y();                                   // se initializeaza y care va avea coordonata y a robotului
    int q=t.Q();                                            // se initializeaza q cu inaltimea hartii
    int w=t.W();                                            // se initializeaza w cu latimea hartii
    for(int i=x-4;i<=x+4;i++)                               // de la linai 15 pana la 27 se parcurge harta ce inconjoara 4 spatii robotul
        {
            for(int j=y-4;j<=y+4;j++)
            {
                if(i>=0 && i<q && j>=0 && j<w)              // se verifica daca nu s-a iesit din harta
                {
                    char c=t.Pozitia_x_y(i,j);              // variabila c primeste valoarea obiectului din harta de pe pozitia i si j
                    if(c=='C')                              // se verifica c este capcana
                    {
                        int cont1 = x - i;                  // se clculeaza apropierea fata de robot in inaltime
                        int cont2 = y - j;                  // se clculeaza apropierea fata de robot in latime
                        if(cont1 < 0)                       // daca variabila este mai mica decat 0 se face modul
                            cont1 = 0 - cont1;
                        if(cont2 < 0)                       // daca variabila este mai mica decat 0 se face modul
                            cont2 = 0 - cont2;
                        if(cont1 + cont2 < mix)             // daca cele doua variabile in care se afla apropierea adunate sunt mai mici decat
                        {                                   // maximul de pana acum atunci inseamna ca una dintre capcanele pe care suntem acum este mai apropiata de robot
                            /*
                            Spre exemplu avem
                            0 0 0 0 0 0 0 0 0
                            0 0 0 C 0 0 0 0 0
                            0 0 0 0 0 C 0 0 0
                            0 0 0 0 R 0 0 0 0
                            0 0 0 0 0 0 0 0 0
                            0 0 0 0 0 0 0 0 0
                            0 0 0 0 0 0 0 0 0
                            0 0 0 0 0 0 0 0 0
                            Capcana din  stanga(mai indepartata) va avea o suma cont1 + cont2 mai mare (2+1=3) decat dea din dreapta (1+1=2),
                            astfel in concluzie capcana din dreapta este mai aprope de robot.

                            */
                            mix=cont1+cont2;            // mix retine valoarea celei mai mici suma
                            u=i;                        // se retin pozitiile capcanei
                            p=j;
                        }
                    }
                }
            }
        }
    t.Modifica_Harta(u,p,'0');                          //capcana este stearsa
    return t;
}
Robot_Tip_1::~Robot_Tip_1()                             //destructorul
{
    Set_tot_zero();                                     // toate componentele clasei devin 0
}
Robot_Tip_1::Robot_Tip_1(Robot_Tip_1& b)                // constructorul de copiere
{
    Muta_Robotul(b.Coordonata_x(),b.Coordonata_y());    // se muta robotul in functie de al doilea
    Modifica_Tip(b.Tip());                              // se modifica tipul primului robot in functie de tipul robotului b
    Item(b.Am_itemul());                                // am_itemul primeste am_itemul lui b
}
