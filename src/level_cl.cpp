// leins, 13.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "level_cl.h"

using namespace std;

void level_cl::init(int nLevel, int nLifes)
{
  lifes = nLifes; // num of lives
  numOfLevel = nLevel;
  numOfBricks = (nLevel + 1) * (nLevel + 2);

  // init bricks vector:
  float width = 0.3 - 0.01 * nLevel;
  float deltaX = (2 - 2 * THICK - (nLevel + 2)* width) / (2 * (nLevel + 2) + 1);
  float deltaY = THICK * 2;
  float heigth = 0.1 - 0.01 * (nLevel - 1);
  float xBrick = (-1 + THICK) + 2 * deltaX;
  float yBrick = 1 - THICK - deltaY;
  int cnt = 1;

  for (int i = 0; i < numOfBricks; i++)
  {
    brick_cl brick;

    brick.init(xBrick, yBrick, heigth, width, nLevel);
    xBrick += width + deltaX * 2;
    if (cnt % (nLevel + 2) == 0)
    {
      xBrick = (-1 + THICK) + 2 * deltaX;
      yBrick -= deltaY + heigth;
    }
    bricks.push_back(brick);
    cnt++;
  }

} // end of init function

void level_cl::draw()
{
  glBegin(GL_QUADS);
  glColor4f(1, 1, 0, 1);
  glVertex2d(-1, 1);
  glVertex2d(-1 + THICK, 1);
  glVertex2d(-1 + THICK, -1);
  glVertex2d(-1, -1);
  glEnd();

  glBegin(GL_QUADS);
  glColor4f(1, 1, 0, 1);
  glVertex2d(-1, 1);
  glVertex2d(1, 1);
  glVertex2d(1, 1 - THICK);
  glVertex2d(-1, 1 - THICK);
  glEnd();

  glBegin(GL_QUADS);
  glColor4f(1, 1, 0, 1);
  glVertex2d(1 - THICK, 1);
  glVertex2d(1, 1);
  glVertex2d(1, -1);
  glVertex2d(1 - THICK, -1);
  glEnd();

  for (auto it : bricks)
    it.draw();
} // end of draw function

void level_cl::process(ball_cl &ball)
{
  point_cl curPos = ball.get_center();
  float x = curPos.get_x();
  float y = curPos.get_y();
  vector<brick_cl>::iterator it;

  if (x <= -1 + THICK || x >= 1 - THICK)
    ball.change_n(-1, 1);
  if (y >= 1 - THICK)
    ball.change_n(1, -1);

  for (it = bricks.begin(); it != bricks.end(); it++)
  {
    if ((*it).get_alpha() <= 0)
    {
      bricks.erase(it);
      break;
    }
    (*it).process(ball);
  }
} // end of process function
