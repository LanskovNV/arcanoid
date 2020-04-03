#pragma once
#ifndef METHODS_CL_H
#define METHODS_CL_H

// leins, 17.04.2018

#include <string>
#include "game_cl.h"

class methods_cl
{
public:
  virtual void Draw() {}
  virtual void Init(std::string fileName) {}
  virtual void Action(game_cl &game) {}
};

#endif // METHODS_CL_H
