// leins, 13.05.2018

#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ball_cl.h"

// init and put to start position
void ball_cl::init()
{
  // color is here
  float r = 1, g = 0, b = 0, a = 1;

  radius = START_RADIUS;
  center.init(0, DOWN_POS + radius); // start ball position
  norm.init(0.01, 0.01); // start normal direction
  color.color_init(r, g, b, a);
} // end of init func

// moving
void ball_cl::change_step()
{
  float newX = center.get_x() + norm.get_x();
  float newY = center.get_y() + norm.get_y();

  center.init(newX, newY);
} // end of change_step function

void ball_cl::draw()
{
  float i;
  const float sepCnt = 20;
  const float pi = 3.14159265;

  glColor4f(color.get_r(), color.get_g(), color.get_b(), color.get_a());

  glBegin(GL_TRIANGLE_FAN);
  glVertex2d(center.get_x(), center.get_y());
  for (i = 0; i < sepCnt; i++)
  {
    float angl = i / (sepCnt - 1) * 2.0 * pi;
    glVertex2d(center.get_x() + radius * cos(angl), center.get_y() + radius * sin(angl));
  }
  glEnd();
} // end of draw function





