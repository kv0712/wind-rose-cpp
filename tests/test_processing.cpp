#include <gtest/gtest.h>
#include "processing.h"

TEST(AverageSpeedTest, NoRecordsForMonth) {
    std::vector<WindRecord> records = {
        {1, 1, "North", 3.5},
        {2, 1, "West", 6.2}
    };
    EXPECT_DOUBLE_EQ(0.0, calculateAverageSpeed(records, 2));
}

TEST(AverageSpeedTest, SingleRecord) {
    std::vector<WindRecord> records = {
        {1, 3, "North", 4.0}
    };
    EXPECT_DOUBLE_EQ(4.0, calculateAverageSpeed(records, 3));
}

TEST(AverageSpeedTest, MultipleRecords) {
    std::vector<WindRecord> records = {
        {1, 5, "North", 3.0},
        {2, 5, "West", 5.0},
        {3, 5, "East", 7.0}
    };
    EXPECT_DOUBLE_EQ(5.0, calculateAverageSpeed(records, 5));
}