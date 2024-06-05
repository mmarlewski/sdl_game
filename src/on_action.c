#include "../inc/state.h"

void floor_on_move_start(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__METAL_TARGET_CHECKED:
        {
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_TARGET_UNCHECKED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_WATER:
        {
            room_change_floor_at(state->curr_room, FLOOR__WATER, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            room_change_floor_at(state->curr_room, FLOOR__LAVA, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            room_change_floor_at(state->curr_room, FLOOR__PIT, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            room_change_floor_at(state->curr_room, FLOOR__WATER, action->move.object->tilemap_pos);
        }
        break;
        default:
        break;
    }
}

void floor_on_move_floating_start(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__METAL_TARGET_CHECKED:
        {
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_TARGET_UNCHECKED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_WATER:
        {
            room_change_floor_at(state->curr_room, FLOOR__WATER, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            room_change_floor_at(state->curr_room, FLOOR__LAVA, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            room_change_floor_at(state->curr_room, FLOOR__PIT, action->move.object->tilemap_pos);
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            room_change_floor_at(state->curr_room, FLOOR__WATER, action->move.object->tilemap_pos);
        }
        break;
        default:
        break;
    }
}

void floor_on_move_flying_start(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        default:
        break;
    }
}

void floor_on_move_end(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__METAL_TARGET_UNCHECKED:
        {
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_TARGET_CHECKED,
                    vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)
                )
            );
        }
        break;
        case FLOOR__METAL_SPIKES_ON:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));

        }
        break;
        case FLOOR__STONE_TRAP:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            add_action_after_curr_action_action_sequence(sequence, new_action_change_floor(FLOOR__STONE, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
        }
        break;
        case FLOOR__ICE:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(sequence, new_action_move(vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(sequence, new_action_move(vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
        }
        break;
        case FLOOR__WATER:
        {
            if(action->move.object->type == OBJECT__COLUMN)
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_remove_object(
                        action->move.object,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__WATER_COLUMN,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
            }
            else
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_fall(
                        action->move.object,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
            }
        }
        break;
        case FLOOR__LAVA:
        {
            if(action->move.object->type == OBJECT__COLUMN)
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_remove_object(
                        action->move.object,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__LAVA_COLUMN,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
            }
            else
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_fall(
                        action->move.object,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
            }
        }
        break;
        case FLOOR__METAL_HATCH_OPEN:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->move.object,
                    vec2i_move_in_dir4_by(
                        action->tilemap_pos,
                        action->move.dir4,
                        1
                    )
                )
            );
        }
        break;
        case FLOOR__PIT:
        {
            if(action->move.object->type == OBJECT__COLUMN)
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_remove_object(
                        action->move.object,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__PIT_COLUMN,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
            }
            else
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_fall(
                        action->move.object,
                        vec2i_move_in_dir4_by(
                            action->tilemap_pos,
                            action->move.dir4,
                            1
                        )
                    )
                );
            }
        }
        break;
        default:
        break;
    }
}

void floor_on_move_floating_end(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__METAL_TARGET_UNCHECKED:
        {
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_TARGET_CHECKED,
                    vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)
                )
            );
        }
        break;
        case FLOOR__METAL_SPIKES_ON:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
        }
        break;
        case FLOOR__STONE_TRAP:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->move.object, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
            add_action_after_curr_action_action_sequence(sequence, new_action_change_floor(FLOOR__STONE, vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)));
        }
        break;
        case FLOOR__ICE:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(sequence, new_action_move(vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(sequence, new_action_move(vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1), action->move.dir4));
        }
        break;
        case FLOOR__PIT:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->move.object,
                    vec2i_move_in_dir4_by(
                        action->tilemap_pos,
                        action->move.dir4,
                        1
                    )
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_move_flying_end(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        default:
        break;
    }
}

void floor_on_drop(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__METAL_TARGET_UNCHECKED:
        {
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_TARGET_CHECKED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_SPIKES_ON:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_death(
                    action->move.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__STONE_TRAP:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_death(
                    action->move.object,
                    action->tilemap_pos
                )
            );
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_WATER:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            room_change_floor_at(
                state->curr_room,
                FLOOR__WATER,
                action->tilemap_pos
            );
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->drop.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            room_change_floor_at(
                state->curr_room,
                FLOOR__LAVA,
                action->tilemap_pos
            );
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->drop.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            room_change_floor_at(
                state->curr_room,
                FLOOR__PIT,
                action->tilemap_pos
            );
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->drop.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ICE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_move(
                    action->tilemap_pos,
                    action->drop.dir4
                )
            );
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            room_change_floor_at(
                state->curr_room,
                FLOOR__WATER,
                action->tilemap_pos
            );
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->drop.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__WATER:
        {
            if(action->drop.object->type == OBJECT__COLUMN)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_remove_object(
                        action->drop.object,
                        action->tilemap_pos
                    )
                );
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__WATER_COLUMN,
                        action->tilemap_pos
                    )
                );
            }
            else
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_fall(
                        action->drop.object,
                        action->tilemap_pos
                    )
                );
            }
        }
        break;
        case FLOOR__LAVA:
        {
            if(action->drop.object->type == OBJECT__COLUMN)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_remove_object(
                        action->drop.object,
                        action->tilemap_pos
                    )
                );
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__LAVA_COLUMN,
                        action->tilemap_pos
                    )
                );
            }
            else
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_fall(
                        action->drop.object,
                        action->tilemap_pos
                    )
                );
            }
        }
        break;
        case FLOOR__PIT:
        {
            if(action->drop.object->type == OBJECT__COLUMN)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_remove_object(
                        action->drop.object,
                        action->tilemap_pos
                    )
                );
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__PIT_COLUMN,
                        action->tilemap_pos
                    )
                );
            }
            else
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_fall(
                        action->drop.object,
                        action->tilemap_pos
                    )
                );
            }
        }
        break;
        default:
        break;
    }
}

