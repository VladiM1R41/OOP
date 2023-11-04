#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class Point {
    public:
        T x;
        T y;
    
        Point();
        Point(const T _x, const T _y): x(_x), y(_y){}

        bool operator==(const Point<T>& other) const noexcept{
            return x == other.x && y == other.y;
        }
        bool operator!=(const Point<T>& other) const noexcept {
            return !(*this == other);
        }


        friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) noexcept {
            os << "(" << point.x << ", " << point.y << ")";
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Point<T>& point) noexcept {
            is >> point.x >> point.y;
            return is;
        }
        
        static T line(const Point<T>& p1, const Point<T>& p2) noexcept{
            T dx = p2.x - p1.x;
            T dy = p2.y - p1.y;
            return std::sqrt(dx*dx + dy*dy);
        }
};