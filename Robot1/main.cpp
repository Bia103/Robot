#include <iostream>
#include "Harta.h"
#include "Roboti.h"
#include "Iteme.h"
using namespace std;

int main()
{
    Harta h;
    h.Arata_Harta();
   // h.Modifica_Harta(0,5);
    h.Arata_Harta_Cu_Robot(0,0);
    cout<<endl<<h.Pozitia_x_y(0,5);
    return 0;
}
