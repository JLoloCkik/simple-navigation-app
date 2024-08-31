#include "angle.h"
#include <cmath>

namespace ljankai {

Angle::Angle(double value) : value_(value) {}

Angle Angle::FromDegrees(double value) { return Angle(value * M_PI / 180); }
Angle Angle::FromRadian(double value) { return Angle(value); }

double Angle::AsDegrees() const { return value_ * 180 / M_PI; }
double Angle::AsRadian() const { return value_; }
Angle Angle::Normalize() const { return Angle(fmod(value_, 2 * M_PI)); }


} // namespace ljankai