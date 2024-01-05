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
    floor->metal_piston = load_texture_from_filepath (renderer, "./res/floor/metal_piston.png");
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
    destroy_texture(floor->metal_piston);
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
    object->wall_rock = load_texture_from_filepath(renderer, "./res/object/wall_rock.png");
    object->wall_rock_outline = load_texture_from_filepath(renderer, "./res/object/wall_rock_outline.png");

    object->wall_stone = load_texture_from_filepath(renderer, "./res/object/wall_stone.png");
    object->wall_stone_outline = load_texture_from_filepath(renderer, "./res/object/wall_stone_outline.png");

    object->wall_metal = load_texture_from_filepath(renderer, "./res/object/wall_metal.png");
    object->wall_metal_outline = load_texture_from_filepath(renderer, "./res/object/wall_metal_outline.png");

    object->exit_rock_up = load_texture_from_filepath(renderer, "./res/object/exit_rock_up.png");
    object->exit_rock_blocked_up = load_texture_from_filepath(renderer, "./res/object/exit_rock_blocked_up.png");
    object->exit_rock_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_rock_up_outline.png");

    object->exit_rock_right = load_texture_from_filepath(renderer, "./res/object/exit_rock_right.png");
    object->exit_rock_blocked_right = load_texture_from_filepath(renderer, "./res/object/exit_rock_blocked_right.png");
    object->exit_rock_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_rock_right_outline.png");

    object->exit_rock_down = load_texture_from_filepath(renderer, "./res/object/exit_rock_down.png");
    object->exit_rock_blocked_down = load_texture_from_filepath(renderer, "./res/object/exit_rock_blocked_down.png");
    object->exit_rock_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_rock_down_outline.png");

    object->exit_rock_left = load_texture_from_filepath(renderer, "./res/object/exit_rock_left.png");
    object->exit_rock_blocked_left = load_texture_from_filepath(renderer, "./res/object/exit_rock_blocked_left.png");
    object->exit_rock_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_rock_left_outline.png");

    object->exit_stone_up = load_texture_from_filepath(renderer, "./res/object/exit_stone_up.png");
    object->exit_stone_blocked_up = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_up.png");
    object->exit_stone_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_up_outline.png");

    object->exit_stone_right = load_texture_from_filepath(renderer, "./res/object/exit_stone_right.png");
    object->exit_stone_blocked_right = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_right.png");
    object->exit_stone_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_right_outline.png");

    object->exit_stone_down = load_texture_from_filepath(renderer, "./res/object/exit_stone_down.png");
    object->exit_stone_blocked_down = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_down.png");
    object->exit_stone_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_down_outline.png");

    object->exit_stone_left = load_texture_from_filepath(renderer, "./res/object/exit_stone_left.png");
    object->exit_stone_blocked_left = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_left.png");
    object->exit_stone_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_left_outline.png");

    object->exit_metal_up = load_texture_from_filepath(renderer, "./res/object/exit_metal_up.png");
    object->exit_metal_blocked_up = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_up.png");
    object->exit_metal_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_up_outline.png");

    object->exit_metal_right = load_texture_from_filepath(renderer, "./res/object/exit_metal_right.png");
    object->exit_metal_blocked_right = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_right.png");
    object->exit_metal_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_right_outline.png");

    object->exit_metal_down = load_texture_from_filepath(renderer, "./res/object/exit_metal_down.png");
    object->exit_metal_blocked_down = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_down.png");
    object->exit_metal_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_down_outline.png");

    object->exit_metal_left = load_texture_from_filepath(renderer, "./res/object/exit_metal_left.png");
    object->exit_metal_blocked_left = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_left.png");
    object->exit_metal_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_left_outline.png");

    object->stalactite = load_texture_from_filepath(renderer, "./res/object/stalactite.png");
    object->stalactite_outline = load_texture_from_filepath(renderer, "./res/object/stalactite_outline.png");

    object->stalactite_fallen = load_texture_from_filepath(renderer, "./res/object/stalactite_fallen.png");
    object->stalactite_fallen_outline = load_texture_from_filepath(renderer, "./res/object/stalactite_fallen_outline.png");

    object->stalactite_fallen_item = load_texture_from_filepath(renderer, "./res/object/stalactite_fallen_item.png");
    object->stalactite_fallen_item_outline = load_texture_from_filepath(renderer, "./res/object/stalactite_fallen_item_outline.png");

    object->stalagmite = load_texture_from_filepath(renderer, "./res/object/stalagmite.png");
    object->stalagmite_outline = load_texture_from_filepath(renderer, "./res/object/stalagmite_outline.png");

    object->stalagnate = load_texture_from_filepath(renderer, "./res/object/stalagnate.png");
    object->stalagnate_outline = load_texture_from_filepath(renderer, "./res/object/stalagnate_outline.png");

    object->pillar = load_texture_from_filepath(renderer, "./res/object/pillar.png");
    object->pillar_outline = load_texture_from_filepath(renderer, "./res/object/pillar_outline.png");

    object->pipe = load_texture_from_filepath(renderer, "./res/object/pipe.png");
    object->pipe_outline = load_texture_from_filepath(renderer, "./res/object/pipe_outline.png");

    object->cover_rock = load_texture_from_filepath(renderer, "./res/object/cover_rock.png");
    object->cover_rock_outline = load_texture_from_filepath(renderer, "./res/object/cover_rock_outline.png");

    object->cover_metal = load_texture_from_filepath(renderer, "./res/object/cover_metal.png");
    object->cover_metal_outline = load_texture_from_filepath(renderer, "./res/object/cover_metal_outline.png");

    object->cover_glass = load_texture_from_filepath(renderer, "./res/object/cover_glass.png");
    object->cover_glass_outline = load_texture_from_filepath(renderer, "./res/object/cover_glass_outline.png");

    object->crate_gemstone = load_texture_from_filepath(renderer, "./res/object/crate_gemstone.png");
    object->crate_gemstone_outline = load_texture_from_filepath(renderer, "./res/object/crate_gemstone_outline.png");

    object->crate_gemstone_item = load_texture_from_filepath(renderer, "./res/object/crate_gemstone_item.png");
    object->crate_gemstone_item_outline = load_texture_from_filepath(renderer, "./res/object/crate_gemstone_item_outline.png");

    object->crate_cell = load_texture_from_filepath(renderer, "./res/object/crate_cell.png");
    object->crate_cell_outline = load_texture_from_filepath(renderer, "./res/object/crate_cell_outline.png");

    object->crate_cell_item = load_texture_from_filepath(renderer, "./res/object/crate_cell_item.png");
    object->crate_cell_item_outline = load_texture_from_filepath(renderer, "./res/object/crate_cell_item_outline.png");

    object->crate_dynamite = load_texture_from_filepath(renderer, "./res/object/crate_dynamite.png");
    object->crate_dynamite_outline = load_texture_from_filepath(renderer, "./res/object/crate_dynamite_outline.png");

    object->crate_dynamite_item = load_texture_from_filepath(renderer, "./res/object/crate_dynamite_item.png");
    object->crate_dynamite_item_outline = load_texture_from_filepath(renderer, "./res/object/crate_dynamite_item_outline.png");

    object->rock = load_texture_from_filepath(renderer, "./res/object/rock.png");
    object->rock_outline = load_texture_from_filepath(renderer, "./res/object/rock_outline.png");

    object->rock_item = load_texture_from_filepath(renderer, "./res/object/rock_item.png");
    object->rock_item_outline = load_texture_from_filepath(renderer, "./res/object/rock_item_outline.png");

    object->rock_damaged = load_texture_from_filepath(renderer, "./res/object/rock_damaged.png");
    object->rock_damaged_outline = load_texture_from_filepath(renderer, "./res/object/rock_damaged_outline.png");

    object->rock_damaged_item = load_texture_from_filepath(renderer, "./res/object/rock_damaged_item.png");
    object->rock_damaged_item_outline = load_texture_from_filepath(renderer, "./res/object/rock_damaged_item_outline.png");

    object->safe = load_texture_from_filepath(renderer, "./res/object/safe.png");
    object->safe_outline = load_texture_from_filepath(renderer, "./res/object/safe_outline.png");

    object->safe_item = load_texture_from_filepath(renderer, "./res/object/safe_item.png");
    object->safe_item_outline = load_texture_from_filepath(renderer, "./res/object/safe_item_outline.png");

    object->safe_damaged = load_texture_from_filepath(renderer, "./res/object/safe_damaged.png");
    object->safe_damaged_outline = load_texture_from_filepath(renderer, "./res/object/safe_damaged_outline.png");

    object->safe_damaged_item = load_texture_from_filepath(renderer, "./res/object/safe_damaged_item.png");
    object->safe_damaged_item_outline = load_texture_from_filepath(renderer, "./res/object/safe_damaged_item_outline.png");

    object->display = load_texture_from_filepath(renderer, "./res/object/display.png");
    object->display_outline = load_texture_from_filepath(renderer, "./res/object/display_outline.png");

    object->display_item = load_texture_from_filepath(renderer, "./res/object/display_item.png");
    object->display_item_outline = load_texture_from_filepath(renderer, "./res/display_item_outline.png");

    object->display_damaged = load_texture_from_filepath(renderer, "./res/object/display_damaged.png");
    object->display_damaged_outline = load_texture_from_filepath(renderer, "./res/object/display_damaged_outline.png");

    object->display_damaged_item = load_texture_from_filepath(renderer, "./res/object/display_damaged_item.png");
    object->display_damaged_item_outline = load_texture_from_filepath(renderer, "./res/object/display_damaged_item_outline.png");

    object->vending_cell = load_texture_from_filepath(renderer, "./res/object/vending_cell.png");
    object->vending_cell_outline = load_texture_from_filepath(renderer, "./res/object/vending_cell_outline.png");

    object->vending_cell_item = load_texture_from_filepath(renderer, "./res/object/vending_cell_item.png");
    object->vending_cell_item_outline = load_texture_from_filepath(renderer, "./res/object/vending_cell_item_outline.png");

    object->vending_cell_damaged = load_texture_from_filepath(renderer, "./res/object/vending_cell_damaged.png");
    object->vending_cell_damaged_outline = load_texture_from_filepath(renderer, "./res/object/vending_cell_damaged_outline.png");

    object->vending_cell_damaged_item = load_texture_from_filepath(renderer, "./res/object/vending_cell_damaged_item.png");
    object->vending_cell_damaged_item_outline = load_texture_from_filepath(renderer, "./res/object/vending_cell_damaged_item_outline.png");

    object->vending_dynamite = load_texture_from_filepath(renderer, "./res/object/vending_dynamite.png");
    object->vending_dynamite_outline = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_outline.png");

    object->vending_dynamite_item = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_item.png");
    object->vending_dynamite_item_outline = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_item_outline.png");

    object->vending_dynamite_damaged = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_damaged.png");
    object->vending_dynamite_damaged_outline = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_damaged_outline.png");

    object->vending_dynamite_damaged_item = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_damaged_item.png");
    object->vending_dynamite_damaged_item_outline = load_texture_from_filepath(renderer, "./res/object/vending_dynamite_damaged_item_outline.png");

    object->barrel = load_texture_from_filepath(renderer, "./res/object/barrel.png");
    object->barrel_outline = load_texture_from_filepath(renderer, "./res/object/barrel_outline.png");

    object->spring = load_texture_from_filepath(renderer, "./res/object/spring.png");
    object->spring_outline = load_texture_from_filepath(renderer, "./res/object/spring_outline.png");

    object->weight = load_texture_from_filepath(renderer, "./res/object/weight.png");
    object->weight_outline = load_texture_from_filepath(renderer, "./res/object/weight_outline.png");

    object->piston = load_texture_from_filepath(renderer, "./res/object/piston.png");
    object->piston_outline = load_texture_from_filepath(renderer, "./res/object/piston_outline.png");

    object->ball = load_texture_from_filepath(renderer, "./res/object/ball.png");
    object->ball_outline = load_texture_from_filepath(renderer, "./res/object/ball_outline.png");

    object->ball_spikes = load_texture_from_filepath(renderer, "./res/object/ball_spikes.png");
    object->ball_spikes_outline = load_texture_from_filepath(renderer, "./res/object/ball_spikes_outline.png");

    object->hero_1 = load_texture_from_filepath(renderer, "./res/object/hero_1.png");
    object->hero_2 = load_texture_from_filepath(renderer, "./res/object/hero_2.png");
    object->hero_outline_1 = load_texture_from_filepath(renderer, "./res/object/hero_outline_1.png");
    object->hero_outline_2 = load_texture_from_filepath(renderer, "./res/object/hero_outline_2.png");

    object->goat_1 = load_texture_from_filepath(renderer, "./res/object/goat_1.png");
    object->goat_2 = load_texture_from_filepath(renderer, "./res/object/goat_2.png");
    object->goat_outline_1 = load_texture_from_filepath(renderer, "./res/object/goat_outline_1.png");
    object->goat_outline_2 = load_texture_from_filepath(renderer, "./res/object/goat_outline_2.png");

    object->spider_1 = load_texture_from_filepath(renderer, "./res/object/spider_1.png");
    object->spider_2 = load_texture_from_filepath(renderer, "./res/object/spider_2.png");
    object->spider_outline_1 = load_texture_from_filepath(renderer, "./res/object/spider_outline_1.png");
    object->spider_outline_2 = load_texture_from_filepath(renderer, "./res/object/spider_outline_2.png");

    object->bull_1 = load_texture_from_filepath(renderer, "./res/object/bull_1.png");
    object->bull_2 = load_texture_from_filepath(renderer, "./res/object/bull_2.png");
    object->bull_outline_1 = load_texture_from_filepath(renderer, "./res/object/bull_outline_1.png");
    object->bull_outline_2 = load_texture_from_filepath(renderer, "./res/object/bull_outline_2.png");

    object->fly_1 = load_texture_from_filepath(renderer, "./res/object/fly_1.png");
    object->fly_2 = load_texture_from_filepath(renderer, "./res/object/fly_2.png");
    object->fly_outline_1 = load_texture_from_filepath(renderer, "./res/object/fly_outline_1.png");
    object->fly_outline_2 = load_texture_from_filepath(renderer, "./res/object/fly_outline_2.png");

    object->chameleon_1 = load_texture_from_filepath(renderer, "./res/object/chameleon_1.png");
    object->chameleon_2 = load_texture_from_filepath(renderer, "./res/object/chameleon_2.png");
    object->chameleon_outline_1 = load_texture_from_filepath(renderer, "./res/object/chameleon_outline_1.png");
    object->chameleon_outline_2 = load_texture_from_filepath(renderer, "./res/object/chameleon_outline_2.png");

    object->turret_grounded_1 = load_texture_from_filepath(renderer, "./res/object/turret_grounded_1.png");
    object->turret_grounded_2 = load_texture_from_filepath(renderer, "./res/object/turret_grounded_2.png");
    object->turret_grounded_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_grounded_outline_1.png");
    object->turret_grounded_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_grounded_outline_2.png");

    object->turret_standing_1 = load_texture_from_filepath(renderer, "./res/object/turret_standing_1.png");
    object->turret_standing_2 = load_texture_from_filepath(renderer, "./res/object/turret_standing_2.png");
    object->turret_standing_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_standing_outline_1.png");
    object->turret_standing_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_standing_outline_2.png");

    object->turret_undeployed = load_texture_from_filepath(renderer, "./res/object/turret_undeployed.png");
    object->turret_undeployed_outline = load_texture_from_filepath(renderer, "./res/object/turret_undeployed_outline.png");

    object->turret_deployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_deployed_1.png");
    object->turret_deployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_deployed_2.png");
    object->turret_deployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_deployed_outline_1.png");
    object->turret_deployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_deployed_outline_2.png");
}

