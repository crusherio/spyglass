#ifndef SPYGLASS_CONTOUR_H_
#define SPYGLASS_CONTOUR_H_

#include "spyglass.h"

namespace Spyglass {

  SG_GEN_GET_OBJECT_FUNCTION(SG_GET_CONTOUR, std::vector<cv::Point *>);

  namespace Contour {
    void define_ruby_class();
    VALUE get_ruby_class();

    static VALUE rb_alloc(VALUE self);
    static void rb_free(std::vector<cv::Point *> *contour);
    static VALUE rb_initialize(int argc, VALUE *argv, VALUE self);
    static VALUE rb_get_corners(VALUE self);
    static VALUE rb_get_rect(VALUE self);
    static VALUE rb_is_convex(VALUE self);

    std::vector<cv::Point> to_value_vector(std::vector<cv::Point *> *contour);
    VALUE from_cvpoint_vector(std::vector<cv::Point> contours);
    VALUE from_contour_vector(std::vector<std::vector<cv::Point> > contours);
  }
}

#endif // SPYGLASS_CONTOUR_H_
