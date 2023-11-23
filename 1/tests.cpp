#include <gtest/gtest.h>
#include "nod.hpp"

TEST(basic_tests, test_01) {
    ASSERT_TRUE(nod(0,0)==0);
}

TEST(basic_tests, test_02) {
    ASSERT_TRUE(nod(1,1)==1);
}

TEST(basic_tests, test_03) {
    ASSERT_TRUE(nod(2,5)==1);
}

TEST(basic_tests, test_04) {
    ASSERT_TRUE(nod(54321,9876)==3);
}

TEST(basic_tests, test_05) {
    ASSERT_TRUE(nod(-1,1)==1);
}

TEST(basic_tests, test_06) {
    ASSERT_TRUE(nod(66,-24)==6);
}

TEST(basic_tests, test_07) {
    ASSERT_TRUE(nod(-435,-738)==3);
}