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
    Texture* rock_crack_pit;

    Texture* stone;
    Texture* stone_trap;

    Texture* metal;
    Texture* metal_spikes_on;
    Texture* metal_spikes_off;
    Texture* metal_hatch_open_1;
    Texture* metal_hatch_open_2;
    Texture* metal_hatch_closed;
    Texture* metal_cover_bottom;
    Texture* metal_target_unchecked;
    Texture* metal_target_checked;

    Texture* metal_piston;
    Texture* metal_piston_cell;
    Texture* metal_piston_dynamite;
    Texture* metal_piston_barrel;
    Texture* metal_piston_mimic;
    Texture* metal_no_piston;

    Texture* gold;

    Texture* marble;

    Texture* obsidian;

    Texture* grass;

    Texture* sand;

    Texture* coins;

    Texture* pit;
    Texture* pit_column;

    Texture* water_1;
    Texture* water_2;
    Texture* water_lily_pod_1;
    Texture* water_lily_pod_2;
    Texture* water_stalactite_fallen_1;
    Texture* water_stalactite_fallen_2;
    Texture* water_column_1;
    Texture* water_column_2;

    Texture* lava_1;
    Texture* lava_2;
    Texture* lava_stalactite_fallen_1;
    Texture* lava_stalactite_fallen_2;
    Texture* lava_column_1;
    Texture* lava_column_2;

    Texture* ice;
    Texture* ice_crack_water;

    Texture* obstacle;

    Texture* conv_belt_up;
    Texture* conv_belt_right;
    Texture* conv_belt_down;
    Texture* conv_belt_left;

    Texture* ext_bridge_source_on_horizontal;
    Texture* ext_bridge_source_off_horizontal;
    Texture* ext_bridge_part_horizontal;
    Texture* ext_bridge_source_on_vertical;
    Texture* ext_bridge_source_off_vertical;
    Texture* ext_bridge_part_vertical;

    Texture* stone_stairs_below;
    Texture* stone_stairs_below_blocked;
    Texture* stone_stairs_above_unpowered;
    Texture* stone_stairs_above_powered;
    Texture* rock_stairs_below;
    Texture* metal_stairs_below_off;
    Texture* metal_stairs_above_off;
    Texture* metal_stairs_below_on;
    Texture* metal_stairs_below;

} Textures_Floor;

void load_textures_floor (Renderer* renderer, Textures_Floor* floor);
void destroy_textures_floor (Textures_Floor* floor);

