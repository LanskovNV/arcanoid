#pragma once
#ifndef MENU_LIST_CL_H
#define MENU_LIST_CL_H

// leins, 17.04.2018
#include <fstream>
#include "button_cl.h"
#include "list_cl.h"

enum elem_type_t
{
    button,
    list
};

union elem_t
{
    button_cl button;
    list_cl list;
};

struct list_elem_t
{
    elem_t elem;
    elem_type_t type;
};

class menu_list_cl: public methods_cl
{
private:
    list_elem_t *node;
public:
    void Draw() override;
    void Init(fstream &stream) override;
    void Action() override;
}

#endif // MENU_LIST_CL_H
