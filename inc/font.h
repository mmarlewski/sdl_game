#ifndef FONT_H
#define FONT_H

#include "../inc/common.h"
#include "../inc/vec.h"

Font* load_font_from_filepath_of_size(char* filepath, int size);
void destroy_font(Font* font);

void draw_font_at_screen_pos(char* text, Renderer* renderer, Font* font, Vec3i color, float transparency, Vec2i screen_pos, int scale);

#endif
