#include "../inc/textures.h"

void load_textures_floor (Renderer* renderer, Textures_Floor* floor)
{
    floor->highlight = load_texture_from_filepath (renderer, "./res/floor/highlight.png");
    floor->rock = load_texture_from_filepath (renderer, "./res/floor/rock.png");
    floor->rock_crack_water = load_texture_from_filepath (renderer, "./res/floor/rock_crack_water.png");
    floor->rock_crack_lava = load_texture_from_filepath (renderer, "./res/floor/rock_crack_lava.png");
    floor->stone = load_texture_from_filepath (renderer, "./res/floor/stone.png");
    floor->stone_spikes_on = load_texture_from_filepath (renderer, "./res/floor/stone_spikes_on.png");
    floor->stone_spikes_off = load_texture_from_filepath (renderer, "./res/floor/stone_spikes_off.png");
    floor->metal = load_texture_from_filepath (renderer, "./res/floor/metal.png");
    floor->metal_hatch_open_1 = load_texture_from_filepath (renderer, "./res/floor/metal_hatch_open_1.png");
    floor->metal_hatch_open_2 = load_texture_from_filepath (renderer, "./res/floor/metal_hatch_open_2.png");
    floor->metal_hatch_closed = load_texture_from_filepath (renderer, "./res/floor/metal_hatch_closed.png");
    floor->metal_cover_bottom = load_texture_from_filepath (renderer, "./res/floor/metal_cover_bottom.png");
    floor->grass = load_texture_from_filepath (renderer, "./res/floor/grass.png");
    floor->water_1 = load_texture_from_filepath (renderer, "./res/floor/water_1.png");
    floor->water_2 = load_texture_from_filepath (renderer, "./res/floor/water_2.png");
    floor->water_stalactite_fallen_1 = load_texture_from_filepath (renderer, "./res/floor/water_stalactite_fallen_1.png");
    floor->water_stalactite_fallen_2 = load_texture_from_filepath (renderer, "./res/floor/water_stalactite_fallen_2.png");
    floor->lava_1 = load_texture_from_filepath (renderer, "./res/floor/lava_1.png");
    floor->lava_2 = load_texture_from_filepath (renderer, "./res/floor/lava_2.png");
    floor->lava_stalactite_fallen_1 = load_texture_from_filepath (renderer, "./res/floor/lava_stalactite_fallen_1.png");
    floor->lava_stalactite_fallen_2 = load_texture_from_filepath (renderer, "./res/floor/lava_stalactite_fallen_2.png");
    floor->ice = load_texture_from_filepath (renderer, "./res/floor/ice.png");
    floor->ice_crack_water = load_texture_from_filepath (renderer, "./res/floor/ice_crack_water.png");
}
void destroy_textures_floor (Textures_Floor* floor)
{
    destroy_texture(floor->highlight);
    destroy_texture(floor->rock);
    destroy_texture(floor->rock_crack_water);
    destroy_texture(floor->rock_crack_lava);
    destroy_texture(floor->stone);
    destroy_texture(floor->stone_spikes_on);
    destroy_texture(floor->stone_spikes_off);
    destroy_texture(floor->metal);
    destroy_texture(floor->metal_hatch_open_1);
    destroy_texture(floor->metal_hatch_open_2);
    destroy_texture(floor->metal_hatch_closed);
    destroy_texture(floor->metal_cover_bottom);
    destroy_texture(floor->grass);
    destroy_texture(floor->water_1);
    destroy_texture(floor->water_2);
    destroy_texture(floor->water_stalactite_fallen_1);
    destroy_texture(floor->water_stalactite_fallen_2);
    destroy_texture(floor->lava_1);
    destroy_texture(floor->lava_2);
    destroy_texture(floor->lava_stalactite_fallen_1);
    destroy_texture(floor->lava_stalactite_fallen_2);
    destroy_texture(floor->ice);
    destroy_texture(floor->ice_crack_water);
}

