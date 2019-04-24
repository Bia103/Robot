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
        virtual Harta Abilitate(const Harta &,int,int);
        void Muta_Robotul(int,int);
        void Modifica_Tip(int);
        int Am_itemul();
         void Item(int);
};

#endif // ROBOTI_H
