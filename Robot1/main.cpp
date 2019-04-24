#include <iostream>
#include "Harta.h"
#include "Roboti.h"
#include "Iteme.h"
#include "Robot_Tip_1.h"
#include "Robot_tip_2.h"
#include "Robot_Tip_3.h"
#include "Simulare.h"
using namespace std;

int main()
{
    Simulare s;
    int x;
    char c;
    cout<<"Exista 3 tipuri de roboti:\n 1)-Robotul ce elimina o capcana din perimetrul acestuia in momentul in care gaseste un item compatibil\n 2)-Robotul ce sare peste capcane daca are un item \n 3)-Robotul ce se teleporteaza cat mai aprope de tinta lui\n";
    cout<<"Alegeti un numar intre 1 si 3 ce va reprezenta tipul robotului e va fi implicat in simulare :";
    cin>>x;
    cout<<endl;
    cout<<"Doriti sa vedeti simularea robotului cu pauze intre pasi sau totul sa fie simulat instant? Raspundeti cu D(da) sau N(nu): ";
    cin>>c;
    cout<<endl<<"Introduceti inaltimea si respectiv lungimea hartii:";
    int y,z;
    cin>>y>>z;
    if(c == 'D')
        s.Incepe_simularea(x,1,y,z);
    else s.Incepe_simularea(x,0,y,z);
    return 0;
}
