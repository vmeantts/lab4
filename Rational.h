#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>

class Rational
{
private:
    int numerator;
    int denominator;

    void simplify();

public:
    // Конструктор
    Rational(int num = 0, int den = 1);

    // Получение числителя и знаменателя
    int Numerator() const;
    int Denominator() const;

    // Бинарные операторы
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // Операции с int
    Rational operator+(int value) const;
    Rational operator-(int value) const;
    Rational operator*(int value) const;
    Rational operator/(int value) const;

    // Унарные операторы
    Rational operator+() const;
    Rational operator-() const;

    // Составные операторы
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    // Сравнение
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    // Вывод
    void print() const;
};

#endif