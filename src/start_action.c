#include "../inc/state.h"

void start_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("start action:       %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION__NONE:
        {
            //
        }
        break;
        case ACTION__SEQUENCE:
        {
            ListElem* curr_elem = action->sequence.action_list->head;
            action->sequence.curr_action_list_elem = curr_elem;

            if(curr_elem != NULL)
            {
                Action* curr_action = (Action*) curr_elem->data;
                start_action(state, action, curr_action, textures, sounds, musics, colors);
            }
            else
            {
                action->is_finished = TRUE;
            }
        }
        break;
        case ACTION__SIMULTANEOUS:
        {
            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                if(curr_elem)
                {
                    Action* curr_action = (Action*) curr_elem->data;
                    start_action(state, curr_action, curr_action, textures, sounds, musics, colors);
                }
            }
        }
        break;
        case ACTION__MOVE:
        case ACTION__MOVE_FLOATING:
        case ACTION__MOVE_FLYING:
        {
            if(action->type == ACTION__MOVE)
            {
                play_sound(sounds->move);
            }
            else if(action->type == ACTION__MOVE_FLOATING)
            {
                play_sound(sounds->move_floating);
            }
            else if(action->type == ACTION__MOVE_FLYING)
            {
                play_sound(sounds->move_flying);
            }

            action->move.object = room_get_object_at(state->curr_room, action->tilemap_pos);

            if(action->move.object == NULL ||
               !is_tilemap_in_bounds(vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)))
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->move.object->tilemap_pos = action->tilemap_pos;

            Vec2i curr_tilemap_pos = action->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, action->move.dir4, 1);
            Object* object_on_next_tilemap_pos = room_get_object_at(state->curr_room, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash(action->tilemap_pos, action->move.dir4);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, crash);

                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
            }
            else
            {
                Animation* animation = new_animation_move_sprite_in_gamemap_in_line(
                    get_texture_1_from_object(action->move.object, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS
                );
                action->animation = animation;
                add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);

                int floor = room_get_floor_at(state->curr_room, action->move.object->tilemap_pos);

                if(action->type == ACTION__MOVE)
                {
                    floor_on_move_start(state, sounds, sequence, action, floor);
                }
                else if(action->type == ACTION__MOVE_FLOATING)
                {
                    floor_on_move_floating_start(state, sounds, sequence, action, floor);
                }
                else if(action->type == ACTION__MOVE_FLYING)
                {
                    floor_on_move_flying_start(state, sounds, sequence, action, floor);
                }

                action->move.object->is_visible = FALSE;
            }
        }
        break;
        case ACTION__CRASH:
        {
            play_sound(sounds->crash);

            action->crash.object_crushing = room_get_object_at(state->curr_room, action->tilemap_pos);
            action->crash.object_crushed = room_get_object_at(state->curr_room, vec2i_move_in_dir4_by(action->tilemap_pos, action->crash.dir4, 1));

            if(action->crash.object_crushing == NULL ||
               action->crash.object_crushed == NULL)
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->crash.object_crushing->tilemap_pos = action->tilemap_pos;

            Texture* object_texture = get_texture_1_from_object(action->crash.object_crushing, textures);
            Vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash.object_crushing->tilemap_pos);
            Vec2f next_object_gamemap_pos = vec2f_move_in_dir4_by(curr_object_gamemap_pos, action->crash.dir4, 1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Animation* animation = new_animation_simultaneous_of_2(
                new_animation_camera_shake(1,1.0f,0.1f),
                new_animation_sequence_of_2(
                    new_animation_move_sprite_in_gamemap_in_line(
                        object_texture,
                        curr_object_gamemap_pos,
                        next_object_gamemap_pos,
                        ACTION_LENGTH_IN_SECONDS * 0.5f
                    ),
                    new_animation_move_sprite_in_gamemap_in_line(
                        object_texture,
                        next_object_gamemap_pos,
                        curr_object_gamemap_pos,
                        ACTION_LENGTH_IN_SECONDS * 0.5f
                    )
                )
            );

            action->animation = animation;

            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);

            action->crash.object_crushing->is_visible = FALSE;
        }
        break;
        case ACTION__FALL:
        {
            int fall_floor = room_get_floor_at(state->curr_room, action->tilemap_pos);

            if(action->fall.object == NULL)
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->fall.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_none();

            if(fall_floor == FLOOR__WATER)
            {
                animation = new_animation_sequence_of_3(
                    new_animation_fall_sprite_in_gamemap(
                        get_texture_1_from_object(action->fall.object, textures),
                        tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                        0.2f,
                        ACTION_LENGTH_IN_SECONDS
                    ),
                    new_animation_play_sound(sounds->fall_water),
                    new_animation_show_sprite_in_gamemap(
                        textures->animation.fall_water,
                        tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                        0.2f
                    )
                );
            }
            else if(fall_floor == FLOOR__LAVA || fall_floor == FLOOR__METAL_HATCH_OPEN)
            {
                animation = new_animation_sequence_of_3(
                    new_animation_fall_sprite_in_gamemap(
                        get_texture_1_from_object(action->fall.object, textures),
                        tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                        0.2f,
                        ACTION_LENGTH_IN_SECONDS
                    ),
                    new_animation_play_sound(sounds->fall_lava),
                    new_animation_show_sprite_in_gamemap(
                        textures->animation.fall_lava,
                        tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                        0.2f
                    )
                );
            }
            else if(fall_floor == FLOOR__PIT)
            {
                animation = new_animation_sequence_of_3(
                    new_animation_fall_sprite_in_gamemap(
                        get_texture_1_from_object(action->fall.object, textures),
                        tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                        0.2f,
                        ACTION_LENGTH_IN_SECONDS
                    ),
                    new_animation_play_sound(sounds->fall_pit),
                    new_animation_show_sprite_in_gamemap(
                        textures->animation.fall_pit,
                        tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                        0.2f
                    )
                );
            }

            action->animation = animation;
            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);

            action->fall.object->is_visible = FALSE;
        }
        break;
        case ACTION__DEATH:
        {
            if(action->death.object == NULL)
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->death.object->tilemap_pos = action->tilemap_pos;

            if(is_object_enemy(action->death.object) ||
               is_object_ally(action->death.object))
            {
                play_sound(sounds->death);

                // add_animation_to_animation_list(
                //     state,
                //     new_animation_background_flash(
                //         state->background_color,
                //         colors->white,
                //         0.05f,
                //         1.0f
                //         ),
                //     textures,
                //     sounds,
                //     musics,
                //     colors
                //     );

                add_animation_to_animation_list(
                    state,
                    action->animation = new_animation_simultaneous_of_2(
                    new_animation_death_shake(2.0f, 0.1f),
                    new_animation_ascend_sprite_in_gamemap(
                        textures->animation.death_2,
                        tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                        0.1f,
                        ACTION_LENGTH_IN_SECONDS
                        )
                    ),
                    textures,
                    sounds,
                    musics,
                    colors
                );
            }

            Animation* animation = new_animation_none();

            action->animation = animation;

            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);
        }
        break;
        case ACTION__BLOW_UP:
        {
            play_sound(sounds->bomb);

            Animation* animation = new_animation_simultaneous_of_2(
                new_animation_camera_shake(1,1.0f,0.1f),
                new_animation_sequence_of_2(
                    new_animation_show_sprite_in_gamemap(
                        textures->animation.blow_up_1,
                        tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                        ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                    new_animation_show_sprite_in_gamemap(
                        textures->animation.blow_up_2,
                        tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                        ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                )
            );

            action->animation = animation;

            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);
        }
        break;
        case ACTION__THROW:
        {
            play_sound(sounds->throww);

            Vec2i target_tilemap_pos = vec2i_move_in_dir4_by(action->tilemap_pos, action->throww.dir4, action->throww.distance);
            action->throww.object_thrown = room_get_object_at(state->curr_room, action->tilemap_pos);
            action->throww.object_on_target = room_get_object_at(state->curr_room, target_tilemap_pos);

            if(action->throww.object_on_target != NULL ||
               !is_tilemap_in_bounds(target_tilemap_pos))
            {
                Action* lift = new_action_lift(action->tilemap_pos, action->throww.dir4);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, lift);

                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            if(action->throww.object_thrown == NULL)
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->throww.object_thrown->tilemap_pos = action->tilemap_pos;

            Vec2i curr_tilemap_pos = action->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos, action->throww.dir4, action->throww.distance);

            Animation* animation = new_animation_move_sprite_in_gamemap_in_arch(
                get_texture_1_from_object(action->throww.object_thrown, textures),
                tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                2.0f
            );

            action->animation = animation;

            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);

            action->throww.object_thrown->is_visible = FALSE;
        }
        break;
        case ACTION__LIFT:
        {
            play_sound(sounds->throww);

            action->lift.object = room_get_object_at(state->curr_room, action->tilemap_pos);

            if(action->lift.object == NULL)
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->lift.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_move_sprite_in_gamemap_in_arch(
                get_texture_1_from_object(action->lift.object, textures),
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                2.0f
            );

            action->animation = animation;

            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);

            action->lift.object->is_visible = FALSE;
        }
        break;
        case ACTION__DROP:
        {
            play_sound(sounds->drop);

            if(action->drop.object == NULL)
            {
                action->is_finished = TRUE;
                action->is_finished_at_start = TRUE;
                break;
            }

            action->drop.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_simultaneous_of_2(
                new_animation_camera_shake(1,1.0f,0.1f),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.drop_2,
                    tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 1
                )
            );

            action->animation = animation;

            add_animation_to_animation_list(state, animation, textures, sounds, musics, colors);
        }
        break;
        case ACTION__CHANGE_FLOOR:
        {

            int floor = room_get_floor_at(state->curr_room, action->tilemap_pos);
            if(floor != FLOOR__NONE)
            {
                room_change_floor_at(state->curr_room, action->change_floor.new_floor_type, action->tilemap_pos);
            }
        }
        break;
        case ACTION__CHANGE_OBJECT:
        {
            Object* object = room_get_object_at(state->curr_room, action->tilemap_pos);
            if(object != NULL)
            {
                object->type = action->change_object.new_object_type;
            }
        }
        break;
        case ACTION__ADD_OBJECT:
        {
            if(action->add_object.new_object != NULL)
            {
                room_add_object_at(
                    state->curr_room,
                    action->add_object.new_object,
                    action->tilemap_pos
                );
            }
        }
        break;
        case ACTION__REMOVE_OBJECT:
        {
            //
        }
        break;
        case ACTION__CHANGE_OBJECT_TILEMAP_POS:
        {
            //
        }
        break;
        case ACTION__MELT:
        {
            play_sound(sounds->melt);

            Object* melt_object = room_get_object_at(state->curr_room, action->tilemap_pos);
            int melt_floor = room_get_floor_at(state->curr_room, action->tilemap_pos);

            if(melt_object != NULL)
            {
                object_on_melt(state, sounds, sequence, action, melt_object);
            }
            else if(melt_floor != FLOOR__NONE)
            {
                floor_on_melt(state, sounds, sequence, action, melt_floor);
            }
        }
        break;
        case ACTION__BREAK:
        {
            play_sound(sounds->breakk);

            Object* break_object = room_get_object_at(state->curr_room, action->tilemap_pos);
            int break_floor = room_get_floor_at(state->curr_room, action->tilemap_pos);

            if(break_object != NULL)
            {
                object_on_break(state, sounds, sequence, action, break_object);
            }
            else if(break_floor != FLOOR__NONE)
            {
                floor_on_break(state, sounds, sequence, action, break_floor);
            }
        }
        break;
        case ACTION__SHAKE:
        {
            play_sound(sounds->shake);

            Object* shake_object = room_get_object_at(state->curr_room, action->tilemap_pos);
            int shake_floor = room_get_floor_at(state->curr_room, action->tilemap_pos);

            if(shake_object != NULL)
            {
                object_on_shake(state, sounds, sequence, action, shake_object);
            }
            else if(shake_floor != FLOOR__NONE)
            {
                floor_on_shake(state, sounds, sequence, action, shake_floor);
            }
        }
        break;
        case ACTION__PLAY_SOUND:
        {
            play_sound(action->play_sound.sound);
        }
        break;
        default:
        break;
    }
}
