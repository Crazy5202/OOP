#include <gtest/gtest.h>
#include "triangle.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "array.hpp"

TEST(triangle, different) {
    Triangle* tester = new Triangle();
    EXPECT_EQ(tester->get_points().size(), 0);
    delete tester;
    std::vector<std::pair<double,double>> init_vector{{0,0},{1,1},{-1,1}};
    tester = new Triangle(init_vector);
    EXPECT_EQ(tester->get_points(), init_vector);
    EXPECT_EQ(double(*tester), 1.0);
    EXPECT_TRUE(tester == tester);
    Triangle new_tester = Triangle(init_vector);
    Triangle new_tester_2 = new_tester;
    EXPECT_EQ(new_tester_2, new_tester);
}

TEST(hexagon, center) {
    std::vector<std::pair<double,double>> init_vector{{2,2},{2,4.23},{4,1},{4,5.47},{6,2},{6,4.23}};
    Hexagon* tester = new Hexagon(init_vector);
    std::pair<double, double> center = tester->find_center();
    EXPECT_EQ(center.first, 4);
}

TEST(throws, constructor) {
    std::vector<std::pair<double,double>> init_vector{{2,2},{2,4.23},{4,1},{4,5.47},{6,2},{6,4.23}};
    EXPECT_ANY_THROW(Triangle* tester = new Triangle(init_vector));
}

TEST(throws, array) {
    Array* arr = new Array(1);
    std::vector<std::pair<double,double>> init_vector{{0,1},{1,0},{-1,0}};
    Triangle* tester = new Triangle(init_vector);
    arr->place_figure(0, tester);
    EXPECT_EQ(double(*tester), 1);
    EXPECT_ANY_THROW(arr->place_figure(1, tester));
    arr->resize(2);
    init_vector = {{2,2},{2,4.23},{4,1},{4,5.47},{6,2},{6,4.23}};
    Hexagon* new_tester = new Hexagon(init_vector);
    arr->place_figure(1, new_tester);
    EXPECT_EQ(arr->get_size(), 2);
    EXPECT_EQ((*arr)[1]->find_center().first, 4);
    arr->resize(1);
    EXPECT_ANY_THROW((*arr)[1]);
    EXPECT_ANY_THROW(arr->remove_figure(1));
}