// leins 17.04.2018

#include <iostream>
#include <cstring>
#include <GL/gl.h>
#include <GL/glut.h>
#include "button_cl.h"

using namespace std;

void button_cl::change_state()
{
  state = !state;
} // end of change_state function

void button_cl::draw()
{
    color_class drawColor;
    int length = name.size();
    float xLeft = pos.get_x();
    float yUp = pos.get_y();

    // setting up color (by state)
    if (!state)
        drawColor = color;
    else
        drawColor = hightColor;

    // draw button
    glBegin(GL_QUADS);
    glColor4f(drawColor.get_r(), drawColor.get_g(), drawColor.get_b(), drawColor.get_a());
    glVertex2d(xLeft, yUp);
    glVertex2d(xLeft + WEIGTH, yUp);
    glVertex2d(xLeft + WEIGTH, yUp - HIGTH);
    glVertex2d(xLeft, yUp - HIGTH);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0, 0, 0, 1);
    glVertex2d(xLeft + WEIGTH - 0.01, yUp);
    glVertex2d(xLeft + WEIGTH, yUp);
    glVertex2d(xLeft + WEIGTH, yUp - HIGTH);
    glVertex2d(xLeft+ WEIGTH - 0.01, yUp - HIGTH);
    glEnd();

    // draw button_name
    glColor3f(0, 0, 0);
    glRasterPos2f(xLeft, yUp - HIGTH * 3 / 4);
    for (int i = 0; i < length; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, name[i]);
} // end of draw function

void button_cl::init(fstream &stream)
{
  string curStr;
  float xLeft;
  float yUp;

  stream >> curStr;
    while (!stream.eof() && curStr != "ButtonEnd")
    {
      if (curStr == "Position")
      {
        stream >> xLeft;
        stream >> yUp;
        pos.init(xLeft, yUp);
      }
      else if (curStr == "Color")
      {
        float r, g, b;
        stream >> r;
        stream >> g;
        stream >> b;
        color.color_init(r, g, b, 1);
      }
      else if (curStr == "HightColor")
      {
        float r, g, b;
        stream >> r;
        stream >> g;
        stream >> b;
        hightColor.color_init(r, g, b, 1);
      }
      else if (curStr == "Name")
      {
         stream >> name;
      }
      else
      {
        cout << "ERROR:(button_cl.cpp, init func)incorrect menu file" << endl;
        break;
      }
      stream >> curStr;
    }
    state = false;
} // end of init function

game_mode_t button_cl::new_mode()
{
  if (state)
  {
    if (name == "start_game")
      return m_game;
    else if (name == "to_start")
      return m_start;
    else if (name == "about")
      return m_help;
    else if (name == "exit")
      return m_exit;
    else
    {
      cout << "ERROR:(button_cl.cpp new_mode func - incorrect mode)" << endl;
      return m_exit;
    }
  }
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  return m_exit;
} // end of new_mode function

bool button_cl::in_button(float x, float y)
{
  float xLeft = pos.get_x();
  float yUp = pos.get_y();

  if (x >= xLeft && x <= xLeft + WEIGTH)
    if (y <= yUp && y >= yUp - HIGTH)
      return true;
  return false;
} // end of in_button func
