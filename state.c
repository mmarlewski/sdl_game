#include "state.h"

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics)
{
    state->is_game_running = 1;

    // camera

    state->camera.world_pos = make_vec2f(0, 0);
    state->camera.zoom = 2.0f;

    // mouse

    state->mouse.screen_pos = make_vec2i(0, 0);
    state->mouse.world_pos = make_vec2f(0, 0);
    state->mouse.gamemap_pos = make_vec2f(0, 0);
    state->mouse.tilemap_pos = make_vec2i(0, 0);
    state->mouse.is_dragging = 0;
    state->mouse.drag_origin_world_pos = make_vec2f(0, 0);

    // gamemap

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            state->gamemap.tilemap[i][j] = malloc(sizeof(*state->gamemap.tilemap[i][j]));
            state->gamemap.tilemap[i][j]->floor = FLOOR_TYPE__METAL;
        }
    }

    state->gamemap.object_head = 0;
    state->gamemap.object_tail = 0;

    state->gamemap.object_hero = 0;
    state->gamemap.object_acting = 0;

    state->gamemap.danger_tilemap_pos_head = 0;
    state->gamemap.danger_tilemap_pos_tail = 0;

    state->gamemap.highlight_tilemap_pos = make_vec2i(1,1);

    state->gamemap.sprite_head = 0;
    state->gamemap.sprite_tail = 0;

    // action

    state->action.is_executing_actions = 0;
    state->action.curr_action = 0;
    state->action.action_head = 0;
    state->action.action_tail = 0;
}

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
        if(state->action.curr_action)
        {
            if(state->action.curr_action->is_finished)
            {
                end_action(state, state->action.curr_action, textures, sounds, musics);
                Action* next_action = state->action.curr_action->next;
                destroy_action(state->action.curr_action);
                state->action.curr_action = next_action;

                if(state->action.curr_action)
                {
                    start_action(state, state->action.curr_action, textures, sounds, musics);
                }
            }
            else
            {
                update_action(state, state->action.curr_action, delta_time, textures, sounds, musics);
            }
        }
        else
        {
            state->action.is_executing_actions = 0;
        }
    }
    else
    {
        if (input->was_up && !input->is_up)
        {
            Object* object_acting = state->gamemap.object_acting;

            if(object_acting)
            {
                add_action_to_end_actions(state, new_action_move(object_acting, DIR4__UP));
                execute_actions(state, textures, sounds, musics);
            }
        }

        if (input->was_right && !input->is_right)
        {
            Object* object_acting = state->gamemap.object_acting;

            if(object_acting)
            {
                add_action_to_end_actions(state, new_action_move(object_acting, DIR4__RIGHT));
                execute_actions(state, textures, sounds, musics);
            }
        }

        if (input->was_down && !input->is_down)
        {
            Object* object_acting = state->gamemap.object_acting;

            if(object_acting)
            {
                add_action_to_end_actions(state, new_action_move(object_acting, DIR4__DOWN));
                execute_actions(state, textures, sounds, musics);
            }
        }

        if (input->was_left && !input->is_left)
        {
            Object* object_acting = state->gamemap.object_acting;

            if(object_acting)
            {
                add_action_to_end_actions(state, new_action_move(object_acting, DIR4__LEFT));
                execute_actions(state, textures, sounds, musics);
            }
        }
    }
}

// gamemap

int is_tilemap_pos_in_tilemap(vec2i tilemap_pos)
{
    return (tilemap_pos.x >= 0 && tilemap_pos.x < TILEMAP_WIDTH && tilemap_pos.y >= 0 && tilemap_pos.y < TILEMAP_HEIGHT);
}

Object* get_object_on_tilemap_pos(State* state, vec2i tilemap_pos)
{
    if(!is_tilemap_pos_in_tilemap(tilemap_pos)) return 0;

    for(Object* curr_object = state->gamemap.object_head; curr_object; curr_object = curr_object->next)
    {
        if(curr_object->tilemap_pos.x == tilemap_pos.x && curr_object->tilemap_pos.y == tilemap_pos.y)
        {
            return curr_object;
        }
    }

    return 0;
}

