#ifndef VECTOR_3
#define VECTOR_3

/*
@author - Duzhinsky D.E. ( github - W1VvV1W )
@date - 06.02.2018
*/

#include <initializer_list>
#include <stdexcept>
#include <cassert>

#include <math.h>

template<typename T>
struct Vector3 {
    T x = 0, y = 0, z = 0;

    Vector3() {}
    Vector3(Vector3& rhs) { *this = rhs; }
    Vector3(T& x_a, T& y_a, T& z_a)
                : x(x_a), y(y_a), z(z_a) {}
    Vector3(const T&& x_a, const T&& y_a, const T&& z_a)
                : x(x_a), y(y_a), z(z_a) {}
    Vector3(std::initializer_list<T> rhs);
    ~Vector3() {}
    Vector3& operator=(Vector3& rhs);

    double abs();
    void normalize();

    Vector3& operator+=(Vector3& rhs);
    Vector3  operator+ (Vector3& rhs);
    Vector3& operator-=(Vector3& rhs);
    Vector3  operator- (Vector3& rhs);
    Vector3& operator*=(double scalar);
    Vector3  operator* (double scalar);
};

template<typename T>
Vector3<T>::Vector3(std::initializer_list<T> rhs) {
    assert(rhs.size() <= 3);
    if(rhs.size() >= 1)
        x = *rhs.begin();
    if(rhs.size() >= 2)
        y = *(rhs.begin() + 1);
    if(rhs.size() == 3)
        z = *(rhs.begin() + 2);
}

template<typename T>
Vector3<T>& Vector3<T>::operator=(Vector3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    return *this;
}

template<typename T>
double Vector3<T>::abs() {
    return sqrt(x*x + y*y + z*z);
}

template<typename T>
void Vector3<T>::normalize() {
    double inv_abs = 1/abs();
    x *= inv_abs;
    y *= inv_abs;
    z *= inv_abs;
}
template<typename T>
Vector3<T>& Vector3<T>::operator+=(Vector3& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

template<typename T>
Vector3<T>  Vector3<T>::operator+ (Vector3& rhs) {
    return Vector3(this->x + rhs.x, this->y + rhs.y, this->z += rhs.z);
}

template<typename T>
Vector3<T>& Vector3<T>::operator-=(Vector3& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}

template<typename T>
Vector3<T>  Vector3<T>::operator- (Vector3& rhs) {
    return Vector3()+rhs;
}

template<typename T>
Vector3<T>&  Vector3<T>::operator*=(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

template<typename T>
Vector3<T>  Vector3<T>::operator* (double scalar) {
    return Vector3()*scalar;
}

#endif
