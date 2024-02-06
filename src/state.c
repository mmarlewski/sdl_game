#include "../inc/state.h"
#include <string.h>

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->is_game_running = 1;
    state->time = 0.0f;
    state->gamestate = GAMESTATE__NONE;
    state->timer = 0.0f;
    state->background_color = colors->hero_background;

    // camera

    state->camera_world_pos = vec2f(0, 0);
    state->camera_zoom = 2.0f;

    // mouse

    state->mouse_screen_pos = vec2i(0, 0);
    state->mouse_world_pos = vec2f(0, 0);
    state->mouse_gamemap_pos = vec2f(0, 0);
    state->mouse_tilemap_pos = vec2i(0, 0);
    state->mouse_is_dragging = 0;
    state->mouse_drag_origin_world_pos = vec2f(0, 0);

    state->room_list = new_list((void (*)(void *))&destroy_room);
    state->passage_list = new_list((void (*)(void *))&destroy_passage);
    state->curr_room = 0;

    // gamemap

    state->enemy_list = new_list((void (*)(void *))&destroy_enemy);
    state->hero_object = new_object(OBJECT_TYPE__HERO);
    state->curr_enemy = 0;

    state->ally_list = new_list((void (*)(void *))&destroy_ally);

    state->sprite_list = new_list((void (*)(void *))&destroy_sprite);

    state->prev_selected_tilemap_pos = vec2i(0, 0);
    state->curr_selected_tilemap_pos = vec2i(0, 0);

    state->curr_ally_skill = 0;
    state->is_curr_ally_skill_two_target = 0;

    state->possible_target_1_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);
    state->possible_target_2_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);

    state->target_1_tilemap_pos = vec2i(0, 0);
    state->target_2_tilemap_pos = vec2i(0, 0);

    state->hero_ap = HERO_MAX_AP;

    for(int i = 0; i < ITEM__COUNT; i++)
    {
        state->hero_item_number[i] = 0;
    }
    for(int i = 0; i < BODY_PART__COUNT; i++)
    {
        state->hero_body_part_augmentation[i] = AUGMENTATION__NONE;
    }
    state->hero_curr_item = ITEM__NONE;

    state->show_all_order_numbers = 0;

    state->animation_list = new_list((void (*)(void *))&destroy_animation);

    // action

    state->is_executing_actions = 0;
    state->ally_action_sequence = new_action_sequence();
    state->enemy_action_sequence = 0;
}

void change_gamestate(State* state, int new_gamestate)
{
    state->gamestate = new_gamestate;

    printf("########################################\n");
    printf("----------------------------------------\n");
    printf("gamestate : %s \n", get_gamestate_name(state->gamestate));
    printf("----------------------------------------\n");

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
        printf("hero ap   : %s %i / %i \n", hero_ap_bar, hero_ap, HERO_MAX_AP);
        printf("----------------------------------------\n");
        for(int i = 1; i < ITEM__COUNT; i++)
        {
            printf("%-10s: %i \n",
                get_name_from_item(i),
                state->hero_item_number[i]
                );
        }
        printf("----------------------------------------\n");
        for(int i = 1; i < BODY_PART__COUNT; i++)
        {
            printf("%-10s: %-10s \n",
                get_body_part_name(i),
                get_augmentation_name(state->hero_body_part_augmentation[i])
                );
        }
        printf("----------------------------------------\n");
    }

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2 ||
    state->gamestate == GAMESTATE__HERO_EXECUTING_ANIMATION ||
    state->gamestate == GAMESTATE__HERO_EXECUTING_SKILL)
    {
        printf("curr_skill: %s \n", get_skill_name(state->curr_ally_skill));
        printf("----------------------------------------\n");
    }

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
    state->gamestate == GAMESTATE__ENEMY_EXECUTING_ANIMATION ||
    state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE ||
    state->gamestate == GAMESTATE__ENEMY_MOVING ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET)
    {
        printf("curr_enemy: %s \n", get_name_from_object_type(state->curr_enemy->object->type));
        printf("----------------------------------------\n");
    }
}

void change_background_color(State* state, Vec3i new_background_color)
{
    state->background_color = new_background_color;
}

// gamemap

void add_room(State* state, Room* room)
{
    List* room_list = state->room_list;

    add_new_list_element_to_list_end(room_list,room);
}

Room* get_room(State* state, char* name)
{
    List* room_list = state->room_list;

    for(ListElem* elem = room_list->head; elem != 0; elem = elem->next)
    {
        if(elem != 0)
        {
            Room* room = (Room*) elem->data;

            if(strcmp(room->name, name) == 0)
            {
                return room;
            }
        }
    }

    return 0;
}

void set_curr_room(State* state, Room* room)
{
    state->curr_room = room;
}

void add_passage(State* state, Passage* passage)
{
    List* passage_list = state->passage_list;

    add_new_list_element_to_list_end(passage_list,passage);
}

