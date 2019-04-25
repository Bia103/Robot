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
    Roboti *r;                  // robotul
    int scor;                   // scorul robotului
    public:
        Simulare();             // constructorul fara parametrii
        Simulare(Simulare&);    // constructorul de copiere
        void Incepe_simularea(int,int,int,int);     // metoda ce se ocupa de simularea jocului
        Simulare operator =(const Simulare& op2);   // supraincarcarea lui =
        ~Simulare();                                // destructorul

};

#endif // SIMULARE_H