typedef struct
{
    Texture* wall_rock;
    Texture* wall_stone;
    Texture* wall_metal;
    Texture* wall_gold;
    Texture* wall_marble;
    Texture* wall_obsidian;
    Texture* wall_outline;

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
    Texture* exit_stone_powered_up;
    Texture* exit_stone_unpowered_up;
    Texture* exit_stone_up_outline;
    Texture* exit_stone_right;
    Texture* exit_stone_blocked_right;
    Texture* exit_stone_powered_right;
    Texture* exit_stone_unpowered_right;
    Texture* exit_stone_right_outline;
    Texture* exit_stone_down;
    Texture* exit_stone_blocked_down;
    Texture* exit_stone_powered_down;
    Texture* exit_stone_unpowered_down;
    Texture* exit_stone_down_outline;
    Texture* exit_stone_left;
    Texture* exit_stone_blocked_left;
    Texture* exit_stone_powered_left;
    Texture* exit_stone_unpowered_left;
    Texture* exit_stone_left_outline;

    Texture* exit_metal_up;
    Texture* exit_metal_blocked_up;
    Texture* exit_metal_on_up;
    Texture* exit_metal_off_up;
    Texture* exit_metal_up_outline;
    Texture* exit_metal_right;
    Texture* exit_metal_blocked_right;
    Texture* exit_metal_on_right;
    Texture* exit_metal_off_right;
    Texture* exit_metal_right_outline;
    Texture* exit_metal_down;
    Texture* exit_metal_blocked_down;
    Texture* exit_metal_on_down;
    Texture* exit_metal_off_down;
    Texture* exit_metal_down_outline;
    Texture* exit_metal_left;
    Texture* exit_metal_blocked_left;
    Texture* exit_metal_on_left;
    Texture* exit_metal_off_left;
    Texture* exit_metal_left_outline;

    Texture* exit_gold_locked_up;
    Texture* exit_gold_unlocked_up;
    Texture* exit_gold_up_outline;
    Texture* exit_gold_locked_right;
    Texture* exit_gold_unlocked_right;
    Texture* exit_gold_right_outline;
    Texture* exit_gold_locked_down;
    Texture* exit_gold_unlocked_down;
    Texture* exit_gold_down_outline;
    Texture* exit_gold_locked_left;
    Texture* exit_gold_unlocked_left;
    Texture* exit_gold_left_outline;

    Texture* exit_marble_up;
    Texture* exit_marble_up_outline;
    Texture* exit_marble_right;
    Texture* exit_marble_right_outline;
    Texture* exit_marble_down;
    Texture* exit_marble_down_outline;
    Texture* exit_marble_left;
    Texture* exit_marble_left_outline;

    Texture* exit_obsidian_up;
    Texture* exit_obsidian_up_outline;
    Texture* exit_obsidian_right;
    Texture* exit_obsidian_right_outline;
    Texture* exit_obsidian_down;
    Texture* exit_obsidian_down_outline;
    Texture* exit_obsidian_left;
    Texture* exit_obsidian_left_outline;

    Texture* pillar;
    Texture* pillar_outline;

    Texture* sarcophagus;
    Texture* sarcophagus_outline;

    Texture* pipe;
    Texture* pipe_outline;

    Texture* stalactite;
    Texture* stalactite_outline;

    Texture* stalactite_fallen;
    Texture* stalactite_fallen_outline;

    Texture* stalactite_fallen_item;
    Texture* stalactite_fallen_item_outline;

    Texture* stalagmite;
    Texture* stalagmite_outline;

    Texture* stalagnate;
    Texture* stalagnate_outline;

    Texture* cover_rock;
    Texture* cover_rock_outline;

    Texture* cover_metal;
    Texture* cover_metal_outline;

    Texture* cover_glass;
    Texture* cover_glass_outline;

    Texture* crate_gemstone;
    Texture* crate_gemstone_outline;

    Texture* crate_gemstone_item;
    Texture* crate_gemstone_item_outline;

    Texture* crate_cell;
    Texture* crate_cell_outline;

    Texture* crate_cell_item;
    Texture* crate_cell_item_outline;

    Texture* crate_dynamite;
    Texture* crate_dynamite_outline;

    Texture* crate_dynamite_item;
    Texture* crate_dynamite_item_outline;

    Texture* rock;
    Texture* rock_outline;

    Texture* rock_item;
    Texture* rock_item_outline;

    Texture* rock_damaged;
    Texture* rock_damaged_outline;

    Texture* rock_damaged_item;
    Texture* rock_damaged_item_outline;

    Texture* safe;
    Texture* safe_outline;

    Texture* safe_item;
    Texture* safe_item_outline;

    Texture* safe_damaged;
    Texture* safe_damaged_outline;

    Texture* safe_damaged_item;
    Texture* safe_damaged_item_outline;

    Texture* display;
    Texture* display_outline;

    Texture* display_item;
    Texture* display_item_outline;

    Texture* display_damaged;
    Texture* display_damaged_outline;

    Texture* display_damaged_item;
    Texture* display_damaged_item_outline;

    Texture* vending_cell;
    Texture* vending_cell_outline;

    Texture* vending_cell_item;
    Texture* vending_cell_item_outline;

    Texture* vending_cell_damaged;
    Texture* vending_cell_damaged_outline;

    Texture* vending_cell_damaged_item;
    Texture* vending_cell_damaged_item_outline;

    Texture* vending_dynamite;
    Texture* vending_dynamite_outline;

    Texture* vending_dynamite_item;
    Texture* vending_dynamite_item_outline;

    Texture* vending_dynamite_damaged;
    Texture* vending_dynamite_damaged_outline;

    Texture* vending_dynamite_damaged_item;
    Texture* vending_dynamite_damaged_item_outline;

    Texture* barrel;
    Texture* barrel_outline;

    Texture* column;
    Texture* column_outline;

    Texture* spring;
    Texture* spring_outline;

    Texture* piston;
    Texture* piston_outline;

    Texture* piston_cell;
    Texture* piston_cell_outline;

    Texture* piston_dynamite;
    Texture* piston_dynamite_outline;

    Texture* piston_barrel;
    Texture* piston_barrel_outline;

    Texture* obstacle;
    Texture* obstacle_outline;

    Texture* ball;
    Texture* ball_outline;

    Texture* ball_spikes;
    Texture* ball_spikes_outline;

    Texture* throne;
    Texture* throne_outline;

    Texture* golem_unpowered;
    Texture* golem_unpowered_outline;

    Texture* golem_half_powered;
    Texture* golem_half_powered_outline;

    Texture* golem_powered_1;
    Texture* golem_powered_2;
    Texture* golem_powered_outline_1;
    Texture* golem_powered_outline_2;

    Texture* hero_1;
    Texture* hero_2;
    Texture* hero_outline_1;
    Texture* hero_outline_2;

    Texture* hero_floating_1;
    Texture* hero_floating_2;
    Texture* hero_floating_outline_1;
    Texture* hero_floating_outline_2;

    Texture* hero_flying_1;
    Texture* hero_flying_2;
    Texture* hero_flying_outline_1;
    Texture* hero_flying_outline_2;

    Texture* minibot_ally_1;
    Texture* minibot_ally_2;
    Texture* minibot_ally_outline_1;
    Texture* minibot_ally_outline_2;

    Texture* minibot_ally_cell_1;
    Texture* minibot_ally_cell_2;
    Texture* minibot_ally_cell_outline_1;
    Texture* minibot_ally_cell_outline_2;

    Texture* minibot_ally_dynamite_1;
    Texture* minibot_ally_dynamite_2;
    Texture* minibot_ally_dynamite_outline_1;
    Texture* minibot_ally_dynamite_outline_2;

    Texture* minibot_ally_gemstone_1;
    Texture* minibot_ally_gemstone_2;
    Texture* minibot_ally_gemstone_outline_1;
    Texture* minibot_ally_gemstone_outline_2;

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

    Texture* squid_1;
    Texture* squid_2;
    Texture* squid_outline_1;
    Texture* squid_outline_2;

    Texture* mole_1;
    Texture* mole_2;
    Texture* mole_outline_1;
    Texture* mole_outline_2;

    Texture* mimic_1;
    Texture* mimic_2;
    Texture* mimic_outline_1;
    Texture* mimic_outline_2;

    Texture* shark_1;
    Texture* shark_2;
    Texture* shark_outline_1;
    Texture* shark_outline_2;

    Texture* shark_fin_1;
    Texture* shark_fin_2;
    Texture* shark_fin_outline_1;
    Texture* shark_fin_outline_2;

    Texture* minibot_enemy_1;
    Texture* minibot_enemy_2;
    Texture* minibot_enemy_outline_1;
    Texture* minibot_enemy_outline_2;

    Texture* minibot_enemy_cell_1;
    Texture* minibot_enemy_cell_2;
    Texture* minibot_enemy_cell_outline_1;
    Texture* minibot_enemy_cell_outline_2;

    Texture* minibot_enemy_dynamite_1;
    Texture* minibot_enemy_dynamite_2;
    Texture* minibot_enemy_dynamite_outline_1;
    Texture* minibot_enemy_dynamite_outline_2;

    Texture* minibot_enemy_gemstone_1;
    Texture* minibot_enemy_gemstone_2;
    Texture* minibot_enemy_gemstone_outline_1;
    Texture* minibot_enemy_gemstone_outline_2;

    Texture* turret_laser_grounded_1;
    Texture* turret_laser_grounded_2;
    Texture* turret_laser_grounded_outline_1;
    Texture* turret_laser_grounded_outline_2;

    Texture* turret_laser_standing_1;
    Texture* turret_laser_standing_2;
    Texture* turret_laser_standing_outline_1;
    Texture* turret_laser_standing_outline_2;

    Texture* turret_laser_undeployed_1;
    Texture* turret_laser_undeployed_2;
    Texture* turret_laser_undeployed_outline_1;
    Texture* turret_laser_undeployed_outline_2;

    Texture* turret_laser_deployed_1;
    Texture* turret_laser_deployed_2;
    Texture* turret_laser_deployed_outline_1;
    Texture* turret_laser_deployed_outline_2;

    Texture* turret_bomb_grounded_1;
    Texture* turret_bomb_grounded_2;
    Texture* turret_bomb_grounded_outline_1;
    Texture* turret_bomb_grounded_outline_2;

    Texture* turret_bomb_standing_1;
    Texture* turret_bomb_standing_2;
    Texture* turret_bomb_standing_outline_1;
    Texture* turret_bomb_standing_outline_2;

    Texture* turret_bomb_undeployed_1;
    Texture* turret_bomb_undeployed_2;
    Texture* turret_bomb_undeployed_outline_1;
    Texture* turret_bomb_undeployed_outline_2;

    Texture* turret_bomb_deployed_1;
    Texture* turret_bomb_deployed_2;
    Texture* turret_bomb_deployed_outline_1;
    Texture* turret_bomb_deployed_outline_2;

    Texture* turret_projectile_grounded_1;
    Texture* turret_projectile_grounded_2;
    Texture* turret_projectile_grounded_outline_1;
    Texture* turret_projectile_grounded_outline_2;

    Texture* turret_projectile_standing_1;
    Texture* turret_projectile_standing_2;
    Texture* turret_projectile_standing_outline_1;
    Texture* turret_projectile_standing_outline_2;

    Texture* turret_projectile_undeployed_1;
    Texture* turret_projectile_undeployed_2;
    Texture* turret_projectile_undeployed_outline_1;
    Texture* turret_projectile_undeployed_outline_2;

    Texture* turret_projectile_deployed_1;
    Texture* turret_projectile_deployed_2;
    Texture* turret_projectile_deployed_outline_1;
    Texture* turret_projectile_deployed_outline_2;

    Texture* squirrel_exit_obsidian_down_1;
    Texture* squirrel_exit_obsidian_down_2;

    Texture* stairs_above_stone_powered;
    Texture* stairs_above_stone_powered_outline;

    Texture* stairs_above_stone;
    Texture* stairs_above_stone_outline;

    Texture* stairs_above_rock;
    Texture* stairs_above_rock_outline;

    Texture* stairs_above_metal_on;
    Texture* stairs_above_metal_on_outline;

    Texture* stairs_above_metal;
    Texture* stairs_above_metal_outline;

    Texture* lever_metal_off;
    Texture* lever_metal_off_outline;

    Texture* lever_metal_on;
    Texture* lever_metal_on_outline;

    Texture* lever_stone_unpowered;
    Texture* lever_stone_unpowered_outline;

    Texture* lever_stone_powered;
    Texture* lever_stone_powered_outline;

    Texture* ext_wall_source_on_horizontal;
    Texture* ext_wall_source_on_horizontal_outline;

    Texture* ext_wall_source_off_horizontal;
    Texture* ext_wall_source_off_horizontal_outline;

    Texture* ext_wall_part_horizontal;
    Texture* ext_wall_part_horizontal_outline;

    Texture* ext_wall_source_on_vertical;
    Texture* ext_wall_source_on_vertical_outline;

    Texture* ext_wall_source_off_vertical;
    Texture* ext_wall_source_off_vertical_outline;

    Texture* ext_wall_part_vertical;
    Texture* ext_wall_part_vertical_outline;

    Texture* harpoon_gun_up;
    Texture* harpoon_gun_up_outline;

    Texture* harpoon_gun_right;
    Texture* harpoon_gun_right_outline;

    Texture* harpoon_gun_down;
    Texture* harpoon_gun_down_outline;

    Texture* harpoon_gun_left;
    Texture* harpoon_gun_left_outline;

    Texture* station_fist_hand;
    Texture* station_hook_hand;
    Texture* station_chain_hand;
    Texture* station_scissor_hand;
    Texture* station_spring_leg;
    Texture* station_strider_leg;
    Texture* station_track_leg;
    Texture* station_boot_leg;
    Texture* station_minibot_torso;
    Texture* station_wings_torso;
    Texture* station_manipulation_head;
    Texture* station_teleportation_head;
    Texture* station_taken;
    Texture* station_outline;

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
    Texture* throw_up;
    Texture* throw_right;
    Texture* throw_down;
    Texture* throw_left;

    Texture* lift_none;
    Texture* lift_up;
    Texture* lift_right;
    Texture* lift_down;
    Texture* lift_left;

    Texture* fall;
    Texture* drop;
    Texture* change;

    Texture* floor_border_solid;
    Texture* floor_border_dashed;
    Texture* floor_border_dotted;
    Texture* floor_danger;

    Texture* arrow_thin_up_start;
    Texture* arrow_thin_up_end;
    Texture* arrow_thin_up_up;
    Texture* arrow_thin_up_right;
    Texture* arrow_thin_up_down;
    Texture* arrow_thin_up_left;

    Texture* arrow_thin_right_start;
    Texture* arrow_thin_right_end;
    Texture* arrow_thin_right_up;
    Texture* arrow_thin_right_right;
    Texture* arrow_thin_right_down;
    Texture* arrow_thin_right_left;

    Texture* arrow_thin_down_start;
    Texture* arrow_thin_down_end;
    Texture* arrow_thin_down_up;
    Texture* arrow_thin_down_right;
    Texture* arrow_thin_down_down;
    Texture* arrow_thin_down_left;

    Texture* arrow_thin_left_start;
    Texture* arrow_thin_left_end;
    Texture* arrow_thin_left_up;
    Texture* arrow_thin_left_right;
    Texture* arrow_thin_left_down;
    Texture* arrow_thin_left_left;

    Texture* arrow_thick_up_start;
    Texture* arrow_thick_up_end;
    Texture* arrow_thick_up_up;
    Texture* arrow_thick_up_right;
    Texture* arrow_thick_up_down;
    Texture* arrow_thick_up_left;

    Texture* arrow_thick_right_start;
    Texture* arrow_thick_right_end;
    Texture* arrow_thick_right_up;
    Texture* arrow_thick_right_right;
    Texture* arrow_thick_right_down;
    Texture* arrow_thick_right_left;

    Texture* arrow_thick_down_start;
    Texture* arrow_thick_down_end;
    Texture* arrow_thick_down_up;
    Texture* arrow_thick_down_right;
    Texture* arrow_thick_down_down;
    Texture* arrow_thick_down_left;

    Texture* arrow_thick_left_start;
    Texture* arrow_thick_left_end;
    Texture* arrow_thick_left_up;
    Texture* arrow_thick_left_right;
    Texture* arrow_thick_left_down;
    Texture* arrow_thick_left_left;

    Texture* dots_line_horizontal;
    Texture* dots_line_vertical;

    Texture* dots_arch_horizontal;
    Texture* dots_arch_vertical;

    Texture* attack_dir4_up;
    Texture* attack_dir4_right;
    Texture* attack_dir4_down;
    Texture* attack_dir4_left;

    Texture* immovable_effect;
    Texture* crash_effect;
    Texture* blow_up_effect;
    Texture* death_effect;
    Texture* break_effect;
    Texture* melt_effect;
    Texture* shake_effect;
    Texture* stomp_effect;
    Texture* use_effect;
    Texture* manipulation_effect;
    Texture* teleportation_effect;

    Texture* no_positions;
    Texture* no_attack;

    Texture* plus_1_cell;
    Texture* plus_2_cell;
    Texture* plus_3_cell;
    Texture* minus_1_cell;
    Texture* minus_2_cell;
    Texture* minus_3_cell;
    Texture* plus_1_dynamite;
    Texture* plus_2_dynamite;
    Texture* plus_3_dynamite;
    Texture* minus_1_dynamite;
    Texture* minus_2_dynamite;
    Texture* minus_3_dynamite;
    Texture* plus_1_gemstone;
    Texture* plus_2_gemstone;
    Texture* plus_3_gemstone;
    Texture* minus_1_gemstone;
    Texture* minus_2_gemstone;
    Texture* minus_3_gemstone;

    Texture* floor_environment_falling_stalactite;
    Texture* floor_environment_emerge_water;
    Texture* floor_environment_emerge_pit;
    Texture* floor_environment_emerge_burrow;
    Texture* environment_emerge_pipe;
    Texture* floor_environment_collapse_burrow;

} Textures_Skill;

