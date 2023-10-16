#ifndef DIR_H
#define DIR_H

#include "../inc/common.h"
#include "../inc/vec.h"

enum DIR4
{
    DIR4__NONE,

    DIR4__UP,
    DIR4__RIGHT,
    DIR4__DOWN,
    DIR4__LEFT,

    DIR4__COUNT
};

vec2i make_vec2i_move_in_dir4_by(vec2i vec, int dir4, int by);
vec2f make_vec2f_move_in_dir4_by(vec2f vec, int dir4, float by);

vec2i* new_vec2i_move_in_dir4_by(vec2i vec, int dir4, int by);
vec2f* new_vec2f_move_in_dir4_by(vec2f vec, int dir4, float by);

int get_x_diff_from_vec2i_to_vec2i(vec2i from, vec2i to);
int get_y_diff_from_vec2i_to_vec2i(vec2i from, vec2i to);
int get_dir4_from_vec2i_to_vec2i(vec2i from, vec2i to);

typedef struct
{
    int dir4;

    int x_diff;
    int y_diff;
    int diff;

    int abs_x_diff;
    int abs_y_diff;
    int abs_diff;

} DistanceInfo;

DistanceInfo get_distance_info_from_vec2i_to_vec2i(vec2i from, vec2i to);

#endif
