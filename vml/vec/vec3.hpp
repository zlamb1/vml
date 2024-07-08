#pragma once

#include "vml/macro.hpp"

namespace VML
{
    template<typename T>
    union Vec3 {
        #ifdef USE_ANON_STRUCTS
        struct { T x, y, z; };
        struct { T r, g, b; };
        #else
        T x, y, z; 
        #endif

        T& operator[](size_t i) 
        {
            ASSERT_RANGE(i, 0, 2); 
            switch (i) {
                default:
                case 0: return x;
                case 1: return y; 
                case 2: return z;
            }
        }

        const T& operator[](size_t i) const 
        {
            ASSERT_RANGE(i, 0, 2);
            switch (i) {
                default:
                case 0: return x;
                case 1: return y; 
                case 2: return z; 
            }
        }

        friend bool operator==(const Vec3& vec1, const Vec3& vec2)
        {
            return vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z;
        }

        friend bool operator!=(const Vec3& vec1, const Vec3& vec2)
        {
            return vec1.x != vec2.x || vec1.y != vec2.y || vec1.z != vec2.z; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec3& v) 
        {
            os << v.x << ", " << v.y << ", " << v.z;
            return os;
        }
    };

    typedef Vec3<float> Vec3f;
    typedef Vec3<double> Vec3d; 
    typedef Vec3<int32_t> Vec3i; 
}