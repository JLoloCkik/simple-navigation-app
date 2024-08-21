#ifndef LJANKAI_GEO_COORDINATE_H
#define LJANKAI_GEO_COORDINATE_H

#include "angle.h"

namespace ljankai
{

  class GeoCoordinate
  {
  public:
    static GeoCoordinate FromDegrees(double latitude, double longitude);
    static GeoCoordinate FromRadian(double latitude, double longitude);

    GeoCoordinate(const Angle &latitude, const Angle &longitude);

    const Angle &Latitude() const;
    const Angle &Longitude() const;
    double DistanceTo(const GeoCoordinate &other) const;
    Angle BearingTo(const GeoCoordinate &other) const;

    bool operator==(const GeoCoordinate &other) const
    {
      return latitude_ == other.latitude_ && longitude_ == other.longitude_;
    };

    bool operator!=(const GeoCoordinate &other) const
    {
      return !(*this == other);
    };

  private:
    const Angle latitude_;
    const Angle longitude_;
  };

} // namespace ljankaii

#endif