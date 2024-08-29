#ifndef LJANKAI_WAYPOINT_H
#define LJANKAI_WAYPOINT_H

#include <string>
#include "geo_coordinate.h"

namespace ljankai
{
    struct Waypoint
    {
        std::string name;
        GeoCoordinate geo_coordinate;

        Waypoint(const std::string &name, const GeoCoordinate &geocordinate)
            : name(name), geo_coordinate(geocordinate) {}

        bool operator==(const Waypoint &other) const
        {
            return geo_coordinate == other.geo_coordinate && name == other.name;
        };

        bool operator!=(const Waypoint &other) const
        {
            return !(*this == other);
        };

        struct HashFunction
        {
            size_t operator()(const Waypoint &waypoint) const
            {
                size_t result = 17;
                result = 7 * (result + GeoCoordinate::HashFunction()(waypoint.geo_coordinate));
                result = 7 * (result + std::hash<std::string>()(waypoint.name));
                return result;
            }
        };
    };

    //     std::map<std::string, GeoCoordinate> EuCountries()
    //     {
    //         return {
    //             {"Austria", GeoCoordinate::FromDegrees(48.2082, 16.3738)},
    //             {"Belgium", GeoCoordinate::FromDegrees(50.8503, 4.3517)},
    //             {"Bulgaria", GeoCoordinate::FromDegrees(42.6977, 23.3219)},
    //             {"Croatia", GeoCoordinate::FromDegrees(45.815, 15.9819)},
    //             {"Cyprus", GeoCoordinate::FromDegrees(35.1856, 33.3823)},
    //             {"Czech Republic", GeoCoordinate::FromDegrees(50.0755, 14.4378)},
    //             {"Denmark", GeoCoordinate::FromDegrees(55.6867, 12.5701)},
    //             {"Estonia", GeoCoordinate::FromDegrees(59.4370, 24.7536)},
    //             {"Finland", GeoCoordinate::FromDegrees(60.1699, 24.9384)},
    //             {"France", GeoCoordinate::FromDegrees(48.8566, 2.3522)},
    //             {"Germany", GeoCoordinate::FromDegrees(52.5200, 13.4050)},
    //             {"Greece", GeoCoordinate::FromDegrees(37.9838, 23.7275)},
    //             {"Hungary", GeoCoordinate::FromDegrees(47.4979, 19.0402)},
    //             {"Ireland", GeoCoordinate::FromDegrees(53.3498, -6.2603)},
    //             {"Italy", GeoCoordinate::FromDegrees(41.9028, 12.4964)},
    //             {"Latvia", GeoCoordinate::FromDegrees(56.9496, 24.1052)},
    //             {"Lithuania", GeoCoordinate::FromDegrees(54.6872, 25.2797)},
    //             {"Luxembourg", GeoCoordinate::FromDegrees(49.6116, 6.1319)},
    //             {"Malta", GeoCoordinate::FromDegrees(35.9375, 14.3754)},
    //             {"Netherlands", GeoCoordinate::FromDegrees(52.3676, 4.8952)},
    //             {"Poland", GeoCoordinate::FromDegrees(52.2370, 21.0175)},
    //             {"Portugal", GeoCoordinate::FromDegrees(38.7223, -9.1393)},
    //             {"Romania", GeoCoordinate::FromDegrees(44.4268, 26.1025)},
    //             {"Slovakia", GeoCoordinate::FromDegrees(48.1486, 17.1077)},
    //             {"Slovenia", GeoCoordinate::FromDegrees(46.0569, 14.5058)},
    //             {"Spain", GeoCoordinate::FromDegrees(40.4168, -3.7038)},
    //             {"Sweden", GeoCoordinate::FromDegrees(59.3293, 18.0686)}
    //         };
    //     }
} // namespace ljankai
#endif
