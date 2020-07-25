
// Created by Neeraj sharma on 23-07-2020.

#ifndef VECTOR_3D_CPP
#define VECTOR_3D_CPP
#include <cmath>


struct Vector3D
{
    float x,y,z;

    Vector3D() = default;

    Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    float& operator[] (int i)
    {
        return ((&x) [i]);
    }

    const float& operator[] (int i) const
    {
        return ((&x) [i]);
    }

    Vector3D& operator /= (float s)
    {
        s = 1.f/s;
        x *= s;
        y *= s;
        z *= s;
        return *(this);
    }

    Vector3D& operator *= (float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *(this);
    }

    // vector addition and subtraction
    Vector3D& operator += (const Vector3D& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *(this);
    }

    Vector3D& operator -= (const Vector3D& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *(this);
    }

};


inline Vector3D operator / (const Vector3D& v , float s)
{
    s = 1.f/s;
    return {v.x*s, v.y*s, v.z*s};
}

inline Vector3D operator * (const Vector3D& v, float s )
{
    return {v.z*s, v.y*s, v.z*s};
}

inline Vector3D operator - (const Vector3D& v)
{
    return {-v.z, -v.y, -v.z};
}

inline Vector3D operator + (const Vector3D& v1, const Vector3D& v2)
{
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

inline Vector3D operator - (const Vector3D& v1, const Vector3D v2)
{
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};

}

// magnitude
inline float magnitude (const Vector3D v)
{
    return  std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

// unit vector
inline Vector3D normalize(const Vector3D& v)
{
    return (v / magnitude(v));
}

 //Vector dot product
inline float dot(const Vector3D& a, const Vector3D& b)
{
    return (a.x * b.x + a.y*b.y + a.z*b.z);
}

inline Vector3D cross(const Vector3D& a, const Vector3D& b)
{
    return {
            a.y*b.z - a.z*b.y,
            a.z*b.x - a.x*b.z,
            a.x*b.y - a.y*b.x
            };
}

#endif// VECTOR_3D_CPP