void floor_on_drop_floating(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__METAL_TARGET_UNCHECKED:
        {
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_TARGET_CHECKED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_SPIKES_ON:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_death(
                    action->move.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__STONE_TRAP:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_death(
                    action->move.object,
                    action->tilemap_pos
                )
            );
            add_action_after_curr_action_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_WATER:
        {
            room_change_floor_at(
                state->curr_room,
                FLOOR__WATER,
                action->tilemap_pos
            );
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            room_change_floor_at(
                state->curr_room,
                FLOOR__LAVA,
                action->tilemap_pos
            );
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            remove_all_actions_after_curr_action_action_sequence(sequence);
            room_change_floor_at(
                state->curr_room,
                FLOOR__PIT,
                action->tilemap_pos
            );
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->drop.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ICE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_move(
                    action->tilemap_pos,
                    action->drop.dir4
                )
            );
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_move(
                    action->tilemap_pos,
                    action->drop.dir4
                )
            );
        }
        break;
        case FLOOR__PIT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_fall(
                    action->drop.object,
                    action->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_drop_flying(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        default:
        break;
    }
}

void floor_on_melt(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__STONE_TRAP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE,
                    action->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_break(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__ROCK_CRACK_WATER:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__WATER,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__LAVA,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__PIT,
                    action->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_shake(State* state, Action* sequence, Action* action, int floor)
{
    switch(floor)
    {
        case FLOOR__ROCK_CRACK_WATER:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__WATER,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__LAVA,
                    action->tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__PIT,
                    action->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_stomp(State* state, Action* sequence, int floor, Vec2i tilemap_pos)
{
    switch(floor)
    {
        case FLOOR__STONE_STAIRS_BELOW_BLOCKED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE_STAIRS_BELOW,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__WATER_LILY_POD:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__WATER,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__STONE_TRAP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ICE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__ICE_CRACK_WATER,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ICE_CRACK_WATER:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__WATER,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_WATER:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__WATER,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_LAVA:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__LAVA,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__ROCK_CRACK_PIT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__PIT,
                    tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_manipulation(State* state, Action* sequence, int floor, Vec2i tilemap_pos)
{
    switch(floor)
    {
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL,
                    tilemap_pos
                )
            );

            int left_go_on = TRUE;
            int right_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__LEFT,
                    i
                );
                int left_floor = room_get_floor_at(
                    state->curr_room,
                    left_tilemap_pos
                );
                if(left_floor == FLOOR__LAVA && left_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__EXT_BRIDGE_PART_HORIZONTAL,
                            left_tilemap_pos
                        )
                    );
                }
                if(left_floor != FLOOR__LAVA)
                {
                    left_go_on = FALSE;
                }

                Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__RIGHT,
                    i
                );
                int right_floor = room_get_floor_at(
                    state->curr_room,
                    right_tilemap_pos
                );
                if(right_floor == FLOOR__LAVA && right_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__EXT_BRIDGE_PART_HORIZONTAL,
                            right_tilemap_pos
                        )
                    );
                }
                if(right_floor != FLOOR__LAVA)
                {
                    right_go_on = FALSE;
                }
            }
        }
        break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_HORIZONTAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__EXT_BRIDGE_SOURCE_OFF_HORIZONTAL,
                    tilemap_pos
                )
            );

            int left_go_on = TRUE;
            int right_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__LEFT,
                    i
                );
                int left_floor = room_get_floor_at(
                    state->curr_room,
                    left_tilemap_pos
                );
                if(left_floor == FLOOR__EXT_BRIDGE_PART_HORIZONTAL &&
                   left_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__LAVA,
                            left_tilemap_pos
                        )
                    );
                }
                if(left_floor != FLOOR__EXT_BRIDGE_PART_HORIZONTAL)
                {
                    left_go_on = FALSE;
                }

                Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__RIGHT,
                    i
                );
                int right_floor = room_get_floor_at(
                    state->curr_room,
                    right_tilemap_pos
                );
                if(right_floor == FLOOR__EXT_BRIDGE_PART_HORIZONTAL &&
                   right_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__LAVA,
                            right_tilemap_pos
                        )
                    );
                }
                if(right_floor != FLOOR__EXT_BRIDGE_PART_HORIZONTAL)
                {
                    right_go_on = FALSE;
                }
            }
        }
        break;
        case FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL,
                    tilemap_pos
                )
            );

            int up_go_on = TRUE;
            int down_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__UP,
                    i
                );
                int up_floor = room_get_floor_at(
                    state->curr_room,
                    up_tilemap_pos
                );
                if(up_floor == FLOOR__LAVA && up_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__EXT_BRIDGE_PART_VERTICAL,
                            up_tilemap_pos
                        )
                    );
                }
                if(up_floor != FLOOR__LAVA)
                {
                    up_go_on = FALSE;
                }

                Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__DOWN,
                    i
                );
                int down_floor = room_get_floor_at(
                    state->curr_room,
                    down_tilemap_pos
                );
                if(down_floor == FLOOR__LAVA && down_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__EXT_BRIDGE_PART_VERTICAL,
                            down_tilemap_pos
                        )
                    );
                }
                if(down_floor != FLOOR__LAVA)
                {
                    down_go_on = FALSE;
                }
            }
        }
        break;
        case FLOOR__EXT_BRIDGE_SOURCE_ON_VERTICAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL,
                    tilemap_pos
                )
            );

            int up_go_on = TRUE;
            int down_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__UP,
                    i
                );
                int up_floor = room_get_floor_at(
                    state->curr_room,
                    up_tilemap_pos
                );
                if(up_floor == FLOOR__EXT_BRIDGE_PART_VERTICAL &&
                   up_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__LAVA,
                            up_tilemap_pos
                        )
                    );
                }
                if(up_floor != FLOOR__EXT_BRIDGE_PART_VERTICAL)
                {
                    up_go_on = FALSE;
                }

                Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(
                    tilemap_pos,
                    DIR4__DOWN,
                    i
                );
                int down_floor = room_get_floor_at(
                    state->curr_room,
                    down_tilemap_pos
                );
                if(down_floor == FLOOR__EXT_BRIDGE_PART_VERTICAL &&
                   down_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__LAVA,
                            down_tilemap_pos
                        )
                    );
                }
                if(down_floor != FLOOR__EXT_BRIDGE_PART_VERTICAL)
                {
                    down_go_on = FALSE;
                }
            }
        }
        break;
        case FLOOR__METAL_PISTON:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_add_object(
                    new_object(OBJECT__PISTON),
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_PISTON_CELL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_add_object(
                    new_object(OBJECT__PISTON_CELL),
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_PISTON_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_add_object(
                    new_object(OBJECT__PISTON_DYNAMITE),
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_add_object(
                    new_object(OBJECT__PISTON_BARREL),
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_PISTON_MIMIC:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_NO_PISTON,
                    tilemap_pos
                )
            );
            add_action_to_end_action_sequence(
                sequence,
                new_action_add_object(
                    new_object(OBJECT__MIMIC),
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_SPIKES_OFF:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR__METAL_SPIKES_ON, tilemap_pos));
        }
        break;
        case FLOOR__METAL_SPIKES_ON:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR__METAL_SPIKES_OFF, tilemap_pos));
        }
        break;
        case FLOOR__METAL_HATCH_CLOSED:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR__METAL_HATCH_OPEN, tilemap_pos));
        }
        break;
        case FLOOR__METAL_HATCH_OPEN:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_floor(FLOOR__METAL_HATCH_CLOSED, tilemap_pos));
        }
        break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_add_object(
                    new_object(OBJECT__STAIRS_ABOVE_METAL_ON),
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_STAIRS_BELOW_OFF:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_STAIRS_BELOW_ON,
                    tilemap_pos
                )
            );
        }
        break;
        case FLOOR__METAL_STAIRS_BELOW_ON:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_STAIRS_BELOW_OFF,
                    tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

