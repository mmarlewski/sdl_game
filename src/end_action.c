#include "../inc/state.h"

void end_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("end action:         %s \n", get_action_name_from_type(action->type));

    if(action->is_finished_at_start) return;

    switch(action->type)
    {
        case ACTION__NONE:
        {
            //
        }
        break;
        case ACTION__SEQUENCE:
        {
            remove_all_list_elements(action->sequence.action_list, 1);
            action->sequence.curr_action_list_elem = 0;
        }
        break;
        case ACTION__SIMULTANEOUS:
        {
            remove_all_list_elements(action->simultaneous.action_list, 1);
        }
        break;
        case ACTION__MOVE:
        case ACTION__MOVE_FLOATING:
        case ACTION__MOVE_FLYING:
        {
            action->move.object->tilemap_pos = vec2i_move_in_dir4_by(action->move.object->tilemap_pos, action->move.dir4, 1);

            int floor = room_get_floor_at(state->curr_room, action->move.object->tilemap_pos);

            if(action->type == ACTION__MOVE)
            {
                floor_on_move_end(state, sequence, action, floor);
            }
            else if(action->type == ACTION__MOVE_FLOATING)
            {
                floor_on_move_floating_end(state, sequence, action, floor);
            }
            else if(action->type == ACTION__MOVE_FLYING)
            {
                floor_on_move_flying_end(state, sequence, action, floor);
            }

            action->move.object->is_visible = 1;
        }
        break;
        case ACTION__CRASH:
        {
            Action* crushed_action_sequence = new_action_sequence();
            Object* crushed_object = room_get_object_at(state->curr_room, vec2i_move_in_dir4_by(action->crash.object_crushing->tilemap_pos, action->crash.dir4, 1));
            if(crushed_object != 0)
            {
                object_on_crashed(state, crushed_action_sequence, action, crushed_object);
            }

            Action* crushing_action_sequence = new_action_sequence();
            Object* crushing_object = action->crash.object_crushing;
            if(crushing_object != 0)
            {
                object_on_crashing(state, crushing_action_sequence, action, crushing_object);
            }

            add_action_after_curr_action_action_sequence(sequence, new_action_simultaneous_of_2(crushed_action_sequence, crushing_action_sequence));

            action->crash.object_crushing->is_visible = 1;
        }
        break;
        case ACTION__FALL:
        {
            add_action_after_curr_action_action_sequence(sequence, new_action_death(action->fall.object, action->tilemap_pos));

            action->fall.object->is_visible = 0;
        }
        break;
        case ACTION__DEATH:
        {
            object_on_death(state, sequence, action, action->death.object);

            action->death.object->is_to_be_removed = 1;
        }
        break;
        case ACTION__BLOW_UP:
        {
            Action* push_around = new_action_simultaneous();

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                    action->tilemap_pos,
                    dir4,
                    1
                );
                Object* object = room_get_object_at(
                    state->curr_room,
                    tilemap_pos
                );

                if(object != 0 && is_object_movable(object))
                {
                    if(is_object_flying(object))
                    {
                        add_action_sequence_to_action_simultaneous(
                            push_around,
                            new_action_sequence_of_1(
                                new_action_move_flying(
                                    tilemap_pos,
                                    dir4
                                )
                            )
                        );
                    }
                    else if(is_object_floating(object))
                    {
                        add_action_sequence_to_action_simultaneous(
                            push_around,
                            new_action_sequence_of_1(
                                new_action_move_floating(
                                    tilemap_pos,
                                    dir4
                                )
                            )
                        );
                    }
                    else
                    {
                        add_action_sequence_to_action_simultaneous(
                            push_around,
                            new_action_sequence_of_1(
                                new_action_move(
                                    tilemap_pos,
                                    dir4
                                )
                            )
                        );
                    }
                }
            }

            add_action_after_curr_action_action_sequence(
                sequence,
                push_around
            );
        }
        break;
        case ACTION__THROW:
        {
            Vec2i curr_tilemap_pos = action->throw.object_thrown->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, action->throw.dir4, action->throw.distance);

            action->throw.object_thrown->tilemap_pos = next_tilemap_pos;

            add_action_after_curr_action_action_sequence(sequence, new_action_drop(action->throw.object_thrown, next_tilemap_pos, action->throw.dir4));

            action->throw.object_thrown->is_visible = 1;
        }
        break;
        case ACTION__LIFT:
        {
            add_action_after_curr_action_action_sequence(sequence, new_action_drop(action->throw.object_thrown, action->tilemap_pos, action->throw.dir4));

            action->throw.object_thrown->is_visible = 1;
        }
        break;
        case ACTION__DROP:
        {
            object_on_drop(state, sequence, action, action->drop.object);

            int floor = room_get_floor_at(state->curr_room, action->drop.object->tilemap_pos);

            if(!is_object_floating(action->drop.object) &&
               !is_object_flying(action->drop.object))
            {
                floor_on_drop(state, sequence, action, floor);
            }
            else if(is_object_floating(action->drop.object))
            {
                floor_on_drop_floating(state, sequence, action, floor);
            }
            else if(is_object_flying(action->drop.object))
            {
                floor_on_drop_flying(state, sequence, action, floor);
            }
        }
        break;
        case ACTION__CHANGE_FLOOR:
        {
            //
        }
        break;
        case ACTION__CHANGE_OBJECT:
        {
            //
        }
        break;
        case ACTION__ADD_OBJECT:
        {
            //
        }
        break;
        case ACTION__REMOVE_OBJECT:
        {
            if(action->remove_object.object_to_remove != 0)
            {
                action->remove_object.object_to_remove->is_to_be_removed = 1;
            }
        }
        break;
        case ACTION__CHANGE_OBJECT_TILEMAP_POS:
        {
            if(action->change_object_tilemap_pos.object != 0)
            {
                action->change_object_tilemap_pos.object->tilemap_pos =
                    action->change_object_tilemap_pos.new_tilemap_pos;
            }
        }
        break;
        case ACTION__MELT:
        {
            //
        }
        break;
        case ACTION__BREAK:
        {
            //
        }
        break;
        case ACTION__SHAKE:
        {
            //
        }
        break;
        default:
        break;
    }
}
