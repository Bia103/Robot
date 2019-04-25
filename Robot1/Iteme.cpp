#include "Iteme.h"

Iteme::Iteme()
{
    //tip=0;
}
Iteme::Iteme(int x)
{
//    tip=x;
}
int Iteme::Get_Tip()
{
//    return tip;
}
int Iteme::Valid()
{
    return 0;
}

Item1::Item1()
{
    tip=1;valid=0;
}
Item1::Item1(int x)
{
    tip=x;
}
int Item1::Get_Tip()
{
    return tip;
}
int Item1::Valid()
{
    return valid;
}
void Item1::Set_Valid()
{
    valid=1;
}
Item1::~Item1()
{
    tip=valid=0;
}

Item2::Item2()
{
    tip=2;valid=0;
}
Item2::Item2(int x)
{
    tip=x;
}
int Item2::Get_Tip()
{
    return tip;
}
int Item2::Valid()
{
    return valid;
}
void Item2::Set_Valid()
{
    valid=1;
}
Item2::~Item2()
{
    tip=valid=0;
}

Item3::Item3()
{
    tip=3;valid=0;
}
Item3::Item3(int x)
{
    tip=x;
}
int Item3::Get_Tip()
{
    return tip;
}
int Item3::Valid()
{
    return valid;
}
void Item3::Set_Valid()
{
    valid=1;
}
Item3::~Item3()
{
    tip=valid=0;
}
