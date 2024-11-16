#include "../inc/textures.h"
#include "../inc/item.h"

void load_textures_floor(Renderer* renderer, Textures_Floor* floor)
{
    floor->highlight = load_texture_from_filepath(renderer, "./res/floor/highlight.png");

    floor->rock = load_texture_from_filepath(renderer, "./res/floor/rock.png");
    floor->rock_crack_water = load_texture_from_filepath(renderer, "./res/floor/rock_crack_water.png");
    floor->rock_crack_lava = load_texture_from_filepath(renderer, "./res/floor/rock_crack_lava.png");
    floor->rock_crack_pit = load_texture_from_filepath(renderer, "./res/floor/rock_crack_pit.png");

    floor->stone = load_texture_from_filepath(renderer, "./res/floor/stone.png");
    floor->stone_trap = load_texture_from_filepath(renderer, "./res/floor/stone_trap.png");

    floor->metal = load_texture_from_filepath(renderer, "./res/floor/metal.png");
    floor->metal_spikes_on = load_texture_from_filepath(renderer, "./res/floor/metal_spikes_on.png");
    floor->metal_spikes_off = load_texture_from_filepath(renderer, "./res/floor/metal_spikes_off.png");
    floor->metal_hatch_open_1 = load_texture_from_filepath(renderer, "./res/floor/metal_hatch_open_1.png");
    floor->metal_hatch_open_2 = load_texture_from_filepath(renderer, "./res/floor/metal_hatch_open_2.png");
    floor->metal_hatch_closed = load_texture_from_filepath(renderer, "./res/floor/metal_hatch_closed.png");
    floor->metal_cover_bottom = load_texture_from_filepath(renderer, "./res/floor/metal_cover_bottom.png");
    floor->metal_target_unchecked = load_texture_from_filepath(renderer, "./res/floor/metal_target_unchecked.png");
    floor->metal_target_checked = load_texture_from_filepath(renderer, "./res/floor/metal_target_checked.png");

    floor->metal_piston = load_texture_from_filepath(renderer, "./res/floor/metal_piston.png");
    floor->metal_piston_cell = load_texture_from_filepath(renderer, "./res/floor/metal_piston_cell.png");
    floor->metal_piston_dynamite = load_texture_from_filepath(renderer, "./res/floor/metal_piston_dynamite.png");
    floor->metal_piston_barrel = load_texture_from_filepath(renderer, "./res/floor/metal_piston_barrel.png");
    floor->metal_piston_mimic = load_texture_from_filepath(renderer, "./res/floor/metal_piston_mimic.png");
    floor->metal_no_piston = load_texture_from_filepath(renderer, "./res/floor/metal_no_piston.png");

    floor->gold = load_texture_from_filepath(renderer, "./res/floor/gold.png");

    floor->marble = load_texture_from_filepath(renderer, "./res/floor/marble.png");

    floor->obsidian = load_texture_from_filepath(renderer, "./res/floor/obsidian.png");

    floor->grass = load_texture_from_filepath(renderer, "./res/floor/grass.png");

    floor->sand = load_texture_from_filepath(renderer, "./res/floor/sand.png");

    floor->coins = load_texture_from_filepath(renderer, "./res/floor/coins.png");

    floor->pit = load_texture_from_filepath(renderer, "./res/floor/pit.png");
    floor->pit_column = load_texture_from_filepath(renderer, "./res/floor/pit_column.png");

    floor->water_1 = load_texture_from_filepath(renderer, "./res/floor/water_1.png");
    floor->water_2 = load_texture_from_filepath(renderer, "./res/floor/water_2.png");
    floor->water_lily_pod_1 = load_texture_from_filepath(renderer, "./res/floor/water_lily_pod_1.png");
    floor->water_lily_pod_2 = load_texture_from_filepath(renderer, "./res/floor/water_lily_pod_2.png");
    floor->water_stalactite_fallen_1 = load_texture_from_filepath(renderer, "./res/floor/water_stalactite_fallen_1.png");
    floor->water_stalactite_fallen_2 = load_texture_from_filepath(renderer, "./res/floor/water_stalactite_fallen_2.png");
    floor->water_column_1 = load_texture_from_filepath(renderer, "./res/floor/water_column_1.png");
    floor->water_column_2 = load_texture_from_filepath(renderer, "./res/floor/water_column_2.png");

    floor->lava_1 = load_texture_from_filepath(renderer, "./res/floor/lava_1.png");
    floor->lava_2 = load_texture_from_filepath(renderer, "./res/floor/lava_2.png");
    floor->lava_stalactite_fallen_1 = load_texture_from_filepath(renderer, "./res/floor/lava_stalactite_fallen_1.png");
    floor->lava_stalactite_fallen_2 = load_texture_from_filepath(renderer, "./res/floor/lava_stalactite_fallen_2.png");
    floor->lava_column_1 = load_texture_from_filepath(renderer, "./res/floor/lava_column_1.png");
    floor->lava_column_2 = load_texture_from_filepath(renderer, "./res/floor/lava_column_2.png");

    floor->ice = load_texture_from_filepath(renderer, "./res/floor/ice.png");
    floor->ice_crack_water = load_texture_from_filepath(renderer, "./res/floor/ice_crack_water.png");

    floor->obstacle = load_texture_from_filepath(renderer, "./res/floor/obstacle.png");

    floor->conv_belt_up = load_texture_from_filepath(renderer, "./res/floor/conv_belt_up.png");
    floor->conv_belt_right = load_texture_from_filepath(renderer, "./res/floor/conv_belt_right.png");
    floor->conv_belt_down = load_texture_from_filepath(renderer, "./res/floor/conv_belt_down.png");
    floor->conv_belt_left = load_texture_from_filepath(renderer, "./res/floor/conv_belt_left.png");

    floor->ext_bridge_source_on_horizontal = load_texture_from_filepath(renderer, "./res/floor/ext_bridge_source_on_horizontal.png");
    floor->ext_bridge_source_off_horizontal = load_texture_from_filepath(renderer, "./res/floor/ext_bridge_source_off_horizontal.png");
    floor->ext_bridge_part_horizontal = load_texture_from_filepath(renderer, "./res/floor/ext_bridge_part_horizontal.png");
    floor->ext_bridge_source_on_vertical = load_texture_from_filepath(renderer, "./res/floor/ext_bridge_source_on_vertical.png");
    floor->ext_bridge_source_off_vertical = load_texture_from_filepath(renderer, "./res/floor/ext_bridge_source_off_vertical.png");
    floor->ext_bridge_part_vertical = load_texture_from_filepath(renderer, "./res/floor/ext_bridge_part_vertical.png");

    floor->stone_stairs_below = load_texture_from_filepath(renderer, "./res/floor/stone_stairs_below.png");
    floor->stone_stairs_below_blocked = load_texture_from_filepath(renderer, "./res/floor/stone_stairs_below_blocked.png");
    floor->stone_stairs_above_unpowered = load_texture_from_filepath(renderer, "./res/floor/stone_stairs_above_unpowered.png");
    floor->stone_stairs_above_powered = load_texture_from_filepath(renderer, "./res/floor/stone_stairs_above_powered.png");
    floor->rock_stairs_below = load_texture_from_filepath(renderer, "./res/floor/rock_stairs_below.png");
    floor->metal_stairs_below_off = load_texture_from_filepath(renderer, "./res/floor/metal_stairs_below_off.png");
    floor->metal_stairs_above_off = load_texture_from_filepath(renderer, "./res/floor/metal_stairs_above_off.png");
    floor->metal_stairs_below_on = load_texture_from_filepath(renderer, "./res/floor/metal_stairs_below_on.png");
    floor->metal_stairs_below = load_texture_from_filepath(renderer, "./res/floor/metal_stairs_below.png");
}
void destroy_textures_floor(Textures_Floor* floor)
{
    // later
}

