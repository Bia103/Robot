#include "Roboti.h"

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
Harta Roboti::Abilitate(const Harta &h)
{
    return h;
}
void Roboti::Muta_Robotul(int x,int y)
{
    this->y=y;
    this->x=x;
}
