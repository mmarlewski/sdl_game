#include "../inc/state.h"

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->is_game_running = 1;
    state->time = 0.0f;
    state->gamestate = GAMESTATE__NONE;
    state->timer = 0.0f;
    state->background_color = colors->hero_background;

    // camera

    state->camera.world_pos = vec2f(0, 0);
    state->camera.zoom = 2.0f;

    // mouse

    state->mouse.screen_pos = vec2i(0, 0);
    state->mouse.world_pos = vec2f(0, 0);
    state->mouse.gamemap_pos = vec2f(0, 0);
    state->mouse.tilemap_pos = vec2i(0, 0);
    state->mouse.is_dragging = 0;
    state->mouse.drag_origin_world_pos = vec2f(0, 0);

    // gamemap

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            state->gamemap.floor_array[i][j] = FLOOR_TYPE__METAL;
        }
    }

    state->gamemap.object_list = new_list((void (*)(void *))&destroy_object);
    state->gamemap.object_enemy_list = new_list((void (*)(void *))&destroy_object);
    state->gamemap.object_hero = new_object(OBJECT_TYPE__HERO);
    state->gamemap.object_hero->tilemap_pos = vec2i(10,6);
    add_object_to_gamemap_objects(state, state->gamemap.object_hero);
    state->gamemap.curr_object_enemy = 0;

    state->gamemap.sprite_list = new_list((void (*)(void *))&destroy_sprite);

    state->gamemap.prev_selected_tilemap_pos = vec2i(0, 0);
    state->gamemap.curr_selected_tilemap_pos = vec2i(0, 0);

    state->gamemap.curr_skill = 0;
    state->gamemap.is_skill_two_target = 0;

    state->gamemap.possible_target_1_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);
    state->gamemap.possible_target_2_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);

    state->gamemap.target_1_tilemap_pos = vec2i(0, 0);
    state->gamemap.target_2_tilemap_pos = vec2i(0, 0);

    state->gamemap.hero_ap = HERO_MAX_AP;

    state->gamemap.show_all_order_numbers = 0;

    state->gamemap.animation_list = new_list((void (*)(void *))&destroy_animation);

    // action

    state->action.is_executing_actions = 0;
    state->action.hero_action_sequence = new_action_sequence();
    state->action.enemy_action_sequence = 0;
}

void change_gamestate(State* state, int new_gamestate)
{
    state->gamestate = new_gamestate;

    printf("\n");
    printf("gamestate: %s \n", get_gamestate_name(state->gamestate));

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_SKILL ||
    state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2 ||
    state->gamestate == GAMESTATE__HERO_EXECUTING_SKILL)
    {
        int hero_ap = get_hero_ap(state);
        char hero_ap_bar[HERO_MAX_AP + 2];
        hero_ap_bar[0] = '[';
        for(int i = 0; i < HERO_MAX_AP; i ++)
        {
            hero_ap_bar[i + 1] = (i + 1 <= hero_ap) ? '#' : '-';
        }
        hero_ap_bar[HERO_MAX_AP + 1] = ']';
        printf("hero_ap: %s %i / %i \n", hero_ap_bar, hero_ap, HERO_MAX_AP);
    }

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2 ||
    state->gamestate == GAMESTATE__HERO_EXECUTING_SKILL)
    {
        printf("curr_skill: %s \n", get_skill_name(state->gamemap.curr_skill));
    }

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
    state->gamestate == GAMESTATE__ENEMY_ATTACKING ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE ||
    state->gamestate == GAMESTATE__ENEMY_MOVING ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET)
    {
        printf("curr_enemy: %s \n", get_name_from_object_type(state->gamemap.curr_object_enemy->type));
    }
}

void change_background_color(State* state, Vec3i new_background_color)
{
    state->background_color = new_background_color;
}

// gamemap

int is_tilemap_pos_in_tilemap(Vec2i tilemap_pos)
{
    return (tilemap_pos.x >= 0 && tilemap_pos.x < TILEMAP_WIDTH && tilemap_pos.y >= 0 && tilemap_pos.y < TILEMAP_HEIGHT);
}

Object* get_object_on_tilemap_pos(State* state, Vec2i tilemap_pos)
{
    if(!is_tilemap_pos_in_tilemap(tilemap_pos)) return 0;

    for(ListElem* curr_elem = state->gamemap.object_list->head; curr_elem; curr_elem = curr_elem->next)
    {
        Object* curr_object = (Object*)curr_elem->data;
        if(!curr_object->is_dead &&
        curr_object->tilemap_pos.x == tilemap_pos.x &&
        curr_object->tilemap_pos.y == tilemap_pos.y)
        {
            return curr_object;
        }
    }

    return 0;
}

int get_floor_on_tilemap_pos(State* state, Vec2i tilemap_pos)
{
    if(!is_tilemap_pos_in_tilemap(tilemap_pos)) return 0;

    return state->gamemap.floor_array[tilemap_pos.y][tilemap_pos.x];
}

void change_floor_in_tilemap_pos(State* state, int new_floor, Vec2i tilemap_pos)
{
    if(!is_tilemap_pos_in_tilemap(tilemap_pos)) return;

    state->gamemap.floor_array[tilemap_pos.y][tilemap_pos.x] = new_floor;
}

void add_object_to_gamemap_objects(State* state, Object* new_object)
{
    add_new_list_element_to_list_end(state->gamemap.object_list, new_object);

    if(is_object_enemy(new_object))
    {
        add_new_list_element_to_list_end(state->gamemap.object_enemy_list, new_object);
    }
}

