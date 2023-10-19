#include "../inc/state.h"

void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics)
{
    // quit

    if(input->is_quit)
    {
        state->is_game_running = 0;
    }

    // camera

    if(input->is_mouse_scrolling)
    {
        float change_camera_zoom_by = input->mouse_scrolled * state->camera.zoom * delta_time * 10.0f;
        state->camera.zoom += change_camera_zoom_by;
    }

    // mouse

    vec2i mouse_screen_pos;
    vec2f mouse_world_pos;
    vec2f mouse_gamemap_pos;
    vec2i mouse_tilemap_pos;

    mouse_screen_pos = make_vec2i(input->mouse_x, input->mouse_y);
    mouse_world_pos = screen_pos_to_world_pos(mouse_screen_pos, state->camera.world_pos, state->camera.zoom);
    mouse_world_pos.x -= TILE_LENGTH * 0.5f;
    mouse_gamemap_pos = world_pos_to_gamemap_pos(iso_pos_to_cart_pos(mouse_world_pos));
    mouse_tilemap_pos = gamemap_pos_to_tilemap_pos(mouse_gamemap_pos);

    state->mouse.screen_pos = mouse_screen_pos;
    state->mouse.world_pos = mouse_world_pos;
    state->mouse.gamemap_pos = mouse_gamemap_pos;
    state->mouse.tilemap_pos = mouse_tilemap_pos;

    // drag

    if(!input->was_mouse_left && input->is_mouse_left)
    {
        state->mouse.is_dragging = 1;
        state->mouse.drag_origin_world_pos = state->mouse.world_pos;
    }
    else if(input->was_mouse_left && !input->is_mouse_left)
    {
        state->mouse.is_dragging = 0;
    }
    else if(input->is_mouse_left)
    {
        vec2f drag_world_diff;
        vec2f new_camera_world_pos;

        drag_world_diff.x = state->mouse.world_pos.x - state->camera.world_pos.x;
        drag_world_diff.y = state->mouse.world_pos.y - state->camera.world_pos.y;

        new_camera_world_pos.x = state->mouse.drag_origin_world_pos.x - drag_world_diff.x;
        new_camera_world_pos.y = state->mouse.drag_origin_world_pos.y - drag_world_diff.y;

        state->camera.world_pos = new_camera_world_pos;
    }

    // gamestate

    if(state->gamemap.object_hero == 0)
    {
        change_gamestate(state, GAMESTATE__NONE);
    }

    switch(state->gamestate)
    {
        case GAMESTATE__NONE:
        {
            //
        }
        break;
        case GAMESTATE__HERO_CHOOSING_SKILL:
        {
            if (input->was_esc && !input->is_esc)
            {
                state->is_game_running = 0;

                break;
            }

            if(input->was_enter && !input->is_enter)
            {
                restore_hero_ap(state);

                if(state->gamemap.object_enemy_list->size > 0)
                {
                    state->gamemap.curr_object_enemy_list_elem =
                    state->gamemap.object_enemy_list->head;

                    state->gamemap.curr_object_enemy =
                    (Object*)state->gamemap.curr_object_enemy_list_elem->data;

                    state->action.enemy_action_sequence =
                    (Action*)state->gamemap.curr_object_enemy->enemy_action_sequence;

                    change_background_color(state, make_vec3i(200, 50, 50));

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

            if(input->was_1 && !input->is_1) skill = SKILL__CHARGE;
            if(input->was_2 && !input->is_2) skill = SKILL__FLY;
            if(input->was_3 && !input->is_3) skill = SKILL__JUMP;
            if(input->was_4 && !input->is_4) skill = SKILL__CHARGE_AND_PUSH;
            if(input->was_5 && !input->is_5) skill = SKILL__CHARGE_AND_THROW;
            if(input->was_6 && !input->is_6) skill = SKILL__PUSH;
            if(input->was_7 && !input->is_7) skill = SKILL__PULL;
            if(input->was_8 && !input->is_8) skill = SKILL__PULL_AND_THROW;
            if(input->was_9 && !input->is_9) skill = SKILL__THROW;

            if(input->was_0 && !input->is_0)
            {
                state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                execute_action_sequence(state, state->action.hero_action_sequence, textures, sounds, musics);

                change_gamestate(state, GAMESTATE__HERO_EXECUTING_SKILL);
            }

            state->gamemap.curr_skill = skill;
            state->gamemap.is_skill_two_target = is_skill_two_target(skill);

            if(get_hero_ap(state) > 0 && skill != SKILL__NONE)
            {
                if(is_skill_two_target(skill))
                {
                    state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                    state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                    remove_all_pos_from_possible_target_1_tilemap_pos_list(state);

                    skill_add_pos_to_possible_target_1_tilemap_pos_list(
                            state,
                            state->gamemap.curr_skill,
                            state->gamemap.object_hero->tilemap_pos
                            );

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_1);
                }
                else
                {
                    state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                    state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                    remove_all_pos_from_possible_target_2_tilemap_pos_list(state);

                    skill_add_pos_to_possible_target_2_tilemap_pos_list(
                            state,
                            state->gamemap.curr_skill,
                            state->gamemap.object_hero->tilemap_pos,
                            state->gamemap.target_1_tilemap_pos
                            );

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_2);
                }
            }
        }
        break;
        case GAMESTATE__HERO_CHOOSING_TARGET_1:
        {
            if (input->was_esc && !input->is_esc)
            {
                remove_all_actions_from_action_sequence(state->action.hero_action_sequence);

                change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);

                break;
            }

            state->gamemap.curr_selected_tilemap_pos = state->mouse.tilemap_pos;

            if(is_tilemap_pos_in_possible_target_1_tilemap_pos_list(state, state->gamemap.curr_selected_tilemap_pos))
            {
                if(input->was_mouse_left && !input->is_mouse_left)
                {
                    state->gamemap.target_1_tilemap_pos = state->gamemap.curr_selected_tilemap_pos;

                    state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                    state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                    remove_all_pos_from_possible_target_2_tilemap_pos_list(state);

                    skill_add_pos_to_possible_target_2_tilemap_pos_list(
                        state,
                        state->gamemap.curr_skill,
                        state->gamemap.object_hero->tilemap_pos,
                        state->gamemap.target_1_tilemap_pos
                        );

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_2);
                }
            }
        }
        break;
        case GAMESTATE__HERO_CHOOSING_TARGET_2:
        {
            if (input->was_esc && !input->is_esc)
            {
                state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                remove_all_actions_from_action_sequence(state->action.hero_action_sequence);

                if(is_skill_two_target(state->gamemap.curr_skill))
                {
                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_TARGET_1);
                }
                else
                {
                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                }

                break;
            }

            state->gamemap.curr_selected_tilemap_pos = state->mouse.tilemap_pos;

            if(is_tilemap_pos_in_possible_target_2_tilemap_pos_list(state, state->gamemap.curr_selected_tilemap_pos))
            {
                remove_all_actions_from_action_sequence(state->action.hero_action_sequence);

                state->gamemap.target_2_tilemap_pos = state->gamemap.curr_selected_tilemap_pos;

                skill_add_actions_to_action_sequence(
                    state,
                    state->action.hero_action_sequence,
                    state->gamemap.curr_skill,
                    state->gamemap.object_hero->tilemap_pos,
                    state->gamemap.target_1_tilemap_pos,
                    state->gamemap.target_2_tilemap_pos
                    );

                if(input->was_mouse_left && !input->is_mouse_left)
                {
                    state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                    state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                    execute_action_sequence(state, state->action.hero_action_sequence, textures, sounds, musics);

                    change_gamestate(state, GAMESTATE__HERO_EXECUTING_SKILL);
                }
            }
        }
        break;
        case GAMESTATE__HERO_EXECUTING_SKILL:
        {
            if(state->action.hero_action_sequence->is_finished)
            {
                end_action(state, state->action.hero_action_sequence, state->action.hero_action_sequence, textures, sounds, musics);

                for(ListElem* curr_elem = state->gamemap.object_enemy_list->head;
                curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Object* curr_object = (Object*)curr_elem->data;
                    if(!curr_object->is_dead)
                    {
                        curr_object->enemy_performed_attack = 0;
                        remove_all_actions_from_action_sequence(curr_object->enemy_action_sequence);
                        object_enemy_add_actions_to_action_sequence_attack(state, curr_object->enemy_action_sequence, curr_object);
                    }
                }

                remove_all_dead_objects_from_gamemap_objects(state);

                modify_hero_ap(state, -1);

                change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
            }
            else
            {
                update_action(state, state->action.hero_action_sequence, state->action.hero_action_sequence, delta_time, textures, sounds, musics);
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK:
        {
            state->timer += delta_time;

            if(state->timer > 0.5f)
            {
                state->timer = 0.0f;

                execute_action_sequence(state, state->action.enemy_action_sequence, textures, sounds, musics);

                change_gamestate(state, GAMESTATE__ENEMY_ATTACKING);
            }
        }
        break;
        case GAMESTATE__ENEMY_ATTACKING:
        {
            if(state->action.enemy_action_sequence->is_finished)
            {
                state->gamemap.curr_object_enemy->enemy_performed_attack = 1;

                end_action(state, state->action.enemy_action_sequence, state->action.enemy_action_sequence, textures, sounds, musics);

                for(ListElem* curr_elem = state->gamemap.object_enemy_list->head;
                curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Object* curr_object = (Object*)curr_elem->data;
                    if(!curr_object->is_dead && !curr_object->enemy_performed_attack)
                    {
                        remove_all_actions_from_action_sequence(curr_object->enemy_action_sequence);
                        object_enemy_add_actions_to_action_sequence_attack(state, curr_object->enemy_action_sequence, curr_object);
                    }
                }

                if(state->gamemap.curr_object_enemy_list_elem->next == 0)
                {
                    state->gamemap.curr_object_enemy_list_elem =
                    state->gamemap.object_enemy_list->head;

                    state->gamemap.curr_object_enemy =
                    (Object*)state->gamemap.curr_object_enemy_list_elem->data;

                    state->action.enemy_action_sequence =
                    (Action*)state->gamemap.curr_object_enemy->enemy_action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE);
                    state->timer = 0.0f;
                }
                else
                {
                    state->gamemap.curr_object_enemy_list_elem =
                    state->gamemap.curr_object_enemy_list_elem->next;

                    state->gamemap.curr_object_enemy =
                    (Object*)state->gamemap.curr_object_enemy_list_elem->data;

                    state->action.enemy_action_sequence =
                    (Action*)state->gamemap.curr_object_enemy->enemy_action_sequence;

                    change_gamestate(state, GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK);
                    state->timer = 0.0f;
                }
            }
            else
            {
                update_action(state, state->action.enemy_action_sequence, state->action.enemy_action_sequence, delta_time, textures, sounds, musics);
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE:
        {
            state->timer += delta_time;

            if(state->timer > 0.5f)
            {
                state->timer = 0.0f;

                object_enemy_add_actions_to_action_sequence_move(state, state->action.enemy_action_sequence, state->gamemap.curr_object_enemy);

                execute_action_sequence(state, state->action.enemy_action_sequence, textures, sounds, musics);

                change_gamestate(state, GAMESTATE__ENEMY_MOVING);
            }
        }
        break;
        case GAMESTATE__ENEMY_MOVING:
        {
            if(state->action.enemy_action_sequence->is_finished)
            {
                end_action(state, state->action.enemy_action_sequence, state->action.enemy_action_sequence, textures, sounds, musics);

                for(ListElem* curr_elem = state->gamemap.object_enemy_list->head;
                curr_elem != 0; curr_elem = curr_elem->next)
                {
                    Object* curr_object = (Object*)curr_elem->data;
                    if(!curr_object->is_dead && !curr_object->enemy_performed_attack)
                    {
                        remove_all_actions_from_action_sequence(curr_object->enemy_action_sequence);
                        object_enemy_add_actions_to_action_sequence_attack(state, curr_object->enemy_action_sequence, curr_object);
                    }
                }

                if(state->gamemap.curr_object_enemy->is_dead)
                {
                    if(state->gamemap.curr_object_enemy_list_elem->next == 0)
                    {
                        remove_all_dead_objects_from_gamemap_objects(state);

                        change_background_color(state, make_vec3i(100, 160, 220));

                        change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                    }
                    else
                    {
                        state->gamemap.curr_object_enemy_list_elem =
                        state->gamemap.curr_object_enemy_list_elem->next;

                        state->gamemap.curr_object_enemy =
                        (Object*)state->gamemap.curr_object_enemy_list_elem->data;

                        state->action.enemy_action_sequence =
                        (Action*)state->gamemap.curr_object_enemy->enemy_action_sequence;

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
                update_action(state, state->action.enemy_action_sequence, state->action.enemy_action_sequence, delta_time, textures, sounds, musics);
            }
        }
        break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET:
        {
            state->timer += delta_time;

            if(state->timer > 0.5f)
            {
                state->timer = 0.0f;

                remove_all_actions_from_action_sequence(state->action.enemy_action_sequence);
                object_enemy_add_actions_to_action_sequence_attack(state, state->action.enemy_action_sequence, state->gamemap.curr_object_enemy);

                state->gamemap.curr_object_enemy->enemy_performed_attack = 0;

                if(state->gamemap.curr_object_enemy_list_elem->next == 0)
                {
                    remove_all_dead_objects_from_gamemap_objects(state);

                    change_background_color(state, make_vec3i(100, 160, 220));

                    change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
                }
                else
                {
                    state->gamemap.curr_object_enemy_list_elem =
                    state->gamemap.curr_object_enemy_list_elem->next;

                    state->gamemap.curr_object_enemy =
                    (Object*)state->gamemap.curr_object_enemy_list_elem->data;

                    state->action.enemy_action_sequence =
                    (Action*)state->gamemap.curr_object_enemy->enemy_action_sequence;

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
