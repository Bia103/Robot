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

//am_itemul=1;

    int x=Coordonata_x();
    int y=Coordonata_y();
    int q=t.Q();
    int w=t.W();
    //cout<<"x="<<x<<" y="<<y<<endl;;
   // cout<<"hxh="<<xh<<" hyh="<<yh<<endl;;
    //int xh=t.Coord_xh();
    // int yh=t.Coord_yh();
    if(x==xh && y<yh && Am_itemul() && t.Pozitia_x_y(x,y+1)=='C' && (t.Pozitia_x_y(x,y+2) == '0' || t.Pozitia_x_y(x,y+2) =='S' || t.Pozitia_x_y(x,y+2) =='I') && y+2<w)
    {

        Muta_Robotul(x,y+2);
         Item(-1);
        //return;
    }
    if(x<xh&&y<yh&&Am_itemul()&&t.Pozitia_x_y(x+1,y+1)=='C'&&(t.Pozitia_x_y(x+2,y+2)=='0'||t.Pozitia_x_y(x+2,y+2)=='S'|| t.Pozitia_x_y(x+2,y+2) =='I')&& y+2<w&& x+2<q)
    {
        //cout<<"Dapz";
        Muta_Robotul(x+2,y+2);
         Item(-1);
        //return;
    }
    if(x>xh&&y<yh&&Am_itemul()&&t.Pozitia_x_y(x-1,y+1)=='C'&&(t.Pozitia_x_y(x-2,y+2)=='0'||t.Pozitia_x_y(x-2,y+2)=='S'|| t.Pozitia_x_y(x-2,y+2) =='I') && y+2 < w& & x-2 >= 0)
    {

        Muta_Robotul(x-2,y+2);
         Item(-1);
        //return;
    }
    if(x>xh&&y==yh&&Am_itemul()&&t.Pozitia_x_y(x-1,y)=='C'&&(t.Pozitia_x_y(x-2,y) == '0' || t.Pozitia_x_y(x-2,y)=='S'|| t.Pozitia_x_y(x-2,y) =='I')&& x-2>=0)
    {

        Muta_Robotul(x-2,y);
         Item(-1);
        //return;
    }

    if(x<xh && y==yh && Am_itemul() && t.Pozitia_x_y(x+1,y)=='C' && (t.Pozitia_x_y(x+2,y)=='0' || t.Pozitia_x_y(x+2,y) == 'S'|| t.Pozitia_x_y(x+2,y) =='I')&& x+2<q)
    {

        Muta_Robotul(x+2,y);
        Item(-1);
        //return;
    }
    /**********/
    if(x==xh &&y>yh&&Am_itemul() &&t.Pozitia_x_y(x,y-1)=='C'&&(t.Pozitia_x_y(x,y-2)||t.Pozitia_x_y(x,y-2)=='S'|| t.Pozitia_x_y(x,y-2) =='I') && y-2>=0)
    {

        Muta_Robotul(x,y-2);
        Item(-1);
        //return;
    }
    if(x<xh&&y>yh&&Am_itemul() &&t.Pozitia_x_y(x+1,y-1)=='C'&&(t.Pozitia_x_y(x+2,y-2)=='0'||t.Pozitia_x_y(x+2,y-2)=='S'|| t.Pozitia_x_y(x+2,y-2) =='I') && x+2<q && y-2>=0)
    {

        Muta_Robotul(x+2,y-2);
        Item(-1);
        //return;
    }
    if(x>xh&&y>yh&&Am_itemul() &&t.Pozitia_x_y(x-1,y-1)=='C'&&(t.Pozitia_x_y(x-2,y-2)=='0'||t.Pozitia_x_y(x-2,y-2)=='S'|| t.Pozitia_x_y(x-2,y-2) =='I') && y-2>=0 && x-2>=0)
    {

        Muta_Robotul(x-2,y-2);
        Item(-1);
        //return;
    }
    //cout<<"Experiment"<<x<<" "<<y<<endl; Muta_Robotul(12,12);
    // Item(-1);
    return t;
}
