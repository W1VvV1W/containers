/*
@author - Duzhinsky D.E. ( github - W1VvV1W)
@date - Feb. 2018
@license - MIT.
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <numeric>

/* GCD and LCM from stack overflow :3
*  If you are including this file to your project
*  include a file with your gcd and lcm to avoid errors
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
    Fraction(Fraction& rhs) { *this = rhs; }
    Fraction(T& numerator_a, T& denominator_a) : numerator(numerator_a), denominator(denominator_a) {}
    Fraction(const T& numerator_a, const T& denominator_a) : numerator(numerator_a), denominator(denominator_a) {}
    ~Fraction() {}

    T common_denominator_with(Fraction& rhs) { return lcm<T>(this->denominator, rhs.denominator); }
    void reduce_to_common_denominator_with(Fraction& rhs);
    void reduce();

    const bool operator!=(const Fraction& rhs);
    const bool operator==(const Fraction& rhs);
    const bool operator>=(const Fraction& rhs);
    const bool operator<=(const Fraction& rhs);
    const bool operator> (const Fraction& rhs);
    const bool operator< (const Fraction& rhs);

    Fraction operator- ();
    Fraction operator+ ();
    Fraction operator++();
    Fraction operator--();

    Fraction operator-=(const Fraction& rhs);
    Fraction operator+=(const Fraction& rhs);
    Fraction operator- (const Fraction& rhs);
    Fraction operator+ (const Fraction& rhs);

    Fraction operator/=(const Fraction& rhs);
    Fraction operator*=(const Fraction& rhs);
    Fraction operator/ (const Fraction& rhs);
    Fraction operator* (const Fraction& rhs);

};

template<typename T>
void Fraction<T>::reduce() {
    int div = gcd(this->numerator, this->denominator);
    numerator /= div;
    denominator /= div;
}

template<typename T>
void Fraction<T>::reduce_to_common_denominator_with(Fraction<T>& rhs) {
    T common_denominator = common_denominator_with(rhs);
    this->numerator = common_denominator/this->denominator * this->numerator;
    rhs.numerator = common_denominator/rhs.denominator * rhs.numerator;
    this->denominator = common_denominator;
    rhs.denominator = common_denominator;
}

template<typename T>
const bool Fraction<T>::operator!=(const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator != rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) != rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
const bool Fraction<T>::operator==(const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator == rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) == rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
const bool Fraction<T>::operator>=(const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator >= rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) >= rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
const bool Fraction<T>::operator<=(const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator <= rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) <= rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
const bool Fraction<T>::operator> (const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator) return this->numerator > rhs.numerator;
    T common_denominator = common_denominator_with(rhs);
    return this->numerator*(common_denominator/this->denominator) > rhs.numerator*(common_denominator/rhs.denominator);
}

template<typename T>
const bool Fraction<T>::operator< (const Fraction<T>& rhs) {
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
Fraction<T> Fraction<T>::operator-=(const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator)
        return this->numerator -= rhs.numerator;
    this->reduce_to_common_denominator_with(rhs);
    this->numerator-=rhs.numerator;
}

template<typename T>
Fraction<T> Fraction<T>::operator+=(const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator)
        return this->numerator += rhs.numerator;
    this->reduce_to_common_denominator_with(rhs);
    this->numerator+=rhs.numerator;
}

template<typename T>
Fraction<T> Fraction<T>::operator- (const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator)
        return Fraction<T>(this->numerator - rhs.numerator, this->denominator);
    Fraction<T> tmp;
    tmp.reduce_to_common_denominator_with(rhs);
    tmp.numerator -= rhs.numerator;
    return tmp;
}

template<typename T>
Fraction<T> Fraction<T>::operator+ (const Fraction<T>& rhs) {
    if(this->denominator == rhs.denominator)
        return Fraction<T>(this->numerator + rhs.numerator, this->denominator);
    Fraction<T> tmp;
    tmp.reduce_to_common_denominator_with(rhs);
    tmp.numerator += rhs.numerator;
    return tmp;

}

template<typename T>
Fraction<T> Fraction<T>::operator/=(const Fraction<T>& rhs) {
    this->numerator *= rhs.denominator;
    this->denominator *= rhs.numerator;
    this->reduce();
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator*=(const Fraction<T>& rhs) {
    this->numerator *= rhs.numerator;
    this->denominator *= rhs.denominator;
    this->reduce();
    return *this;
}

template<typename T>
Fraction<T> Fraction<T>::operator/ (const Fraction<T>& rhs) {
    return Fraction<T>(this->numerator * rhs.denominator, this->denominator * numerator).reduce();
}

template<typename T>
Fraction<T> Fraction<T>::operator* (const Fraction<T>& rhs) {
    return Fraction<T>(this->numerator * rhs.numerator, this->denominator * rhs.denominator).reduce();
}

#endif // FRACTION_H
