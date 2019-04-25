#include "Roboti.h"
#include <iostream>
using namespace std;
Roboti::Roboti()
{
    x=0;
    y=0;
    tip=0;
}
Roboti::Roboti(int tip)
{
    x=0;
    y=0;
    this->tip=tip;
}
int Roboti::Coordonata_x()
{
    return x;
}
int Roboti::Coordonata_y()
{
    return y;
}
int Roboti::Tip()
{
    return tip;
}
Harta Roboti::Abilitate(const Harta &h,int xh,int yh)
{
    return h;
}
void Roboti::Muta_Robotul(int x,int y)
{
    this->y=y;
    this->x=x;
}
void Roboti::Modifica_Tip(int t)
{
    tip=t;
}
int Roboti::Am_itemul()
{
    return am_itemul;
}
void Roboti::Item(int x)
{
    am_itemul=am_itemul+x;
}
void Roboti::Set_tot_zero()
{
    x=y=tip=am_itemul=0;
}
Roboti::~Roboti()
{
    x=y=tip=am_itemul=0;
}
