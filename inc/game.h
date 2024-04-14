#ifndef GAME_H
#define GAME_H

#include "../inc/common.h"
#include "../inc/state.h"
#include "../inc/input.h"
#include "../inc/vec.h"
#include "../inc/dir.h"
#include "../inc/list.h"
#include "../inc/math_utils.h"
#include "../inc/floor.h"
#include "../inc/object.h"
#include "../inc/sprite.h"
#include "../inc/animation.h"
#include "../inc/action.h"
#include "../inc/skill.h"
#include "../inc/texture.h"
#include "../inc/sound.h"
#include "../inc/music.h"
#include "../inc/textures.h"
#include "../inc/sounds.h"
#include "../inc/musics.h"
#include "../inc/colors.h"
#include "../inc/font.h"
#include "../inc/fonts.h"

void init_sdl (Window** window, Renderer** renderer);
void destroy_sdl (Window* window, Renderer* renderer);

void render (Renderer* renderer, State* state, Input* input, Textures* textures, Colors* colors, Fonts* fonts);

void draw_gamemap(Renderer* renderer, State* state, Textures* textures, Colors* colors, Fonts* fonts);
void draw_hud(Renderer* renderer, State* state, Textures* textures, Colors* colors, Fonts* fonts);
void draw_action(Renderer* renderer, State* state, Action* action, Vec3i color, Textures* textures, Colors* colors);

#endif
