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

            int skill = SKILL__NONE;

            if(input->was_up && !input->is_up) skill = SKILL__MOVE;
            if(input->was_right && !input->is_right) skill = SKILL__PUSH;
            if(input->was_down && !input->is_down) skill = SKILL__THROW;
            if(input->was_left && !input->is_left) skill = SKILL__PULL;

            state->gamemap.curr_skill = skill;
            state->gamemap.is_skill_two_target = is_skill_two_target(skill);

            if(skill != SKILL__NONE)
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
                remove_all_actions_from_main_action_sequence(state);

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

                remove_all_actions_from_main_action_sequence(state);

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
                remove_all_actions_from_main_action_sequence(state);

                state->gamemap.target_2_tilemap_pos = state->gamemap.curr_selected_tilemap_pos;

                skill_get_actions_to_execute(
                    state,
                    state->action.main_action_sequence,
                    state->gamemap.curr_skill,
                    state->gamemap.object_hero->tilemap_pos,
                    state->gamemap.target_1_tilemap_pos,
                    state->gamemap.target_2_tilemap_pos
                    );

                if(input->was_mouse_left && !input->is_mouse_left)
                {
                    state->gamemap.prev_selected_tilemap_pos = make_vec2i(-1, -1);
                    state->gamemap.curr_selected_tilemap_pos = make_vec2i(-1, -1);

                    execute_actions(state, textures, sounds, musics);

                    change_gamestate(state, GAMESTATE__HERO_EXECUTING_SKILL);
                }
            }
        }
        break;
        case GAMESTATE__HERO_EXECUTING_SKILL:
        {
            if(state->action.main_action_sequence->is_finished)
            {
                end_action(state, state->action.main_action_sequence, state->action.main_action_sequence, textures, sounds, musics);
                change_gamestate(state, GAMESTATE__HERO_CHOOSING_SKILL);
            }
            else
            {
                update_action(state, state->action.main_action_sequence, state->action.main_action_sequence, delta_time, textures, sounds, musics);
            }
        }
        break;
        default:
        break;
    }
}
