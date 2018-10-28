#include <exception>
#include <string>

#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Object.hpp"
#include "rice/Module.hpp"

#include "../lib/include/G2lib.hh"

using namespace G2lib;
using namespace Rice;

//struct G2libArgumentError : public std::exception {
//  std::string err;
//  G2libArgumentError(std::string err_) : err(err_) {}
//  ~G2libArgumentError() throw () {};
//  const char * what() const throw () { return err.c_str(); }
//};
std::string G2libErrorStrings[] = {
  "Input list len must be 2"
};
// void rbG2lib_error0(G2libArgumentError const& exp) {
//   throw Exception(rb_eArgError, G2libErrorStrings[0].c_str());
// }
const Object NilObject = Object();

#include "LineSegment_rb.hh"

extern "C"
void Init_G2lib() {
  RUBY_TRY {
  Module rb_mG2lib = define_module("G2lib");

  Data_Type<rbLineSegment> rb_cLineSegment = define_class_under<rbLineSegment>(rb_mG2lib, "LineSegment")
  .define_constructor(
      Constructor<rbLineSegment, const Object, const Object, const Object, const Object>(), 
      (Arg("a_") = NilObject, Arg("b_") = NilObject, Arg("c_") = NilObject, Arg("d_") = NilObject))
    .define_method("copy", &rbLineSegment::copy)
    .define_method("xBegin", &rbLineSegment::xBegin_rb)
    .define_method("yBegin", &rbLineSegment::yBegin_rb)
    .define_method("xEnd", &rbLineSegment::xEnd_rb)
    .define_method("yEnd", &rbLineSegment::yEnd_rb)
    .define_method("theta", &rbLineSegment::theta_rb)
    .define_method("sinTheta", &rbLineSegment::sinTheta_rb)
    .define_method("cosTheta", &rbLineSegment::cosTheta_rb)
    .define_method("length", &rbLineSegment::length_rb)
    .define_method("build", &rbLineSegment::build_rb)
    .define_method("build_2P", &rbLineSegment::build_2P_rb, (Arg("a"), Arg("b"), Arg("c") = NilObject, Arg("d") = NilObject))
    .define_method("x", &rbLineSegment::X_rb)
    .define_method("y", &rbLineSegment::Y_rb)
    .define_method("eval", &rbLineSegment::eval_rb, (Arg("s"), Arg("t") = NilObject))
    .define_method("eval_D", &rbLineSegment::eval_D_rb, (Arg("s"), Arg("t") = NilObject))
    .define_method("eval_DD", &rbLineSegment::eval_DD_rb, (Arg("s"), Arg("t") = NilObject))
    .define_method("eval_DDD", &rbLineSegment::eval_DDD_rb, (Arg("s"), Arg("t") = NilObject))
    .define_method("trim", &rbLineSegment::trim_rb)
    .define_method("translate", &rbLineSegment::translate_rb, (Arg("a"), Arg("b") = NilObject))
    .define_method("rotate", &rbLineSegment::rotate_rb, (Arg("theta"), Arg("a"), Arg("b") = NilObject))
    .define_method("reverse", &rbLineSegment::reverse_rb)
    .define_method("changeOrigin", &rbLineSegment::changeOrigin_rb, (Arg("a"), Arg("b") = NilObject))
    .define_method("closestPoint", &rbLineSegment::closestPoint_rb, (Arg("a"), Arg("b") = NilObject))
    .define_method("distance", &rbLineSegment::distance_rb, (Arg("a"), Arg("b") = NilObject))
    .define_method("findST", &rbLineSegment::findST_rb, (Arg("a"), Arg("b") = NilObject))
    .define_method("p1p2", &rbLineSegment::p1p2_rb)
    .define_method("intersect", &rbLineSegment::intersect_rb);
  }
  RUBY_CATCH
}