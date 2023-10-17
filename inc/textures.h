#ifndef TEXTURES_H
#define TEXTURES_H

#include "../inc/common.h"
#include "../inc/texture.h"
#include "../inc/dir.h"

typedef struct
{
    Texture* metal;
    Texture* metal_spikes;
    Texture* metal_lava_crack;
    Texture* lava;
    Texture* ice;
    Texture* ice_water_crack;
    Texture* water;

} Textures_Floor;

void load_textures_floor (Renderer* renderer, Textures_Floor* floor);
void destroy_textures_floor (Textures_Floor* floor);

typedef struct
{
    Texture* red;
    Texture* orange;
    Texture* yellow;
    Texture* green;
    Texture* teal;
    Texture* blue;
    Texture* purple;
    Texture* pink;
    Texture* grey;

} Textures_Highlight;

void load_textures_highlight (Renderer* renderer, Textures_Highlight* highlight);
void destroy_textures_highlight (Textures_Highlight* highlight);

typedef struct
{
    Texture* frame_1;
    Texture* frame_2;
    Texture* frame_3;
    Texture* frame_4;
    Texture* frame_5;
    Texture* frame_6;

} Textures_Danger;

void load_textures_danger (Renderer* renderer, Textures_Danger* danger);
void destroy_textures_danger (Textures_Danger* danger);

typedef struct
{
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_MoveGround;

void load_textures_move_ground (Renderer* renderer, Textures_MoveGround* move_ground);
void destroy_textures_move_ground (Textures_MoveGround* move_ground);

typedef struct
{
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_MoveAir;

void load_textures_move_air (Renderer* renderer, Textures_MoveAir* move_air);
void destroy_textures_move_air (Textures_MoveAir* move_air);

typedef struct
{
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_CrashGround;

void load_textures_crash_ground (Renderer* renderer, Textures_CrashGround* crash_ground);
void destroy_textures_crash (Textures_CrashGround* crash_ground);

typedef struct
{
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_CrashAir;

void load_textures_crash (Renderer* renderer, Textures_CrashAir* crash_air);
void destroy_textures_crash_air (Textures_CrashAir* crash_air);

typedef struct
{
    Texture* fall;

} Textures_Fall;

void load_textures_fall (Renderer* renderer, Textures_Fall* fall);
void destroy_textures_fall (Textures_Fall* fall);

typedef struct
{
    Texture* death;
    Texture* skull;

} Textures_Death;

void load_textures_death (Renderer* renderer, Textures_Death* death);
void destroy_textures_death (Textures_Death* death);

typedef struct
{
    Texture* blow_up;
    Texture* explosion;

} Textures_BlowUp;

void load_textures_blow_up (Renderer* renderer, Textures_BlowUp* blow_up);
void destroy_textures_blow_up (Textures_BlowUp* blow_up);

typedef struct
{
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_Throw;

void load_textures_throw (Renderer* renderer, Textures_Throw* throw);
void destroy_textures_throw (Textures_Throw* throw);

typedef struct
{
    Texture* drop;
    Texture* thump;

} Textures_Drop;

void load_textures_drop (Renderer* renderer, Textures_Drop* drop);
void destroy_textures_drop (Textures_Drop* drop);

typedef struct
{
    Texture* pillar;
    Texture* barrel;
    Texture* spring;
    Texture* hero;
    Texture* goat;
    Texture* spider;
    Texture* bull;
    Texture* fly;
    Texture* chameleon;

} Textures_Object;

void load_textures_object (Renderer* renderer, Textures_Object* object);
void destroy_textures_object (Textures_Object* object);

typedef struct
{
    Textures_Floor floor;

    Textures_Highlight highlight;
    Textures_Danger danger;

    Textures_MoveGround move_ground;
    Textures_MoveAir move_air;

    Textures_CrashGround crash_ground;
    Textures_CrashAir crash_air;

    Textures_Fall fall;
    Textures_Death death;
    Textures_BlowUp blow_up;

    Textures_Throw throw;
    Textures_Drop drop;

    Textures_Object object;

} Textures;

void load_textures (Renderer* renderer, Textures* textures);
void destroy_textures (Textures* textures);

Texture* get_texture_move_ground(Textures* textures, int dir4);
Texture* get_texture_move_air(Textures* textures, int dir4);
Texture* get_texture_crash_ground(Textures* textures, int dir4);
Texture* get_texture_crash_air(Textures* textures, int dir4);
Texture* get_texture_throw(Textures* textures, int dir4);

#endif
