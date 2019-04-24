#ifndef HARTA_H
#define HARTA_H


class Harta
{
    char **a;
    int xh,yh;
    int q,w;
    public:
        Harta(const Harta &b);
        Harta();
        Harta(int i,int j);
        Arata_Harta();
        Arata_Harta_Cu_Robot(int,int);
        Modifica_Harta(int,int,char);
        char Pozitia_x_y(int,int);
        int Coord_xh();
        int Coord_yh();
        int Q();
        int W();
        Harta operator =(const Harta& op2);
        ~Harta();
        //char Pozitia_x_y(int,int);
};

#endif // HARTA_H
