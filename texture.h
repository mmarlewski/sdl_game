#ifndef TEXTURE_H
#define TEXTURE_H

#include "common.h"
#include "vec.h"
#include "math_utils.h"

Texture* load_texture_from_filepath (Renderer* renderer, char* filepath);
void destroy_texture (Texture* texture);

void draw_texture_at_screen_pos (Renderer* renderer, Texture* texture, vec2i screen_pos, float camera_zoom);
void draw_texture_at_world_pos (Renderer* renderer, Texture* texture, vec2f world_pos, vec2f camera_pos, float camera_zoom);

#endif