Animation* floor_on_manipulation_get_animation(State* state, int floor, Vec2i tilemap_pos, Textures* textures)
{
    Animation* animation = new_animation_none();

    switch(floor)
    {
        case FLOOR__METAL_PISTON:
        {
            //
        }
        break;
        case FLOOR__METAL_SPIKES_OFF:
        {
            //
        }
        break;
        case FLOOR__METAL_SPIKES_ON:
        {
            //
        }
        break;
        case FLOOR__METAL_HATCH_CLOSED:
        {
            //
        }
        break;
        case FLOOR__METAL_HATCH_OPEN:
        {
            //
        }
        break;
        case FLOOR__METAL_STAIRS_ABOVE_OFF:
        {
            //
        }
        break;
        default:
        break;
    }

    return animation;
}

void floor_on_pick_item(State* state, Action* sequence, int floor, Vec2i tilemap_pos)
{
    switch(floor)
    {
        case FLOOR__STONE_STAIRS_ABOVE_POWERED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE_STAIRS_ABOVE_UNPOWERED,
                    tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void floor_on_put_item(State* state, Action* sequence, int floor, Vec2i tilemap_pos, int item_type)
{
    switch(floor)
    {
        case FLOOR__STONE_STAIRS_ABOVE_UNPOWERED:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_floor(
                        FLOOR__STONE_STAIRS_ABOVE_POWERED,
                        tilemap_pos
                    )
                );

                add_action_to_end_action_sequence(
                    sequence,
                    new_action_add_object(
                        new_object(OBJECT__STAIRS_ABOVE_STONE_POWERED),
                        tilemap_pos
                    )
                );
            }
        }
        break;
        default:
        break;
    }
}

