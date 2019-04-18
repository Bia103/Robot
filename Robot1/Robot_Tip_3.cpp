#include "Robot_Tip_3.h"
#include "Roboti.h"
#include <iostream>
using namespace std;
Robot_Tip_3::Robot_Tip_3():Roboti()
{
    //ctor
}
Robot_Tip_3::Robot_Tip_3(int t):Roboti(t)
{

}
Harta Robot_Tip_3::Abilitate(const Harta&h)
{
    int p=0,u=0,mix=INT_MAX;
    Harta t;
    int x=Coordonata_x();
    int y=Coordonata_y();
    int xh=t.Coord_xh();
    int yh=t.Coord_yh();
    for(int i=x-4; i<=x+4; i++)
    {
        for(int j=y-4; j<=y+4; j++)
        {//cout<<"Da ";
            if(i>=0&&i<15&&j>=0&&j<15)
            {int cont1 =xh-i;
            int cont2=yh-j;
            if(cont1<0)
                cont1 =0-cont1;
            if(cont2<0)
                cont2 =0-cont2;
//            cout<<cont<<" ";
            if(cont1+cont2<=mix&&t.Pozitia_x_y(i,j)!='C')
            {
                mix=cont1+cont2;
                u=i;
                p=j;
                //cout<<u<<" "<<p<<endl;
            }}
        }
    }
    Muta_Robotul(u,p);
    //if(x<=xh&&yh)
}
