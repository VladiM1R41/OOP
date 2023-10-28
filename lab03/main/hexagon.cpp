#include"hexagon.hpp"
#include<iostream>
#include<cmath>

Hexagon::Hexagon(const Point& _left_lower, const Point& _right_lower, const Point& _left_middle, const Point& _right_middle, const Point& _left_upper,const Point& _right_upper, const std::string& _figure_name):
    left_lower(_left_lower),left_middle(_left_middle),right_lower(_right_lower),right_middle(_right_middle),left_upper(_left_upper),right_upper(_right_upper),Figure(_figure_name){}

Hexagon::Hexagon(const Hexagon& other) noexcept: left_lower(other.left_lower), right_lower(other.right_lower), left_middle(other.left_middle), right_middle(other.right_middle), left_upper(other.left_upper),right_upper(other.right_upper), Figure(other.figure_name) {}

double Hexagon::area() const noexcept {
    double a = Point::line(left_lower, right_lower);
    double b = Point::line(left_lower, left_middle);
    double c = Point::line(right_lower, right_middle);
    double d = Point::line(left_middle, left_upper);
    double e = Point::line(right_middle, right_upper);
    double f = Point::line(left_upper,right_upper);
    double d1 = Point::line(left_middle,right_lower);
    double d2 = Point::line(left_middle,right_middle);
    double d3 = Point::line(left_middle,right_upper);
    double p1 = (a + b + d1)*0.5;
    double p2 = (c + d1 + d2)*0.5;
    double p3 = (e + d2 + d3)*0.5;
    double p4 = (f + d + d3)*0.5;
    double s1 = sqrt(p1*(p1 - a)*(p1 - b)*(p1 - d1));
    double s2 = sqrt(p2*(p2 - c)*(p2 - d1)*(p2 - d2));
    double s3 = sqrt(p3*(p3 - e)*(p3 - d2)*(p3 - d3));
    double s4 = sqrt(p4*(p4 - f)*(p4 - d)*(p4 - d3));
    
    return s1 + s2 + s3 + s4;
}

double Hexagon::perimetr() const noexcept {
    double a = Point::line(right_lower, left_lower);
    double b = Point::line(right_lower, right_middle);
    double c = Point::line(left_lower, left_middle);
    double d = Point::line(right_middle, right_upper);
    double e = Point::line(left_middle, left_upper);
    double f = Point::line(left_upper, right_upper);

    return a + b + c + d + e + f;
}

Point Hexagon::center() const noexcept {
    double xCenter =  (left_lower.x + left_middle.x + right_lower.x + right_middle.x + left_upper.x + right_upper.x)/6.0;
    double yCenter =  (left_lower.y + left_middle.y + right_lower.y + right_middle.y + left_upper.y + right_upper.y)/6.0;

    return Point{xCenter, yCenter};
}


Hexagon::operator double() const noexcept {
    return this -> area();
}
Hexagon& Hexagon::operator=(const Hexagon& other) noexcept{

    if (this != &other) {
        left_lower = other.left_lower;
        left_middle = other.left_middle;
        left_upper = other.left_upper;
        right_lower = other.right_lower;
        right_middle = other.right_middle;
        right_upper = other.right_upper;
    }

    return *this;
}
Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {

    if (this != &other) {
        left_lower = other.left_lower;
        left_middle = other.left_middle;
        left_upper = other.left_upper;
        right_lower = other.right_lower;
        right_middle = other.right_middle;
        right_upper = other.right_upper;
    }

    return *this;
}
bool Hexagon::operator==(const Hexagon& other) const noexcept {
    return left_lower == other.left_lower && 
    left_middle == other.left_middle &&
    left_upper == other.left_upper && 
    right_lower == other.right_lower && 
    right_middle == other.right_middle && 
    right_upper == other.right_upper;
}
bool Hexagon::operator!=(const Hexagon& other) const noexcept {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Hexagon& pent) {
    os << "Left Lower: " << pent.left_lower << std::endl;
    os << "Right Lower: " << pent.right_lower << std::endl;
    os << "Left Middle: " << pent.left_middle << std::endl;
    os << "Right Middle: " << pent.right_middle << std::endl;
    os << "Left Upper: " << pent.left_upper << std::endl;
    os << "Right Upper: " << pent.right_upper << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Hexagon& pent) {
    is >> pent.left_lower;
    is >> pent.right_lower;
    is >> pent.left_middle;
    is >> pent.right_middle;
    is >> pent.left_upper;
    is >> pent.right_upper;


    pent.figure_name = "Hexagon";

    return is;
    
}