#include <gtest/gtest.h>
#include "triangle.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "array.hpp"
#include "shared_methods.hpp"

TEST(triangle, different) {
    Triangle<int>* tester = new Triangle<int>();
    delete tester;
    std::vector<std::pair<int,int>> init_vector{{0,0},{0,1},{1,0}};
    tester = new Triangle(init_vector);
    EXPECT_EQ(tester->points, init_vector);
    EXPECT_TRUE(double(*tester)-0.43<0.01);
    EXPECT_TRUE(tester == tester);
    Triangle new_tester = Triangle(init_vector);
    Triangle new_tester_2 = new_tester;
    EXPECT_EQ(new_tester_2, new_tester);
}

TEST(hexagon, center) {
    std::vector<std::pair<double,double>> init_vector{{2,2},{2,4.23},{4,1},{4,5.47},{6,2},{6,4.23}};
    Hexagon<double> tester(init_vector);
    std::pair<double, double> center = find_center(tester);
    EXPECT_EQ(center.first, 4);
}


TEST(array, different) {
    Array<Triangle<int>> arr(3);
    std::vector<std::pair<int,int>> init_vector_triag{{0,0},{0,1},{1,0}};
    Triangle<int> tester(init_vector_triag);
    arr[0] = tester;
    EXPECT_TRUE(double(arr[0])-0.43 < 0.01);
    EXPECT_ANY_THROW(arr[4]);
    std::vector<std::pair<double, double>> init_vector_hexagon = {{2,2},{2,4.23},{4,1},{4,5.47},{6,2},{6,4.23}};
    Hexagon<double> new_tester(init_vector_hexagon);
    Array<Hexagon<double>> new_arr(2);
    new_arr[0]=new_tester;
    EXPECT_TRUE(new_arr.find_total_square() - 12.92 < 0.01);
    EXPECT_EQ(find_center(new_arr[0]).first, 4);
}