void load_textures_object(Renderer* renderer, Textures_Object* object)
{
    object->wall_rock = load_texture_from_filepath(renderer, "./res/object/wall_rock.png");
    object->wall_stone = load_texture_from_filepath(renderer, "./res/object/wall_stone.png");
    object->wall_metal = load_texture_from_filepath(renderer, "./res/object/wall_metal.png");
    object->wall_gold = load_texture_from_filepath(renderer, "./res/object/wall_gold.png");
    object->wall_marble = load_texture_from_filepath(renderer, "./res/object/wall_marble.png");
    object->wall_obsidian = load_texture_from_filepath(renderer, "./res/object/wall_obsidian.png");
    object->wall_outline = load_texture_from_filepath(renderer, "./res/object/wall_outline.png");

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
    object->exit_stone_powered_up = load_texture_from_filepath(renderer, "./res/object/exit_stone_powered_up.png");
    object->exit_stone_unpowered_up = load_texture_from_filepath(renderer, "./res/object/exit_stone_unpowered_up.png");
    object->exit_stone_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_up_outline.png");

    object->exit_stone_right = load_texture_from_filepath(renderer, "./res/object/exit_stone_right.png");
    object->exit_stone_blocked_right = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_right.png");
    object->exit_stone_powered_right = load_texture_from_filepath(renderer, "./res/object/exit_stone_powered_right.png");
    object->exit_stone_unpowered_right = load_texture_from_filepath(renderer, "./res/object/exit_stone_unpowered_right.png");
    object->exit_stone_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_right_outline.png");

    object->exit_stone_down = load_texture_from_filepath(renderer, "./res/object/exit_stone_down.png");
    object->exit_stone_blocked_down = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_down.png");
    object->exit_stone_powered_down = load_texture_from_filepath(renderer, "./res/object/exit_stone_powered_down.png");
    object->exit_stone_unpowered_down = load_texture_from_filepath(renderer, "./res/object/exit_stone_unpowered_down.png");
    object->exit_stone_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_down_outline.png");

    object->exit_stone_left = load_texture_from_filepath(renderer, "./res/object/exit_stone_left.png");
    object->exit_stone_blocked_left = load_texture_from_filepath(renderer, "./res/object/exit_stone_blocked_left.png");
    object->exit_stone_powered_left = load_texture_from_filepath(renderer, "./res/object/exit_stone_powered_left.png");
    object->exit_stone_unpowered_left = load_texture_from_filepath(renderer, "./res/object/exit_stone_unpowered_left.png");
    object->exit_stone_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_stone_left_outline.png");

    object->exit_metal_up = load_texture_from_filepath(renderer, "./res/object/exit_metal_up.png");
    object->exit_metal_blocked_up = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_up.png");
    object->exit_metal_on_up = load_texture_from_filepath(renderer, "./res/object/exit_metal_on_up.png");
    object->exit_metal_off_up = load_texture_from_filepath(renderer, "./res/object/exit_metal_off_up.png");
    object->exit_metal_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_up_outline.png");

    object->exit_metal_right = load_texture_from_filepath(renderer, "./res/object/exit_metal_right.png");
    object->exit_metal_blocked_right = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_right.png");
    object->exit_metal_on_right = load_texture_from_filepath(renderer, "./res/object/exit_metal_on_right.png");
    object->exit_metal_off_right = load_texture_from_filepath(renderer, "./res/object/exit_metal_off_right.png");
    object->exit_metal_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_right_outline.png");

    object->exit_metal_down = load_texture_from_filepath(renderer, "./res/object/exit_metal_down.png");
    object->exit_metal_blocked_down = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_down.png");
    object->exit_metal_on_down = load_texture_from_filepath(renderer, "./res/object/exit_metal_on_down.png");
    object->exit_metal_off_down = load_texture_from_filepath(renderer, "./res/object/exit_metal_off_down.png");
    object->exit_metal_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_down_outline.png");

    object->exit_metal_left = load_texture_from_filepath(renderer, "./res/object/exit_metal_left.png");
    object->exit_metal_blocked_left = load_texture_from_filepath(renderer, "./res/object/exit_metal_blocked_left.png");
    object->exit_metal_on_left = load_texture_from_filepath(renderer, "./res/object/exit_metal_on_left.png");
    object->exit_metal_off_left = load_texture_from_filepath(renderer, "./res/object/exit_metal_off_left.png");
    object->exit_metal_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_metal_left_outline.png");

    object->exit_gold_locked_up = load_texture_from_filepath(renderer, "./res/object/exit_gold_locked_up.png");
    object->exit_gold_unlocked_up = load_texture_from_filepath(renderer, "./res/object/exit_gold_unlocked_up.png");
    object->exit_gold_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_gold_up_outline.png");

    object->exit_gold_locked_right = load_texture_from_filepath(renderer, "./res/object/exit_gold_locked_right.png");
    object->exit_gold_unlocked_right = load_texture_from_filepath(renderer, "./res/object/exit_gold_unlocked_right.png");
    object->exit_gold_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_gold_right_outline.png");

    object->exit_gold_locked_down = load_texture_from_filepath(renderer, "./res/object/exit_gold_locked_down.png");
    object->exit_gold_unlocked_down = load_texture_from_filepath(renderer, "./res/object/exit_gold_unlocked_down.png");
    object->exit_gold_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_gold_down_outline.png");

    object->exit_gold_locked_left = load_texture_from_filepath(renderer, "./res/object/exit_gold_locked_left.png");
    object->exit_gold_unlocked_left = load_texture_from_filepath(renderer, "./res/object/exit_gold_unlocked_left.png");
    object->exit_gold_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_gold_left_outline.png");

    object->exit_marble_up = load_texture_from_filepath(renderer, "./res/object/exit_marble_up.png");
    object->exit_marble_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_marble_up_outline.png");

    object->exit_marble_right = load_texture_from_filepath(renderer, "./res/object/exit_marble_right.png");
    object->exit_marble_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_marble_right_outline.png");

    object->exit_marble_down = load_texture_from_filepath(renderer, "./res/object/exit_marble_down.png");
    object->exit_marble_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_marble_down_outline.png");

    object->exit_marble_left = load_texture_from_filepath(renderer, "./res/object/exit_marble_left.png");
    object->exit_marble_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_marble_left_outline.png");

    object->exit_obsidian_up = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_up.png");
    object->exit_obsidian_up_outline = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_up_outline.png");

    object->exit_obsidian_right = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_right.png");
    object->exit_obsidian_right_outline = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_right_outline.png");

    object->exit_obsidian_down = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_down.png");
    object->exit_obsidian_down_outline = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_down_outline.png");

    object->exit_obsidian_left = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_left.png");
    object->exit_obsidian_left_outline = load_texture_from_filepath(renderer, "./res/object/exit_obsidian_left_outline.png");

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

    object->sarcophagus = load_texture_from_filepath(renderer, "./res/object/sarcophagus.png");
    object->sarcophagus_outline = load_texture_from_filepath(renderer, "./res/object/sarcophagus_outline.png");

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

    object->column = load_texture_from_filepath(renderer, "./res/object/column.png");
    object->column_outline = load_texture_from_filepath(renderer, "./res/object/column_outline.png");

    object->spring = load_texture_from_filepath(renderer, "./res/object/spring.png");
    object->spring_outline = load_texture_from_filepath(renderer, "./res/object/spring_outline.png");

    object->piston = load_texture_from_filepath(renderer, "./res/object/piston.png");
    object->piston_outline = load_texture_from_filepath(renderer, "./res/object/piston_outline.png");

    object->piston_cell = load_texture_from_filepath(renderer, "./res/object/piston_cell.png");
    object->piston_cell_outline = load_texture_from_filepath(renderer, "./res/object/piston_cell_outline.png");

    object->piston_dynamite = load_texture_from_filepath(renderer, "./res/object/piston_dynamite.png");
    object->piston_dynamite_outline = load_texture_from_filepath(renderer, "./res/object/piston_dynamite_outline.png");

    object->piston_barrel = load_texture_from_filepath(renderer, "./res/object/piston_barrel.png");
    object->piston_barrel_outline = load_texture_from_filepath(renderer, "./res/object/piston_barrel_outline.png");

    object->obstacle = load_texture_from_filepath(renderer, "./res/object/obstacle.png");
    object->obstacle_outline = load_texture_from_filepath(renderer, "./res/object/obstacle_outline.png");

    object->ball = load_texture_from_filepath(renderer, "./res/object/ball.png");
    object->ball_outline = load_texture_from_filepath(renderer, "./res/object/ball_outline.png");

    object->ball_spikes = load_texture_from_filepath(renderer, "./res/object/ball_spikes.png");
    object->ball_spikes_outline = load_texture_from_filepath(renderer, "./res/object/ball_spikes_outline.png");

    object->throne = load_texture_from_filepath(renderer, "./res/object/throne.png");
    object->throne_outline = load_texture_from_filepath(renderer, "./res/object/throne_outline.png");

    object->sign_mole_warning = load_texture_from_filepath(renderer, "./res/object/sign_mole_warning.png");
    object->sign_mole_warning_outline = load_texture_from_filepath(renderer, "./res/object/sign_mole_warning_outline.png");

    object->golem_unpowered = load_texture_from_filepath(renderer, "./res/object/golem_unpowered.png");
    object->golem_unpowered_outline = load_texture_from_filepath(renderer, "./res/object/golem_unpowered_outline.png");

    object->golem_half_powered = load_texture_from_filepath(renderer, "./res/object/golem_half_powered.png");
    object->golem_half_powered_outline = load_texture_from_filepath(renderer, "./res/object/golem_half_powered_outline.png");

    object->golem_powered_1 = load_texture_from_filepath(renderer, "./res/object/golem_powered_1.png");
    object->golem_powered_2 = load_texture_from_filepath(renderer, "./res/object/golem_powered_2.png");
    object->golem_powered_outline_1 = load_texture_from_filepath(renderer, "./res/object/golem_powered_outline_1.png");
    object->golem_powered_outline_2 = load_texture_from_filepath(renderer, "./res/object/golem_powered_outline_2.png");

    object->hero_1 = load_texture_from_filepath(renderer, "./res/object/hero_1.png");
    object->hero_2 = load_texture_from_filepath(renderer, "./res/object/hero_2.png");
    object->hero_outline_1 = load_texture_from_filepath(renderer, "./res/object/hero_outline_1.png");
    object->hero_outline_2 = load_texture_from_filepath(renderer, "./res/object/hero_outline_2.png");

    object->hero_floating_1 = load_texture_from_filepath(renderer, "./res/object/hero_floating_1.png");
    object->hero_floating_2 = load_texture_from_filepath(renderer, "./res/object/hero_floating_2.png");
    object->hero_floating_outline_1 = load_texture_from_filepath(renderer, "./res/object/hero_floating_outline_1.png");
    object->hero_floating_outline_2 = load_texture_from_filepath(renderer, "./res/object/hero_floating_outline_2.png");

    object->hero_flying_1 = load_texture_from_filepath(renderer, "./res/object/hero_flying_1.png");
    object->hero_flying_2 = load_texture_from_filepath(renderer, "./res/object/hero_flying_2.png");
    object->hero_flying_outline_1 = load_texture_from_filepath(renderer, "./res/object/hero_flying_outline_1.png");
    object->hero_flying_outline_2 = load_texture_from_filepath(renderer, "./res/object/hero_flying_outline_2.png");

    object->minibot_ally_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_1.png");
    object->minibot_ally_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_2.png");
    object->minibot_ally_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_outline_1.png");
    object->minibot_ally_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_outline_2.png");

    object->minibot_ally_cell_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_cell_1.png");
    object->minibot_ally_cell_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_cell_2.png");
    object->minibot_ally_cell_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_cell_outline_1.png");
    object->minibot_ally_cell_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_cell_outline_2.png");

    object->minibot_ally_dynamite_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_dynamite_1.png");
    object->minibot_ally_dynamite_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_dynamite_2.png");
    object->minibot_ally_dynamite_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_dynamite_outline_1.png");
    object->minibot_ally_dynamite_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_dynamite_outline_2.png");

    object->minibot_ally_gemstone_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_gemstone_1.png");
    object->minibot_ally_gemstone_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_gemstone_2.png");
    object->minibot_ally_gemstone_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_gemstone_outline_1.png");
    object->minibot_ally_gemstone_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_ally_gemstone_outline_2.png");

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

    object->squid_1 = load_texture_from_filepath(renderer, "./res/object/squid_1.png");
    object->squid_2 = load_texture_from_filepath(renderer, "./res/object/squid_2.png");
    object->squid_outline_1 = load_texture_from_filepath(renderer, "./res/object/squid_outline_1.png");
    object->squid_outline_2 = load_texture_from_filepath(renderer, "./res/object/squid_outline_2.png");

    object->mole_1 = load_texture_from_filepath(renderer, "./res/object/mole_1.png");
    object->mole_2 = load_texture_from_filepath(renderer, "./res/object/mole_2.png");
    object->mole_outline_1 = load_texture_from_filepath(renderer, "./res/object/mole_outline_1.png");
    object->mole_outline_2 = load_texture_from_filepath(renderer, "./res/object/mole_outline_2.png");

    object->mimic_1 = load_texture_from_filepath(renderer, "./res/object/mimic_1.png");
    object->mimic_2 = load_texture_from_filepath(renderer, "./res/object/mimic_2.png");
    object->mimic_outline_1 = load_texture_from_filepath(renderer, "./res/object/mimic_outline_1.png");
    object->mimic_outline_2 = load_texture_from_filepath(renderer, "./res/object/mimic_outline_2.png");

    object->shark_1 = load_texture_from_filepath(renderer, "./res/object/shark_1.png");
    object->shark_2 = load_texture_from_filepath(renderer, "./res/object/shark_2.png");
    object->shark_outline_1 = load_texture_from_filepath(renderer, "./res/object/shark_outline_1.png");
    object->shark_outline_2 = load_texture_from_filepath(renderer, "./res/object/shark_outline_2.png");

    object->shark_fin_1 = load_texture_from_filepath(renderer, "./res/object/shark_fin_1.png");
    object->shark_fin_2 = load_texture_from_filepath(renderer, "./res/object/shark_fin_2.png");
    object->shark_fin_outline_1 = load_texture_from_filepath(renderer, "./res/object/shark_fin_outline_1.png");
    object->shark_fin_outline_2 = load_texture_from_filepath(renderer, "./res/object/shark_fin_outline_2.png");

    object->minibot_enemy_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_1.png");
    object->minibot_enemy_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_2.png");
    object->minibot_enemy_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_outline_1.png");
    object->minibot_enemy_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_outline_2.png");

    object->minibot_enemy_cell_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_cell_1.png");
    object->minibot_enemy_cell_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_cell_2.png");
    object->minibot_enemy_cell_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_cell_outline_1.png");
    object->minibot_enemy_cell_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_cell_outline_2.png");

    object->minibot_enemy_dynamite_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_dynamite_1.png");
    object->minibot_enemy_dynamite_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_dynamite_2.png");
    object->minibot_enemy_dynamite_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_dynamite_outline_1.png");
    object->minibot_enemy_dynamite_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_dynamite_outline_2.png");

    object->minibot_enemy_gemstone_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_gemstone_1.png");
    object->minibot_enemy_gemstone_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_gemstone_2.png");
    object->minibot_enemy_gemstone_outline_1 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_gemstone_outline_1.png");
    object->minibot_enemy_gemstone_outline_2 = load_texture_from_filepath(renderer, "./res/object/minibot_enemy_gemstone_outline_2.png");

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

    object->squirrel_exit_obsidian_down_1 = load_texture_from_filepath(renderer, "./res/object/squirrel_exit_obsidian_down_1.png");
    object->squirrel_exit_obsidian_down_2 = load_texture_from_filepath(renderer, "./res/object/squirrel_exit_obsidian_down_2.png");

    object->stairs_above_stone_powered = load_texture_from_filepath(renderer, "./res/object/stairs_above_stone_powered.png");
    object->stairs_above_stone_powered_outline = load_texture_from_filepath(renderer, "./res/object/stairs_above_stone_powered_outline.png");

    object->stairs_above_stone = load_texture_from_filepath(renderer, "./res/object/stairs_above_stone.png");
    object->stairs_above_stone_outline = load_texture_from_filepath(renderer, "./res/object/stairs_above_stone_outline.png");

    object->stairs_above_rock = load_texture_from_filepath(renderer, "./res/object/stairs_above_rock.png");
    object->stairs_above_rock_outline = load_texture_from_filepath(renderer, "./res/object/stairs_above_rock_outline.png");

    object->stairs_above_metal_on = load_texture_from_filepath(renderer, "./res/object/stairs_above_metal_on.png");
    object->stairs_above_metal_on_outline = load_texture_from_filepath(renderer, "./res/object/stairs_above_metal_on_outline.png");

    object->stairs_above_metal = load_texture_from_filepath(renderer, "./res/object/stairs_above_metal.png");
    object->stairs_above_metal_outline = load_texture_from_filepath(renderer, "./res/object/stairs_above_metal_outline.png");

    object->station_fist_hand = load_texture_from_filepath(renderer, "./res/object/station_fist_hand.png");
    object->station_hook_hand = load_texture_from_filepath(renderer, "./res/object/station_hook_hand.png");
    object->station_chain_hand = load_texture_from_filepath(renderer, "./res/object/station_chain_hand.png");
    object->station_scissor_hand = load_texture_from_filepath(renderer, "./res/object/station_scissor_hand.png");
    object->station_spring_leg = load_texture_from_filepath(renderer, "./res/object/station_spring_leg.png");
    object->station_strider_leg = load_texture_from_filepath(renderer, "./res/object/station_strider_leg.png");
    object->station_track_leg = load_texture_from_filepath(renderer, "./res/object/station_track_leg.png");
    object->station_boot_leg = load_texture_from_filepath(renderer, "./res/object/station_boot_leg.png");
    object->station_minibot_torso = load_texture_from_filepath(renderer, "./res/object/station_minibot_torso.png");
    object->station_wings_torso = load_texture_from_filepath(renderer, "./res/object/station_wings_torso.png");
    object->station_manipulation_head = load_texture_from_filepath(renderer, "./res/object/station_manipulation_head.png");
    object->station_teleportation_head = load_texture_from_filepath(renderer, "./res/object/station_teleportation_head.png");
    object->station_taken = load_texture_from_filepath(renderer, "./res/object/station_taken.png");
    object->station_outline = load_texture_from_filepath(renderer, "./res/object/station_outline.png");

    object->lever_metal_off = load_texture_from_filepath(renderer, "./res/object/lever_metal_off.png");
    object->lever_metal_off_outline = load_texture_from_filepath(renderer, "./res/object/lever_metal_off_outline.png");

    object->lever_metal_on = load_texture_from_filepath(renderer, "./res/object/lever_metal_on.png");
    object->lever_metal_on_outline = load_texture_from_filepath(renderer, "./res/object/lever_metal_on_outline.png");

    object->lever_stone_unpowered = load_texture_from_filepath(renderer, "./res/object/lever_stone_unpowered.png");
    object->lever_stone_unpowered_outline = load_texture_from_filepath(renderer, "./res/object/lever_stone_unpowered_outline.png");

    object->lever_stone_powered = load_texture_from_filepath(renderer, "./res/object/lever_stone_powered.png");
    object->lever_stone_powered_outline = load_texture_from_filepath(renderer, "./res/object/lever_stone_powered_outline.png");

    object->ext_wall_source_on_horizontal = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_on_horizontal.png");
    object->ext_wall_source_on_horizontal_outline = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_on_horizontal_outline.png");

    object->ext_wall_source_off_horizontal = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_off_horizontal.png");
    object->ext_wall_source_off_horizontal_outline = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_off_horizontal_outline.png");

    object->ext_wall_part_horizontal = load_texture_from_filepath(renderer, "./res/object/ext_wall_part_horizontal.png");
    object->ext_wall_part_horizontal_outline = load_texture_from_filepath(renderer, "./res/object/ext_wall_part_horizontal_outline.png");

    object->ext_wall_source_on_vertical = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_on_vertical.png");
    object->ext_wall_source_on_vertical_outline = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_on_vertical_outline.png");

    object->ext_wall_source_off_vertical = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_off_vertical.png");
    object->ext_wall_source_off_vertical_outline = load_texture_from_filepath(renderer, "./res/object/ext_wall_source_off_vertical_outline.png");

    object->ext_wall_part_vertical = load_texture_from_filepath(renderer, "./res/object/ext_wall_part_vertical.png");
    object->ext_wall_part_vertical_outline = load_texture_from_filepath(renderer, "./res/object/ext_wall_part_vertical_outline.png");

    object->harpoon_gun_up = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_up.png");
    object->harpoon_gun_up_outline = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_up_outline.png");

    object->harpoon_gun_right = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_right.png");
    object->harpoon_gun_right_outline = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_right_outline.png");

    object->harpoon_gun_down = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_down.png");
    object->harpoon_gun_down_outline = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_down_outline.png");

    object->harpoon_gun_left = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_left.png");
    object->harpoon_gun_left_outline = load_texture_from_filepath(renderer, "./res/object/harpoon_gun_left_outline.png");
}

