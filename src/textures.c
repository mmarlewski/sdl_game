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

void load_textures_fall (Renderer* renderer, Textures_Fall* fall)
{
    fall->fall = load_texture_from_filepath (renderer, "./res/fall/fall.png");
}
void destroy_textures_fall (Textures_Fall* fall)
{
    destroy_texture(fall->fall);
}

void load_textures_death (Renderer* renderer, Textures_Death* death)
{
    death->death = load_texture_from_filepath (renderer, "./res/death/death.png");
    death->skull = load_texture_from_filepath (renderer, "./res/death/skull.png");
}
void destroy_textures_death (Textures_Death* death)
{
    destroy_texture(death->death);
    destroy_texture(death->skull);
}

void load_textures_blow_up (Renderer* renderer, Textures_BlowUp* blow_up)
{
    blow_up->blow_up = load_texture_from_filepath (renderer, "./res/blow_up/blow_up.png");
    blow_up->explosion = load_texture_from_filepath (renderer, "./res/blow_up/explosion.png");
}
void destroy_textures_blow_up (Textures_BlowUp* blow_up)
{
    destroy_texture(blow_up->blow_up);
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
    drop->drop = load_texture_from_filepath (renderer, "./res/drop/drop.png");
    drop->thump = load_texture_from_filepath (renderer, "./res/drop/thump.png");
}
void destroy_textures_drop (Textures_Drop* drop)
{
    destroy_texture(drop->drop);
    destroy_texture(drop->thump);
}

void load_textures_object (Renderer* renderer, Textures_Object* object)
{
    object->pillar = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar.png");
    object->pillar_outline_yellow = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar_outline_yellow.png");
    object->pillar_outline_red = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar_outline_red.png");

    object->pillar_spikes = load_texture_from_filepath
    (renderer, "./res/object/pillar_spikes/pillar_spikes.png");
    object->pillar_spikes_outline_yellow = load_texture_from_filepath
    (renderer, "./res/object/pillar_spikes/pillar_spikes_outline_yellow.png");
    object->pillar_spikes_outline_red = load_texture_from_filepath
     (renderer, "./res/object/pillar_spikes/pillar_spikes_outline_red.png");

    object->barrel = load_texture_from_filepath
    (renderer, "./res/object/barrel/barrel.png");
    object->barrel_outline_yellow = load_texture_from_filepath
     (renderer, "./res/object/barrel/barrel_outline_yellow.png");
    object->barrel_outline_red = load_texture_from_filepath
    (renderer, "./res/object/barrel/barrel_outline_red.png");

    object->spring = load_texture_from_filepath
    (renderer, "./res/object/spring/spring.png");
    object->spring_outline_yellow = load_texture_from_filepath
    (renderer, "./res/object/spring/spring_outline_yellow.png");
    object->spring_outline_red = load_texture_from_filepath
    (renderer, "./res/object/spring/spring_outline_red.png");

    object->hero = load_texture_from_filepath
    (renderer, "./res/object/hero/hero.png");
    object->hero_outline_yellow = load_texture_from_filepath
    (renderer, "./res/object/hero/hero_outline_yellow.png");
    object->hero_outline_red = load_texture_from_filepath
    (renderer, "./res/object/hero/hero_outline_red.png");

    object->goat = load_texture_from_filepath
     (renderer, "./res/object/goat/goat.png");
    object->goat_outline_yellow = load_texture_from_filepath
     (renderer, "./res/object/goat/goat_outline_yellow.png");
    object->goat_outline_red = load_texture_from_filepath
    (renderer, "./res/object/goat/goat_outline_red.png");

    object->spider = load_texture_from_filepath
    (renderer, "./res/object/spider/spider.png");
    object->spider_outline_yellow = load_texture_from_filepath
     (renderer, "./res/object/spider/spider_outline_yellow.png");
    object->spider_outline_red = load_texture_from_filepath
    (renderer, "./res/object/spider/spider_outline_red.png");

    object->bull = load_texture_from_filepath
    (renderer, "./res/object/bull/bull.png");
    object->bull_outline_yellow = load_texture_from_filepath
     (renderer, "./res/object/bull/bull_outline_yellow.png");
    object->bull_outline_red = load_texture_from_filepath
    (renderer, "./res/object/bull/bull_outline_red.png");

    object->fly = load_texture_from_filepath
    (renderer, "./res/object/fly/fly.png");
    object->fly_outline_yellow = load_texture_from_filepath
    (renderer, "./res/object/fly/fly_outline_yellow.png");
    object->fly_outline_red = load_texture_from_filepath
    (renderer, "./res/object/fly/fly_outline_red.png");

    object->chameleon = load_texture_from_filepath
    (renderer, "./res/object/chameleon/chameleon.png");
    object->chameleon_outline_yellow = load_texture_from_filepath
    (renderer, "./res/object/chameleon/chameleon_outline_yellow.png");
    object->chameleon_outline_red = load_texture_from_filepath
     (renderer, "./res/object/chameleon/chameleon_outline_red.png");
}
void destroy_textures_object (Textures_Object* object)
{
    destroy_texture(object->pillar);
    destroy_texture(object->pillar_outline_yellow);
    destroy_texture(object->pillar_outline_red);

    destroy_texture(object->pillar_spikes);
    destroy_texture(object->pillar_spikes_outline_yellow);
    destroy_texture(object->pillar_spikes_outline_red);

    destroy_texture(object->barrel);
    destroy_texture(object->barrel_outline_yellow);
    destroy_texture(object->barrel_outline_red);

    destroy_texture(object->spring);
    destroy_texture(object->spring_outline_yellow);
    destroy_texture(object->spring_outline_red);

    destroy_texture(object->hero);
    destroy_texture(object->hero_outline_yellow);
    destroy_texture(object->hero_outline_red);

    destroy_texture(object->goat);
    destroy_texture(object->goat_outline_yellow);
    destroy_texture(object->goat_outline_red);

    destroy_texture(object->spider);
    destroy_texture(object->spider_outline_yellow);
    destroy_texture(object->spider_outline_red);

    destroy_texture(object->bull);
    destroy_texture(object->bull_outline_yellow);
    destroy_texture(object->bull_outline_red);

    destroy_texture(object->fly);
    destroy_texture(object->fly_outline_yellow);
    destroy_texture(object->fly_outline_red);

    destroy_texture(object->chameleon);
    destroy_texture(object->chameleon_outline_yellow);
    destroy_texture(object->chameleon_outline_red);
}

