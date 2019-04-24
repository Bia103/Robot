#ifndef SIMULARE_H
#define SIMULARE_H
#include "Harta.h"
#include "Roboti.h"
#include "Iteme.h"
#include "Robot_Tip_1.h"
#include "Robot_tip_2.h"
#include "Robot_Tip_3.h"
class Simulare
{

    Roboti *r;
    int scor;
    //Robot_Tip_1 r1;
    //Robot_tip_2 r2;
    //Robot_Tip_3 r3;
    //Iteme i;
    public:
        Simulare();
        void Incepe_simularea(int,int,int,int);

};

#endif // SIMULARE_H
