#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__NONE:                       is = 0; break;
        case SKILL__USE:                        is = 0; break;
        case SKILL__MOVE:                       is = 0; break;

        case SKILL__ATTACK_DIR:                 is = 0; break;
        case SKILL__NO_ATTACK:                  is = 0; break;

        case SKILL__SHOOT_PROJECTILE_FLY:       is = 0; break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:  is = 0; break;

        case SKILL__CHARGE:             is = 0; break;
        case SKILL__JUMP:               is = 0; break;
        case SKILL__BURROW:             is = 0; break;

        case SKILL__CHARGE_AND_JUMP:    is = 1; break;

        case SKILL__PUSH:               is = 1; break;
        case SKILL__PUNCH:              is = 1; break;
        case SKILL__CHARGE_AND_PUNCH:   is = 1; break;
        case SKILL__DRILL:              is = 0; break;
        case SKILL__DRILL_FLOOR:        is = 0; break;

        case SKILL__BRANCHING_BOLT:     is = 0; break;
        case SKILL__STUNNING_BOLT:      is = 0; break;
        case SKILL__COOKING_BOLT:       is = 0; break;
        case SKILL__ELECTRIFY_FLOOR:    is = 0; break;
        
        case SKILL__SCORCH_WITH_FIRE:   is = 0; break;
        case SKILL__SPEW_TAR_BALL:      is = 0; break;
        case SKILL__FIRE_WELD_FLOOR:    is = 0; break;
        case SKILL__ROCKET_JUMP:        is = 0; break;
        case SKILL__ROCKET_DASH:        is = 0; break;
        
        case SKILL__PENETRATING_BEAM:   is = 0; break;
        case SKILL__BOUNCING_BEAM:      is = 1; break;
        case SKILL__FOCUSED_BEAM:       is = 0; break;
        case SKILL__LASER_WELD_FLOOR:   is = 0; break;
        
        case SKILL__ICE_BLOCK:          is = 0; break;
        case SKILL__ICE_WALL:           is = 0; break;
        case SKILL__ICE_PROJECTILE:     is = 0; break;
        case SKILL__FREEZE_FLOOR:       is = 0; break;
        case SKILL__ICE_BUNKER:         is = 0; break;
        
        case SKILL__LONG_SHOT:          is = 0; break;
        case SKILL__POINT_BLANK_SHOT:   is = 0; break;
        case SKILL__HEAD_SHOT:          is = 0; break;
        case SKILL__STUNNING_SHOT:      is = 0; break;
        case SKILL__HARPOON_SHOT:       is = 1; break;
        
        case SKILL__HIGH_PROJECTILE:    is = 0; break;
        case SKILL__DOUBLE_JUMP:        is = 1; break;
        case SKILL__RICOSHET:           is = 1; break;
        case SKILL__NEST:               is = 0; break;
        
        case SKILL__SWING:              is = 1; break;
        case SKILL__NAIL:               is = 0; break;
        case SKILL__JUMP_AND_NAIL:      is = 0; break;
        case SKILL__NAIL_FLOOR:         is = 0; break;
        
        case SKILL__THROW:              is = 1; break;
        case SKILL__JUMP_AND_CARRY:     is = 1; break;
        case SKILL__BURROW_AND_GTFO:    is = 1; break;

        case SKILL__THRUST:             is = 0; break;
        case SKILL__PENETRATING_THRUST: is = 0; break;
        case SKILL__HEAD_SLICE:         is = 0; break;
        case SKILL__BURROW_AND_SLICE:   is = 0; break;
        case SKILL__CHARGE_AND_SLICE:   is = 0; break;

        case SKILL__WHIP_PULL:          is = 1; break;
        case SKILL__BURY:               is = 1; break;
        case SKILL__WHIP_SMACK:         is = 0; break;

        case SKILL__LAUNCH_MINIBOT:     is = 0; break;
        case SKILL__MINIBOT_MERGE:      is = 0; break;

        case SKILL__CHARGE_AND_THROW:   is = 1; break;
        case SKILL__DRAG:               is = 1; break;
        case SKILL__PULL:               is = 0; break;
        case SKILL__PUSH_DAMAGE:        is = 1; break;
        case SKILL__THROW_DAMAGE:       is = 1; break;
        case SKILL__DRAG_DAMAGE:        is = 1; break;
        case SKILL__JUMP_DAMAGE_AROUND: is = 0; break;
        case SKILL__CHARGE_AND_DAMAGE_3:is = 0; break;
        case SKILL__DAMAGE_1:           is = 0; break;
        case SKILL__DAMAGE_3:           is = 0; break;
        case SKILL__PROJECTILE_LINE_1:  is = 0; break;
        case SKILL__PROJECTILE_ARCH_1:  is = 0; break;
        case SKILL__PROJECTILE_LINE_AROUND:     is = 0; break;
        case SKILL__LAUNCH_MINIBOT_MEGASPIDER:  is = 0; break;

        default: break;
    }

    return is;
}

