#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include"figure.hpp"
#include"point.hpp"

class Hexagon final: public Figure {

  public:
    Hexagon() = default;

    Hexagon(const Point& _left_lower, const Point& _right_lower, const Point&  _left_middle, const Point& _right_middle, const Point& _left_upper,const Point& _right_upper, const std::string& _figure_name);

    Hexagon(const Hexagon& other) noexcept;

    virtual ~Hexagon() noexcept = default;

    virtual double area() const noexcept override;
    virtual double perimetr() const noexcept override;
    virtual Point center() const noexcept override;

    explicit virtual operator double() const noexcept override;
    Hexagon& operator=(const Hexagon&) noexcept;
    Hexagon& operator=(Hexagon&&) noexcept;
    bool operator==(const Hexagon&) const noexcept;
    bool operator!=(const Hexagon&) const noexcept;

    friend std::ostream& operator<<(std::ostream&, const Hexagon&);
    friend std::istream& operator>>(std::istream&, Hexagon&);

  private:
    Point left_lower;
    Point right_lower;
    Point left_middle;
    Point right_middle;
    Point left_upper;
    Point right_upper;

};

#endif