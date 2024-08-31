#include "waypoint.h"
#include "geo_coordinate.h"
#include <gtest/gtest.h>

namespace ljankai
{

    TEST(WaypointTest, EqualityOperatorWorks)
    {
        Waypoint wp1("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));
        Waypoint wp2("Finland", GeoCoordinate::FromDegrees(60.1699, 24.9384));
        Waypoint wp3("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));

        EXPECT_TRUE(wp1 == wp3);
        EXPECT_TRUE(wp3 == wp1);

        EXPECT_TRUE(wp1 != wp2);
        EXPECT_TRUE(wp2 != wp3);

        EXPECT_FALSE(wp1 == wp2);
        EXPECT_FALSE(wp2 == wp3);

        EXPECT_FALSE(wp1 != wp3);
        EXPECT_FALSE(wp3 != wp1);
    }

    TEST(WaypointTest, TestHash)
    {
        Waypoint wp1("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));
        Waypoint wp2("Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536));
        Waypoint wp3("Finland", GeoCoordinate::FromDegrees(60.1699, 24.9384));

        EXPECT_EQ(Waypoint::HashFunction()(wp1), Waypoint::HashFunction()(wp2));
        EXPECT_NE(Waypoint::HashFunction()(wp1), Waypoint::HashFunction()(wp3));
    }

}