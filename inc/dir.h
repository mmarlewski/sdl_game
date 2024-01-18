#ifndef DIR_H
#define DIR_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/list.h"

enum DIR4
{
    DIR4__NONE,

    DIR4__UP,
    DIR4__RIGHT,
    DIR4__DOWN,
    DIR4__LEFT,

    DIR4__COUNT
};

int get_opposite_dir4(int dir4);

Vec2i vec2i_move_in_dir4_by(Vec2i vec, int dir4, int by);
Vec2f vec2f_move_in_dir4_by(Vec2f vec, int dir4, float by);

int get_x_diff_from_vec2i_to_vec2i(Vec2i from, Vec2i to);
int get_y_diff_from_vec2i_to_vec2i(Vec2i from, Vec2i to);
int get_dir4_from_vec2i_to_vec2i(Vec2i from, Vec2i to);

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

DistanceInfo get_distance_info_from_vec2i_to_vec2i(Vec2i from, Vec2i to);

void get_line_from_tilemap_pos_in_dir4(Vec2i from_tilemap_pos, int dir4, int length, List* list);
void get_line_from_tilemap_pos_to_tilemap_pos(Vec2i from_tilemap_pos, Vec2i to_tilemap_pos, List* list);
void get_square_perimeter_tilemap_pos(Vec2i center_tilemap_pos, int radius, List* list);
void get_square_area_tilemap_pos(Vec2i center_tilemap_pos, int radius, List* list);

#endif