void object_on_crashing(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT__DISPLAY:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__DISPLAY_DAMAGED_ITEM,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__BALL_SPIKES:
        {
            if(action->crash.object_crushed->type != OBJECT__BARREL &&
               action->crash.object_crushed->type != OBJECT__PISTON_BARREL &&
               !is_object_wall(action->crash.object_crushed) &&
               !is_object_exit(action->crash.object_crushed))
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_death(
                        action->crash.object_crushed,
                        action->crash.object_crushed->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_NO_PISTON,
                    object->tilemap_pos
                )
            );
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
        case OBJECT__STALACTITE:
        {
            int floor = room_get_floor_at(
                state->curr_room,
                object->tilemap_pos
            );

            switch(floor)
            {
                case FLOOR__WATER:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__WATER_STALACTITE_FALLEN,
                            object->tilemap_pos
                        )
                    );

                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            object,
                            object->tilemap_pos
                        )
                    );
                }
                break;
                case FLOOR__LAVA:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__LAVA_STALACTITE_FALLEN,
                            object->tilemap_pos
                        )
                    );

                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            object,
                            object->tilemap_pos
                        )
                    );
                }
                break;
                case FLOOR__PIT:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            object,
                            object->tilemap_pos
                        )
                    );
                }
                break;
                default:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_object(
                            OBJECT__STALACTITE_FALLEN_ITEM,
                            object->tilemap_pos
                        )
                    );
                }
                break;
            }
        }
        break;
        case OBJECT__BALL:
        {
            for(int i = 0; i < 5; i++)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_move(
                        vec2i_move_in_dir4_by(
                            object->tilemap_pos,
                            action->crash.dir4,
                            i
                        ),
                        action->crash.dir4
                    )
                );
            }
        }
        break;
        case OBJECT__BALL_SPIKES:
        {
            if(action->crash.object_crushed->type != OBJECT__BARREL &&
               action->crash.object_crushed->type != OBJECT__BARREL &&
               !is_object_wall(action->crash.object_crushed) &&
               !is_object_exit(action->crash.object_crushed))
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_death(
                        action->crash.object_crushing,
                        action->crash.object_crushed->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__DISPLAY:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__DISPLAY_DAMAGED_ITEM,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_NO_PISTON,
                    object->tilemap_pos
                )
            );
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
        case OBJECT__PILLAR:
        {
            //
        }
        break;
        case OBJECT__BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_blow_up(
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_blow_up(
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_NO_PISTON,
                    object->tilemap_pos
                )
            );
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
        case OBJECT__DISPLAY:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(OBJECT__DISPLAY_DAMAGED_ITEM, object->tilemap_pos)
            );
        }
        break;
        case OBJECT__BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_NO_PISTON,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__BALL:
        case OBJECT__BALL_SPIKES:
        {
            if(action->drop.dir4 != DIR4__NONE)
            {
                for(int i = 0; i < 5; i++)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_move(
                            vec2i_move_in_dir4_by(
                                action->tilemap_pos,
                                action->drop.dir4,
                                i
                            ),
                            action->drop.dir4
                        )
                    );
                }
            }
        }
        break;
        case OBJECT__TURRET_LASER_DEPLOYED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__TURRET_LASER_UNDEPLOYED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__TURRET_BOMB_DEPLOYED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__TURRET_BOMB_UNDEPLOYED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__TURRET_PROJECTILE_DEPLOYED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__TURRET_PROJECTILE_UNDEPLOYED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__TURRET_LASER_UNDEPLOYED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__TURRET_LASER_DEPLOYED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__TURRET_BOMB_UNDEPLOYED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__TURRET_BOMB_DEPLOYED,
                    action->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__TURRET_PROJECTILE_UNDEPLOYED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__TURRET_PROJECTILE_DEPLOYED,
                    action->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void object_on_melt(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_OBSIDIAN_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_BLOCKED_UP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_UP,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_BLOCKED_RIGHT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_RIGHT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_BLOCKED_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__SAFE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(OBJECT__SAFE_DAMAGED_ITEM, object->tilemap_pos)
            );
        }
        break;
        case OBJECT__VENDING_CELL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_CELL_DAMAGED_ITEM,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_CELL_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_CELL_DAMAGED_ITEM,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_DYNAMITE_DAMAGED_ITEM,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_DYNAMITE_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_DYNAMITE_DAMAGED_ITEM,
                    object->tilemap_pos
                )
            );
        }
        break;
        default:
        {
            if(is_object_meltable(object))
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_death(object, object->tilemap_pos)
                );
            }
        }
        break;
    }
}

void object_on_break(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT__EXIT_STONE_BLOCKED_LEFT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_LEFT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_ROCK_BLOCKED_UP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_ROCK_UP,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_ROCK_BLOCKED_RIGHT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_ROCK_RIGHT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_ROCK_BLOCKED_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_ROCK_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__ROCK:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(OBJECT__ROCK_DAMAGED_ITEM, object->tilemap_pos)
            );
        }
        break;
        default:
        {
            if(is_object_breakable(object))
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_death(object, object->tilemap_pos)
                );
            }
        }
        break;
    }
}

