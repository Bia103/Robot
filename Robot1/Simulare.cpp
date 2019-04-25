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
    int n;                          // variabila folosita mai tarziu pentru obtinerea unui numar random
    Robot_Tip_1 r1(1);              //se concep cele 3 tipuri de roboti de la linia 26 pana la 28
    Robot_tip_2 r2(2);
    Robot_Tip_3 r3(3);
    Harta h(b,c);                   // se construieste harta cu dimensiunile ei
    if(tip == 1)                    // upcasting in functie de tipul robotului
    {
        r = &r1;
    }
    else if(tip == 2)
    {
        r =& r2;
    }
    else if(tip == 3)
    {
        r = &r3;
    }
    int xh = h.Coord_xh();        //se extrage inaltimea lui S
    int yh = h.Coord_yh();        //se extrage latimea lui S
    int y = r->Coordonata_y();
    int x = r->Coordonata_x();
    int u=-1,p=-1;                // in caz ca x are un item in raza lui u si p vor deveni coordonatele acestuia
    int ok=0;                     // ok indica daca robotul s-a blocat pe harta sau nu
    h.Arata_Harta_Cu_Robot(0,0);
    cout<<endl;
    while(x!=xh || y!=yh)                           // atata timp cat nu am ajuns la S se executa bucata de cod
    {
        ok=0;
        int mx=999;                                 // daca robotul nu are nici un item depistat in raza de actiune atunci se porneste scanarea
        if(u==-1)                                   // patratului de 4 blocuri ce il inconjoara
            for(int i = x-4 ; i <= x+4; i++)        // cautarea se face la fel ca in abilitatea robotului de tip 1
            {
                for(int j=y-4; j <= y+4; j++)
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
        if(u!=-1)                                   // daca s-a gasit un potential item in perimetrul robotului, atunci acesta isi schimba directia inaintand spre casuta respectiva
        {   cout<<endl;
            if(x > u && y > p )                     // daca coordonatele la care se afla robotul sunt mai mari decat cele ale itemului
            {
                if(h.Pozitia_x_y(x-1,y-1) != 'C')   // daca drumul optim spre item nu contine o capcana atunci robotul se indreapta in acea directie
                {
                    x--;
                    y--;
                    ok=1;
                }
                else if(r->Tip() == 2 && r->Am_itemul() > 0)            // daca robotul este de tip 2 si are itemul, acesta incearca o saritura peste capcana
                {
                    h=r->Abilitate(h,u,p);                              // se incearca saritura
                    if(y == r->Coordonata_y()&&x==r->Coordonata_x())    // daca coordonatele initiale ale coincid cu cele de dupa utilizarea abilitatii, inseamna ca robotul nu a reusit sa sara
                        if(h.Pozitia_x_y(x,y-1) != 'C')                 // robotul incearca sa faca un ocol
                        {
                            y--;
                            r->Muta_Robotul(x,y);
                            ok=1;
                        }
                        else if(h.Pozitia_x_y(x-1,y) != 'C')            // robotul incearca sa faca un ocol
                        {
                            x--;
                            r->Muta_Robotul(x,y);
                            ok=1;
                        }
                    y = r->Coordonata_y();                              // se reactualizeaza coordonatele robotului
                    x = r->Coordonata_x();
                    ok=1;
                    cout<<"Robotul sare peste o capcana si ajunge la pozitia: "<<x<<" "<<y<<endl;
                }
                else if(h.Pozitia_x_y(x,y-1) != 'C')                    // robotul incearca sa ocoleasca capcana
                {
                    y--;
                    ok=1;
                }
                else if(h.Pozitia_x_y(x-1,y) != 'C')                    // robotul incearca sa ocoleasca capcana
                {
                    x--;
                    ok=1;
                }
            }
            else if(x < u&& y < p  )                                    // la fel ca in primul caz
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
            else if(x > u&& y < p )                                     // la fel ca in primul caz
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
            else if(x < u && y > p )                              // la fel ca in primul caz
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
            else if(x == u&& y > p)                 // la fel ca in primul caz
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
            else if(x == u&& y < p )                    // la fel ca in primul caz
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
            else if(x < u&& y == p )                    // la fel ca in primul caz
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
            else if(x > u&& y == p )                        // la fel ca in primul caz
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
            else if(u == x && p == y)
                ok=1;
            r->Muta_Robotul(x,y);                           // se muta robotul in functie de noile coordonate
            if(h.Pozitia_x_y(x,y) == 'I')                   // se verifica daca am ajuns pe un item
            {
                n=1+rand()%3;                               // o variabila n ia o valoare random ce va inica tipul itemului
                h.Modifica_Harta(x,y,'0');                  // itemul este sters de pe harta deoarece este considerat consumat
                Item1 i1;                                   // se concep cele 3 tipuri de iteme
                Item2 i2;
                Item3 i3;
                if(n==1)                                    // in functie de n aceste tipuri unul dintre iteme devine valid
                    i1.Set_Valid();
                else if(n==2)
                    i2.Set_Valid();
                else
                    i3.Set_Valid();
                if((i3.Valid() && r->Tip() == 3) || (i2.Valid() && r->Tip() == 2) || (i1.Valid() && r->Tip() == 1)) // se verifica daca tipul robotului coincide cu tipul itemului
                {
                    cout<<endl<<"Item compatibil"<<endl;
                    if(r->Tip() == 2)           // se verifica daca robotul este de tip 2
                    {
                        r->Item(1);             // se adauga inca o utilizare pentru acest robot
                        cout<<"Se adauga in stocul robotului inca o utilizare "<<endl;
                    }
                    else if(r->Tip() == 3)      // se verifica daca robotul este de tip 3
                    {
                        h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());  // se afiseaza odata harta inainte de teleportarea robotului
                        h = r->Abilitate(h,xh,yh);                                    // robotul isi manifesta abilitatea
                        cout<<"Deoarece robotul este compatibil cu itemul acesta se teleporteaza pe pozitiile:"<<r->Coordonata_x()<<" "<<r->Coordonata_y()<<endl;
                    }
                    else
                    {
                        h = r->Abilitate(h,u,p); // daca robotul este de tip 1 atunci sterge capcana din perimetrul acestuia
                        cout<<"Deoarece robotul este compatibil cu itemul se sterge o capcana din perimetrul acestuia."<<endl;
                    }

                }
                else                            // cazul in care robotul nu este compatibil cu itemul
                    cout<<endl<<"Item incompatibil"<<endl;
                u = p = -1;                     // deoarece itemul a fost folosit coodronatele acestuia revin la valoarea initiala care indica inexistenta unui item
                scor++;                         // deoarece totusi s-a obtinut un item, fie el compatibil sau nu scorul creste
                y = r->Coordonata_y();          // se reactualizeaza x si y
                x = r->Coordonata_x();
            }
            h.Arata_Harta_Cu_Robot(r->Coordonata_x(),r->Coordonata_y());  //se afiseaza harta pentru aceasta runda
            cout<<endl<<"Se muta robotul pe pozitia: "<<x<<" "<<y;
        }
        else  // in caz ca robotul nu are nici un item in perimetru, acesta se va indrepta spre S, analog cu bucata de program pentru care u!= -1
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
        if(e)                       //daca utilizatorul a ales sa vada programul pas cu pas atunci aceasta instructiune il opreste si il forteaza sa apese pe tastatura pentru urmatoarea stare
        {
            cout<<"Apasati o tasta, iar apoi enter daca sunteti gata sa treceti la pasul urmator: ";
            char c;
            cin>>c;
        }
        if(ok == 0)                 // daca robotul nu mai poate inainta se iese fortat din while
            break;
    }
    if(ok==0)                       // se verifica daca robotul nu a mai putut inainta si se afiseaza un mesaj relefant
        cout<<endl<<"Robotul nu a mai putut inainta"<<endl;
    cout<<"\nScor = "<<scor<<endl;  // este afisat scorul final al robotului
}
Simulare::~Simulare()               // destructorul
{
    scor=0;                         // scorul va i 0
    delete r;                       // se sterge robotul
}
