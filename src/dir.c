#include "../inc/dir.h"

int get_opposite_dir8(int dir8)
{
    int opposite_dir8 = DIR8__NONE;

    switch(dir8)
    {
        case DIR8__UP_LEFT: opposite_dir8 = DIR8__DOWN_RIGHT; break;
        case DIR8__UP: opposite_dir8 = DIR8__DOWN; break;
        case DIR8__UP_RIGHT: opposite_dir8 = DIR8__DOWN_LEFT; break;
        case DIR8__RIGHT: opposite_dir8 = DIR8__LEFT; break;
        case DIR8__DOWN_RIGHT: opposite_dir8 = DIR8__UP_LEFT; break;
        case DIR8__DOWN: opposite_dir8 = DIR8__UP; break;
        case DIR8__DOWN_LEFT: opposite_dir8 = DIR8__UP_RIGHT; break;
        case DIR8__LEFT: opposite_dir8 = DIR8__RIGHT; break;
        default: break;
    }

    return opposite_dir8;
}

Vec2i vec2i_move_in_dir8_by(Vec2i vec, int dir8, int by)
{
    switch(dir8)
    {
        case DIR8__UP_LEFT:     vec.x += -by;   vec.y += -by; break;
        case DIR8__UP:          vec.x += 0;     vec.y += -by; break;
        case DIR8__UP_RIGHT:    vec.x += by;    vec.y += -by; break;
        case DIR8__RIGHT:       vec.x += by;    vec.y += 0; break;
        case DIR8__DOWN_RIGHT:  vec.x += by;    vec.y += by; break;
        case DIR8__DOWN:        vec.x += 0;     vec.y += by; break;
        case DIR8__DOWN_LEFT:   vec.x += -by;   vec.y += by; break;
        case DIR8__LEFT:        vec.x += -by;   vec.y += 0; break;
        default: break;
    }

    return vec;
}

Vec2f vec2f_move_in_dir8_by(Vec2f vec, int dir8, float by)
{
    switch(dir8)
    {
        case DIR8__UP_LEFT:     vec.x += -by;   vec.y += -by; break;
        case DIR8__UP:          vec.x += 0;     vec.y += -by; break;
        case DIR8__UP_RIGHT:    vec.x += by;    vec.y += -by; break;
        case DIR8__RIGHT:       vec.x += by;    vec.y += 0; break;
        case DIR8__DOWN_RIGHT:  vec.x += by;    vec.y += by; break;
        case DIR8__DOWN:        vec.x += 0;     vec.y += by; break;
        case DIR8__DOWN_LEFT:   vec.x += -by;   vec.y += by; break;
        case DIR8__LEFT:        vec.x += -by;   vec.y += 0; break;
        default: break;
    }

    return vec;
}

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

Vec2i vec2i_move_in_dir4_by(Vec2i vec, int dir4, int by)
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

Vec2f vec2f_move_in_dir4_by(Vec2f vec, int dir4, float by)
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

int get_x_diff_from_vec2i_to_vec2i(Vec2i from, Vec2i to)
{
    return (to.x - from.x);
}

int get_y_diff_from_vec2i_to_vec2i(Vec2i from, Vec2i to)
{
    return (to.y - from.y);
}

int get_dir4_from_vec2i_to_vec2i(Vec2i from, Vec2i to)
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


DistanceInfo get_distance_info_from_vec2i_to_vec2i(Vec2i from, Vec2i to)
{
    int dir4 = DIR4__NONE;
    int dir8 = DIR8__NONE;
    int diff = 0;

    int x_diff = get_x_diff_from_vec2i_to_vec2i(from, to);
    int y_diff = get_y_diff_from_vec2i_to_vec2i(from, to);

    if(x_diff > 0 && y_diff == 0)
    {
        dir4 = DIR4__RIGHT;
        dir8 = DIR8__RIGHT;
        diff = x_diff;
    }
    if(x_diff < 0 && y_diff == 0)
    {
        dir4 = DIR4__LEFT;
        dir8 = DIR8__LEFT;
        diff = x_diff;
    }
    if(x_diff == 0 && y_diff > 0)
    {
        dir4 = DIR4__DOWN;
        dir8 = DIR8__DOWN;
        diff = y_diff;
    }
    if(x_diff == 0 && y_diff < 0)
    {
        dir4 = DIR4__UP;
        dir8 = DIR8__UP;
        diff = y_diff;
    }

    if(x_diff != 0 && y_diff != 0 && abs(x_diff) == abs(y_diff))
    {
        if(x_diff < 0 && y_diff < 0)
        {
            dir4 = DIR4__NONE;
            dir8 = DIR8__UP_LEFT;
            diff = x_diff;
        }
        if(x_diff > 0 && y_diff < 0)
        {
            dir4 = DIR4__NONE;
            dir8 = DIR8__UP_RIGHT;
            diff = x_diff;
        }
        if(x_diff > 0 && y_diff > 0)
        {
            dir4 = DIR4__NONE;
            dir8 = DIR8__DOWN_RIGHT;
            diff = x_diff;
        }
        if(x_diff < 0 && y_diff > 0)
        {
            dir4 = DIR4__NONE;
            dir8 = DIR8__DOWN_LEFT;
            diff = x_diff;
        }
    }

    int abs_x_diff = abs(x_diff);
    int abs_y_diff = abs(y_diff);
    int abs_diff = abs(diff);

    DistanceInfo distance_info;

    distance_info.dir4 = dir4;
    distance_info.dir8 = dir8;
    distance_info.x_diff = x_diff;
    distance_info.y_diff = y_diff;
    distance_info.diff = diff;
    distance_info.abs_x_diff = abs_x_diff;
    distance_info.abs_y_diff = abs_y_diff;
    distance_info.abs_diff = abs_diff;

    return distance_info;
}

void get_line_from_tilemap_pos_in_dir4(Vec2i from_tilemap_pos, int dir4, int length, List* list)
{
    Vec2i tilemap_pos = from_tilemap_pos;
    for(int i = 0; i < length; i++)
    {
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, dir4, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
}

void get_line_from_tilemap_pos_to_tilemap_pos(Vec2i from_tilemap_pos, Vec2i to_tilemap_pos, List* list)
{
    int distance = fmax(abs(to_tilemap_pos.x - from_tilemap_pos.x), abs(to_tilemap_pos.y - from_tilemap_pos.y));

    for(int i = 0; i < distance; i++)
    {
        Vec2i new_tilemap_pos =
            vec2i(
                round(from_tilemap_pos.x + ((float) i / distance) * (to_tilemap_pos.x - from_tilemap_pos.x)),
                round(from_tilemap_pos.y + ((float) i / distance) * (to_tilemap_pos.y - from_tilemap_pos.y))
            );

        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(new_tilemap_pos));
    }
}

void get_square_perimeter_tilemap_pos(Vec2i center_tilemap_pos, int radius, List* list)
{
    if(radius < 0) return;

    Vec2i tilemap_pos = center_tilemap_pos;
    tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__UP, radius);
    tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__LEFT, radius);

    for(int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__RIGHT, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
    for(int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__DOWN, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
    for(int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__LEFT, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
    for(int i = 0; i < radius * 2; i++)
    {
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__UP, 1);
        add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(tilemap_pos));
    }
}

void get_square_area_tilemap_pos(Vec2i center_tilemap_pos, int radius, List* list)
{
    if(radius < 0) return;

    add_new_list_element_to_list_end(list, new_vec2i_from_vec2i(center_tilemap_pos));

    for(int i = 0; i < radius; i++)
    {
        get_square_perimeter_tilemap_pos(center_tilemap_pos, i, list);
    }
}
