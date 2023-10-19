#ifndef PHOMB_HPP
#define PHOMB_HPP

#include"figure.hpp"
#include"point.hpp"

class Rhomb final: public Figure {

  public:
    Rhomb() = default;
    Rhomb(const Point& _upper, const Point& _lower, const Point& _left, const Point& _right, const std::string& _figure_name);
    Rhomb(const Rhomb& other) noexcept;

    virtual ~Rhomb() noexcept = default;

    explicit virtual operator double() const noexcept override;
    Rhomb& operator=(const Rhomb&) noexcept;
    Rhomb& operator=(Rhomb&&) noexcept; 
    bool operator==(const Rhomb&) const noexcept;
    bool operator!=(const Rhomb&) const noexcept;


    virtual double area() const noexcept override;
    virtual double perimetr() const noexcept override;
    virtual Point center() const noexcept override;


    friend std::ostream& operator<<(std::ostream&, const Rhomb&);
    friend std::istream& operator>>(std::istream&, Rhomb&);
  private:
    Point upper_vertex;
    Point lower_vertex;
    Point left_vertex;
    Point right_vertex;
};

#endif