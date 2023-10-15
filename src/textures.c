#include "../inc/textures.h"

void load_textures_floor (Renderer* renderer, Textures_Floor* floor)
{
    floor->metal = load_texture_from_filepath (renderer, "./res/floor/metal.png");
    floor->metal_spikes = load_texture_from_filepath (renderer, "./res/floor/metal_spikes.png");
    floor->metal_lava_crack = load_texture_from_filepath (renderer, "./res/floor/metal_lava_crack.png");
    floor->lava = load_texture_from_filepath (renderer, "./res/floor/lava.png");
    floor->ice = load_texture_from_filepath (renderer, "./res/floor/ice.png");
    floor->ice_water_crack = load_texture_from_filepath (renderer, "./res/floor/ice_water_crack.png");
    floor->water = load_texture_from_filepath (renderer, "./res/floor/water.png");
}
void destroy_textures_floor (Textures_Floor* floor)
{
    destroy_texture(floor->metal);
    destroy_texture(floor->metal_spikes);
    destroy_texture(floor->metal_lava_crack);
    destroy_texture(floor->lava);
    destroy_texture(floor->ice);
    destroy_texture(floor->ice_water_crack);
    destroy_texture(floor->water);
}

void load_textures_highlight (Renderer* renderer, Textures_Highlight* highlight)
{
    highlight->red = load_texture_from_filepath (renderer, "./res/highlight/red.png");
    highlight->orange = load_texture_from_filepath (renderer, "./res/highlight/orange.png");
    highlight->yellow = load_texture_from_filepath (renderer, "./res/highlight/yellow.png");
    highlight->green = load_texture_from_filepath (renderer, "./res/highlight/green.png");
    highlight->teal = load_texture_from_filepath (renderer, "./res/highlight/teal.png");
    highlight->blue = load_texture_from_filepath (renderer, "./res/highlight/blue.png");
    highlight->purple = load_texture_from_filepath (renderer, "./res/highlight/purple.png");
    highlight->pink = load_texture_from_filepath (renderer, "./res/highlight/pink.png");
    highlight->grey = load_texture_from_filepath (renderer, "./res/highlight/grey.png");
}
void destroy_textures_highlight (Textures_Highlight* highlight)
{
    destroy_texture(highlight->red);
    destroy_texture(highlight->orange);
    destroy_texture(highlight->yellow);
    destroy_texture(highlight->green);
    destroy_texture(highlight->teal);
    destroy_texture(highlight->blue);
    destroy_texture(highlight->purple);
    destroy_texture(highlight->pink);
    destroy_texture(highlight->grey);
}

void load_textures_danger (Renderer* renderer, Textures_Danger* danger)
{
    danger->frame_1 = load_texture_from_filepath (renderer, "./res/danger/frame_1.png");
    danger->frame_2 = load_texture_from_filepath (renderer, "./res/danger/frame_2.png");
    danger->frame_3 = load_texture_from_filepath (renderer, "./res/danger/frame_3.png");
    danger->frame_4 = load_texture_from_filepath (renderer, "./res/danger/frame_4.png");
    danger->frame_5 = load_texture_from_filepath (renderer, "./res/danger/frame_5.png");
    danger->frame_6 = load_texture_from_filepath (renderer, "./res/danger/frame_6.png");
}
void destroy_textures_danger (Textures_Danger* danger)
{
    destroy_texture(danger->frame_1);
    destroy_texture(danger->frame_2);
    destroy_texture(danger->frame_3);
    destroy_texture(danger->frame_4);
    destroy_texture(danger->frame_5);
    destroy_texture(danger->frame_6);
}

void load_textures_move_ground (Renderer* renderer, Textures_MoveGround* move_ground)
{
    move_ground->up = load_texture_from_filepath (renderer, "./res/move_ground/up.png");
    move_ground->right = load_texture_from_filepath (renderer, "./res/move_ground/right.png");
    move_ground->down = load_texture_from_filepath (renderer, "./res/move_ground/down.png");
    move_ground->left = load_texture_from_filepath (renderer, "./res/move_ground/left.png");
}
void destroy_textures_move_ground (Textures_MoveGround* move_ground)
{
    destroy_texture(move_ground->up);
    destroy_texture(move_ground->right);
    destroy_texture(move_ground->down);
    destroy_texture(move_ground->left);
}

