#include "circle.h"

namespace Shapes {
Circle::Circle(int xCenter, int yCenter, int radius) noexcept : _center(xCenter, yCenter), _radius(radius) {}

bool Circle::isIn(int x, int y) const noexcept {
  return (_center.x_ - x) * (_center.x_ - x) + (_center.y_ - y) * (_center.y_ - y) <= _radius * _radius;
}
} // namespace Shapes