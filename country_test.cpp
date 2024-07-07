#include "Country.h"

#include <cmath>
#include <gtest/gtest.h>

using ljankai::convert_radian;
using ljankai::direction_calculator;
using ljankai::distance_calculator;
// ConvertRadian

TEST(CountryTest, ConvertRadian0Degrees) {
  EXPECT_DOUBLE_EQ(convert_radian(0), 0);
}

TEST(CountryTest, ConvertRadian180Degrees) {
  EXPECT_DOUBLE_EQ(convert_radian(180), M_PI);
}

TEST(CountryTest, ConvertRadian360Degrees) {
  EXPECT_DOUBLE_EQ(convert_radian(360), 2 * M_PI);
}

// DirectionCalculator

TEST(CountryTest, DirectionCalculatorNorth) {
  EXPECT_DOUBLE_EQ(direction_calculator(convert_radian(0),convert_radian(0),
              convert_radian(90),convert_radian(0)), 0);
}

TEST(CountryTest, DirectionCalculatorFromSouthNorth45) {
  EXPECT_DOUBLE_EQ(direction_calculator(convert_radian(-45),convert_radian(0),
              convert_radian(45),convert_radian(0)), 0);
}

TEST(CountryTest, DirectionCalculatorWest) {
  EXPECT_DOUBLE_EQ(direction_calculator(convert_radian(0),convert_radian(0),
              convert_radian(0),convert_radian(-90)), 270);
}

TEST(CountryTest, DirectionCalculatorFromSouthNorth90) {
  EXPECT_DOUBLE_EQ(direction_calculator(convert_radian(-90),convert_radian(0),
              convert_radian(90),convert_radian(0)), 0);
}

// DistanceCalculator

TEST(CountryTest, DistanceCalculator) {
  EXPECT_NEAR(distance_calculator(convert_radian(-90),convert_radian(0),
    convert_radian(90),convert_radian(0)), 	20037.5, 0.1);
}
