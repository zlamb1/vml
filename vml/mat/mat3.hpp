#pragma once

#include <iostream>

#include "vml/vec/vec3.hpp"
#include "vml/macro.hpp"

namespace VML
{
    template<typename T>
    union Mat3 
    {
        T m9[9]; 
        T m3x3[3][3]; 

        #ifdef USE_ANON_STRUCTS
        struct {
            T m11, m12, m13,
            m21, m22, m23,
            m31, m32, m33;
        };
        #endif

        T& operator[](size_t i) 
        {
            ASSERT_RANGE(i, 0, 8); 
            return m9[i]; 
        }

        const T& operator[](size_t i) const 
        {
            ASSERT_RANGE(i, 0, 8); 
            return m9[i]; 
        }

        Mat3<T> operator+(const Mat3<T>& mat) 
        {
            return {
                m9[0] + mat.m9[0], m9[1] + mat.m9[1], m9[2] + mat.m9[2],
                m9[3] + mat.m9[3], m9[4] + mat.m9[4], m9[5] + mat.m9[5],
                m9[6] + mat.m9[6], m9[7] + mat.m9[7], m9[8] + mat.m9[8]
            };
        }

        Mat3<T> operator+=(const Mat3<T>& mat) 
        {
            m9 = (this + mat).m9; 
        }

        Mat3<T> operator-(const Mat3<T>& mat) 
        {
            return 
            {
                m9[0] - mat.m9[0], m9[1] - mat.m9[1], m9[2] - mat.m9[2],
                m9[3] - mat.m9[3], m9[4] - mat.m9[4], m9[5] - mat.m9[5],
                m9[6] - mat.m9[6], m9[7] - mat.m9[7], m9[8] - mat.m9[8]
            };
        }

        Mat3<T> operator-=(const Mat3<T>& mat) 
        {
            m9 = (this - mat).m9; 
        }

        Vec3<T> operator*(const Vec3<T>& vec) 
        {
            return 
            {
                m9[0] * vec[0] + m9[1] * vec[1] + m9[2] * vec[2],
                m9[3] * vec[0] + m9[4] * vec[1] + m9[5] * vec[2],
                m9[6] * vec[0] + m9[7] * vec[1] + m9[8] * vec[2]
            };
        }

        Mat3<T> operator*(const Mat3<T>& mat) 
        {
            return 
            {
                m9[0] * mat.m9[0] + m9[1] * mat.m9[3] + m9[2] * mat.m9[6],
                m9[0] * mat.m9[1] + m9[1] * mat.m9[4] + m9[2] * mat.m9[7],
                m9[0] * mat.m9[2] + m9[1] * mat.m9[5] + m9[2] * mat.m9[8],
                m9[3] * mat.m9[0] + m9[4] * mat.m9[3] + m9[5] * mat.m9[6],
                m9[3] * mat.m9[1] + m9[4] * mat.m9[4] + m9[5] * mat.m9[7],
                m9[3] * mat.m9[2] + m9[4] * mat.m9[5] + m9[5] * mat.m9[8],
                m9[6] * mat.m9[0] + m9[7] * mat.m9[3] + m9[8] * mat.m9[6],
                m9[6] * mat.m9[1] + m9[7] * mat.m9[4] + m9[8] * mat.m9[7],
                m9[6] * mat.m9[2] + m9[7] * mat.m9[5] + m9[8] * mat.m9[8]
            };
        }

        void operator*=(Mat3 const& mat) 
        {
            m9 = (this * mat).m9; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Mat3& mat) 
        {
            for (int r = 0; r < 3; r++) 
            {
                for (int c = 0; c < 3; c++) 
                {
                    os << mat.m3x3[r][c];
                    if (r != 2 || c != 2) os << ", ";
                }
                os << std::endl;
            }
            return os; 
        }
    };

    typedef Mat3<float> Mat3f; 
    typedef Mat3<double> Mat3d; 
    typedef Mat3<int32_t> Mat3i; 
}