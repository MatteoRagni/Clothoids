#ifndef CIRCLEARC_WRAP_HH
#define CIRCLEARC_WRAP_HH

#include <boost/python.hpp>
#include <exception>
#include <string>
#include "../src/Circle.hh"

using namespace boost::python;
using namespace G2lib;

class pyCircleArc : public CircleArc {
 public:
  using CircleArc::CircleArc;

  pyCircleArc(list p, real_type theta0, real_type k, real_type L) { build_0(p, theta0, k, L); }

  void copy(pyCircleArc const& c) { CircleArc::copy(c); }

  void build_0(list p, real_type theta0, real_type k, real_type L) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    CircleArc::build(extract< real_type >(p[0]), extract< real_type >(p[1]), theta0, k, L);
  }

  bool build_G1_0(list p0, real_type theta0, list p1) {
    if ((len(p1) != 2) || (len(p0) != 2))
      throw G2libArgumentError(G2libErrorStrings[0]);
    return CircleArc::build_G1(extract< real_type >(p0[0]), extract< real_type >(p0[1]), theta0,
                               extract< real_type >(p1[0]), extract< real_type >(p1[1]));
  }

  bool build_3P_0(list p0, list p1, list p2) {
    if ((len(p0) != 2) || (len(p1) != 2) || (len(p2) != 2))
      throw G2libArgumentError(G2libErrorStrings[0]);
    return CircleArc::build_3P(extract< real_type >(p0[0]), extract< real_type >(p0[1]), extract< real_type >(p1[0]),
                               extract< real_type >(p1[1]), extract< real_type >(p2[0]), extract< real_type >(p2[1]));
  }

  tuple thetaMinMax_0() {
    real_type thMin, thMax;
    CircleArc::thetaMinMax(thMin, thMax);
    return make_tuple(thMin, thMax);
  }

  list XY_0(real_type s) {
    real_type x, y;
    list result;
    CircleArc::XY(s, x, y);
    result.append(x);
    result.append(y);
    return result;
  }

  list XY_1(real_type s, real_type t) {
    real_type x, y;
    list result;
    CircleArc::XY(s, t, x, y);
    result.append(x);
    result.append(y);
    return result;
  }

  tuple TG_0(real_type s) {
    real_type tx, ty;
    list result;
    CircleArc::TG(s, tx, ty);
    return make_tuple(tx, ty);
  }

  tuple NOR_0(real_type s) {
    real_type nx, ny;
    list result;
    CircleArc::NOR(s, nx, ny);
    return make_tuple(nx, ny);
  }

  tuple NOR_D_0(real_type s) {
    real_type nx_D, ny_D;
    list result;
    CircleArc::NOR_D(s, nx_D, ny_D);
    return make_tuple(nx_D, ny_D);
  }

  tuple NOR_DD_0(real_type s) {
    real_type nx_DD, ny_DD;
    list result;
    CircleArc::NOR_DD(s, nx_DD, ny_DD);
    return make_tuple(nx_DD, ny_DD);
  }

  tuple NOR_DDD_0(real_type s) {
    real_type nx_DDD, ny_DDD;
    list result;
    CircleArc::NOR_DDD(s, nx_DDD, ny_DDD);
    return make_tuple(nx_DDD, ny_DDD);
  }

  list eval_0(real_type s) {
    real_type x, y;
    list result;
    CircleArc::eval(s, x, y);
    result.append(x);
    result.append(y);
    return result;
  }

  list eval_1(real_type s, real_type t) {
    real_type x, y;
    list result;
    CircleArc::eval(s, t, x, y);
    result.append(x);
    result.append(y);
    return result;
  }

  list eval_D_0(real_type s) {
    real_type x_D, y_D;
    list result;
    CircleArc::eval_D(s, x_D, y_D);
    result.append(x_D);
    result.append(y_D);
    return result;
  }

  list eval_D_1(real_type s, real_type t) {
    real_type x_D, y_D;
    list result;
    CircleArc::eval_D(s, t, x_D, y_D);
    result.append(x_D);
    result.append(y_D);
    return result;
  }

  list eval_DD_0(real_type s) {
    real_type x_DD, y_DD;
    list result;
    CircleArc::eval_DD(s, x_DD, y_DD);
    result.append(x_DD);
    result.append(y_DD);
    return result;
  }

  list eval_DD_1(real_type s, real_type t) {
    real_type x_DD, y_DD;
    list result;
    CircleArc::eval_DD(s, t, x_DD, y_DD);
    result.append(x_DD);
    result.append(y_DD);
    return result;
  }

  list eval_DDD_0(real_type s) {
    real_type x_DDD, y_DDD;
    list result;
    CircleArc::eval_DDD(s, x_DDD, y_DDD);
    result.append(x_DDD);
    result.append(y_DDD);
    return result;
  }

  list eval_DDD_1(real_type s, real_type t) {
    real_type x_DDD, y_DDD;
    list result;
    CircleArc::eval_DDD(s, t, x_DDD, y_DDD);
    result.append(x_DDD);
    result.append(y_DDD);
    return result;
  }

  void changeOrigin_0(list p)  {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    CircleArc::changeOrigin(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  void translate_0(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    CircleArc::translate(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  void rotate_0(real_type angle, list center) {
    if (len(center) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    CircleArc::rotate(angle, extract<real_type>(center[0]), extract<real_type>(center[1]));
  }

  tuple bbTriangle_0() {
    real_type p0[2], p1[2], p2[2];
    bool val = CircleArc::bbTriangle(p0, p1, p2);
    if (val) {
      list l_p0, l_p1, l_p2;
      l_p0.append(p0[0]); l_p0.append(p0[1]);
      l_p1.append(p1[0]); l_p0.append(p1[1]);
      l_p2.append(p2[0]); l_p0.append(p2[1]);
      return make_tuple(val, l_p0, l_p1, l_p2);
    }
    return make_tuple(val);
  }

  tuple closestPoint_0(real_type x, real_type y) {
    real_type d, X, Y, S;
    list result;
    d = CircleArc::closestPoint(x, y, X, Y, S);
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
    d = CircleArc::distance(x, y, S);
    return make_tuple(d, S);
  }

  tuple distance_1(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    return distance_0(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }

  tuple findST_0(real_type x, real_type y) {
    real_type s, t;
    CircleArc::findST(x, y, s, t);
    return make_tuple(s, t);
  }

  tuple findST_1(list p) {
    if (len(p) != 2)
      throw G2libArgumentError(G2libErrorStrings[0]);
    return findST_0(extract<real_type>(p[0]), extract<real_type>(p[1]));
  }
};

#endif /* CIRCLEARC_WRAP_HH */