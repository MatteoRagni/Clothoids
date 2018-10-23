#include <boost/python.hpp>
#include <exception>
#include <string>

using namespace boost::python;
//using namespace G2lib;

struct G2libArgumentError : public std::exception {
  std::string err;
  G2libArgumentError(std::string err_) : err(err_) {}
  ~G2libArgumentError() throw () {};
  const char * what() const throw () { return err.c_str(); }
};
std::string G2libErrorStrings[] = {
  "Input list len must be 2"
};
void pyG2lib_error0(G2libArgumentError const& x) {
    PyErr_SetString(PyExc_UserWarning, G2libErrorStrings[0].c_str());
}

#include "LineSegmentWrap.hh"
#include "CircleArcWrap.hh"

BOOST_PYTHON_MODULE(G2lib) {
  register_exception_translator<G2libArgumentError>(pyG2lib_error0);

  class_< pyLineSegment >("LineSegment", init< real_type, real_type, real_type, real_type >())
      .def(init< pyLineSegment const & >())
      .def(init<>())
      .def(init<list, list>())
      .def("copy", &pyLineSegment::copy)
      .add_property("xBegin", &pyLineSegment::xBegin)
      .add_property("yBegin", &pyLineSegment::yBegin)
      .add_property("xEnd", &pyLineSegment::xEnd)
      .add_property("yEnd", &pyLineSegment::yEnd)
      .add_property("theta", &pyLineSegment::theta)
      .add_property("sinTheta", &pyLineSegment::sinTheta)
      .add_property("cosTheta", &pyLineSegment::cosTheta)
      .add_property("length", &pyLineSegment::length)
      .def("build", &pyLineSegment::build)
      .def("build_2P", &pyLineSegment::build_2P_0)
      .def("build_2P", &pyLineSegment::build_2P_1)
      .def("X", &pyLineSegment::X)
      .def("Y", &pyLineSegment::Y)
      .def("eval", &pyLineSegment::eval_0)
      .def("eval_D", &pyLineSegment::eval_D_0)
      .def("eval_DD", &pyLineSegment::eval_DD_0)
      .def("eval_DDD", &pyLineSegment::eval_DDD_0)
      .def("eval", &pyLineSegment::eval_1)
      .def("eval_D", &pyLineSegment::eval_D_1)
      .def("eval_DD", &pyLineSegment::eval_DD_1)
      .def("eval_DDD", &pyLineSegment::eval_DDD_1)
      .def("trim", &pyLineSegment::trim)
      .def("translate", &pyLineSegment::translate)
      .def("translate", &pyLineSegment::translate_0)
      .def("rotate", &pyLineSegment::rotate)
      .def("rotate", &pyLineSegment::rotate_0)
      .def("reverse", &pyLineSegment::reverse)
      .def("changeOrigin", &pyLineSegment::changeOrigin)
      .def("closestPoint", &pyLineSegment::closestPoint_0)
      .def("closestPoint", &pyLineSegment::closestPoint_1)
      .def("distance", &pyLineSegment::distance_0)
      .def("distance", &pyLineSegment::distance_1)
      .def("findST", &pyLineSegment::findST_0)
      .def("findST", &pyLineSegment::findST_1)
      .def("p1p2", &pyLineSegment::p1p2_0)
      .def("intersect", &pyLineSegment::intersect);

  class_< pyCircleArc >("CircleArc", init<>())
    .def(init<list, real_type, real_type, real_type>())
    .def(init<real_type, real_type, real_type, real_type, real_type>())
    .add_property("sinTheta0", &pyCircleArc::sinTheta0)
    .add_property("cosTheta0", &pyCircleArc::cosTheta0)
    .add_property("kappa", &pyCircleArc::kappa)
    .add_property("length", &pyCircleArc::length)
    .add_property("xBegin", &pyCircleArc::xBegin)
    .add_property("yBegin", &pyCircleArc::yBegin)
    .add_property("thetaBegin", &pyCircleArc::thetaBegin)
    .add_property("xEnd", &pyCircleArc::xEnd)
    .add_property("yEnd", &pyCircleArc::yEnd)
    .add_property("thetaEnd", &pyCircleArc::thetaEnd)
    .add_property("thetaTotalVariation", &pyCircleArc::thetaTotalVariation)
    .add_property("deltaTheta", &pyCircleArc::deltaTheta)
    .def("copy", &pyCircleArc::copy)
    .def("lenTolerance", &pyCircleArc::lenTolerance)
    .def("build", &pyCircleArc::build)
    .def("build", &pyCircleArc::build_0)
    .def("build_G1", &pyCircleArc::build_G1)
    .def("build_G1", &pyCircleArc::build_G1_0)
    .def("build_3P", &pyCircleArc::build_3P)
    .def("build_3P", &pyCircleArc::build_3P_0)
    .def("theta", &pyCircleArc::theta)
    .def("theta_D", &pyCircleArc::theta_D)
    .def("theta_DD", &pyCircleArc::theta_DD)
    .def("theta_DDD", &pyCircleArc::theta_DDD)
    .def("thetaMinMax", &pyCircleArc::thetaMinMax_0)
    .def("X", &pyCircleArc::X)
    .def("X_D", &pyCircleArc::X_D)
    .def("X_DD", &pyCircleArc::X_DD)
    .def("X_DDD", &pyCircleArc::X_DDD)
    .def("Y", &pyCircleArc::Y)
    .def("Y_D", &pyCircleArc::Y_D)
    .def("Y_DD", &pyCircleArc::Y_DD)
    .def("Y_DDD", &pyCircleArc::Y_DDD)
    .def("tg_X", &pyCircleArc::tg_x)
    .def("tg_y", &pyCircleArc::tg_y)
    .def("nor_X", &pyCircleArc::nor_x)
    .def("nor_y", &pyCircleArc::nor_y)
    .def("XY", &pyCircleArc::XY_0)
    .def("XY", &pyCircleArc::XY_1)
    .def("TG", &pyCircleArc::TG_0)
    .def("NOR", &pyCircleArc::NOR_0)
    .def("NOR_D", &pyCircleArc::NOR_D_0)
    .def("NOR_DD", &pyCircleArc::NOR_DD_0)
    .def("NOR_DDD", &pyCircleArc::NOR_DDD_0)    
    .def("eval", &pyCircleArc::eval_0)
    .def("eval_D", &pyCircleArc::eval_D_0)
    .def("eval_DD", &pyCircleArc::eval_DD_0)
    .def("eval_DDD", &pyCircleArc::eval_DDD_0)
    .def("eval", &pyCircleArc::eval_1)
    .def("eval_D", &pyCircleArc::eval_D_1)
    .def("eval_DD", &pyCircleArc::eval_DD_1)
    .def("eval_DDD", &pyCircleArc::eval_DDD_1)
    .def("trim", &pyCircleArc::trim)
    .def("changeCurvilinearOrigin", &pyCircleArc::changeCurvilinearOrigin)
    .def("changeOrigin", &pyCircleArc::changeOrigin)
    .def("changeOrigin", &pyCircleArc::changeOrigin_0)
    .def("rotate", &pyCircleArc::rotate)
    .def("rotate", &pyCircleArc::rotate_0)
    .def("translate", &pyCircleArc::translate)
    .def("translate", &pyCircleArc::translate_0)
    .def("scale", &pyCircleArc::scale)
    .def("reverse", &pyCircleArc::reverse)
    .def("bbTriangle", &pyCircleArc::bbTriangle_0)
    .def("closestPoint", &pyCircleArc::closestPoint_0)
    .def("closestPoint", &pyCircleArc::closestPoint_1)
    .def("distance", &pyCircleArc::distance_0)
    .def("distance", &pyCircleArc::distance_1)
    .def("findST", &pyCircleArc::findST_0)
    .def("findST", &pyCircleArc::findST_1);
};