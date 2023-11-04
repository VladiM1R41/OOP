#pragma once

#include "point.hpp"

template <class T>
class Figure {

  protected:
    Figure() = default;
    virtual std::ostream& print(std::ostream& os) const noexcept = 0;
    virtual std::istream& input(std::istream& is) noexcept = 0;
  public:
    virtual ~Figure() noexcept = default;
    virtual T area() const noexcept = 0;
    virtual Point<T> center() const noexcept = 0;

    explicit virtual operator T() const noexcept = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& f) noexcept {
        return f.print(os);
    }
    friend std::istream& operator>>(std::istream& is, Figure& f) {
        return f.input(is);
    }
    
};
