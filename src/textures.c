#include "../inc/textures.h"
#include "../inc/item.h"

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
    // later
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

    object->turret_laser_grounded_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_grounded_1.png");
    object->turret_laser_grounded_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_grounded_2.png");
    object->turret_laser_grounded_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_grounded_outline_1.png");
    object->turret_laser_grounded_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_grounded_outline_2.png");

    object->turret_laser_standing_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_standing_1.png");
    object->turret_laser_standing_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_standing_2.png");
    object->turret_laser_standing_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_standing_outline_1.png");
    object->turret_laser_standing_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_standing_outline_2.png");

    object->turret_laser_undeployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_undeployed_1.png");
    object->turret_laser_undeployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_undeployed_2.png");
    object->turret_laser_undeployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_undeployed_outline_1.png");
    object->turret_laser_undeployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_undeployed_outline_2.png");

    object->turret_laser_deployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_deployed_1.png");
    object->turret_laser_deployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_deployed_2.png");
    object->turret_laser_deployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_laser_deployed_outline_1.png");
    object->turret_laser_deployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_laser_deployed_outline_2.png");

    object->turret_bomb_grounded_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_grounded_1.png");
    object->turret_bomb_grounded_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_grounded_2.png");
    object->turret_bomb_grounded_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_grounded_outline_1.png");
    object->turret_bomb_grounded_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_grounded_outline_2.png");

    object->turret_bomb_standing_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_standing_1.png");
    object->turret_bomb_standing_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_standing_2.png");
    object->turret_bomb_standing_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_standing_outline_1.png");
    object->turret_bomb_standing_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_standing_outline_2.png");

    object->turret_bomb_undeployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_undeployed_1.png");
    object->turret_bomb_undeployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_undeployed_2.png");
    object->turret_bomb_undeployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_undeployed_outline_1.png");
    object->turret_bomb_undeployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_undeployed_outline_2.png");

    object->turret_bomb_deployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_deployed_1.png");
    object->turret_bomb_deployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_deployed_2.png");
    object->turret_bomb_deployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_deployed_outline_1.png");
    object->turret_bomb_deployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_bomb_deployed_outline_2.png");

    object->turret_projectile_grounded_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_grounded_1.png");
    object->turret_projectile_grounded_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_grounded_2.png");
    object->turret_projectile_grounded_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_grounded_outline_1.png");
    object->turret_projectile_grounded_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_grounded_outline_2.png");

    object->turret_projectile_standing_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_standing_1.png");
    object->turret_projectile_standing_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_standing_2.png");
    object->turret_projectile_standing_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_standing_outline_1.png");
    object->turret_projectile_standing_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_standing_outline_2.png");

    object->turret_projectile_undeployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_undeployed_1.png");
    object->turret_projectile_undeployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_undeployed_2.png");
    object->turret_projectile_undeployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_undeployed_outline_1.png");
    object->turret_projectile_undeployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_undeployed_outline_2.png");

    object->turret_projectile_deployed_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_deployed_1.png");
    object->turret_projectile_deployed_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_deployed_2.png");
    object->turret_projectile_deployed_outline_1 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_deployed_outline_1.png");
    object->turret_projectile_deployed_outline_2 = load_texture_from_filepath(renderer, "./res/object/turret_projectile_deployed_outline_2.png");
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
    // later
}

