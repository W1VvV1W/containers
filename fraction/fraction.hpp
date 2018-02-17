/*
@author - Duzhinsky D.E. ( github - W1VvV1W)
@date - Feb. 2018
@license - MIT.
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <numeric>
#include <cmath>

#include <stdint.h>

/** GCD and LCM from stack overflow :3
*  If you are going to include this file to your project,
*  include a file with your gcd and lcm declaration to avoid errors
*/

template<typename T>
T gcd(T a, T b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

template<typename T>
T lcm(T a, T b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

template<typename T>
class Fraction {
  public:
    T numerator = 0, denominator = 0;

    Fraction() {}
    Fraction(Fraction& rhs) { numerator = rhs.numerator; denominator = rhs.denominator; }
    Fraction(T& numerator_a, T& denominator_a) : numerator(numerator_a), denominator(denominator_a) {}
    Fraction(const T&& numerator_a, const T&& denominator_a) : numerator(numerator_a), denominator(denominator_a) {}
    ~Fraction() {}

    T common_denominator_with(Fraction& rhs) { return lcm<T>(this->denominator, rhs.denominator); }
    void reduce_to_common_denominator_with(Fraction& rhs);
    void reduce();
    uint64_t integer_part() { return uint64_t((float)numerator/(float)denominator - 0.5); }
    void power(long double exp) { std::pow(numerator, exp); std::pow(denominator, exp); }

    bool operator!=(Fraction& rhs);
    bool operator==(Fraction& rhs);
    bool operator>=(Fraction& rhs);
    bool operator<=(Fraction& rhs);
    bool operator> (Fraction& rhs);
    bool operator< (Fraction& rhs);

    Fraction operator- ();
    Fraction operator+ ();
    Fraction operator++();
    Fraction operator--();

    Fraction operator-=(Fraction& rhs);
    Fraction operator+=(Fraction& rhs);
    Fraction operator- (Fraction& rhs);
    Fraction operator+ (Fraction& rhs);

    Fraction operator/=(Fraction& rhs);
    Fraction operator*=(Fraction& rhs);
    Fraction operator/ (Fraction& rhs);
    Fraction operator* (Fraction& rhs);
};

template<typename T>
void Fraction<T>::reduce() {
    T div = gcd<T>(numerator, denominator);
    numerator /= div;
    denominator /= div;
}

template<typename T>
void Fraction<T>::reduce_to_common_denominator_with(Fraction<T>& rhs) {
    int low_com_sub = lcm<T>(this->denominator, rhs.denominator);
    this->numerator *= low_com_sub/this->denominator;
    rhs.numerator *= low_com_sub/rhs.denominator;
    this->denominator = low_com_sub;
    rhs.denominator = low_com_sub;
}

template<typename T>
bool Fraction<T>::operator!=(Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator != rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) != rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
bool Fraction<T>::operator==(Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator == rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) == rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
bool Fraction<T>::operator>=(Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator >= rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) >= rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
bool Fraction<T>::operator<=(Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator <= rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) <= rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
bool Fraction<T>::operator> (Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator > rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) > rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
 bool Fraction<T>::operator< (Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator < rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) < rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
Fraction<T> Fraction<T>::operator- () {
    numerator = -numerator;
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator+ () {
    numerator = +numerator;
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator++() {
    this->numerator += this->denominator;
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator--() {
    this->numerator -= this->denominator;
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator-=(Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator)
        this->numerator -= rhs.numerator;
    else {
        this->reduce_to_common_denominator_with(rhs);
        this->numerator -= rhs.numerator;
    }
    this->reduce();
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator+=(Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator)
        this->numerator += rhs.numerator;
    else {
        this->reduce_to_common_denominator_with(rhs);
        this->numerator += rhs.numerator;
    }
    this->reduce();
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator- (Fraction<T>& rhs) {
    Fraction<T> tmp(*this);
    if(this->denominator == rhs.denominator)
        tmp.numerator -= rhs.numerator;
    else {
        tmp.reduce_to_common_denominator_with(rhs);
        tmp.numerator -= rhs.numerator;
    }
    tmp.reduce();
    return tmp;
}

template<typename T>
Fraction<T> Fraction<T>::operator+ (Fraction<T>& rhs) {
    Fraction<T> tmp(*this);
    if(this->denominator == rhs.denominator)
        tmp.numerator += rhs.numerator;
    else {
        tmp.reduce_to_common_denominator_with(rhs);
        tmp.numerator += rhs.numerator;
    }
    tmp.reduce();
    return tmp;
}

template<typename T>
Fraction<T> Fraction<T>::operator/=(Fraction<T>& rhs) {
    this->numerator *= rhs.denominator;
    this->denominator *= rhs.numerator;
    this->reduce();
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator*=(Fraction<T>& rhs) {
    this->numerator *= rhs.numerator;
    this->denominator *= rhs.denominator;
    this->reduce();
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator/ (Fraction<T>& rhs) {
    Fraction<T> tmp(*this);
    tmp.numerator *= rhs.denominator;
    tmp.denominator *= rhs.numerator;
    tmp.reduce();
    return tmp;
}

template<typename T>
Fraction<T> Fraction<T>::operator* (Fraction<T>& rhs) {
    Fraction<T> tmp(*this);
    tmp.numerator *= rhs.numerator;
    tmp.denominator *= rhs.denominator;
    tmp.reduce();
    return tmp;
}

template<typename T>
T common_denominator_with(Fraction<T>& lhs, Fraction<T>& rhs) {
    return lhs.common_denominator_with(rhs);
}

template<typename T>
void reduce_to_common_denominator_with(Fraction<T>& lhs, Fraction<T>& rhs) {
    lhs.reduce_to_common_denominator_with(rhs);
}

template<typename T>
void reduce(Fraction<T>& rhs) {
    rhs.reduce();
}

template<typename T>
uint64_t integer_part(Fraction<T>& rhs) {
    return rhs.integer_part();
}

namespace std {
    template<typename T>
    void pow(Fraction<T>& rhs, long double exp) {
        std::pow(rhs.numerator, exp);
        std::pow(rhs.denominator, exp);
    }
}


#endif // FRACTION_H
