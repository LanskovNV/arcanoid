// leins, 17.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include "game_cl.h"

using namespace std;

void game_cl::proc_platform(char sign)
{
  platform.change_pos(sign);
} // end of func

void game_cl::draw()
{
  levels[currentLevel].draw();
  ball.draw();
  platform.draw();
  current_info();
} // end of draw function

void game_cl::set_mode(game_mode_t newMode)
{
  mode = newMode;
} // end of set_mode function

string game_cl::get_name()
{
  switch(mode)
  {
  case m_start:
    return START_MENU_FILE;
  case m_help:
  case m_game:
    return HELP_MENU_FILE;
  default:
    return "error.txt";
  }
} // end of get_name function

void game_cl::init(game_mode_t newMode, int startLevel, int nLifes)
{
  mode = newMode;
  switch (mode)
  {
  case m_start:
  case m_exit:
    break;
  case m_game:
    ball.init();
    platform.init();
    currentLevel = startLevel; // change first level
    for (int i = 1 ; i <= MAX_LEVEL; i++)
    {
      levels[i-1].init(i, nLifes);
    }
    break;
  case m_win:
    break;
  case m_help:
    break;
  default:
    cout << "ERROR:(game_cl.cpp init func)unknown game mode" << endl;
    break;
  }
} // end of init function

void game_cl::process()
{
  game_mode_t m = this->get_mode();
  point_cl pos = ball.get_center();

  switch (m)
  {
  case m_game:
    if (levels[currentLevel].get_bricks().empty() && currentLevel < 2)
      currentLevel++;
    if (levels[currentLevel].get_bricks().empty() && currentLevel == 2)
      this->init(m_win, currentLevel, 1);

    if (levels[currentLevel].get_lifes() == 0)
      this->set_mode(m_lose);
    else
    {
      ball.change_step();
      platform.process(ball);
      levels[currentLevel].process(ball);
      if (pos.get_y() < DOWN_POS - THICK)
      {
        ball.init();
        platform.init();
        levels[currentLevel].death();
      }
    }
    break;
  case m_win:
    print_info("you win!!!");
    break;
  case m_lose:
    print_info("you lose, try again");
    break;
  case m_help:
    print_info("classic arcanoid game");
    break;
  case m_exit:
    exit(0);
    break;
  default:
    break;
  }
} // end of process function

void game_cl::current_info()
{
  string str;
  stringstream stream1, stream2;

  // print current level
  str = "level: ";
  stream1 << currentLevel + 1;
  str += stream1.str();

  glColor3f(0, 0, 0);
  glRasterPos2f(0.7, -0.9);
  for (unsigned int i = 0; i < str.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);

  // print lifes
  str = "lifes: ";
  stream2 << levels[currentLevel].get_lifes();
  str += stream2.str();

  glColor3f(0, 0, 0);
  glRasterPos2f(0.7, -0.93);
  for (unsigned int i = 0; i < str.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);


} // end of current info function

void game_cl::print_info(std::string str)
{
  if (mode == m_help || mode == m_win || mode == m_lose)
  {
    glColor3f(0, 0, 0);
    glRasterPos2f(-0.3, 0);
    for (unsigned int i = 0; i < str.size(); i++)
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
  }
} // end of PrintInfo func
