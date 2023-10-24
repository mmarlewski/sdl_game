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
    Texture* highlight;

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

} Textures_Move;

void load_textures_move (Renderer* renderer, Textures_Move* move);
void destroy_textures_move (Textures_Move* move);

typedef struct
{
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_Crash;

void load_textures_crash (Renderer* renderer, Textures_Crash* crash);
void destroy_textures_crash (Textures_Crash* crash);

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
    Texture* up;
    Texture* right;
    Texture* down;
    Texture* left;

} Textures_Lift;

void load_textures_lift (Renderer* renderer, Textures_Lift* lift);
void destroy_textures_lift (Textures_Lift* lift);

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
    Texture* pillar_outline;

    Texture* pillar_spikes;
    Texture* pillar_spikes_outline;

    Texture* barrel;
    Texture* barrel_outline;

    Texture* spring;
    Texture* spring_outline;

    Texture* weight;
    Texture* weight_outline;

    Texture* hero;
    Texture* hero_outline;

    Texture* goat;
    Texture* goat_outline;

    Texture* spider;
    Texture* spider_outline;

    Texture* bull;
    Texture* bull_outline;

    Texture* fly;
    Texture* fly_outline;

    Texture* chameleon;
    Texture* chameleon_outline;

} Textures_Object;

void load_textures_object (Renderer* renderer, Textures_Object* object);
void destroy_textures_object (Textures_Object* object);

typedef struct
{
    Texture* num_1;
    Texture* num_2;
    Texture* num_3;
    Texture* num_4;
    Texture* num_5;
    Texture* num_6;
    Texture* num_7;
    Texture* num_8;
    Texture* num_9;
    Texture* num_0;

} Textures_OrderNumber;

void load_textures_order_number (Renderer* renderer, Textures_OrderNumber* order_number);
void destroy_textures_order_number (Textures_OrderNumber* order_number);

typedef struct
{
    Textures_Floor floor;

    Textures_Highlight highlight;
    Textures_Danger danger;

    Textures_Move move;
    Textures_Crash crash;

    Textures_Fall fall;
    Textures_Death death;
    Textures_BlowUp blow_up;

    Textures_Throw throw;
    Textures_Lift lift;
    Textures_Drop drop;

    Textures_Object object;

    Textures_OrderNumber order_number;

} Textures;

void load_textures (Renderer* renderer, Textures* textures);
void destroy_textures (Textures* textures);

Texture* get_texture_move(Textures* textures, int dir4);
Texture* get_texture_crash(Textures* textures, int dir4);

Texture* get_texture_throw(Textures* textures, int dir4);
Texture* get_texture_lift(Textures* textures, int dir4);

Texture* get_texture_order_number(Textures* textures, int num);

#endif
