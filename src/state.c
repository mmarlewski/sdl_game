#include "../inc/state.h"
#include <string.h>

void init_state (State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->is_game_running = 1;
    state->time = 0.0f;
    state->gamestate = GAMESTATE__NONE;
    state->timer = 0.0f;
    state->background_color = colors->ally_background;

    state->camera_world_pos = vec2f(0, 0);
    state->camera_zoom = 2.0f;

    state->mouse_screen_pos = vec2i(0, 0);
    state->mouse_world_pos = vec2f(0, 0);
    state->mouse_gamemap_pos = vec2f(0, 0);
    state->mouse_tilemap_pos = vec2i(0, 0);

    state->mouse_is_dragging = 0;
    state->mouse_drag_origin_world_pos = vec2f(0, 0);

    state->is_executing_actions = 0;
    state->enemy_action_sequence = 0;
    state->ally_action_sequence = new_action_sequence();

    state->room_list = new_list((void (*)(void *))&destroy_room);
    state->visited_room_list = new_list((void (*)(void *))&destroy_room);
    state->passage_list = new_list((void (*)(void *))&destroy_passage);
    state->curr_room = 0;

    state->animation_list = new_list((void (*)(void *))&destroy_animation);
    state->sprite_list = new_list((void (*)(void *))&destroy_sprite);

    state->possible_target_1_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);
    state->possible_target_2_tilemap_pos_list = new_list((void(*)(void*))&destroy_vec2i);
    state->show_all_order_numbers = 0;
    state->selected_tilemap_pos = vec2i(0, 0);

    state->enemy_list = new_list((void (*)(void *))&destroy_enemy);
    state->curr_enemy_list_elem = 0;
    state->curr_enemy = 0;

    state->ally_list = new_list((void (*)(void *))&destroy_ally);
    state->curr_ally_list_elem = 0;
    state->curr_ally = 0;
    state->curr_ally_object = 0;
    state->curr_ally_skill = SKILL__NONE;
    state->ally_move_distance = 0;
    state->curr_ally_target_1_tilemap_pos = vec2i(0, 0);
    state->curr_ally_target_2_tilemap_pos = vec2i(0, 0);
    state->curr_skill_animation = 0;

    state->hero_object = new_object(OBJECT_TYPE__HERO);
    state->hero_ap = ALLY_MAX_ACTION_POINTS;
    for(int i = 0; i < ITEM__COUNT; i++)
    {
        state->hero_item_number[i] = 0;
    }
    for(int i = 0; i < BODY_PART__COUNT; i++)
    {
        state->hero_body_part_augmentation[i] = AUGMENTATION__NONE;
    }
    state->hero_curr_item = ITEM__NONE;

    state->minibot_object = new_object(OBJECT_TYPE__MINIBOT_ALLY);
    state->was_minibot_launched = 0;

    state->curr_ally_draw_below_texture_list = new_list((void (*)(void *)) 0);
    state->curr_ally_draw_below_tilemap_pos_list = new_list((void (*)(void *)) &destroy_vec2i);
    state->curr_ally_draw_above_texture_list = new_list((void (*)(void *)) 0);
    state->curr_ally_draw_above_tilemap_pos_list = new_list((void (*)(void *)) &destroy_vec2i);
    state->curr_ally_draw_effect_texture_list = new_list((void (*)(void *)) 0);
    state->curr_ally_draw_effect_tilemap_pos_list = new_list((void (*)(void *)) &destroy_vec2i);

    //

    state->camera_zoom = 2.0f;
    Vec2f middle_world_iso_pos = cart_pos_to_iso_pos(
        gamemap_pos_to_world_pos(
            vec2f(TILEMAP_LENGTH * 0.5f,TILEMAP_LENGTH * 0.5f)
            )
        );
    middle_world_iso_pos.x += TILE_LENGTH * 0.5f;
    middle_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state->camera_world_pos = middle_world_iso_pos;

    create_level(state);

    Room* room = get_room(state, "7_2");

    room_add_object_at(
        room,
        state->hero_object,
        vec2i(7,2)
        );
    set_curr_room(
        state,
        room
        );
    add_new_list_element_to_list_end(
        state->visited_room_list,
        room
        );

    state->hero_item_number[ITEM__CELL] = 1;
    state->hero_item_number[ITEM__DYNAMITE] = 1;
    state->hero_item_number[ITEM__GEMSTONE] = 1;

    // hero_add_augmentation(state, AUGMENTATION__HOOK_HAND);
    // hero_add_augmentation(state, AUGMENTATION__CHAIN_HAND);
    // hero_add_augmentation(state, AUGMENTATION__SPRING_LEG);
    // hero_add_augmentation(state, AUGMENTATION__BOOT_LEG);
    // hero_add_augmentation(state, AUGMENTATION__MINIBOT_TORSO);
    // hero_add_augmentation(state, AUGMENTATION__MANIPULATION_HEAD);

    update_enemy_list(state);
    update_all_enemy_order(state);
    for(ListElem* curr_elem = state->enemy_list->head;
    curr_elem != 0; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        update_enemy_attack_dir4(state, curr_enemy);
        update_enemy_attack_targets(state, curr_enemy);
        clear_enemy_attack_actions_and_draw(state,curr_enemy);
        get_enemy_attack_actions_and_draw(state,curr_enemy,textures);
    }

    update_ally_list(state);
    for(ListElem* curr_elem = state->ally_list->head;
    curr_elem != 0; curr_elem = curr_elem->next)
    {
        Ally* curr_ally = (Ally*) curr_elem->data;
        update_ally_skill_list(state, curr_ally);
        restore_ally_action_points(state, curr_ally);
    }

    state->curr_ally_list_elem = state->ally_list->head;
    state->curr_ally = state->curr_ally_list_elem->data;
    state->curr_ally_object = state->curr_ally->object;

    change_gamestate(state, GAMESTATE__ALLY_CHOOSING_SKILL);
}

