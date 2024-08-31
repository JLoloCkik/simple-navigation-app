#ifndef LJANKAI_ANGLE_H
#define LJANKAI_ANGLE_H

#include <cstddef>
#include <functional>

namespace ljankai
{

  class Angle
  {
  public:
    static Angle FromDegrees(double value);
    static Angle FromRadian(double value);

    ~Angle() = default;

    double AsDegrees() const;
    double AsRadian() const;
    Angle Normalize() const;

    bool operator==(const Angle &angle) const
    {
      return value_ == angle.value_;
    }
    bool operator!=(const Angle &angle) const
    {
      return value_ != angle.value_;
    }

    struct HashFunction
    {
      size_t operator()(const Angle &angle) const
      {
        return 7 * (17 + std::hash<double>()(angle.value_));
      }
    };

  private:
    explicit Angle(double value);

    const double value_;
  };

} // namespace ljankai

#endif