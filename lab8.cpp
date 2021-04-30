//Working with objects

#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

/class complex number
class trig_complex
{
    double _r; //module
    double _f; //angle

    //converts a number from a trigonometric form to a simple one
    void ttnf(double &a, double &b) const
    {
        a = _r * cos(_f);
        b = _r * sin(_f);
    }

public:

    //returns the real part of a number
    const double &r() const
    {
        return _r;
    }

    //returns the imaginary part of a number
    const double &f() const
    {
        return _f;
    }

    //addition
    trig_complex add(const trig_complex &val) const
    {
        double a, a1, b, b1;
        ttnf(a, b);
        val.ttnf(a1, b1);
        return trig_complex(true, a + a1, b + b1);
    }

    //subtraction
    trig_complex sub(const trig_complex &val) const
    {
        double a, a1, b, b1;
        ttnf(a, b);
        val.ttnf(a1, b1);
        return trig_complex(true, a - a1, b - b1);
    }

    //multiplication
    trig_complex mul(const trig_complex &val) const
    {
        return trig_complex(_r * val._r, _f + val._f);
    }

    //division
    trig_complex div(const trig_complex &val) const
    {
        return trig_complex(_r / val._r, _f - val._f);
    }

    //string representation in trigonometric form
    string to_string() const
    {
        stringstream ss;
        ss << fixed << setprecision(3) << _r << "*(cos(" << _f << ") + i*sin(" << _f << "))";
        return ss.str();
    }

    //simple string representation
    string to_native_string() const
    {
        double a, b;
        ttnf(a, b);
        stringstream ss;
        ss << fixed << setprecision(3) << a << ((b < 0) ? "" : "+") << b << "i";
        return ss.str();
    }

    //constructions
    explicit trig_complex(bool, double a = 0, double b = 0)
    {
        _r = sqrt(pow(a, 2) + pow(b, 2));
        if (!_r)_f = 0;
        else
        {
            if (!a)_f = M_PI / 2;
            else
            {
                _f = atan(b / a);
                if (a < 0)
                {
                    if (b < 0)_f -= M_PI;
                    if (b > 0)_f += M_PI;
                }
            }
        }
    }

    explicit trig_complex(double r = 0, double f = 0)
    {
        _r = r;
        _f = f;
    }
};


int main()
{
    //testing
    trig_complex a(true, -1, -2);
    trig_complex b(true, 0, 3);

    cout << a.to_native_string() << endl;
    cout << b.to_native_string() << endl;
    cout << a.add(b).to_string() << endl; //addition
    cout << a.sub(b).to_string() << endl; //substruction
    cout << a.mul(b).to_string() << endl; //multiplication
    cout << a.div(b).to_string() << endl; //division
}
