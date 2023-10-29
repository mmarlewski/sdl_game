#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include "../inc/common.h"
#include "../inc/vec.h"

Vec2f screen_pos_to_world_pos(Vec2i screen_pos, Vec2f camera_pos, float camera_zoom);
Vec2i world_pos_to_screen_pos(Vec2f world_pos, Vec2f camera_pos, float camera_zoom);

Vec2f cart_pos_to_iso_pos(Vec2f cart_pos);
Vec2f iso_pos_to_cart_pos(Vec2f iso_pos);

Vec2f world_pos_to_gamemap_pos(Vec2f world_pos);
Vec2f gamemap_pos_to_world_pos(Vec2f gamemap_pos);

Vec2i gamemap_pos_to_tilemap_pos(Vec2f gamemap_pos);
Vec2f tilemap_pos_to_gamemap_pos(Vec2i tilemap_pos);

#endif
