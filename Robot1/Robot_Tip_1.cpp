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
Harta Robot_Tip_1::Abilitate(const Harta &h)
{
    int u=0,p=0,mi=INT_MAX,xh;
    Harta t(h);cout<<"ce?"<<endl;
    xh=t.Coord_xh();
    int x=Coordonata_x();
    int y=Coordonata_y();
    //cout<<"x="<<x<<" y="<<y<<endl;
    t.Arata_Harta();
    for(int i=x-4;i<=x+4;i++)
        {for(int j=y-4;j<=y+4;j++)
            {
                if(i>=0&&i<15&&j>=0&&j<15)
                {
                    char c=t.Pozitia_x_y(i,j);
                    //cout<<c;
                    if(c=='C')
                    { int cont =xh-i;
                        if(cont<0)
                            cont =0-cont;
                        cout<<cont<<" ";
                        if(cont<mi&&j>=p)
                        {
                            mi=cont;
                            u=i;
                            p=j;
                             //cout<<u<<" "<<p<<endl;
                        }
                    }
                }
            }
            cout<<endl;
        }
            cout<<endl;

    t.Modifica_Harta(u,p);
    return t;
}
