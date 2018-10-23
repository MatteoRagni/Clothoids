#ifndef LINESEGMENT_WRAP_HH
#define LINESEGMENT_WRAP_HH

#include <boost/python.hpp>
#include <exception>
#include <string>
#include "../src/Line.hh"

using namespace boost::python;
using namespace G2lib;

class pyLineSegment : public LineSegment {
 public:
  using LineSegment::LineSegment;

  pyLineSegment(list p1, list p2) {
    build_2P_1(p1, p2);
  }

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

  tuple findST_0(real_type x, real_type y) {
    real_type s, t;
    LineSegment::findST(x, y, s, t);
    return make_tuple(s, t);
  }

  tuple findST_1(list p) {
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

#endif /* LINESEGMENT_WRAP_HH */