#ifndef LEVEL_CL_H
#define LEVEL_CL_H
// leins, 13.05.2018

#include <vector>
#include "brick_cl.h"

#define MAX_LEVEL 3 // 0, 1, 2
#define THICK 0.04

// here is main game parameters
class level_cl
{
private:
  int numOfBricks;
  int numOfLevel;
  int lifes;
  std::vector<brick_cl> bricks;

public:
  int num_bricks() { return numOfBricks; }
  int num_level() { return numOfLevel; }
  std::vector<brick_cl> get_bricks() { return bricks; }
  int get_lifes() { return lifes; }
  void death() { --lifes; }

  void init(int nLevel, int nLifes);
  void draw();
  void process(ball_cl &ball);
};

#endif // LEVEL_CL_H
