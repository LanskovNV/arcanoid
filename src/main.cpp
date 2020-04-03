// leins, 10.04.2018

#include <GL/gl.h>
#include <GL/glut.h>
#include "glut_callbacks.h"
#include "list_cl.h"
#include "game_cl.h"

using namespace std;

// global variables (used in callback functions)
game_cl g_game;
list_cl g_menu_list;

int main(int argc, char *argv[])
{
  // initialization
  g_game.init(m_start, 0, 3);
  g_menu_list.init(g_game.get_name());

  // glut begin
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WIN_W, WIN_H);
  glutCreateWindow("menu");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutMouseFunc(Mouse);
  glutSpecialFunc(Special);
  glutPassiveMotionFunc(PassiveMotion);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glutMainLoop();
  // glut end

  return 0;
}// end of main
