//Function

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double Number(string x) {
    double n = 0;
    while (true)
    {
        cout << x;
        cin >> n;
        if (!cin)
        {
            cout << "Input error!\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }
    return n;
}

unsigned long long fact(int v)
{
    return (v!=0)?v*fact(v-1):1;
}



int main()
{
    double x = Number("Enter x: ");

    const int n = 15;
    double res = 0;

    for(int i=0; i<n; i++)
        res+=pow(-1,i)*pow(x,2*i)/fact(2*i+1);

    cout << "sin(x)/x with row border 15 = " << res << endl;
    return 0;
}
