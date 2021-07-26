#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"cursorpos.h"
using namespace std;


class cQuad
{
private:
    double a;
    double b;
    double A;
    double u;
    void calc_A()
    {
        A=a*b;
    }
    void calc_u()
    {
        u=a+a+b+b;
    }
public:
    double get_a()
    {
        if(a>0)
            return a;
        else
            return -1;
    }
    double get_b()
    {
        if(b>0)
            return b;
        else
            return -1;
    }
    double get_u()
    {
        if(u>0)
            return u;
        else
            return -1;
    }
    double get_A()
    {
        if(A>0)
            return A;
        else
            return -1;
    }
    cQuad(double i_a, double i_b)   //rectangle
    {
        a=i_a;
        b=i_b;
        calc_A();
        calc_u();
    }
    cQuad(double i_a)   //square
    {
        a=i_a;
        b=i_a;
        calc_A();
        calc_u();
    }


};




int main()
{
    cQuad* pQuad[999]; //Pointer auf Klasse deklarieren
    bool esc=false;
    bool flag=false;
    bool square;
    double a,b;
    size_t value;
    size_t temp=0;
    size_t num=0;
    printf("Wie viele Quadrahte und Rechtecke\n");
    cin>>value;

    while(temp<value)
    {
        
        printf("Rechteck (0) oder Quadraht (1)");
        cin>>square;

        if(square)
        {
            printf("Seitenl\x84nge");
            cin>>a;
        } else
        {
            printf("Seitenl\x84nge a");
            cin>>a;
            printf("Seitenl\x84nge b");
            cin>>b;
        }

        if(square)
            pQuad[temp]=new cQuad(a);
        else
            pQuad[temp]=new cQuad(a,b);
        temp++;
    }

    while(!esc)
    {
        flag=false;
        while(!flag)
        {
            system("cls");
            set_cursor(2,0);
            printf("%d Eintr\x84ge vorhanden\nWelche Eintrag soll angezeigt werden:\t",value);
            cin>>num;
            if(num<=value)
                flag=true;
        }

        if(num<=0)
            esc=true;
        else
        {
            printf("\nFl%ccheninhalt: %4.4lf",132,pQuad[num-1]->get_A());
            printf("\nUmfang: %4.4lf",(*pQuad[num-1]).get_u());
            printf("\nSeitenl\x84nge a: %4.4lf",pQuad[num-1]->get_a());
            printf("\nSeitenl\x84nge b: %4.4lf",pQuad[num-1]->get_b());
            while(!_kbhit());
        }
    }
    for(size_t i=0; i<value; i++)
        delete pQuad[i];
    return 0;
}
