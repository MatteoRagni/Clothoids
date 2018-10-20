#include <boost/python.hpp>
#include <exception>
#include <string>
#include "../src/Line.hh"

using namespace boost::python;
using namespace G2lib;

struct G2libArgumentError : public std::exception {
  std::string err;
  G2libArgumentError(std::string err_) : err(err_) {}
  ~G2libArgumentError() throw () {};
  const char * what() const throw () { return err.c_str(); }
};
std::string G2libErrorStrings[] = {
  "Input list len must be 2"
};
void pyLineSegment_error0(G2libArgumentError const& x) {
    PyErr_SetString(PyExc_UserWarning, G2libErrorStrings[0].c_str());
}

class pyLineSegment : public G2lib::LineSegment {
 public:
  using LineSegment::LineSegment;
  using LineSegment::translate;

  void copy(pyLineSegment const &c) { LineSegment::copy(c); }

  void build_2P_0(real_type _x0, real_type _y0, real_type _x1, real_type _y1) {
    LineSegment::build_2P(_x0, _y0, _x1, _y1);
  }

  void build_2P_1(list _a, list _b) {
    if ((len(_a) != 2) || (len(_b) != 2))
      throw G2libArgumentError(G2libErrorStrings[0]);
    LineSegment::build_2P(extract< real_type >(_a[0]), extract< real_type >(_a[1]), extract< real_type >(_b[0]),
                          extract< real_type >(_b[1]));
  }

  list findST_0(real_type x, real_type y) {
    real_type s, t;
    list result;
    LineSegment::findST(x, y, s, t);
    result.append(s);
    result.append(t);
    return result;
  }

  list findST_1(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    return findST_0(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  list eval_0(real_type s) {
    real_type x, y;
    list result;
    LineSegment::eval(s, x, y);
    result.append(x);
    result.append(y);
    return result;
  }

  list eval_1(real_type s, real_type t) {
    real_type x, y;
    list result;
    LineSegment::eval(s, t, x, y);
    result.append(x);
    result.append(y);
    return result;
  }

  list eval_D_0(real_type s) {
    real_type x_D, y_D;
    list result;
    LineSegment::eval_D(s, x_D, y_D);
    result.append(x_D);
    result.append(y_D);
    return result;
  }

  list eval_D_1(real_type s, real_type t) {
    real_type x_D, y_D;
    list result;
    LineSegment::eval_D(s, t, x_D, y_D);
    result.append(x_D);
    result.append(y_D);
    return result;
  }

  list eval_DD_0(real_type s) {
    real_type x_DD, y_DD;
    list result;
    LineSegment::eval_DD(s, x_DD, y_DD);
    result.append(x_DD);
    result.append(y_DD);
    return result;
  }

  list eval_DD_1(real_type s, real_type t) {
    real_type x_DD, y_DD;
    list result;
    LineSegment::eval_DD(s, t, x_DD, y_DD);
    result.append(x_DD);
    result.append(y_DD);
    return result;
  }

  list eval_DDD_0(real_type s) {
    real_type x_DDD, y_DDD;
    list result;
    LineSegment::eval_DDD(s, x_DDD, y_DDD);
    result.append(x_DDD);
    result.append(y_DDD);
    return result;
  }

  list eval_DDD_1(real_type s, real_type t) {
    real_type x_DDD, y_DDD;
    list result;
    LineSegment::eval_DDD(s, t, x_DDD, y_DDD);
    result.append(x_DDD);
    result.append(y_DDD);
    return result;
  }

  void translate_0(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    LineSegment::translate(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  void rotate_0(real_type angle, list center) {
    if (len(center) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    LineSegment::rotate(angle, extract<real_type>(center[0]), extract<real_type>(center[1]));
  }

  tuple closestPoint_0(real_type x, real_type y) {
    real_type d, X, Y, S;
    list result;
    d = LineSegment::closestPoint(x, y, X, Y, S);
    result.append(X);
    result.append(Y);
    return make_tuple(d, S, result);
  }

  tuple closestPoint_1(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    return closestPoint_0(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  tuple distance_0(real_type x, real_type y) {
    real_type d, S;
    d = LineSegment::distance(x, y, S);
    return make_tuple(d, S);
  }

  tuple distance_1(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    return distance_0(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  tuple p1p2_0() {
    real_type p1[2], p2[2];
    list p1_l, p2_l;
    LineSegment::p1p2(p1, p2);
    p1_l.append(p1[0]); p1_l.append(p1[1]);
    p2_l.append(p2[0]); p2_l.append(p2[1]);
    return make_tuple(p1_l, p2_l);
  }

  tuple intersect(pyLineSegment const &c) {
    bool f;
    real_type s1, s2;
    f = LineSegment::intersect(c, s1, s2);
    return make_tuple(f, s1, s2);
  } 
};

BOOST_PYTHON_MODULE(G2lib) {
  register_exception_translator<G2libArgumentError>(pyLineSegment_error0);
  class_< pyLineSegment >("LineSegment", init< real_type, real_type, real_type, real_type >())
      .def(init< pyLineSegment const & >())
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
};