Passage* get_passage(State* state, char* from_room_name, Vec2i from_tilemap_pos)
{
    List* passage_list = state->passage_list;

    for(ListElem* elem = passage_list->head; elem != 0; elem = elem->next)
    {
        if(elem != 0)
        {
            Passage* passage = (Passage*) elem->data;

            printf("passage: %p \n", passage);
            printf("from_room_name: %s \n", passage->from_room_name);
            printf("from_room_name: %s \n", from_room_name);
            printf("from_tilemap_pos: %i, %i \n", passage->from_tilemap_pos.x, passage->from_tilemap_pos.y);
            printf("from_tilemap_pos: %i, %i \n", from_tilemap_pos.x, from_tilemap_pos.y);

            if(passage != 0)
            {
                if(strcmp(passage->from_room_name, from_room_name) == 0 &&
                vec2i_equals(passage->from_tilemap_pos, from_tilemap_pos))
                {
                    return passage;
                }
            }
        }
    }

    return 0;
}

Object* room_get_object_at(Room* room, Vec2i tilemap_pos)
{
    if(!is_tilemap_in_bounds(tilemap_pos)) return 0;

    for(ListElem* curr_elem = room->object_list->head; curr_elem; curr_elem = curr_elem->next)
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

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite)
{
    add_new_list_element_to_list_end(state->sprite_list, new_sprite);
}

void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite)
{
    remove_list_element_of_data(state->sprite_list, sprite, 1);
}

void add_pos_to_possible_target_1_tilemap_pos_list(State* state, Vec2i new_pos)
{
    add_new_list_element_to_list_end(state->possible_target_1_tilemap_pos_list, new_vec2i(new_pos.x, new_pos.y));
}

void remove_all_pos_from_possible_target_1_tilemap_pos_list(State* state)
{
    remove_all_list_elements(state->possible_target_1_tilemap_pos_list, 1);
}

int is_tilemap_pos_in_possible_target_1_tilemap_pos_list(State* state, Vec2i pos)
{
    for(ListElem* curr_elem = state->possible_target_1_tilemap_pos_list->head; curr_elem; curr_elem = curr_elem->next )
    {
        Vec2i* curr_vec = (Vec2i*)curr_elem->data;
        if(curr_vec->x == pos.x && curr_vec->y == pos.y) return 1;
    }

    return 0;
}

void add_animation_to_animation_list(State* state, Animation* animation, Textures *textures, Sounds *sounds, Musics *musics, Colors *colors)
{
    add_new_list_element_to_list_end(state->animation_list, animation);
    start_animation(state, animation, textures, sounds, musics, colors);
}

void add_pos_to_possible_target_2_tilemap_pos_list(State* state, Vec2i new_pos)
{
    add_new_list_element_to_list_end(state->possible_target_2_tilemap_pos_list, new_vec2i(new_pos.x, new_pos.y));
}

void remove_all_pos_from_possible_target_2_tilemap_pos_list(State* state)
{
    remove_all_list_elements(state->possible_target_2_tilemap_pos_list, 1);
}

int is_tilemap_pos_in_possible_target_2_tilemap_pos_list(State* state, Vec2i pos)
{
    for(ListElem* curr_elem = state->possible_target_2_tilemap_pos_list->head; curr_elem; curr_elem = curr_elem->next )
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
    state->is_executing_actions = 1;
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
        case GAMESTATE__HERO_EXECUTING_ANIMATION:   name = "hero executing animation";  break;
        case GAMESTATE__HERO_EXECUTING_SKILL:       name = "hero executing skill";      break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK:  name = "enemy pause before attack"; break;
        case GAMESTATE__ENEMY_EXECUTING_ANIMATION:  name = "enemy executing animation"; break;
        case GAMESTATE__ENEMY_EXECUTING_ATTACK:     name = "enemy executing attack";    break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE:    name = "enemy pause before move";   break;
        case GAMESTATE__ENEMY_MOVING:               name = "enemy moving";              break;
        case GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET:  name = "enemy pause before target"; break;
        default: break;
    }

    return name;
}

int get_hero_ap(State* state)
{
    return state->hero_ap;
}

void modify_hero_ap(State* state, int by)
{
    state->hero_ap += by;

    if(state->hero_ap < 0) state->hero_ap = 0;
    if(state->hero_ap > HERO_MAX_AP) state->hero_ap = HERO_MAX_AP;
}

void restore_hero_ap(State* state)
{
    state->hero_ap = HERO_MAX_AP;
}

void hero_add_augmentation(State* state, int augmentation)
{
    int body_part = get_augmentation_body_part(augmentation);

    state->hero_body_part_augmentation[body_part] = augmentation;

    if(hero_has_augmentation(state, AUGMENTATION__STRIDER_LEG))
    {
        state->hero_object->type = OBJECT_TYPE__HERO_FLOATING;
    }
    if(hero_has_augmentation(state, AUGMENTATION__WINGS_TORSO))
    {
        state->hero_object->type = OBJECT_TYPE__HERO_FLYING;
    }
}

int hero_has_augmentation(State* state, int augmentation)
{
    int body_part = get_augmentation_body_part(augmentation);

    return state->hero_body_part_augmentation[body_part] == augmentation;
}

