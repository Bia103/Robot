#include "Harta.h"
#include <random>
#include<iostream>
using namespace std;
Harta::Harta()
{
    a=new char*[15];
    for(int i = 0; i < 15; ++i)
        a[i] = new char[15];
    int n=rand()%120;
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
    n=rand()%60+1;
    for(int i=0;i<n;i++)
    {
        int xh=rand()%15;
        int yh=rand()%15;
        a[xh][yh]='I';
    }
    n=rand()%3+10;
    int z=rand()%3+10;
    a[n][z]='S';
    xh=n;
    yh=z;
    a[0][0]='0';
    q=15;
    w=15;
}
Harta::Harta(int b, int c)
{
    q=b;
    w=c;
    a=new char*[q];
    for(int i = 0; i < q; ++i)
        a[i] = new char[w];
    int n=rand()%200;
    for(int i=0;i<q;i++)
        for(int j=0;j<w;j++)
            a[i][j]='0';
    for(int i=0; i<n ; i++)
    {
        int xh = rand()%q;
        int yh = rand()%w;
        if(xh != w-1 && yh != 13 && yh !=0 )
            a[xh][yh]='C';
    }
    n=rand()%60+1;
    for(int i=0;i<n;i++)
    {
        int xh=rand()%q;
        int yh=rand()%w;
        a[xh][yh]='I';
    }
    n=rand()%(q/2)-1+q/2;
    int z=rand()%(w/2)-1+w/2;
    a[n][z]='S';
    xh=n;
    yh=z;
    a[0][0]='0';
}
Harta::Harta(const Harta &b)
{
    q=b.q;
    w=b.w;
    a=new char*[q];
    for(int i = 0; i < q; ++i)
        a[i] = new char[w];
    for(int i=0;i<q;i++)
        for(int j=0;j<w;j++)
            a[i][j]=b.a[i][j];
    xh=b.xh;
    yh=b.yh;
}
Harta::Arata_Harta()
{
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<q;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
Harta::Arata_Harta_Cu_Robot(int x,int y)
{
    cout<<endl;
    for(int i=0;i<=w+1;i++)
        cout<<"X ";
    cout<<endl;
    for(int i=0;i<q;i++)
    {
         cout<<"X ";
        for(int j=0;j<w;j++)
            if(i==x&&y==j)
                cout<<"R ";
            else if(a[i][j]=='0')
               cout<<"  ";
            else cout<<a[i][j]<<" ";
        cout<<"X ";
        cout<<endl;
    }
    for(int i=0;i<=w+1;i++)
        cout<<"X ";
    cout<<endl;
}
Harta::Modifica_Harta(int x,int y,char c)
{
    a[x][y]=c;
}
char Harta::Pozitia_x_y(int x,int y)
{
    return a[x][y];
}
int Harta::Coord_xh()
{
    return xh;
}
int Harta::Coord_yh()
{
    return yh;
}
Harta Harta:: operator=(const Harta &op2)
{
    char **u=new char*[op2.q];
    for(int i = 0; i < op2.q; ++i)
        u[i] = new char[op2.w];
     for(int i = 0; i < op2.q; ++i) {
        delete[] a[i];
    }
    delete[] a;
    for(int i=0;i<op2.q;i++)
        for(int j=0;j<op2.w;j++)
            u[i][j]=op2.a[i][j];
    q=op2.q;
    w=op2.w;
    a=u;
    xh=op2.xh;
    yh=op2.yh;
    return *this;
}
int Harta::Q()
{
    return q;
}
int Harta::W()
{
    return w;
}
Harta::~Harta()
{
    for(int i = 0; i < q; ++i)
        delete[] a[i];
    delete []a;
    q=w=xh=yh=0;
}