int get_floor_on_tilemap_pos(State* state, vec2i tilemap_pos)
{
    if(!is_tilemap_pos_in_tilemap(tilemap_pos)) return 0;

    Tile* tile = state->gamemap.tilemap[tilemap_pos.y][tilemap_pos.x];
    
    return (tile) ? (tile->floor) : (0);
}

void change_floor_in_tilemap_pos(State* state, int new_floor, vec2i tilemap_pos)
{
    if(!is_tilemap_pos_in_tilemap(tilemap_pos)) return;

    Tile* tile = state->gamemap.tilemap[tilemap_pos.y][tilemap_pos.x];

    tile->floor = new_floor;
}

void add_object_to_gamemap_objects(State* state, Object* new_object)
{
    if(state->gamemap.object_head)
    {
        state->gamemap.object_tail->next = new_object;
    }
    else
    {
        state->gamemap.object_head = new_object;
    }

    state->gamemap.object_tail = new_object;
    new_object->next = 0;
}

void remove_object_from_gamemap_objects(State* state, Object* object)
{
    if(state->gamemap.object_acting == object)
    {
        state->gamemap.object_acting = 0;
    }

    Object* prev_object = 0;
    Object* curr_object = state->gamemap.object_head;
    Object* next_object = (curr_object) ? (curr_object->next) : (0);

    while(curr_object)
    {
        if(curr_object == object)
        {
            destroy_object(curr_object);

            if(curr_object == state->gamemap.object_head)
            {
                state->gamemap.object_head = next_object;
            }

            if(curr_object == state->gamemap.object_tail)
            {
                state->gamemap.object_tail = prev_object;
            }

            if(prev_object)
            {
                prev_object->next = next_object;
            }

            return;
        }
        else
        {
            prev_object = curr_object;
            curr_object = curr_object->next;
            next_object = (curr_object) ? (curr_object->next) : (0);
        }
    }

    return;
}

void add_pos_to_gamemap_danger_pos(State* state, vec2i* new_pos)
{
    if(state->gamemap.danger_tilemap_pos_head)
    {
        state->gamemap.danger_tilemap_pos_tail->next = new_pos;
    }
    else
    {
        state->gamemap.danger_tilemap_pos_head = new_pos;
    }

    state->gamemap.danger_tilemap_pos_tail = new_pos;
    new_pos->next = 0;
}

void remove_pos_from_gamemap_danger_pos(State* state, vec2i* pos)
{
    vec2i* prev_pos = 0;
    vec2i* curr_pos = state->gamemap.danger_tilemap_pos_head;
    vec2i* next_pos = (curr_pos) ? (curr_pos->next) : (0);

    while(curr_pos)
    {
        if(curr_pos == pos)
        {
            destroy_vec2i(curr_pos);

            if(curr_pos == state->gamemap.danger_tilemap_pos_head)
            {
                state->gamemap.danger_tilemap_pos_head = next_pos;
            }

            if(curr_pos == state->gamemap.danger_tilemap_pos_tail)
            {
                state->gamemap.danger_tilemap_pos_tail = prev_pos;
            }

            if(prev_pos)
            {
                prev_pos->next = next_pos;
            }

            return;
        }
        else
        {
            prev_pos = curr_pos;
            curr_pos = curr_pos->next;
            next_pos = (curr_pos) ? (curr_pos->next) : (0);
        }
    }

    return;
}

void remove_all_pos_from_gamemap_danger_pos(State* state)
{
    vec2i* curr_pos = state->gamemap.danger_tilemap_pos_head;
    vec2i* next_pos = (curr_pos) ? (curr_pos->next) : (0);
    while(curr_pos)
    {
        next_pos = (curr_pos) ? (curr_pos->next) : (0);
        destroy_vec2i(curr_pos);
        curr_pos = next_pos;
    }

    state->gamemap.danger_tilemap_pos_head = 0;
    state->gamemap.danger_tilemap_pos_tail = 0;
}

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite)
{
    if(state->gamemap.sprite_head)
    {
        state->gamemap.sprite_tail->next = new_sprite;
    }
    else
    {
        state->gamemap.sprite_head = new_sprite;
    }

    state->gamemap.sprite_tail = new_sprite;
    new_sprite->next = 0;
}