void load_textures_skill (Renderer* renderer, Textures_Skill* skill);
void destroy_textures_skill (Textures_Skill* skill);

typedef struct
{
    Texture* blow_up_1;
    Texture* blow_up_2;

    Texture* death_1;
    Texture* death_2;

    Texture* drop_1;
    Texture* drop_2;

    Texture* hook_up_start;
    Texture* hook_up_end;
    Texture* hook_up_up;
    Texture* hook_up_right;
    Texture* hook_up_down;
    Texture* hook_up_left;

    Texture* hook_right_start;
    Texture* hook_right_end;
    Texture* hook_right_up;
    Texture* hook_right_right;
    Texture* hook_right_down;
    Texture* hook_right_left;

    Texture* hook_down_start;
    Texture* hook_down_end;
    Texture* hook_down_up;
    Texture* hook_down_right;
    Texture* hook_down_down;
    Texture* hook_down_left;

    Texture* hook_left_start;
    Texture* hook_left_end;
    Texture* hook_left_up;
    Texture* hook_left_right;
    Texture* hook_left_down;
    Texture* hook_left_left;

    Texture* spiderweb_up_start;
    Texture* spiderweb_up_end;
    Texture* spiderweb_up_up;
    Texture* spiderweb_up_right;
    Texture* spiderweb_up_down;
    Texture* spiderweb_up_left;

    Texture* spiderweb_right_start;
    Texture* spiderweb_right_end;
    Texture* spiderweb_right_up;
    Texture* spiderweb_right_right;
    Texture* spiderweb_right_down;
    Texture* spiderweb_right_left;

    Texture* spiderweb_down_start;
    Texture* spiderweb_down_end;
    Texture* spiderweb_down_up;
    Texture* spiderweb_down_right;
    Texture* spiderweb_down_down;
    Texture* spiderweb_down_left;

    Texture* spiderweb_left_start;
    Texture* spiderweb_left_end;
    Texture* spiderweb_left_up;
    Texture* spiderweb_left_right;
    Texture* spiderweb_left_down;
    Texture* spiderweb_left_left;

    Texture* tentacle_up_start;
    Texture* tentacle_up_end;
    Texture* tentacle_up_up;
    Texture* tentacle_up_right;
    Texture* tentacle_up_down;
    Texture* tentacle_up_left;

    Texture* tentacle_right_start;
    Texture* tentacle_right_end;
    Texture* tentacle_right_up;
    Texture* tentacle_right_right;
    Texture* tentacle_right_down;
    Texture* tentacle_right_left;

    Texture* tentacle_down_start;
    Texture* tentacle_down_end;
    Texture* tentacle_down_up;
    Texture* tentacle_down_right;
    Texture* tentacle_down_down;
    Texture* tentacle_down_left;

    Texture* tentacle_left_start;
    Texture* tentacle_left_end;
    Texture* tentacle_left_up;
    Texture* tentacle_left_right;
    Texture* tentacle_left_down;
    Texture* tentacle_left_left;

    Texture* tongue_up_start;
    Texture* tongue_up_end;
    Texture* tongue_up_up;
    Texture* tongue_up_right;
    Texture* tongue_up_down;
    Texture* tongue_up_left;

    Texture* tongue_right_start;
    Texture* tongue_right_end;
    Texture* tongue_right_up;
    Texture* tongue_right_right;
    Texture* tongue_right_down;
    Texture* tongue_right_left;

    Texture* tongue_down_start;
    Texture* tongue_down_end;
    Texture* tongue_down_up;
    Texture* tongue_down_right;
    Texture* tongue_down_down;
    Texture* tongue_down_left;

    Texture* tongue_left_start;
    Texture* tongue_left_end;
    Texture* tongue_left_up;
    Texture* tongue_left_right;
    Texture* tongue_left_down;
    Texture* tongue_left_left;

    Texture* scissor_up_start;
    Texture* scissor_up_end;
    Texture* scissor_up_up;
    Texture* scissor_up_right;
    Texture* scissor_up_down;
    Texture* scissor_up_left;

    Texture* scissor_right_start;
    Texture* scissor_right_end;
    Texture* scissor_right_up;
    Texture* scissor_right_right;
    Texture* scissor_right_down;
    Texture* scissor_right_left;

    Texture* scissor_down_start;
    Texture* scissor_down_end;
    Texture* scissor_down_up;
    Texture* scissor_down_right;
    Texture* scissor_down_down;
    Texture* scissor_down_left;

    Texture* scissor_left_start;
    Texture* scissor_left_end;
    Texture* scissor_left_up;
    Texture* scissor_left_right;
    Texture* scissor_left_down;
    Texture* scissor_left_left;

    Texture* laser_up;
    Texture* laser_right;
    Texture* laser_down;
    Texture* laser_left;
    Texture* laser_vertical;
    Texture* laser_horizontal;

    Texture* cell;
    Texture* dynamite;
    Texture* gemstone;
    Texture* minibot;
    Texture* minibot_enemy;
    Texture* fly_projectile;
    Texture* squirrel_projectile;

} Textures_Animation;

