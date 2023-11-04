#include<gtest/gtest.h>
#include "rhomb.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"

TEST(TestRhomb, TestArea) {
    Point<double> upper_vertex(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    Rhomb<double> r = Rhomb(upper_vertex, lower_vertex, left_vertex, right_vertex);
    double ans_area = 4.0;
    EXPECT_DOUBLE_EQ(r.area(), ans_area);
}

TEST(TestRhomb, TestCenter) {
    Point<double> upper_vertex(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    Rhomb<double> r = Rhomb(upper_vertex, lower_vertex, left_vertex, right_vertex);
    Point ans = Point(0.0, 0.0);
    EXPECT_EQ(r.center(), ans);

}

TEST(TestRhomb, TestOperatorDouble) {
    Point<double> upper_vertex(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    Rhomb<double> r = Rhomb(upper_vertex, lower_vertex, left_vertex, right_vertex);
    double ans_area = 4.0;
    EXPECT_DOUBLE_EQ(static_cast<double>(r), ans_area);
}

TEST(TestRhomb, TestOperatorEqualandNotEqual) {
    Point upper_vertex(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    Rhomb r1(upper_vertex, lower_vertex, left_vertex, right_vertex);
    Rhomb r2(upper_vertex, lower_vertex, left_vertex, right_vertex);
    ASSERT_TRUE(r1 == r2); 
    upper_vertex = Point(1.0, 1.0);
    lower_vertex = Point(-1.0, -1.0);
    left_vertex = Point(-3.0, 3.0);
    right_vertex = Point(3.0, -3.0);
    r2 = Rhomb(upper_vertex, lower_vertex, left_vertex, right_vertex);
    ASSERT_TRUE(r1 != r2);
}


TEST(TestPentagone, TestArea) {
    Point left_lower(0.0, 0.0), right_lower(2.0, 0.0), left_middle(-1.0, 2.0), right_middle(3.0, 2.0), upper(1.0, 3.0);
    Pentagone<double> p = Pentagone(left_lower, right_lower, left_middle, right_middle, upper);

    double ans = 8.0;
    EXPECT_FLOAT_EQ(p.area(), ans);

}

TEST(TestPentagone, TestCenter) {
    Point left_lower(0.0, 0.0), right_lower(2.0, 0.0), left_middle(-1.0, 2.0), right_middle(3.0, 2.0), upper(1.0, 3.0);
    Pentagone<double> p = Pentagone(left_lower, right_lower, left_middle, right_middle, upper);

    Point ans(1.0, 1.4);
    EXPECT_FLOAT_EQ(ans.x, p.center().x);
    EXPECT_FLOAT_EQ(ans.y, p.center().y);
}

TEST(TestPentagone, TestOperatorDouble) {
    Point left_lower(0.0, 0.0), right_lower(2.0, 0.0), left_middle(-1.0, 2.0), right_middle(3.0, 2.0), upper(1.0, 3.0);
    Pentagone<double> p = Pentagone(left_lower, right_lower, left_middle, right_middle, upper);

    double ans = 8.0;
    EXPECT_FLOAT_EQ(static_cast<double>(p), ans);

}


TEST(TestPentagone, TestOperatorEqualandNotEqual) {
    Point left_lower(0.0, 0.0), right_lower(2.0, 0.0), left_middle(-1.0, 2.0), right_middle(3.0, 2.0), upper(1.0, 3.0);
    Pentagone<double> p = Pentagone(left_lower, right_lower, left_middle, right_middle, upper);
    Pentagone p1 = Pentagone(left_lower, right_lower, left_middle, right_middle, upper);
    ASSERT_TRUE(p == p1);
    left_lower = Point(0.0, -1.0); right_lower = Point(1.0, -5.0); left_middle = Point(0.0, 3.0); right_middle = Point(-1.0, 8.0); upper = Point(2.0, 6.0);
    p1 = Pentagone(left_lower, right_lower, left_middle, right_middle, upper);
    ASSERT_TRUE(p != p1);
}


TEST(TestHexagon, TestArea) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    Hexagon<double> h(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper);
    double ans = 4.0;
    EXPECT_FLOAT_EQ(h.area(), ans);
}

TEST(TestHexagon, TestCenter) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    Hexagon<double> h(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper);
    Point ans = Point(0.5, 1.0);
    EXPECT_EQ(h.center(), ans);

}

TEST(TestHexagon, TestOperatorDouble) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    Hexagon<double> h(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper);
    double ans = 4.0;
    EXPECT_FLOAT_EQ(static_cast<double>(h), ans);
}

TEST(TestHexagon, TestOperatorEqualandNotEqual) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    Hexagon<double> h1(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper);
    Hexagon h2 = Hexagon(left_lower, right_lower, left_middle,right_middle,left_upper, right_upper);
    ASSERT_TRUE(h1 == h2);
    left_lower = Point(1.0, -2.0),right_lower = Point(2.0, -2.0),left_middle = Point(0.0,0.0),right_middle = Point(3.0,0.0),left_upper = Point(1.0, 1.0),right_upper = Point(2.0,1.0);
    h2 = Hexagon(left_lower, right_lower, left_middle,right_middle,left_upper, right_upper);
    ASSERT_TRUE(h1 != h2);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}