void destroy_textures_object(Textures_Object* object)
{
    // later
}

void load_textures_order_number(Renderer* renderer, Textures_OrderNumber* order_number)
{
    order_number->num_1 = load_texture_from_filepath(renderer, "./res/order_number/num_1.png");
    order_number->num_2 = load_texture_from_filepath(renderer, "./res/order_number/num_2.png");
    order_number->num_3 = load_texture_from_filepath(renderer, "./res/order_number/num_3.png");
    order_number->num_4 = load_texture_from_filepath(renderer, "./res/order_number/num_4.png");
    order_number->num_5 = load_texture_from_filepath(renderer, "./res/order_number/num_5.png");
    order_number->num_6 = load_texture_from_filepath(renderer, "./res/order_number/num_6.png");
    order_number->num_7 = load_texture_from_filepath(renderer, "./res/order_number/num_7.png");
    order_number->num_8 = load_texture_from_filepath(renderer, "./res/order_number/num_8.png");
    order_number->num_9 = load_texture_from_filepath(renderer, "./res/order_number/num_9.png");
    order_number->num_0 = load_texture_from_filepath(renderer, "./res/order_number/num_0.png");
}
void destroy_textures_order_number(Textures_OrderNumber* order_number)
{
    // later
}

void load_textures_skill(Renderer* renderer, Textures_Skill* skill)
{
    skill->throw_up = load_texture_from_filepath(renderer, "./res/skill/throw_up.png");
    skill->throw_right = load_texture_from_filepath(renderer, "./res/skill/throw_right.png");
    skill->throw_down = load_texture_from_filepath(renderer, "./res/skill/throw_down.png");
    skill->throw_left = load_texture_from_filepath(renderer, "./res/skill/throw_left.png");

    skill->lift_none = load_texture_from_filepath(renderer, "./res/skill/lift_none.png");
    skill->lift_up = load_texture_from_filepath(renderer, "./res/skill/lift_up.png");
    skill->lift_right = load_texture_from_filepath(renderer, "./res/skill/lift_right.png");
    skill->lift_down = load_texture_from_filepath(renderer, "./res/skill/lift_down.png");
    skill->lift_left = load_texture_from_filepath(renderer, "./res/skill/lift_left.png");

    skill->fall = load_texture_from_filepath(renderer, "./res/skill/fall.png");
    skill->drop = load_texture_from_filepath(renderer, "./res/skill/drop.png");
    skill->change = load_texture_from_filepath(renderer, "./res/skill/change.png");

    skill->floor_border_solid = load_texture_from_filepath(renderer, "./res/skill/floor_border_solid.png");
    skill->floor_border_dashed = load_texture_from_filepath(renderer, "./res/skill/floor_border_dashed.png");
    skill->floor_border_dotted = load_texture_from_filepath(renderer, "./res/skill/floor_border_dotted.png");
    skill->floor_danger = load_texture_from_filepath(renderer, "./res/skill/floor_danger.png");

    skill->arrow_thin_up_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_up_start.png");
    skill->arrow_thin_up_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_up_end.png");
    skill->arrow_thin_up_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_up_up.png");
    skill->arrow_thin_up_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_up_right.png");
    skill->arrow_thin_up_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_up_down.png");
    skill->arrow_thin_up_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_up_left.png");

    skill->arrow_thin_right_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_right_start.png");
    skill->arrow_thin_right_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_right_end.png");
    skill->arrow_thin_right_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_right_up.png");
    skill->arrow_thin_right_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_right_right.png");
    skill->arrow_thin_right_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_right_down.png");
    skill->arrow_thin_right_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_right_left.png");

    skill->arrow_thin_down_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_down_start.png");
    skill->arrow_thin_down_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_down_end.png");
    skill->arrow_thin_down_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_down_up.png");
    skill->arrow_thin_down_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_down_right.png");
    skill->arrow_thin_down_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_down_down.png");
    skill->arrow_thin_down_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_down_left.png");

    skill->arrow_thin_left_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_left_start.png");
    skill->arrow_thin_left_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_left_end.png");
    skill->arrow_thin_left_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_left_up.png");
    skill->arrow_thin_left_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_left_right.png");
    skill->arrow_thin_left_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_left_down.png");
    skill->arrow_thin_left_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thin_left_left.png");

    skill->arrow_thick_up_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_up_start.png");
    skill->arrow_thick_up_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_up_end.png");
    skill->arrow_thick_up_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_up_up.png");
    skill->arrow_thick_up_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_up_right.png");
    skill->arrow_thick_up_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_up_down.png");
    skill->arrow_thick_up_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_up_left.png");

    skill->arrow_thick_right_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_right_start.png");
    skill->arrow_thick_right_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_right_end.png");
    skill->arrow_thick_right_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_right_up.png");
    skill->arrow_thick_right_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_right_right.png");
    skill->arrow_thick_right_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_right_down.png");
    skill->arrow_thick_right_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_right_left.png");

    skill->arrow_thick_down_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_down_start.png");
    skill->arrow_thick_down_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_down_end.png");
    skill->arrow_thick_down_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_down_up.png");
    skill->arrow_thick_down_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_down_right.png");
    skill->arrow_thick_down_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_down_down.png");
    skill->arrow_thick_down_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_down_left.png");

    skill->arrow_thick_left_start = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_left_start.png");
    skill->arrow_thick_left_end = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_left_end.png");
    skill->arrow_thick_left_up = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_left_up.png");
    skill->arrow_thick_left_right = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_left_right.png");
    skill->arrow_thick_left_down = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_left_down.png");
    skill->arrow_thick_left_left = load_texture_from_filepath(renderer, "./res/skill/arrow_thick_left_left.png");

    skill->dots_line_horizontal = load_texture_from_filepath(renderer, "./res/skill/dots_line_horizontal.png");
    skill->dots_line_vertical = load_texture_from_filepath(renderer, "./res/skill/dots_line_vertical.png");

    skill->dots_arch_horizontal_1_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_1_1.png");
    skill->dots_arch_horizontal_2_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_2_1.png");
    skill->dots_arch_horizontal_2_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_2_2.png");
    skill->dots_arch_horizontal_3_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_3_1.png");
    skill->dots_arch_horizontal_3_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_3_2.png");
    skill->dots_arch_horizontal_3_3 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_3_3.png");
    skill->dots_arch_horizontal_6_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_6_1.png");
    skill->dots_arch_horizontal_6_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_6_2.png");
    skill->dots_arch_horizontal_6_3 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_6_3.png");
    skill->dots_arch_horizontal_6_4 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_6_4.png");
    skill->dots_arch_horizontal_6_5 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_6_5.png");
    skill->dots_arch_horizontal_6_6 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_6_6.png");
    skill->dots_arch_horizontal_10_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_1.png");
    skill->dots_arch_horizontal_10_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_2.png");
    skill->dots_arch_horizontal_10_3 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_3.png");
    skill->dots_arch_horizontal_10_4 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_4.png");
    skill->dots_arch_horizontal_10_5 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_5.png");
    skill->dots_arch_horizontal_10_6 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_6.png");
    skill->dots_arch_horizontal_10_7 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_7.png");
    skill->dots_arch_horizontal_10_8 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_8.png");
    skill->dots_arch_horizontal_10_9 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_9.png");
    skill->dots_arch_horizontal_10_10 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_horizontal_10_10.png");
    skill->dots_arch_vertical_1_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_1_1.png");
    skill->dots_arch_vertical_2_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_2_1.png");
    skill->dots_arch_vertical_2_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_2_2.png");
    skill->dots_arch_vertical_3_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_3_1.png");
    skill->dots_arch_vertical_3_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_3_2.png");
    skill->dots_arch_vertical_3_3 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_3_3.png");
    skill->dots_arch_vertical_6_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_6_1.png");
    skill->dots_arch_vertical_6_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_6_2.png");
    skill->dots_arch_vertical_6_3 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_6_3.png");
    skill->dots_arch_vertical_6_4 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_6_4.png");
    skill->dots_arch_vertical_6_5 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_6_5.png");
    skill->dots_arch_vertical_6_6 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_6_6.png");
    skill->dots_arch_vertical_10_1 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_1.png");
    skill->dots_arch_vertical_10_2 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_2.png");
    skill->dots_arch_vertical_10_3 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_3.png");
    skill->dots_arch_vertical_10_4 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_4.png");
    skill->dots_arch_vertical_10_5 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_5.png");
    skill->dots_arch_vertical_10_6 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_6.png");
    skill->dots_arch_vertical_10_7 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_7.png");
    skill->dots_arch_vertical_10_8 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_8.png");
    skill->dots_arch_vertical_10_9 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_9.png");
    skill->dots_arch_vertical_10_10 = load_texture_from_filepath(renderer, "./res/skill/dots_arch_vertical_10_10.png");

    skill->attack_dir4_up = load_texture_from_filepath(renderer, "./res/skill/attack_dir4_up.png");
    skill->attack_dir4_right = load_texture_from_filepath(renderer, "./res/skill/attack_dir4_right.png");
    skill->attack_dir4_down = load_texture_from_filepath(renderer, "./res/skill/attack_dir4_down.png");
    skill->attack_dir4_left = load_texture_from_filepath(renderer, "./res/skill/attack_dir4_left.png");

    skill->immovable_effect = load_texture_from_filepath(renderer, "./res/skill/immovable_effect.png");
    skill->crash_effect = load_texture_from_filepath(renderer, "./res/skill/crash_effect.png");
    skill->blow_up_effect = load_texture_from_filepath(renderer, "./res/skill/blow_up_effect.png");
    skill->death_effect = load_texture_from_filepath(renderer, "./res/skill/death_effect.png");
    skill->break_effect = load_texture_from_filepath(renderer, "./res/skill/break_effect.png");
    skill->melt_effect = load_texture_from_filepath(renderer, "./res/skill/melt_effect.png");
    skill->shake_effect = load_texture_from_filepath(renderer, "./res/skill/shake_effect.png");
    skill->stomp_effect = load_texture_from_filepath(renderer, "./res/skill/stomp_effect.png");
    skill->use_effect = load_texture_from_filepath(renderer, "./res/skill/use_effect.png");
    skill->manipulation_effect = load_texture_from_filepath(renderer, "./res/skill/manipulation_effect.png");
    skill->teleportation_effect = load_texture_from_filepath(renderer, "./res/skill/teleportation_effect.png");

    skill->no_positions = load_texture_from_filepath(renderer, "./res/skill/no_positions.png");
    skill->no_attack = load_texture_from_filepath(renderer, "./res/skill/no_attack.png");

    skill->plus_1_cell = load_texture_from_filepath(renderer, "./res/skill/plus_1_cell.png");
    skill->plus_2_cell = load_texture_from_filepath(renderer, "./res/skill/plus_2_cell.png");
    skill->plus_3_cell = load_texture_from_filepath(renderer, "./res/skill/plus_3_cell.png");
    skill->minus_1_cell = load_texture_from_filepath(renderer, "./res/skill/minus_1_cell.png");
    skill->minus_2_cell = load_texture_from_filepath(renderer, "./res/skill/minus_2_cell.png");
    skill->minus_3_cell = load_texture_from_filepath(renderer, "./res/skill/minus_3_cell.png");
    skill->plus_1_dynamite = load_texture_from_filepath(renderer, "./res/skill/plus_1_dynamite.png");
    skill->plus_2_dynamite = load_texture_from_filepath(renderer, "./res/skill/plus_2_dynamite.png");
    skill->plus_3_dynamite = load_texture_from_filepath(renderer, "./res/skill/plus_3_dynamite.png");
    skill->minus_1_dynamite = load_texture_from_filepath(renderer, "./res/skill/minus_1_dynamite.png");
    skill->minus_2_dynamite = load_texture_from_filepath(renderer, "./res/skill/minus_2_dynamite.png");
    skill->minus_3_dynamite = load_texture_from_filepath(renderer, "./res/skill/minus_3_dynamite.png");
    skill->plus_1_gemstone = load_texture_from_filepath(renderer, "./res/skill/plus_1_gemstone.png");
    skill->plus_2_gemstone = load_texture_from_filepath(renderer, "./res/skill/plus_2_gemstone.png");
    skill->plus_3_gemstone = load_texture_from_filepath(renderer, "./res/skill/plus_3_gemstone.png");
    skill->minus_1_gemstone = load_texture_from_filepath(renderer, "./res/skill/minus_1_gemstone.png");
    skill->minus_2_gemstone = load_texture_from_filepath(renderer, "./res/skill/minus_2_gemstone.png");
    skill->minus_3_gemstone = load_texture_from_filepath(renderer, "./res/skill/minus_3_gemstone.png");

    skill->floor_environment_falling_stalactite = load_texture_from_filepath(renderer, "./res/skill/floor_environment_falling_stalactite.png");
    skill->floor_environment_emerge_water = load_texture_from_filepath(renderer, "./res/skill/floor_environment_emerge_water.png");
    skill->floor_environment_emerge_pit = load_texture_from_filepath(renderer, "./res/skill/floor_environment_emerge_pit.png");
    skill->floor_environment_emerge_burrow = load_texture_from_filepath(renderer, "./res/skill/floor_environment_emerge_burrow.png");
    skill->environment_emerge_pipe = load_texture_from_filepath(renderer, "./res/skill/environment_emerge_pipe.png");
    skill->floor_environment_collapse_burrow = load_texture_from_filepath(renderer, "./res/skill/floor_environment_collapse_burrow.png");
}

