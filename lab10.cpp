//operator overloading

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;


//the polynomial
class polinom
{

    double* _k; //array of coefficients of the polynomial. The index is equal to the degree of the variable
    int _cnt; //array size
    char _c; //variable symbol

    //calculating the factorial
    unsigned long long int factorial(int n) const
    {
        return (n) ? n * factorial(n - 1) : 1;
    }

    //evaluates the expression x^n=(a+z)^n
    double* uexp(double a, int n) const
    {
        double* res = new double[n + 1];
        for (int k = 0; k <= n; k++)
            res[k] = pow(a, n - k) * (factorial(n) / (factorial(k) * factorial(n - k)));
        return res;
    }


public:

    //initializes the variable character
    void var(char var)
    {
        _c = var;
    }

    //returns the character of the variable
    char var() const
    {
        return _c;
    }

    //replaces х=(a+z) and returns the result
    polinom operator+(double a) const
    {
        double* res = new double[_cnt] {0};
        for (int i = 0; i < _cnt; i++)
        {
            double* pres = uexp(a, i);
            transform(pres, pres + i + 1, res, res, [this, &i](const double& val1, const double& val2)
            {
                return val1 * _k[i] + val2;
            });
            delete[] pres;
        }
        return polinom(res, _cnt);
    }

    //string representation of a polynomial
    string to_string() const
    {
        stringstream ss;
        ss<< fixed << setprecision(1);
        for (int i = _cnt - 1; i >= 0; i--)
        {
            ss << _k[i];
            if (i >= 1)ss << '*' << _c;
            if (i > 1)ss << '^' << i << ' ';
            if (i != 0)ss << '+';
        }
        return ss.str();
    }

    //constructors
    polinom(double* k, int cnt, char var = 'x')
    {
        _k = k;
        _cnt = cnt;
        _c = var;
    }

    polinom(const initializer_list<double>& list, char var = 'x')
    {
        _k = new double[list.size()];
        copy(list.begin(), list.end(), _k);
        _cnt = list.size();
        _c = var;
    }

    //destructor
    ~polinom()
    {
        delete[] _k;
    }
};


int main()
{
    //testing
    polinom p({ 2,2,3 });
    polinom res = p + 2;
    res.var('z');
    cout << res.to_string() << endl;

    return 0;
}
