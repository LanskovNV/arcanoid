// leins, 13.05.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include "glut_callbacks.h"
#include "game_cl.h"
#include "list_cl.h"

using namespace std;

// global variables used in callbacks functions
extern game_cl g_game;
extern list_cl g_menu_list;

void Keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
}// End of Keyboard function

void Display(void)
{
  game_mode_t mode = g_game.get_mode();

  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  if (mode == m_game)
  {
    g_game.process();
    g_game.draw();
    g_menu_list.draw();
  }
  else
  {
    g_game.process();
    g_menu_list.draw();
  }

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}// End of Display function

void PassiveMotion(int x, int y)
{
  float x1 = float(x) / WIN_W * 2 - 1;
  float y1 = -float(y) / WIN_H * 2 + 1;

  g_menu_list.passive(x1, y1);
} // end of passive motion func

void Mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN)
    {
      game_mode_t newMode = g_menu_list.new_mode();
      g_game.init(newMode, 0, 3);
      if (newMode == m_game)
        g_menu_list.init(GAME_MENU_FILE);
      else if (newMode == m_help || newMode == m_win)
        g_menu_list.init(HELP_MENU_FILE);
      else
        g_menu_list.init(START_MENU_FILE);
    }
} // end of Mouse function

// function to callback arrows keys
void Special(int key, int x, int y)
{
  if (key == GLUT_KEY_LEFT)
    g_game.proc_platform(-1);
  if (key == GLUT_KEY_RIGHT)
    g_game.proc_platform(1);
}
