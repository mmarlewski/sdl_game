#include "../inc/state.h"

void floor_on_move_start(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR_TYPE__ROCK_CRACK_LAVA:
        {
            change_floor_in_tilemap_pos(state, FLOOR_TYPE__LAVA, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR_TYPE__ICE_CRACK_WATER:
        {
            change_floor_in_tilemap_pos(state, FLOOR_TYPE__WATER, action->move.object->tilemap_pos);
        }
        break;
        default:
        break;
    }
}

void floor_on_move_end(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR_TYPE__STONE_SPIKES_ON:
        {
            if(!is_object_flying(action->move.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, new_action_death(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        case FLOOR_TYPE__LAVA:
        {
            if(!is_object_flying(action->move.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        case FLOOR_TYPE__ICE:
        {
            if(!is_object_flying(action->move.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_move( vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
            }
        }
        break;
        case FLOOR_TYPE__ICE_CRACK_WATER:
        {
            if(!is_object_flying(action->move.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_move( vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
            }
        }
        break;
        case FLOOR_TYPE__WATER:
        {
            if(!is_object_flying(action->move.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:
        {
            if(!is_object_flying(action->move.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            }
        }
        break;
        default:
        break;
    }
}

void floor_on_drop(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR_TYPE__METAL:
        {
            if(action->drop.object->type == OBJECT_TYPE__WEIGHT)
            {
                change_floor_in_tilemap_pos(state, FLOOR_TYPE__ROCK_CRACK_LAVA, action->tilemap_pos);
            }
        }
        break;
        case FLOOR_TYPE__ROCK_CRACK_LAVA:
        {
            if(!is_object_flying(action->drop.object))
            {
                change_floor_in_tilemap_pos(state, FLOOR_TYPE__LAVA, action->tilemap_pos);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__LAVA:
        {
            if(!is_object_flying(action->drop.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__ICE:
        {
            if(!is_object_flying(action->drop.object))
            {
                if(action->drop.object->type == OBJECT_TYPE__WEIGHT)
                {
                    change_floor_in_tilemap_pos(state, FLOOR_TYPE__ICE_CRACK_WATER, action->tilemap_pos);
                }
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_move(action->tilemap_pos, action->drop.dir4));
            }
        }
        break;
        case FLOOR_TYPE__ICE_CRACK_WATER:
        {
            if(!is_object_flying(action->drop.object))
            {
                change_floor_in_tilemap_pos(state, FLOOR_TYPE__WATER, action->tilemap_pos);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__WATER:
        {
            if(!is_object_flying(action->drop.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:
        {
            if(!is_object_flying(action->drop.object))
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(sequence, new_action_fall(action->drop.object, action->tilemap_pos));
            }
        }
        break;
        default:
        break;
    }
}

void floor_on_interact(State* state, Action* sequence, int floor, Vec2i tilemap_pos)
{
    switch(floor)
    {
        case FLOOR_TYPE__METAL_PISTON:
        {
            Object* object_piston = new_object(OBJECT_TYPE__PISTON);
            object_piston->tilemap_pos = tilemap_pos;
            add_action_to_end_action_sequence(sequence,new_action_add_object(object_piston, tilemap_pos));
        }
        break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR_TYPE__STONE_SPIKES_ON, tilemap_pos));
        }
        break;
        case FLOOR_TYPE__STONE_SPIKES_ON:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR_TYPE__STONE_SPIKES_OFF, tilemap_pos));
        }
        break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR_TYPE__METAL_HATCH_OPEN, tilemap_pos));
        }
        break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR_TYPE__METAL_HATCH_CLOSED, tilemap_pos));
        }
        break;
        default:
        break;
    }
}

Animation* floor_on_interact_get_animation(State* state, int floor, Vec2i tilemap_pos, Textures* textures)
{
    Animation* animation = new_animation_none();

    switch(floor)
    {
        case FLOOR_TYPE__METAL_PISTON:
        {
            animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.piston_1,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.piston_2,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );
        }
        break;
        case FLOOR_TYPE__STONE_SPIKES_OFF:
        {
            animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.stone_spikes_1,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.stone_spikes_2,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );
        }
        break;
        case FLOOR_TYPE__STONE_SPIKES_ON:
        {
            animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.stone_spikes_2,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.stone_spikes_1,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );
        }
        break;
        case FLOOR_TYPE__METAL_HATCH_CLOSED:
        {
            animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.metal_hatch_2,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.metal_hatch_1,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );
        }
        break;
        case FLOOR_TYPE__METAL_HATCH_OPEN:
        {
            animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.metal_hatch_1,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.metal_hatch_2,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );
        }
        break;
        default:
        break;
    }

    return animation;
}

void object_on_crashing(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__BALL_SPIKES:
        {
            if(action->crash.object_crushed->type != OBJECT_TYPE__BARREL)
            {
                add_action_to_end_action_sequence(sequence, new_action_death(action->crash.object_crushed, action->crash.object_crushed->tilemap_pos));
            }
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        default:
        break;
    }
}

void object_on_crashed(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__BALL_SPIKES:
        {
            if(action->crash.object_crushed->type != OBJECT_TYPE__BARREL)
            {
                add_action_to_end_action_sequence(sequence, new_action_death(action->crash.object_crushing, action->crash.object_crushed->tilemap_pos));
            }
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BALL:
        {
            add_action_to_end_action_sequence(sequence, new_action_move(object->tilemap_pos, action->crash.dir4));
        }
        break;
        default:
        break;
    }
}

void object_on_death(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_blow_up(object->tilemap_pos));
        }
        break;
        default:
        break;
    }
}

void object_on_drop(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PILLAR:
        {
            //
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BALL:
        {
            if(action->drop.dir4 != DIR4__NONE)
            {
                add_action_to_end_action_sequence(sequence, new_action_move( action->tilemap_pos, action->drop.dir4));
            }
        }
        break;
        case OBJECT_TYPE__BALL_SPIKES:
        {
            if(action->drop.dir4 != DIR4__NONE)
            {
                add_action_to_end_action_sequence(sequence, new_action_move( action->tilemap_pos, action->drop.dir4));
            }
        }
        break;
        default:
        break;
    }
}

void object_on_interact(State* state, Action* sequence, Object* object, Vec2i tilemap_pos)
{
    switch(object->type)
    {
        case OBJECT_TYPE__PISTON:
        {
            add_action_to_end_action_sequence(sequence,new_action_remove_object(object, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BALL:
        {
            add_action_to_end_action_sequence(sequence,new_action_change_object(OBJECT_TYPE__BALL_SPIKES, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BALL_SPIKES:
        {
            add_action_to_end_action_sequence(sequence,new_action_change_object(OBJECT_TYPE__BALL, object->tilemap_pos));
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        default:
        break;
    }
}

Animation* object_on_interact_get_animation(State* state, Object* object, Vec2i tilemap_pos, Textures* textures)
{
    Animation* animation = new_animation_none();

    switch(object->type)
    {
        case OBJECT_TYPE__PISTON:
        {
            animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.piston_2,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.piston_1,
                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );
        }
        break;
        case OBJECT_TYPE__BALL:
        {
        }
        break;
        case OBJECT_TYPE__BALL_SPIKES:
        {
        }
        break;
        case OBJECT_TYPE__BARREL:
        {
        }
        break;
        default:
        break;
    }

    return animation;
}