void remove_object_from_gamemap_objects(State* state, Object* object)
{
    if(object == state->gamemap.object_hero)
    {
        state->gamemap.object_hero = 0;
    }

    if(is_object_enemy(object))
    {
        remove_list_element_of_data(state->gamemap.object_enemy_list, object, 0);
    }

    remove_list_element_of_data(state->gamemap.object_list, object, 1);
}

void remove_all_dead_objects_from_gamemap_objects(State* state)
{
    ListElem* curr_elem = state->gamemap.object_list->head;
    while(curr_elem != 0)
    {
        ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (0);

        Object* curr_object = (Object*)curr_elem->data;
        if(curr_object->is_dead)
        {
            remove_object_from_gamemap_objects(state, curr_object);
        }

        curr_elem = next_elem;
    }
}

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite)
{
    add_new_list_element_to_list_end(state->gamemap.sprite_list, new_sprite);
}

void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite)
{
    remove_list_element_of_data(state->gamemap.sprite_list, sprite, 1);
}

void add_pos_to_possible_target_1_tilemap_pos_list(State* state, Vec2i new_pos)
{
    add_new_list_element_to_list_end(state->gamemap.possible_target_1_tilemap_pos_list, new_vec2i(new_pos.x, new_pos.y));
}

void remove_all_pos_from_possible_target_1_tilemap_pos_list(State* state)
{
    remove_all_list_elements(state->gamemap.possible_target_1_tilemap_pos_list, 1);
}

int is_tilemap_pos_in_possible_target_1_tilemap_pos_list(State* state, Vec2i pos)
{
    for(ListElem* curr_elem = state->gamemap.possible_target_1_tilemap_pos_list->head; curr_elem; curr_elem = curr_elem->next )
    {
        Vec2i* curr_vec = (Vec2i*)curr_elem->data;
        if(curr_vec->x == pos.x && curr_vec->y == pos.y) return 1;
    }

    return 0;
}

void add_animation_to_animation_list(State* state, Animation* animation, Textures *textures, Sounds *sounds, Musics *musics, Colors *colors)
{
    add_new_list_element_to_list_end(state->gamemap.animation_list, animation);
    start_animation(state, animation, textures, sounds, musics, colors);
}

void add_pos_to_possible_target_2_tilemap_pos_list(State* state, Vec2i new_pos)
{
    add_new_list_element_to_list_end(state->gamemap.possible_target_2_tilemap_pos_list, new_vec2i(new_pos.x, new_pos.y));
}

void remove_all_pos_from_possible_target_2_tilemap_pos_list(State* state)
{
    remove_all_list_elements(state->gamemap.possible_target_2_tilemap_pos_list, 1);
}

int is_tilemap_pos_in_possible_target_2_tilemap_pos_list(State* state, Vec2i pos)
{
    for(ListElem* curr_elem = state->gamemap.possible_target_2_tilemap_pos_list->head; curr_elem; curr_elem = curr_elem->next )
    {
        Vec2i* curr_vec = (Vec2i*)curr_elem->data;
        if(curr_vec->x == pos.x && curr_vec->y == pos.y) return 1;
    }

    return 0;
}

// action

void remove_all_actions_from_action_sequence(Action* action_sequence)
{
    remove_all_list_elements(action_sequence->sequence.action_list,1);
}

void execute_action_sequence(State* state, Action* action_sequence, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->action.is_executing_actions = 1;
    action_sequence->is_finished = 0;

    start_action(state, action_sequence, action_sequence, textures, sounds, musics, colors);
}

char* get_gamestate_name(int gamestate)
{
    char* name = "";

    switch(gamestate)
    {
        case GAMESTATE__NONE:                       name = "none";                      break;
        case GAMESTATE__HERO_CHOOSING_SKILL:        name = "hero choosing skill";       break;
        case GAMESTATE__HERO_CHOOSING_TARGET_1:     name = "hero choosing target 1";    break;
        case GAMESTATE__HERO_CHOOSING_TARGET_2:     name = "hero choosing target 2";    break;
        case GAMESTATE__HERO_EXECUTING_SKILL:       name = "hero skill executing";      break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK:  name = "enemy pause before attack"; break;
        case GAMESTATE__ENEMY_ATTACKING:            name = "enemy attacking";           break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE:    name = "enemy pause before move";   break;
        case GAMESTATE__ENEMY_MOVING:               name = "enemy moving";              break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET:  name = "enemy pause before target"; break;
        default: break;
    }

    return name;
}

int get_hero_ap(State* state)
{
    return state->gamemap.hero_ap;
}

void modify_hero_ap(State* state, int by)
{
    state->gamemap.hero_ap += by;

    if(state->gamemap.hero_ap < 0) state->gamemap.hero_ap = 0;
    if(state->gamemap.hero_ap > HERO_MAX_AP) state->gamemap.hero_ap = HERO_MAX_AP;
}

void restore_hero_ap(State* state)
{
    state->gamemap.hero_ap = HERO_MAX_AP;
}

void determine_enemy_order(State* state)
{
    int order_number = 1;
    for(ListElem* curr_elem = state->gamemap.object_enemy_list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Object* curr_object = (Object*)curr_elem->data;
        curr_object->enemy.order_number = order_number;
        order_number++;
    }
}
