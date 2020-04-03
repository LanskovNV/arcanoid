// leins, 15.04.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include "platform_cl.h"
#include "level_cl.h"

void platform_cl::init()
{
  float r = 1;
  float g = 0;
  float b = 1;

  width = START_RADIUS * 15; // platform size
  speed = START_RADIUS ; // platform speed
  xLeft = 0 - width / 2;
  color.color_init(r, g, b, 1);
} // end of Init function

void platform_cl::change_pos(char sign)
{  
  if ((sign < 0 && xLeft >= -1 + THICK) ||
      (sign > 0 && xLeft + width <= 1 - THICK))
    xLeft += sign * speed;
} // end of ChangePos function

void platform_cl::process(ball_cl &ball)
{
  point_cl p = ball.get_center();
  float ballX = p.get_x();
  float ballY = p.get_y();

  if ( ballX > xLeft && ballX < xLeft + width && ballY <= DOWN_POS && ballY >= DOWN_POS - THICK)
    ball.change_n(1, -1);

} // end of Process function

void platform_cl::draw()
{
  // draw platform
  glBegin(GL_QUADS);
  glColor4d(color.get_r(), color.get_g(), color.get_b(), color.get_a());
  glVertex2d(xLeft, DOWN_POS);
  glVertex2d(xLeft + width, DOWN_POS);
  glVertex2d(xLeft + width, DOWN_POS - THICK);
  glVertex2d(xLeft, DOWN_POS - THICK);
  glEnd();
} // end of Draw function




