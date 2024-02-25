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

#define ACTION_LENGTH_IN_SECONDS 0.1f
#define ACTION_THROW_LENGTH_MODIFIER 4.0f

#define ALLY_MAX_ACTION_POINTS 100

#define OBJECT_TURRET_RANGE 3

#endif
