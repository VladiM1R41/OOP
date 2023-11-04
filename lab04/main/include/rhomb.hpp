#pragma once

#include "point.hpp"
#include "figure.hpp"

template <class T>
class Rhomb final: public Figure<T> {
    
  protected:
    Point<T> upper;
    Point<T> lower;
    Point<T> left;
    Point<T> right;

    virtual std::ostream& print(std::ostream& os) const noexcept override {
        os << "Upper: " << upper << "\n";
        os << "Lower: " << lower << "\n";
        os << "Left: " << left << "\n";
        os << "Right: " << right << "\n";
        return os;
    }
    virtual std::istream& input(std::istream& is) noexcept override {
        is >> upper >> lower >> left >> right;
        return is;
    }

  public:
    Rhomb() = default;
    Rhomb(const Point<T>& _upper, const Point<T>& _lower, const Point<T>& _left, const Point<T>& _right): upper(_upper), lower(_lower), left(_left), right(_right){}

    virtual T area() const noexcept override {
        T diag1 = Point<T>::line(upper, lower);
        T diag2 = Point<T>::line(left, right);

        return diag1*diag2*0.5;
    }

    virtual Point<T> center() const noexcept override {
        T X = (upper.x + lower.x + right.x + left.x) * 0.25;
        T Y = (upper.y + lower.y + left.y + right.y) * 0.25;

        return Point<T>{X, Y};
    }

    explicit virtual operator T() const noexcept override {
        return this->area();
    }

    virtual bool operator==(const Rhomb<T>& other) const {

        return other.upper == upper && other.lower == lower && other.right == right && other.left == left;
    }
    virtual bool operator!=(const Rhomb<T>& other) const  {
        return !(*this == other);
    }

};