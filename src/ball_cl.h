#ifndef BALL_CL_H
#define BALL_CL_H
// leins, 13.05.2018

#include "color_class.h"
#include "point_cl.h"

#define DOWN_POS -0.8 // platform level (y coordinate)
#define START_RADIUS 0.025

class ball_cl
{
private:
  point_cl norm;
  point_cl center;
  float radius;
  color_class color;

public:
  void change_n(float xSign, float ySign) {   norm.change(xSign, ySign); }
  color_class get_color() { return color; }
  point_cl get_center() { return center; }
  float get_r() { return radius; }

  void init(); // init and put to start position
  void draw();
  void change_step();
};

#endif // BALL_CL_H
