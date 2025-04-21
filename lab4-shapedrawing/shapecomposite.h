#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>
#include "shape.h"

namespace Shapes {
enum class ShapeOperation { INTERSECTION, SUM, DIFFERENCE };

class ShapeComposite : public Shape {
 public:
  ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation) noexcept;
  [[nodiscard]] bool isIn(int x, int y) const noexcept override;

 private:
  std::shared_ptr<Shape> _shape1;
  std::shared_ptr<Shape> _shape2;
  ShapeOperation _operation;
};
} // namespace Shapes

#endif //SHAPECOMPOSITE_H
