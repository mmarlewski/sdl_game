#include "state.h"

void update_state (Input* input, State* state, float delta_time, Textures* textures, Sounds* sounds, Musics* musics)
{
    if (input->is_quit || input->was_esc)
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

    // gamemap

    // action

    if(state->action.is_executing_actions)
    {
        if(state->action.action_sequence->is_finished)
        {
            state->action.is_executing_actions = 0;
        }
        else
        {
            update_action(state, state->action.action_sequence, delta_time, textures, sounds, musics);
        }
    }
    else
    {
        int dir = DIR4__NONE;
        int dir_opp = DIR4__NONE;
        int is_move_with_push = 0;

        if(input->is_mouse_left)
        {
            is_move_with_push = 1;
        }

        if (input->was_up && !input->is_up)
        {
            dir = DIR4__UP;
            dir_opp = DIR4__DOWN;
        }

        if (input->was_right && !input->is_right)
        {
            dir = DIR4__RIGHT;
            dir_opp = DIR4__LEFT;
        }

        if (input->was_down && !input->is_down)
        {
            dir = DIR4__DOWN;
            dir_opp = DIR4__UP;
        }

        if (input->was_left && !input->is_left)
        {
            dir = DIR4__LEFT;
            dir_opp = DIR4__RIGHT;
        }

        if(dir != DIR4__NONE && !is_move_with_push)
        {
            Object* object_acting = state->gamemap.object_acting;

            if(object_acting)
            {
                add_action_to_end_after_action(state->action.action_sequence->sequence.action_head, new_action_move(object_acting, dir));
                execute_actions(state, textures, sounds, musics);
            }
        }

        if(dir != DIR4__NONE && is_move_with_push)
        {
            Object* object_acting = state->gamemap.object_acting;
            Object* object_pushed = 0;

            if(object_acting)
            {
                vec2i object_acting_tilemap_pos = object_acting->tilemap_pos;
                vec2i object_pushed_tilemap_pos = move_vec2i_in_dir4_by(object_acting_tilemap_pos, dir, 1);

                object_pushed = get_object_on_tilemap_pos(state, object_pushed_tilemap_pos);
                if(object_pushed)
                {
                    Action* push_pushed = new_action_sequence();
                    add_action_to_end_after_action(push_pushed->sequence.action_head, new_action_push(object_pushed, dir));
                    add_action_to_end_after_action(push_pushed->sequence.action_head, new_action_push(object_pushed, dir));
                    add_action_to_end_after_action(push_pushed->sequence.action_head, new_action_push(object_pushed, dir));

                    Action* move_acting = new_action_sequence();
                    add_action_to_end_after_action(move_acting->sequence.action_head, new_action_move(object_acting, dir_opp));
                    add_action_to_end_after_action(move_acting->sequence.action_head, new_action_move(object_acting, dir_opp));
                    add_action_to_end_after_action(move_acting->sequence.action_head, new_action_move(object_acting, dir_opp));

                    Action* push_and_move = new_action_simultaneous();
                    add_action_sequence_to_action_simultaneous(push_and_move, push_pushed);
                    add_action_sequence_to_action_simultaneous(push_and_move, move_acting);
                    add_action_to_end_after_action(state->action.action_sequence->sequence.action_head, push_and_move);
                }
                else
                {
                    for(int i = 0; i < 3; i++)
                    {
                        add_action_to_end_after_action(state->action.action_sequence->sequence.action_head, new_action_move(object_acting, dir));
                        
                        object_acting_tilemap_pos = move_vec2i_in_dir4_by(object_acting_tilemap_pos, dir, 1);
                        object_pushed_tilemap_pos = move_vec2i_in_dir4_by(object_pushed_tilemap_pos, dir, 1);

                        object_pushed = get_object_on_tilemap_pos(state, object_pushed_tilemap_pos);
                        if(object_pushed)
                        {
                            add_action_to_end_after_action(state->action.action_sequence->sequence.action_head, new_action_push(object_pushed, dir));
                            add_action_to_end_after_action(state->action.action_sequence->sequence.action_head, new_action_push(object_pushed, dir));
                            add_action_to_end_after_action(state->action.action_sequence->sequence.action_head, new_action_push(object_pushed, dir));
                            break;
                        }
                    }
                }

                execute_actions(state, textures, sounds, musics);
            }
        }
    }
}