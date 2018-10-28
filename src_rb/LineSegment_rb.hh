#ifndef LINE_SEGMENT_RB_HH
#define LINE_SEGMENT_RB_HH

#include <string>

#include <iostream>
#include "../lib/include/Line.hh"
#include "rice/Array.hpp"
#include "rice/Hash.hpp"
#include "rice/protect.hpp"
//#include "ruby.h"

using namespace Rice;
using namespace G2lib;

class rbLineSegment : public LineSegment {

 public:
  rbLineSegment(const Object a = NilObject, const Object b = NilObject, const Object c = NilObject,
                const Object d = NilObject)
      : LineSegment::LineSegment(0, 0, 0, 0) {
    if (a.is_nil() && b.is_nil()) {
      return;
    } else if (std::strcmp((from_ruby<std::string>(a.call("class").to_s())).c_str(), "G2lib::LineSegment") == 0) {
     copy(from_ruby<rbLineSegment>(a));
     return;
    }
    build_rb(a, b, c, d);
  }

  void copy(rbLineSegment const &c) { LineSegment::copy(c); }
  Object xBegin_rb() { return to_ruby(xBegin()); }
  Object yBegin_rb() { return to_ruby(yBegin()); }
  Object xEnd_rb() { return to_ruby(xEnd()); }
  Object yEnd_rb() { return to_ruby(yEnd()); }
  Object theta_rb() { return to_ruby(theta()); }
  Object sinTheta_rb() { return to_ruby(sinTheta()); }
  Object cosTheta_rb() { return to_ruby(cosTheta()); }
  Object length_rb() { return to_ruby(length()); }

  void build_rb(const Object a, const Object b, const Object c, const Object d) {
    build(from_ruby< real_type >(a), from_ruby< real_type >(b), from_ruby< real_type >(c), from_ruby< real_type >(d));
  }

  void build_2P_rb(const Object a, const Object b, const Object c = NilObject, const Object d = NilObject) {
    if (a.is_a(rb_cArray) && b.is_a(rb_cArray)) {
      Array p1(a), p2(b);
      if (p1.size() != 2)
        rb_raise(rb_eArgError, "Size for first element != 2");
      if (p2.size() != 2)
        rb_raise(rb_eArgError, "Size for second element != 2");
      build_2P(from_ruby< real_type >(p1[0]), from_ruby< real_type >(p1[1]), from_ruby< real_type >(p2[0]),
               from_ruby< real_type >(p2[1]));
      return;
    } else {
      real_type x0, y0, x1, y1;
      x0 = from_ruby< real_type >(a);
      y0 = from_ruby< real_type >(b);
      x1 = from_ruby< real_type >(c);
      y1 = from_ruby< real_type >(d);
      build_2P(x0, y0, x1, y1);
    }
  }

  Object X_rb(const Object s) { return to_ruby(X(from_ruby< real_type >(s))); }
  Object Y_rb(const Object s) { return to_ruby(Y(from_ruby< real_type >(s))); }

  Array eval_rb(const Object s, const Object t = NilObject) {
    Array p;
    real_type x, y;
    if (t.is_nil()) {
      eval(from_ruby< real_type >(s), x, y);
    } else {
      eval(from_ruby< real_type >(s), from_ruby< real_type >(t), x, y);
    }
    p.push(to_ruby(x));
    p.push(to_ruby(y));
    return p;
  }

  Array eval_D_rb(const Object s, const Object t = NilObject) {
    Array p;
    real_type x, y;
    if (t.is_nil()) {
      eval_D(from_ruby< real_type >(s), x, y);
    } else {
      eval_D(from_ruby< real_type >(s), from_ruby< real_type >(t), x, y);
    }
    p.push(to_ruby(x));
    p.push(to_ruby(y));
    return p;
  }

  Array eval_DD_rb(const Object s, const Object t = NilObject) {
    Array p;
    real_type x, y;
    if (t.is_nil()) {
      eval_DD(from_ruby< real_type >(s), x, y);
    } else {
      eval_DD(from_ruby< real_type >(s), from_ruby< real_type >(t), x, y);
    }
    p.push(to_ruby(x));
    p.push(to_ruby(y));
    return p;
  }

  Array eval_DDD_rb(const Object s, const Object t = NilObject) {
    Array p;
    real_type x, y;
    if (t.is_nil()) {
      eval_DDD(from_ruby< real_type >(s), x, y);
    } else {
      eval_DDD(from_ruby< real_type >(s), from_ruby< real_type >(t), x, y);
    }
    p.push(to_ruby(x));
    p.push(to_ruby(y));
    return p;
  }

  void trim_rb(const Object s_begin, const Object s_end) {
    trim(from_ruby< real_type >(s_begin), from_ruby< real_type >(s_end));
  }

