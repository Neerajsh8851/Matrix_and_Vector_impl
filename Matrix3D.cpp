//
// Created by Neeraj sharma on 23-07-2020.
//
//#ifndef MATRIX_3D_CPP
//#define MATRIX_3D_CPP

#include "Vector3D.cpp"

struct Matrix3D
{
private:
    float  M[3][3]{};

public:
    Matrix3D() = default;

    Matrix3D(const Vector3D& v0, const Vector3D& v1, const Vector3D& v2)
    {
        M[0][0] = v0.x; M[0][1] = v0.y; M[0][2] = v0.z;
        M[1][0] = v1.x; M[1][1] = v1.y; M[1][2] = v1.z;
        M[2][0] = v2.x; M[2][1] = v2.y; M[2][2] = v2.z;
    }

    Matrix3D (float n00, float n01, float n02,
              float n10, float n11, float n12,
              float n20, float n21, float n22)
    {
        M[0][0] = n00; M[0][1] = n10; M[0][2] = n20;
        M[1][0] = n01; M[1][1] = n11; M[1][2] = n21;
        M[2][0] = n02; M[2][1] = n12; M[2][2] = n22;
    }

    float& operator () (int i, int j)
    {
        return M[j][i];
    }

    const float& operator () (int i, int j) const
    {
        return M[j][i];
    }

    Vector3D& operator [] (int j)
    {
        return (*reinterpret_cast<Vector3D *>(M[j]));
    }

    const Vector3D& operator [] (int j) const
    {
        return (*reinterpret_cast<const Vector3D *>(M[j]));
    }
};

// 3x3 Matrix multiplication
inline Matrix3D operator * (const Matrix3D& m1 , const Matrix3D& m2 )
{
    return  {
            m1(0,0)*m2(0,0) + m1(0,1)*m2(1,0) + m1(0,2)*m2(2,0),
            m1(0,0)*m2(0,1) + m1(0,1)*m2(1,1) + m1(0,2)*m2(2,1),
            m1(0,0)*m2(0,2) + m1(0,1)*m2(1,2) + m1(0,2)*m2(2,2),
            m1(1,0)*m2(0,0) + m1(1,1)*m2(1,0) + m1(1,2)*m2(2,0),
            m1(1,0)*m2(0,1) + m1(1,1)*m2(1,1) + m1(1,2)*m2(2,1),
            m1(1,0)*m2(0,2) + m1(1,1)*m2(1,2) + m1(1,2)*m2(2,2),
            m1(2,0)*m2(0,0) + m1(2,1)*m2(1,0) + m1(2,2)*m2(2,0),
            m1(2,0)*m2(0,1) + m1(2,1)*m2(1,1) + m1(2,2)*m2(2,1),
            m1(2,0)*m2(0,2) + m1(2,1)*m2(1,2) + m1(2,2)*m2(2,2)
            };
}

// Matrix M * vector v = another Vector
inline Vector3D operator * (const Matrix3D& m , const Vector3D& v)
{
    return  {
            m(0,0)*v.x + m(0,1)*v.y + m(0,2)*v.z,
            m(1,0)*v.x + m(1,1)*v.y + m(1,2)*v.z,
            m(2,0)*v.x + m(2,1)*v.y + m(2,2)*v.z
            };
}

//#endif