#include "../inc/state.h"

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics)
{
    state->is_game_running = 1;
    state->gamestate = GAMESTATE__NONE;

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

    state->gamemap.sprite_head = 0;
    state->gamemap.sprite_tail = 0;

    state->gamemap.selected_tilemap_pos = make_vec2i(0, 0);

    state->gamemap.curr_skill = 0;
    state->gamemap.is_skill_two_target = 0;

    state->gamemap.possible_target_1_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);
    state->gamemap.possible_target_2_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);

    state->gamemap.target_1_tilemap_pos = make_vec2i(0, 0);
    state->gamemap.target_2_tilemap_pos = make_vec2i(0, 0);

    // action

    state->action.is_executing_actions = 0;
    state->action.main_action_sequence = new_action_sequence();
}

void change_gamestate(State* state, int new_gamestate)
{
    state->gamestate = new_gamestate;
    printf("\n");
    printf("gamestate: %s \n", get_gamestate_name(new_gamestate));
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
    if(state->gamemap.object_hero == object)
    {
        state->gamemap.object_hero = 0;
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

void add_pos_to_possible_target_1_tilemap_pos_list(State* state, vec2i* new_pos)
{
    add_new_list_element_to_list_end(state->gamemap.possible_target_1_tilemap_pos_list, new_pos);
}

void remove_all_pos_from_possible_target_1_tilemap_pos_list(State* state)
{
    remove_all_list_elements(state->gamemap.possible_target_1_tilemap_pos_list, 1);
}

int is_tilemap_pos_in_possible_target_1_tilemap_pos_list(State* state, vec2i pos)
{
    for(ListElem* curr_elem = state->gamemap.possible_target_1_tilemap_pos_list->head; curr_elem; curr_elem = curr_elem->next )
    {
        vec2i* curr_vec = (vec2i*)curr_elem->data;
        if(curr_vec->x == pos.x && curr_vec->y == pos.y) return 1;
    }

    return 0;
}

void add_pos_to_possible_target_2_tilemap_pos_list(State* state, vec2i* new_pos)
{
    add_new_list_element_to_list_end(state->gamemap.possible_target_2_tilemap_pos_list, new_pos);
}

void remove_all_pos_from_possible_target_2_tilemap_pos_list(State* state)
{
    remove_all_list_elements(state->gamemap.possible_target_2_tilemap_pos_list, 1);
}

int is_tilemap_pos_in_possible_target_2_tilemap_pos_list(State* state, vec2i pos)
{
    for(ListElem* curr_elem = state->gamemap.possible_target_2_tilemap_pos_list->head; curr_elem; curr_elem = curr_elem->next )
    {
        vec2i* curr_vec = (vec2i*)curr_elem->data;
        if(curr_vec->x == pos.x && curr_vec->y == pos.y) return 1;
    }

    return 0;
}

// action

void execute_actions(State* state, Textures* textures, Sounds* sounds, Musics* musics)
{
    state->action.is_executing_actions = 1;
    state->action.main_action_sequence->is_finished = 0;

    start_action(state, state->action.main_action_sequence, state->action.main_action_sequence, textures, sounds, musics);
}

void print_action(Action* action, int depth)
{
    char* action_type = get_action_name_from_type(action->type);
    for(int i = 0; i < depth; i++) printf("  ");
    printf("action: %i (%s) \n", action, action_type);

    if(action->type == ACTION_TYPE__SEQUENCE)
    {
        for(int i = 0; i < depth; i++) printf("  ");
        printf("[ \n");
        for(ListElem* curr_elem = action->sequence.action_list->head; curr_elem; curr_elem = curr_elem->next)
        {
            print_action(curr_elem->data, depth + 1);
        }
        for(int i = 0; i < depth; i++) printf("  ");
        printf("] \n");
    }

    if(action->type == ACTION_TYPE__SIMULTANEOUS)
    {
        for(int i = 0; i < depth; i++) printf("  ");
        printf("{ \n");
        for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
        {
            print_action(curr_elem->data, depth + 1);
        }
        for(int i = 0; i < depth; i++) printf("  ");
        printf("} \n");
    }
}

char* get_gamestate_name(int gamestate)
{
    char* name = "";

    switch(gamestate)
    {
        case GAMESTATE__NONE:               name = "none";              break;
        case GAMESTATE__CHOOSING_SKILL:     name = "choosing skill";    break;
        case GAMESTATE__CHOOSING_TARGET_1:  name = "choosing target 1"; break;
        case GAMESTATE__CHOOSING_TARGET_2:  name = "choosing target 2"; break;
        case GAMESTATE__SKILL_EXECUTING:    name = "skill executing";   break;
        default: break;
    }

    return name;
}