void change_gamestate(State* state, int new_gamestate)
{
    state->gamestate = new_gamestate;

    printf("########################################\n");
    printf("----------------------------------------\n");
    printf("gamestate : %s \n", get_gamestate_name(state->gamestate));
    printf("----------------------------------------\n");
    printf("curr room : %s \n", state->curr_room->name);
    printf("----------------------------------------\n");
    printf("curr ally : %s \n", get_name_from_object_type(state->curr_ally_object->type));
    printf("----------------------------------------\n");

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
    state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        int curr_ally_ap = state->curr_ally->object->action_points;
        char hero_ap_bar[ALLY_MAX_ACTION_POINTS + 2];
        hero_ap_bar[0] = '[';
        for(int i = 0; i < ALLY_MAX_ACTION_POINTS; i ++)
        {
            char character = ' ';

            if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
            state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
            {
                int curr_skill_cost = get_skill_action_points(state->curr_ally_skill);
                if(i < curr_ally_ap - curr_skill_cost) character = '#';
                else if(i < curr_ally_ap) character = '-';
            }
            else
            {
                character = (i < curr_ally_ap) ? '#' : ' ';
            }

            hero_ap_bar[i + 1] = character;
        }
        hero_ap_bar[ALLY_MAX_ACTION_POINTS + 1] = ']';
        printf("hero ap   : %s %i / %i \n", hero_ap_bar, curr_ally_ap, ALLY_MAX_ACTION_POINTS);
        if(state->curr_ally->object->type == OBJECT_TYPE__HERO ||
        state->curr_ally->object->type == OBJECT_TYPE__HERO_FLOATING ||
        state->curr_ally->object->type == OBJECT_TYPE__HERO_FLYING)
        {
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
        }
        printf("----------------------------------------\n");
        for(int i = 0; i < state->curr_ally->skill_list->size; i++)
        {
            ListElem* curr_elem = get_nth_list_element(state->curr_ally->skill_list, i);
            if(curr_elem != 0)
            {
                int curr_skill = (int) curr_elem->data;
                char key_char = KEY__NONE;
                switch(i)
                {
                    case 0:  key_char = 'Q'; break;
                    case 1:  key_char = 'W'; break;
                    case 2:  key_char = 'E'; break;
                    case 3:  key_char = 'R'; break;
                    case 4:  key_char = 'T'; break;
                    case 5:  key_char = 'Y'; break;
                    case 6:  key_char = 'U'; break;
                    case 7:  key_char = 'I'; break;
                    case 8:  key_char = 'O'; break;
                    case 9:  key_char = 'P'; break;
                    case 10: key_char = 'A'; break;
                    case 11: key_char = 'S'; break;
                    case 12: key_char = 'D'; break;
                    case 13: key_char = 'F'; break;
                    case 14: key_char = 'G'; break;
                    case 15: key_char = 'H'; break;
                    case 16: key_char = 'J'; break;
                    case 17: key_char = 'K'; break;
                    case 18: key_char = 'L'; break;
                    case 19: key_char = 'Z'; break;
                    case 20: key_char = 'X'; break;
                    case 21: key_char = 'C'; break;
                    case 22: key_char = 'V'; break;
                    case 23: key_char = 'B'; break;
                    case 24: key_char = 'N'; break;
                    case 25: key_char = 'M'; break;
                    default: break;
                }
                int curr_skill_cost = get_skill_action_points(curr_skill);
                char* curr_skill_name = get_skill_name(curr_skill);
                if(curr_skill_cost == -1)
                {
                    printf("key %-1c : ? : %-10s \n",
                        key_char,
                        curr_skill_name
                        );
                }
                else
                {
                    printf("key %-1c : %i : %-10s \n",
                        key_char,
                        curr_skill_cost,
                        curr_skill_name
                        );
                }
            }
        }
        printf("----------------------------------------\n");
    }

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
    state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
    state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        printf("curr skill: %s \n", get_skill_name(state->curr_ally_skill));
        printf("----------------------------------------\n");
    }

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
    state->gamestate == GAMESTATE__ENEMY_EXECUTING_ANIMATION ||
    state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE ||
    state->gamestate == GAMESTATE__ENEMY_MOVING ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET)
    {
        printf("curr enemy: %s \n", get_name_from_object_type(state->curr_enemy->object->type));
        printf("----------------------------------------\n");
        printf("curr skill: %s \n", get_skill_name(state->curr_enemy->skill));
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
        if(!curr_object->is_to_be_removed &&
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

void add_animation_to_animation_list(State* state, Animation* animation, Textures *textures, Sounds *sounds, Musics *musics, Colors *colors)
{
    add_new_list_element_to_list_end(state->animation_list, animation);
    start_animation(state, animation, textures, sounds, musics, colors);
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
        case GAMESTATE__ALLY_CHOOSING_SKILL:        name = "ally choosing skill";       break;
        case GAMESTATE__ALLY_CHOOSING_TARGET_1:     name = "ally choosing target 1";    break;
        case GAMESTATE__ALLY_CHOOSING_TARGET_2:     name = "ally choosing target 2";    break;
        case GAMESTATE__ALLY_EXECUTING_ANIMATION:   name = "ally executing animation";  break;
        case GAMESTATE__ALLY_EXECUTING_SKILL:       name = "ally executing skill";      break;
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

void get_object_skills(State* state, Object* object, List* skill_list)
{
    switch(object->type)
    {
        case OBJECT_TYPE__HERO:
        case OBJECT_TYPE__HERO_FLOATING:
        case OBJECT_TYPE__HERO_FLYING:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);
            if(hero_has_augmentation(state, AUGMENTATION__MANIPULATION_HEAD))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MANIPULATION);
            }
            if(hero_has_augmentation(state, AUGMENTATION__TELEPORTATION_HEAD))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__TELEPORTATION);
            }

            // move

            if(object->type == OBJECT_TYPE__HERO)
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            }
            if(object->type == OBJECT_TYPE__HERO_FLOATING)
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE_FLOATING);
            }
            if(object->type == OBJECT_TYPE__HERO_FLYING)
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE_FLYING);
            }

            // augmentation

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
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__DRAG);
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PULL);
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
                if(!state->was_minibot_launched)
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__LAUNCH_MINIBOT);
                }
            }
            if(hero_has_augmentation(state, AUGMENTATION__WINGS_TORSO))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__ASCEND);
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__DESCEND);
            }
            if(hero_has_augmentation(state, AUGMENTATION__HOOK_HAND) &&
            hero_has_augmentation(state, AUGMENTATION__CHAIN_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__DRAG_AND_THROW);
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

            // item

            if(hero_has_augmentation(state, AUGMENTATION__SCISSOR_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PICK_ITEM_FAR);
            }
            else
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PICK_ITEM_CLOSE);
            }
            if(state->hero_item_number[ITEM__CELL] > 0)
            {
                if(hero_has_augmentation(state, AUGMENTATION__SCISSOR_HAND))
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_CELL_FAR);
                }
                else
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_CELL_CLOSE);
                }
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_CELL);
            }
            if(state->hero_item_number[ITEM__DYNAMITE] > 0)
            {
                if(hero_has_augmentation(state, AUGMENTATION__SCISSOR_HAND))
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_DYNAMITE_FAR);
                }
                else
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_DYNAMITE_CLOSE);
                }
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_DYNAMITE);
            }
            if(state->hero_item_number[ITEM__GEMSTONE] > 0)
            {
                if(hero_has_augmentation(state, AUGMENTATION__SCISSOR_HAND))
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_GEMSTONE_FAR);
                }
                else
                {
                    add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_GEMSTONE_CLOSE);
                }
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_GEMSTONE);
            }
        }
        break;
        case OBJECT_TYPE__MINIBOT_ALLY:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PICK_ITEM_CLOSE);
        }
        break;
        case OBJECT_TYPE__MINIBOT_ALLY_CELL:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_CELL_CLOSE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_CELL);
        }
        break;
        case OBJECT_TYPE__MINIBOT_ALLY_DYNAMITE:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_DYNAMITE_CLOSE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_DYNAMITE);
        }
        break;
        case OBJECT_TYPE__MINIBOT_ALLY_GEMSTONE:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_GEMSTONE_CLOSE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_GEMSTONE);
        }
        break;
        default:
        break;
    }
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