void load_textures_skill (Renderer* renderer, Textures_Skill* skill)
{
    skill->throw_up = load_texture_from_filepath (renderer, "./res/skill/throw_up.png");
    skill->throw_right = load_texture_from_filepath (renderer, "./res/skill/throw_right.png");
    skill->throw_down = load_texture_from_filepath (renderer, "./res/skill/throw_down.png");
    skill->throw_left = load_texture_from_filepath (renderer, "./res/skill/throw_left.png");

    skill->lift_none = load_texture_from_filepath (renderer, "./res/skill/lift_none.png");
    skill->lift_up = load_texture_from_filepath (renderer, "./res/skill/lift_up.png");
    skill->lift_right = load_texture_from_filepath (renderer, "./res/skill/lift_right.png");
    skill->lift_down = load_texture_from_filepath (renderer, "./res/skill/lift_down.png");
    skill->lift_left = load_texture_from_filepath (renderer, "./res/skill/lift_left.png");

    skill->fall = load_texture_from_filepath (renderer, "./res/skill/fall.png");
    skill->drop = load_texture_from_filepath (renderer, "./res/skill/drop.png");
    skill->change = load_texture_from_filepath (renderer, "./res/skill/change.png");

    skill->floor_border_solid = load_texture_from_filepath (renderer, "./res/skill/floor_border_solid.png");
    skill->floor_border_dashed = load_texture_from_filepath (renderer, "./res/skill/floor_border_dashed.png");
    skill->floor_border_dotted = load_texture_from_filepath (renderer, "./res/skill/floor_border_dotted.png");
    skill->floor_danger = load_texture_from_filepath (renderer, "./res/skill/floor_danger.png");

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

    skill->immovable_effect = load_texture_from_filepath (renderer, "./res/skill/immovable_effect.png");
    skill->crash_effect = load_texture_from_filepath (renderer, "./res/skill/crash_effect.png");
    skill->blow_up_effect = load_texture_from_filepath (renderer, "./res/skill/blow_up_effect.png");
    skill->death_effect = load_texture_from_filepath (renderer, "./res/skill/death_effect.png");
    skill->break_effect = load_texture_from_filepath (renderer, "./res/skill/break_effect.png");
    skill->melt_effect = load_texture_from_filepath (renderer, "./res/skill/melt_effect.png");
    skill->shake_effect = load_texture_from_filepath (renderer, "./res/skill/shake_effect.png");

    skill->plus_1_cell = load_texture_from_filepath (renderer, "./res/skill/plus_1_cell.png");
    skill->plus_2_cell = load_texture_from_filepath (renderer, "./res/skill/plus_2_cell.png");
    skill->plus_3_cell = load_texture_from_filepath (renderer, "./res/skill/plus_3_cell.png");
    skill->minus_1_cell = load_texture_from_filepath (renderer, "./res/skill/minus_1_cell.png");
    skill->minus_2_cell = load_texture_from_filepath (renderer, "./res/skill/minus_2_cell.png");
    skill->minus_3_cell = load_texture_from_filepath (renderer, "./res/skill/minus_3_cell.png");
    skill->plus_1_dynamite = load_texture_from_filepath (renderer, "./res/skill/plus_1_dynamite.png");
    skill->plus_2_dynamite = load_texture_from_filepath (renderer, "./res/skill/plus_2_dynamite.png");
    skill->plus_3_dynamite = load_texture_from_filepath (renderer, "./res/skill/plus_3_dynamite.png");
    skill->minus_1_dynamite = load_texture_from_filepath (renderer, "./res/skill/minus_1_dynamite.png");
    skill->minus_2_dynamite = load_texture_from_filepath (renderer, "./res/skill/minus_2_dynamite.png");
    skill->minus_3_dynamite = load_texture_from_filepath (renderer, "./res/skill/minus_3_dynamite.png");
    skill->plus_1_gemstone = load_texture_from_filepath (renderer, "./res/skill/plus_1_gemstone.png");
    skill->plus_2_gemstone = load_texture_from_filepath (renderer, "./res/skill/plus_2_gemstone.png");
    skill->plus_3_gemstone = load_texture_from_filepath (renderer, "./res/skill/plus_3_gemstone.png");
    skill->minus_1_gemstone = load_texture_from_filepath (renderer, "./res/skill/minus_1_gemstone.png");
    skill->minus_2_gemstone = load_texture_from_filepath (renderer, "./res/skill/minus_2_gemstone.png");
    skill->minus_3_gemstone = load_texture_from_filepath (renderer, "./res/skill/minus_3_gemstone.png");
}
void destroy_textures_skill (Textures_Skill* skill)
{
    // later
}

