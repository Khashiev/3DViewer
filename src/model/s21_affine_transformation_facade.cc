#include "s21_affine_transformation_facade.h"

namespace s21 {

void AffineTransformationFacade::move(Parser* parser, double move_x,
                                      double move_y, double move_z) {
  AffineTransformation::getInstance().move_points(parser, move_x, move_y,
                                                  move_z);
}

void AffineTransformationFacade::rotate(Parser* parser, Axes axis,
                                        double angle) {
  AffineTransformation::getInstance().rotation_points(parser, axis, angle);
}

void AffineTransformationFacade::scale(Parser* parser, double scale_x,
                                       double scale_y, double scale_z) {
  AffineTransformation::getInstance().scale_points(parser, scale_x, scale_y,
                                                   scale_z);
}

void AffineTransformationFacade::normalize(Parser* parser) {
  AffineTransformation::getInstance().normalize_figure(parser);
}

}  // namespace s21
