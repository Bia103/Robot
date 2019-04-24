#ifndef ROBOT_TIP_1_H
#define ROBOT_TIP_1_H
#include "Roboti.h"
#include "Harta.h"
class Robot_Tip_1:public Roboti
{
    //robotul ce poate anihila cea mai apropiata capcana

    public:
        Robot_Tip_1();
        Robot_Tip_1(int);
        Harta Abilitate(const Harta &,int,int);


};

#endif // ROBOT_TIP_1_H
