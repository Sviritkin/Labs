#include <iostream>
#include <cmath>

using namespace std;

double Number (string x){

int n;

while (true)
{
    cout << x;
    cin >> n;
    if (!cin || n < 0)
    {
        cout << "Ошибка ввода!\n";
        cin.clear ();
        while (cin.get() != '\n');
    }
    else break;
    }
return n;
}


int main()
{
    setlocale (LC_ALL, "Russian");

    double V, S, t, V1, V2;

    V = Number ("Введите скорость: ");
    S = Number ("Введите расстояние: ");
    t = Number ("Введите время: ");

    V1 = S/t;
    V2 = S/((2 * S)/(V - t));

    cout << "Средняя скорость из пункта А в пункт Б: " << V1 << endl;
    cout << "Средняя скорость из пункта Б в пункт А: " << V2 << endl;

    return 0;
}
