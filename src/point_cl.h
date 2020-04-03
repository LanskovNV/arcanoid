#ifndef POINT_CL_H
#define POINT_CL_H
// leins, 16.05.2018

// application current moide type
enum game_mode_t
{
  m_exit,
  m_game,
  m_start,
  m_help,
  m_lose,
  m_win
};

class point_cl // the vector is the same
{
private:
  float x;
  float y;

public:
  void init(float x0, float y0) {x = x0; y = y0;}
  float get_x() {return x;}
  float get_y() {return y;}
  void change(float changeX, float changeY)
  {
    x *= changeX;
    y *= changeY;
  }
};


#endif // POINT_CL_H
