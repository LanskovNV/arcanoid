#ifndef BRICK_CL_H
#define BRICK_CL_H
// leins, 12.05.2018

#include "color_class.h"
#include "ball_cl.h"

class brick_cl
{
private:
  int degree;
  float width;
  float heigth;
  color_class color;
  point_cl pos; // left up point

public:
  float get_alpha() { return color.get_a(); } // check in game_cl: process
  void change_alpha() { color.change_alpha(1. / degree); }
  bool in_brick(ball_cl ball);
  void draw();
  void process(ball_cl &ball);
  void init(float x, float y, float h, float w, int degree1);
};

#endif // BRICK_CL_H
