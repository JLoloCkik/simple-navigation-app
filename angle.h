#ifndef LJANKAI_ANGLE_H
#define LJANKAI_ANGLE_H

namespace ljankai {

class Angle {
public:
  static Angle FromDegrees(double value);
  static Angle FromRadian(double value);

  ~Angle() = default;

  double AsDegrees() const;
  double AsRadian() const;
  Angle Normalize() const;

  bool operator==(const Angle &angle) const;
  bool operator!=(const Angle &angle) const;

private:
  explicit Angle(double value);

  const double value_;
};

} // namespace ljankai

#endif