void load_textures_move_air (Renderer* renderer, Textures_MoveAir* move_air)
{
    move_air->up = load_texture_from_filepath (renderer, "./res/move_air/up.png");
    move_air->right = load_texture_from_filepath (renderer, "./res/move_air/right.png");
    move_air->down = load_texture_from_filepath (renderer, "./res/move_air/down.png");
    move_air->left = load_texture_from_filepath (renderer, "./res/move_air/left.png");
}
void destroy_textures_move_air (Textures_MoveAir* move_air)
{
    destroy_texture(move_air->up);
    destroy_texture(move_air->right);
    destroy_texture(move_air->down);
    destroy_texture(move_air->left);
}

void load_textures_crash (Renderer* renderer, Textures_Crash* crash)
{
    crash->up = load_texture_from_filepath (renderer, "./res/crash/up.png");
    crash->right = load_texture_from_filepath (renderer, "./res/crash/right.png");
    crash->down = load_texture_from_filepath (renderer, "./res/crash/down.png");
    crash->left = load_texture_from_filepath (renderer, "./res/crash/left.png");
}
void destroy_textures_crash (Textures_Crash* crash)
{
    destroy_texture(crash->up);
    destroy_texture(crash->right);
    destroy_texture(crash->down);
    destroy_texture(crash->left);
}

void load_textures_blow_up (Renderer* renderer, Textures_BlowUp* blow_up)
{
    blow_up->explosion = load_texture_from_filepath (renderer, "./res/blow_up/explosion.png");
}
void destroy_textures_blow_up (Textures_BlowUp* blow_up)
{
    destroy_texture(blow_up->explosion);
}

void load_textures_throw (Renderer* renderer, Textures_Throw* throw)
{
    throw->up = load_texture_from_filepath (renderer, "./res/throw/up.png");
    throw->right = load_texture_from_filepath (renderer, "./res/throw/right.png");
    throw->down = load_texture_from_filepath (renderer, "./res/throw/down.png");
    throw->left = load_texture_from_filepath (renderer, "./res/throw/left.png");
}
void destroy_textures_throw (Textures_Throw* throw)
{
    destroy_texture(throw->up);
    destroy_texture(throw->right);
    destroy_texture(throw->down);
    destroy_texture(throw->left);
}

void load_textures_drop (Renderer* renderer, Textures_Drop* drop)
{
    drop->thump = load_texture_from_filepath (renderer, "./res/drop/thump.png");
}
void destroy_textures_drop (Textures_Drop* drop)
{
    destroy_texture(drop->thump);
}

void load_textures_object (Renderer* renderer, Textures_Object* object)
{
    object->pillar = load_texture_from_filepath (renderer, "./res/object/pillar.png");
    object->barrel = load_texture_from_filepath (renderer, "./res/object/barrel.png");
    object->spring = load_texture_from_filepath (renderer, "./res/object/spring.png");
    object->hero = load_texture_from_filepath (renderer, "./res/object/hero.png");
    object->goat = load_texture_from_filepath (renderer, "./res/object/goat.png");
    object->spider = load_texture_from_filepath (renderer, "./res/object/spider.png");
    object->bull = load_texture_from_filepath (renderer, "./res/object/bull.png");
    object->fly = load_texture_from_filepath (renderer, "./res/object/fly.png");
    object->chameleon = load_texture_from_filepath (renderer, "./res/object/chameleon.png");
}
void destroy_textures_object (Textures_Object* object)
{
    destroy_texture(object->pillar);
    destroy_texture(object->barrel);
    destroy_texture(object->spring);
    destroy_texture(object->hero);
    destroy_texture(object->goat);
    destroy_texture(object->spider);
    destroy_texture(object->bull);
    destroy_texture(object->fly);
    destroy_texture(object->chameleon);
}

void load_textures (Renderer* renderer, Textures* textures)
{
    load_textures_floor(renderer,&textures->floor);

    load_textures_highlight(renderer,&textures->highlight);
    load_textures_danger(renderer,&textures->danger);

    load_textures_move_ground(renderer,&textures->move_ground);
    load_textures_move_air(renderer,&textures->move_air);
    load_textures_crash(renderer,&textures->crash);
    load_textures_blow_up(renderer,&textures->blow_up);
    load_textures_drop(renderer,&textures->drop);

    load_textures_object(renderer,&textures->object);
}

void destroy_textures (Textures* textures)
{
    destroy_textures_floor (&textures->floor);

    destroy_textures_highlight (&textures->highlight);
    destroy_textures_danger (&textures->danger);

    destroy_textures_move_ground (&textures->move_ground);
    destroy_textures_move_air (&textures->move_air);
    destroy_textures_crash (&textures->crash);
    destroy_textures_blow_up (&textures->blow_up);
    destroy_textures_drop (&textures->drop);

    destroy_textures_object (&textures->object);
}
