#ifndef ROBOT_TIP_1_H
#define ROBOT_TIP_1_H
#include "Roboti.h"
#include "Harta.h"
class Robot_Tip_1:public Roboti
{
    //Robotul ce poate anihila cea mai apropiata capcana
    public:
        Robot_Tip_1();                              // constructorul fara paramatrii
        Robot_Tip_1(int);                           // constructorul cu un paramatru
        Robot_Tip_1(Robot_Tip_1& );                 // constructorul de copiere
        Harta Abilitate(const Harta &,int,int);     // abilitatea primului robot
        ~Robot_Tip_1();                             // destructorul

};

#endif // ROBOT_TIP_1_H
