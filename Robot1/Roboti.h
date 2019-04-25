#ifndef ROBOTI_H
#define ROBOTI_H
#include"Harta.h"

class Roboti                                    // clasa de baza a tuturor robotilor
{
    int am_itemul;
    int x,y,tip;
    /*
    am_itemul= arata daca un robot stocheaza un item
    x= coordonata x(inaltime) la care se afla robotul
    y= coordonata y(latime) la care se afla robotul
    tip= denumeste tipul robotului
    */
    public:
        Roboti();                               // constructorul fara parametrii
        Roboti(int);                            // constructorul cu parametru
        Roboti(Roboti&);                         // constructorul de copiere
        int Coordonata_x();                     // returneaza coordonata x
        int Coordonata_y();                     // returneaza coordonata y
        int Tip();                              // intoarce tipul robotului
        void Set_tot_zero();                    // seteaza toate variabilele clasei la 0
        virtual Harta Abilitate(const Harta &,int,int); // abilitatea robotului ce este virtuala
        void Muta_Robotul(int,int);             // metoda ce muta robotul pe harta
        void Modifica_Tip(int);                 // metoda ce modifica tipul robotului
        int Am_itemul();                        // metoda ce returneaza valoarea lui am_itemul
        void Item(int);                         // metoda ce creste valoarea itemului
        virtual ~Roboti();                      // destructor
};

#endif // ROBOTI_H