Ally* get_ally_of_object(State* state, Object* object)
{
    for(ListElem* elem = state->ally_list->head; elem != 0; elem = elem->next)
    {
        Ally* ally = (Ally*)elem->data;

        if(ally->object == object)
        {
            return ally;
        }
    }

    return 0;
}

void draw_texture_list(
    Renderer* renderer,
    State* state,
    List* texture_list,
    List* tilemap_pos_list,
    Vec3i color,
    float transparency
)
{
    ListElem* texture_elem = texture_list->head;
    ListElem* tilemap_pos_elem = tilemap_pos_list->head;

    while(texture_elem != 0 && tilemap_pos_elem != 0)
    {
        Texture* texture = (Texture*) texture_elem->data;
        Vec2i* tilemap_pos = (Vec2i*) tilemap_pos_elem->data;

        draw_texture_at_tilemap_pos(
            renderer,
            texture,
            color,
            transparency,
            *tilemap_pos,
            state->camera_world_pos,
            state->camera_zoom
            );

        texture_elem = texture_elem->next;
        tilemap_pos_elem = tilemap_pos_elem->next;
    }
}

// enemy

void update_enemy_list(State* state)
{
    if(state->curr_room != 0)
    {
        remove_all_list_elements(state->enemy_list, 1);
        for(ListElem* curr_elem = state->curr_room->object_list->head;
        curr_elem != 0; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != 0 && is_object_enemy(curr_object))
            {
                add_new_list_element_to_list_end(
                    state->enemy_list,
                    new_enemy(curr_object)
                    );
            }
        }
    }
}

