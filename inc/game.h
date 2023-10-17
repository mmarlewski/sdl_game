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

void init_sdl (Window** window, Renderer** renderer);
void destroy_sdl (Window* window, Renderer* renderer);

void render (Renderer* renderer, State* state, Input* input, Textures* textures);

void draw_line (Renderer* renderer, vec2f start, vec2f end);
void draw_rectangle (Renderer* renderer, vec2f start, vec2f dims);

void draw_gamemap(Renderer* renderer, State* state, Textures* textures);
void draw_action(Renderer* renderer, State* state, Action* action, Textures* textures);

#endif