void determine_enemy_list(State* state)
{
    remove_all_list_elements(state->enemy_list,1);

    for(ListElem* elem = state->curr_room->object_list->head; elem != 0; elem = elem->next)
    {
        Object* object = (Object*)elem->data;

        if(object != 0 && is_object_enemy(object))
        {
            Enemy* enemy = new_enemy(object);

            add_new_list_element_to_list_end(state->enemy_list, enemy);
        }
    }
}

void determine_enemy_order(State* state)
{
    int order_number = 1;
    for(ListElem* curr_elem = state->enemy_list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*)curr_elem->data;
        curr_enemy->order_number = order_number;
        order_number++;
    }
}

void determine_ally_list(State* state)
{
    remove_all_list_elements(state->ally_list,1);

    for(ListElem* elem = state->curr_room->object_list->head; elem != 0; elem = elem->next)
    {
        Object* object = (Object*)elem->data;

        if(object != 0 && is_object_ally(object))
        {
            Ally* ally = new_ally(object);

            add_new_list_element_to_list_end(state->ally_list, ally);
        }
    }
}

void determine_ally_order(State* state)
{
    int order_number = 1;
    for(ListElem* curr_elem = state->ally_list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Ally* curr_ally = (Ally*)curr_elem->data;
        curr_ally->order_number = order_number;
        order_number++;
    }
}

void get_object_ally_skills(State* state, Object* object, List* skill_list)
{
    switch(object->type)
    {
        case OBJECT_TYPE__HERO:
        case OBJECT_TYPE__HERO_FLOATING:
        case OBJECT_TYPE__HERO_FLYING:
        {
            if(hero_has_augmentation(state, AUGMENTATION__FIST_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUSH);
            }
            if(hero_has_augmentation(state, AUGMENTATION__HOOK_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW);
            }
            if(hero_has_augmentation(state, AUGMENTATION__CHAIN_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PULL);
            }
            if(hero_has_augmentation(state, AUGMENTATION__SCISSOR_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PICK_ITEM_FAR);
            }
            if(hero_has_augmentation(state, AUGMENTATION__SPRING_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__JUMP);
            }
            if(hero_has_augmentation(state, AUGMENTATION__STRIDER_LEG))
            {
                //
            }
            if(hero_has_augmentation(state, AUGMENTATION__TRACK_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__CHARGE);
            }
            if(hero_has_augmentation(state, AUGMENTATION__BOOT_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__STOMP);
            }
            if(hero_has_augmentation(state, AUGMENTATION__MINIBOT_TORSO))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__LAUNCH_MINIBOT);
            }
            if(hero_has_augmentation(state, AUGMENTATION__WINGS_TORSO))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__ASCEND);
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__DESCEND);

            }
            if(hero_has_augmentation(state, AUGMENTATION__MANIPULATION_HEAD))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MANIPULATION);
            }
            if(hero_has_augmentation(state, AUGMENTATION__TELEPORTATION_HEAD))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__TELEPORTATION);
            }
            if(hero_has_augmentation(state, AUGMENTATION__HOOK_HAND) &&
            hero_has_augmentation(state, AUGMENTATION__CHAIN_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PULL_AND_THROW);
            }
            if(hero_has_augmentation(state, AUGMENTATION__HOOK_HAND) &&
            hero_has_augmentation(state, AUGMENTATION__TRACK_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__CHARGE_AND_THROW);
            }
            if(hero_has_augmentation(state, AUGMENTATION__FIST_HAND) &&
            hero_has_augmentation(state, AUGMENTATION__TRACK_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__CHARGE_AND_PUSH);
            }
            if(hero_has_augmentation(state, AUGMENTATION__SPRING_LEG) &&
            hero_has_augmentation(state, AUGMENTATION__BOOT_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__JUMP_AND_STOMP);
            }
            if(hero_has_augmentation(state, AUGMENTATION__SPRING_LEG) &&
            hero_has_augmentation(state, AUGMENTATION__TRACK_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__CHARGE_AND_JUMP);
            }
            if(hero_has_augmentation(state, AUGMENTATION__HOOK_HAND) &&
            hero_has_augmentation(state, AUGMENTATION__SPRING_LEG))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__JUMP_AND_CARRY);
            }
        }
        break;
        case OBJECT_TYPE__MINIBOT_ALLY:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PICK_ITEM_CLOSE);
        }
        break;
        case OBJECT_TYPE__MINIBOT_ALLY_CELL:
        case OBJECT_TYPE__MINIBOT_ALLY_DYNAMITE:
        case OBJECT_TYPE__MINIBOT_ALLY_GEMSTONE:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_CLOSE);
        }
        break;
        default:
        break;
    }
}

void remove_all_dead_objects(State* state)
{
    //
}

Enemy* get_enemy_of_object(State* state, Object* object)
{
    for(ListElem* elem = state->enemy_list->head; elem != 0; elem = elem->next)
    {
        Enemy* enemy = (Enemy*)elem->data;

        if(enemy->object == object)
        {
            return enemy;
        }
    }

    return 0;
}
