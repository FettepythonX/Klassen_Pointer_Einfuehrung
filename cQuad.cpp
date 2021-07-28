#include"cQuad.h"

//class cQuad
//{
//private:
//    bool square;
//    double a;
//    double b;
//    double A;
//    double u;
    void cQuad::calc_A()
    {
        A=a*b;
    }
    void cQuad::calc_u()
    {
        u=a+a+b+b;
    }
    void cQuad::calc_all()
    {
        calc_u();
        calc_A();
    }

//public:
    void cQuad::correct_a(double i_a)
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

    bool cQuad::is_square()
    {
        return square;
    }
    void cQuad::correct_b(double i_b)
    {
        if(i_b>0)
            a=i_b;
        calc_all();
    }

    double cQuad::get_a()
    {
        if(a>0)
            return a;
        else
            return -1;
    }

    double cQuad::get_b()
    {
        if(b>0)
            return b;
        else
            return -1;
    }

    double cQuad::get_u()
    {
        if(u>0)
            return u;
        else
            return -1;
    }

    double cQuad::get_A()
    {
        if(A>0)
            return A;
        else
            return -1;
    }

    cQuad::cQuad(double i_a, double i_b)   //rectangle
    {
        square=false;
        a=i_a;
        b=i_b;
        calc_A();
        calc_u();
    }

    cQuad::cQuad(double i_a)   //square
    {
        square=true;
        a=i_a;
        b=i_a;
        calc_A();
        calc_u();
    }


//};