#include "Robot_Tip_1.h"
#include"Harta.h"
#include<cmath>
#include <iostream>
using namespace std;
Robot_Tip_1::Robot_Tip_1():Roboti()
{

}
Robot_Tip_1::Robot_Tip_1(int x):Roboti(x)
{

}
Harta Robot_Tip_1::Abilitate(const Harta &h,int xh,int yh)
{
    int u=0,p=0,mix=INT_MAX,miy=INT_MAX;
    Harta t(h);
    int x=Coordonata_x();
    int y=Coordonata_y();
    int q=t.Q();
    int w=t.W();
    for(int i=x-4;i<=x+4;i++)
        {for(int j=y-4;j<=y+4;j++)
            {
                if(i>=0 && i<q && j>=0 && j<w)
                {
                    char c=t.Pozitia_x_y(i,j);
                    if(c=='C')
                    { int cont1 =x-i;
                    int cont2=y-j;
                        if(cont1<0)
                            cont1 =0-cont1;
                        if(cont2<0)
                            cont2 =0-cont2;
                        if(cont1+cont2<mix)
                        {
                            mix=cont1+cont2;
                            u=i;
                            p=j;
                        }
                    }
                }
            }
        }
    t.Modifica_Harta(u,p,'0');
    return t;
}
Robot_Tip_1::~Robot_Tip_1()
{
    Set_tot_zero();
}
Robot_Tip_1::Robot_Tip_1(Robot_Tip_1& b)
{
    Muta_Robotul(b.Coordonata_x(),b.Coordonata_y());
    Modifica_Tip(b.Tip());
    Item(b.Am_itemul());
}
