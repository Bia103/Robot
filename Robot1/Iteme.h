#ifndef ITEME_H
#define ITEME_H
#include "Roboti.h"

class Iteme
{
    int tip,valid;
    public:
        Iteme();
        Iteme(int );
        virtual int Get_Tip()=0;
        virtual int Valid()=0;
        virtual void Set_Valid()=0;

};
class Item1:Iteme
{
    int tip,valid;
    public:
        Item1();
        Item1(int );
        int Get_Tip();
        int Valid();
        void Set_Valid();
        ~Item1();
};
class Item2
{
    int tip,valid;
    public:
        Item2();
        Item2(int );
        int Get_Tip();
        int Valid();
        void Set_Valid();
        ~Item2();
};
class Item3
{
    int tip,valid;
    public:
        Item3();
        Item3(int );
        int Get_Tip();
        int Valid();
        void Set_Valid();
        ~Item3();
};

#endif // ITEME_H
