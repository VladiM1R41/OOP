#ifndef FIGURE_HPP
#define FIGURE_HPP

#include<string_view>
#include"point.hpp"

class Figure {

  public:
    Figure() = default;
    Figure(const std::string&);
    
    virtual ~Figure() noexcept = default;

    explicit virtual operator double() const noexcept = 0;


    virtual double area() const noexcept = 0;
    virtual double perimetr() const noexcept = 0;
    virtual Point center() const noexcept = 0;

  protected:
    std::string figure_name;
};


#endif