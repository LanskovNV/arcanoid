#pragma once
#ifndef _COLOR_CLASS
#define _COLOR_CLASS

/* leins, 02.04.2018 */
class color_class
{
private:
  float A;
  float R;
  float G;
  float B;

public:
  void color_init(float r, float g, float b, float a)
  {
    R = r;
    G = g;
    B = b;
    A = a;
  }
  void change_alpha(float delta)
  {
    A -= delta;
  }
  float get_a() { return A; }
  float get_r() { return R; }
  float get_g() { return G; }
  float get_b() { return B; }
};

#endif


