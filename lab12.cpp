//Generalized functions and classes

#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

class complex
{
    double _a;
    double _b;

public:


    const double& a() const
    {
        return _a;
    }


    const double& b() const
    {
        return _b;
    }


    complex operator+(const complex& val) const
    {
        return complex(_a + val._a, _b + val._b);
    }

    complex operator+(const double& val) const
    {
        return *this + complex(val, 0);
    }


    complex operator-(const complex& val) const
    {
        return complex(_a - val._a, _b - val._b);
    }

    complex operator-(const double& val) const
    {
        return *this - complex(val, 0);
    }


    complex operator*(const complex& val) const
    {
        return complex(_a * val._a - _b * val._b, _a * val._b + _b * val._a);
    }

    complex operator*(const double& val) const
    {
        return *this * complex(val, 0);
    }


    complex operator/(const complex& val) const
    {
        return complex((_a*val._a+_b*val._b)/(pow(val._a,2)+pow(val._b,2)),
                       (val._a*_b-_a*val._b)/ (pow(val._a, 2) + pow(val._b, 2)));
    }

    complex operator/(const double& val) const
    {
        return *this / complex(val, 0);
    }


    string to_string() const
    {
        stringstream ss;
        ss<<fixed<<setprecision(3)<< _a << ((_b >= 0) ? "+" : "") << _b << "i";
        return ss.str();
    }


    explicit complex(double a = 0, double b = 0)
    {
        _a = a;
        _b = b;
    }
};

complex pow(const complex& val, unsigned char n)
{
    if (!n)return complex(1., 0);
    complex res = val;
    for (unsigned char i = 1; i < n; i++)
        res = res * val;
    return res;
}

unsigned long long factorial(unsigned char n)
{
    return (n != 0) ? n * factorial(n - 1) : 1;
}

template<class T> T sin(const T& z, unsigned char n)
{
    T sum(0);
    for (unsigned char i = 0; i <= n; i++)
        sum = sum + ((pow(z, 2 * i + 1) * pow(-1, i)) / factorial(2 * i + 1));
    return sum;
}

ostream& operator<<(ostream& ost, const complex& val)
{
    ost << val.to_string();
    return ost;
}


int main()
{

    complex a(5, 2);
    complex b(3, 2);
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    cout << sin(1.234, 10) << endl;
    cout << sin(a, 10) << endl;

}
