#pragma once

#include "macro.hpp"

namespace VML
{
    template<typename T>
    union Vec4 {
        #ifdef USE_ANON_STRUCTS
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        struct { T s, t, p, q; };
        #else
        T x, y, z, w;
        #endif

        T& operator[](size_t i) 
        {
            ASSERT_RANGE(i, 0, 3); 
            switch (i) {
                default:
                case 0: return x;
                case 1: return y; 
                case 2: return z;
                case 3: return w; 
            }
        }

        const T& operator[](size_t i) const 
        {
            ASSERT_RANGE(i, 0, 3); 
            switch (i) {
                default:
                case 0: return x;
                case 1: return y; 
                case 2: return z; 
                case 3: return w; 
            }
        }

        friend bool operator==(const Vec4& vec1, const Vec4& vec2)
        {
            return vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.y && vec1.w == vec2.w;
        }

        friend bool operator!=(const Vec4& vec1, const Vec4& vec2)
        {
            return vec1.x != vec2.x || vec1.y != vec2.y || vec1.z != vec2.z || vec1.w != vec2.w; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec4& v) 
        {
            os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
            return os;
        }
    };

    typedef Vec4<float> Vec4f;
    typedef Vec4<double> Vec4d; 
    typedef Vec4<int32_t> Vec4i; 
}