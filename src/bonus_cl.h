#ifndef BONUS_CL_H
#define BONUS_CL_H
// leins, 16.05.2018

#include "color_class.h"

enum type_t
{
  fast,
  slow
};

class bonus_cl
{
private:
  type_t type;
  float x;
  float y;
  color_class color;

public:
  void init();
  void draw();
  void process();
};

#endif // BONUS_CL_H