void destroy_textures_skill(Textures_Skill* skill)
{
    // later
}

void load_textures_animation(Renderer* renderer, Textures_Animation* animation)
{
    animation->blow_up_1 = load_texture_from_filepath(renderer, "./res/animation/blow_up_1.png");
    animation->blow_up_2 = load_texture_from_filepath(renderer, "./res/animation/blow_up_2.png");

    animation->death_1 = load_texture_from_filepath(renderer, "./res/animation/death_1.png");
    animation->death_2 = load_texture_from_filepath(renderer, "./res/animation/death_2.png");

    animation->drop_1 = load_texture_from_filepath(renderer, "./res/animation/drop_1.png");
    animation->drop_2 = load_texture_from_filepath(renderer, "./res/animation/drop_2.png");

    animation->hook_up_start = load_texture_from_filepath(renderer, "./res/animation/hook_up_start.png");
    animation->hook_up_end = load_texture_from_filepath(renderer, "./res/animation/hook_up_end.png");
    animation->hook_up_up = load_texture_from_filepath(renderer, "./res/animation/hook_up_up.png");
    animation->hook_up_right = load_texture_from_filepath(renderer, "./res/animation/hook_up_right.png");
    animation->hook_up_down = load_texture_from_filepath(renderer, "./res/animation/hook_up_down.png");
    animation->hook_up_left = load_texture_from_filepath(renderer, "./res/animation/hook_up_left.png");

    animation->hook_right_start = load_texture_from_filepath(renderer, "./res/animation/hook_right_start.png");
    animation->hook_right_end = load_texture_from_filepath(renderer, "./res/animation/hook_right_end.png");
    animation->hook_right_up = load_texture_from_filepath(renderer, "./res/animation/hook_right_up.png");
    animation->hook_right_right = load_texture_from_filepath(renderer, "./res/animation/hook_right_right.png");
    animation->hook_right_down = load_texture_from_filepath(renderer, "./res/animation/hook_right_down.png");
    animation->hook_right_left = load_texture_from_filepath(renderer, "./res/animation/hook_right_left.png");

    animation->hook_down_start = load_texture_from_filepath(renderer, "./res/animation/hook_down_start.png");
    animation->hook_down_end = load_texture_from_filepath(renderer, "./res/animation/hook_down_end.png");
    animation->hook_down_up = load_texture_from_filepath(renderer, "./res/animation/hook_down_up.png");
    animation->hook_down_right = load_texture_from_filepath(renderer, "./res/animation/hook_down_right.png");
    animation->hook_down_down = load_texture_from_filepath(renderer, "./res/animation/hook_down_down.png");
    animation->hook_down_left = load_texture_from_filepath(renderer, "./res/animation/hook_down_left.png");

    animation->hook_left_start = load_texture_from_filepath(renderer, "./res/animation/hook_left_start.png");
    animation->hook_left_end = load_texture_from_filepath(renderer, "./res/animation/hook_left_end.png");
    animation->hook_left_up = load_texture_from_filepath(renderer, "./res/animation/hook_left_up.png");
    animation->hook_left_right = load_texture_from_filepath(renderer, "./res/animation/hook_left_right.png");
    animation->hook_left_down = load_texture_from_filepath(renderer, "./res/animation/hook_left_down.png");
    animation->hook_left_left = load_texture_from_filepath(renderer, "./res/animation/hook_left_left.png");

    animation->spiderweb_up_start = load_texture_from_filepath(renderer, "./res/animation/spiderweb_up_start.png");
    animation->spiderweb_up_end = load_texture_from_filepath(renderer, "./res/animation/spiderweb_up_end.png");
    animation->spiderweb_up_up = load_texture_from_filepath(renderer, "./res/animation/spiderweb_up_up.png");
    animation->spiderweb_up_right = load_texture_from_filepath(renderer, "./res/animation/spiderweb_up_right.png");
    animation->spiderweb_up_down = load_texture_from_filepath(renderer, "./res/animation/spiderweb_up_down.png");
    animation->spiderweb_up_left = load_texture_from_filepath(renderer, "./res/animation/spiderweb_up_left.png");

    animation->spiderweb_right_start = load_texture_from_filepath(renderer, "./res/animation/spiderweb_right_start.png");
    animation->spiderweb_right_end = load_texture_from_filepath(renderer, "./res/animation/spiderweb_right_end.png");
    animation->spiderweb_right_up = load_texture_from_filepath(renderer, "./res/animation/spiderweb_right_up.png");
    animation->spiderweb_right_right = load_texture_from_filepath(renderer, "./res/animation/spiderweb_right_right.png");
    animation->spiderweb_right_down = load_texture_from_filepath(renderer, "./res/animation/spiderweb_right_down.png");
    animation->spiderweb_right_left = load_texture_from_filepath(renderer, "./res/animation/spiderweb_right_left.png");

    animation->spiderweb_down_start = load_texture_from_filepath(renderer, "./res/animation/spiderweb_down_start.png");
    animation->spiderweb_down_end = load_texture_from_filepath(renderer, "./res/animation/spiderweb_down_end.png");
    animation->spiderweb_down_up = load_texture_from_filepath(renderer, "./res/animation/spiderweb_down_up.png");
    animation->spiderweb_down_right = load_texture_from_filepath(renderer, "./res/animation/spiderweb_down_right.png");
    animation->spiderweb_down_down = load_texture_from_filepath(renderer, "./res/animation/spiderweb_down_down.png");
    animation->spiderweb_down_left = load_texture_from_filepath(renderer, "./res/animation/spiderweb_down_left.png");

    animation->spiderweb_left_start = load_texture_from_filepath(renderer, "./res/animation/spiderweb_left_start.png");
    animation->spiderweb_left_end = load_texture_from_filepath(renderer, "./res/animation/spiderweb_left_end.png");
    animation->spiderweb_left_up = load_texture_from_filepath(renderer, "./res/animation/spiderweb_left_up.png");
    animation->spiderweb_left_right = load_texture_from_filepath(renderer, "./res/animation/spiderweb_left_right.png");
    animation->spiderweb_left_down = load_texture_from_filepath(renderer, "./res/animation/spiderweb_left_down.png");
    animation->spiderweb_left_left = load_texture_from_filepath(renderer, "./res/animation/spiderweb_left_left.png");

    animation->tentacle_up_start = load_texture_from_filepath(renderer, "./res/animation/tentacle_up_start.png");
    animation->tentacle_up_end = load_texture_from_filepath(renderer, "./res/animation/tentacle_up_end.png");
    animation->tentacle_up_up = load_texture_from_filepath(renderer, "./res/animation/tentacle_up_up.png");
    animation->tentacle_up_right = load_texture_from_filepath(renderer, "./res/animation/tentacle_up_right.png");
    animation->tentacle_up_down = load_texture_from_filepath(renderer, "./res/animation/tentacle_up_down.png");
    animation->tentacle_up_left = load_texture_from_filepath(renderer, "./res/animation/tentacle_up_left.png");

    animation->tentacle_right_start = load_texture_from_filepath(renderer, "./res/animation/tentacle_right_start.png");
    animation->tentacle_right_end = load_texture_from_filepath(renderer, "./res/animation/tentacle_right_end.png");
    animation->tentacle_right_up = load_texture_from_filepath(renderer, "./res/animation/tentacle_right_up.png");
    animation->tentacle_right_right = load_texture_from_filepath(renderer, "./res/animation/tentacle_right_right.png");
    animation->tentacle_right_down = load_texture_from_filepath(renderer, "./res/animation/tentacle_right_down.png");
    animation->tentacle_right_left = load_texture_from_filepath(renderer, "./res/animation/tentacle_right_left.png");

    animation->tentacle_down_start = load_texture_from_filepath(renderer, "./res/animation/tentacle_down_start.png");
    animation->tentacle_down_end = load_texture_from_filepath(renderer, "./res/animation/tentacle_down_end.png");
    animation->tentacle_down_up = load_texture_from_filepath(renderer, "./res/animation/tentacle_down_up.png");
    animation->tentacle_down_right = load_texture_from_filepath(renderer, "./res/animation/tentacle_down_right.png");
    animation->tentacle_down_down = load_texture_from_filepath(renderer, "./res/animation/tentacle_down_down.png");
    animation->tentacle_down_left = load_texture_from_filepath(renderer, "./res/animation/tentacle_down_left.png");

    animation->tentacle_left_start = load_texture_from_filepath(renderer, "./res/animation/tentacle_left_start.png");
    animation->tentacle_left_end = load_texture_from_filepath(renderer, "./res/animation/tentacle_left_end.png");
    animation->tentacle_left_up = load_texture_from_filepath(renderer, "./res/animation/tentacle_left_up.png");
    animation->tentacle_left_right = load_texture_from_filepath(renderer, "./res/animation/tentacle_left_right.png");
    animation->tentacle_left_down = load_texture_from_filepath(renderer, "./res/animation/tentacle_left_down.png");
    animation->tentacle_left_left = load_texture_from_filepath(renderer, "./res/animation/tentacle_left_left.png");

    animation->tongue_up_start = load_texture_from_filepath(renderer, "./res/animation/tongue_up_start.png");
    animation->tongue_up_end = load_texture_from_filepath(renderer, "./res/animation/tongue_up_end.png");
    animation->tongue_up_up = load_texture_from_filepath(renderer, "./res/animation/tongue_up_up.png");
    animation->tongue_up_right = load_texture_from_filepath(renderer, "./res/animation/tongue_up_right.png");
    animation->tongue_up_down = load_texture_from_filepath(renderer, "./res/animation/tongue_up_down.png");
    animation->tongue_up_left = load_texture_from_filepath(renderer, "./res/animation/tongue_up_left.png");

    animation->tongue_right_start = load_texture_from_filepath(renderer, "./res/animation/tongue_right_start.png");
    animation->tongue_right_end = load_texture_from_filepath(renderer, "./res/animation/tongue_right_end.png");
    animation->tongue_right_up = load_texture_from_filepath(renderer, "./res/animation/tongue_right_up.png");
    animation->tongue_right_right = load_texture_from_filepath(renderer, "./res/animation/tongue_right_right.png");
    animation->tongue_right_down = load_texture_from_filepath(renderer, "./res/animation/tongue_right_down.png");
    animation->tongue_right_left = load_texture_from_filepath(renderer, "./res/animation/tongue_right_left.png");

    animation->tongue_down_start = load_texture_from_filepath(renderer, "./res/animation/tongue_down_start.png");
    animation->tongue_down_end = load_texture_from_filepath(renderer, "./res/animation/tongue_down_end.png");
    animation->tongue_down_up = load_texture_from_filepath(renderer, "./res/animation/tongue_down_up.png");
    animation->tongue_down_right = load_texture_from_filepath(renderer, "./res/animation/tongue_down_right.png");
    animation->tongue_down_down = load_texture_from_filepath(renderer, "./res/animation/tongue_down_down.png");
    animation->tongue_down_left = load_texture_from_filepath(renderer, "./res/animation/tongue_down_left.png");

    animation->tongue_left_start = load_texture_from_filepath(renderer, "./res/animation/tongue_left_start.png");
    animation->tongue_left_end = load_texture_from_filepath(renderer, "./res/animation/tongue_left_end.png");
    animation->tongue_left_up = load_texture_from_filepath(renderer, "./res/animation/tongue_left_up.png");
    animation->tongue_left_right = load_texture_from_filepath(renderer, "./res/animation/tongue_left_right.png");
    animation->tongue_left_down = load_texture_from_filepath(renderer, "./res/animation/tongue_left_down.png");
    animation->tongue_left_left = load_texture_from_filepath(renderer, "./res/animation/tongue_left_left.png");

    animation->scissor_up_start = load_texture_from_filepath(renderer, "./res/animation/scissor_up_start.png");
    animation->scissor_up_end = load_texture_from_filepath(renderer, "./res/animation/scissor_up_end.png");
    animation->scissor_up_up = load_texture_from_filepath(renderer, "./res/animation/scissor_up_up.png");
    animation->scissor_up_right = load_texture_from_filepath(renderer, "./res/animation/scissor_up_right.png");
    animation->scissor_up_down = load_texture_from_filepath(renderer, "./res/animation/scissor_up_down.png");
    animation->scissor_up_left = load_texture_from_filepath(renderer, "./res/animation/scissor_up_left.png");

    animation->scissor_right_start = load_texture_from_filepath(renderer, "./res/animation/scissor_right_start.png");
    animation->scissor_right_end = load_texture_from_filepath(renderer, "./res/animation/scissor_right_end.png");
    animation->scissor_right_up = load_texture_from_filepath(renderer, "./res/animation/scissor_right_up.png");
    animation->scissor_right_right = load_texture_from_filepath(renderer, "./res/animation/scissor_right_right.png");
    animation->scissor_right_down = load_texture_from_filepath(renderer, "./res/animation/scissor_right_down.png");
    animation->scissor_right_left = load_texture_from_filepath(renderer, "./res/animation/scissor_right_left.png");

    animation->scissor_down_start = load_texture_from_filepath(renderer, "./res/animation/scissor_down_start.png");
    animation->scissor_down_end = load_texture_from_filepath(renderer, "./res/animation/scissor_down_end.png");
    animation->scissor_down_up = load_texture_from_filepath(renderer, "./res/animation/scissor_down_up.png");
    animation->scissor_down_right = load_texture_from_filepath(renderer, "./res/animation/scissor_down_right.png");
    animation->scissor_down_down = load_texture_from_filepath(renderer, "./res/animation/scissor_down_down.png");
    animation->scissor_down_left = load_texture_from_filepath(renderer, "./res/animation/scissor_down_left.png");

    animation->scissor_left_start = load_texture_from_filepath(renderer, "./res/animation/scissor_left_start.png");
    animation->scissor_left_end = load_texture_from_filepath(renderer, "./res/animation/scissor_left_end.png");
    animation->scissor_left_up = load_texture_from_filepath(renderer, "./res/animation/scissor_left_up.png");
    animation->scissor_left_right = load_texture_from_filepath(renderer, "./res/animation/scissor_left_right.png");
    animation->scissor_left_down = load_texture_from_filepath(renderer, "./res/animation/scissor_left_down.png");
    animation->scissor_left_left = load_texture_from_filepath(renderer, "./res/animation/scissor_left_left.png");

    animation->laser_up = load_texture_from_filepath(renderer, "./res/animation/laser_up.png");
    animation->laser_right = load_texture_from_filepath(renderer, "./res/animation/laser_right.png");
    animation->laser_down = load_texture_from_filepath(renderer, "./res/animation/laser_down.png");
    animation->laser_left = load_texture_from_filepath(renderer, "./res/animation/laser_left.png");
    animation->laser_vertical = load_texture_from_filepath(renderer, "./res/animation/laser_vertical.png");
    animation->laser_horizontal = load_texture_from_filepath(renderer, "./res/animation/laser_horizontal.png");

    animation->cell = load_texture_from_filepath(renderer, "./res/animation/cell.png");
    animation->dynamite = load_texture_from_filepath(renderer, "./res/animation/dynamite.png");
    animation->gemstone = load_texture_from_filepath(renderer, "./res/animation/gemstone.png");
    animation->minibot = load_texture_from_filepath(renderer, "./res/animation/minibot.png");
    animation->minibot_enemy = load_texture_from_filepath(renderer, "./res/animation/minibot_enemy.png");
    animation->fly_projectile = load_texture_from_filepath(renderer, "./res/animation/fly_projectile.png");
    animation->squirrel_projectile = load_texture_from_filepath(renderer, "./res/animation/squirrel_projectile.png");
}

