
class cQuad
{
private:
    bool square;
    double a;
    double b;
    double A;
    double u;

    void calc_A();
    void calc_u();
    void calc_all();

public:
    void correct_a(double i_a);
    bool is_square();
    void correct_b(double i_b);
    double get_a();
    double get_b();
    double get_u();
    double get_A();
    cQuad(double i_a, double i_b);   //rectangle
    cQuad(double i_a);   //square
};