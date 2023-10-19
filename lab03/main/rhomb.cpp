#include"rhomb.hpp"
#include<cmath>
#include<iostream>


Rhomb::Rhomb(const Point& upper, const Point& lower, const Point& left, const Point& right, const std::string& name): upper_vertex(upper), lower_vertex(lower), left_vertex(left), right_vertex(right), Figure(name){}

Rhomb::Rhomb(const Rhomb& other) noexcept: upper_vertex(other.upper_vertex), lower_vertex(other.lower_vertex), left_vertex(other.left_vertex), right_vertex(other.right_vertex), Figure(other.figure_name){}

double Rhomb::area() const noexcept {

    double d1 = Point::line(upper_vertex, lower_vertex);
    double d2 = Point::line(left_vertex, right_vertex);

    return d1*d2*0.5;
}

double Rhomb::perimetr() const noexcept {
    double a = Point::line(lower_vertex, left_vertex);
    std::cout << "   a     :" << a<<"\n";
    return 4.0*a;
}

Point Rhomb::center() const noexcept {
    double CenterX = (upper_vertex.x + lower_vertex.x + right_vertex.x + left_vertex.x) * 0.25;
    double CenterY = (upper_vertex.y + lower_vertex.y + left_vertex.y + right_vertex.y)*0.25;

    return Point{CenterX, CenterY};
}


Rhomb::operator double () const noexcept {
    return this -> area();
}
Rhomb& Rhomb::operator=(const Rhomb& other) noexcept {
    
    if (this != &other) {
        upper_vertex = other.upper_vertex;
        lower_vertex = other.lower_vertex;
        left_vertex = other.left_vertex;
        right_vertex = other.right_vertex;
    }

    return *this;
}
Rhomb& Rhomb::operator=(Rhomb&& other) noexcept {
    
    if (this != &other) {
        upper_vertex = other.upper_vertex;
        lower_vertex = other.lower_vertex;
        left_vertex = other.left_vertex;
        right_vertex = other.right_vertex;
    }

    return *this;
}
bool Rhomb::operator==(const Rhomb& other) const noexcept {
    return upper_vertex == other.upper_vertex && lower_vertex == other.lower_vertex && right_vertex == other.right_vertex && left_vertex == other.left_vertex;
}
bool Rhomb::operator!=(const Rhomb& other) const noexcept {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rhomb& rhomb){
    os << "Upper vertex: " << rhomb.upper_vertex << std::endl;
    os << "Left vertex: " << rhomb.left_vertex << std::endl;
    os << "Right vertex: " << rhomb.right_vertex << std::endl;
    os << "Lower vertex: " << rhomb.lower_vertex << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Rhomb& rhomb) {
    std::cout << "Введите верхнюю точку ромба: ";
    is >> rhomb.upper_vertex;
    std::cout << "введите левую вершину ромба: ";
    is >> rhomb.left_vertex;
    std::cout << "введите правую вершину ромба: ";
    is >> rhomb.right_vertex;
    std::cout << "введите нижнюю вершину ромба: ";
    is >> rhomb.lower_vertex;

    rhomb.figure_name = "rhomb";
    
    return is;
}