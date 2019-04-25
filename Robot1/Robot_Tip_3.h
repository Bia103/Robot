#ifndef ROBOT_TIP_3_H
#define ROBOT_TIP_3_H
#include "Roboti.h"

class Robot_Tip_3:public Roboti
{
    //robotul ce se teleporteaza cat mai aproape de final (S)
    public:
        Robot_Tip_3();
        Robot_Tip_3(int);
        Robot_Tip_3(Robot_Tip_3& );
        Harta Abilitate(const Harta&h,int,int);
        ~Robot_Tip_3();

};

#endif // ROBOT_TIP_3_H