void object_on_shake(State* state, Action* sequence, Action* action, Object* object)
{
    switch(object->type)
    {
        case OBJECT__EXIT_ROCK_BLOCKED_LEFT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_ROCK_LEFT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_BLOCKED_UP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_UP,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_BLOCKED_RIGHT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_RIGHT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_BLOCKED_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_BLOCKED_LEFT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_LEFT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__DISPLAY:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(OBJECT__DISPLAY_DAMAGED_ITEM, object->tilemap_pos)
            );
        }
        break;
        case OBJECT__BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_NO_PISTON,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__STALACTITE:
        {
            int floor = room_get_floor_at(state->curr_room, action->tilemap_pos);

            switch(floor)
            {
                case FLOOR__WATER:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__WATER_STALACTITE_FALLEN,
                            object->tilemap_pos
                        )
                    );

                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            object,
                            object->tilemap_pos
                        )
                    );
                }
                break;
                case FLOOR__LAVA:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_floor(
                            FLOOR__LAVA_STALACTITE_FALLEN,
                            object->tilemap_pos
                        )
                    );

                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            object,
                            object->tilemap_pos
                        )
                    );
                }
                break;
                case FLOOR__PIT:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            object,
                            object->tilemap_pos
                        )
                    );
                }
                break;
                default:
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_change_object(
                            OBJECT__STALACTITE_FALLEN_ITEM,
                            object->tilemap_pos
                        )
                    );
                }
                break;
            }
        }
        break;
        default:
        break;
    }
}

