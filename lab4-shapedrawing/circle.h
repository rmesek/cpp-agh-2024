#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes {
class Circle : public Shape {
 public:
  Circle(int xCenter, int yCenter, int radius) noexcept;
  [[nodiscard]] bool isIn(int x, int y) const noexcept override;
  [[nodiscard]] int x() const noexcept { return _center.x_; }
  [[nodiscard]] int y() const noexcept { return _center.y_; }
  [[nodiscard]] int radius() const noexcept { return _radius; };

 private:
  Point _center;
  int _radius;
};
} // namespace Shapes

#endif //CIRCLE_H
