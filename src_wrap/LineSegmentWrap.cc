#include <boost/python.hpp>
#include "../src/Line.hh"

using namespace boost::python;
using namespace G2lib;


class pyLineSegment : public G2lib::LineSegment {
  using LineSegment::LineSegment;

  public:
  void build_2P_0(real_type _x0, real_type _y0, real_type _x1, real_type _y1) {
    LineSegment::build_2P(_x0, _y0, _x1, _y1);
  }

  void build_2P_1(list _a, list _b) {
    if ((len(_a) != 2) || (len(_b) != 2))
      return; // TODO Code for an exception is needed
    LineSegment::build_2P(extract<real_type>(_a[0]), extract<real_type>(_a[1]), extract<real_type>(_b[0]), extract<real_type>(_b[1]));
  }

  list findST_0(real_type x, real_type y) {
    real_type s, t;
    list result;
    LineSegment::findST(x, y, s, t);
    result.append(s);
    result.append(t);
    return result;
  }


};


BOOST_PYTHON_MODULE(G2lib) {

  //void (LineSegment::*build_2P_0)( real_type _x0, real_type _y0, real_type _x1, real_type _y1) = &LineSegment::build_2P;
  //void (LineSegment::*eval_0)(real_type, real_type &, real_type &) const = &LineSegment::eval;
  //void (LineSegment::*eval_1)(real_type, real_type, real_type &, real_type &) const = &LineSegment::eval;

  class_<pyLineSegment>("LineSegment", init<real_type, real_type, real_type, real_type>())
    .def(init<pyLineSegment const &>())
    .def(init<>())
    .def("copy", &pyLineSegment::copy)
    .add_property("xBegin", &pyLineSegment::xBegin)
    .add_property("yBegin", &pyLineSegment::yBegin)
    .add_property("xEnd", &pyLineSegment::xEnd)
    .add_property("yEnd", &pyLineSegment::yEnd)
    .add_property("theta", &pyLineSegment::theta)
    .add_property("sinTheta", &pyLineSegment::sinTheta)
    .add_property("cosTheta", &pyLineSegment::cosTheta)
    .add_property("length", &pyLineSegment::length)
    .def("X", &pyLineSegment::X)
    .def("Y", &pyLineSegment::Y)
    .def("build",  &pyLineSegment::build)
    .def("trim", &pyLineSegment::trim)
    .def("translate", &pyLineSegment::translate)
    .def("rotate", &pyLineSegment::rotate)
    .def("reverse", &pyLineSegment::reverse)
    .def("changeOrigin", &pyLineSegment::changeOrigin)
    .def("build_2P", &pyLineSegment::build_2P_0)
    .def("build_2P", &pyLineSegment::build_2P_1)
    .def("findST", &pyLineSegment::findST_0);

}