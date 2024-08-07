#include "angle.h"
#include "geo_coordinate.h"
#include <cmath>
#include <gtest/gtest.h>

using ljankai::Angle;
using ljankai::GeoCoordinate;

// DirectionCalculator

TEST(GeoCoordinateTest, DirectionCalculatorNorth) {
  GeoCoordinate start = GeoCoordinate::FromDegrees(0, 0);
  GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

  EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(0));
}

TEST(GeoCoordinateTest, DirectionCalculatorFromSouthNorth45) {
  GeoCoordinate start = GeoCoordinate::FromDegrees(-45, 0);
  GeoCoordinate end = GeoCoordinate::FromDegrees(45, 0);

  EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(0));
}

TEST(GeoCoordinateTest, DirectionCalculatorWest) {
  GeoCoordinate start = GeoCoordinate::FromDegrees(0, 0);
  GeoCoordinate end = GeoCoordinate::FromDegrees(0, -90);

  EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(270));
}

TEST(GeoCoordinateTest, DirectionCalculatorFromSouthNorth90) {
  GeoCoordinate start = GeoCoordinate::FromDegrees(-90, 0);
  GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

  EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(0));
}

// DistanceCalculator

TEST(GeoCoordinateTest, DistanceCalculatorSouthNorth90) {
  GeoCoordinate start = GeoCoordinate::FromDegrees(-90, 0);
  GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

  EXPECT_NEAR(start.DistanceTo(end), 20037.5, 0.1);
}

TEST(GeoCoordinateTest, DistanceCalculatorSouthNorth180) {
  GeoCoordinate start = GeoCoordinate::FromDegrees(-180, 0);
  GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

  EXPECT_NEAR(start.DistanceTo(end), 10010, 0.1);
}