void object_on_stomp(State* state, Action* sequence, Object* object, Vec2i tilemap_pos)
{
    switch(object->type)
    {
        case OBJECT__MINIBOT_ALLY:
        case OBJECT__MINIBOT_ALLY_CELL:
        case OBJECT__MINIBOT_ALLY_DYNAMITE:
        case OBJECT__MINIBOT_ALLY_GEMSTONE:
        case OBJECT__MINIBOT_ENEMY:
        case OBJECT__MINIBOT_ENEMY_CELL:
        case OBJECT__MINIBOT_ENEMY_DYNAMITE:
        case OBJECT__MINIBOT_ENEMY_GEMSTONE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_death(
                    object,
                    object->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void object_on_manipulate(State* state, Action* sequence, Object* object, Vec2i tilemap_pos)
{
    switch(object->type)
    {
        case OBJECT__HARPOON_GUN_UP:
        case OBJECT__HARPOON_GUN_RIGHT:
        case OBJECT__HARPOON_GUN_DOWN:
        case OBJECT__HARPOON_GUN_LEFT:
        {
            Vec2i source_tilemap_pos = object->tilemap_pos;
            Vec2i target_tilemap_pos = object->tilemap_pos;

            int dir4 = DIR4__NONE;
            switch(object->type)
            {
                case OBJECT__HARPOON_GUN_UP: dir4 = DIR4__UP; break;
                case OBJECT__HARPOON_GUN_RIGHT: dir4 = DIR4__RIGHT; break;
                case OBJECT__HARPOON_GUN_DOWN: dir4 = DIR4__DOWN; break;
                case OBJECT__HARPOON_GUN_LEFT: dir4 = DIR4__LEFT; break;
                default: break;
            }

            int target_go_on = TRUE;
            for(int i = 1; i < 10 && target_go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    i
                );

                Object* object = room_get_object_at(
                    state->curr_room,
                    tilemap_pos
                );

                if(object != NULL)
                {
                    target_go_on = FALSE;
                    target_tilemap_pos = tilemap_pos;
                }
            }

            Object* target_object = room_get_object_at(
                state->curr_room,
                target_tilemap_pos
            );

            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_tilemap_pos,
                    source_tilemap_pos
                );

            if(distance_info.dir4 != DIR4__NONE)
            {
                Vec2i prev_tilemap_pos = target_tilemap_pos;
                Vec2i curr_tilemap_pos = target_tilemap_pos;
                Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(
                    curr_tilemap_pos,
                    distance_info.dir4,
                    1
                );

                Object* prev_object = room_get_object_at(
                    state->curr_room,
                    prev_tilemap_pos
                );
                Object* curr_object = room_get_object_at(
                    state->curr_room,
                    curr_tilemap_pos
                );
                Object* next_object = room_get_object_at(
                    state->curr_room,
                    next_tilemap_pos
                );

                int prev_floor = room_get_floor_at(
                    state->curr_room,
                    prev_tilemap_pos
                );
                int curr_floor = room_get_floor_at(
                    state->curr_room,
                    curr_tilemap_pos
                );
                int next_floor = room_get_floor_at(
                    state->curr_room,
                    next_tilemap_pos
                );

                for(int i = 0; i < distance_info.abs_diff + 1; i++)
                {
                    // if pos before source_pos
                    if(!vec2i_equals(curr_tilemap_pos, source_tilemap_pos))
                    {
                        Vec2i just_before_source_tilemap_pos =
                            vec2i_move_in_dir4_by(
                                source_tilemap_pos,
                                get_opposite_dir4(distance_info.dir4),
                                1
                            );
                        // if pos just before source_pos
                        if(vec2i_equals(curr_tilemap_pos, just_before_source_tilemap_pos))
                        {
                            if(!is_object_floating(target_object) &&
                               !is_object_flying(target_object))
                            {
                                add_action_to_end_action_sequence(
                                    sequence,
                                    new_action_move(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                            else if(is_object_floating(target_object))
                            {
                                add_action_to_end_action_sequence(
                                    sequence,
                                    new_action_move_floating(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                            else if(is_object_flying(target_object))
                            {
                                add_action_to_end_action_sequence(
                                    sequence,
                                    new_action_move_flying(
                                        curr_tilemap_pos,
                                        distance_info.dir4
                                    )
                                );
                            }
                        }
                        else
                        {
                            add_action_to_end_action_sequence(
                                sequence,
                                new_action_move_flying(
                                    curr_tilemap_pos,
                                    distance_info.dir4
                                )
                            );
                        }
                    }

                    prev_tilemap_pos = curr_tilemap_pos;
                    curr_tilemap_pos = next_tilemap_pos;
                    next_tilemap_pos = vec2i_move_in_dir4_by(
                        curr_tilemap_pos,
                        distance_info.dir4,
                        1
                    );

                    prev_object = room_get_object_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    curr_object = room_get_object_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    next_object = room_get_object_at(
                        state->curr_room,
                        next_tilemap_pos
                    );

                    prev_floor = room_get_floor_at(
                        state->curr_room,
                        prev_tilemap_pos
                    );
                    curr_floor = room_get_floor_at(
                        state->curr_room,
                        curr_tilemap_pos
                    );
                    next_floor = room_get_floor_at(
                        state->curr_room,
                        next_tilemap_pos
                    );
                }
            }
        }
        break;
        case OBJECT__EXT_WALL_SOURCE_OFF_HORIZONTAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXT_WALL_SOURCE_ON_HORIZONTAL,
                    object->tilemap_pos
                )
            );

            int left_go_on = TRUE;
            int right_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__LEFT,
                    i
                );
                Object* left_object = room_get_object_at(
                    state->curr_room,
                    left_tilemap_pos
                );
                if(left_object == NULL && left_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_add_object(
                            new_object(OBJECT__EXT_WALL_PART_HORIZONTAL),
                            left_tilemap_pos
                        )
                    );
                }
                if(left_object != NULL)
                {
                    left_go_on = FALSE;
                }

                Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__RIGHT,
                    i
                );
                Object* right_object = room_get_object_at(
                    state->curr_room,
                    right_tilemap_pos
                );
                if(right_object == NULL && right_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_add_object(
                            new_object(OBJECT__EXT_WALL_PART_HORIZONTAL),
                            right_tilemap_pos
                        )
                    );
                }
                if(right_object != NULL)
                {
                    right_go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__EXT_WALL_SOURCE_ON_HORIZONTAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXT_WALL_SOURCE_OFF_HORIZONTAL,
                    object->tilemap_pos
                )
            );

            int left_go_on = TRUE;
            int right_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i left_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__LEFT,
                    i
                );
                Object* left_object = room_get_object_at(
                    state->curr_room,
                    left_tilemap_pos
                );
                if(left_object != NULL &&
                   left_object->type == OBJECT__EXT_WALL_PART_HORIZONTAL &&
                   left_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            left_object,
                            left_tilemap_pos
                        )
                    );
                }
                if(left_object != NULL &&
                   left_object->type != OBJECT__EXT_WALL_PART_HORIZONTAL)
                {
                    left_go_on = FALSE;
                }

                Vec2i right_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__RIGHT,
                    i
                );
                Object* right_object = room_get_object_at(
                    state->curr_room,
                    right_tilemap_pos
                );
                if(right_object != NULL &&
                   right_object->type == OBJECT__EXT_WALL_PART_HORIZONTAL &&
                   right_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            right_object,
                            right_tilemap_pos
                        )
                    );
                }
                if(right_object != NULL &&
                   right_object->type != OBJECT__EXT_WALL_PART_HORIZONTAL)
                {
                    right_go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__EXT_WALL_SOURCE_OFF_VERTICAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXT_WALL_SOURCE_ON_VERTICAL,
                    object->tilemap_pos
                )
            );

            int up_go_on = TRUE;
            int down_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__UP,
                    i
                );
                Object* up_object = room_get_object_at(
                    state->curr_room,
                    up_tilemap_pos
                );
                if(up_object == NULL && up_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_add_object(
                            new_object(OBJECT__EXT_WALL_PART_VERTICAL),
                            up_tilemap_pos
                        )
                    );
                }
                if(up_object != NULL)
                {
                    up_go_on = FALSE;
                }

                Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__DOWN,
                    i
                );
                Object* down_object = room_get_object_at(
                    state->curr_room,
                    down_tilemap_pos
                );
                if(down_object == NULL && down_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_add_object(
                            new_object(OBJECT__EXT_WALL_PART_VERTICAL),
                            down_tilemap_pos
                        )
                    );
                }
                if(down_object != NULL)
                {
                    down_go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__EXT_WALL_SOURCE_ON_VERTICAL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXT_WALL_SOURCE_OFF_VERTICAL,
                    object->tilemap_pos
                )
            );

            int up_go_on = TRUE;
            int down_go_on = TRUE;
            for(int i = 1; i < 10; i++)
            {
                Vec2i up_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__UP,
                    i
                );
                Object* up_object = room_get_object_at(
                    state->curr_room,
                    up_tilemap_pos
                );
                if(up_object != NULL &&
                   up_object->type == OBJECT__EXT_WALL_PART_VERTICAL &&
                   up_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            up_object,
                            up_tilemap_pos
                        )
                    );
                }
                if(up_object != NULL &&
                   up_object->type != OBJECT__EXT_WALL_PART_VERTICAL)
                {
                    up_go_on = FALSE;
                }

                Vec2i down_tilemap_pos = vec2i_move_in_dir4_by(
                    object->tilemap_pos,
                    DIR4__DOWN,
                    i
                );
                Object* down_object = room_get_object_at(
                    state->curr_room,
                    down_tilemap_pos
                );
                if(down_object != NULL &&
                   down_object->type == OBJECT__EXT_WALL_PART_VERTICAL &&
                   down_go_on)
                {
                    add_action_to_end_action_sequence(
                        sequence,
                        new_action_remove_object(
                            down_object,
                            down_tilemap_pos
                        )
                    );
                }
                if(down_object != NULL &&
                   down_object->type != OBJECT__EXT_WALL_PART_VERTICAL)
                {
                    down_go_on = FALSE;
                }
            }
        }
        break;
        case OBJECT__LEVER_METAL_ON:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__LEVER_METAL_OFF,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_ON_UP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_OFF_UP,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_ON_RIGHT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_OFF_RIGHT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_ON_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_OFF_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_ON_LEFT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_OFF_LEFT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_OFF_UP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_ON_UP,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_OFF_RIGHT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_ON_RIGHT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_OFF_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_ON_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_METAL_OFF_LEFT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_METAL_ON_LEFT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_remove_object(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_PISTON,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_CELL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_remove_object(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_PISTON_CELL,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_remove_object(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_PISTON_DYNAMITE,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_BARREL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_remove_object(
                    object,
                    object->tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__METAL_PISTON_BARREL,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__BALL:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_object(OBJECT__BALL_SPIKES, object->tilemap_pos));
        }
        break;
        case OBJECT__BALL_SPIKES:
        {
            add_action_to_end_action_sequence(sequence, new_action_change_object(OBJECT__BALL, object->tilemap_pos));
        }
        break;
        case OBJECT__BARREL:
        {
            add_action_to_end_action_sequence(sequence, new_action_death(object, object->tilemap_pos));
        }
        break;
        case OBJECT__STAIRS_ABOVE_METAL_ON:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_remove_object(
                    object,
                    tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

Animation* object_on_manipulate_get_animation(State* state, Object* object, Vec2i tilemap_pos, Textures* textures)
{
    Animation* animation = new_animation_none();

    switch(object->type)
    {
        case OBJECT__HARPOON_GUN_UP:
        case OBJECT__HARPOON_GUN_RIGHT:
        case OBJECT__HARPOON_GUN_DOWN:
        case OBJECT__HARPOON_GUN_LEFT:
        {
            Vec2i source_tilemap_pos = object->tilemap_pos;
            Vec2i target_tilemap_pos = object->tilemap_pos;

            int dir4 = DIR4__NONE;
            switch(object->type)
            {
                case OBJECT__HARPOON_GUN_UP: dir4 = DIR4__UP; break;
                case OBJECT__HARPOON_GUN_RIGHT: dir4 = DIR4__RIGHT; break;
                case OBJECT__HARPOON_GUN_DOWN: dir4 = DIR4__DOWN; break;
                case OBJECT__HARPOON_GUN_LEFT: dir4 = DIR4__LEFT; break;
                default: break;
            }

            int go_on = TRUE;
            for(int i = 1; i < 10 && go_on; i++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    dir4,
                    i
                );

                Object* object = room_get_object_at(
                    state->curr_room,
                    tilemap_pos
                );

                if(object != NULL)
                {
                    go_on = FALSE;
                    target_tilemap_pos = tilemap_pos;
                }
            }

            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_tilemap_pos
                );

            Animation* animation_sequence = new_animation_sequence();

            for(int i = 0; i < distance_info.abs_diff + 1; i++)
            {
                Animation* animation_simultaneous = new_animation_simultaneous();
                Vec2i tilemap_pos = source_tilemap_pos;
                float show_sprite_length_in_seconds = 0.1f;

                for(int j = 0; j <= i; j++)
                {
                    if(vec2i_equals(tilemap_pos, source_tilemap_pos))
                    {
                        Texture* texture = get_texture_hook_start(textures, distance_info.dir4);

                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                texture,
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                            )
                        );
                    }
                    else if(vec2i_equals(tilemap_pos, target_tilemap_pos))
                    {
                        Texture* texture = get_texture_hook_end(textures, get_opposite_dir4(distance_info.dir4));

                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                texture,
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                            )
                        );
                    }
                    else
                    {
                        Texture* texture = get_texture_hook_from_to(textures, get_opposite_dir4(distance_info.dir4), distance_info.dir4);

                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                texture,
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                            )
                        );
                    }

                    tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, distance_info.dir4, 1);
                }

                add_animation_to_end_animation_sequence(
                    animation_sequence,
                    animation_simultaneous
                );
            }

            animation = animation_sequence;
        }
        break;
        default:
        break;
    }

    return animation;
}

