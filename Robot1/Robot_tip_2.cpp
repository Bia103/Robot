#include "Robot_tip_2.h"
#include"Harta.h"
#include"Roboti.h"
#include<iostream>
using namespace std;
Robot_tip_2::Robot_tip_2():Roboti()                         //constructorul fara parametri
{

}
Robot_tip_2::Robot_tip_2(int x):Roboti(x)                   //constructorul cu paramatrii ce il trimite pe x care este tipul spre clasa de baza
{

}
Harta Robot_tip_2::Abilitate(const Harta &h,int xh,int yh)  // xh si yh sunt coordonatele spre care robotul trebuie sa inainteze
{
    Harta t(h);                                             // se construieste o noua harta egala cu prima
    int x=Coordonata_x();                                   // se initializeaza x care va avea coordonata x a robotului
    int y=Coordonata_y();                                   // se initializeaza y care va avea coordonata y a robotului
    int q=t.Q();                                            // se initializeaza q cu inaltimea hartii
    int w=t.W();                                            // se initializeaza w cu latimea hartii
    v=1;
    // dupa prima expricatie pentru if, toate celelate sunt identice
    if(x == xh && y<yh && Am_itemul() && t.Pozitia_x_y(x,y+1) == 'C' && (t.Pozitia_x_y(x,y+2) == '0' || t.Pozitia_x_y(x,y+2) == 'S' || t.Pozitia_x_y(x,y+2) == 'I') && y+2 < w)
    {
        /*
        In conditia de mai sus se verifica:
        - modul in care este plasat robotul fata de pozitia la care trebuie sa ajunga
        - daca in eventualitatea unei sarituri facute peste capcana pozitia in care trebuie sa ajunga este diferita de C
        - daca nu cumva robotul iese din harta
        */
        Muta_Robotul(x,y+2); // pozitia robotului se modifica sarind peste capcana
         Item(-1);v=0;       // se consuma un item din stocare
    }
    if(x < xh && y < yh && Am_itemul() && t.Pozitia_x_y(x+1,y+1) == 'C' && (t.Pozitia_x_y(x+2,y+2) == '0' || t.Pozitia_x_y(x+2,y+2) == 'S' || t.Pozitia_x_y(x+2,y+2) == 'I') && y+2 < w && x+2 < q)
    {
        Muta_Robotul(x+2,y+2);
         Item(-1);v=0;
    }
    if(x > xh&&y<yh&&Am_itemul()&&t.Pozitia_x_y(x-1,y+1)=='C'&&(t.Pozitia_x_y(x-2,y+2)=='0'||t.Pozitia_x_y(x-2,y+2)=='S'|| t.Pozitia_x_y(x-2,y+2) =='I') && y+2 < w& & x-2 >= 0)
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
Robot_tip_2::~Robot_tip_2()                             // destructorul
{
    Set_tot_zero();                                     // toate variabilele devin 0
}
int Robot_tip_2::V()
{
    return v;
}
Robot_tip_2::Robot_tip_2(Robot_tip_2& b)                // constructorul de copiere
{
    Muta_Robotul(b.Coordonata_x(),b.Coordonata_y());    // se muta robotul in functie de al doilea
    Modifica_Tip(b.Tip());                              // se modifica tipul primului robot in functie de tipul robotului b
    Item(b.Am_itemul());                                // am_itemul primeste am_itemul lui b
}
