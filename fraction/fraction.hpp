#ifndef FRACTION_H
#define FRACTION_H

template<typename T>
class Fraction {
  public:
    T numerator = 0, denominator = 0;

    Fraction() {}
    Fraction(Fraction& rhs) { *this = rhs; }
    Fraction(T& numerator_a, T& denominator_a) : numerator(numerator_a), denominator(denominator_a) {}
    Fraction(const T& numerator_a, const T& denominator_a) : numerator(numerator_a), denominator(denominator_a) {}
    ~Fraction() {}

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
    Fraction operator++(const Fraction& rhs);
    Fraction operator--(const Fraction& rhs);

    Fraction operator-=(const Fraction& rhs);
    Fraction operator+=(const Fraction& rhs);
    Fraction operator- (const Fraction& rhs);
    Fraction operator+ (const Fraction& rhs);

    Fraction operator/=(const Fraction& rhs);
    Fraction operator*=(const Fraction& rhs);
    Fraction operator/ (const Fraction& rhs);
    Fraction operator* (const Fraction& rhs);

};


#endif // FRACTION_H
