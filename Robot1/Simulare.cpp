#include "Simulare.h"
#include "Robot_Tip_1.h"
#include "Robot_tip_2.h"
#include "Robot_Tip_3.h"
#include <iostream>
#include <random>
using namespace std;
Simulare::Simulare()
{
    scor=0;
}
Simulare::Simulare(Simulare& b)
{
    r=b.r;
    scor=b.scor;
}
Simulare Simulare:: operator=(const Simulare &op2)
{
    scor=op2.scor;
    r=op2.r;
    return *this;
}
void Simulare::Incepe_simularea(int tip,int e,int b,int c)
{
    int n;
    Robot_Tip_1 r1(1);
    Robot_tip_2 r2(2);
    Robot_Tip_3 r3(3);
    Harta h(b,c);
    if(tip==1)
    {

        r=&r1;
    }
    else if(tip==2)
    {

        r=&r2;
    }
    else if(tip==3)
    {

        r=&r3;
    }
    cout<<tip<<" ";
    cout<<r->Tip();
    int xh=h.Coord_xh();
    int yh=h.Coord_yh();
    int y=r->Coordonata_y();
    int x = r->Coordonata_x();
    int u=-1,p=-1;
    int ok=0;
    h.Arata_Harta_Cu_Robot(0,0);
    cout<<endl;
    while(x!=xh || y!=yh)
    {
        ok=0;
        int mx=999;
        if(u==-1)
            for(int i = x-4 ; i <= x+4; i++)
            {
                for(int j=y-4; j<=y+4; j++)
                {
                    if(i>=0 && i<b && j>=0 && j<c)
                    {

                        int cont1 =x-i;
                        int cont2=y-j;
                        if(cont1<0)
                            cont1 =0-cont1;
                        if(cont2<0)
                            cont2 =0-cont2;

                        char c=h.Pozitia_x_y(i,j);
                        if(c == 'I' && cont1+cont2 <= mx)
                        {
                            mx=cont1+cont2;
                            u=i;
                            p=j;
                        }
                    }
                }
            }
        if(u!=-1)
        {   cout<<endl;
            if(x > u && y > p )
            {
                if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    x--;
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul() >0 )
                {
                    h=r->Abilitate(h,u,p);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x,y-1) != 'C')
                        {
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y) != 'C')
                        {
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x,y-1) != 'C')
                {
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y) != 'C')
                {
                    x--;
                    ok=1;
                }
            }
            else if(x < u&& y < p  )
            {
                if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    x++;
                    y++;
                    ok=1;
                }
                else if(r->Tip() == 2&& r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,u,p);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y) != 'C')
                        {
                            x++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x,y+1) != 'C')
                        {
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y) != 'C')
                {
                    x++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x,y+1) != 'C')
                {
                    y++;
                    ok=1;
                }
            }
            else if(x > u&& y < p )
            {
                if(h.Pozitia_x_y(x-1,y+1) != 'C')
                {
                    x--;
                    y++;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul() >0)
                {
                    h=r->Abilitate(h,u,p);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x-1,y) != 'C')
                        {
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x,y+1) != 'C')
                        {
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    ok=1;
                    x = r->Coordonata_x();

                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x-1,y) != 'C')
                {
                    x--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x,y+1) != 'C')
                {
                    y++;
                    ok=1;
                }
            }
            else if(x < u && y > p )
            {
                if(h.Pozitia_x_y(x+1,y-1) != 'C')
                {
                    x++;
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0  )
                {
                    h=r->Abilitate(h,u,p);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y) != 'C')
                        {
                            x++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x,y-1) != 'C')
                        {
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    ok=1;
                    x = r->Coordonata_x();
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y) != 'C')
                {
                    x++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x,y-1) != 'C')
                {
                    y--;
                    ok=1;
                }

            }
            else if(x == u&& y > p)
            {
                if(h.Pozitia_x_y(x,y-1) != 'C')
                {
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,u,p);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y-1) != 'C')
                        {
                            x++;
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                        {
                            y--;
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y-1) != 'C')
                {
                    x++;
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    y--;
                    x--;
                    ok=1;
                }

            }
            else if(x == u&& y < p )
            {
                if(h.Pozitia_x_y(x,y+1) != 'C')
                {
                    y++;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,u,p);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y+1) != 'C')
                        {
                            x++;
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y+1) != 'C')
                        {
                            y++;
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    x++;
                    y++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y+1) != 'C')
                {
                    y++;
                    x--;
                    ok=1;
                }
            }
            else if(x < u&& y == p )
            {
                if(h.Pozitia_x_y(x+1,y) != 'C')
                {
                    x++;
                    ok = 1;
                }
                else if(r->Tip() == 2 && r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,u,p);
                    ok=1;
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y-1) != 'C')
                        {
                            x++;
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                        {
                            y++;
                            x++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    cout<<endl<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y-1) != 'C')
                {
                    x++;
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    y++;
                    x++;
                    ok=1;
                }
            }
            else if(x > u&& y == p )
            {

                if(h.Pozitia_x_y(x-1,y) != 'C')
                {
                    x--;
                    ok=1;
                }
                else if(r->Tip() == 2 && r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,u,p);
                    ok=1;
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x-1,y+1) != 'C')
                        {
                            x--;
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                        {
                            y--;
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();

                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x-1,y+1) != 'C')
                {
                    x--;
                    y++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    y--;
                    x--;
                    ok=1;
                }
            }
            else if(u==x&&p==y)
                ok=1;
            r->Muta_Robotul(x,y);
            if(h.Pozitia_x_y(x,y)=='I')
            {
                n=1+rand()%3;
                h.Modifica_Harta(x,y,'0');
                Item1 i1;
                Item2 i2;
                Item3 i3;
                if(n==1)
                    i1.Set_Valid();
                else if(n==2)
                    i2.Set_Valid();
                else
                    i3.Set_Valid();
                if((i3.Valid() && r->Tip() == 3) || (i2.Valid() && r->Tip() == 2) || (i1.Valid() && r->Tip() == 1))
                {
                    cout<<endl<<"Item compatibil"<<endl;
                    if(r->Tip() == 2)
                    {
                        r->Item(1);
                        cout<<"Se addauga in stocul robotului inca o utilizare "<<endl;
                    }
                    else if(r->Tip() == 3)
                    {
                        h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());
                        h = r->Abilitate(h,xh,yh);
                        cout<<"Deoarece robotul este compatibil cu itemul acesta se teleporteaza pe pozitiile:"<<r->Coordonata_x()<<" "<<r->Coordonata_y()<<endl;
                    }
                    else
                    {
                        h = r->Abilitate(h,u,p);
                        cout<<"Deoarece robotul este compatibil cu itemul se sterge o capcana din perimetrul acestuia."<<endl;
                    }

                }
                else
                    cout<<endl<<"Item incompatibil"<<endl;
                u = p = -1;
                scor++;
                y = r->Coordonata_y();
                x = r->Coordonata_x();
            }
            h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());
            cout<<endl<<"Se muta robotul pe pozitia: "<<x<<" "<<y;
        }
        else
        {
            cout<<endl;
            if(x > xh && y > yh)
            {
                if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    x--;
                    y--;
                    ok=1;

                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,xh,yh);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x,y-1) != 'C')
                        {
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y) != 'C')
                        {
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x,y-1) != 'C')
                {
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y) != 'C')
                {
                    x--;
                    ok=1;
                }

            }
            else if(x < xh&& y < yh )
            {
                if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    x++;
                    y++;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0 )
                {
                    h=r->Abilitate(h,xh,yh);//

                    ok=1;
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y) != 'C')
                        {
                            x++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x,y+1) != 'C')
                        {
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y) != 'C')
                {
                    x++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x,y+1) != 'C')
                {
                    y++;
                    ok=1;
                }

            }
            else if(x > xh&& y < yh)
            {
                if(h.Pozitia_x_y(x-1,y+1) != 'C')
                {
                    x--;
                    y++;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0 )
                {
                    h=r->Abilitate(h,xh,yh);

                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x-1,y) != 'C')
                        {
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x,y+1) != 'C')
                        {
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                     y = r->Coordonata_y();
                    ok=1;
                    x = r->Coordonata_x();
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x-1,y) != 'C')
                {
                    x--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x,y+1) != 'C')
                {
                    y++;
                    ok=1;
                }
            }
            else if(x < xh&& y > yh )
            {
                if(h.Pozitia_x_y(x+1,y-1) != 'C')
                {
                    x++;
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,xh,yh);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                       {

                        if(h.Pozitia_x_y(x+1,y) != 'C')
                        {
                            x++;
                            ok=1;
                            r->Muta_Robotul(x,y);
                        }
                        else if(h.Pozitia_x_y(x,y-1) != 'C')
                        {
                            y--;
                            ok=1;
                            r->Muta_Robotul(x,y);
                        }
                        }
                    y = r->Coordonata_y();
                    ok=1;
                    x = r->Coordonata_x();
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y) != 'C')
                {
                    x++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x,y-1) != 'C')
                {
                    y--;
                    ok=1;
                }
            }
            else if(x == xh&& y > yh )
            {

                if(h.Pozitia_x_y(x,y-1) != 'C')
                {
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {

                    h=r->Abilitate(h,xh,yh);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y-1) != 'C')
                        {
                            x++;
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                        {
                            y--;
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<endl<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y-1) != 'C')
                {
                    x++;
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    y--;
                    x--;
                    ok=1;
                }
            }
            else if(x == xh&& y < yh )
            {
                if(h.Pozitia_x_y(x,y+1) != 'C')
                {
                    y++;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,xh,yh);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y+1) != 'C')
                        {
                            x++;
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y+1) != 'C')
                        {
                            y++;
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    x++;
                    y++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y+1) != 'C')
                {
                    y++;
                    x--;
                    ok=1;
                }
            }
            else if(x < xh&& y == yh )
            {
                if(h.Pozitia_x_y(x+1,y) != 'C')
                {
                    x++;
                    ok = 1;
                }
                else if(r->Tip() == 2&&r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,xh,yh);
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x+1,y-1) != 'C')
                        {//
                            x++;
                            y--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                        {
                            y++;
                            x++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x+1,y-1) != 'C')
                {
                    x++;
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    y++;
                    x++;
                    ok=1;
                }
            }
            else if(x > xh&& y == yh )
            {
                if(h.Pozitia_x_y(x-1,y) != 'C')
                {
                    x--;
                    ok=1;
                }
                else if(r->Tip() == 2 && r->Am_itemul()>0)
                {
                    h=r->Abilitate(h,u,p);

                    ok=1;
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())
                        if(h.Pozitia_x_y(x-1,y+1) != 'C')
                        {
                            x--;
                            y++;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                        {
                            y--;
                            x--;r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x-1,y+1) != 'C')
                {
                    x--;
                    y++;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    y--;
                    x--;
                    ok=1;
                }
            }
            r->Muta_Robotul(x,y);
            h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());
            cout<<endl<<"Se muta robotul pe pozitia: "<<x<<" "<<y;
        }
        if(e)
        {
            cout<<"Apasati o tasta, iar apoi enter daca sunteti gata sa treceti la pasul urmator: ";
            char c;
            cin>>c;
        }
        if(ok == 0)
            break;
    }
    if(ok==0)
        cout<<endl<<"Robotul nu a mai putut inainta"<<endl;
    cout<<"\nScor = "<<scor<<endl;
}
Simulare::~Simulare()
{
    scor=0;
    delete r;
}
