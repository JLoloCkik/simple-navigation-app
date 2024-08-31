#include "angle.h"
#include "geo_coordinate.h"
#include <cmath>
#include <gtest/gtest.h>

// DirectionCalculator
namespace ljankai
{
  TEST(GeoCoordinateTest, DirectionCalculatorNorth)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(0, 0);
    GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

    EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(0));
  }

  TEST(GeoCoordinateTest, DirectionCalculatorFromSouthNorth45)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(-45, 0);
    GeoCoordinate end = GeoCoordinate::FromDegrees(45, 0);

    EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(0));
  }

  TEST(GeoCoordinateTest, DirectionCalculatorWest)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(0, 0);
    GeoCoordinate end = GeoCoordinate::FromDegrees(0, -90);

    EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(270));
  }

  TEST(GeoCoordinateTest, DirectionCalculatorFromSouthNorth90)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(-90, 0);
    GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

    EXPECT_EQ(start.BearingTo(end), Angle::FromDegrees(0));
  }

  // DistanceCalculator

  TEST(GeoCoordinateTest, DistanceCalculatorSouthNorth90)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(-90, 0);
    GeoCoordinate end = GeoCoordinate::FromDegrees(90, 0);

    EXPECT_NEAR(start.DistanceTo(end), 20037.5, 0.1);
  }

  TEST(GeoCoordinateTest, DistanceCalculatorBetweenTwoPoints)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(0, 50);
    GeoCoordinate end = GeoCoordinate::FromDegrees(0, 90);

    EXPECT_NEAR(start.DistanceTo(end), 4452.8, 0.1);
  }

  TEST(GeoCoordinateTest, DistanceCalculatorBetweenAdjacentLatitudes)
  {
    GeoCoordinate start = GeoCoordinate::FromDegrees(1, 0);
    GeoCoordinate end = GeoCoordinate::FromDegrees(2, 0);

    EXPECT_NEAR(start.DistanceTo(end), 111.3, 0.1);
  }

  TEST(GeoCoordinateTest, TestHash)
  {
    GeoCoordinate cord1 = GeoCoordinate::FromDegrees(2, 0);
    GeoCoordinate cord2 = GeoCoordinate::FromDegrees(2, 0);
    GeoCoordinate cord3 = GeoCoordinate::FromDegrees(3, 0);

    EXPECT_EQ(GeoCoordinate::HashFunction()(cord1), GeoCoordinate::HashFunction()(cord2));
    EXPECT_NE(GeoCoordinate::HashFunction()(cord1), GeoCoordinate::HashFunction()(cord3));
  }

  TEST(GeoCoordinateTest, EqualityOperatorWorks)
  {
    GeoCoordinate cord1 = GeoCoordinate::FromDegrees(59.4370, 24.7536);
    GeoCoordinate cord2 = GeoCoordinate::FromDegrees(60.1699, 24.9384);
    GeoCoordinate cord3 = GeoCoordinate::FromDegrees(59.4370, 24.7536);

    EXPECT_TRUE(cord1 == cord3);
    EXPECT_TRUE(cord3 == cord1);

    EXPECT_TRUE(cord1 != cord2);
    EXPECT_TRUE(cord2 != cord3);

    EXPECT_FALSE(cord1 == cord2);
    EXPECT_FALSE(cord2 == cord3);

    EXPECT_FALSE(cord1 != cord3);
    EXPECT_FALSE(cord3 != cord1);
  }
}