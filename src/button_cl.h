#pragma once
#ifndef BUTTON_CL_H
#define BUTTON_CL_H
// leins, 18.04.2018

#include <fstream>
#include "color_class.h"
#include "point_cl.h"

#define HIGTH 0.04
#define WEIGTH 0.3

class button_cl
{
private:
    point_cl pos; // left up coner
    std::string name;
    color_class color;
    color_class hightColor;
    bool state;

public:
    bool get_state() { return state; }

    void draw();
    void init(std::fstream &stream);
    game_mode_t new_mode();
    void change_state();
    bool in_button(float x, float y);
};

#endif
