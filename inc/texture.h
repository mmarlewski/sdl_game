#ifndef TEXTURE_H
#define TEXTURE_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/math_utils.h"

Texture* load_texture_from_filepath (Renderer* renderer, char* filepath);
void destroy_texture (Texture* texture);

void draw_texture_at_screen_pos (Renderer* renderer, Texture* texture, Vec3i color, float transparency, Vec2i screen_pos, float camera_zoom);
void draw_texture_at_world_pos (Renderer* renderer, Texture* texture, Vec3i color, float transparency, Vec2f world_pos, Vec2f camera_pos, float camera_zoom);
void draw_texture_at_gamemap_pos (Renderer* renderer, Texture* texture, Vec3i color,float transparency , Vec2f gamemap_pos, Vec2f camera_pos, float camera_zoom);

#endif
