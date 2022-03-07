#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    Math Operation;

    int x = 3, y = 5, z = 7;
    double a = 11.5, b = 17.6, c = 11.3;
    char* s;

    //Operatia de adunare a doua numere de tip int
    cout << Operation.Add(x, y) << endl;
    //Operatia de adunare a trei numere de tip int
    cout << Operation.Add(x, y, z) << endl;
    //Operatia de adunare a doua numere de tip double
    cout << Operation.Add(a, b) << endl;
    //Operatia de adunare a trei numere de tip double
    cout << Operation.Add(a, b, c) << endl;
    //Operatia de inmultire a doua numere de tip int
    cout << Operation.Mul(x, y) << endl;
    //Operatia de inmultire a trei numere de tip int
    cout << Operation.Mul(x, y, z) << endl;
    //Operatia de inmultire a doua numere de tip double
    cout << Operation.Mul(a, b) << endl;
    //Operatia de inmultire a trei numere de tip double
    cout << Operation.Mul(a, b, c) << endl;
    //adunarea numerelor dintr-o lista cu argumente variabile
    cout << Operation.Add(10, 15, 22, 35, 41, 50, 6, 7, 18, 99) << endl;
    //concatenarea a doua siruri de caractere
    s = Operation.Add("This is the first exercise ", "for the OOP lab3");
    cout << s;
    delete[] s;
    return 0;
}
