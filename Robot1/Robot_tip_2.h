#ifndef ROBOT_TIP_2_H
#define ROBOT_TIP_2_H
#include "Roboti.h"
#include "Harta.h"
class Robot_tip_2:public Roboti
{
    //robotul ce poate sari peste o capcana apropiata

    public:
        Robot_tip_2();
        Robot_tip_2(int);
        Harta Abilitate(const Harta &,int,int);

        //int Am_itemul();

};

#endif // ROBOT_TIP_2_H
