#ifndef ROBOTI_H
#define ROBOTI_H


class Roboti
{
    int x,y,tip;
    public:
        Roboti();
        Roboti(int);
        virtual int Coordonata_x();
        virtual int Coordonata_y();
        virtual int Tip();
        virtual void Abilitate();
        void Muta_Robotul(int,int);

};

#endif // ROBOTI_H