void load_textures_animation (Renderer* renderer, Textures_Animation* animation);
void destroy_textures_animation (Textures_Animation* animation);

typedef struct
{
    Texture* no_augmentation;
    Texture* fist_hand;
    Texture* hook_hand;
    Texture* chain_hand;
    Texture* scissor_hand;
    Texture* spring_leg;
    Texture* strider_leg;
    Texture* track_leg;
    Texture* boot_leg;
    Texture* minibot_torso;
    Texture* wings_torso;
    Texture* manipulation_head;
    Texture* teleportation_head;

    Texture* use;
    Texture* manipulation;
    Texture* teleportation;
    Texture* move;
    Texture* pick_item;
    Texture* put_item_cell;
    Texture* put_item_dynamite;
    Texture* put_item_gemstone;
    Texture* throw_item_cell;
    Texture* throw_item_dynamite;
    Texture* throw_item_gemstone;
    Texture* shoot_projectile;
    Texture* push;
    Texture* throw;
    Texture* pull;
    Texture* drag;
    Texture* jump;
    Texture* charge;
    Texture* stomp;
    Texture* drag_and_throw;
    Texture* charge_and_push;
    Texture* charge_and_throw;
    Texture* charge_and_jump;
    Texture* jump_and_carry;
    Texture* jump_and_stomp;
    Texture* launch_minibot;
    Texture* minibot_merge;
    Texture* turret_laser;
    Texture* turret_bomb;
    Texture* turret_projectile;
    Texture* kill_around;

    Texture* golem;
    Texture* hero;
    Texture* goat;
    Texture* spider;
    Texture* bull;
    Texture* fly;
    Texture* chameleon;
    Texture* squid;
    Texture* mole;
    Texture* mimic;
    Texture* shark;
    Texture* shark_fin;
    Texture* tturret_laser;
    Texture* tturret_bomb;
    Texture* tturret_projectile;
    Texture* squirrel;
    Texture* minibot_ally;
    Texture* minibot_enemy;
    Texture* environment;

    Texture* cell;
    Texture* dynamite;
    Texture* gemstone;

    Texture* end_turn;
    Texture* start_again;
    Texture* start_game;
    Texture* bar_part;

} Textures_Hud;

