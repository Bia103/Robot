#include "Roboti.h"
#include <iostream>
using namespace std;
Roboti::Roboti()            //constructorul fara parametri
{
    x=0;                    //robotul incepe din coltul ce se afla in stanga sus, asa ca initial coordonatele lui vor fi 0
    y=0;
    tip=0;                  // deoarece nu se specifica tipul, acesta va fi considerat 0 (adica nu are vreo abilitate)
}
Roboti::Roboti(int tip)     //constructorul fara parametri
{
    x=0;                    //robotul incepe din coltul ce se afla in stanga sus, asa ca initial coordonatele lui vor fi 0
    y=0;
    this->tip=tip;          //tipul este initializat cu cel dorit de utilizator
}
int Roboti::Coordonata_x()  //metoda ce intoarce pozitia x pe care se afla robotul
{
    return x;               // returnarea lui x
}
int Roboti::Coordonata_y()  //metoda ce intoarce pozitia y pe care se afla robotul
{
    return y;               // returnarea lui y
}
int Roboti::Tip()           //metoda ce intoarce tipul robotului
{
    return tip;             // returnarea tipului
}
Harta Roboti::Abilitate(const Harta &h,int xh,int yh) // metoda ce returneaza harta cu modificarile facute pe ea in functie de robot
{
    return h;               // returnarea hartii
}
void Roboti::Muta_Robotul(int x,int y)     // metoda ce muta coordonatele robotului
{
    this->y = y;                           //mutarea lui y(latimea)
    this->x = x;                           //mutarea lui x(inaltimea)
}
void Roboti::Modifica_Tip(int t)           // metoda ce schimba tipul robotului
{
    tip = t;                               //schimbarea tipului
}
int Roboti::Am_itemul()                    // metoda ce returneaza voaloarea aflata in am_itemul
{
    return am_itemul;                      // returnarea valorii itemului
}
void Roboti::Item(int x)                   //metoda ce schimba valoarea din am_item
{
    am_itemul=am_itemul+x;                 // schimba valoarii din am_item
}
void Roboti::Set_tot_zero()                // metoda ce le atribuie tuturor variabilelor valoarea 0
{
    x=y=tip=am_itemul=0;                   // toate variabiele devin 0
}
Roboti::~Roboti()                          //destructor
{
    x=y=tip=am_itemul=0;                   // toate variabiele devin 0
}
