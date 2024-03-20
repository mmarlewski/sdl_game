#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

// printf("here ok \n");

// typedefs

typedef SDL_Renderer Renderer;
typedef SDL_Window Window;

typedef SDL_Texture Texture;

typedef Mix_Chunk Sound;

typedef Mix_Music Music;

// defines

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 750

#define FPS_CAP 60.0f
#define FPS_CAP_IN_MILISECONDS (1000.0f / FPS_CAP)

#define TILEMAP_LENGTH 10
#define TILE_LENGTH 64

#define GAMEMAP_WIDTH 64 * TILEMAP_LENGTH
#define GAMEMAP_HEIGHT 64 * 0.5f * TILEMAP_LENGTH

#define ACTION_LENGTH_IN_SECONDS 0.02f
#define ACTION_THROW_LENGTH_MODIFIER 4.0f

#define ALLY_MAX_ACTION_POINTS 5

#define OBJECT_TURRET_RANGE 3

#define SKILL_PICK_AND_PUT_ITEM_FAR_RANGE 10
#define SKILL_THROW_ITEM_RANGE 5
#define SKILL_PUSH_RANGE 2
#define SKILL_THROW_RANGE 2
#define SKILL_DRAG_RANGE 10
#define SKILL_PULL_RANGE 10
#define SKILL_JUMP_RANGE 2
#define SKILL_CHARGE_RANGE 10
#define SKILL_CHARGE_PUSH_RANGE 5
#define SKILL_CHARGE_THROW_RANGE 5
#define SKILL_CHARGE_JUMP_RANGE 5
#define SKILL_JUMP_AND_CARRY_RANGE 2
#define SKILL_JUMP_AND_STOMP_RANGE 2
#define SKILL_LAUNCH_MINIBOT_RANGE 10

#endif