int get_skill_action_points(int skill)
{
    int ap = 0;

    // all skills cost now 1 ap
    ap = 1;

    return ap;
}

char* get_in_game_skill_name(int skill)
{
    char* name = "???";

    switch(skill)
    {
        case SKILL__NONE:               name = "--"; break;
        case SKILL__USE:                name = "use"; break;
        case SKILL__MOVE:               name = "move"; break;

        case SKILL__ATTACK_DIR:         name = "---"; break;
        case SKILL__NO_ATTACK:          name = "no attack"; break;

        case SKILL__CHARGE:             name = "charge"; break;
        case SKILL__JUMP:               name = "jump"; break;
        case SKILL__BURROW:             name = "burrow"; break;

        case SKILL__CHARGE_AND_JUMP:    name = "charge and jump"; break;

        case SKILL__PUSH:               name = "push"; break;
        case SKILL__PUNCH:              name = "punch"; break;
        case SKILL__CHARGE_AND_PUNCH:   name = "charge and punch"; break;
        case SKILL__DRILL:              name = "drill"; break;
        case SKILL__DRILL_FLOOR:        name = "drill floor"; break;

        case SKILL__BRANCHING_BOLT:     name = "branching bolt"; break;
        case SKILL__STUNNING_BOLT:      name = "stunning bolt"; break;
        case SKILL__COOKING_BOLT:       name = "cooking bolt"; break;
        case SKILL__ELECTRIFY_FLOOR:    name = "electrify floor"; break;
        
        case SKILL__SCORCH_WITH_FIRE:   name = "scorch with fire"; break;
        case SKILL__SPEW_TAR_BALL:      name = "spew tar ball"; break;
        case SKILL__FIRE_WELD_FLOOR:    name = "fire weld floor"; break;
        case SKILL__ROCKET_JUMP:        name = "rocket jump"; break;
        case SKILL__ROCKET_DASH:        name = "rocket dash"; break;
        
        case SKILL__PENETRATING_BEAM:   name = "penetrating beam"; break;
        case SKILL__BOUNCING_BEAM:      name = "bouncing beam"; break;
        case SKILL__FOCUSED_BEAM:       name = "focused beam"; break;
        case SKILL__LASER_WELD_FLOOR:   name = "laser weld floor"; break;
        
        case SKILL__ICE_BLOCK:          name = "ice block"; break;
        case SKILL__ICE_WALL:           name = "ice wall"; break;
        case SKILL__ICE_PROJECTILE:     name = "ice projectile"; break;
        case SKILL__FREEZE_FLOOR:       name = "freeze floor"; break;
        case SKILL__ICE_BUNKER:         name = "ice bunker"; break;
        
        case SKILL__LONG_SHOT:          name = "long shot"; break;
        case SKILL__POINT_BLANK_SHOT:   name = "point blank shot"; break;
        case SKILL__HEAD_SHOT:          name = "head shot"; break;
        case SKILL__STUNNING_SHOT:      name = "stunning shot"; break;
        case SKILL__HARPOON_SHOT:       name = "harpoon shot"; break;
        
        case SKILL__HIGH_PROJECTILE:    name = "high projectile"; break;
        case SKILL__DOUBLE_JUMP:        name = "double jump"; break;
        case SKILL__RICOSHET:           name = "ricoshet"; break;
        case SKILL__NEST:               name = "nest"; break;
        
        case SKILL__SWING:              name = "swing"; break;
        case SKILL__NAIL:               name = "nail"; break;
        case SKILL__JUMP_AND_NAIL:      name = "jump and nail"; break;
        case SKILL__NAIL_FLOOR:         name = "nail floor"; break;
        
        case SKILL__THROW:              name = "throw"; break;
        case SKILL__JUMP_AND_CARRY:     name = "jump and carry"; break;
        case SKILL__BURROW_AND_GTFO:    name = "burrow and gtfo"; break;

        case SKILL__THRUST:             name = "thrust"; break;
        case SKILL__PENETRATING_THRUST: name = "penetring thrust"; break;
        case SKILL__HEAD_SLICE:         name = "head slice"; break;
        case SKILL__BURROW_AND_SLICE:   name = "burrow and slice"; break;
        case SKILL__CHARGE_AND_SLICE:   name = "charge and slice"; break;

        case SKILL__WHIP_PULL:          name = "whip pull"; break;
        case SKILL__BURY:               name = "bury"; break;
        case SKILL__WHIP_SMACK:         name = "whip smack"; break;

        case SKILL__LAUNCH_MINIBOT:     name = "launch minibot"; break;
        case SKILL__MINIBOT_MERGE:      name = "minibot merge"; break;

        case SKILL__CHARGE_AND_THROW:   name = "charge and throw"; break;
        case SKILL__DRAG:               name = "drag"; break;
        case SKILL__PULL:               name = "pull"; break;
        case SKILL__PUSH_DAMAGE:        name = "push"; break;
        case SKILL__THROW_DAMAGE:       name = "throw"; break;
        case SKILL__DRAG_DAMAGE:        name = "drag"; break;
        case SKILL__JUMP_DAMAGE_AROUND: name = "jump"; break;
        case SKILL__DAMAGE_1:           name = "damage"; break;
        case SKILL__DAMAGE_3:           name = "damage"; break;
        case SKILL__CHARGE_AND_DAMAGE_3:name = "charge"; break;
        case SKILL__PROJECTILE_LINE_1:  name = "projectile line"; break;
        case SKILL__PROJECTILE_ARCH_1:  name = "projectile arch"; break;
        case SKILL__PROJECTILE_LINE_AROUND:     name = "projectile line around"; break;
        case SKILL__LAUNCH_MINIBOT_MEGASPIDER:  name = "launch minibot megaspider"; break;

        default: break;
    }

    return name;
}