void update_all_enemy_order(State* state)
{
    int curr_order_number = 1;
    for(ListElem* curr_elem = state->enemy_list->head;
    curr_elem != 0; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        if(curr_enemy != 0)
        {
            curr_enemy->order_number = curr_order_number;
            curr_order_number++;
        }
    }
}

void update_enemy_attack_dir4(State* state, Enemy* enemy)
{
    if(enemy != 0)
    {
        enemy->object->attack_dir4 = rand() % 4 + 1;
    }
}

void update_enemy_attack_targets(State* state, Enemy* enemy)
{
    if(enemy != 0)
    {
        object_enemy_prepare_attack(state, enemy);
    }
}

void clear_enemy_attack_actions_and_draw(
    State* state,
    Enemy* enemy
)
{
    if(enemy != 0)
    {
        remove_all_actions_from_action_sequence(
            enemy->action_sequence
            );
        remove_all_list_elements(
            enemy->draw_below_texture_list,
            0
            );
        remove_all_list_elements(
            enemy->draw_below_tilemap_pos_list,
            1
            );
        remove_all_list_elements(
            enemy->draw_above_texture_list,
            0
            );
        remove_all_list_elements(
            enemy->draw_above_tilemap_pos_list,
            1
            );
        remove_all_list_elements(
            enemy->draw_effect_texture_list,
            0
            );
        remove_all_list_elements(
            enemy->draw_effect_tilemap_pos_list,
            1
            );
    }
}