void object_on_pick_item(State* state, Action* sequence, Object* object, Vec2i tilemap_pos)
{
    switch(object->type)
    {
        case OBJECT__GOLEM_POWERED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__GOLEM_HALF_POWERED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__GOLEM_HALF_POWERED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__GOLEM_UNPOWERED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__LEVER_STONE_POWERED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__LEVER_STONE_UNPOWERED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__MINIBOT_ALLY_CELL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__MINIBOT_ALLY,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__MINIBOT_ALLY_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__MINIBOT_ALLY,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__MINIBOT_ALLY_GEMSTONE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__MINIBOT_ALLY,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__MINIBOT_ENEMY_CELL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__MINIBOT_ENEMY,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__MINIBOT_ENEMY_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__MINIBOT_ENEMY,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__MINIBOT_ENEMY_GEMSTONE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__MINIBOT_ENEMY,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_POWERED_UP:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_UNPOWERED_UP,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_POWERED_RIGHT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_UNPOWERED_RIGHT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_POWERED_DOWN:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_UNPOWERED_DOWN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__EXIT_STONE_POWERED_LEFT:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__EXIT_STONE_UNPOWERED_LEFT,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__CRATE_CELL_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__CRATE_CELL,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__CRATE_DYNAMITE_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__CRATE_DYNAMITE,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__CRATE_GEMSTONE_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__CRATE_GEMSTONE,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__STALACTITE_FALLEN_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__STALACTITE_FALLEN,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__ROCK_DAMAGED_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__ROCK_DAMAGED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__SAFE_DAMAGED_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__SAFE_DAMAGED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__DISPLAY_DAMAGED_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__DISPLAY_DAMAGED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_CELL_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_CELL,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_CELL_DAMAGED_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_CELL_DAMAGED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_DYNAMITE_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_DYNAMITE,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__VENDING_DYNAMITE_DAMAGED_ITEM:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__VENDING_DYNAMITE_DAMAGED,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__STAIRS_ABOVE_STONE_POWERED:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_floor(
                    FLOOR__STONE_STAIRS_ABOVE_UNPOWERED,
                    tilemap_pos
                )
            );

            add_action_to_end_action_sequence(
                sequence,
                new_action_remove_object(
                    object,
                    tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_CELL:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__PISTON,
                    object->tilemap_pos
                )
            );
        }
        break;
        case OBJECT__PISTON_DYNAMITE:
        {
            add_action_to_end_action_sequence(
                sequence,
                new_action_change_object(
                    OBJECT__PISTON,
                    object->tilemap_pos
                )
            );
        }
        break;
        default:
        break;
    }
}