void load_textures_object (Renderer* renderer, Textures_Object* object)
{
    object->wall_rock = load_texture_from_filepath
    (renderer, "./res/object/wall_rock/wall_rock.png");
    object->wall_rock_outline = load_texture_from_filepath
    (renderer, "./res/object/wall_rock/wall_rock_outline.png");

    object->wall_stone = load_texture_from_filepath
    (renderer, "./res/object/wall_stone/wall_stone.png");
    object->wall_stone_outline = load_texture_from_filepath
    (renderer, "./res/object/wall_stone/wall_stone_outline.png");

    object->wall_metal = load_texture_from_filepath
    (renderer, "./res/object/wall_metal/wall_metal.png");
    object->wall_metal_outline = load_texture_from_filepath
    (renderer, "./res/object/wall_metal/wall_metal_outline.png");

    object->exit_rock_up = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_up.png");
    object->exit_rock_up_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_up_outline.png");
    object->exit_rock_right = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_right.png");
    object->exit_rock_right_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_right_outline.png");
    object->exit_rock_down = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_down.png");
    object->exit_rock_down_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_down_outline.png");
    object->exit_rock_left = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_left.png");
    object->exit_rock_left_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_rock/exit_rock_left_outline.png");

    object->exit_stone_up = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_up.png");
    object->exit_stone_up_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_up_outline.png");
    object->exit_stone_right = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_right.png");
    object->exit_stone_right_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_right_outline.png");
    object->exit_stone_down = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_down.png");
    object->exit_stone_down_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_down_outline.png");
    object->exit_stone_left = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_left.png");
    object->exit_stone_left_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_stone/exit_stone_left_outline.png");

    object->exit_metal_up = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_up.png");
    object->exit_metal_up_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_up_outline.png");
    object->exit_metal_right = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_right.png");
    object->exit_metal_right_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_right_outline.png");
    object->exit_metal_down = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_down.png");
    object->exit_metal_down_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_down_outline.png");
    object->exit_metal_left = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_left.png");
    object->exit_metal_left_outline = load_texture_from_filepath
    (renderer, "./res/object/exit_metal/exit_metal_left_outline.png");

    object->stalactite = load_texture_from_filepath
    (renderer, "./res/object/stalactite/stalactite.png");
    object->stalactite_outline = load_texture_from_filepath
    (renderer, "./res/object/stalactite/stalactite_outline.png");

    object->stalactite_fallen = load_texture_from_filepath
    (renderer, "./res/object/stalactite_fallen/stalactite_fallen.png");
    object->stalactite_fallen_outline = load_texture_from_filepath
    (renderer, "./res/object/stalactite_fallen/stalactite_fallen_outline.png");

    object->stalagmite = load_texture_from_filepath
    (renderer, "./res/object/stalagmite/stalagmite.png");
    object->stalagmite_outline = load_texture_from_filepath
    (renderer, "./res/object/stalagmite/stalagmite_outline.png");

    object->stalagnate = load_texture_from_filepath
    (renderer, "./res/object/stalagnate/stalagnate.png");
    object->stalagnate_outline = load_texture_from_filepath
    (renderer, "./res/object/stalagnate/stalagnate_outline.png");

    object->pillar = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar.png");
    object->pillar_outline = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar_outline.png");
    object->pillar_spikes = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar_spikes.png");
    object->pillar_spikes_outline = load_texture_from_filepath
    (renderer, "./res/object/pillar/pillar_spikes_outline.png");

    object->cover = load_texture_from_filepath
    (renderer, "./res/object/cover/cover.png");
    object->cover_outline = load_texture_from_filepath
     (renderer, "./res/object/cover/cover_outline.png");

    object->rock = load_texture_from_filepath
    (renderer, "./res/object/rock/rock.png");
    object->rock_outline = load_texture_from_filepath
     (renderer, "./res/object/rock/rock_outline.png");

    object->rock_damaged = load_texture_from_filepath
    (renderer, "./res/object/rock_damaged/rock_damaged.png");
    object->rock_damaged_outline = load_texture_from_filepath
     (renderer, "./res/object/rock_damaged/rock_damaged_outline.png");

    object->safe = load_texture_from_filepath
    (renderer, "./res/object/safe/safe.png");
    object->safe_outline = load_texture_from_filepath
     (renderer, "./res/object/safe/safe_outline.png");

    object->safe_damaged = load_texture_from_filepath
    (renderer, "./res/object/safe_damaged/safe_damaged.png");
    object->safe_damaged_outline = load_texture_from_filepath
     (renderer, "./res/object/safe_damaged/safe_damaged_outline.png");

    object->barrel = load_texture_from_filepath
    (renderer, "./res/object/barrel/barrel.png");
    object->barrel_outline = load_texture_from_filepath
     (renderer, "./res/object/barrel/barrel_outline.png");

    object->spring = load_texture_from_filepath
    (renderer, "./res/object/spring/spring.png");
    object->spring_outline = load_texture_from_filepath
    (renderer, "./res/object/spring/spring_outline.png");

    object->weight = load_texture_from_filepath
    (renderer, "./res/object/weight/weight.png");
    object->weight_outline = load_texture_from_filepath
    (renderer, "./res/object/weight/weight_outline.png");

    object->hero_1 = load_texture_from_filepath
    (renderer, "./res/object/hero/hero_1.png");
    object->hero_2 = load_texture_from_filepath
    (renderer, "./res/object/hero/hero_2.png");
    object->hero_outline_1 = load_texture_from_filepath
    (renderer, "./res/object/hero/hero_outline_1.png");
    object->hero_outline_2 = load_texture_from_filepath
    (renderer, "./res/object/hero/hero_outline_2.png");

    object->goat_1 = load_texture_from_filepath
     (renderer, "./res/object/goat/goat_1.png");
    object->goat_2 = load_texture_from_filepath
     (renderer, "./res/object/goat/goat_2.png");
    object->goat_outline_1 = load_texture_from_filepath
     (renderer, "./res/object/goat/goat_outline_1.png");
    object->goat_outline_2 = load_texture_from_filepath
     (renderer, "./res/object/goat/goat_outline_2.png");

    object->spider_1 = load_texture_from_filepath
    (renderer, "./res/object/spider/spider_1.png");
    object->spider_2 = load_texture_from_filepath
    (renderer, "./res/object/spider/spider_2.png");
    object->spider_outline_1 = load_texture_from_filepath
     (renderer, "./res/object/spider/spider_outline_1.png");
    object->spider_outline_2 = load_texture_from_filepath
     (renderer, "./res/object/spider/spider_outline_2.png");

    object->bull_1 = load_texture_from_filepath
    (renderer, "./res/object/bull/bull_1.png");
    object->bull_2 = load_texture_from_filepath
    (renderer, "./res/object/bull/bull_2.png");
    object->bull_outline_1 = load_texture_from_filepath
     (renderer, "./res/object/bull/bull_outline_1.png");
    object->bull_outline_2 = load_texture_from_filepath
     (renderer, "./res/object/bull/bull_outline_2.png");

    object->fly_1 = load_texture_from_filepath
    (renderer, "./res/object/fly/fly_1.png");
    object->fly_2 = load_texture_from_filepath
    (renderer, "./res/object/fly/fly_2.png");
    object->fly_outline_1 = load_texture_from_filepath
    (renderer, "./res/object/fly/fly_outline_1.png");
    object->fly_outline_2 = load_texture_from_filepath
    (renderer, "./res/object/fly/fly_outline_2.png");

    object->chameleon_1 = load_texture_from_filepath
    (renderer, "./res/object/chameleon/chameleon_1.png");
    object->chameleon_2 = load_texture_from_filepath
    (renderer, "./res/object/chameleon/chameleon_2.png");
    object->chameleon_outline_1 = load_texture_from_filepath
    (renderer, "./res/object/chameleon/chameleon_outline_1.png");
    object->chameleon_outline_2 = load_texture_from_filepath
    (renderer, "./res/object/chameleon/chameleon_outline_2.png");
}