  void translate_rb(const Object a, const Object b = NilObject) {
    if (a.is_a(rb_cArray)) {
      Array p(a);
      if (p.size() != 2)
        rb_raise(rb_eArgError, "Size for first element != 2");
      translate(from_ruby< real_type >(p[0]), from_ruby< real_type >(p[1]));
      return;
    }
    translate(from_ruby< real_type >(a), from_ruby< real_type >(b));
  }

  void rotate_rb(const Object theta, const Object a, const Object b = NilObject) {
    if (a.is_a(rb_cArray)) {
      Array p(a);
      if (p.size() != 2)
        rb_raise(rb_eArgError, "Size for first element != 2");
      rotate(from_ruby< real_type >(theta), from_ruby< real_type >(p[0]), from_ruby< real_type >(p[1]));
      return;
    }
    rotate(from_ruby< real_type >(theta), from_ruby< real_type >(a), from_ruby< real_type >(b));
  }

  void changeOrigin_rb(const Object a, const Object b = NilObject) {
    if (a.is_a(rb_cArray)) {
      Array p(a);
      if (p.size() != 2)
        rb_raise(rb_eArgError, "Size for first element != 2");
      changeOrigin(from_ruby< real_type >(p[0]), from_ruby< real_type >(p[1]));
      return;
    }
    changeOrigin(from_ruby< real_type >(a), from_ruby< real_type >(b));
  }

  inline void closestPoint_return(Hash &h, const real_type &x, const real_type &y, const real_type &s, const real_type & d) {
    Array c;
    c.push(to_ruby(x));
    c.push(to_ruby(y));
    h[Symbol("s")] = to_ruby(s);
    h[Symbol("point")] = c;
    h[Symbol("dist")] = to_ruby(d);
  }

  Hash closestPoint_rb(const Object a, const Object b = NilObject) {
    real_type x, y, d, s;
    Hash h;
    Array c;
    if (a.is_a(rb_cArray)) {
      Array p(a);
      if (p.size() != 2)
        rb_raise(rb_eArgError, "Size for first element != 2");
      d = closestPoint(from_ruby< real_type >(p[0]), from_ruby< real_type >(p[1]), x, y, s);
      closestPoint_return(h, x, y, s, d);
      return h;
    }
    d = closestPoint(from_ruby< real_type >(a), from_ruby< real_type >(b), x, y, s);
    closestPoint_return(h, x, y, s, d);
    return h;
  }

  inline void distance_return(Hash & h, const real_type & s, const real_type d) {
    h[Symbol("s")] = s;
    h[Symbol("dist")] = d;
  }

  Object distance_rb(const Object a, const Object b = NilObject) {
    Hash h;
    real_type d, s;
    if (a.is_a(rb_cArray)) {
      Array p(a);
      d = distance(from_ruby<real_type>(p[0]), from_ruby<real_type>(p[1]), s);
      distance_return(h, s, d);
      return h;
    }
    d = distance(from_ruby<real_type>(a), from_ruby<real_type>(b), s);
    distance_return(h, s, d);
    return h;
  }

  void inline findST_return(Hash & h, const real_type & s, const real_type & t) {
    h[Symbol("s")] = to_ruby(s);
    h[Symbol("t")] = to_ruby(t);
  }

  Hash findST_rb(const Object a, const Object b = NilObject) {
    Hash h;
    real_type s, t;
    
    if (a.is_a(rb_cArray)) {
      Array p(a);
      findST(from_ruby< real_type >(p[0]), from_ruby< real_type >(p[1]), s, t);
      findST_return(h, s, t);
      return h;
    }
    findST(from_ruby< real_type >(a), from_ruby< real_type >(b), s, t);
    findST_return(h, s, t);
    return h;
  }

  Hash p1p2_rb() {
    Hash h;
    Array q1;
    Array q2;
    real_type p1[2], p2[2];
    p1p2(p1, p2);
    q1.push(to_ruby(p1[0]));
    q1.push(to_ruby(p1[1]));
    q2.push(to_ruby(p2[0]));
    q2.push(to_ruby(p2[1]));
    h[Symbol("begin")] = q1;
    h[Symbol("end")] = q2;
    return h;
  }

  Hash intersect_rb(const Object l) {
    Hash h;
    real_type s1, s2;
    LineSegment ls = from_ruby<rbLineSegment>(l);
    bool r =intersect(ls, s1, s2);
    h[Symbol("s1")] = to_ruby(s1);
    h[Symbol("s2")] = to_ruby(s2);
    h[Symbol("intersect")] = to_ruby(r);
    return h;
  }

  void reverse_rb(void) { reverse(); }
};

#endif