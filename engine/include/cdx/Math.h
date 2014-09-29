#pragma once

#include <math.h>


template<typename T>
struct vector2 {

    T x;
    T y;

    // Constructors
    vector2<T>() {}
    vector2<T>(const T x0, const T y0) : x(x0), y(y0) {}

    // Function call operator
    void operator ()(const T x0, const T y0) {
        x = x0;
        y = y0;
    }

    // Equality
    bool operator ==(const vector2<T>& v) {
        return (x == v.x && y == v.y);
    }

    // Inequality
    bool operator !=(const vector2<T>& v) {
        return (x != v.x || y != v.y);
    }

    // Assignment
    const vector2<T>& operator =(const vector2<T>& v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    // Negation
    const vector2<T> operator -(void) const {
        return vector2<T>(-x, -y);
    }

    // Addition
    const vector2<T> operator +(const vector2<T>& v) const {
        return vector2<T>(x + v.x, y + v.y);
    }

    // Subtraction
    const vector2<T> operator -(const vector2<T>& v) const {
        return vector2<T>(x - v.x, y - v.y);
    }

    // Uniform scaling
    const vector2<T> operator *(const T num) const {
        vector2<T> temp(*this);
        return temp *= num;
    }

    // Uniform scaling
    const vector2<T> operator /(const T num) const {
        vector2<T> temp(*this);
        return temp /= num;
    }

    // Addition
    const vector2<T>& operator +=(const vector2<T>& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    // Subtraction
    const vector2<T>& operator -=(const vector2<T>& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    // Uniform scaling
    const vector2<T>& operator *=(const T num) {
        x *= num;
        y *= num;
        return *this;
    }

    // Uniform scaling
    const vector2<T>& operator /=(const T num) {
        x /= num;
        y /= num;
        return *this;
    }

    // Dot product
    T operator *(const vector2<T>& v) const {
        return x * v.x + y * v.y;
    }

};

// Macro to make creating the constructors for derived vectors easier
#define VECTOR2_CONSTRUCTORS(name, type)   \
    name() {}                        \
    name(const vector2<type> &v): vector2<type>(v.x, v.y) {}    \
    name(type x0, type y0): vector2<type>(x0, y0) {}


struct Vec2f : public vector2<float> {
    VECTOR2_CONSTRUCTORS(Vec2f, float)

    // Gets the length of this vector squared
    float length_squared() const {
        return (float) (*this * *this);
    }

    // Gets the length of this vector
    float length() const {
        return (float) sqrt(*this * *this);
    }

    // Normalizes this vector
    void normalize() {
        *this /= length();
    }

    // Returns the normalized vector
    Vec2f normalized() const {
        return *this / length();
    }

    // Truncates the vector if it is longer than a certain length
    void truncate(const float maxLength) {
        if (length_squared() > maxLength * maxLength) {
            normalize();
            *this *= maxLength;
        }
    }

    // Reflects this vector about n
    void reflect(const Vec2f& n) {
        Vec2f orig(*this);
        project(n);
        *this = *this * 2 - orig;
    }

    // Projects this vector onto v
    void project(const Vec2f& v) {
        *this = v * (*this * v) / (v * v);
    }

    // Returns this vector projected onto v
    Vec2f projected(const Vec2f& v) {
        return v * (*this * v) / (v * v);
    }

    // Computes the angle between 2 arbitrary vectors
    static inline float angle(const Vec2f& v1, const Vec2f& v2) {
        return acosf((v1 * v2) / (v1.length() * v2.length()));
    }

    // Computes the angle between 2 normalized arbitrary vectors
    static inline float angle_normalized(const Vec2f& v1, const Vec2f& v2) {
        return acosf(v1 * v2);
    }
};
