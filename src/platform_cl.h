#ifndef PLATFORM_CL_H
#define PLATFORM_CL_H
// leins, 13.05.2018

#include "color_class.h"
#include "ball_cl.h"

class platform_cl
{
private:
  color_class color;
  float width;
  float xLeft;
  float speed;

public:
  void init();
  void draw();
  void change_pos(char sign);
  void process(ball_cl &ball);
};

#endif // PLATFORM_CL_H
