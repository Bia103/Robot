#include "Robot_tip_2.h"
#include"Harta.h"
#include"Roboti.h"
Robot_tip_2::Robot_tip_2():Roboti()
{
    am_itemul=0;
}

Robot_tip_2::Robot_tip_2(int x):Roboti(x)
{
    am_itemul=0;
}
int Robot_tip_2::Am_itemul()
{
    return am_itemul;
}
void Robot_tip_2::Item()
{
    am_itemul=1;
}
Harta Robot_tip_2::Abilitate(const Harta &h)
{
    Harta t(h);
    int x=Coordonata_x();
    int y=Coordonata_y();
    int xh=t.Coord_xh();
    if(x==xh&&am_itemul&&t.Pozitia_x_y(x,y+1)=='C'&&t.Pozitia_x_y(x,y+2))
    {
        am_itemul=0;
        Muta_Robotul(x,y+2);
        //return;
    }
    if(x<xh&&am_itemul&&t.Pozitia_x_y(x+1,y+1)=='C'&&t.Pozitia_x_y(x+2,y+2)=='0')
    {
        am_itemul=0;
        Muta_Robotul(x+2,y+2);
        //return;
    }
    if(x>xh&&am_itemul&&t.Pozitia_x_y(x-1,y-1)=='C'&&t.Pozitia_x_y(x-2,y-2)=='0')
    {
        am_itemul=0;
        Muta_Robotul(x+2,y+2);
        //return;
    }
    return t;
}
