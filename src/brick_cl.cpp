// leins, 14.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
//#include <ctime>
#include "brick_cl.h"

void brick_cl::draw()
{
  float xLeft = pos.get_x();
  float yUp = pos.get_y();

  glBegin(GL_QUADS);
  glColor4f(color.get_r(), color.get_g(), color.get_b(), color.get_a());
  glVertex2d(xLeft, yUp);
  glVertex2d(xLeft + width, yUp);
  glVertex2d(xLeft + width, yUp - heigth);
  glVertex2d(xLeft, yUp - heigth);
  glEnd();

} // end of draw function

void brick_cl::init(float x, float y, float h, float w, int degree1)
{
  float r, g, b;

  // every brick have a random color
  //srand(time(NULL));
  r = rand() % 255 / 255.;
  //srand(time(NULL) + r);
  g = rand() % 255 / 255.;
  //srand(time(NULL) + g);
  b = rand() % 255 / 255.;

  color.color_init(r, g, b, 1);
  pos.init(x, y);
  width = w;
  heigth = h;

  degree = degree1;
} // end of init function

// answer is ball in brick
bool brick_cl::in_brick(ball_cl ball)
{
  point_cl p = ball.get_center();
  float x = p.get_x();
  float y = p.get_y();

  if (x >= pos.get_x() && x <= pos.get_x() + width)
    if (y <= pos.get_y() && y >= pos.get_y() - heigth)
      return true;
  return false;
} // end of InBrick function

// TODO: fix ball process!!!
void brick_cl::process(ball_cl &ball)
{
  point_cl center = ball.get_center();
  float x = center.get_x();
  float y = center.get_y();
  bool inBrick = false;
  float xLeft = pos.get_x();
  float yUp = pos.get_y();

  if (x >= xLeft && x <= xLeft + width)
    if (y <= yUp && y >= yUp - heigth)
      inBrick = true;
  if (inBrick)
  {
    if (x + ball.get_r() > xLeft + width ||
        x - ball.get_r() < xLeft)
      ball.change_n(-1, 1); // invert x in normal
    else if (y + ball.get_r() > yUp ||
             y - ball.get_r() < yUp - heigth)
      ball.change_n(1, -1); // invert y in normal

    this->change_alpha();
  }

} // end of Process function
