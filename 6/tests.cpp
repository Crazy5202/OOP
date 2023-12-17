#include <gtest/gtest.h>
#include "orc.hpp"
#include "slaver.hpp"
#include "druid.hpp"

static const int distance = 10;

TEST(fights, orc_orc) {
    Orc orc1 = Orc(0,0, "Zero");
    Orc orc2 = Orc(1,1, "One");
    EXPECT_EQ(orc1.accept(&orc2, distance), true);
    EXPECT_EQ(orc2.accept(&orc1, distance), true);
}

TEST(fights, orc_druid) {
    Orc orc = Orc(0,0, "Killer");
    Druid druid = Druid(1,1, "Victim");
    EXPECT_EQ(orc.accept(&druid, distance), false);
    EXPECT_EQ(druid.accept(&orc, distance), true);
}

TEST(fights, slaver_druid) {
    Slaver slaver = Slaver(0,0, "Killer");
    Druid druid = Druid(1,1, "Victim");
    EXPECT_EQ(slaver.accept(&druid, distance), false);
    EXPECT_EQ(druid.accept(&slaver, distance), true);
}

TEST(fights, orc_massacre) {
    Orc orc = Orc(0,0, "Killer");
    Druid druid = Druid(1,1, "Victim");
    Slaver slaver = Slaver(2,2, "Prey");
    EXPECT_EQ(slaver.accept(&orc, distance), true);
    EXPECT_EQ(druid.accept(&orc, distance), true);
    EXPECT_EQ(druid.accept(&slaver, distance), false);
}

TEST(fights, out_of_reach) {
    Orc orc1 = Orc(0,0, "Zero");
    Orc orc2 = Orc(10,10, "One");
    EXPECT_EQ(orc1.accept(&orc2, distance), false);
    EXPECT_EQ(orc2.accept(&orc1, distance), false);
}