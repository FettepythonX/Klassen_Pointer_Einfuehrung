#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;


class cQuad
{
private:
    bool square;
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
    void calc_all()
    {
        calc_u();
        calc_A();
    }

public:
    void correct_a(double i_a)
    {
        if(square)
        {
            a=i_a;
            b=i_a;
            calc_all();
        }else if(i_a>0)
            a=i_a,
            calc_all();
    }

    bool is_square()
    {
        return square;
    }
    void correct_b(double i_b)
    {
        if(i_b>0)
            a=i_b;
        calc_all();
    }

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
        square=false;
        a=i_a;
        b=i_b;
        calc_A();
        calc_u();
    }

    cQuad(double i_a)   //square
    {
        square=true;
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

    double a,b;
    size_t value;     //size_t ist unsigned int mit angepasster größe. die größe richtet sich nach der CPU-Architektur, zb bei einem 8bit cpu entspricht dies uint8_t
    
    size_t num=0;

    printf("Wie viele Quadrate und Rechtecke: ");
    cin>>value;

    for(size_t i=0; i<value; i++)
    {
        printf("Seitenl\x84nge a: ");
        cin>>a;
        printf("Seitenl\x84nge b (bei Quadrat 0): ");
        cin>>b;
        if(b==0)
            pQuad[i]=new cQuad(a);   //Dynamische Instanzierung auf pQuad
        else
            pQuad[i]=new cQuad(a,b); //Dynamische Instanzierung auf pQuad
    }
    
    while(!esc)
    {
        flag=false;
        while(!flag)
        {
            system("cls");
            printf("%d Eintr\x84ge vorhanden\nWelche Eintrag soll angezeigt werden:\t",value);
            cin>>num;
            if(num<=value)
                flag=true;
        }

        if(num<=0)
            esc=true;
        else
        {
            printf("\nFl%ccheninhalt: %4.4lf",132,pQuad[num-1]->get_A());   //Zugriff auf Klasse jetzt nicht mehr mit objekt.funktion sonder pointer->funktion
            printf("\nUmfang: %4.4lf",(*pQuad[num-1]).get_u());             //andere schreibweise
            printf("\nSeitenl\x84nge a: %4.4lf",pQuad[num-1]->get_a());
            if(!pQuad[num-1]->is_square())                                  //überprüft ob die es sich um ein quadraht oder rechteck handelt
                printf("\nSeitenl\x84nge b: %4.4lf\n",pQuad[num-1]->get_b());
            while(!_kbhit());                                               //_kbhit() gibt 0 zurück wenn keine Taste gedrückt wurde, und 1 wenn eine Taste gedrückt wurde
        }
    }
    for(size_t i=0; i<value; i++)   //alle Objekte zerstören, die mit new erstellt wurden. (alles was mit "new" erstellt wird, muss auch mit "delete" zerstört werden
        delete pQuad[i];
    return 0;
}
