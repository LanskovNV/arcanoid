#ifndef GLUT_CALLBACKS_H
#define GLUT_CALLBACKS_H
// leins, 13.05.2018

#define WIN_H 600
#define WIN_W 800

// glut callback functions
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Mouse(int button, int state, int x, int y);
void Special(int key, int x, int y);
void PassiveMotion(int x, int y);

#endif // GLUT_CALLBACKS_H