void destroy_textures_object (Textures_Object* object)
{
    destroy_texture(object->pillar);
    destroy_texture(object->pillar_outline);

    destroy_texture(object->pillar_spikes);
    destroy_texture(object->pillar_spikes_outline);

    destroy_texture(object->barrel);
    destroy_texture(object->barrel_outline);

    destroy_texture(object->spring);
    destroy_texture(object->spring_outline);

    destroy_texture(object->hero_1);
    destroy_texture(object->hero_2);
    destroy_texture(object->hero_outline_1);
    destroy_texture(object->hero_outline_2);

    destroy_texture(object->goat_1);
    destroy_texture(object->goat_2);
    destroy_texture(object->goat_outline_1);
    destroy_texture(object->goat_outline_2);

    destroy_texture(object->spider_1);
    destroy_texture(object->spider_2);
    destroy_texture(object->spider_outline_1);
    destroy_texture(object->spider_outline_2);

    destroy_texture(object->bull_1);
    destroy_texture(object->bull_2);
    destroy_texture(object->bull_outline_1);
    destroy_texture(object->bull_outline_2);

    destroy_texture(object->fly_1);
    destroy_texture(object->fly_2);
    destroy_texture(object->fly_outline_1);
    destroy_texture(object->fly_outline_2);

    destroy_texture(object->chameleon_1);
    destroy_texture(object->chameleon_2);
    destroy_texture(object->chameleon_outline_1);
    destroy_texture(object->chameleon_outline_2);
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

void load_textures_action (Renderer* renderer, Textures_Action* action)
{
    action->none = load_texture_from_filepath (renderer, "./res/action/none/none.png");
    action->move_up = load_texture_from_filepath (renderer, "./res/action/move/up.png");
    action->move_right = load_texture_from_filepath (renderer, "./res/action/move/right.png");
    action->move_down = load_texture_from_filepath (renderer, "./res/action/move/down.png");
    action->move_left = load_texture_from_filepath (renderer, "./res/action/move/left.png");
    action->crash_up = load_texture_from_filepath (renderer, "./res/action/crash/up.png");
    action->crash_right = load_texture_from_filepath (renderer, "./res/action/crash/right.png");
    action->crash_down = load_texture_from_filepath (renderer, "./res/action/crash/down.png");
    action->crash_left = load_texture_from_filepath (renderer, "./res/action/crash/left.png");
    action->fall = load_texture_from_filepath (renderer, "./res/action/fall/fall.png");
    action->death = load_texture_from_filepath (renderer, "./res/action/death/death.png");
    action->skull = load_texture_from_filepath (renderer, "./res/action/death/skull.png");
    action->blow_up = load_texture_from_filepath (renderer, "./res/action/blow_up/blow_up.png");
    action->explosion = load_texture_from_filepath (renderer, "./res/action/blow_up/explosion.png");
    action->throw_up = load_texture_from_filepath (renderer, "./res/action/throw/up.png");
    action->throw_right = load_texture_from_filepath (renderer, "./res/action/throw/right.png");
    action->throw_down = load_texture_from_filepath (renderer, "./res/action/throw/down.png");
    action->throw_left = load_texture_from_filepath (renderer, "./res/action/throw/left.png");
    action->lift_none = load_texture_from_filepath (renderer, "./res/action/lift/none.png");
    action->lift_up = load_texture_from_filepath (renderer, "./res/action/lift/up.png");
    action->lift_right = load_texture_from_filepath (renderer, "./res/action/lift/right.png");
    action->lift_down = load_texture_from_filepath (renderer, "./res/action/lift/down.png");
    action->lift_left = load_texture_from_filepath (renderer, "./res/action/lift/left.png");
    action->drop = load_texture_from_filepath (renderer, "./res/action/drop/drop.png");
    action->thump = load_texture_from_filepath (renderer, "./res/action/drop/thump.png");
    action->change = load_texture_from_filepath (renderer, "./res/action/change/change.png");
}
void destroy_textures_action (Textures_Action* action)
{
    destroy_texture(action->none);
    destroy_texture(action->move_up);
    destroy_texture(action->move_right);
    destroy_texture(action->move_down);
    destroy_texture(action->move_left);
    destroy_texture(action->crash_up);
    destroy_texture(action->crash_right);
    destroy_texture(action->crash_down);
    destroy_texture(action->crash_left);
    destroy_texture(action->fall);
    destroy_texture(action->death);
    destroy_texture(action->skull);
    destroy_texture(action->blow_up);
    destroy_texture(action->explosion);
    destroy_texture(action->throw_up);
    destroy_texture(action->throw_right);
    destroy_texture(action->throw_down);
    destroy_texture(action->throw_left);
    destroy_texture(action->lift_none);
    destroy_texture(action->lift_up);
    destroy_texture(action->lift_right);
    destroy_texture(action->lift_down);
    destroy_texture(action->lift_left);
    destroy_texture(action->drop);
    destroy_texture(action->thump);
    destroy_texture(action->change);
}

void load_textures (Renderer* renderer, Textures* textures)
{
    load_textures_floor(renderer,&textures->floor);
    load_textures_object(renderer,&textures->object);
    load_textures_order_number(renderer,&textures->order_number);
    load_textures_action(renderer,&textures->action);
}

void destroy_textures (Textures* textures)
{
    destroy_textures_floor (&textures->floor);
    destroy_textures_object (&textures->object);
    destroy_textures_order_number (&textures->order_number);
    destroy_textures_action(&textures->action);
}

Texture* get_texture_move(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->action.move_up; break;
        case DIR4__RIGHT: texture = textures->action.move_right; break;
        case DIR4__DOWN: texture = textures->action.move_down; break;
        case DIR4__LEFT: texture = textures->action.move_left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_crash(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->action.crash_up; break;
        case DIR4__RIGHT: texture = textures->action.crash_right; break;
        case DIR4__DOWN: texture = textures->action.crash_down; break;
        case DIR4__LEFT: texture = textures->action.crash_left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_throw(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->action.throw_up; break;
        case DIR4__RIGHT: texture = textures->action.throw_right; break;
        case DIR4__DOWN: texture = textures->action.throw_down; break;
        case DIR4__LEFT: texture = textures->action.throw_left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_lift(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__NONE: texture = textures->action.lift_none; break;
        case DIR4__UP: texture = textures->action.lift_up; break;
        case DIR4__RIGHT: texture = textures->action.lift_right; break;
        case DIR4__DOWN: texture = textures->action.lift_down; break;
        case DIR4__LEFT: texture = textures->action.lift_left; break;
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
