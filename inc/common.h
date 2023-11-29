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

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define FPS_CAP 60.0f
#define FPS_CAP_IN_MILIS (1000.0f / FPS_CAP)

#define TILEMAP_LENGTH 10
#define TILE_LENGTH 64

#define HERO_MAX_AP 10

#endif
