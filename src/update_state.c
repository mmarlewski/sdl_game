#include "../inc/state.h"

void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    remove_all_list_elements(state->curr_ally_skill_list, 0);
    get_object_ally_skills(state, state->curr_ally->object, state->curr_ally_skill_list);

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2)
    {
            remove_all_list_elements(state->curr_ally_draw_below_texture_list, 0);
            remove_all_list_elements(state->curr_ally_draw_below_gamemap_pos_list, 1);
            skill_get_draw_below(
                state,
                state->curr_ally_curr_skill,
                state->curr_ally->object->tilemap_pos,
                state->curr_ally_target_1_tilemap_pos,
                state->curr_ally_target_2_tilemap_pos,
                state->curr_ally_draw_below_texture_list,
                state->curr_ally_draw_below_gamemap_pos_list,
                textures,
                colors
                );

            remove_all_list_elements(state->curr_ally_draw_above_texture_list, 0);
            remove_all_list_elements(state->curr_ally_draw_above_gamemap_pos_list, 1);
            skill_get_draw_above(
                state,
                state->curr_ally_curr_skill,
                state->curr_ally->object->tilemap_pos,
                state->curr_ally_target_1_tilemap_pos,
                state->curr_ally_target_2_tilemap_pos,
                state->curr_ally_draw_above_texture_list,
                state->curr_ally_draw_above_gamemap_pos_list,
                textures,
                colors
                );

            remove_all_list_elements(state->curr_ally_draw_effect_texture_list, 0);
            remove_all_list_elements(state->curr_ally_draw_effect_gamemap_pos_list, 1);
            skill_get_draw_effect(
                state,
                state->curr_ally_curr_skill,
                state->curr_ally->object->tilemap_pos,
                state->curr_ally_target_1_tilemap_pos,
                state->curr_ally_target_2_tilemap_pos,
                state->curr_ally_draw_effect_texture_list,
                state->curr_ally_draw_effect_gamemap_pos_list,
                textures,
                colors
                );
    }

    for(ListElem* enemy_elem = state->enemy_list->head; enemy_elem != 0; enemy_elem = enemy_elem->next)
    {
        Enemy* enemy = (Enemy*) enemy_elem->data;

        if(enemy != 0)
        {
            remove_all_list_elements(enemy->draw_below_texture_list, 0);
            remove_all_list_elements(enemy->draw_below_tilemap_pos_list, 1);
            skill_get_draw_below(
                state,
                enemy->skill,
                enemy->object->tilemap_pos,
                enemy->target_1_tilemap_pos,
                enemy->target_2_tilemap_pos,
                enemy->draw_below_texture_list,
                enemy->draw_below_tilemap_pos_list,
                textures,
                colors
                );

            remove_all_list_elements(enemy->draw_above_texture_list, 0);
            remove_all_list_elements(enemy->draw_above_tilemap_pos_list, 1);
            skill_get_draw_above(
                state,
                enemy->skill,
                enemy->object->tilemap_pos,
                enemy->target_1_tilemap_pos,
                enemy->target_2_tilemap_pos,
                enemy->draw_above_texture_list,
                enemy->draw_above_tilemap_pos_list,
                textures,
                colors
                );

            remove_all_list_elements(enemy->draw_effect_texture_list, 0);
            remove_all_list_elements(enemy->draw_effect_tilemap_pos_list, 1);
            skill_get_draw_effect(
                state,
                enemy->skill,
                enemy->object->tilemap_pos,
                enemy->target_1_tilemap_pos,
                enemy->target_2_tilemap_pos,
                enemy->draw_effect_texture_list,
                enemy->draw_effect_tilemap_pos_list,
                textures,
                colors
                );
        }
    }

    // !!!!!

    // quit

    if(input->is_quit)
    {
        state->is_game_running = 0;
    }

    // time

    state->time += delta_time;

    // camera

    if(input->is_mouse_scrolling)
    {
        float change_camera_zoom_by = input->mouse_scrolled * state->camera_zoom * delta_time * 10.0f;
        state->camera_zoom += change_camera_zoom_by;
    }

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

    // drag

    if(!input->was_mouse_left && input->is_mouse_left)
    {
        state->mouse_is_dragging = 1;
        state->mouse_drag_origin_world_pos = state->mouse_world_pos;
    }
    else if(input->was_mouse_left && !input->is_mouse_left)
    {
        state->mouse_is_dragging = 0;
    }
    else if(input->is_mouse_left)
    {
        Vec2f drag_world_diff;
        Vec2f new_camera_world_pos;

        drag_world_diff.x = state->mouse_world_pos.x - state->camera_world_pos.x;
        drag_world_diff.y = state->mouse_world_pos.y - state->camera_world_pos.y;

        new_camera_world_pos.x = state->mouse_drag_origin_world_pos.x - drag_world_diff.x;
        new_camera_world_pos.y = state->mouse_drag_origin_world_pos.y - drag_world_diff.y;

        state->camera_world_pos = new_camera_world_pos;
    }

    state->show_all_order_numbers = input->is_key[KEY__T];

    // animations

    List* animation_to_be_removed_list = new_list(0);

    for(ListElem* curr_elem = state->animation_list->head; curr_elem; curr_elem = curr_elem->next)
    {
        Animation* curr_animation = (Animation*)curr_elem->data;
        if(curr_animation->is_finished)
        {
            end_animation(state, curr_animation, textures, sounds, musics, colors);
            add_new_list_element_to_list_end(animation_to_be_removed_list, curr_animation);
        }
        else
        {
            update_animation(state, curr_animation, delta_time, textures, sounds, musics, colors);
        }
    }

    for(ListElem* curr_elem = animation_to_be_removed_list->head; curr_elem; curr_elem = curr_elem->next)
    {
        remove_list_element_of_data(state->animation_list, curr_elem->data, 1);
    }

    destroy_list(animation_to_be_removed_list);

    // gamestate

    if(state->gamestate != GAMESTATE__NONE &&
     state->hero_object == 0)
    {
        change_gamestate(state, GAMESTATE__NONE);
    }

    switch(state->gamestate)
    {
        case GAMESTATE__NONE:
        {
            if (input->was_key[KEY__ESC] && !input->is_key[KEY__ESC])
            {
                state->is_game_running = 0;

                break;
            }
        }
        break;
        case GAMESTATE__HERO_CHOOSING_SKILL:
        {
            if (input->was_key[KEY__ESC] && !input->is_key[KEY__ESC])
            {
                state->is_game_running = 0;

                break;
            }

            if(input->was_key[KEY__ENTER] && !input->is_key[KEY__ENTER])
            {
                restore_hero_ap(state);

                if(state->enemy_list->size > 0)
                {
                    state->curr_enemy_list_elem =
                    state->enemy_list->head;

                    state->curr_enemy =
                    (Enemy*)state->curr_enemy_list_elem->data;

                    state->enemy_action_sequence =
                    (Action*)state->curr_enemy->action_sequence;

                    add_animation_to_animation_list(state,new_animation_change_background_color(state->background_color,colors->enemy_background, 0.25f), textures, sounds, musics, colors);

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK);
                    state->timer = 0.0f;
                }
                else
                {
                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                }

                break;
            }

            int skill = SKILL__NONE;

            if(input->was_key[KEY__W] && !input->is_key[KEY__W]) skill = SKILL__MANIPULATION;
            if(input->was_key[KEY__E] && !input->is_key[KEY__E]) skill = SKILL__USE;

            if(input->was_key[KEY__R] && !input->is_key[KEY__R])
            {
                switch(state->curr_ally->object->type)
                {
                    case OBJECT_TYPE__HERO:
                    case OBJECT_TYPE__MINIBOT_ALLY:
                    case OBJECT_TYPE__MINIBOT_ALLY_CELL:
                    case OBJECT_TYPE__MINIBOT_ALLY_DYNAMITE:
                    case OBJECT_TYPE__MINIBOT_ALLY_GEMSTONE:
                    {
                        skill = SKILL__MOVE;
                    }
                    break;
                    case OBJECT_TYPE__HERO_FLOATING:
                    {
                        skill = SKILL__MOVE;
                    }
                    break;
                    case OBJECT_TYPE__HERO_FLYING:
                    {
                        skill = SKILL__MOVE;
                    }
                    break;
                    default:
                    break;
                }
            }

            if(input->was_key[KEY__1] && !input->is_key[KEY__1])
            {
                if(state->curr_ally_skill_list->size >= 1)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 0);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__2] && !input->is_key[KEY__2])
            {
                if(state->curr_ally_skill_list->size >= 2)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 1);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__3] && !input->is_key[KEY__3])
            {
                if(state->curr_ally_skill_list->size >= 3)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 2);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__4] && !input->is_key[KEY__4])
            {
                if(state->curr_ally_skill_list->size >= 4)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 3);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__5] && !input->is_key[KEY__5])
            {
                if(state->curr_ally_skill_list->size >= 5)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 4);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__6] && !input->is_key[KEY__6])
            {
                if(state->curr_ally_skill_list->size >= 6)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 5);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__7] && !input->is_key[KEY__7])
            {
                if(state->curr_ally_skill_list->size >= 7)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 6);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__8] && !input->is_key[KEY__8])
            {
                if(state->curr_ally_skill_list->size >= 8)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 7);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }
            if(input->was_key[KEY__9] && !input->is_key[KEY__9])
            {
                if(state->curr_ally_skill_list->size >= 9)
                {
                    ListElem* list_elem = get_nth_list_element(state->curr_ally_skill_list, 8);
                    if(list_elem != 0)
                    {
                        skill = (int) list_elem->data;
                    }
                }
            }

            if(input->was_key[KEY__A] && !input->is_key[KEY__A])
            {
                skill = SKILL__PICK_ITEM_CLOSE;
            }
            if(input->was_key[KEY__S] && !input->is_key[KEY__S])
            {
                skill = SKILL__PICK_ITEM_FAR;
            }
            if(input->was_key[KEY__D] && !input->is_key[KEY__D])
            {
                if(state->hero_item_number[ITEM__CELL] > 0)
                {
                    state->hero_curr_item = ITEM__CELL;
                    skill = SKILL__PUT_ITEM_CLOSE;
                }
            }
            if(input->was_key[KEY__F] && !input->is_key[KEY__F])
            {
                if(state->hero_item_number[ITEM__CELL] > 0)
                {
                    state->hero_curr_item = ITEM__CELL;
                    skill = SKILL__PUT_ITEM_FAR;
                }
            }
            if(input->was_key[KEY__G] && !input->is_key[KEY__G])
            {
                if(state->hero_item_number[ITEM__DYNAMITE] > 0)
                {
                    state->hero_curr_item = ITEM__DYNAMITE;
                    skill = SKILL__PUT_ITEM_CLOSE;
                }
            }
            if(input->was_key[KEY__H] && !input->is_key[KEY__H])
            {
                if(state->hero_item_number[ITEM__DYNAMITE] > 0)
                {
                    state->hero_curr_item = ITEM__DYNAMITE;
                    skill = SKILL__PUT_ITEM_FAR;
                }
            }
            if(input->was_key[KEY__J] && !input->is_key[KEY__J])
            {
                if(state->hero_item_number[ITEM__GEMSTONE] > 0)
                {
                    state->hero_curr_item = ITEM__GEMSTONE;
                    skill = SKILL__PUT_ITEM_CLOSE;
                }
            }
            if(input->was_key[KEY__K] && !input->is_key[KEY__K])
            {
                if(state->hero_item_number[ITEM__GEMSTONE] > 0)
                {
                    state->hero_curr_item = ITEM__GEMSTONE;
                    skill = SKILL__PUT_ITEM_FAR;
                }
            }

            if(input->was_key[KEY__Z] && !input->is_key[KEY__Z])
            {
                if(state->hero_item_number[ITEM__CELL] > 0)
                {
                    skill = SKILL__THROW_CELL;
                }
            }
            if(input->was_key[KEY__X] && !input->is_key[KEY__X])
            {
                if(state->hero_item_number[ITEM__DYNAMITE] > 0)
                {
                    skill = SKILL__THROW_DYNAMITE;
                }
            }
            if(input->was_key[KEY__C] && !input->is_key[KEY__C])
            {
                if(state->hero_item_number[ITEM__GEMSTONE] > 0)
                {
                    skill = SKILL__THROW_GEMSTONE;
                }
            }

            if(input->was_key[KEY__0] && !input->is_key[KEY__0])
            {
                state->prev_selected_tilemap_pos = vec2i(-1, -1);
                state->curr_selected_tilemap_pos = vec2i(-1, -1);

                execute_action_sequence(state, state->ally_action_sequence, textures, sounds, musics, colors);

                change_gamestate(state, GAMESTATE__HERO_EXECUTING_SKILL);
            }

            state->curr_ally_curr_skill = skill;
            state->is_curr_ally_skill_two_target = is_skill_two_target(skill);

            if(get_hero_ap(state) > 0 && skill != SKILL__NONE)
            {
                if(is_skill_two_target(skill))
                {
                    state->prev_selected_tilemap_pos = vec2i(-1, -1);
                    state->curr_selected_tilemap_pos = vec2i(-1, -1);

                    remove_all_pos_from_possible_target_1_tilemap_pos_list(state);

                    skill_get_possible_target_1_pos(
                        state,
                        state->curr_ally_curr_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->possible_target_1_tilemap_pos_list
                        );

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_1);
                }
                else
                {
                    state->prev_selected_tilemap_pos = vec2i(-1, -1);
                    state->curr_selected_tilemap_pos = vec2i(-1, -1);

                    remove_all_pos_from_possible_target_2_tilemap_pos_list(state);

                    skill_get_possible_target_2_pos(
                        state,
                        state->curr_ally_curr_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->possible_target_2_tilemap_pos_list
                        );

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_2);
                }
            }
        }
        break;
        case GAMESTATE__HERO_CHOOSING_TARGET_1:
        {
            if (input->was_key[KEY__Q] && !input->is_key[KEY__Q])
            {
                remove_all_actions_from_action_sequence(state->ally_action_sequence);

                change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);

                break;
            }

            state->curr_selected_tilemap_pos = state->mouse_tilemap_pos;

            if(is_tilemap_pos_in_possible_target_1_tilemap_pos_list(state, state->curr_selected_tilemap_pos))
            {
                if(input->was_mouse_left && !input->is_mouse_left)
                {
                    state->curr_ally_target_1_tilemap_pos = state->curr_selected_tilemap_pos;

                    state->prev_selected_tilemap_pos = vec2i(-1, -1);
                    state->curr_selected_tilemap_pos = vec2i(-1, -1);

                    remove_all_pos_from_possible_target_2_tilemap_pos_list(state);

                    skill_get_possible_target_2_pos(
                        state,
                        state->curr_ally_curr_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->possible_target_2_tilemap_pos_list
                        );

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_2);
                }
            }
        }
        break;
        case GAMESTATE__HERO_CHOOSING_TARGET_2:
        {
            if (input->was_key[KEY__Q] && !input->is_key[KEY__Q])
            {
                state->prev_selected_tilemap_pos = vec2i(-1, -1);
                state->curr_selected_tilemap_pos = vec2i(-1, -1);

                remove_all_actions_from_action_sequence(state->ally_action_sequence);

                if(is_skill_two_target(state->curr_ally_curr_skill))
                {
                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_1);
                }
                else
                {
                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                }

                break;
            }

            state->curr_selected_tilemap_pos = state->mouse_tilemap_pos;

            if(is_tilemap_pos_in_possible_target_2_tilemap_pos_list(state, state->curr_selected_tilemap_pos))
            {
                remove_all_actions_from_action_sequence(state->ally_action_sequence);

                state->curr_ally_target_2_tilemap_pos = state->curr_selected_tilemap_pos;

                skill_get_actions(
                    state,
                    state->ally_action_sequence,
                    state->curr_ally_curr_skill,
                    state->curr_ally->object->tilemap_pos,
                    state->curr_ally_target_1_tilemap_pos,
                    state->curr_ally_target_2_tilemap_pos
                    );

                if(input->was_mouse_left && !input->is_mouse_left)
                {
                    state->prev_selected_tilemap_pos = vec2i(-1, -1);
                    state->curr_selected_tilemap_pos = vec2i(-1, -1);

                    Animation* animation = skill_get_animation(
                        state,
                        state->curr_ally_curr_skill,
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
                        state->curr_ally_curr_skill,
                        state->curr_ally->object->tilemap_pos,
                        state->curr_ally_target_1_tilemap_pos,
                        state->curr_ally_target_2_tilemap_pos
                        );

                    state->curr_ally_skill_animation = animation;

                    change_gamestate(state, GAMESTATE__HERO_EXECUTING_ANIMATION);
                }
            }
        }
        break;
        case GAMESTATE__HERO_EXECUTING_ANIMATION:
        {
            if(state->curr_ally_skill_animation->is_finished)
            {
                state->curr_ally_skill_animation = 0;

                execute_action_sequence(
                    state,
                    state->ally_action_sequence,
                    textures,
                    sounds,
                    musics,
                    colors
                    );

                change_gamestate(state, GAMESTATE__HERO_EXECUTING_SKILL);
            }
        }
        break;
        case GAMESTATE__HERO_EXECUTING_SKILL:
        {
            if(state->ally_action_sequence->is_finished)
            {
                end_action(state, state->ally_action_sequence, state->ally_action_sequence, textures, sounds, musics, colors);

                for(ListElem* curr_elem = state->enemy_list->head;
                curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Enemy* curr_enemy = (Enemy*)curr_elem->data;
                    if(curr_enemy != 0)
                    {
                        curr_enemy->performed_attack = 0;
                        remove_all_actions_from_action_sequence(curr_enemy->action_sequence);
                        object_enemy_prepare_attack(state, curr_enemy);
                    }
                }

                remove_all_dead_objects(state);

                determine_enemy_list(state);
                determine_enemy_order(state);

                modify_hero_ap(state, -1);

                change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
            }
            else
            {
                update_action(state, state->ally_action_sequence, state->ally_action_sequence, delta_time, textures, sounds, musics, colors);
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK:
        {
            state->timer += delta_time;

            if(state->timer > 1.0f)
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

                state->curr_ally_skill_animation = animation;

                change_gamestate(state, GAMESTATE__ENEMY_EXECUTING_ANIMATION);
            }
        }
        break;
        case GAMESTATE__ENEMY_EXECUTING_ANIMATION:
        {
            if(state->curr_ally_skill_animation->is_finished)
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
            }
        }
        break;
        case GAMESTATE__ENEMY_EXECUTING_ATTACK:
        {
            if(state->enemy_action_sequence->is_finished)
            {
                state->curr_enemy->performed_attack = 1;

                end_action(state, state->enemy_action_sequence, state->enemy_action_sequence, textures, sounds, musics, colors);

                for(ListElem* curr_elem = state->enemy_list->head;
                curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Enemy* curr_enemy = (Enemy*)curr_elem->data;
                    if(!curr_enemy->performed_attack)
                    {
                        remove_all_actions_from_action_sequence(curr_enemy->action_sequence);
                        object_enemy_prepare_attack(state, curr_enemy);
                    }
                }

                if(state->curr_enemy_list_elem->next == 0)
                {
                    state->curr_enemy_list_elem =
                    state->enemy_list->head;

                    state->curr_enemy =
                    (Enemy*)state->curr_enemy_list_elem->data;

                    state->enemy_action_sequence =
                    (Action*)state->curr_enemy->action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE);
                    state->timer = 0.0f;
                }
                else
                {
                    state->curr_enemy_list_elem =
                    state->curr_enemy_list_elem->next;

                    state->curr_enemy =
                    (Enemy*)state->curr_enemy_list_elem->data;

                    state->enemy_action_sequence =
                    (Action*)state->curr_enemy->action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK);
                    state->timer = 0.0f;
                }
            }
            else
            {
                update_action(state, state->enemy_action_sequence, state->enemy_action_sequence, delta_time, textures, sounds, musics, colors);
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE:
        {
            state->timer += delta_time;

            if(state->timer > 0.5f)
            {
                state->timer = 0.0f;

                object_enemy_prepare_move(state, state->curr_enemy);

                execute_action_sequence(state, state->enemy_action_sequence, textures, sounds, musics, colors);

                change_gamestate(state, GAMESTATE__ENEMY_MOVING);
            }
        }
        break;
        case GAMESTATE__ENEMY_MOVING:
        {
            if(state->enemy_action_sequence->is_finished)
            {
                end_action(state, state->enemy_action_sequence, state->enemy_action_sequence, textures, sounds, musics, colors);

                for(ListElem* curr_elem = state->enemy_list->head;
                curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Enemy* curr_enemy = (Enemy*)curr_elem->data;
                    if(!curr_enemy->performed_attack)
                    {
                        remove_all_actions_from_action_sequence(curr_enemy->action_sequence);
                        object_enemy_prepare_attack(state, curr_enemy);
                    }
                }

                if(state->curr_enemy->object->is_dead)
                {
                    if(state->curr_enemy_list_elem->next == 0)
                    {
                        remove_all_dead_objects(state);

                        add_animation_to_animation_list(state,new_animation_change_background_color(state->background_color,colors->hero_background, 0.25f), textures, sounds, musics, colors);

                        change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                    }
                    else
                    {
                        state->curr_enemy_list_elem =
                        state->curr_enemy_list_elem->next;

                        state->curr_enemy =
                        (Enemy*)state->curr_enemy_list_elem->data;

                        state->enemy_action_sequence =
                        (Action*)state->curr_enemy->action_sequence;

                        change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE);
                        state->timer = 0.0f;
                    }
                }
                else
                {
                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET);
                    state->timer = 0.0f;
                }
            }
            else
            {
                update_action(state, state->enemy_action_sequence, state->enemy_action_sequence, delta_time, textures, sounds, musics, colors);
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET:
        {
            state->timer += delta_time;

            if(state->timer > 1.0f)
            {
                state->timer = 0.0f;

                remove_all_actions_from_action_sequence(state->enemy_action_sequence);
                object_enemy_prepare_attack(state, state->curr_enemy);

                state->curr_enemy->performed_attack = 0;

                if(state->curr_enemy_list_elem->next == 0)
                {
                    remove_all_dead_objects(state);

                    determine_enemy_list(state);
                    determine_enemy_order(state);

                    add_animation_to_animation_list(state,new_animation_change_background_color(state->background_color,colors->hero_background, 0.25f), textures, sounds, musics, colors);

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                }
                else
                {
                    state->curr_enemy_list_elem =
                    state->curr_enemy_list_elem->next;

                    state->curr_enemy =
                    (Enemy*)state->curr_enemy_list_elem->data;

                    state->enemy_action_sequence =
                    (Action*)state->curr_enemy->action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE);
                    state->timer = 0.0f;
                }
            }
        }
        break;
        default:
        break;
    }
}
