#ifndef G2LIB_WRAP_H
#define G2LIB_WRAP_H

#include "../src/Line.hh"


typedef struct LineSegment_wrap LineSegment_wrap;
inline LineSegment_wrap * LineSegment_CC2C(G2lib::LineSegment * l) {
  return reinterpet_cast<LineSegment_wrap *>(l);
}

qq


#ifdef __cplusplus__
extern "C" {
#endif 

LineSegment_wrap * LineSegment_new();
LineSegment_wrap * LineSegment_new_value(double _x0, double _y0, double _theta0, double _L);
LineSegment_wrap * LineSegment_new_copy(const LineSegment_wrap * c);
void LineSegment_build(LineSegment_wrap * self, double _x0, double _y0, double _theta0, double _L);
void LineSegment_build_2P(LineSegment_wrap * self, double _x0, double _y0, double _x1, double _y1);


#ifdef __cplusplus__
};
#endif 
#endif