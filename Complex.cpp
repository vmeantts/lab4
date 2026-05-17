#include "Complex.h"
#include <cmath>

// конструкторы
Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(int x, int y) {
    re = x;
    im = y;
}

// копирование
Complex::Complex(const Complex& other) {
    re = other.re;
    im = other.im;
}

// присваивание
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

// сложение
Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

// вычитание
Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

// умножение
Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im,
        re * other.im + im * other.re);
}

// деление
Complex Complex::operator/(const Complex& other) const {
    int denom = other.re * other.re + other.im * other.im;
    return Complex(
        (re * other.re + im * other.im) / denom,
        (im * other.re - re * other.im) / denom
    );
}

// ++ префикс
Complex& Complex::operator++() {
    re++;
    im++;
    return *this;
}

// ++ постфикс
Complex Complex::operator++(int) {
    Complex temp = *this;
    re++;
    im++;
    return temp;
}

// -- префикс
Complex& Complex::operator--() {
    re--;
    im--;
    return *this;
}

// -- постфикс
Complex Complex::operator--(int) {
    Complex temp = *this;
    re--;
    im--;
    return temp;
}

// модуль
double Complex::modulus() const {
    return sqrt(re * re + im * im);
}

// сравнения
bool Complex::operator>(const Complex& other) const {
    return modulus() > other.modulus();
}

bool Complex::operator<(const Complex& other) const {
    return modulus() < other.modulus();
}

bool Complex::operator==(const Complex& other) const {
    return modulus() == other.modulus();
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// ввод
istream& operator>>(istream& in, Complex& c) {
    cout << "Введите действительную часть: ";
    in >> c.re;
    cout << "Введите мнимую часть: ";
    in >> c.im;
    return in;
}

// вывод
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.re << " + " << c.im << "*i";
    return out;
}