void load_textures_animation (Renderer* renderer, Textures_Animation* animation)
{
    animation->blow_up_1 = load_texture_from_filepath (renderer, "./res/animation/blow_up_1.png");
    animation->blow_up_2 = load_texture_from_filepath (renderer, "./res/animation/blow_up_2.png");

    animation->death_1 = load_texture_from_filepath (renderer, "./res/animation/death_1.png");
    animation->death_2 = load_texture_from_filepath (renderer, "./res/animation/death_2.png");

    animation->drop_1 = load_texture_from_filepath (renderer, "./res/animation/drop_1.png");
    animation->drop_2 = load_texture_from_filepath (renderer, "./res/animation/drop_2.png");

    animation->piston_1 = load_texture_from_filepath (renderer, "./res/animation/piston_1.png");
    animation->piston_2 = load_texture_from_filepath (renderer, "./res/animation/piston_2.png");

    animation->stone_spikes_1 = load_texture_from_filepath (renderer, "./res/animation/stone_spikes_1.png");
    animation->stone_spikes_2 = load_texture_from_filepath (renderer, "./res/animation/stone_spikes_2.png");

    animation->metal_hatch_1 = load_texture_from_filepath (renderer, "./res/animation/metal_hatch_1.png");
    animation->metal_hatch_2 = load_texture_from_filepath (renderer, "./res/animation/metal_hatch_2.png");

    animation->hook_up_start = load_texture_from_filepath (renderer, "./res/animation/hook_up_start.png");
    animation->hook_up_end = load_texture_from_filepath (renderer, "./res/animation/hook_up_end.png");
    animation->hook_up_up = load_texture_from_filepath (renderer, "./res/animation/hook_up_up.png");
    animation->hook_up_right = load_texture_from_filepath (renderer, "./res/animation/hook_up_right.png");
    animation->hook_up_down = load_texture_from_filepath (renderer, "./res/animation/hook_up_down.png");
    animation->hook_up_left = load_texture_from_filepath (renderer, "./res/animation/hook_up_left.png");

    animation->hook_right_start = load_texture_from_filepath (renderer, "./res/animation/hook_right_start.png");
    animation->hook_right_end = load_texture_from_filepath (renderer, "./res/animation/hook_right_end.png");
    animation->hook_right_up = load_texture_from_filepath (renderer, "./res/animation/hook_right_up.png");
    animation->hook_right_right = load_texture_from_filepath (renderer, "./res/animation/hook_right_right.png");
    animation->hook_right_down = load_texture_from_filepath (renderer, "./res/animation/hook_right_down.png");
    animation->hook_right_left = load_texture_from_filepath (renderer, "./res/animation/hook_right_left.png");

    animation->hook_down_start = load_texture_from_filepath (renderer, "./res/animation/hook_down_start.png");
    animation->hook_down_end = load_texture_from_filepath (renderer, "./res/animation/hook_down_end.png");
    animation->hook_down_up = load_texture_from_filepath (renderer, "./res/animation/hook_down_up.png");
    animation->hook_down_right = load_texture_from_filepath (renderer, "./res/animation/hook_down_right.png");
    animation->hook_down_down = load_texture_from_filepath (renderer, "./res/animation/hook_down_down.png");
    animation->hook_down_left = load_texture_from_filepath (renderer, "./res/animation/hook_down_left.png");

    animation->hook_left_start = load_texture_from_filepath (renderer, "./res/animation/hook_left_start.png");
    animation->hook_left_end = load_texture_from_filepath (renderer, "./res/animation/hook_left_end.png");
    animation->hook_left_up = load_texture_from_filepath (renderer, "./res/animation/hook_left_up.png");
    animation->hook_left_right = load_texture_from_filepath (renderer, "./res/animation/hook_left_right.png");
    animation->hook_left_down = load_texture_from_filepath (renderer, "./res/animation/hook_left_down.png");
    animation->hook_left_left = load_texture_from_filepath (renderer, "./res/animation/hook_left_left.png");

    animation->laser_up = load_texture_from_filepath (renderer, "./res/animation/laser_up.png");
    animation->laser_right = load_texture_from_filepath (renderer, "./res/animation/laser_right.png");
    animation->laser_down = load_texture_from_filepath (renderer, "./res/animation/laser_down.png");
    animation->laser_left = load_texture_from_filepath (renderer, "./res/animation/laser_left.png");
    animation->laser_vertical = load_texture_from_filepath (renderer, "./res/animation/laser_vertical.png");
    animation->laser_horizontal = load_texture_from_filepath (renderer, "./res/animation/laser_horizontal.png");

    animation->cell = load_texture_from_filepath (renderer, "./res/animation/cell.png");
    animation->dynamite = load_texture_from_filepath (renderer, "./res/animation/dynamite.png");
    animation->gemstone = load_texture_from_filepath (renderer, "./res/animation/gemstone.png");
}

void destroy_textures_animation (Textures_Animation* animation)
{
    // later
}

