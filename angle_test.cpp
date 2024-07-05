#include "angle.h"
#include <cmath>
#include <gtest/gtest.h>

using ljankai::Angle;

TEST(AngleTest, DegreesEqualsRadian) {
  EXPECT_EQ(Angle::FromDegrees(0), Angle::FromRadian(0));
}
TEST(AngleTest, ReturnsValueInDegrees) {
  auto angle = Angle::FromRadian(M_PI);
  EXPECT_EQ(angle.AsDegrees(), 180);
}
TEST(AngleTest, ReturnsValueInRadian) {
  auto angle = Angle::FromDegrees(180);
  EXPECT_EQ(angle.AsRadian(), M_PI);
}
TEST(AngleTest, NormalizeValueBetweenZeroAndPi) {
  auto angle = Angle::FromDegrees(720);
  EXPECT_EQ(angle.Normalize(), Angle::FromDegrees(0));
}
TEST(AngleTest, NormalizeValueBetweenZeroAndPiWithinError) {
  auto angle = Angle::FromDegrees(400);
  EXPECT_NEAR(angle.Normalize().AsRadian(), Angle::FromDegrees(40).AsRadian(),
              0.000001);
}
TEST(AngleTest, AnglesAreEquale) {
  EXPECT_EQ(Angle::FromDegrees(0), Angle::FromDegrees(0));
}
TEST(AngleTest, AnglesAreNotEquale) {
  EXPECT_NE(Angle::FromDegrees(1), Angle::FromDegrees(0));
}
