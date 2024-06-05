#include "../inc/state.h"
#include <stdlib.h>

void update_state(Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    if(state->gamestate == GAMESTATE__GAME_START)
    {
        if(input->was_mouse_left && !input->is_mouse_left &&
           state->mouse_screen_pos.x >= 600 &&
           state->mouse_screen_pos.x <= 600 + 128 &&
           state->mouse_screen_pos.y >= 300 &&
           state->mouse_screen_pos.y <= 300 + 64)
        {
            init_state(
                state,
                textures,
                sounds,
                musics,
                colors
            );
        }
    }

    if(state->gamestate == GAMESTATE__GAME_OVER)
    {
        if(input->was_mouse_left && !input->is_mouse_left &&
           state->mouse_screen_pos.x >= 600 &&
           state->mouse_screen_pos.x <= 600 + 128 &&
           state->mouse_screen_pos.y >= 300 &&
           state->mouse_screen_pos.y <= 300 + 64)
        {
            init_state(
                state,
                textures,
                sounds,
                musics,
                colors
            );
        }
    }

    if(state->gamestate == GAMESTATE__GAME_WON)
    {
        if(input->was_mouse_left && !input->is_mouse_left &&
           state->mouse_screen_pos.x >= 600 &&
           state->mouse_screen_pos.x <= 600 + 128 &&
           state->mouse_screen_pos.y >= 300 &&
           state->mouse_screen_pos.y <= 300 + 64)
        {
            init_state(
                state,
                textures,
                sounds,
                musics,
                colors
            );
        }
    }

    // quit

    if(input->is_quit)
    {
        state->is_game_running = FALSE;
    }

    // time

    state->time += delta_time;

    execute_all_mechanisms(state);

    // camera

    // if(input->is_mouse_scrolling)
    // {
    //     float change_camera_zoom_by = input->mouse_scrolled * state->camera_zoom * delta_time * 10.0f;
    //     state->camera_zoom += change_camera_zoom_by;
    // }

    // mouse

    Vec2i mouse_screen_pos;
    Vec2f mouse_world_pos;
    Vec2f mouse_gamemap_pos;
    Vec2i mouse_tilemap_pos;

    mouse_screen_pos = vec2i(input->mouse_x, input->mouse_y);
    mouse_world_pos = screen_pos_to_world_pos(mouse_screen_pos, state->camera_world_pos, state->camera_zoom);
    mouse_world_pos.x -= TILE_LENGTH * 0.5f;
    mouse_gamemap_pos = world_pos_to_gamemap_pos(iso_pos_to_cart_pos(mouse_world_pos));
    mouse_tilemap_pos = gamemap_pos_to_tilemap_pos(mouse_gamemap_pos);

    state->mouse_screen_pos = mouse_screen_pos;
    state->mouse_world_pos = mouse_world_pos;
    state->mouse_gamemap_pos = mouse_gamemap_pos;
    state->mouse_tilemap_pos = mouse_tilemap_pos;

    // dragging

    // if(!input->was_mouse_left && input->is_mouse_left)
    // {
    //     state->mouse_is_dragging =TRUE1;
    //     state->mouse_drag_origin_world_pos = state->mouse_world_pos;
    // }
    // else if(input->was_mouse_left && !input->is_mouse_left)
    // {
    //     state->mouse_is_dragging = FALSE;
    // }
    // else if(input->is_mouse_left)
    // {
    //     Vec2f drag_world_diff;
    //     Vec2f new_camera_world_pos;

    //     drag_world_diff.x = state->mouse_world_pos.x - state->camera_world_pos.x;
    //     drag_world_diff.y = state->mouse_world_pos.y - state->camera_world_pos.y;

    //     new_camera_world_pos.x = state->mouse_drag_origin_world_pos.x - drag_world_diff.x;
    //     new_camera_world_pos.y = state->mouse_drag_origin_world_pos.y - drag_world_diff.y;

    //     state->camera_world_pos = new_camera_world_pos;
    // }

    // state->show_all_order_numbers = input->is_key[KEY__2];

    // animations

    List* animation_to_be_removed_list = new_list(0);

    for(ListElem* curr_elem = state->animation_list->head;
        curr_elem; curr_elem = curr_elem->next)
    {
        Animation* curr_animation = (Animation*) curr_elem->data;
        if(curr_animation->is_finished)
        {
            end_animation(
                state,
                curr_animation,
                textures,
                sounds,
                musics,
                colors
            );
            add_new_list_element_to_list_end(
                animation_to_be_removed_list,
                curr_animation
            );
        }
        else
        {
            update_animation(
                state,
                curr_animation,
                delta_time,
                textures,
                sounds,
                musics,
                colors
            );
        }
    }

    for(ListElem* curr_elem = animation_to_be_removed_list->head;
        curr_elem; curr_elem = curr_elem->next)
    {
        remove_list_element_of_data(
            state->animation_list,
            curr_elem->data,
            1
        );
    }

    destroy_list(animation_to_be_removed_list);

    // gamestate

    if(state->gamestate != GAMESTATE__GAME_OVER &&
       state->hero_object->is_to_be_removed)
    {
        // game over
        change_gamestate(state, GAMESTATE__GAME_OVER);
    }

    if(state->gamestate != GAMESTATE__GAME_WON &&
       state->was_throne_used)
    {
        // game over
        change_gamestate(state, GAMESTATE__GAME_WON);
    }

    if(state->enemy_list->size == 0)
    {
        // restore all ally action points
        for(ListElem* curr_elem = state->ally_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Ally* curr_ally = (Ally*) curr_elem->data;
            restore_ally_action_points(state, curr_ally);
        }
    }

    switch(state->gamestate)
    {
        case GAMESTATE__NONE:
        case GAMESTATE__GAME_OVER:
        case GAMESTATE__GAME_WON:
        {
            //
        }
        break;
        case GAMESTATE__ALLY_CHOOSING_SKILL:
        {
            // change curr ally left
            if(input->was_key[KEY__LEFT] && !input->is_key[KEY__LEFT])
            {
                ListElem* curr_elem = state->curr_ally_list_elem;
                if(curr_elem != NULL)
                {
                    ListElem* prev_elem = curr_elem->prev;
                    if(prev_elem != NULL)
                    {
                        Ally* prev_ally = (Ally*) prev_elem->data;
                        if(prev_ally != NULL)
                        {
                            state->curr_ally_list_elem = prev_elem;
                            state->curr_ally = prev_ally;
                            state->curr_ally_object = prev_ally->object;

                            change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                            break;
                        }
                    }
                    else
                    {
                        ListElem* tail_elem = state->ally_list->tail;
                        Ally* tail_ally = (Ally*) tail_elem->data;
                        if(tail_ally != NULL)
                        {
                            state->curr_ally_list_elem = tail_elem;
                            state->curr_ally = tail_ally;
                            state->curr_ally_object = tail_ally->object;

                            change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                            break;
                        }
                    }
                }
            }

            // change curr ally right
            if(input->was_key[KEY__RIGHT] && !input->is_key[KEY__RIGHT])
            {
                ListElem* curr_elem = state->curr_ally_list_elem;
                if(curr_elem != NULL)
                {
                    ListElem* next_elem = curr_elem->next;
                    if(next_elem != NULL)
                    {
                        Ally* next_ally = (Ally*) next_elem->data;
                        if(next_ally != NULL)
                        {
                            state->curr_ally_list_elem = next_elem;
                            state->curr_ally = next_ally;
                            state->curr_ally_object = next_ally->object;

                            change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                            break;
                        }
                    }
                    else
                    {
                        ListElem* head_elem = state->ally_list->head;
                        Ally* head_ally = (Ally*) head_elem->data;
                        if(head_ally != NULL)
                        {
                            state->curr_ally_list_elem = head_elem;
                            state->curr_ally = head_ally;
                            state->curr_ally_object = head_ally->object;

                            change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                            break;
                        }
                    }
                }
            }

            // change curr ally mouse
            if(input->was_mouse_left && !input->is_mouse_left)
            {
                Object* potential_new_ally_object =
                    room_get_object_at(state->curr_room, mouse_tilemap_pos);

                if(potential_new_ally_object != NULL)
                {
                    Ally* potential_new_ally =
                        get_ally_of_object(state, potential_new_ally_object);

                    if(potential_new_ally != NULL)
                    {
                        ListElem* new_ally_elem =
                            get_list_element_of_data(state->ally_list, potential_new_ally);

                        if(new_ally_elem != NULL)
                        {
                            state->curr_ally_list_elem = new_ally_elem;
                            state->curr_ally = potential_new_ally;
                            state->curr_ally_object = potential_new_ally_object;

                            change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                            break;
                        }
                    }
                }
            }

            // end ally turn
            if(input->was_key[KEY__ENTER] && !input->is_key[KEY__ENTER] ||
               (input->was_mouse_left && !input->is_mouse_left &&
                state->mouse_screen_pos.x >= 1200 - 64 - 10 + 100 &&
                state->mouse_screen_pos.x <= 1200 - 64 - 10 + 64 + 100 &&
                state->mouse_screen_pos.y >= 10 &&
                state->mouse_screen_pos.y <= 10 + 64))
            {
                // restore all ally action points
                for(ListElem* curr_elem = state->ally_list->head;
                    curr_elem != NULL; curr_elem = curr_elem->next)
                {
                    Ally* curr_ally = (Ally*) curr_elem->data;
                    restore_ally_action_points(state, curr_ally);
                }

                // start enemy turn
                if(state->enemy_list->size > 0)
                {
                    // enemy with order number of 1
                    for(ListElem* curr_elem = state->enemy_list->head;
                        curr_elem != NULL; curr_elem = curr_elem->next)
                    {
                        Enemy* curr_enemy = (Enemy*) curr_elem->data;
                        if(curr_enemy->order_number == 1)
                        {
                            state->curr_enemy_list_elem = curr_elem;
                            state->curr_enemy = curr_enemy;
                            state->enemy_action_sequence = (Action*) curr_enemy->action_sequence;
                        }
                    }

                    add_animation_to_animation_list(
                        state,
                        new_animation_change_background_color(
                            colors->ally_background,
                            colors->enemy_background,
                            0.25f
                        ),
                        textures,
                        sounds,
                        musics,
                        colors
                    );

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK);
                    state->timer = 0.0f;
                    break;
                }
                // or start ally turn again
                else
                {
                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                    break;
                }
            }

            // choose skill

            int skill = SKILL__NONE;

            if(input->was_mouse_left && !input->is_mouse_left)
            {
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        int index = i * 2 + j;

                        if(state->mouse_screen_pos.x >= 138 + 10 * (i + 1) + 64 * i &&
                           state->mouse_screen_pos.x <= 138 + 10 * (i + 1) + 64 * i + 64 &&
                           state->mouse_screen_pos.y >= 600 + 50 + 10 * j + 64 * j &&
                           state->mouse_screen_pos.y <= 600 + 50 + 10 * j + 64 * j + 64)
                        {
                            ListElem* skill_elem = get_nth_list_element(
                                state->curr_ally->skill_list,
                                index
                            );

                            if(skill_elem != NULL)
                            {
                                skill = (int) skill_elem->data;
                            }
                        }
                    }
                }
            }

            state->curr_ally_skill = skill;

            // if curr ally has enough action points
            if(state->curr_ally->object->action_points > 0 &&
               state->curr_ally->object->action_points >= get_skill_action_points(skill) &&
               skill != SKILL__NONE)
            {
                // go to choosing target 1
                if(is_skill_two_target(skill))
                {
                    state->selected_tilemap_pos = vec2i(-1, -1);

                    remove_all_list_elements(state->possible_target_1_tilemap_pos_list, 1);
                    skill_get_possible_target_1_pos(
                        state,
                        skill,
                        state->curr_ally->object->tilemap_pos,
                        state->possible_target_1_tilemap_pos_list
                    );

                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_TARGET_1);
                    break;
                }
                // go to choosing target 2
                else
                {
                    state->selected_tilemap_pos = vec2i(-1, -1);

                    // possible target 2 positions
                    remove_all_list_elements(state->possible_target_2_tilemap_pos_list, 1);
                    skill_get_possible_target_2_pos(
                        state,
                        skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->possible_target_2_tilemap_pos_list
                    );

                    // selected position
                    int is_mouse_pos_in_possible_target_2_pos = FALSE;
                    for(ListElem* curr_elem = state->possible_target_2_tilemap_pos_list->head;
                        !is_mouse_pos_in_possible_target_2_pos && curr_elem != NULL;
                        curr_elem = curr_elem->next)
                    {
                        Vec2i* tilemap_pos = (Vec2i*) curr_elem->data;

                        if(vec2i_equals(*tilemap_pos, mouse_tilemap_pos))
                        {
                            is_mouse_pos_in_possible_target_2_pos = TRUE;
                        }
                    }

                    clear_curr_ally_attack_actions_and_draw(state);

                    // new actions and draw
                    if(is_mouse_pos_in_possible_target_2_pos)
                    {
                        get_curr_ally_attack_actions_and_draw(state, textures);
                    }

                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_TARGET_2);
                    break;
                }
            }
        }
        break;
        case GAMESTATE__ALLY_CHOOSING_TARGET_1:
        {
            // go back
            if(input->was_key[KEY__ESC] && !input->is_key[KEY__ESC] ||
               input->was_mouse_right && !input->is_mouse_right)
            {
                remove_all_actions_from_action_sequence(
                    state->ally_action_sequence
                );

                change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                break;
            }

            // selected position
            int is_mouse_pos_in_possible_target_1_pos = FALSE;
            for(ListElem* curr_elem = state->possible_target_1_tilemap_pos_list->head;
                !is_mouse_pos_in_possible_target_1_pos && curr_elem != NULL;
                curr_elem = curr_elem->next)
            {
                Vec2i* tilemap_pos = (Vec2i*) curr_elem->data;

                if(vec2i_equals(*tilemap_pos, mouse_tilemap_pos))
                {
                    is_mouse_pos_in_possible_target_1_pos = TRUE;
                }
            }

            if(is_mouse_pos_in_possible_target_1_pos)
            {
                state->selected_tilemap_pos = mouse_tilemap_pos;

                // go to choosing target 2
                if(input->was_mouse_left && !input->is_mouse_left)
                {
                    state->curr_ally_target_1_tilemap_pos = state->selected_tilemap_pos;

                    state->selected_tilemap_pos = vec2i(-1, -1);

                    remove_all_list_elements(state->possible_target_2_tilemap_pos_list, 1);
                    skill_get_possible_target_2_pos(
                        state,
                        state->curr_ally_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->possible_target_2_tilemap_pos_list
                    );

                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_TARGET_2);
                    break;
                }
            }
            else
            {
                state->selected_tilemap_pos = vec2i(-1, -1);
            }
        }
        break;
        case GAMESTATE__ALLY_CHOOSING_TARGET_2:
        {
            // go back
            if(input->was_key[KEY__ESC] && !input->is_key[KEY__ESC] ||
               input->was_mouse_right && !input->is_mouse_right)
            {
                state->selected_tilemap_pos = vec2i(-1, -1);

                remove_all_actions_from_action_sequence(
                    state->ally_action_sequence
                );

                if(is_skill_two_target(state->curr_ally_skill))
                {
                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_TARGET_1);
                    break;
                }
                else
                {
                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                    break;
                }

                break;
            }

            // selected position
            int is_mouse_pos_in_possible_target_2_pos = FALSE;
            for(ListElem* curr_elem = state->possible_target_2_tilemap_pos_list->head;
                !is_mouse_pos_in_possible_target_2_pos && curr_elem != NULL;
                curr_elem = curr_elem->next)
            {
                Vec2i* tilemap_pos = (Vec2i*) curr_elem->data;

                if(vec2i_equals(*tilemap_pos, mouse_tilemap_pos))
                {
                    is_mouse_pos_in_possible_target_2_pos = TRUE;
                }
            }
            int is_new_selected_pos = !vec2i_equals(
                state->selected_tilemap_pos,
                state->mouse_tilemap_pos
            );

            // new actions and draw
            if(is_new_selected_pos)
            {
                clear_curr_ally_attack_actions_and_draw(state);

                if(is_mouse_pos_in_possible_target_2_pos)
                {
                    state->selected_tilemap_pos = state->mouse_tilemap_pos;

                    state->curr_ally_target_2_tilemap_pos = state->selected_tilemap_pos;

                    get_curr_ally_attack_actions_and_draw(state, textures);
                }
                else
                {
                    state->selected_tilemap_pos = vec2i(-1, -1);
                }
            }

            // go to executing
            if(input->was_mouse_left && !input->is_mouse_left)
            {
                if(is_mouse_pos_in_possible_target_2_pos)
                {
                    state->selected_tilemap_pos = vec2i(-1, -1);

                    Animation* animation = skill_get_animation(
                        state,
                        state->curr_ally_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->curr_ally_target_2_tilemap_pos,
                        textures,
                        colors
                    );

                    add_animation_to_animation_list(
                        state,
                        animation,
                        textures,
                        sounds,
                        musics,
                        colors
                    );

                    skill_on_use(
                        state,
                        state->curr_ally_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->curr_ally_target_2_tilemap_pos,
                        textures,
                        colors
                    );

                    state->curr_skill_animation = animation;

                    change_gamestate(state, GAMESTATE__ALLY_EXECUTING_ANIMATION);
                    break;
                }
            }
        }
        break;
        case GAMESTATE__ALLY_EXECUTING_ANIMATION:
        {
            if(state->curr_skill_animation->is_finished)
            {
                state->curr_skill_animation = NULL;

                execute_action_sequence(
                    state,
                    state->ally_action_sequence,
                    textures,
                    sounds,
                    musics,
                    colors
                );

                change_gamestate(state, GAMESTATE__ALLY_EXECUTING_SKILL);
                break;
            }
        }
        break;
        case GAMESTATE__ALLY_EXECUTING_SKILL:
        {
            if(state->ally_action_sequence->is_finished)
            {
                end_action(
                    state,
                    state->ally_action_sequence,
                    state->ally_action_sequence,
                    textures,
                    sounds,
                    musics,
                    colors
                );

                if(state->enemy_list->size > 0)
                {
                    if(state->curr_ally_skill == SKILL__MOVE ||
                       state->curr_ally_skill == SKILL__MOVE_FLOATING ||
                       state->curr_ally_skill == SKILL__MOVE_FLYING)
                    {
                        state->curr_ally->object->action_points -=
                            state->ally_move_distance;
                    }
                    else
                    {
                        state->curr_ally->object->action_points -=
                            get_skill_action_points(state->curr_ally_skill);
                    }
                }

                // objects to be removed
                remove_all_object_to_be_removed(state);

                // all enemy
                update_enemy_list(state);
                update_all_enemy_order(state);
                for(ListElem* curr_elem = state->enemy_list->head;
                    curr_elem != NULL; curr_elem = curr_elem->next)
                {
                    Enemy* curr_enemy = (Enemy*) curr_elem->data;
                    update_enemy_attack_targets(state, curr_enemy);
                    clear_enemy_attack_actions_and_draw(state, curr_enemy);
                    get_enemy_attack_actions_and_draw(state, curr_enemy, textures);
                }

                // all allies
                update_ally_list(state);
                for(ListElem* curr_elem = state->ally_list->head;
                    curr_elem != NULL; curr_elem = curr_elem->next)
                {
                    Ally* curr_ally = (Ally*) curr_elem->data;
                    update_ally_skill_list(state, curr_ally);
                }

                // curr allies
                int was_prev_ally_chosen = FALSE;
                for(ListElem* curr_elem = state->ally_list->head;
                    !was_prev_ally_chosen && curr_elem != NULL;
                    curr_elem = curr_elem->next)
                {
                    Ally* curr_ally = (Ally*) curr_elem->data;
                    if(curr_ally != NULL)
                    {
                        if(curr_ally->object != NULL &&
                           curr_ally->object == state->curr_ally_object)
                        {
                            state->curr_ally_list_elem = curr_elem;
                            state->curr_ally = curr_ally;
                            state->curr_ally_object = curr_ally->object;
                            was_prev_ally_chosen = TRUE;
                        }
                    }
                }
                if(!was_prev_ally_chosen)
                {
                    state->curr_ally_list_elem = state->ally_list->head;
                    state->curr_ally = state->curr_ally_list_elem->data;
                    state->curr_ally_object = state->curr_ally->object;
                }

                change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                break;
            }
            else
            {
                update_action(
                    state,
                    state->ally_action_sequence,
                    state->ally_action_sequence,
                    delta_time,
                    textures,
                    sounds,
                    musics,
                    colors
                );
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK:
        {
            if(state->timer > ENEMY_PAUSE_LENGTH_IN_SECONDS)
            {
                state->timer = 0.0f;

                Animation* animation = skill_get_animation(
                    state,
                    state->curr_enemy->skill,
                    state->curr_enemy->object->tilemap_pos,
                    state->curr_enemy->target_1_tilemap_pos,
                    state->curr_enemy->target_2_tilemap_pos,
                    textures,
                    colors
                );

                add_animation_to_animation_list(
                    state,
                    animation,
                    textures,
                    sounds,
                    musics,
                    colors
                );

                state->curr_skill_animation = animation;

                change_gamestate(state, GAMESTATE__ENEMY_EXECUTING_ANIMATION);
                break;
            }
            else
            {
                state->timer += delta_time;
            }
        }
        break;
        case GAMESTATE__ENEMY_EXECUTING_ANIMATION:
        {
            if(state->curr_skill_animation->is_finished)
            {
                execute_action_sequence(
                    state,
                    state->enemy_action_sequence,
                    textures,
                    sounds,
                    musics,
                    colors
                );

                change_gamestate(state, GAMESTATE__ENEMY_EXECUTING_ATTACK);
                break;
            }
        }
        break;
        case GAMESTATE__ENEMY_EXECUTING_ATTACK:
        {
            if(state->enemy_action_sequence->is_finished)
            {
                state->curr_enemy->performed_attack = TRUE;

                end_action(
                    state,
                    state->enemy_action_sequence,
                    state->enemy_action_sequence,
                    textures,
                    sounds,
                    musics,
                    colors
                );

                // update enemy attacks and draw
                for(ListElem* curr_elem = state->enemy_list->head;
                    curr_elem != NULL; curr_elem = curr_elem->next)
                {
                    Enemy* curr_enemy = (Enemy*) curr_elem->data;
                    if(!curr_enemy->object->is_to_be_removed &&
                       !curr_enemy->performed_attack)
                    {
                        update_enemy_attack_targets(state, curr_enemy);
                        clear_enemy_attack_actions_and_draw(state, curr_enemy);
                        get_enemy_attack_actions_and_draw(state, curr_enemy, textures);
                    }
                }

                // determine next enemy
                int next_enemy_order_number = state->curr_enemy->order_number + 1;
                ListElem* next_enemy_list_elem = NULL;
                int found_next_enemy = FALSE;
                while(!found_next_enemy &&
                      next_enemy_order_number <= state->enemy_list->size)
                {
                    for(ListElem* curr_elem = state->enemy_list->head;
                        curr_elem != NULL; curr_elem = curr_elem->next)
                    {
                        Enemy* curr_enemy = (Enemy*) curr_elem->data;
                        if(curr_enemy->order_number == next_enemy_order_number)
                        {
                            if(curr_enemy->object->is_to_be_removed)
                            {
                                next_enemy_order_number++;
                            }
                            else
                            {
                                found_next_enemy = TRUE;
                                next_enemy_list_elem = curr_elem;
                            }
                        }
                    }
                }

                // go to next enemy
                if(next_enemy_list_elem != NULL)
                {
                    state->curr_enemy_list_elem = next_enemy_list_elem;
                    state->curr_enemy = (Enemy*) next_enemy_list_elem->data;
                    state->enemy_action_sequence = (Action*) state->curr_enemy->action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK);
                    state->timer = 0.0f;
                    break;
                }
                // start moving enemies from beginning
                else
                {
                    // enemy with order number of 1
                    for(ListElem* curr_elem = state->enemy_list->head;
                        curr_elem != NULL; curr_elem = curr_elem->next)
                    {
                        Enemy* curr_enemy = (Enemy*) curr_elem->data;
                        if(curr_enemy->order_number == 1)
                        {
                            state->curr_enemy_list_elem = curr_elem;
                            state->curr_enemy = curr_enemy;
                            state->enemy_action_sequence = (Action*) curr_enemy->action_sequence;
                        }
                    }

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE);
                    state->timer = 0.0f;
                    break;
                }
            }
            else
            {
                update_action(
                    state,
                    state->enemy_action_sequence,
                    state->enemy_action_sequence,
                    delta_time,
                    textures,
                    sounds,
                    musics,
                    colors
                );
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE:
        {
            if(state->timer > ENEMY_PAUSE_LENGTH_IN_SECONDS)
            {
                state->timer = 0.0f;

                object_enemy_prepare_move(state, state->curr_enemy);

                execute_action_sequence(state, state->enemy_action_sequence, textures, sounds, musics, colors);

                change_gamestate(state, GAMESTATE__ENEMY_MOVING);
                break;
            }
            else
            {
                state->timer += delta_time;
            }
        }
        break;
        case GAMESTATE__ENEMY_MOVING:
        {
            if(state->enemy_action_sequence->is_finished)
            {
                end_action(
                    state,
                    state->enemy_action_sequence,
                    state->enemy_action_sequence,
                    textures,
                    sounds,
                    musics,
                    colors
                );

                // update enemy attacks and draw
                for(ListElem* curr_elem = state->enemy_list->head;
                    curr_elem != NULL; curr_elem = curr_elem->next)
                {
                    Enemy* curr_enemy = (Enemy*) curr_elem->data;
                    if(!curr_enemy->object->is_to_be_removed &&
                       !curr_enemy->performed_attack)
                    {
                        update_enemy_attack_targets(state, curr_enemy);
                        clear_enemy_attack_actions_and_draw(state, curr_enemy);
                        get_enemy_attack_actions_and_draw(state, curr_enemy, textures);
                    }
                }

                // go to target
                change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET);
                state->timer = 0.0f;
                break;
            }
            else
            {
                update_action(
                    state,
                    state->enemy_action_sequence,
                    state->enemy_action_sequence,
                    delta_time,
                    textures,
                    sounds,
                    musics,
                    colors
                );
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET:
        {
            if(state->timer > ENEMY_PAUSE_LENGTH_IN_SECONDS)
            {
                state->timer = 0.0f;

                // if enemy didn't die when moving
                if(!state->curr_enemy->object->is_to_be_removed)
                {
                    update_enemy_attack_dir4(state, state->curr_enemy);
                    update_enemy_attack_targets(state, state->curr_enemy);
                    clear_enemy_attack_actions_and_draw(state, state->curr_enemy);
                    get_enemy_attack_actions_and_draw(state, state->curr_enemy, textures);
                    state->curr_enemy->performed_attack = FALSE;
                }

                // determine next enemy
                int next_enemy_order_number = state->curr_enemy->order_number + 1;
                ListElem* next_enemy_list_elem = NULL;
                int found_next_enemy = FALSE;
                while(!found_next_enemy &&
                      next_enemy_order_number <= state->enemy_list->size)
                {
                    for(ListElem* curr_elem = state->enemy_list->head;
                        curr_elem != NULL; curr_elem = curr_elem->next)
                    {
                        Enemy* curr_enemy = (Enemy*) curr_elem->data;
                        if(curr_enemy->order_number == next_enemy_order_number)
                        {
                            if(curr_enemy->object->is_to_be_removed)
                            {
                                next_enemy_order_number++;
                            }
                            else
                            {
                                found_next_enemy = TRUE;
                                next_enemy_list_elem = curr_elem;
                            }
                        }
                    }
                }

                // go to next enemy
                if(next_enemy_list_elem != NULL)
                {
                    state->curr_enemy_list_elem = next_enemy_list_elem;
                    state->curr_enemy = (Enemy*) next_enemy_list_elem->data;
                    state->enemy_action_sequence = (Action*) state->curr_enemy->action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE);
                    state->timer = 0.0f;
                    break;
                }
                // end enemy turn
                else
                {
                    // objects to be removed
                    remove_all_object_to_be_removed(state);

                    // all enemies
                    update_enemy_list(state);
                    update_all_enemy_order(state);
                    for(ListElem* curr_elem = state->enemy_list->head;
                        curr_elem != NULL; curr_elem = curr_elem->next)
                    {
                        Enemy* curr_enemy = (Enemy*) curr_elem->data;
                        update_enemy_attack_targets(state, curr_enemy);
                        clear_enemy_attack_actions_and_draw(state, curr_enemy);
                        get_enemy_attack_actions_and_draw(state, curr_enemy, textures);
                    }

                    // all allies
                    update_ally_list(state);
                    for(ListElem* curr_elem = state->ally_list->head;
                        curr_elem != NULL; curr_elem = curr_elem->next)
                    {
                        Ally* curr_ally = (Ally*) curr_elem->data;
                        update_ally_skill_list(state, curr_ally);
                    }

                    // curr ally
                    int was_prev_ally_chosen = FALSE;
                    for(ListElem* curr_elem = state->ally_list->head;
                        !was_prev_ally_chosen && curr_elem != NULL;
                        curr_elem = curr_elem->next)
                    {
                        Ally* curr_ally = (Ally*) curr_elem->data;
                        if(curr_ally != NULL)
                        {
                            if(curr_ally->object != NULL &&
                               curr_ally->object == state->curr_ally_object)
                            {
                                state->curr_ally_list_elem = curr_elem;
                                state->curr_ally = curr_ally;
                                state->curr_ally_object = curr_ally->object;
                                was_prev_ally_chosen = TRUE;
                            }
                        }
                    }
                    if(!was_prev_ally_chosen)
                    {
                        state->curr_ally_list_elem = state->ally_list->head;
                        state->curr_ally = state->curr_ally_list_elem->data;
                        state->curr_ally_object = state->curr_ally->object;
                    }

                    add_animation_to_animation_list(
                        state,
                        new_animation_change_background_color(
                            colors->enemy_background,
                            colors->ally_background,
                            0.25f
                        ),
                        textures,
                        sounds,
                        musics,
                        colors
                    );

                    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
                    break;
                }
            }
            else
            {
                state->timer += delta_time;
            }
        }
        break;
        default:
        break;
    }
}