void destroy_textures_animation(Textures_Animation* animation)
{
    // later
}

void load_textures_hud(Renderer* renderer, Textures_Hud* hud)
{
    hud->no_augmentation = load_texture_from_filepath(renderer, "./res/hud/no_augmentation.png");
    hud->fist_hand = load_texture_from_filepath(renderer, "./res/hud/fist_hand.png");
    hud->hook_hand = load_texture_from_filepath(renderer, "./res/hud/hook_hand.png");
    hud->chain_hand = load_texture_from_filepath(renderer, "./res/hud/chain_hand.png");
    hud->scissor_hand = load_texture_from_filepath(renderer, "./res/hud/scissor_hand.png");
    hud->spring_leg = load_texture_from_filepath(renderer, "./res/hud/spring_leg.png");
    hud->strider_leg = load_texture_from_filepath(renderer, "./res/hud/strider_leg.png");
    hud->track_leg = load_texture_from_filepath(renderer, "./res/hud/track_leg.png");
    hud->boot_leg = load_texture_from_filepath(renderer, "./res/hud/boot_leg.png");
    hud->minibot_torso = load_texture_from_filepath(renderer, "./res/hud/minibot_torso.png");
    hud->wings_torso = load_texture_from_filepath(renderer, "./res/hud/wings_torso.png");
    hud->manipulation_head = load_texture_from_filepath(renderer, "./res/hud/manipulation_head.png");
    hud->teleportation_head = load_texture_from_filepath(renderer, "./res/hud/teleportation_head.png");

    hud->use = load_texture_from_filepath(renderer, "./res/hud/use.png");
    hud->manipulation = load_texture_from_filepath(renderer, "./res/hud/manipulation.png");
    hud->teleportation = load_texture_from_filepath(renderer, "./res/hud/teleportation.png");
    hud->move = load_texture_from_filepath(renderer, "./res/hud/move.png");
    hud->pick_item = load_texture_from_filepath(renderer, "./res/hud/pick_item.png");
    hud->put_item_cell = load_texture_from_filepath(renderer, "./res/hud/put_item_cell.png");
    hud->put_item_dynamite = load_texture_from_filepath(renderer, "./res/hud/put_item_dynamite.png");
    hud->put_item_gemstone = load_texture_from_filepath(renderer, "./res/hud/put_item_gemstone.png");
    hud->throw_item_cell = load_texture_from_filepath(renderer, "./res/hud/throw_item_cell.png");
    hud->throw_item_dynamite = load_texture_from_filepath(renderer, "./res/hud/throw_item_dynamite.png");
    hud->throw_item_gemstone = load_texture_from_filepath(renderer, "./res/hud/throw_item_gemstone.png");
    hud->shoot_projectile = load_texture_from_filepath(renderer, "./res/hud/shoot_projectile.png");
    hud->push = load_texture_from_filepath(renderer, "./res/hud/push.png");
    hud->throww = load_texture_from_filepath(renderer, "./res/hud/throw.png");
    hud->pull = load_texture_from_filepath(renderer, "./res/hud/pull.png");
    hud->drag = load_texture_from_filepath(renderer, "./res/hud/drag.png");
    hud->jump = load_texture_from_filepath(renderer, "./res/hud/jump.png");
    hud->charge = load_texture_from_filepath(renderer, "./res/hud/charge.png");
    hud->stomp = load_texture_from_filepath(renderer, "./res/hud/stomp.png");
    hud->drag_and_throw = load_texture_from_filepath(renderer, "./res/hud/drag_and_throw.png");
    hud->charge_and_push = load_texture_from_filepath(renderer, "./res/hud/charge_and_push.png");
    hud->charge_and_throw = load_texture_from_filepath(renderer, "./res/hud/charge_and_throw.png");
    hud->charge_and_jump = load_texture_from_filepath(renderer, "./res/hud/charge_and_jump.png");
    hud->jump_and_carry = load_texture_from_filepath(renderer, "./res/hud/jump_and_carry.png");
    hud->jump_and_stomp = load_texture_from_filepath(renderer, "./res/hud/jump_and_stomp.png");
    hud->launch_minibot = load_texture_from_filepath(renderer, "./res/hud/launch_minibot.png");
    hud->minibot_merge = load_texture_from_filepath(renderer, "./res/hud/minibot_merge.png");
    hud->turret_laser = load_texture_from_filepath(renderer, "./res/hud/turret_laser.png");
    hud->turret_bomb = load_texture_from_filepath(renderer, "./res/hud/turret_bomb.png");
    hud->turret_projectile = load_texture_from_filepath(renderer, "./res/hud/turret_projectile.png");
    hud->kill_around = load_texture_from_filepath(renderer, "./res/hud/kill_around.png");

    hud->hero = load_texture_from_filepath(renderer, "./res/hud/hero.png");
    hud->golem = load_texture_from_filepath(renderer, "./res/hud/golem.png");
    hud->goat = load_texture_from_filepath(renderer, "./res/hud/goat.png");
    hud->spider = load_texture_from_filepath(renderer, "./res/hud/spider.png");
    hud->bull = load_texture_from_filepath(renderer, "./res/hud/bull.png");
    hud->fly = load_texture_from_filepath(renderer, "./res/hud/fly.png");
    hud->chameleon = load_texture_from_filepath(renderer, "./res/hud/chameleon.png");
    hud->squid = load_texture_from_filepath(renderer, "./res/hud/squid.png");
    hud->mole = load_texture_from_filepath(renderer, "./res/hud/mole.png");
    hud->mimic = load_texture_from_filepath(renderer, "./res/hud/mimic.png");
    hud->shark = load_texture_from_filepath(renderer, "./res/hud/shark.png");
    hud->shark_fin = load_texture_from_filepath(renderer, "./res/hud/shark_fin.png");
    hud->tturret_laser = load_texture_from_filepath(renderer, "./res/hud/tturret_laser.png");
    hud->tturret_bomb = load_texture_from_filepath(renderer, "./res/hud/tturret_bomb.png");
    hud->tturret_projectile = load_texture_from_filepath(renderer, "./res/hud/tturret_projectile.png");
    hud->squirrel = load_texture_from_filepath(renderer, "./res/hud/squirrel.png");
    hud->minibot_ally = load_texture_from_filepath(renderer, "./res/hud/minibot_ally.png");
    hud->minibot_enemy = load_texture_from_filepath(renderer, "./res/hud/minibot_enemy.png");
    hud->environment_falling_stalactite = load_texture_from_filepath(renderer, "./res/hud/environment_falling_stalactite.png");
    hud->environment_emerge_water = load_texture_from_filepath(renderer, "./res/hud/environment_emerge_water.png");
    hud->environment_emerge_pit = load_texture_from_filepath(renderer, "./res/hud/environment_emerge_pit.png");
    hud->environment_emerge_burrow = load_texture_from_filepath(renderer, "./res/hud/environment_emerge_burrow.png");
    hud->environment_emerge_pipe = load_texture_from_filepath(renderer, "./res/hud/environment_emerge_pipe.png");
    hud->environment_collapse_burrow = load_texture_from_filepath(renderer, "./res/hud/environment_collapse_burrow.png");
    hud->environment_conv_belt = load_texture_from_filepath(renderer, "./res/hud/environment_conv_belt.png");

    hud->status_fragile = load_texture_from_filepath(renderer, "./res/hud/status_fragile.png");
    hud->status_high = load_texture_from_filepath(renderer, "./res/hud/status_high.png");
    hud->status_floating = load_texture_from_filepath(renderer, "./res/hud/status_floating.png");
    hud->status_flying = load_texture_from_filepath(renderer, "./res/hud/status_flying.png");
    hud->status_wall = load_texture_from_filepath(renderer, "./res/hud/status_wall.png");
    hud->status_exit = load_texture_from_filepath(renderer, "./res/hud/status_exit.png");
    hud->status_stable = load_texture_from_filepath(renderer, "./res/hud/status_stable.png");
    hud->status_manipulatable = load_texture_from_filepath(renderer, "./res/hud/status_manipulatable.png");
    hud->status_station = load_texture_from_filepath(renderer, "./res/hud/status_station.png");
    hud->status_stone = load_texture_from_filepath(renderer, "./res/hud/status_stone.png");
    hud->status_metal = load_texture_from_filepath(renderer, "./res/hud/status_metal.png");
    hud->status_glass = load_texture_from_filepath(renderer, "./res/hud/status_glass.png");
    hud->status_floor_manipulatable = load_texture_from_filepath(renderer, "./res/hud/status_floor_manipulatable.png");
    hud->status_floor_not_traversable = load_texture_from_filepath(renderer, "./res/hud/status_floor_not_traversable.png");
    hud->status_floor_warning = load_texture_from_filepath(renderer, "./res/hud/status_floor_warning.png");
    hud->status_floor_deadly = load_texture_from_filepath(renderer, "./res/hud/status_floor_deadly.png");

    hud->cell = load_texture_from_filepath(renderer, "./res/hud/cell.png");
    hud->dynamite = load_texture_from_filepath(renderer, "./res/hud/dynamite.png");
    hud->gemstone = load_texture_from_filepath(renderer, "./res/hud/gemstone.png");

    hud->end_turn = load_texture_from_filepath(renderer, "./res/hud/end_turn.png");
    hud->reset_turn = load_texture_from_filepath(renderer, "./res/hud/reset_turn.png");
    hud->reset_turn_inactive = load_texture_from_filepath(renderer, "./res/hud/reset_turn_inactive.png");
    hud->reset_turn_used = load_texture_from_filepath(renderer, "./res/hud/reset_turn_used.png");
    hud->reset_turn_3x = load_texture_from_filepath(renderer, "./res/hud/reset_turn_3x.png");
    hud->reset_turn_2x = load_texture_from_filepath(renderer, "./res/hud/reset_turn_2x.png");
    hud->reset_turn_1x = load_texture_from_filepath(renderer, "./res/hud/reset_turn_1x.png");
    hud->show_attack_order = load_texture_from_filepath(renderer, "./res/hud/show_attack_order.png");
    hud->start_again = load_texture_from_filepath(renderer, "./res/hud/start_again.png");
    hud->start_game = load_texture_from_filepath(renderer, "./res/hud/start_game.png");
    hud->restart_game = load_texture_from_filepath(renderer, "./res/hud/restart_game.png");
    hud->load_save = load_texture_from_filepath(renderer, "./res/hud/load_save.png");
    hud->bar_part = load_texture_from_filepath(renderer, "./res/hud/bar_part.png");
}
void destroy_textures_hud(Textures_Hud* hud)
{
    // later
}

