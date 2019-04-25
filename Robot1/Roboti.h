#ifndef ROBOTI_H
#define ROBOTI_H
#include"Harta.h"

class Roboti
{
    int am_itemul;
    int x,y,tip;
    public:
        Roboti();
        Roboti(int);
        virtual int Coordonata_x();
        virtual int Coordonata_y();
        virtual int Tip();
        void Set_tot_zero();
        virtual Harta Abilitate(const Harta &,int,int);
        void Muta_Robotul(int,int);
        void Modifica_Tip(int);
        int Am_itemul();
        void Item(int);
        virtual ~Roboti();
};

#endif // ROBOTI_H