void load_textures_order_number (Renderer* renderer, Textures_OrderNumber* order_number)
{
    order_number->num_1 = load_texture_from_filepath
     (renderer, "./res/order_number/num_1.png");
    order_number->num_2 = load_texture_from_filepath
    (renderer, "./res/order_number/num_2.png");
    order_number->num_3 = load_texture_from_filepath
    (renderer, "./res/order_number/num_3.png");
    order_number->num_4 = load_texture_from_filepath
    (renderer, "./res/order_number/num_4.png");
    order_number->num_5 = load_texture_from_filepath
    (renderer, "./res/order_number/num_5.png");
    order_number->num_6 = load_texture_from_filepath
    (renderer, "./res/order_number/num_6.png");
    order_number->num_7= load_texture_from_filepath
    (renderer, "./res/order_number/num_7.png");
    order_number->num_8 = load_texture_from_filepath
    (renderer, "./res/order_number/num_8.png");
    order_number->num_9 = load_texture_from_filepath
    (renderer, "./res/order_number/num_9.png");
    order_number->num_0 = load_texture_from_filepath
    (renderer, "./res/order_number/num_0.png");
}
void destroy_textures_order_number (Textures_OrderNumber* order_number)
{
    destroy_texture(order_number->num_1);
    destroy_texture(order_number->num_2);
    destroy_texture(order_number->num_3);
    destroy_texture(order_number->num_4);
    destroy_texture(order_number->num_5);
    destroy_texture(order_number->num_6);
    destroy_texture(order_number->num_7);
    destroy_texture(order_number->num_8);
    destroy_texture(order_number->num_9);
    destroy_texture(order_number->num_0);
}

void load_textures (Renderer* renderer, Textures* textures)
{
    load_textures_floor(renderer,&textures->floor);

    load_textures_highlight(renderer,&textures->highlight);
    load_textures_danger(renderer,&textures->danger);

    load_textures_move(renderer,&textures->move);
    load_textures_crash(renderer,&textures->crash);

    load_textures_fall(renderer,&textures->fall);
    load_textures_death(renderer,&textures->death);
    load_textures_blow_up(renderer,&textures->blow_up);

    load_textures_throw(renderer,&textures->throw);
    load_textures_drop(renderer,&textures->drop);

    load_textures_object(renderer,&textures->object);
    load_textures_order_number(renderer,&textures->order_number);
}

void destroy_textures (Textures* textures)
{
    destroy_textures_floor (&textures->floor);

    destroy_textures_highlight (&textures->highlight);
    destroy_textures_danger (&textures->danger);

    destroy_textures_move (&textures->move);
    destroy_textures_crash (&textures->crash);

    destroy_textures_fall (&textures->fall);
    destroy_textures_death (&textures->death);
    destroy_textures_blow_up (&textures->blow_up);

    destroy_textures_throw (&textures->throw);
    destroy_textures_drop (&textures->drop);

    destroy_textures_object (&textures->object);
    destroy_textures_order_number (&textures->order_number);
}

Texture* get_texture_move(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->move.up; break;
        case DIR4__RIGHT: texture = textures->move.right; break;
        case DIR4__DOWN: texture = textures->move.down; break;
        case DIR4__LEFT: texture = textures->move.left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_crash(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->crash.up; break;
        case DIR4__RIGHT: texture = textures->crash.right; break;
        case DIR4__DOWN: texture = textures->crash.down; break;
        case DIR4__LEFT: texture = textures->crash.left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_throw(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->throw.up; break;
        case DIR4__RIGHT: texture = textures->throw.right; break;
        case DIR4__DOWN: texture = textures->throw.down; break;
        case DIR4__LEFT: texture = textures->throw.left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_order_number(Textures* textures, int num)
{
    Texture* texture = textures->order_number.num_0;

    switch(num)
    {
        case 1: texture = textures->order_number.num_1; break;
        case 2: texture = textures->order_number.num_2; break;
        case 3: texture = textures->order_number.num_3; break;
        case 4: texture = textures->order_number.num_4; break;
        case 5: texture = textures->order_number.num_5; break;
        case 6: texture = textures->order_number.num_6; break;
        case 7: texture = textures->order_number.num_7; break;
        case 8: texture = textures->order_number.num_8; break;
        case 9: texture = textures->order_number.num_9; break;
        default: break;
    }

    return texture;
}
