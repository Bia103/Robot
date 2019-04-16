#ifndef ROBOTI_H
#define ROBOTI_H
#include"Harta.h"

class Roboti
{
    int x,y,tip;
    public:
        Roboti();
        Roboti(int);
        virtual int Coordonata_x();
        virtual int Coordonata_y();
        virtual int Tip();
        virtual Harta Abilitate(const Harta &);
        void Muta_Robotul(int,int);

};

#endif // ROBOTI_H
