#include <iostream>

using namespace std;

int factorial (int n){

if (n < 0)
    return 0;

if (n == 0)
    return 1;

if (n == 1)
    return 1;

else
    return n * factorial (n - 1);

}

int main (){

int n;
setlocale (LC_ALL, "Russian");

cout << "������� ����� ��� ���������� ����������: ";

cin >> n;

cout << "��������� ��� ����� " << n << " = " << factorial (n) << endl;

return 0;
}