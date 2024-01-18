#include "../inc/state.h"

void start_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // printf("start action:       %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            ListElem* curr_elem = action->sequence.action_list->head;
            action->sequence.curr_action_list_elem = curr_elem;

            if(curr_elem != 0)
            {
                Action* curr_action = (Action*)curr_elem->data;
                start_action(state, action, curr_action, textures, sounds, musics, colors);
            }
            else
            {
                action->is_finished = 1;
            }
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                if(curr_elem)
                {
                    Action* curr_action = (Action*)curr_elem->data;
                    start_action(state, curr_action, curr_action, textures, sounds, musics, colors);
                }
            }
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            action->move.object = get_object_on_tilemap_pos(state, action->tilemap_pos);

            if(action->move.object == 0 ||
            !is_tilemap_pos_in_tilemap(vec2i_move_in_dir4_by(action->tilemap_pos, action->move.dir4, 1)))
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->move.object->tilemap_pos = action->tilemap_pos;

            Vec2i curr_tilemap_pos = action->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos,action->move.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash( action->tilemap_pos, action->move.dir4);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, crash);

                action->is_finished = 1;
                action->is_finished_at_start = 1;
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
                add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);

                int floor = get_floor_on_tilemap_pos(state, action->move.object->tilemap_pos);
                floor_on_move_start(state, sequence, action, floor);

                action->move.object->is_visible = 0;
            }
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->crash.object_crushing = get_object_on_tilemap_pos(state, action->tilemap_pos);
            action->crash.object_crushed = get_object_on_tilemap_pos(state, vec2i_move_in_dir4_by(action->tilemap_pos, action->crash.dir4, 1));

            if(action->crash.object_crushing == 0 ||
            action->crash.object_crushed == 0)
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->crash.object_crushing->tilemap_pos = action->tilemap_pos;

            Texture* object_texture = get_texture_1_from_object(action->crash.object_crushing, textures);
            Vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash.object_crushing->tilemap_pos);
            Vec2f next_object_gamemap_pos = vec2f_move_in_dir4_by(curr_object_gamemap_pos, action->crash.dir4, 1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Animation* animation = new_animation_sequence_of_2(
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
                );

            action->animation = animation;

            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);

            action->crash.object_crushing->is_visible = 0;
        }
        break;
        case ACTION_TYPE__FALL:
        {
            if(action->fall.object == 0)
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->fall.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_fall_sprite_in_gamemap(
                get_texture_1_from_object(action->fall.object, textures),
                tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                0.2f,
                ACTION_LENGTH_IN_SECONDS
                );

            action->animation = animation;
            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);

            action->fall.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            if(action->death.object == 0)
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->death.object->tilemap_pos = action->tilemap_pos;

            if(action->death.object->is_enemy)
            {
                add_animation_to_animation_list(
                    state,
                    new_animation_background_flash(
                        state->background_color,
                        colors->white,
                        0.05f,
                        1.0f
                        ),
                    textures,
                    sounds,
                    musics,
                    colors
                    );
            }

            Animation* animation = new_animation_ascend_sprite_in_gamemap(
                textures->animation.death_2,
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                0.1f,
                ACTION_LENGTH_IN_SECONDS
                );

            action->animation = animation;

            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            Animation* animation = new_animation_sequence_of_2(
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
                );

            action->animation = animation;

            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            Vec2i target_tilemap_pos = vec2i_move_in_dir4_by(action->tilemap_pos, action->throw.dir4, action->throw.distance);
            action->throw.object_thrown = get_object_on_tilemap_pos(state, action->tilemap_pos);
            action->throw.object_on_target = get_object_on_tilemap_pos(state, target_tilemap_pos);

            if(action->throw.object_on_target != 0 ||
            !is_tilemap_pos_in_tilemap(target_tilemap_pos))
            {
                Action* lift = new_action_lift(action->tilemap_pos, action->throw.dir4);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, lift);

                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            if(action->throw.object_thrown == 0)
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->throw.object_thrown->tilemap_pos = action->tilemap_pos;

            Vec2i curr_tilemap_pos = action->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos,action->throw.dir4,action->throw.distance);

            Animation* animation = new_animation_move_sprite_in_gamemap_in_arch(
                get_texture_1_from_object(action->throw.object_thrown, textures),
                tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                ACTION_LENGTH_IN_SECONDS * 4.0f,
                2.0f
                );

            action->animation = animation;

            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);

            action->throw.object_thrown->is_visible = 0;
        }
        break;
        case ACTION_TYPE__LIFT:
        {
            action->lift.object = get_object_on_tilemap_pos(state, action->tilemap_pos);

            if(action->lift.object == 0)
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->lift.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_move_sprite_in_gamemap_in_arch(
                get_texture_1_from_object(action->lift.object, textures),
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                ACTION_LENGTH_IN_SECONDS * 4.0f,
                2.0f
                );

            action->animation = animation;

            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);

            action->lift.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__DROP:
        {
            if(action->drop.object == 0)
            {
                action->is_finished = 1;
                action->is_finished_at_start = 1;
                break;
            }

            action->drop.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_sequence_of_2(
                new_animation_show_sprite_in_gamemap(
                    textures->animation.drop_2,
                    tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    ),
                new_animation_show_sprite_in_gamemap(
                    textures->animation.drop_2,
                    tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * 0.5
                    )
                );

            action->animation = animation;

            add_animation_to_animation_list(state,animation,textures,sounds,musics,colors);
        }
        break;
        case ACTION_TYPE__CHANGE_FLOOR:
        {

            int floor = get_floor_on_tilemap_pos(state, action->tilemap_pos);
            if(floor != FLOOR_TYPE__NONE)
            {
                change_floor_in_tilemap_pos(state, action->change_floor.new_floor_type, action->tilemap_pos);
            }
        }
        break;
        case ACTION_TYPE__CHANGE_OBJECT:
        {
            Object* object = get_object_on_tilemap_pos(state, action->tilemap_pos);
            if(object != 0)
            {
                object->type = action->change_object.new_object_type;
            }
        }
        break;
        case ACTION_TYPE__ADD_OBJECT:
        {
            if(action->add_object.new_object != 0)
            {
                add_object_to_gamemap_objects(state, action->add_object.new_object);
            }
        }
        break;
        case ACTION_TYPE__REMOVE_OBJECT:
        {
            if(action->remove_object.object_to_remove != 0)
            {
                remove_object_from_gamemap_objects(state, action->remove_object.object_to_remove);
            }
        }
        break;
        case ACTION_TYPE__MELT:
        {
            Object* melt_object = get_object_on_tilemap_pos(state, action->tilemap_pos);

            object_on_melt(state, sequence, action, melt_object);
        }
        break;
        case ACTION_TYPE__BREAK:
        {
            Object* melt_object = get_object_on_tilemap_pos(state, action->tilemap_pos);

            object_on_break(state, sequence, action, melt_object);
        }
        break;
        case ACTION_TYPE__SHAKE:
        {
            Object* melt_object = get_object_on_tilemap_pos(state, action->tilemap_pos);

            object_on_shake(state, sequence, action, melt_object);
        }
        break;
        default:
        break;
    }
}