char* get_debug_skill_name(int skill)
{
    char* name = "???";

    switch(skill)
    {
        case SKILL__NONE:               name = "none"; break;
        case SKILL__USE:                name = "use"; break;
        case SKILL__MOVE:               name = "move"; break;

        case SKILL__ATTACK_DIR:         name = "attack dir"; break;
        case SKILL__NO_ATTACK:          name = "no attack"; break;

        case SKILL__CHARGE:             name = "charge"; break;
        case SKILL__JUMP:               name = "jump"; break;
        case SKILL__BURROW:             name = "burrow"; break;

        case SKILL__CHARGE_AND_JUMP:    name = "charge and jump"; break;

        case SKILL__PUSH:               name = "push"; break;
        case SKILL__PUNCH:              name = "punch"; break;
        case SKILL__CHARGE_AND_PUNCH:   name = "charge and punch"; break;
        case SKILL__DRILL:              name = "drill"; break;
        case SKILL__DRILL_FLOOR:        name = "drill floor"; break;

        case SKILL__BRANCHING_BOLT:     name = "branching bolt"; break;
        case SKILL__STUNNING_BOLT:      name = "stunning bolt"; break;
        case SKILL__COOKING_BOLT:       name = "cooking bolt"; break;
        case SKILL__ELECTRIFY_FLOOR:    name = "electrify floor"; break;
        
        case SKILL__SCORCH_WITH_FIRE:   name = "scorch with fire"; break;
        case SKILL__SPEW_TAR_BALL:      name = "spew tar ball"; break;
        case SKILL__FIRE_WELD_FLOOR:    name = "fire weld floor"; break;
        case SKILL__ROCKET_JUMP:        name = "rocket jump"; break;
        case SKILL__ROCKET_DASH:        name = "rocket dash"; break;
        
        case SKILL__PENETRATING_BEAM:   name = "penetrating beam"; break;
        case SKILL__BOUNCING_BEAM:      name = "bouncing beam"; break;
        case SKILL__FOCUSED_BEAM:       name = "focused beam"; break;
        case SKILL__LASER_WELD_FLOOR:   name = "laser weld floor"; break;
        
        case SKILL__ICE_BLOCK:          name = "ice block"; break;
        case SKILL__ICE_WALL:           name = "ice wall"; break;
        case SKILL__ICE_PROJECTILE:     name = "ice projectile"; break;
        case SKILL__FREEZE_FLOOR:       name = "freeze floor"; break;
        case SKILL__ICE_BUNKER:         name = "ice bunker"; break;
        
        case SKILL__LONG_SHOT:          name = "long shot"; break;
        case SKILL__POINT_BLANK_SHOT:   name = "point blank shot"; break;
        case SKILL__HEAD_SHOT:          name = "head shot"; break;
        case SKILL__STUNNING_SHOT:      name = "stunning shot"; break;
        case SKILL__HARPOON_SHOT:       name = "harpoon shot"; break;
        
        case SKILL__HIGH_PROJECTILE:    name = "high projectile"; break;
        case SKILL__DOUBLE_JUMP:        name = "double jump"; break;
        case SKILL__RICOSHET:           name = "ricoshet"; break;
        case SKILL__NEST:               name = "nest"; break;
        
        case SKILL__SWING:              name = "swing"; break;
        case SKILL__NAIL:               name = "nail"; break;
        case SKILL__JUMP_AND_NAIL:      name = "jump and nail"; break;
        case SKILL__NAIL_FLOOR:         name = "nail floor"; break;
        
        case SKILL__THROW:              name = "throw"; break;
        case SKILL__JUMP_AND_CARRY:     name = "jump and carry"; break;
        case SKILL__BURROW_AND_GTFO:    name = "burrow and gtfo"; break;

        case SKILL__THRUST:             name = "thrust"; break;
        case SKILL__PENETRATING_THRUST: name = "penetring thrust"; break;
        case SKILL__HEAD_SLICE:         name = "head slice"; break;
        case SKILL__BURROW_AND_SLICE:   name = "burrow and slice"; break;
        case SKILL__CHARGE_AND_SLICE:   name = "charge and slice"; break;

        case SKILL__WHIP_PULL:          name = "whip pull"; break;
        case SKILL__BURY:               name = "bury"; break;
        case SKILL__WHIP_SMACK:         name = "whip smack"; break;

        case SKILL__LAUNCH_MINIBOT:     name = "launch minibot"; break;
        case SKILL__MINIBOT_MERGE:      name = "minibot merge"; break;

        case SKILL__CHARGE_AND_THROW:   name = "charge and throw"; break;
        case SKILL__DRAG:               name = "drag"; break;
        case SKILL__PULL:               name = "pull"; break;
        case SKILL__PUSH_DAMAGE:        name = "push damage"; break;
        case SKILL__THROW_DAMAGE:       name = "throw damage"; break;
        case SKILL__DRAG_DAMAGE:        name = "drag damage"; break;
        case SKILL__JUMP_DAMAGE_AROUND: name = "jump damage around"; break;
        case SKILL__DAMAGE_1:           name = "damage 1"; break;
        case SKILL__DAMAGE_3:           name = "damage 3"; break;
        case SKILL__CHARGE_AND_DAMAGE_3:name = "charge damage 3"; break;
        case SKILL__PROJECTILE_LINE_1:  name = "projectile line 1"; break;
        case SKILL__PROJECTILE_ARCH_1:  name = "projectile arch 1"; break;
        case SKILL__PROJECTILE_LINE_AROUND:     name = "projectile line around"; break;
        case SKILL__LAUNCH_MINIBOT_MEGASPIDER:  name = "launch minibot megaspider"; break;

        default: break;
    }

    return name;
}