void load_textures(Renderer* renderer, Textures* textures)
{
    textures->tutorial = load_texture_from_filepath(renderer, "./res/tutorial.png");
    textures->shadow = load_texture_from_filepath(renderer, "./res/shadow.png");
    textures->background_rock = load_texture_from_filepath(renderer, "./res/background_rock.png");
    textures->background_stone = load_texture_from_filepath(renderer, "./res/background_stone.png");
    textures->background_metal = load_texture_from_filepath(renderer, "./res/background_metal.png");
    textures->background_marble = load_texture_from_filepath(renderer, "./res/background_marble.png");
    textures->background_obsidian = load_texture_from_filepath(renderer, "./res/background_obsidian.png");
    textures->background_gold = load_texture_from_filepath(renderer, "./res/background_gold.png");

    load_textures_floor(renderer, &textures->floor);
    load_textures_object(renderer, &textures->object);
    load_textures_order_number(renderer, &textures->order_number);
    load_textures_skill(renderer, &textures->skill);
    load_textures_animation(renderer, &textures->animation);
    load_textures_hud(renderer, &textures->hud);
}

void destroy_textures(Textures* textures)
{
    destroy_textures_floor(&textures->floor);
    destroy_textures_object(&textures->object);
    destroy_textures_order_number(&textures->order_number);
    destroy_textures_skill(&textures->skill);
    destroy_textures_animation(&textures->animation);
    destroy_textures_hud(&textures->hud);
}

