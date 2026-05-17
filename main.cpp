#include "Complex.h"
#include <iostream>
using namespace std;


int main() {
    setlocale(LC_ALL, "RU");

    Complex a, b;

    cout << "Ввод комплексного числа A:\n";
    cin >> a;

    cout << "Ввод комплексного числа B:\n";
    cin >> b;

    cout << "\nA = " << a << endl;
    cout << "B = " << b << endl;

    cout << "\nA + B = " << a + b << endl;
    cout << "A - B = " << a - b << endl;
    cout << "A * B = " << a * b << endl;
    cout << "A / B = " << a / b << endl;

    cout << "\n++A = " << ++a << endl;
    cout << "A++ = " << a++ << endl;
    cout << "A после A++ = " << a << endl;

    cout << "\nСравнение:\n";
    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a == b) << endl;

    Complex c = a; // тест копирования
    cout << "\nКопия C = " << c << endl;

    return 0;
}