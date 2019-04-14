#ifndef HARTA_H
#define HARTA_H


class Harta
{
    char **a;
    int xh,yh;
    public:
        Harta(const Harta &b);
        Harta();
        Arata_Harta();
        Arata_Harta_Cu_Robot(int,int);
        Modifica_Harta(int,int);
        char Pozitia_x_y(int,int);
        int Coord_xh();
        Harta operator =(const Harta& op2);
        //char Pozitia_x_y(int,int);
};

#endif // HARTA_H
