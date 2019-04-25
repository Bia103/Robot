#ifndef ROBOT_TIP_2_H
#define ROBOT_TIP_2_H
#include "Roboti.h"
#include "Harta.h"
class Robot_tip_2:public Roboti
{
    //robotul ce poate sari peste o capcana apropiata
    int v;
    public:
        Robot_tip_2();
        Robot_tip_2(int);
        Robot_tip_2(Robot_tip_2& );
        int V();
        Harta Abilitate(const Harta &,int,int);
        ~Robot_tip_2();
};

#endif // ROBOT_TIP_2_H
