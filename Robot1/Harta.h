#ifndef HARTA_H
#define HARTA_H


class Harta
{
    char **a;
    public:
        Harta();
        Arata_Harta();
        Arata_Harta_Cu_Robot(int,int);
        Modifica_Harta(int,int);
        char Pozitia_x_y(int,int);
};

#endif // HARTA_H
