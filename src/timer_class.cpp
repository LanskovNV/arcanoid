/* leins, 02.04.2018 */
#include <ctime>
#include "timer_class.h"

void timer_class::timer_init()
{
  lastTime = clock();
  delta = 0;
} // end of func

void timer_class::timer_update_frame()
{
  double newTime = clock() / (double)CLOCKS_PER_SEC;

  delta = newTime - lastTime;
  lastTime = newTime;
} // end of func


