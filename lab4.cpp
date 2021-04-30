//Function

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


//calculating the factorial
unsigned long long fact(int v)
{
    return (v!=0)?v*fact(v-1):1;
}

//calculating a function
double calc(double x)
{
    const int n=15;
    double res=0;
    for(int i=0; i<n; i++)
        res+=pow(-1,i)*pow(x,2*i)/fact(2*i+1);
    return res;
}


int main()
{
    cout <<fixed<<setprecision(6)<< calc(0.2318) << endl;
    return 0;
}
