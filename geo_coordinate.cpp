#include "geo_coordinate.h"
#include "angle.h"
#include <cmath>
#include <stdexcept>

using ljankai::Angle;
namespace ljankai {
namespace {
constexpr double kRadius = 6378.137;

void EnsureValidCoordinates(const Angle &latitude, const Angle &longitude) {
  if (latitude.AsRadian() < -M_PI / 2 || latitude.AsRadian() > M_PI / 2) {
    throw std::invalid_argument("Illegal latitude value");
  }

  if (longitude.AsRadian() < -M_PI || longitude.AsRadian() > M_PI) {
    throw std::invalid_argument("Illegal longitude value");
  }
}
} // namespace

GeoCoordinate::GeoCoordinate(const Angle &latitude, const Angle &longitude)
    : latitude_(latitude), longitude_(longitude) {
  EnsureValidCoordinates(latitude, longitude);
};

GeoCoordinate GeoCoordinate::FromDegrees(double latitude, double longitude) {
  return GeoCoordinate(Angle::FromDegrees(latitude),
                       Angle::FromDegrees(longitude));
}

GeoCoordinate GeoCoordinate::FromRadian(double latitude, double longitude) {
  return GeoCoordinate(Angle::FromRadian(latitude),
                       Angle::FromRadian(longitude));
}
const Angle &GeoCoordinate::Latitude() const { return latitude_; }
const Angle &GeoCoordinate::Longitude() const { return longitude_; }

double GeoCoordinate::DistanceTo(const GeoCoordinate &other) const {
  return 2 * kRadius *
         asin(
             sqrt((1 - cos(other.latitude_.AsRadian() - latitude_.AsRadian()) +
                   cos(latitude_.AsRadian()) * cos(other.latitude_.AsRadian()) *
                       (1 - cos(other.longitude_.AsRadian() -
                                longitude_.AsRadian()))) /
                  2));
}
Angle GeoCoordinate::BearingTo(const GeoCoordinate &other) const {
  double direction =
      atan2(sin(other.longitude_.AsRadian() - longitude_.AsRadian()) *
                cos(other.latitude_.AsRadian()),
            cos(latitude_.AsRadian()) * sin(other.latitude_.AsRadian()) -
                sin(latitude_.AsRadian()) * cos(other.latitude_.AsRadian()) *
                    cos(other.longitude_.AsRadian() - longitude_.AsRadian()));

  return Angle::FromRadian(fmod(direction + 2 * M_PI, 2 * M_PI));
}
} // namespace ljankai