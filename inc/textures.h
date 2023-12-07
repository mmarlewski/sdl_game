#ifndef TEXTURES_H
#define TEXTURES_H

#include "../inc/common.h"
#include "../inc/texture.h"
#include "../inc/dir.h"

typedef struct
{
    Texture* highlight;

    Texture* rock;
    Texture* rock_crack_water;
    Texture* rock_crack_lava;

    Texture* stone;
    Texture* stone_spikes_on;
    Texture* stone_spikes_off;

    Texture* metal;
    Texture* metal_hatch_open_1;
    Texture* metal_hatch_open_2;
    Texture* metal_hatch_closed;
    Texture* metal_cover_bottom;

    Texture* grass;

    Texture* water_1;
    Texture* water_2;
    Texture* water_stalactite_fallen_1;
    Texture* water_stalactite_fallen_2;

    Texture* lava_1;
    Texture* lava_2;
    Texture* lava_stalactite_fallen_1;
    Texture* lava_stalactite_fallen_2;

    Texture* ice;
    Texture* ice_crack_water;

} Textures_Floor;

void load_textures_floor (Renderer* renderer, Textures_Floor* floor);
void destroy_textures_floor (Textures_Floor* floor);

typedef struct
{
    Texture* wall_rock;
    Texture* wall_rock_outline;

    Texture* wall_stone;
    Texture* wall_stone_outline;

    Texture* wall_metal;
    Texture* wall_metal_outline;

    Texture* exit_rock_up;
    Texture* exit_rock_blocked_up;
    Texture* exit_rock_up_outline;
    Texture* exit_rock_right;
    Texture* exit_rock_blocked_right;
    Texture* exit_rock_right_outline;
    Texture* exit_rock_down;
    Texture* exit_rock_blocked_down;
    Texture* exit_rock_down_outline;
    Texture* exit_rock_left;
    Texture* exit_rock_blocked_left;
    Texture* exit_rock_left_outline;

    Texture* exit_stone_up;
    Texture* exit_stone_blocked_up;
    Texture* exit_stone_up_outline;
    Texture* exit_stone_right;
    Texture* exit_stone_blocked_right;
    Texture* exit_stone_right_outline;
    Texture* exit_stone_down;
    Texture* exit_stone_blocked_down;
    Texture* exit_stone_down_outline;
    Texture* exit_stone_left;
    Texture* exit_stone_blocked_left;
    Texture* exit_stone_left_outline;

    Texture* exit_metal_up;
    Texture* exit_metal_blocked_up;
    Texture* exit_metal_up_outline;
    Texture* exit_metal_right;
    Texture* exit_metal_blocked_right;
    Texture* exit_metal_right_outline;
    Texture* exit_metal_down;
    Texture* exit_metal_blocked_down;
    Texture* exit_metal_down_outline;
    Texture* exit_metal_left;
    Texture* exit_metal_blocked_left;
    Texture* exit_metal_left_outline;

    Texture* stalactite;
    Texture* stalactite_outline;

    Texture* stalactite_fallen;
    Texture* stalactite_fallen_outline;

    Texture* stalagmite;
    Texture* stalagmite_outline;

    Texture* stalagnate;
    Texture* stalagnate_outline;

    Texture* pillar;
    Texture* pillar_outline;
    Texture* pillar_spikes;
    Texture* pillar_spikes_outline;

    Texture* cover_rock;
    Texture* cover_rock_outline;

    Texture* cover_metal;
    Texture* cover_metal_outline;

    Texture* cover_glass;
    Texture* cover_glass_outline;

    Texture* rock;
    Texture* rock_outline;

    Texture* rock_damaged;
    Texture* rock_damaged_outline;

    Texture* safe;
    Texture* safe_outline;

    Texture* safe_damaged;
    Texture* safe_damaged_outline;

    Texture* display;
    Texture* display_outline;

    Texture* display_damaged;
    Texture* display_damaged_outline;

    Texture* vending;
    Texture* vending_outline;

    Texture* vending_damaged;
    Texture* vending_damaged_outline;

    Texture* barrel;
    Texture* barrel_outline;

    Texture* spring;
    Texture* spring_outline;

    Texture* weight;
    Texture* weight_outline;

    Texture* hero_1;
    Texture* hero_2;
    Texture* hero_outline_1;
    Texture* hero_outline_2;

    Texture* goat_1;
    Texture* goat_2;
    Texture* goat_outline_1;
    Texture* goat_outline_2;

    Texture* spider_1;
    Texture* spider_2;
    Texture* spider_outline_1;
    Texture* spider_outline_2;

    Texture* bull_1;
    Texture* bull_2;
    Texture* bull_outline_1;
    Texture* bull_outline_2;

    Texture* fly_1;
    Texture* fly_2;
    Texture* fly_outline_1;
    Texture* fly_outline_2;

    Texture* chameleon_1;
    Texture* chameleon_2;
    Texture* chameleon_outline_1;
    Texture* chameleon_outline_2;

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
    Texture* none;

    Texture* move_up;
    Texture* move_right;
    Texture* move_down;
    Texture* move_left;

    Texture* crash_up;
    Texture* crash_right;
    Texture* crash_down;
    Texture* crash_left;

    Texture* fall;

    Texture* death;
    Texture* skull;

    Texture* blow_up;
    Texture* explosion;

    Texture* throw_up;
    Texture* throw_right;
    Texture* throw_down;
    Texture* throw_left;

    Texture* lift_none;
    Texture* lift_up;
    Texture* lift_right;
    Texture* lift_down;
    Texture* lift_left;

    Texture* drop;
    Texture* thump;

    Texture* change;

} Textures_Action;

void load_textures_action (Renderer* renderer, Textures_Action* action);
void destroy_textures_action (Textures_Action* action);

typedef struct
{
    Textures_Floor floor;
    Textures_Object object;
    Textures_OrderNumber order_number;
    Textures_Action action;

} Textures;

void load_textures (Renderer* renderer, Textures* textures);
void destroy_textures (Textures* textures);

Texture* get_texture_move(Textures* textures, int dir4);
Texture* get_texture_crash(Textures* textures, int dir4);

Texture* get_texture_throw(Textures* textures, int dir4);
Texture* get_texture_lift(Textures* textures, int dir4);

Texture* get_texture_order_number(Textures* textures, int num);

#endif
