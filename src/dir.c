#include "../inc/dir.h"

int get_opposite_dir4(int dir4)
{
    int opposite_dir4 = DIR4__NONE;

    switch(dir4)
    {
        case DIR4__UP: opposite_dir4 = DIR4__DOWN; break;
        case DIR4__RIGHT: opposite_dir4 = DIR4__LEFT; break;
        case DIR4__DOWN: opposite_dir4 = DIR4__UP; break;
        case DIR4__LEFT: opposite_dir4 = DIR4__RIGHT; break;
        default: break;
    }

    return opposite_dir4;
}

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

void get_line_from_tilemap_pos_in_dir4(vec2i from_tilemap_pos, int dir4, int length, List* list)
{
    vec2i tilemap_pos = from_tilemap_pos;
    for (int i = 0; i < length; i++)
    {
        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, dir4, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
}

void get_square_perimeter_tilemap_pos(vec2i center_tilemap_pos, int radius, List* list)
{
    if (radius < 0) return;

    vec2i tilemap_pos = center_tilemap_pos;
    tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__UP, radius);
    tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__LEFT, radius);

    for (int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__RIGHT, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
    for (int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__DOWN, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
    for (int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__LEFT, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
    for (int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = make_vec2i_move_in_dir4_by(tilemap_pos, DIR4__UP, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
}

void get_square_area_tilemap_pos(vec2i center_tilemap_pos, int radius, List* list)
{
    if (radius < 0) return;

    add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(center_tilemap_pos));

    for (int i = 0; i < radius; i++)
    {
        get_square_perimeter_tilemap_pos(center_tilemap_pos, i, list);
    }
}