void object_on_put_item(State* state, Action* sequence, Object* object, Vec2i tilemap_pos, int item_type)
{
    switch(object->type)
    {
        case OBJECT__GOLEM_UNPOWERED:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__GOLEM_HALF_POWERED,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__GOLEM_HALF_POWERED:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__GOLEM_POWERED,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__LEVER_STONE_UNPOWERED:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__LEVER_STONE_POWERED,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__MINIBOT_ALLY:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__MINIBOT_ALLY_CELL,
                        object->tilemap_pos
                    )
                );
            }
            if(item_type == ITEM__DYNAMITE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__MINIBOT_ALLY_DYNAMITE,
                        object->tilemap_pos
                    )
                );
            }
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__MINIBOT_ALLY_GEMSTONE,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__MINIBOT_ENEMY:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__MINIBOT_ENEMY_CELL,
                        object->tilemap_pos
                    )
                );
            }
            if(item_type == ITEM__DYNAMITE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__MINIBOT_ENEMY_DYNAMITE,
                        object->tilemap_pos
                    )
                );
            }
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__MINIBOT_ENEMY_GEMSTONE,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_STONE_UNPOWERED_UP:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_STONE_POWERED_UP,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_STONE_UNPOWERED_RIGHT:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_STONE_POWERED_RIGHT,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_STONE_UNPOWERED_DOWN:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_STONE_POWERED_DOWN,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_STONE_UNPOWERED_LEFT:
        {
            if(item_type == ITEM__CELL)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_STONE_POWERED_LEFT,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_GOLD_LOCKED_UP:
        {
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_GOLD_UNLOCKED_UP,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_GOLD_LOCKED_RIGHT:
        {
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_GOLD_UNLOCKED_RIGHT,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_GOLD_LOCKED_DOWN:
        {
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_GOLD_UNLOCKED_DOWN,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__EXIT_GOLD_LOCKED_LEFT:
        {
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__EXIT_GOLD_UNLOCKED_LEFT,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__VENDING_CELL:
        {
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__VENDING_CELL_ITEM,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        case OBJECT__VENDING_DYNAMITE:
        {
            if(item_type == ITEM__GEMSTONE)
            {
                add_action_to_end_action_sequence(
                    sequence,
                    new_action_change_object(
                        OBJECT__VENDING_DYNAMITE_ITEM,
                        object->tilemap_pos
                    )
                );
            }
        }
        break;
        default:
        break;
    }
}
