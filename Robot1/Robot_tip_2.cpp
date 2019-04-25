#include "Robot_tip_2.h"
#include"Harta.h"
#include"Roboti.h"
#include<iostream>
using namespace std;
Robot_tip_2::Robot_tip_2():Roboti()
{

}
Robot_tip_2::Robot_tip_2(int x):Roboti(x)
{

}
Harta Robot_tip_2::Abilitate(const Harta &h,int xh,int yh)
{
    Harta t(h);
    int x=Coordonata_x();
    int y=Coordonata_y();
    int q=t.Q();
    int w=t.W();
    v=1;
    if(x==xh && y<yh && Am_itemul() && t.Pozitia_x_y(x,y+1)=='C' && (t.Pozitia_x_y(x,y+2) == '0' || t.Pozitia_x_y(x,y+2) =='S' || t.Pozitia_x_y(x,y+2) =='I') && y+2<w)
    {
        Muta_Robotul(x,y+2);
         Item(-1);v=0;
    }
    if(x<xh&&y<yh&&Am_itemul()&&t.Pozitia_x_y(x+1,y+1)=='C'&&(t.Pozitia_x_y(x+2,y+2)=='0'||t.Pozitia_x_y(x+2,y+2)=='S'|| t.Pozitia_x_y(x+2,y+2) =='I')&& y+2<w&& x+2<q)
    {
        Muta_Robotul(x+2,y+2);
         Item(-1);v=0;
    }
    if(x>xh&&y<yh&&Am_itemul()&&t.Pozitia_x_y(x-1,y+1)=='C'&&(t.Pozitia_x_y(x-2,y+2)=='0'||t.Pozitia_x_y(x-2,y+2)=='S'|| t.Pozitia_x_y(x-2,y+2) =='I') && y+2 < w& & x-2 >= 0)
    {
        Muta_Robotul(x-2,y+2);
         Item(-1);v=0;
    }
    if(x>xh&&y==yh&&Am_itemul()&&t.Pozitia_x_y(x-1,y)=='C'&&(t.Pozitia_x_y(x-2,y) == '0' || t.Pozitia_x_y(x-2,y)=='S'|| t.Pozitia_x_y(x-2,y) =='I')&& x-2>=0)
    {
        Muta_Robotul(x-2,y);
        Item(-1);v=0;
    }
    if(x<xh && y==yh && Am_itemul() && t.Pozitia_x_y(x+1,y)=='C' && (t.Pozitia_x_y(x+2,y)=='0' || t.Pozitia_x_y(x+2,y) == 'S'|| t.Pozitia_x_y(x+2,y) =='I')&& x+2<q)
    {
        Muta_Robotul(x+2,y);
        Item(-1);v=0;
    }
    if(x==xh &&y>yh&&Am_itemul() &&t.Pozitia_x_y(x,y-1)=='C'&&(t.Pozitia_x_y(x,y-2)||t.Pozitia_x_y(x,y-2)=='S'|| t.Pozitia_x_y(x,y-2) =='I') && y-2>=0)
    {
        Muta_Robotul(x,y-2);
        Item(-1);v=0;
    }
    if(x<xh&&y>yh&&Am_itemul() &&t.Pozitia_x_y(x+1,y-1)=='C'&&(t.Pozitia_x_y(x+2,y-2)=='0'||t.Pozitia_x_y(x+2,y-2)=='S'|| t.Pozitia_x_y(x+2,y-2) =='I') && x+2<q && y-2>=0)
    {
        Muta_Robotul(x+2,y-2);
        Item(-1);v=0;
    }
    if(x > xh && y > yh && Am_itemul() &&t.Pozitia_x_y(x-1,y-1)=='C'&&(t.Pozitia_x_y(x-2,y-2)=='0'||t.Pozitia_x_y(x-2,y-2)=='S'|| t.Pozitia_x_y(x-2,y-2) =='I') && y-2>=0 && x-2>=0)
    {
        Muta_Robotul(x-2,y-2);
        Item(-1);v=0;
    }
    return t;
}
Robot_tip_2::~Robot_tip_2()
{
    Set_tot_zero();
}
Robot_tip_2::Robot_tip_2(Robot_tip_2& b)
{
    Muta_Robotul(b.Coordonata_x(),b.Coordonata_y());
    Modifica_Tip(b.Tip());
    Item(b.Am_itemul());
}
int Robot_tip_2::V()
{
    return v;
}
