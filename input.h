#ifndef INPUT_H
#define INPUT_H

#include "common.h"

typedef struct
{
    int is_quit;

    int is_esc;
    int was_esc;
    int is_up;
    int was_up;
    int is_down;
    int was_down;
    int is_left;
    int was_left;
    int is_right;
    int was_right;

    int is_mouse_left;
    int was_mouse_left;
    int is_mouse_middle;
    int was_mouse_middle;
    int is_mouse_right;
    int was_mouse_right;

    int mouse_x;
    int mouse_y;
    
    int is_mouse_scrolling;
    int mouse_scrolled;

} Input;

void init_input (Input* input);
void update_input (Input* input);

#endif