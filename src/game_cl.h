#ifndef GAME_CL_H
#define GAME_CL_H
// leins, 17.05.2018

/******************************
 * all game collisions are here
******************************/

#include <string>
#include <vector>
#include "list_cl.h"
#include "level_cl.h"
#include "ball_cl.h"
#include "platform_cl.h"

// configuration file names
#define START_MENU_FILE "start_menu_list.txt"
#define HELP_MENU_FILE "help_menu_list.txt"
#define GAME_MENU_FILE "game_menu_list.txt"
#define LEVEL_MENU_FILE "level_menu_list.txt"

class game_cl
{
private:
  game_mode_t mode;

  // game parameters:
  int currentLevel;
  ball_cl ball;
  platform_cl platform;
  level_cl levels[MAX_LEVEL];

public:
  game_mode_t get_mode() { return mode; }
  void print_info(std::string str);
  void init(game_mode_t mode, int startLevel, int nLifes);
  void process();
  std::string get_name();
  void draw();
  void set_mode(game_mode_t newMode);
  void proc_platform(char sign);
  void current_info();

  // void next_level();
  // void exit_game();
};

#endif // GAME_CL_H
