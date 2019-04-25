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
Harta Robot_Tip_3::Abilitate(const Harta &h,int xh,int yh)
{
    int p=0,u=0,mix=INT_MAX;
    /*
    - u si p reprezinta pozitia pe care robotul de va teleporta
    - mix trebuie sa aiba la final o valoarea cat mai mica fata de coordonatele lui S
    */
    Harta t(h);                                             // se construieste o noua harta egala cu prima
    int x=Coordonata_x();                                   // se initializeaza x care va avea coordonata x a robotului
    int y=Coordonata_y();                                   // se initializeaza y care va avea coordonata y a robotului
    int q=t.Q();                                            // se initializeaza q cu inaltimea hartii
    int w=t.W();                                            // se initializeaza w cu latimea hartii
    for(int i=x-4; i<=x+4; i++)                             // se parcurge perimetrul din jurul robotului
    {
        for(int j=y-4; j<=y+4; j++)
        {
            if(i >=0 && i < q && j >= 0 && j < w )          // se verifica daca nu se iese din harta
            {
                int cont1 = xh - i;                         // se calculeaza care este cea mai apropiata pozitie de S( din punct de vedere al inaltimii) pe care robotul se poate teleporta
                int cont2 = yh - j;                         // se calculeaza care este cea mai apropiata pozitie de S( din punct de vedere al latimii) pe care robotul se poate teleporta
                if(cont1 < 0)                               // se face modulul lui cont1
                    cont1 = 0 - cont1;
                if(cont2<0)
                    cont2 = 0 - cont2;                      // se face modulul lui cont2
                if(cont1 + cont2 <= mix && t.Pozitia_x_y(i,j) != 'C') // se procedeaza ca in Abilitatea robotului de tip 1
                {
                    /*
                    Spre exemplu avem
                            0 0 0 0 0 0 0 0 0           0 0 0 0 0 0 0 0 0
                            0 0 0 0 0 0 0 0 0           0 0 0 0 0 0 0 0 0
                            0 0 0 0 0 0 0 0 0           0 0 0 0 0 0 0 0 0
                            0 0 0 0 R 0 0 0 0  ----->   0 0 0 0 0 0 0 0 0
                            0 0 0 0 0 0 C 0 0           0 0 0 0 0 0 C 0 0
                            0 0 0 0 C 0 0 0 0           0 0 0 0 C 0 0 0 0
                            0 0 0 0 0 0 0 0 C           0 0 0 0 0 0 0 R C
                            0 0 0 0 0 0 0 C C           0 0 0 0 0 0 0 C C
                    */
                    mix = cont1 + cont2;
                    u = i;
                    p = j;

                }
            }
        }
    }
    Muta_Robotul(u,p);      //se muta robotul
    return t;
}
Robot_Tip_3::~Robot_Tip_3() //destructorul
{
    Set_tot_zero();         // sunt setate doate variabilele la 0
}
Robot_Tip_3::Robot_Tip_3(Robot_Tip_3& b)    //constructorul de copiere
{
    Muta_Robotul(b.Coordonata_x(),b.Coordonata_y());
    Modifica_Tip(b.Tip());
    Item(b.Am_itemul());
}
