//Classes and objects

#include <iostream>

using namespace std;

//classes for calculating the factorial of a number
class Factorial
{
    int n; //поле класса

    //function for calculating the factorial of a number
    unsigned long long fact(int n) const
    {
        return (n == 0) ? 1 : n * fact(n - 1);
    }

public:
    int get_n() const
    {
        return n;
    }

    void set_n(int n)
    {
        this->n = n;
    }

    unsigned long long calculate() const
    {
        return fact(n);
    }
};


int main()
{

    Factorial f;
    f.set_n(3);
    cout << f.calculate() << endl;

    return 0;
}
