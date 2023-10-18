#include "../inc/state.h"

void start_action(State* state, Action* sequence, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("\n");
    print_action(state->action.main_action_sequence, 0);

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
            action->sequence.curr_action_list_elem = action->sequence.action_list->head;
            ListElem* curr_elem = action->sequence.curr_action_list_elem;

            if(curr_elem != 0)
            {
                Action* curr_action = (Action*)curr_elem->data;
                start_action(state, sequence, curr_action, textures, sounds, musics);
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
                    start_action(state, curr_action, curr_action, textures, sounds, musics);
                }
            }
        }
        break;
        case ACTION_TYPE__MOVE_GROUND:
        {
            action->move_ground.object->tilemap_pos = action->tilemap_pos;

            vec2i curr_tilemap_pos = action->tilemap_pos;
            vec2i next_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos,action->move_ground.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                Action* crash = new_action_crash_ground(action->move_ground.object, object_on_next_tilemap_pos, action->tilemap_pos, action->move_ground.dir4);
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, crash);

                action->is_finished = 1;
                action->move_ground.is_move_blocked = 1;
            }
            else
            {
                Animation* animation = new_animation_move_sprite_in_gamemap_in_line(
                    get_texture_from_object_type(action->move_ground.object->type, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    0.2f
                );
                action->animation = animation;
                start_animation(state, action->animation, textures, sounds, musics);

                int floor = get_floor_on_tilemap_pos(state, action->move_ground.object->tilemap_pos);
                floor_on_move_ground_start(state, sequence, action, floor);
            }

            action->move_ground.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__MOVE_AIR:
        {
            action->move_air.object->tilemap_pos = action->tilemap_pos;

            vec2i curr_tilemap_pos = action->tilemap_pos;
            vec2i next_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos,action->move_air.dir4,1);
            Object* object_on_next_tilemap_pos = get_object_on_tilemap_pos(state, next_tilemap_pos);

            if(object_on_next_tilemap_pos)
            {
                remove_all_actions_after_curr_action_action_sequence(sequence);
                add_action_after_curr_action_action_sequence(sequence, new_action_crash_air(action->move_air.object, object_on_next_tilemap_pos, action->tilemap_pos, action->move_air.dir4));

                action->is_finished = 1;
                action->move_air.is_move_blocked = 1;
            }
            else
            {
                Animation* animation = new_animation_move_sprite_in_gamemap_in_line(
                    get_texture_from_object_type(action->move_air.object->type, textures),
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                    0.2f
                );

                action->animation = animation;
                start_animation(state, action->animation, textures, sounds, musics);

                int floor = get_floor_on_tilemap_pos(state, action->move_air.object->tilemap_pos);
                floor_on_move_air_start(state, sequence, action, floor);
            }

            action->move_air.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__CRASH_GROUND:
        {
            action->crash_ground.object_crushing->tilemap_pos = action->tilemap_pos;

            Texture* object_texture = get_texture_from_object_type(action->crash_ground.object_crushing->type, textures);
            vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash_ground.object_crushing->tilemap_pos);
            vec2f next_object_gamemap_pos = make_vec2f_move_in_dir4_by(curr_object_gamemap_pos, action->crash_ground.dir4, 1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Animation* animation = new_animation_sequence_of_3(
                new_animation_sequence_of_2(
                    new_animation_move_sprite_in_gamemap_in_line(
                        object_texture,
                        curr_object_gamemap_pos,
                        next_object_gamemap_pos,
                        0.1f
                        ),
                    new_animation_show_sprite_in_gamemap(
                        object_texture,
                        next_object_gamemap_pos,
                        .01f
                        )
                    ),
                new_animation_simultaneous_of_1(
                    new_animation_move_sprite_in_gamemap_in_line(
                        object_texture,
                        next_object_gamemap_pos,
                        curr_object_gamemap_pos,
                        0.1f
                        )
                    ),
                new_animation_show_sprite_in_gamemap(
                    object_texture,
                    curr_object_gamemap_pos,
                    .01f
                    )
                );

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);

            action->crash_ground.object_crushing->is_visible = 0;
        }
        break;
        case ACTION_TYPE__CRASH_AIR:
        {
            action->crash_air.object_crushing->tilemap_pos = action->tilemap_pos;

            Texture* object_texture = get_texture_from_object_type(action->crash_air.object_crushing->type, textures);
            vec2f curr_object_gamemap_pos = tilemap_pos_to_gamemap_pos(action->crash_air.object_crushing->tilemap_pos);
            vec2f next_object_gamemap_pos = make_vec2f_move_in_dir4_by(curr_object_gamemap_pos, action->crash_air.dir4, 1.0f);
            next_object_gamemap_pos.x = curr_object_gamemap_pos.x + (next_object_gamemap_pos.x - curr_object_gamemap_pos.x) * 0.5f;
            next_object_gamemap_pos.y = curr_object_gamemap_pos.y + (next_object_gamemap_pos.y - curr_object_gamemap_pos.y) * 0.5f;

            Animation* animation = new_animation_sequence_of_3(
                new_animation_sequence_of_2(
                    new_animation_move_sprite_in_gamemap_in_line(
                        object_texture,
                        curr_object_gamemap_pos,
                        next_object_gamemap_pos,
                        0.1f
                        ),
                    new_animation_show_sprite_in_gamemap(
                        object_texture,
                        next_object_gamemap_pos,
                        .01f
                        )
                    ),
                new_animation_simultaneous_of_1(
                    new_animation_move_sprite_in_gamemap_in_line(
                        object_texture,
                        next_object_gamemap_pos,
                        curr_object_gamemap_pos,
                        0.1f
                        )
                    ),
                new_animation_show_sprite_in_gamemap(
                    object_texture,
                    curr_object_gamemap_pos,
                    .01f
                    )
                );

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);

            action->crash_air.object_crushing->is_visible = 0;
        }
        break;
        case ACTION_TYPE__FALL:
        {
            action->fall.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_fall_sprite_in_gamemap(
                get_texture_from_object_type(action->fall.object->type, textures),
                tilemap_pos_to_gamemap_pos(action->fall.object->tilemap_pos),
                0.1f,
                0.2f
                );

            action->animation = animation;
            start_animation(state, action->animation, textures, sounds, musics);

            action->fall.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            action->death.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_show_sprite_in_gamemap(
                textures->death.skull,
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                0.2f
                );

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            Animation* animation = new_animation_show_sprite_in_gamemap(
                textures->blow_up.explosion,
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                0.2f
                );

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            action->throw.object->tilemap_pos = action->tilemap_pos;

            vec2i curr_tilemap_pos = action->tilemap_pos;
            vec2i next_tilemap_pos = make_vec2i_move_in_dir4_by(curr_tilemap_pos,action->throw.dir4,action->throw.distance);

            Animation* animation = new_animation_move_sprite_in_gamemap_in_arch(
                get_texture_from_object_type(action->throw.object->type, textures),
                tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                tilemap_pos_to_gamemap_pos(next_tilemap_pos),
                1.0f,
                2.0f
                );

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);

            action->throw.object->is_visible = 0;
        }
        break;
        case ACTION_TYPE__DROP:
        {
            action->drop.object->tilemap_pos = action->tilemap_pos;

            Animation* animation = new_animation_show_sprite_in_gamemap(
                textures->drop.thump,
                tilemap_pos_to_gamemap_pos(action->tilemap_pos),
                0.2f
                );

            action->animation = animation;

            start_animation(state, action->animation, textures, sounds, musics);
        }
        break;
        default:
        break;
    }
}
