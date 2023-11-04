#include<iostream>
#include "array.hpp"
#include "point.hpp"
#include "rhomb.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"

int main() {
    Array<std::shared_ptr<Figure<double>>> figuresArray(3);
    Point<double> upper(0.0, 2.0), lower(0.0, -2.0), left(-1.0, 0.0), right(1.0, 0.0);
    Rhomb<double> r(upper, lower, left, right);
    std::cout << r << std::endl;   
    
    Point<float> left_lower2(0.0, 0.0), right_lower2(1.0, 0.0), left_upper2(-1.0, 1.0), right_upper2(2.0, 1.0), upper2(2.5, 2.0);
    Pentagone<float> p(left_lower2, right_lower2, left_upper2, right_upper2, upper2);
    std::cout << p << std::endl;

    Point<float> left_lower(0.0, 0.0), right_lower(4.0, 0.0),left_middle(-2.0, 2.0),right_middle(6.0, 2.0), left_upper(0.0, 4.0), right_upper(4.0, 4.0);
    Hexagon<float> t(left_lower, right_lower, left_middle,right_middle,left_upper, right_upper);
    std::cout << t << std::endl;
}