void destroy_textures_object (Textures_Object* object)
{
    // later
}

void load_textures_order_number (Renderer* renderer, Textures_OrderNumber* order_number)
{
    order_number->num_1 = load_texture_from_filepath(renderer, "./res/order_number/num_1.png");
    order_number->num_2 = load_texture_from_filepath(renderer, "./res/order_number/num_2.png");
    order_number->num_3 = load_texture_from_filepath(renderer, "./res/order_number/num_3.png");
    order_number->num_4 = load_texture_from_filepath(renderer, "./res/order_number/num_4.png");
    order_number->num_5 = load_texture_from_filepath(renderer, "./res/order_number/num_5.png");
    order_number->num_6 = load_texture_from_filepath(renderer, "./res/order_number/num_6.png");
    order_number->num_7= load_texture_from_filepath(renderer, "./res/order_number/num_7.png");
    order_number->num_8 = load_texture_from_filepath(renderer, "./res/order_number/num_8.png");
    order_number->num_9 = load_texture_from_filepath(renderer, "./res/order_number/num_9.png");
    order_number->num_0 = load_texture_from_filepath(renderer, "./res/order_number/num_0.png");
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

void load_textures_skill (Renderer* renderer, Textures_Skill* skill)
{
    skill->none = load_texture_from_filepath (renderer, "./res/skill/none.png");
    skill->move_up = load_texture_from_filepath (renderer, "./res/skill/move_up.png");
    skill->move_right = load_texture_from_filepath (renderer, "./res/skill/move_right.png");
    skill->move_down = load_texture_from_filepath (renderer, "./res/skill/move_down.png");
    skill->move_left = load_texture_from_filepath (renderer, "./res/skill/move_left.png");
    skill->immovable = load_texture_from_filepath (renderer, "./res/skill/immovable.png");
    skill->crash_up = load_texture_from_filepath (renderer, "./res/skill/crash_up.png");
    skill->crash_right = load_texture_from_filepath (renderer, "./res/skill/crash_right.png");
    skill->crash_down = load_texture_from_filepath (renderer, "./res/skill/crash_down.png");
    skill->crash_left = load_texture_from_filepath (renderer, "./res/skill/crash_left.png");
    skill->crash = load_texture_from_filepath (renderer, "./res/skill/crash.png");
    skill->fall = load_texture_from_filepath (renderer, "./res/skill/fall.png");
    skill->death = load_texture_from_filepath (renderer, "./res/skill/death.png");
    skill->skull = load_texture_from_filepath (renderer, "./res/skill/skull.png");
    skill->blow_up = load_texture_from_filepath (renderer, "./res/skill/blow_up.png");
    skill->explosion = load_texture_from_filepath (renderer, "./res/skill/explosion.png");
    skill->throw_up = load_texture_from_filepath (renderer, "./res/skill/throw_up.png");
    skill->throw_right = load_texture_from_filepath (renderer, "./res/skill/throw_right.png");
    skill->throw_down = load_texture_from_filepath (renderer, "./res/skill/throw_down.png");
    skill->throw_left = load_texture_from_filepath (renderer, "./res/skill/throw_left.png");
    skill->lift_none = load_texture_from_filepath (renderer, "./res/skill/lift_none.png");
    skill->lift_up = load_texture_from_filepath (renderer, "./res/skill/lift_up.png");
    skill->lift_right = load_texture_from_filepath (renderer, "./res/skill/lift_right.png");
    skill->lift_down = load_texture_from_filepath (renderer, "./res/skill/lift_down.png");
    skill->lift_left = load_texture_from_filepath (renderer, "./res/skill/lift_left.png");
    skill->drop = load_texture_from_filepath (renderer, "./res/skill/drop.png");
    skill->thump = load_texture_from_filepath (renderer, "./res/skill/thump.png");
    skill->change = load_texture_from_filepath (renderer, "./res/skill/change.png");

    skill->arrow_thin_up_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_up_start.png");
    skill->arrow_thin_up_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_up_end.png");
    skill->arrow_thin_up_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_up_up.png");
    skill->arrow_thin_up_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_up_right.png");
    skill->arrow_thin_up_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_up_down.png");
    skill->arrow_thin_up_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_up_left.png");

    skill->arrow_thin_right_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_right_start.png");
    skill->arrow_thin_right_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_right_end.png");
    skill->arrow_thin_right_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_right_up.png");
    skill->arrow_thin_right_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_right_right.png");
    skill->arrow_thin_right_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_right_down.png");
    skill->arrow_thin_right_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_right_left.png");

    skill->arrow_thin_down_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_down_start.png");
    skill->arrow_thin_down_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_down_end.png");
    skill->arrow_thin_down_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_down_up.png");
    skill->arrow_thin_down_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_down_right.png");
    skill->arrow_thin_down_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_down_down.png");
    skill->arrow_thin_down_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_down_left.png");

    skill->arrow_thin_left_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_left_start.png");
    skill->arrow_thin_left_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_left_end.png");
    skill->arrow_thin_left_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_left_up.png");
    skill->arrow_thin_left_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_left_right.png");
    skill->arrow_thin_left_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_left_down.png");
    skill->arrow_thin_left_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thin_left_left.png");

    skill->arrow_thick_up_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_up_start.png");
    skill->arrow_thick_up_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_up_end.png");
    skill->arrow_thick_up_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_up_up.png");
    skill->arrow_thick_up_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_up_right.png");
    skill->arrow_thick_up_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_up_down.png");
    skill->arrow_thick_up_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_up_left.png");

    skill->arrow_thick_right_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_right_start.png");
    skill->arrow_thick_right_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_right_end.png");
    skill->arrow_thick_right_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_right_up.png");
    skill->arrow_thick_right_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_right_right.png");
    skill->arrow_thick_right_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_right_down.png");
    skill->arrow_thick_right_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_right_left.png");

    skill->arrow_thick_down_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_down_start.png");
    skill->arrow_thick_down_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_down_end.png");
    skill->arrow_thick_down_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_down_up.png");
    skill->arrow_thick_down_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_down_right.png");
    skill->arrow_thick_down_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_down_down.png");
    skill->arrow_thick_down_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_down_left.png");

    skill->arrow_thick_left_start = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_left_start.png");
    skill->arrow_thick_left_end = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_left_end.png");
    skill->arrow_thick_left_up = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_left_up.png");
    skill->arrow_thick_left_right = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_left_right.png");
    skill->arrow_thick_left_down = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_left_down.png");
    skill->arrow_thick_left_left = load_texture_from_filepath (renderer, "./res/skill/arrow_thick_left_left.png");
}
void destroy_textures_skill (Textures_Skill* skill)
{
    destroy_texture(skill->none);
    destroy_texture(skill->move_up);
    destroy_texture(skill->move_right);
    destroy_texture(skill->move_down);
    destroy_texture(skill->move_left);
    destroy_texture(skill->crash_up);
    destroy_texture(skill->crash_right);
    destroy_texture(skill->crash_down);
    destroy_texture(skill->crash_left);
    destroy_texture(skill->fall);
    destroy_texture(skill->death);
    destroy_texture(skill->skull);
    destroy_texture(skill->blow_up);
    destroy_texture(skill->explosion);
    destroy_texture(skill->throw_up);
    destroy_texture(skill->throw_right);
    destroy_texture(skill->throw_down);
    destroy_texture(skill->throw_left);
    destroy_texture(skill->lift_none);
    destroy_texture(skill->lift_up);
    destroy_texture(skill->lift_right);
    destroy_texture(skill->lift_down);
    destroy_texture(skill->lift_left);
    destroy_texture(skill->drop);
    destroy_texture(skill->thump);
    destroy_texture(skill->change);
}

void load_textures (Renderer* renderer, Textures* textures)
{
    load_textures_floor(renderer,&textures->floor);
    load_textures_object(renderer,&textures->object);
    load_textures_order_number(renderer,&textures->order_number);
    load_textures_skill(renderer,&textures->skill);
}

void destroy_textures (Textures* textures)
{
    destroy_textures_floor (&textures->floor);
    destroy_textures_object (&textures->object);
    destroy_textures_order_number (&textures->order_number);
    destroy_textures_skill(&textures->skill);
}

Texture* get_texture_move(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.move_up; break;
        case DIR4__RIGHT: texture = textures->skill.move_right; break;
        case DIR4__DOWN: texture = textures->skill.move_down; break;
        case DIR4__LEFT: texture = textures->skill.move_left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_crash(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.crash_up; break;
        case DIR4__RIGHT: texture = textures->skill.crash_right; break;
        case DIR4__DOWN: texture = textures->skill.crash_down; break;
        case DIR4__LEFT: texture = textures->skill.crash_left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_throw(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.throw_up; break;
        case DIR4__RIGHT: texture = textures->skill.throw_right; break;
        case DIR4__DOWN: texture = textures->skill.throw_down; break;
        case DIR4__LEFT: texture = textures->skill.throw_left; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_lift(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__NONE: texture = textures->skill.lift_none; break;
        case DIR4__UP: texture = textures->skill.lift_up; break;
        case DIR4__RIGHT: texture = textures->skill.lift_right; break;
        case DIR4__DOWN: texture = textures->skill.lift_down; break;
        case DIR4__LEFT: texture = textures->skill.lift_left; break;
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

Texture* get_texture_arrow_thin_start(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.arrow_thin_up_start; break;
        case DIR4__RIGHT: texture = textures->skill.arrow_thin_right_start; break;
        case DIR4__DOWN: texture = textures->skill.arrow_thin_down_start; break;
        case DIR4__LEFT: texture = textures->skill.arrow_thin_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_arrow_thin_end(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.arrow_thin_up_end; break;
        case DIR4__RIGHT: texture = textures->skill.arrow_thin_right_end; break;
        case DIR4__DOWN: texture = textures->skill.arrow_thin_down_end; break;
        case DIR4__LEFT: texture = textures->skill.arrow_thin_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_arrow_thin_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = 0;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thin_up_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thin_up_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thin_up_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thin_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thin_right_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thin_right_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thin_right_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thin_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thin_down_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thin_down_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thin_down_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thin_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thin_left_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thin_left_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thin_left_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thin_left_left; break;
                default: break;
            }
        }
        break;
        default: break;
    }

    return texture;
}

Texture* get_texture_arrow_thick_start(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.arrow_thick_up_start; break;
        case DIR4__RIGHT: texture = textures->skill.arrow_thick_right_start; break;
        case DIR4__DOWN: texture = textures->skill.arrow_thick_down_start; break;
        case DIR4__LEFT: texture = textures->skill.arrow_thick_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_arrow_thick_end(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->skill.arrow_thick_up_end; break;
        case DIR4__RIGHT: texture = textures->skill.arrow_thick_right_end; break;
        case DIR4__DOWN: texture = textures->skill.arrow_thick_down_end; break;
        case DIR4__LEFT: texture = textures->skill.arrow_thick_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_arrow_thick_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = 0;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thick_up_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thick_up_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thick_up_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thick_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thick_right_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thick_right_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thick_right_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thick_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thick_down_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thick_down_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thick_down_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thick_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->skill.arrow_thick_left_up; break;
                case DIR4__RIGHT: texture = textures->skill.arrow_thick_left_right; break;
                case DIR4__DOWN: texture = textures->skill.arrow_thick_left_down; break;
                case DIR4__LEFT: texture = textures->skill.arrow_thick_left_left; break;
                default: break;
            }
        }
        break;
        default: break;
    }

    return texture;
}
