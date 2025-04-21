#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes {
class Rectangle : public Shape {
 public:
  Rectangle(int xFrom, int yFrom, int xTo, int yTo) noexcept;
  [[nodiscard]] bool isIn(int x, int y) const noexcept override;
  [[nodiscard]] int x() const noexcept { return _lowerLeft.x_; }
  [[nodiscard]] int y() const noexcept { return _lowerLeft.y_; }
  [[nodiscard]] int xTo() const noexcept { return _upperRight.x_; }
  [[nodiscard]] int yTo() const noexcept { return _upperRight.y_; };

 private:
  Point _lowerLeft, _upperRight;
};
} // namespace Shapes

#endif //RECTANGLE_H
