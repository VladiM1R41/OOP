#pragma once
#include "point.hpp"
#include "figure.hpp"

template <class T>
class Hexagon final: public Figure<T> {

   protected:
    Point<T> left_lower;
    Point<T> right_lower;
    Point<T> left_middle;
    Point<T> right_middle;
    Point<T> left_upper;
    Point<T> right_upper;

    virtual std::ostream& print(std::ostream& os) const noexcept override {
        os << "Left Lower: " << this -> left_lower << "\n";
        os << "Right Lower: " << this -> right_lower << "\n";
        os << "Left Middle: " << this -> left_middle << "\n";
        os << "Right Middle: " << this -> right_middle << "\n";
        os << "Left Upper: " << this -> left_upper << "\n";
        os << "Right Upper: " << this -> right_upper << "\n";
        return os;
    }

    virtual std::istream& input(std::istream& is) noexcept override {
        std::cout << "Enter left_lower point: ";
        is >> this -> left_lower;
        std::cout << "Enter right_lower point: ";
        is >> this -> right_lower;
        std::cout << "Enter left_middle point: ";
        is >> this -> left_middle;
        std::cout << "Enter right_middle point: ";
        is >> this -> right_middle;
        std::cout << "Enter left_upper point: ";
        is >> this -> left_upper;
        std::cout << "Enter right_upper point: ";
        is >> this -> right_upper;
        return is;
    }

  public:
    Hexagon() = default;
    Hexagon(const Point<T>& _left_lower, const Point<T>& _right_lower, const Point<T>&  _left_middle, const Point<T>& _right_middle, const Point<T>& _left_upper, const Point<T>& _right_upper):left_lower(_left_lower), left_middle(_left_middle), right_lower(_right_lower), right_middle(_right_middle), left_upper(_left_upper), right_upper(_right_upper){}

    virtual T area() const noexcept override {
        T a = Point<T>::line(left_lower, right_lower);
        T b = Point<T>::line(left_lower, left_middle);
        T c = Point<T>::line(right_lower, right_middle);
        T d = Point<T>::line(left_middle, left_upper);
        T e = Point<T>::line(right_middle, right_upper);
        T f = Point<T>::line(left_upper,right_upper);
        T d1 = Point<T>::line(left_middle,right_lower);
        T d2 = Point<T>::line(left_middle,right_middle);
        T d3 = Point<T>::line(left_middle,right_upper);
        T p1 = (a + b + d1)*0.5;
        T p2 = (c + d1 + d2)*0.5;
        T p3 = (e + d2 + d3)*0.5;
        T p4 = (f + d + d3)*0.5;
        T s1 = sqrt(p1*(p1 - a)*(p1 - b)*(p1 - d1));
        T s2 = sqrt(p2*(p2 - c)*(p2 - d1)*(p2 - d2));
        T s3 = sqrt(p3*(p3 - e)*(p3 - d2)*(p3 - d3));
        T s4 = sqrt(p4*(p4 - f)*(p4 - d)*(p4 - d3));
        
        return s1 + s2 + s3 + s4;
    }

    virtual Point<T> center() const noexcept override {
        T X =  (left_lower.x + left_middle.x + right_lower.x + right_middle.x + left_upper.x + right_upper.x)/6.0;
        T Y =  (left_lower.y + left_middle.y + right_lower.y + right_middle.y + left_upper.y + right_upper.y)/6.0;

        return Point<T>(X, Y);
    }

    explicit virtual operator T() const noexcept override {
        return this -> area();
    }

    virtual bool operator==(const Hexagon<T>& other) const  {
 
        return left_lower == other.left_lower && left_middle == other.left_middle && right_lower == other.right_lower && right_middle == other.right_middle && left_upper == other.left_upper && right_upper == other.right_upper;
    }
    virtual bool operator!=(const Hexagon<T>& other) const  {
        return !(*this == other);
    }

};
