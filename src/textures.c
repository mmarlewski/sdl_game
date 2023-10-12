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

void load_textures_move (Renderer* renderer, Textures_Move* move)
{
    move->up = load_texture_from_filepath (renderer, "./res/move/up.png");
    move->right = load_texture_from_filepath (renderer, "./res/move/right.png");
    move->down = load_texture_from_filepath (renderer, "./res/move/down.png");
    move->left = load_texture_from_filepath (renderer, "./res/move/left.png");
}
void destroy_textures_move (Textures_Move* move)
{
    destroy_texture(move->up);
    destroy_texture(move->right);
    destroy_texture(move->down);
    destroy_texture(move->left);
}

void load_textures_push (Renderer* renderer, Textures_Push* push)
{
    push->up = load_texture_from_filepath (renderer, "./res/push/up.png");
    push->right = load_texture_from_filepath (renderer, "./res/push/right.png");
    push->down = load_texture_from_filepath (renderer, "./res/push/down.png");
    push->left = load_texture_from_filepath (renderer, "./res/push/left.png");
}
void destroy_textures_push (Textures_Push* push)
{
    destroy_texture(push->up);
    destroy_texture(push->right);
    destroy_texture(push->down);
    destroy_texture(push->left);
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
}
void destroy_textures_object (Textures_Object* object)
{
    destroy_texture(object->pillar);
    destroy_texture(object->barrel);
    destroy_texture(object->spring);
    destroy_texture(object->hero);
    destroy_texture(object->goat);
    destroy_texture(object->spider);
}

void load_textures (Renderer* renderer, Textures* textures)
{
    load_textures_floor(renderer,&textures->floor);

    load_textures_highlight(renderer,&textures->highlight);
    load_textures_danger(renderer,&textures->danger);

    load_textures_move(renderer,&textures->move);
    load_textures_push(renderer,&textures->push);
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

    destroy_textures_move (&textures->move);
    destroy_textures_push (&textures->push);
    destroy_textures_crash (&textures->crash);
    destroy_textures_blow_up (&textures->blow_up);
    destroy_textures_drop (&textures->drop);

    destroy_textures_object (&textures->object);
}