Texture* get_texture_throw(Textures* textures, int dir4)
{
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

    switch(item)
    {
        case ITEM__CELL:
        {
            switch(number)
            {
                case -3:texture = textures->skill.minus_3_cell; break;
                case -2:texture = textures->skill.minus_2_cell; break;
                case -1:texture = textures->skill.minus_1_cell; break;
                case 1:texture = textures->skill.plus_1_cell; break;
                case 2:texture = textures->skill.plus_2_cell; break;
                case 3:texture = textures->skill.plus_3_cell; break;
                default:break;
            }
        }
        break;
        case ITEM__DYNAMITE:
        {
            switch(number)
            {
                case -3:texture = textures->skill.minus_3_dynamite; break;
                case -2:texture = textures->skill.minus_2_dynamite; break;
                case -1:texture = textures->skill.minus_1_dynamite; break;
                case 1:texture = textures->skill.plus_1_dynamite; break;
                case 2:texture = textures->skill.plus_2_dynamite; break;
                case 3:texture = textures->skill.plus_3_dynamite; break;
                default:break;
            }
        }
        break;
        case ITEM__GEMSTONE:
        {
            switch(number)
            {
                case -3:texture = textures->skill.minus_3_gemstone; break;
                case -2:texture = textures->skill.minus_2_gemstone; break;
                case -1:texture = textures->skill.minus_1_gemstone; break;
                case 1:texture = textures->skill.plus_1_gemstone; break;
                case 2:texture = textures->skill.plus_2_gemstone; break;
                case 3:texture = textures->skill.plus_3_gemstone; break;
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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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
    Texture* texture = NULL;

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

Texture* get_texture_spiderweb_start(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.spiderweb_up_start; break;
        case DIR4__RIGHT: texture = textures->animation.spiderweb_right_start; break;
        case DIR4__DOWN: texture = textures->animation.spiderweb_down_start; break;
        case DIR4__LEFT: texture = textures->animation.spiderweb_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_spiderweb_end(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.spiderweb_up_end; break;
        case DIR4__RIGHT: texture = textures->animation.spiderweb_right_end; break;
        case DIR4__DOWN: texture = textures->animation.spiderweb_down_end; break;
        case DIR4__LEFT: texture = textures->animation.spiderweb_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_spiderweb_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = NULL;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.spiderweb_up_up; break;
                case DIR4__RIGHT: texture = textures->animation.spiderweb_up_right; break;
                case DIR4__DOWN: texture = textures->animation.spiderweb_up_down; break;
                case DIR4__LEFT: texture = textures->animation.spiderweb_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.spiderweb_right_up; break;
                case DIR4__RIGHT: texture = textures->animation.spiderweb_right_right; break;
                case DIR4__DOWN: texture = textures->animation.spiderweb_right_down; break;
                case DIR4__LEFT: texture = textures->animation.spiderweb_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.spiderweb_down_up; break;
                case DIR4__RIGHT: texture = textures->animation.spiderweb_down_right; break;
                case DIR4__DOWN: texture = textures->animation.spiderweb_down_down; break;
                case DIR4__LEFT: texture = textures->animation.spiderweb_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.spiderweb_left_up; break;
                case DIR4__RIGHT: texture = textures->animation.spiderweb_left_right; break;
                case DIR4__DOWN: texture = textures->animation.spiderweb_left_down; break;
                case DIR4__LEFT: texture = textures->animation.spiderweb_left_left; break;
                default: break;
            }
        }
        break;
        default: break;
    }

    return texture;
}

Texture* get_texture_tentacle_start(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.tentacle_up_start; break;
        case DIR4__RIGHT: texture = textures->animation.tentacle_right_start; break;
        case DIR4__DOWN: texture = textures->animation.tentacle_down_start; break;
        case DIR4__LEFT: texture = textures->animation.tentacle_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_tentacle_end(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.tentacle_up_end; break;
        case DIR4__RIGHT: texture = textures->animation.tentacle_right_end; break;
        case DIR4__DOWN: texture = textures->animation.tentacle_down_end; break;
        case DIR4__LEFT: texture = textures->animation.tentacle_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_tentacle_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = NULL;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tentacle_up_up; break;
                case DIR4__RIGHT: texture = textures->animation.tentacle_up_right; break;
                case DIR4__DOWN: texture = textures->animation.tentacle_up_down; break;
                case DIR4__LEFT: texture = textures->animation.tentacle_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tentacle_right_up; break;
                case DIR4__RIGHT: texture = textures->animation.tentacle_right_right; break;
                case DIR4__DOWN: texture = textures->animation.tentacle_right_down; break;
                case DIR4__LEFT: texture = textures->animation.tentacle_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tentacle_down_up; break;
                case DIR4__RIGHT: texture = textures->animation.tentacle_down_right; break;
                case DIR4__DOWN: texture = textures->animation.tentacle_down_down; break;
                case DIR4__LEFT: texture = textures->animation.tentacle_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tentacle_left_up; break;
                case DIR4__RIGHT: texture = textures->animation.tentacle_left_right; break;
                case DIR4__DOWN: texture = textures->animation.tentacle_left_down; break;
                case DIR4__LEFT: texture = textures->animation.tentacle_left_left; break;
                default: break;
            }
        }
        break;
        default: break;
    }

    return texture;
}

