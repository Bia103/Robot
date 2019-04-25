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
    public:
        Simulare();
        Simulare(Simulare&);
        void Incepe_simularea(int,int,int,int);
        Simulare operator =(const Simulare& op2);
        ~Simulare();

};

#endif // SIMULARE_H
