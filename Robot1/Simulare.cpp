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
void Simulare::Incepe_simularea(int tip,int e,int b,int c)
{
    int n;
    Harta h(b,c);
    if(tip==1)
    {
        Robot_Tip_1 r1(1);
        r=&r1;
    }
    else if(tip==2)
    {
        Robot_tip_2 r2(2);
        r=&r2;
    }
    else if(tip==3)
    {
        Robot_Tip_3 r3(3);
        r=&r3;
    }
    int xh=h.Coord_xh();
    int yh=h.Coord_yh();
    int y=r->Coordonata_y();
    int x = r->Coordonata_x();
    int u=-1,p=-1;
    int ok=0;
    h.Arata_Harta_Cu_Robot(0,0);
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
        {
            if(x > u && y > p )
            {
                if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    x--;
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2&&r->Am_itemul() )
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul() )
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul() )
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    ok=1;
                    x = r->Coordonata_x();
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
                else if(r->Tip() == 2&&r->Am_itemul()  )
                {
                    h=r->Abilitate(h,u,p);
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
                else if(r->Tip() == 2&&r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2 && r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    ok=1;
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                        r->Item(1);
                    else if(r->Tip() == 3)
                    {
                        h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());
                        h = r->Abilitate(h,xh,yh);
                    }
                    else
                    {
                        h = r->Abilitate(h,u,p);
                    }

                }
                else cout<<endl<<"Item incompatibil"<<endl;
                u = p = -1;
                scor++;
                y = r->Coordonata_y();
                x = r->Coordonata_x();
            }
            h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());
        }
        else
        {
            if(x > xh && y > yh)
            {
                if(h.Pozitia_x_y(x-1,y-1) != 'C')
                {
                    x--;
                    y--;
                    ok=1;

                }
                else if(r->Tip() == 2&&r->Am_itemul() )
                {
                    h=r->Abilitate(h,xh,yh);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul() )
                {
                    h=r->Abilitate(h,xh,yh);//
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul() )
                {
                    h=r->Abilitate(h,xh,yh);
                    y = r->Coordonata_y();
                    ok=1;
                    x = r->Coordonata_x();
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
                else if(r->Tip() == 2&&r->Am_itemul()  )
                {
                    h=r->Abilitate(h,u,p);
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
                else if(r->Tip() == 2&&r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2&&r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
                }
                else if(h.Pozitia_x_y(x+1,y+1) != 'C')
                {
                    x++;
                    y--;
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
                else if(r->Tip() == 2&&r->Am_itemul())
                {
                    h=r->Abilitate(h,xh,yh);
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
                else if(r->Tip() == 2 && r->Am_itemul())
                {
                    h=r->Abilitate(h,u,p);
                    ok=1;
                    y = r->Coordonata_y();
                    x = r->Coordonata_x();
                    ok=1;
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
    cout<<"Scor = "<<scor<<endl;
}
