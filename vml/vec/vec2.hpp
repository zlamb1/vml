#pragma once

#include "macro.hpp"

namespace VML
{
    template<typename T> 
    union Vec2 {
        #ifdef USE_ANON_STRUCTS
        struct { T x, y; };
        struct { T u, v; };
        struct { T width, height; };
        #else
        T x, y;
        #endif 

        T& operator[](size_t i) 
        {
            ASSERT_RANGE(i, 0, 1); 
            switch (i) {
                default:
                case 0: return x;
                case 1: return y; 
            }
        }

        const T& operator[](size_t i) const 
        {
            ASSERT_RANGE(i, 0, 1); 
            switch (i) {
                default:
                case 0: return x;
                case 1: return y; 
            }
        }

        friend bool operator==(const Vec2& vec1, const Vec2& vec2)
        {
            return vec1.x == vec2.x && vec1.y == vec2.y; 
        }

        friend bool operator!=(const Vec2& vec1, const Vec2& vec2)
        {
            return vec1.x != vec2.x || vec1.y != vec2.y; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Vec2& v) 
        {
            os << v.x << ", " << v.y;
            return os;
        }
    };

    typedef Vec2<float> Vec2f;
    typedef Vec2<double> Vec2d; 
    typedef Vec2<int32_t> Vec2i;  
}