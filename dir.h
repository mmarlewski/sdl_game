#ifndef DIR_H
#define DIR_H

#include "common.h"
#include "vec.h"

enum DIR4
{
    DIR4__UP,
    DIR4__RIGHT,
    DIR4__DOWN,
    DIR4__LEFT,

    DIR4__COUNT
};

vec2i move_vec2i_in_dir4_by(vec2i pos, int dir4, int by);
vec2f move_vec2f_in_dir4_by(vec2f pos, int dir4, float by);

#endif