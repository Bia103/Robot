#include "Harta.h"
#include <random>
#include<iostream>
using namespace std;
Harta::Harta()
{
    a=new char*[15];
    for(int i = 0; i < 15; ++i)
        a[i] = new char[15];
    int n=rand()%110;
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            a[i][j]='0';
    for(int i=0;i<n;i++)
    {
        int xh=rand()%15;
        int yh=rand()%15;
        if(xh!=14&&yh!=13&&yh!=0)
            a[xh][yh]='C';
    }

    for(int i=0;i<15;i++)
    {
        int ok1=0,ok2=0;
        for(int j=0;j<15;j++)
        {
            if(a[i][j]=='0')
                ok1=1;
            if(a[j][i]=='0')
                ok2=1;
        }
        if(!ok1)
        {
            a[i][8]='0';
        }
        if(!ok2)
        {
            a[8][i]='0';
            int x=i,y=8;
            while(a[y][x+1]!='0'&&a[y-1][x+1]!='0'&&a[y-1][x+1]!='0')
            {
                a[y][x+1]='0';
                x++;
            }
        }
    }
    n=rand()%50;
    for(int i=0;i<n;i++)
    {
        int xh=rand()%15;
        int yh=rand()%15;
        a[xh][yh]='I';
    }
    n=rand()%15;
    a[n][14]='S';
    xh=n;
    yh=14;
    //a[1][1]='C';
}
Harta::Harta(const Harta &b)
{
    a=new char*[15];
    for(int i = 0; i < 15; ++i)
        a[i] = new char[15];
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            a[i][j]=b.a[i][j];
    xh=b.xh;
    yh=b.yh;
}
Harta::Arata_Harta()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
Harta::Arata_Harta_Cu_Robot(int x,int y)
{
    for(int i=0;i<=16;i++)
        cout<<"X ";
    cout<<endl;
    for(int i=0;i<15;i++)
    {
         cout<<"X ";
        for(int j=0;j<15;j++)
            if(i==x&&y==j)
                cout<<"R ";
            else if(a[i][j]=='0')
                cout<<"  ";
            else cout<<a[i][j]<<" ";
        cout<<"X ";
        cout<<endl;
    }
    for(int i=0;i<=16;i++)
        cout<<"X ";
    cout<<endl;
}
Harta::Modifica_Harta(int x,int y)
{
    a[x][y]='0';
}
char Harta::Pozitia_x_y(int x,int y)
{
    return a[x][y];
}
int Harta::Coord_xh()
{
    return xh;
}
Harta Harta:: operator=(const Harta &op2)
{
    char **u=new char*[15];
    for(int i = 0; i < 15; ++i)
        u[i] = new char[15];
     for(int i = 0; i < 5; ++i) {
        delete[] a[i];
    }
    delete[] a;
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            u[i][j]=op2.a[i][j];
    a=u;
    xh=op2.xh;
    yh=op2.yh;
    return *this;
}