void load_textures (Renderer* renderer, Textures* textures)
{
    load_textures_floor(renderer,&textures->floor);
    load_textures_object(renderer,&textures->object);
    load_textures_order_number(renderer,&textures->order_number);
    load_textures_skill(renderer,&textures->skill);
    load_textures_animation(renderer,&textures->animation);
}

void destroy_textures (Textures* textures)
{
    destroy_textures_floor (&textures->floor);
    destroy_textures_object (&textures->object);
    destroy_textures_order_number (&textures->order_number);
    destroy_textures_skill(&textures->skill);
    destroy_textures_animation(&textures->animation);
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

Texture* get_texture_item(Textures* textures, int item, int number)
{
    Texture* texture = 0;

    switch(item)
    {
        case ITEM__CELL:
        {
            switch(number)
            {
                case -3:texture = textures->skill.minus_3_cell;break;
                case -2:texture = textures->skill.minus_2_cell;break;
                case -1:texture = textures->skill.minus_1_cell;break;
                case 1:texture = textures->skill.plus_1_cell;break;
                case 2:texture = textures->skill.plus_2_cell;break;
                case 3:texture = textures->skill.plus_3_cell;break;
                default:break;
            }
        }
        break;
        case ITEM__DYNAMITE:
        {
            switch(number)
            {
                case -3:texture = textures->skill.minus_3_dynamite;break;
                case -2:texture = textures->skill.minus_2_dynamite;break;
                case -1:texture = textures->skill.minus_1_dynamite;break;
                case 1:texture = textures->skill.plus_1_dynamite;break;
                case 2:texture = textures->skill.plus_2_dynamite;break;
                case 3:texture = textures->skill.plus_3_dynamite;break;
                default:break;
            }
        }
        break;
        case ITEM__GEMSTONE:
        {
            switch(number)
            {
                case -3:texture = textures->skill.minus_3_gemstone;break;
                case -2:texture = textures->skill.minus_2_gemstone;break;
                case -1:texture = textures->skill.minus_1_gemstone;break;
                case 1:texture = textures->skill.plus_1_gemstone;break;
                case 2:texture = textures->skill.plus_2_gemstone;break;
                case 3:texture = textures->skill.plus_3_gemstone;break;
                default:break;
            }
        }
        break;
        default:
        break;
    }

    return texture;
}

Texture* get_texture_hook_start(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.hook_up_start; break;
        case DIR4__RIGHT: texture = textures->animation.hook_right_start; break;
        case DIR4__DOWN: texture = textures->animation.hook_down_start; break;
        case DIR4__LEFT: texture = textures->animation.hook_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_hook_end(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.hook_up_end; break;
        case DIR4__RIGHT: texture = textures->animation.hook_right_end; break;
        case DIR4__DOWN: texture = textures->animation.hook_down_end; break;
        case DIR4__LEFT: texture = textures->animation.hook_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_hook_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = 0;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.hook_up_up; break;
                case DIR4__RIGHT: texture = textures->animation.hook_up_right; break;
                case DIR4__DOWN: texture = textures->animation.hook_up_down; break;
                case DIR4__LEFT: texture = textures->animation.hook_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.hook_right_up; break;
                case DIR4__RIGHT: texture = textures->animation.hook_right_right; break;
                case DIR4__DOWN: texture = textures->animation.hook_right_down; break;
                case DIR4__LEFT: texture = textures->animation.hook_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.hook_down_up; break;
                case DIR4__RIGHT: texture = textures->animation.hook_down_right; break;
                case DIR4__DOWN: texture = textures->animation.hook_down_down; break;
                case DIR4__LEFT: texture = textures->animation.hook_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.hook_left_up; break;
                case DIR4__RIGHT: texture = textures->animation.hook_left_right; break;
                case DIR4__DOWN: texture = textures->animation.hook_left_down; break;
                case DIR4__LEFT: texture = textures->animation.hook_left_left; break;
                default: break;
            }
        }
        break;
        default: break;
    }

    return texture;
}

Texture* get_texture_laser(Textures* textures, int dir4)
{
    Texture* texture = 0;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.laser_up; break;
        case DIR4__RIGHT: texture = textures->animation.laser_right; break;
        case DIR4__DOWN: texture = textures->animation.laser_down; break;
        case DIR4__LEFT: texture = textures->animation.laser_left; break;
        default: break;
    }

    return texture;
}
