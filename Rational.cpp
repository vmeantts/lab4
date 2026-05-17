#include "Rational.h"

using namespace std;

// Конструктор
Rational::Rational(int num, int den)
{
    if (den == 0)
    {
        cout << "Ошибка: знаменатель не может быть равен 0.\n";
        den = 1;
    }

    numerator = num;
    denominator = den;

    simplify();
}

// Сокращение дроби
void Rational::simplify()
{
    int divisor = gcd(numerator, denominator);

    numerator /= divisor;
    denominator /= divisor;

    // Знаменатель всегда положительный
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Получение числителя
int Rational::Numerator() const
{
    return numerator;
}

// Получение знаменателя
int Rational::Denominator() const
{
    return denominator;
}

// Сложение
Rational Rational::operator+(const Rational& other) const
{
    int num = numerator * other.denominator +
        other.numerator * denominator;

    int den = denominator * other.denominator;

    return Rational(num, den);
}

// Вычитание
Rational Rational::operator-(const Rational& other) const
{
    int num = numerator * other.denominator -
        other.numerator * denominator;

    int den = denominator * other.denominator;

    return Rational(num, den);
}

// Умножение
Rational Rational::operator*(const Rational& other) const
{
    return Rational(
        numerator * other.numerator,
        denominator * other.denominator
    );
}

// Деление
Rational Rational::operator/(const Rational& other) const
{
    return Rational(
        numerator * other.denominator,
        denominator * other.numerator
    );
}

// Операции с int
Rational Rational::operator+(int value) const
{
    return Rational(
        numerator + value * denominator,
        denominator
    );
}

Rational Rational::operator-(int value) const
{
    return Rational(
        numerator - value * denominator,
        denominator
    );
}

Rational Rational::operator*(int value) const
{
    return Rational(
        numerator * value,
        denominator
    );
}

Rational Rational::operator/(int value) const
{
    return Rational(
        numerator,
        denominator * value
    );
}

// Унарный плюс
Rational Rational::operator+() const
{
    return *this;
}

// Унарный минус
Rational Rational::operator-() const
{
    return Rational(-numerator, denominator);
}

// +=
Rational& Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

// -=
Rational& Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    return *this;
}

// *=
Rational& Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

// /=
Rational& Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    return *this;
}

// ==
bool Rational::operator==(const Rational& other) const
{
    return numerator == other.numerator &&
        denominator == other.denominator;
}

// !=
bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

// Вывод
void Rational::print() const
{
    cout << numerator << "/" << denominator;
}