void load_textures_hud (Renderer* renderer, Textures_Hud* hud);
void destroy_textures_hud (Textures_Hud* hud);

typedef struct
{
    Texture* shadow;

    Textures_Floor floor;
    Textures_Object object;
    Textures_OrderNumber order_number;
    Textures_Skill skill;
    Textures_Animation animation;
    Textures_Hud hud;

} Textures;

void load_textures (Renderer* renderer, Textures* textures);
void destroy_textures (Textures* textures);

Texture* get_texture_throw(Textures* textures, int dir4);
Texture* get_texture_lift(Textures* textures, int dir4);

Texture* get_texture_order_number(Textures* textures, int num);

Texture* get_texture_arrow_thin_start(Textures* textures, int dir4);
Texture* get_texture_arrow_thin_end(Textures* textures, int dir4);
Texture* get_texture_arrow_thin_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_arrow_thick_start(Textures* textures, int dir4);
Texture* get_texture_arrow_thick_end(Textures* textures, int dir4);
Texture* get_texture_arrow_thick_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_item(Textures* textures, int item, int number);

Texture* get_texture_hook_start(Textures* textures, int dir4);
Texture* get_texture_hook_end(Textures* textures, int dir4);
Texture* get_texture_hook_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_spiderweb_start(Textures* textures, int dir4);
Texture* get_texture_spiderweb_end(Textures* textures, int dir4);
Texture* get_texture_spiderweb_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_tentacle_start(Textures* textures, int dir4);
Texture* get_texture_tentacle_end(Textures* textures, int dir4);
Texture* get_texture_tentacle_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_tongue_start(Textures* textures, int dir4);
Texture* get_texture_tongue_end(Textures* textures, int dir4);
Texture* get_texture_tongue_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_scissor_start(Textures* textures, int dir4);
Texture* get_texture_scissor_end(Textures* textures, int dir4);
Texture* get_texture_scissor_from_to(Textures* textures, int dir4_from, int dir4_to);

Texture* get_texture_laser(Textures* textures, int dir4);

#endif
