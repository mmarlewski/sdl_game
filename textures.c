#include "textures.h"

void load_textures_floor (Renderer* renderer, Textures_Floor* floor)
{
    floor->grass = load_texture_from_filepath (renderer, "./floor/grass.png");
    floor->lava = load_texture_from_filepath (renderer, "./floor/lava.png");
    floor->water = load_texture_from_filepath (renderer, "./floor/water.png");
    floor->rock = load_texture_from_filepath (renderer, "./floor/rock.png");
    floor->stone = load_texture_from_filepath (renderer, "./floor/stone.png");
    floor->metal = load_texture_from_filepath (renderer, "./floor/metal.png");
    floor->metal_spikes = load_texture_from_filepath (renderer, "./floor/metal_spikes.png");
}
void destroy_textures_floor (Textures_Floor* floor)
{
    destroy_texture(floor->grass);
    destroy_texture(floor->lava);
    destroy_texture(floor->water);
    destroy_texture(floor->rock);
    destroy_texture(floor->stone);
    destroy_texture(floor->metal);
    destroy_texture(floor->metal_spikes);
}

void load_textures_highlight (Renderer* renderer, Textures_Highlight* highlight)
{
    highlight->red = load_texture_from_filepath (renderer, "./highlight/red.png");
    highlight->orange = load_texture_from_filepath (renderer, "./highlight/orange.png");
    highlight->yellow = load_texture_from_filepath (renderer, "./highlight/yellow.png");
    highlight->green = load_texture_from_filepath (renderer, "./highlight/green.png");
    highlight->teal = load_texture_from_filepath (renderer, "./highlight/teal.png");
    highlight->blue = load_texture_from_filepath (renderer, "./highlight/blue.png");
    highlight->purple = load_texture_from_filepath (renderer, "./highlight/purple.png");
    highlight->pink = load_texture_from_filepath (renderer, "./highlight/pink.png");
    highlight->grey = load_texture_from_filepath (renderer, "./highlight/grey.png");
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
    danger->frame_1 = load_texture_from_filepath (renderer, "./danger/frame_1.png");
    danger->frame_2 = load_texture_from_filepath (renderer, "./danger/frame_2.png");
    danger->frame_3 = load_texture_from_filepath (renderer, "./danger/frame_3.png");
    danger->frame_4 = load_texture_from_filepath (renderer, "./danger/frame_4.png");
    danger->frame_5 = load_texture_from_filepath (renderer, "./danger/frame_5.png");
    danger->frame_6 = load_texture_from_filepath (renderer, "./danger/frame_6.png");
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
    move->up = load_texture_from_filepath (renderer, "./move/up.png");
    move->right = load_texture_from_filepath (renderer, "./move/right.png");
    move->down = load_texture_from_filepath (renderer, "./move/down.png");
    move->left = load_texture_from_filepath (renderer, "./move/left.png");
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
    push->up = load_texture_from_filepath (renderer, "./push/up.png");
    push->right = load_texture_from_filepath (renderer, "./push/right.png");
    push->down = load_texture_from_filepath (renderer, "./push/down.png");
    push->left = load_texture_from_filepath (renderer, "./push/left.png");
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
    crash->up = load_texture_from_filepath (renderer, "./crash/up.png");
    crash->right = load_texture_from_filepath (renderer, "./crash/right.png");
    crash->down = load_texture_from_filepath (renderer, "./crash/down.png");
    crash->left = load_texture_from_filepath (renderer, "./crash/left.png");
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
    blow_up->explosion = load_texture_from_filepath (renderer, "./blow_up/explosion.png");
}
void destroy_textures_blow_up (Textures_BlowUp* blow_up)
{
    destroy_texture(blow_up->explosion);
}

void load_textures_object (Renderer* renderer, Textures_Object* object)
{
    object->hero = load_texture_from_filepath (renderer, "./object/hero.png");
    object->pillar = load_texture_from_filepath (renderer, "./object/pillar.png");
    object->goat = load_texture_from_filepath (renderer, "./object/goat.png");
    object->spider = load_texture_from_filepath (renderer, "./object/spider.png");
}
void destroy_textures_object (Textures_Object* object)
{
    destroy_texture(object->pillar);
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

    destroy_textures_object (&textures->object);
}