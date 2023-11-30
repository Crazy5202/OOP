#include <gtest/gtest.h>
#include "vector.hpp"
#include "allocator.hpp"
#include <vector>
#include <map>

const static int val1 = 10, val2 = 20, val3 = 30;
const static std::pair<int,int> pair1 = {1,2}, pair2 = {3,4}, pair3 = {5,6};

TEST(allocator, vector) {
    std::vector<int, MyAllocator<int>> tester;
    tester.push_back(val1);
    tester.push_back(val2);
    std::vector<int> comparer = {val1,val2};
    for (size_t i{0}; i<comparer.size(); ++i) {
        EXPECT_EQ(tester[i],comparer[i]);
    }
}

TEST(allocator, map) {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int,int>>> tester;
    tester[0]=val1;
    tester[1]=val2;
    tester[2]=val3;
    std::vector<int> comparer = {val1,val2, val3};
    for (size_t i{0}; i<tester.size(); ++i) {
        EXPECT_EQ(tester[i],comparer[i]);
    }
}

TEST(mycont, basic_constructor) {
    Vector<int> tester;
    tester.push_back(val1);
    EXPECT_EQ(tester.size(), 1);
    EXPECT_EQ(tester.capacity(), 1);
    tester.push_back(val2);
    EXPECT_EQ(tester.size(), 2);
    EXPECT_EQ(tester.capacity(), 2);
    EXPECT_EQ(tester[0], val1);
    EXPECT_EQ(tester[1], val2);
}

TEST(mycont_alloc, basic_constructor) {
    Vector<int, MyAllocator<int>> tester;
    tester.push_back(val1);
    EXPECT_EQ(tester.size(), 1);
    EXPECT_EQ(tester.capacity(), 1);
    tester.push_back(val2);
    EXPECT_EQ(tester.size(), 2);
    EXPECT_EQ(tester.capacity(), 2);
    EXPECT_EQ(tester[0], val1);
    EXPECT_EQ(tester[1], val2);
}

TEST(mycont_alloc, value_constructor) {
    Vector<int, MyAllocator<int>> tester(val1,val2);
    EXPECT_EQ(tester.size(), val1);
    EXPECT_EQ(tester.capacity(), val1);
    EXPECT_EQ(tester[val1-1], val2);
}

TEST(mycont_alloc, initlist_constructor) {
    Vector<double, MyAllocator<double>> tester = {1.0,2.0,3.0,4.0,5.0};
    EXPECT_EQ(tester.size(), 5);
    EXPECT_EQ(tester[4], 5.0);
}

TEST(mycont_alloc, copy_assignment_compare) {
    Vector<int, MyAllocator<int>> tester;
    tester.push_back(val1);
    tester.push_back(val2);
    Vector<int, MyAllocator<int>> new_tester(tester);
    Vector<int, MyAllocator<int>> newest_tester = new_tester;
    EXPECT_TRUE(tester == new_tester);
    EXPECT_TRUE(new_tester == newest_tester);
}

TEST(mycont_alloc, pairs_clear_access) {
    Vector<std::pair<int,int>, MyAllocator<std::pair<int,int>>> tester;
    tester.push_back(pair1);
    tester.push_back(pair2);
    EXPECT_EQ(tester[0], pair1);
    EXPECT_EQ(tester[1], pair2);
    tester.clear();
    tester.push_back(pair3);
    EXPECT_EQ(tester[0], pair3);
}

TEST(mycont_alloc, access_throw) {
    Vector<int, MyAllocator<int>> tester;
    tester.push_back(val1);
    tester.push_back(val2);
    tester.clear();
    EXPECT_THROW(tester[0], std::out_of_range);
}

TEST(mycont_alloc, iterators) {
    Vector<std::string, MyAllocator<std::string>> words = {"ba", "is", "ba",  "you"};
    size_t counter = 0;
    for (auto it = words.begin(); it!=words.end(); ++it) {
        if (*it=="ba") ++counter;
    }
    EXPECT_EQ(counter,2);
}