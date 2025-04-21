#include "rectangle.h"

namespace Shapes {
Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) noexcept : _lowerLeft(xFrom, yFrom),
                                                               _upperRight(xTo, yTo) {}

bool Rectangle::isIn(int x, int y) const noexcept {
  return x >= _lowerLeft.x_ && x <= _upperRight.x_ && y >= _lowerLeft.y_ && y <= _upperRight.y_;
}
} // namespace Shapes