void get_enemy_attack_actions_and_draw(
    State* state,
    Enemy* enemy,
    Textures* textures
)
{
    if(enemy != 0)
    {
        skill_get_actions_and_draw(
            state,
            enemy->skill,
            enemy->object->tilemap_pos,
            enemy->target_1_tilemap_pos,
            enemy->target_2_tilemap_pos,
            enemy->action_sequence,
            enemy->draw_below_texture_list,
            enemy->draw_below_tilemap_pos_list,
            enemy->draw_above_texture_list,
            enemy->draw_above_tilemap_pos_list,
            enemy->draw_effect_texture_list,
            enemy->draw_effect_tilemap_pos_list,
            textures
        );
    }
}

// ally

void update_ally_list(State* state)
{
    if(state->curr_room != 0)
    {
        remove_all_list_elements(state->ally_list, 1);
        for(ListElem* curr_elem = state->curr_room->object_list->head;
        curr_elem != 0; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != 0 && is_object_ally(curr_object))
            {
                add_new_list_element_to_list_end(
                    state->ally_list,
                    new_ally(curr_object)
                    );
            }
        }
    }
}

void update_ally_skill_list(State* state, Ally* ally)
{
    if(ally != 0)
    {
        remove_all_list_elements(ally->skill_list, 0);
        get_object_skills(
            state,
            ally->object,
            ally->skill_list
            );
    }
}

void restore_ally_action_points(State* state, Ally* ally)
{
    if(ally != 0)
    {
        ally->object->action_points = ALLY_MAX_ACTION_POINTS;
    }
}


void clear_curr_ally_attack_actions_and_draw(
    State* state
)
{
    if(state->curr_ally != 0)
    {
        remove_all_actions_from_action_sequence(
            state->ally_action_sequence
            );
        remove_all_list_elements(
            state->curr_ally_draw_below_texture_list,
            0
            );
        remove_all_list_elements(
            state->curr_ally_draw_below_tilemap_pos_list,
            1
            );
        remove_all_list_elements(
            state->curr_ally_draw_above_texture_list,
            0
            );
        remove_all_list_elements(
            state->curr_ally_draw_above_tilemap_pos_list,
            1
            );
        remove_all_list_elements(
            state->curr_ally_draw_effect_texture_list,
            0
            );
        remove_all_list_elements(
            state->curr_ally_draw_effect_tilemap_pos_list,
            1
            );
    }
}

void get_curr_ally_attack_actions_and_draw(
    State* state,
    Textures* textures
)
{
    if(state->curr_ally != 0)
    {
        skill_get_actions_and_draw(
            state,
            state->curr_ally_skill,
            state->curr_ally->object->tilemap_pos,
            state->curr_ally_target_1_tilemap_pos,
            state->curr_ally_target_2_tilemap_pos,
            state->ally_action_sequence,
            state->curr_ally_draw_below_texture_list,
            state->curr_ally_draw_below_tilemap_pos_list,
            state->curr_ally_draw_above_texture_list,
            state->curr_ally_draw_above_tilemap_pos_list,
            state->curr_ally_draw_effect_texture_list,
            state->curr_ally_draw_effect_tilemap_pos_list,
            textures
        );
    }
}

// other

void remove_all_object_to_be_removed(State* state)
{
    if(state->curr_room != 0)
    {
        List* object_to_be_removed_list = new_list((void (*)(void *))&destroy_object);

        for(ListElem* curr_elem = state->curr_room->object_list->head;
        curr_elem != 0; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != 0 && curr_object->is_to_be_removed)
            {
                add_new_list_element_to_list_end(object_to_be_removed_list, curr_object);
            }
        }

        for(ListElem* curr_elem = object_to_be_removed_list->head;
        curr_elem != 0; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != 0)
            {
                room_remove_object(state->curr_room, curr_object, 1);
            }
        }

        remove_all_list_elements(object_to_be_removed_list, 0);
        destroy_list(object_to_be_removed_list);
    }
}

int is_floor_deadly_on_move_for_object(
    int floor,
    Object* object
)
{
    return ((!is_object_floating(object) && !is_object_flying(object) && is_floor_deadly_on_move(floor)) ||
    (is_object_floating(object) && is_floor_deadly_on_move_for_floating(floor)) ||
    (is_object_flying(object) && is_floor_deadly_on_move_for_flying(floor)));
}

int is_floor_deadly_on_drop_for_object(
    int floor,
    Object* object
)
{
    return ((!is_object_floating(object) && !is_object_flying(object) && is_floor_deadly_on_drop(floor)) ||
    (is_object_floating(object) && is_floor_deadly_on_drop_for_floating(floor)) ||
    (is_object_flying(object) && is_floor_deadly_on_drop_for_flying(floor)));
}
