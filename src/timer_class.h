#pragma once
#ifndef _TIMER_CLASS
#define _TIMER_CLASS
/* leins, 02.04.2018 */

class timer_class
{
public:
  double delta;
  double lastTime;

  void timer_init();
  void timer_update_frame();
};

#endif
