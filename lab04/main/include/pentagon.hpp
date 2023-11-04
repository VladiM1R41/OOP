#pragma once
#include "point.hpp"
#include "figure.hpp"

template <class T>
class Pentagone final: public Figure<T> {

   protected:
    Point<T> left_lower;
    Point<T> right_lower;
    Point<T> left_middle;
    Point<T> right_middle;
    Point<T> upper;

    virtual std::ostream& print(std::ostream& os) const noexcept override {
        os << " , " << this -> left_lower << " , "<< this -> right_lower << " , "<< this -> left_middle << " , "<< this -> right_middle << " , " << this -> upper << "\n";
        return os;
    }
    virtual std::istream& input(std::istream& is) noexcept override {
        is >> this -> left_lower>> this -> right_lower >> this -> left_middle >> this -> right_middle >> this -> upper;
        return is;
    }

  public:
    Pentagone() = default;
    Pentagone(const Point<T>& _left_lower, const Point<T>& _right_lower, const Point<T>&  _left_middle, const Point<T>& _right_middle, const Point<T>& _upper):left_lower(_left_lower), left_middle(_left_middle), right_lower(_right_lower), right_middle(_right_middle), upper(_upper){}

    virtual T area() const noexcept override {
        T a = Point<T>::line(left_middle, left_lower);
        T b = Point<T>::line(right_middle, right_lower);
        T c = Point<T>::line(right_lower, left_lower);
        T d = Point<T>::line(upper, right_middle);
        T e = Point<T>::line(upper, left_middle);
        T q = Point<T>::line(upper, left_lower);
        T w = Point<T>::line(upper, right_lower);
        T p1 = (a + e + q)*0.5;
        T p2 = (c + q + w)*0.5;
        T p3 = (b + d + w)*0.5;
        T s1 = sqrt(p1*(p1 - a)*(p1 - e)*(p1 - q));
        T s2 = sqrt(p2*(p2 - c)*(p2 - q)*(p2 - w));
        T s3 = sqrt(p3*(p3 - b)*(p3 - d)*(p3 - w)); 
        return s1 + s2 + s3;
    }

    virtual Point<T> center() const noexcept override {
        T X =  (left_lower.x + left_middle.x + right_lower.x + right_middle.x + upper.x)*0.2;
        T Y =  (left_lower.y + left_middle.y + right_lower.y + right_middle.y + upper.y)*0.2;

        return Point<T>(X, Y);
    }

    explicit virtual operator T() const noexcept override {
        return this -> area();
    }

    virtual bool operator==(const Pentagone<T>& other) const {
 
        return left_lower == other.left_lower && left_middle == other.left_middle && right_lower == other.right_lower && right_middle == other.right_middle && upper == other.upper;
    }
    virtual bool operator!=(const Pentagone<T>& other) const  {
        return !(*this == other);
    }

};