void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite)
{
    Sprite* prev_sprite = 0;
    Sprite* curr_sprite = state->gamemap.sprite_head;
    Sprite* next_sprite = (curr_sprite) ? (curr_sprite->next) : (0);

    while(curr_sprite)
    {
        if(curr_sprite == sprite)
        {
            destroy_sprite(curr_sprite);

            if(curr_sprite == state->gamemap.sprite_head)
            {
                state->gamemap.sprite_head = next_sprite;
            }

            if(curr_sprite == state->gamemap.sprite_tail)
            {
                state->gamemap.sprite_tail = prev_sprite;
            }

            if(prev_sprite)
            {
                prev_sprite->next = next_sprite;
            }

            return;
        }
        else
        {
            prev_sprite = curr_sprite;
            curr_sprite = curr_sprite->next;
            next_sprite = (curr_sprite) ? (curr_sprite->next) : (0);
        }
    }

    return;
}

void remove_all_sprites_from_gamemap_sprites(State* state)
{
    Sprite* curr_sprite = state->gamemap.sprite_head;
    Sprite* next_sprite = (curr_sprite) ? (curr_sprite->next) : (0);
    while(curr_sprite)
    {
        next_sprite = (curr_sprite) ? (curr_sprite->next) : (0);
        destroy_sprite(curr_sprite);
        curr_sprite = next_sprite;
    }

    state->gamemap.sprite_head = 0;
    state->gamemap.sprite_tail = 0;
}

// action

void add_action_to_end_actions(State* state, Action* new_action)
{
    if(state->action.action_head)
    {
        state->action.action_tail->next = new_action;
    }
    else
    {
        state->action.action_head = new_action;
    }

    state->action.action_tail = new_action;
    new_action->next = 0;
}

void add_action_after_curr_action(State* state, Action* new_action)
{
    if(state->action.curr_action)
    {
        new_action->next = state->action.curr_action->next;
        state->action.curr_action->next = new_action;
    }
}

void remove_all_actions_after_curr_action(State* state)
{
    Action* curr_action = state->action.curr_action->next;
    Action* next_action = (curr_action) ? (curr_action->next) : 0;
    while(curr_action)
    {
        destroy_action(curr_action);
        curr_action = next_action;
        next_action = (curr_action) ? (curr_action->next) : 0;
    }
    state->action.curr_action->next = 0;
}

void execute_actions(State* state, Textures* textures, Sounds* sounds, Musics* musics)
{
    state->action.is_executing_actions = 1;
    state->action.curr_action = state->action.action_head;
    state->action.action_head = 0;
    state->action.action_tail = 0;

    if(state->action.curr_action)
    {
        start_action(state, state->action.curr_action, textures, sounds, musics);
    }
}

Action* get_action_from_floor_on_action(Action* action_trigger, int floor)
{
    Action* action_result = new_action_sequence();

    switch(action_trigger->type)
    {
        case ACTION_TYPE__MOVE:
        {
            switch(floor)
            {
                case FLOOR_TYPE__ROCK:
                {
                    //
                }
                break;
                case FLOOR_TYPE__STONE:
                {
                    //
                }
                break;
                case FLOOR_TYPE__METAL:
                {
                    //
                }
                break;
                case FLOOR_TYPE__GRASS:
                {
                    //
                }
                break;
                case FLOOR_TYPE__WATER:
                {
                    printf("dropped into water ! \n");

                    Action* drop = new_action_drop(action_trigger->move.object);
                    Action* death = new_action_death(action_trigger->move.object);

                    add_action_to_end_action_sequence(action_result, drop);
                    add_action_to_end_action_sequence(action_result, death);
                }
                break;
                case FLOOR_TYPE__LAVA:
                {
                    printf("dropped into lava ! \n");

                    Action* drop = new_action_drop(action_trigger->move.object);
                    Action* death = new_action_death(action_trigger->move.object);

                    add_action_to_end_action_sequence(action_result, drop);
                    add_action_to_end_action_sequence(action_result, death);
                }
                break;
                default:
                break;
            }
        }
        break;
        default:
        break;
    }

    return action_result;
}