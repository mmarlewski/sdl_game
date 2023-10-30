#ifndef INPUT_H
#define INPUT_H

#include "../inc/common.h"

typedef struct
{
    int is_quit;

    int is_esc;
    int was_esc;
    int is_enter;
    int was_enter;

    int is_up;
    int was_up;
    int is_down;
    int was_down;
    int is_left;
    int was_left;
    int is_right;
    int was_right;

    int is_1;
    int was_1;
    int is_2;
    int was_2;
    int is_3;
    int was_3;
    int is_4;
    int was_4;
    int is_5;
    int was_5;
    int is_6;
    int was_6;
    int is_7;
    int was_7;
    int is_8;
    int was_8;
    int is_9;
    int was_9;
    int is_0;
    int was_0;

    int is_q;
    int was_q;
    int is_w;
    int was_w;
    int is_e;
    int was_e;

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
