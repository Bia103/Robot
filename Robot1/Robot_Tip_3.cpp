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
Harta Robot_Tip_3::Abilitate(const Harta&h,int xh,int yh)
{
    int p=0,u=0,mix=INT_MAX;
    Harta t(h);
    int x=Coordonata_x();
    int y=Coordonata_y();
    int q=t.Q();
    int w=t.W();
    for(int i=x-4; i<=x+4; i++)
    {
        for(int j=y-4; j<=y+4; j++)
        {
            if(i >=0 && i< q && j >= 0 && j < w )
            {
                int cont1 =xh-i;
                int cont2=yh-j;
                if(cont1<0)
                    cont1 =0-cont1;
                if(cont2<0)
                    cont2 =0-cont2;
                if(cont1 + cont2 <= mix && t.Pozitia_x_y(i,j) != 'C')
                {
                    mix=cont1+cont2;
                    u=i;
                    p=j;

                }
            }
        }
    }
    Muta_Robotul(u,p);//cout<<" magieee";
    // cout<<u<<" "<<p<<endl;
    //cout<<"u="<<u<<" p="<<p<<endl;;
    return t;
    //if(x<=xh&&yh)
}
