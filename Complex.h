#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
private:
    int re; // действительная часть
    int im; // мнимая часть

public:
    // конструкторы
    Complex();                 // по умолчанию
    Complex(int x, int y);     // с параметрами

    // копирование
    Complex(const Complex& other);

    // оператор присваивания
    Complex& operator=(const Complex& other);

    // арифметика
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // ++ и --
    Complex& operator++();    // префикс
    Complex operator++(int);  // постфикс
    Complex& operator--();
    Complex operator--(int);

    // сравнение по модулю
    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // ввод-вывод
    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);

    double modulus() const; // модуль числа
};

#endif