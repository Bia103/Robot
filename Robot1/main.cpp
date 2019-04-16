#include <iostream>
#include "Harta.h"
#include "Roboti.h"
#include "Iteme.h"
#include "Robot_Tip_1.h"
#include "Robot_tip_2.h"
using namespace std;

int main()
{
    Harta h,b;
    int mi=INT_MAX;
    h.Arata_Harta();
    Harta o(b);
   // h.Modifica_Harta(0,5);
    o.Arata_Harta_Cu_Robot(0,0);
    h=b;
    h.Arata_Harta_Cu_Robot(0,0);
    cout<<endl<<h.Pozitia_x_y(0,5);
    /*Roboti r;
    cout<<r.Coordonata_x()<<" "<<r.Coordonata_y();*/
    Robot_Tip_1 r1(1);
    cout<<endl<<r1.Coordonata_x()<<" "<<r1.Coordonata_y()<<" "<<r1.Tip();
    //cout<<"xh= "<<
   // h=r1.Abilitate(h);
    Robot_tip_2 r;
    cout<<endl;
    h=r.Abilitate(h);
     h.Arata_Harta_Cu_Robot(r.Coordonata_x(),r.Coordonata_y());
    return 0;
}
