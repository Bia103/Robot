#ifndef ITEME_H
#define ITEME_H
#include "Roboti.h"

class Iteme         //clasa abstracta pentru iteme
{
    int tip,valid;
    public:
        Iteme();
        Iteme(int );
        Iteme(Iteme& );
        virtual int Get_Tip()=0;
        virtual int Valid()=0;
        virtual void Set_Valid()=0;

};
class Item1:Iteme
{
    int tip,valid;
    /*
    tip = tipul obiectului
    valid = daca obiectul acesta poate fi folosit
    */
    public:
        Item1();            // constructorul fara parametrii
        Item1(int );        // constructorul cu parametru
        Item1 (Item1&);     // constructorul de copiere
        int Get_Tip();      // metoda ce returneaza tipul
        int Valid();        // metoda ce returneaza valoarea lui valid
        void Set_Valid();   // metoda ce schimba valoarea lui valid
        ~Item1();           // destructorul
};
class Item2
{
    int tip,valid;
    public:
        Item2();
        Item2(int );
        Item2 (Item2&);
        int Get_Tip();      // metoda ce returneaza tipul
        int Valid();        // metoda ce returneaza valoarea lui valid
        void Set_Valid();   // metoda ce schimba valoarea lui valid
        ~Item2();
};
class Item3
{
    int tip,valid;
    public:
        Item3();
        Item3(int );
        Item3(Item3&);
        int Get_Tip();      // metoda ce returneaza tipul
        int Valid();        // metoda ce returneaza valoarea lui valid
        void Set_Valid();   // metoda ce schimba valoarea lui valid
        ~Item3();
};

#endif // ITEME_H
