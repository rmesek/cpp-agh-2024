#include "shapecomposite.h"
#include "shape.h"

namespace Shapes {
ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1,
                               std::shared_ptr<Shape> shape2,
                               ShapeOperation operation) noexcept
    : _shape1(std::move(shape1)), _shape2(std::move(shape2)), _operation(operation) {}

bool ShapeComposite::isIn(int x, int y) const noexcept {
  switch (_operation) {
    case ShapeOperation::INTERSECTION: return _shape1->isIn(x, y) && _shape2->isIn(x, y);
    case ShapeOperation::SUM: return _shape1->isIn(x, y) || _shape2->isIn(x, y);
    case ShapeOperation::DIFFERENCE: return _shape1->isIn(x, y) && !_shape2->isIn(x, y);
  }
  return false;
}
} // namespace Shapes