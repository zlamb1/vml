#pragma once

#include "macro.hpp"

namespace VML
{
    template<typename T>
    union Mat4 
    {
        T m16[16]; 
        T m4x4[4][4];

        #ifdef USE_ANON_STRUCTS
        struct 
        {
            T m11, m12, m13, m14,
            m21, m22, m23, m24,
            m31, m32, m33, m34,
            m41, m42, m43, m44;
        };
        #endif

        T& operator[](size_t i) 
        {
            ASSERT_RANGE(i, 0, 15); 
            return m16[i]; 
        }

        const T& operator[](size_t i) const 
        {
            ASSERT_RANGE(i, 0, 15); 
            return m16[i];
        }

        Mat4<T> operator+(const Mat4<T>& mat) 
        {
            return {
                m16[0]  + mat.m16[0],  m16[1]  + mat.m16[1],  m16[2]  + mat.m16[2],  m16[3]  + mat.m16[3],
                m16[4]  + mat.m16[4],  m16[5]  + mat.m16[5],  m16[6]  + mat.m16[6],  m16[7]  + mat.m16[7],
                m16[8]  + mat.m16[8],  m16[9]  + mat.m16[9],  m16[10] + mat.m16[10], m16[11] + mat.m16[11],
                m16[12] + mat.m16[12], m16[13] + mat.m16[13], m16[14] + mat.m16[14], m16[15] + mat.m16[15],
            };
        }

        Mat4<T> operator+=(const Mat4<T>& mat) 
        {
            m16 = (this + mat).m16; 
        }

        Mat4<T> operator-(const Mat4<T>& mat) 
        {
            return 
            {
                m16[0]  - mat.m16[0],  m16[1]  - mat.m16[1],  m16[2]  - mat.m16[2],  m16[3]  - mat.m16[3],
                m16[4]  - mat.m16[4],  m16[5]  - mat.m16[5],  m16[6]  - mat.m16[6],  m16[7]  - mat.m16[7],
                m16[8]  - mat.m16[8],  m16[9]  - mat.m16[9],  m16[10] - mat.m16[10], m16[11] - mat.m16[11],
                m16[12] - mat.m16[12], m16[13] - mat.m16[13], m16[14] - mat.m16[14], m16[15] - mat.m16[15],
            };
        }

        Mat4<T> operator-=(const Mat4<T>& mat) 
        {
            m16 = (this - mat).m16; 
        }

        Mat4<T> operator*(const Mat4& mat) 
        {
            return 
            {
                m16[0]  * mat.m16[0] + m16[1]  * mat.m16[4] + m16[2]  * mat.m16[8]  + m16[3]  * mat.m16[12],
                m16[0]  * mat.m16[1] + m16[1]  * mat.m16[5] + m16[2]  * mat.m16[9]  + m16[3]  * mat.m16[13],
                m16[0]  * mat.m16[2] + m16[1]  * mat.m16[6] + m16[2]  * mat.m16[10] + m16[3]  * mat.m16[14],
                m16[0]  * mat.m16[3] + m16[1]  * mat.m16[7] + m16[2]  * mat.m16[11] + m16[3]  * mat.m16[15],
                m16[4]  * mat.m16[0] + m16[5]  * mat.m16[4] + m16[6]  * mat.m16[8]  + m16[7]  * mat.m16[12],
                m16[4]  * mat.m16[1] + m16[5]  * mat.m16[5] + m16[6]  * mat.m16[9]  + m16[7]  * mat.m16[13],
                m16[4]  * mat.m16[2] + m16[5]  * mat.m16[6] + m16[6]  * mat.m16[10] + m16[7]  * mat.m16[14],
                m16[4]  * mat.m16[3] + m16[5]  * mat.m16[7] + m16[6]  * mat.m16[11] + m16[7]  * mat.m16[15],
                m16[8]  * mat.m16[0] + m16[9]  * mat.m16[4] + m16[10] * mat.m16[8]  + m16[11] * mat.m16[12],
                m16[8]  * mat.m16[1] + m16[9]  * mat.m16[5] + m16[10] * mat.m16[9]  + m16[11] * mat.m16[13],
                m16[8]  * mat.m16[2] + m16[9]  * mat.m16[6] + m16[10] * mat.m16[10] + m16[11] * mat.m16[14],
                m16[8]  * mat.m16[3] + m16[9]  * mat.m16[7] + m16[10] * mat.m16[11] + m16[11] * mat.m16[15],
                m16[12] * mat.m16[0] + m16[13] * mat.m16[4] + m16[14] * mat.m16[8]  + m16[15] * mat.m16[12],
                m16[12] * mat.m16[1] + m16[13] * mat.m16[5] + m16[14] * mat.m16[9]  + m16[15] * mat.m16[13],
                m16[12] * mat.m16[2] + m16[13] * mat.m16[6] + m16[14] * mat.m16[10] + m16[15] * mat.m16[14],
                m16[12] * mat.m16[3] + m16[13] * mat.m16[7] + m16[14] * mat.m16[11] + m16[15] * mat.m16[15]
            };
        }

        void operator*=(const Mat4& mat) 
        {
            m16 = (this * mat).m16; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Mat4& mat) 
        {
            for (int r = 0; r < 4; r++) 
            {
                for (int c = 0; c < 4; c++) 
                {
                    os << mat.m4x4[r][c];
                    if (r != 3 || c != 3) os << ", ";
                }
                os << std::endl;
            }
            return os; 
        }
    };

    typedef Mat4<float> Mat4f; 
    typedef Mat4<double> Mat4d; 
    typedef Mat4<int32_t> Mat4i; 
}