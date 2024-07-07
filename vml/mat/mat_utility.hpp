#pragma once

#include "mat3.hpp"
#include "mat4.hpp"

namespace VML
{
    static Mat3f IdentityMat3f() 
    {
        return 
        {
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f
        };
    }

    static Mat4f IdentityMat4f() 
    {
        return 
        {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };
    }

    static Mat4f CreateOrthoProjectionf(float left, float right, float bottom, float top, float near, float far) 
    {
        return 
        {
            2.0f / (right - left), 0.0f, 0.0f, -(right + left) / (right - left),
            0.0f, 2.0f / (top - bottom), 0.0f, -(top + bottom) / (top - bottom),
            0.0f, 0.0f, 2.0f / (far - near), -(far + near) / (far - near),
            0.0f, 0.0f, 0.0f, 1.0f
        };
    }

    template<typename T>
    static Mat3<T> TransposeMat3(const Mat3<T>& mat) 
    {
        return 
        {
            mat.m9[0], mat.m9[3], mat.m9[6],
            mat.m9[1], mat.m9[4], mat.m9[7],
            mat.m9[2], mat.m9[5], mat.m9[8]
        };
    }

    template<typename T> 
    static Mat4<T> TransposeMat4(const Mat4<T> mat) 
    {
        return 
        {
            mat.m16[0], mat.m16[4], mat.m16[8],  mat.m16[12],
            mat.m16[1], mat.m16[5], mat.m16[9],  mat.m16[13],
            mat.m16[2], mat.m16[6], mat.m16[10], mat.m16[14],
            mat.m16[3], mat.m16[7], mat.m16[11], mat.m16[15]
        };
    }
}