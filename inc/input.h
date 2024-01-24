#ifndef INPUT_H
#define INPUT_H

#include "../inc/common.h"

enum KEY
{
    KEY__NONE,

    KEY__ESC,
    KEY__ENTER,
    KEY__SPACE,

    KEY__UP,
    KEY__DOWN,
    KEY__RIGHT,
    KEY__LEFT,

    KEY__1,
    KEY__2,
    KEY__3,
    KEY__4,
    KEY__5,
    KEY__6,
    KEY__7,
    KEY__8,
    KEY__9,
    KEY__0,

    KEY__Q,
    KEY__W,
    KEY__E,
    KEY__R,
    KEY__T,
    KEY__Y,
    KEY__U,
    KEY__I,
    KEY__O,
    KEY__P,

    KEY__A,
    KEY__S,
    KEY__D,
    KEY__F,
    KEY__G,
    KEY__H,
    KEY__J,
    KEY__K,
    KEY__L,

    KEY__Z,
    KEY__X,
    KEY__C,
    KEY__V,
    KEY__B,
    KEY__N,
    KEY__M,

    KEY__COUNT
};
typedef struct
{
    int is_quit;

    int is_key[KEY__COUNT];
    int was_key[KEY__COUNT];

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
