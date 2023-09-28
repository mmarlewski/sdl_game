#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include "common.h"
#include "vec.h"

vec2f screen_pos_to_world_pos(vec2i screen_pos, vec2f camera_pos, float camera_zoom);
vec2i world_pos_to_screen_pos(vec2f world_pos, vec2f camera_pos, float camera_zoom);

vec2f cart_pos_to_iso_pos(vec2f cart_pos);
vec2f iso_pos_to_cart_pos(vec2f iso_pos);

vec2f world_pos_to_gamemap_pos(vec2f world_pos);
vec2f gamemap_pos_to_world_pos(vec2f gamemap_pos);

vec2i gamemap_pos_to_tilemap_pos(vec2f gamemap_pos);
vec2f tilemap_pos_to_gamemap_pos(vec2i tilemap_pos);

#endif