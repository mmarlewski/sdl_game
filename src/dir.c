#include "../inc/dir.h"

vec2i make_vec2i_move_in_dir4_by(vec2i vec, int dir4, int by)
{
    switch(dir4)
    {
        case DIR4__UP: vec.y -= by; break;
        case DIR4__RIGHT: vec.x += by; break;
        case DIR4__DOWN: vec.y += by; break;
        case DIR4__LEFT: vec.x -= by; break;
        default: break;
    }

    return vec;
}

vec2f make_vec2f_move_in_dir4_by(vec2f vec, int dir4, float by)
{
    switch(dir4)
    {
        case DIR4__UP: vec.y -= by; break;
        case DIR4__RIGHT: vec.x += by; break;
        case DIR4__DOWN: vec.y += by; break;
        case DIR4__LEFT: vec.x -= by; break;
        default: break;
    }

    return vec;
}

vec2i* new_vec2i_move_in_dir4_by(vec2i vec, int dir4, int by)
{
    switch(dir4)
    {
        case DIR4__UP: vec.y -= by; break;
        case DIR4__RIGHT: vec.x += by; break;
        case DIR4__DOWN: vec.y += by; break;
        case DIR4__LEFT: vec.x -= by; break;
        default: break;
    }

    return new_vec2i(vec.x, vec.y);
}

vec2f* new_vec2f_move_in_dir4_by(vec2f vec, int dir4, float by)
{
    switch(dir4)
    {
        case DIR4__UP: vec.y -= by; break;
        case DIR4__RIGHT: vec.x += by; break;
        case DIR4__DOWN: vec.y += by; break;
        case DIR4__LEFT: vec.x -= by; break;
        default: break;
    }

    return new_vec2f(vec.x, vec.y);
}

int get_x_diff_from_vec2i_to_vec2i(vec2i from, vec2i to)
{
    return (to.x - from.x);
}

int get_y_diff_from_vec2i_to_vec2i(vec2i from, vec2i to)
{
    return (to.y - from.y);
}

int get_dir4_from_vec2i_to_vec2i(vec2i from, vec2i to)
{
    int dir4 = DIR4__NONE;

    int x_diff = get_x_diff_from_vec2i_to_vec2i(from, to);
    int y_diff = get_y_diff_from_vec2i_to_vec2i(from, to);

    if(x_diff > 0 && y_diff == 0) dir4 = DIR4__RIGHT;
    if(x_diff < 0 && y_diff == 0) dir4 = DIR4__LEFT;
    if(x_diff == 0 && y_diff > 0) dir4 = DIR4__DOWN;
    if(x_diff == 0 && y_diff < 0) dir4 = DIR4__UP;

    return dir4;
}


DistanceInfo get_distance_info_from_vec2i_to_vec2i(vec2i from, vec2i to)
{
    int dir4 = DIR4__NONE;
    int diff = 0;

    int x_diff = get_x_diff_from_vec2i_to_vec2i(from, to);
    int y_diff = get_y_diff_from_vec2i_to_vec2i(from, to);

    if(x_diff > 0 && y_diff == 0)
    {
        dir4 = DIR4__RIGHT;
        diff = x_diff;
    }
    if(x_diff < 0 && y_diff == 0)
    {
        dir4 = DIR4__LEFT;
        diff = x_diff;
    }
    if(x_diff == 0 && y_diff > 0)
    {
        dir4 = DIR4__DOWN;
        diff = y_diff;
    }
    if(x_diff == 0 && y_diff < 0)
    {
        dir4 = DIR4__UP;
        diff = y_diff;
    }

    int abs_x_diff = abs(x_diff);
    int abs_y_diff = abs(y_diff);
    int abs_diff = abs(diff);

    DistanceInfo distance_info;

    distance_info.dir4 = dir4;
    distance_info.x_diff = x_diff;
    distance_info.y_diff = y_diff;
    distance_info.diff = diff;
    distance_info.abs_x_diff = abs_x_diff;
    distance_info.abs_y_diff = abs_y_diff;
    distance_info.abs_diff = abs_diff;

    return distance_info;
}