Texture* get_texture_tongue_start(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.tongue_up_start; break;
        case DIR4__RIGHT: texture = textures->animation.tongue_right_start; break;
        case DIR4__DOWN: texture = textures->animation.tongue_down_start; break;
        case DIR4__LEFT: texture = textures->animation.tongue_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_tongue_end(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.tongue_up_end; break;
        case DIR4__RIGHT: texture = textures->animation.tongue_right_end; break;
        case DIR4__DOWN: texture = textures->animation.tongue_down_end; break;
        case DIR4__LEFT: texture = textures->animation.tongue_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_tongue_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = NULL;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tongue_up_up; break;
                case DIR4__RIGHT: texture = textures->animation.tongue_up_right; break;
                case DIR4__DOWN: texture = textures->animation.tongue_up_down; break;
                case DIR4__LEFT: texture = textures->animation.tongue_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tongue_right_up; break;
                case DIR4__RIGHT: texture = textures->animation.tongue_right_right; break;
                case DIR4__DOWN: texture = textures->animation.tongue_right_down; break;
                case DIR4__LEFT: texture = textures->animation.tongue_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tongue_down_up; break;
                case DIR4__RIGHT: texture = textures->animation.tongue_down_right; break;
                case DIR4__DOWN: texture = textures->animation.tongue_down_down; break;
                case DIR4__LEFT: texture = textures->animation.tongue_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.tongue_left_up; break;
                case DIR4__RIGHT: texture = textures->animation.tongue_left_right; break;
                case DIR4__DOWN: texture = textures->animation.tongue_left_down; break;
                case DIR4__LEFT: texture = textures->animation.tongue_left_left; break;
                default: break;
            }
        }
        break;
        default: break;
    }

    return texture;
}

Texture* get_texture_scissor_start(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.scissor_up_start; break;
        case DIR4__RIGHT: texture = textures->animation.scissor_right_start; break;
        case DIR4__DOWN: texture = textures->animation.scissor_down_start; break;
        case DIR4__LEFT: texture = textures->animation.scissor_left_start; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_scissor_end(Textures* textures, int dir4)
{
    Texture* texture = NULL;

    switch(dir4)
    {
        case DIR4__UP: texture = textures->animation.scissor_up_end; break;
        case DIR4__RIGHT: texture = textures->animation.scissor_right_end; break;
        case DIR4__DOWN: texture = textures->animation.scissor_down_end; break;
        case DIR4__LEFT: texture = textures->animation.scissor_left_end; break;
        default: break;
    }

    return texture;
}

Texture* get_texture_scissor_from_to(Textures* textures, int dir4_from, int dir4_to)
{
    Texture* texture = NULL;

    switch(dir4_from)
    {
        case DIR4__UP:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.scissor_up_up; break;
                case DIR4__RIGHT: texture = textures->animation.scissor_up_right; break;
                case DIR4__DOWN: texture = textures->animation.scissor_up_down; break;
                case DIR4__LEFT: texture = textures->animation.scissor_up_left; break;
                default: break;
            }
        }
        break;
        case DIR4__RIGHT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.scissor_right_up; break;
                case DIR4__RIGHT: texture = textures->animation.scissor_right_right; break;
                case DIR4__DOWN: texture = textures->animation.scissor_right_down; break;
                case DIR4__LEFT: texture = textures->animation.scissor_right_left; break;
                default: break;
            }
        }
        break;
        case DIR4__DOWN:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.scissor_down_up; break;
                case DIR4__RIGHT: texture = textures->animation.scissor_down_right; break;
                case DIR4__DOWN: texture = textures->animation.scissor_down_down; break;
                case DIR4__LEFT: texture = textures->animation.scissor_down_left; break;
                default: break;
            }
        }
        break;
        case DIR4__LEFT:
        {
            switch(dir4_to)
            {
                case DIR4__UP: texture = textures->animation.scissor_left_up; break;
                case DIR4__RIGHT: texture = textures->animation.scissor_left_right; break;
                case DIR4__DOWN: texture = textures->animation.scissor_left_down; break;
                case DIR4__LEFT: texture = textures->animation.scissor_left_left; break;
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
    Texture* texture = NULL;

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

Texture* get_texture_dots_arch_horizontal(Textures* textures, int length, int i)
{
    Texture* texture = NULL;

    switch(length)
    {
        case 10:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_10_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_10_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_10_3; break;
                case 4: texture = textures->skill.dots_arch_horizontal_10_4; break;
                case 5: texture = textures->skill.dots_arch_horizontal_10_5; break;
                case 6: texture = textures->skill.dots_arch_horizontal_10_6; break;
                case 7: texture = textures->skill.dots_arch_horizontal_10_7; break;
                case 8: texture = textures->skill.dots_arch_horizontal_10_8; break;
                case 9: texture = textures->skill.dots_arch_horizontal_10_9; break;
                case 10: texture = textures->skill.dots_arch_horizontal_10_10; break;
                default: break;
            }
        }
        break;
        case 9:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_10_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_10_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_10_3; break;
                case 4: texture = textures->skill.dots_arch_horizontal_10_4; break;
                case 5: texture = textures->skill.dots_arch_horizontal_10_5; break;
                case 6: texture = textures->skill.dots_arch_horizontal_10_7; break;
                case 7: texture = textures->skill.dots_arch_horizontal_10_8; break;
                case 8: texture = textures->skill.dots_arch_horizontal_10_9; break;
                case 9: texture = textures->skill.dots_arch_horizontal_10_10; break;
                default: break;
            }
        }
        break;
        case 8:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_10_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_10_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_10_3; break;
                case 4: texture = textures->skill.dots_arch_horizontal_10_4; break;
                case 5: texture = textures->skill.dots_arch_horizontal_10_5; break;
                case 6: texture = textures->skill.dots_arch_horizontal_10_7; break;
                case 7: texture = textures->skill.dots_arch_horizontal_10_9; break;
                case 8: texture = textures->skill.dots_arch_horizontal_10_10; break;
                default: break;
            }
        }
        break;
        case 7:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_10_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_10_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_10_3; break;
                case 4: texture = textures->skill.dots_arch_horizontal_10_5; break;
                case 5: texture = textures->skill.dots_arch_horizontal_10_7; break;
                case 6: texture = textures->skill.dots_arch_horizontal_10_9; break;
                case 7: texture = textures->skill.dots_arch_horizontal_10_10; break;
                default: break;
            }
        }
        break;
        case 6:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_6_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_6_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_6_3; break;
                case 4: texture = textures->skill.dots_arch_horizontal_6_4; break;
                case 5: texture = textures->skill.dots_arch_horizontal_6_5; break;
                case 6: texture = textures->skill.dots_arch_horizontal_6_6; break;
                default: break;
            }
        }
        break;
        case 5:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_6_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_6_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_6_3; break;
                case 4: texture = textures->skill.dots_arch_horizontal_6_5; break;
                case 5: texture = textures->skill.dots_arch_horizontal_6_6; break;
                default: break;
            }
        }
        break;
        case 4:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_6_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_6_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_6_5; break;
                case 4: texture = textures->skill.dots_arch_horizontal_6_6; break;
                default: break;
            }
        }
        break;
        case 3:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_3_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_3_2; break;
                case 3: texture = textures->skill.dots_arch_horizontal_3_3; break;
                default: break;
            }
        }
        break;
        case 2:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_2_1; break;
                case 2: texture = textures->skill.dots_arch_horizontal_2_2; break;
                default: break;
            }
        }
        break;
        case 1:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_horizontal_1_1; break;
                default: break;
            }
        }
        break;
    }

    return texture;
}

Texture* get_texture_dots_arch_vertical(Textures* textures, int length, int i)
{
    Texture* texture = NULL;

    switch(length)
    {
        case 10:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_10_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_10_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_10_3; break;
                case 4: texture = textures->skill.dots_arch_vertical_10_4; break;
                case 5: texture = textures->skill.dots_arch_vertical_10_5; break;
                case 6: texture = textures->skill.dots_arch_vertical_10_6; break;
                case 7: texture = textures->skill.dots_arch_vertical_10_7; break;
                case 8: texture = textures->skill.dots_arch_vertical_10_8; break;
                case 9: texture = textures->skill.dots_arch_vertical_10_9; break;
                case 10: texture = textures->skill.dots_arch_vertical_10_10; break;
                default: break;
            }
        }
        break;
        case 9:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_10_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_10_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_10_3; break;
                case 4: texture = textures->skill.dots_arch_vertical_10_4; break;
                case 5: texture = textures->skill.dots_arch_vertical_10_5; break;
                case 6: texture = textures->skill.dots_arch_vertical_10_7; break;
                case 7: texture = textures->skill.dots_arch_vertical_10_8; break;
                case 8: texture = textures->skill.dots_arch_vertical_10_9; break;
                case 9: texture = textures->skill.dots_arch_vertical_10_10; break;
                default: break;
            }
        }
        break;
        case 8:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_10_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_10_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_10_3; break;
                case 4: texture = textures->skill.dots_arch_vertical_10_4; break;
                case 5: texture = textures->skill.dots_arch_vertical_10_5; break;
                case 6: texture = textures->skill.dots_arch_vertical_10_7; break;
                case 7: texture = textures->skill.dots_arch_vertical_10_9; break;
                case 8: texture = textures->skill.dots_arch_vertical_10_10; break;
                default: break;
            }
        }
        break;
        case 7:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_10_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_10_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_10_3; break;
                case 4: texture = textures->skill.dots_arch_vertical_10_5; break;
                case 5: texture = textures->skill.dots_arch_vertical_10_7; break;
                case 6: texture = textures->skill.dots_arch_vertical_10_9; break;
                case 7: texture = textures->skill.dots_arch_vertical_10_10; break;
                default: break;
            }
        }
        break;
        case 6:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_6_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_6_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_6_3; break;
                case 4: texture = textures->skill.dots_arch_vertical_6_4; break;
                case 5: texture = textures->skill.dots_arch_vertical_6_5; break;
                case 6: texture = textures->skill.dots_arch_vertical_6_6; break;
                default: break;
            }
        }
        break;
        case 5:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_6_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_6_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_6_3; break;
                case 4: texture = textures->skill.dots_arch_vertical_6_5; break;
                case 5: texture = textures->skill.dots_arch_vertical_6_6; break;
                default: break;
            }
        }
        break;
        case 4:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_6_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_6_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_6_5; break;
                case 4: texture = textures->skill.dots_arch_vertical_6_6; break;
                default: break;
            }
        }
        break;
        case 3:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_3_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_3_2; break;
                case 3: texture = textures->skill.dots_arch_vertical_3_3; break;
                default: break;
            }
        }
        break;
        case 2:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_2_1; break;
                case 2: texture = textures->skill.dots_arch_vertical_2_2; break;
                default: break;
            }
        }
        break;
        case 1:
        {
            switch(i)
            {
                case 1: texture = textures->skill.dots_arch_vertical_1_1; break;
                default: break;
            }
        }
        break;
    }

    return texture;
}