char* get_description_from_skill(int skill, int i)
{
    char* description = "";

    return description;
}

Texture* get_skill_hud_texture(int skill, Textures* textures)
{
    Texture* texture = NULL;

    switch(skill)
    {
        case SKILL__NONE:               texture = textures->hud.skill_none; break;
        case SKILL__USE:                texture = textures->hud.skill_use; break;
        case SKILL__MOVE:               texture = textures->hud.skill_move; break;

        case SKILL__CHARGE:             texture = textures->hud.skill_charge; break;
        case SKILL__JUMP:               texture = textures->hud.skill_jump; break;
        case SKILL__BURROW:             texture = textures->hud.skill_burrow; break;

        case SKILL__CHARGE_AND_JUMP:    texture = textures->hud.skill_charge_and_jump; break;

        case SKILL__PUSH:               texture = textures->hud.skill_push; break;
        case SKILL__PUNCH:              texture = textures->hud.skill_punch; break;
        case SKILL__CHARGE_AND_PUNCH:   texture = textures->hud.skill_charge_and_punch; break;
        case SKILL__DRILL:              texture = textures->hud.skill_drill; break;
        case SKILL__DRILL_FLOOR:        texture = textures->hud.skill_drill_floor; break;

        case SKILL__BRANCHING_BOLT:     texture = textures->hud.skill_branching_bolt; break;
        case SKILL__STUNNING_BOLT:      texture = textures->hud.skill_stunning_bolt; break;
        case SKILL__COOKING_BOLT:       texture = textures->hud.skill_cooking_bolt; break;
        case SKILL__ELECTRIFY_FLOOR:    texture = textures->hud.skill_electrify_floor; break;
        
        case SKILL__SCORCH_WITH_FIRE:   texture = textures->hud.skill_scorch_with_fire; break;
        case SKILL__SPEW_TAR_BALL:      texture = textures->hud.skill_spew_tar_ball; break;
        case SKILL__FIRE_WELD_FLOOR:    texture = textures->hud.skill_fire_weld_floor; break;
        case SKILL__ROCKET_JUMP:        texture = textures->hud.skill_rocket_jump; break;
        case SKILL__ROCKET_DASH:        texture = textures->hud.skill_rocket_dash; break;
        
        case SKILL__PENETRATING_BEAM:   texture = textures->hud.skill_penetrating_beam; break;
        case SKILL__BOUNCING_BEAM:      texture = textures->hud.skill_bouncing_beam; break;
        case SKILL__FOCUSED_BEAM:       texture = textures->hud.skill_focused_beam; break;
        case SKILL__LASER_WELD_FLOOR:   texture = textures->hud.skill_laser_weld_floor; break;
        
        case SKILL__ICE_BLOCK:          texture = textures->hud.skill_ice_block; break;
        case SKILL__ICE_WALL:           texture = textures->hud.skill_ice_wall; break;
        case SKILL__ICE_PROJECTILE:     texture = textures->hud.skill_ice_projectile; break;
        case SKILL__FREEZE_FLOOR:       texture = textures->hud.skill_freeze_water; break;
        case SKILL__ICE_BUNKER:         texture = textures->hud.skill_ice_bunker; break;
        
        case SKILL__LONG_SHOT:          texture = textures->hud.skill_long_shot; break;
        case SKILL__POINT_BLANK_SHOT:   texture = textures->hud.skill_point_black_shot; break;
        case SKILL__HEAD_SHOT:          texture = textures->hud.skill_head_shot; break;
        case SKILL__STUNNING_SHOT:      texture = textures->hud.skill_stunning_shot; break;
        case SKILL__HARPOON_SHOT:       texture = textures->hud.skill_harpoon_shot; break;
        
        case SKILL__HIGH_PROJECTILE:    texture = textures->hud.skill_high_projectile; break;
        case SKILL__DOUBLE_JUMP:        texture = textures->hud.skill_double_jump; break;
        case SKILL__RICOSHET:           texture = textures->hud.skill_ricoshet; break;
        case SKILL__NEST:               texture = textures->hud.skill_launch_nest; break;
        
        case SKILL__SWING:              texture = textures->hud.skill_swing; break;
        case SKILL__NAIL:               texture = textures->hud.skill_nail; break;
        case SKILL__JUMP_AND_NAIL:      texture = textures->hud.skill_jump_and_nail; break;
        case SKILL__NAIL_FLOOR:         texture = textures->hud.skill_nail_floor; break;
        
        case SKILL__THROW:              texture = textures->hud.skill_throw; break;
        case SKILL__JUMP_AND_CARRY:     texture = textures->hud.skill_jump_and_carry; break;
        case SKILL__BURROW_AND_GTFO:    texture = textures->hud.skill_burrow_and_gtfo; break;

        case SKILL__THRUST:             texture = textures->hud.skill_thrust; break;
        case SKILL__PENETRATING_THRUST: texture = textures->hud.skill_penetrating_thrust; break;
        case SKILL__HEAD_SLICE:         texture = textures->hud.skill_head_slice; break;
        case SKILL__BURROW_AND_SLICE:   texture = textures->hud.skill_burrow_and_slice; break;
        case SKILL__CHARGE_AND_SLICE:   texture = textures->hud.skill_charge_and_slice; break;

        case SKILL__WHIP_PULL:          texture = textures->hud.skill_whip_pull; break;
        case SKILL__BURY:               texture = textures->hud.skill_bury; break;
        case SKILL__WHIP_SMACK:         texture = textures->hud.skill_whip_smack; break;

        case SKILL__LAUNCH_MINIBOT:     texture = textures->hud.skill_launch_minibot; break;
        case SKILL__MINIBOT_MERGE:      texture = textures->hud.skill_minibot_merge; break;

        case SKILL__CHARGE_AND_THROW:   texture = textures->hud.skill_charge_and_throw; break;
        case SKILL__DRAG:               texture = textures->hud.skill_drag; break;
        case SKILL__PULL:               texture = textures->hud.skill_pull; break;
        case SKILL__PUSH_DAMAGE:        texture = textures->hud.skill_push_damage; break;
        case SKILL__THROW_DAMAGE:       texture = textures->hud.skill_throw_damage; break;
        case SKILL__DRAG_DAMAGE:        texture = textures->hud.skill_drag_damage; break;
        case SKILL__JUMP_DAMAGE_AROUND: texture = textures->hud.skill_jump_and_stomp; break;
        case SKILL__DAMAGE_1:           texture = textures->hud.skill_damage_1; break;
        case SKILL__DAMAGE_3:           texture = textures->hud.skill_damage_3; break;
        case SKILL__CHARGE_AND_DAMAGE_3:texture = textures->hud.skill_charge_damage_3; break;
        case SKILL__PROJECTILE_LINE_1:  texture = textures->hud.skill_long_shot; break;
        case SKILL__PROJECTILE_ARCH_1:  texture = textures->hud.skill_high_projectile; break;
        case SKILL__PROJECTILE_LINE_AROUND:     texture = textures->hud.skill_kill_around; break;
        case SKILL__LAUNCH_MINIBOT_MEGASPIDER:  texture = textures->hud.skill_launch_minibot; break;

        default: break;
    }

    return texture;
}
