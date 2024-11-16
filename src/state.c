#include "../inc/state.h"
#include <string.h>

void init_state(State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->is_game_running = TRUE;
    state->time = 0.0f;
    state->delta_time = 0.0f;
    state->gamestate = GAMESTATE__NONE;
    state->timer = 0.0f;
    state->background_color = colors->none;
    state->background_texture = NULL;

    state->camera_world_pos = vec2f(0, 0);
    state->camera_zoom = 2.0f;

    state->mouse_screen_pos = vec2i(0, 0);
    state->mouse_world_pos = vec2f(0, 0);
    state->mouse_gamemap_pos = vec2f(0, 0);
    state->mouse_tilemap_pos = vec2i(0, 0);

    state->mouse_is_dragging = FALSE;
    state->mouse_drag_origin_world_pos = vec2f(0, 0);

    state->is_executing_actions = FALSE;
    state->enemy_action_sequence = NULL;
    state->ally_action_sequence = new_action_sequence();

    state->room_list = new_list((void (*)(void*)) & destroy_room);
    state->visited_room_list = new_list((void (*)(void*)) & destroy_room);
    state->passage_list = new_list((void (*)(void*)) & destroy_passage);
    state->curr_room = NULL;

    state->animation_list = new_list((void (*)(void*)) & destroy_animation);
    state->sprite_list = new_list((void (*)(void*)) & destroy_sprite);

    state->possible_target_1_tilemap_pos_list = new_list((void(*)(void*)) & destroy_vec2i);
    state->possible_target_2_tilemap_pos_list = new_list((void(*)(void*)) & destroy_vec2i);
    state->show_all_order_numbers = FALSE;
    state->selected_tilemap_pos = vec2i(0, 0);

    state->enemy_list = new_list((void (*)(void*)) & destroy_enemy);
    state->curr_enemy_list_elem = NULL;
    state->curr_enemy = NULL;

    state->ally_list = new_list((void (*)(void*)) & destroy_ally);
    state->curr_ally_list_elem = NULL;
    state->curr_ally = NULL;
    state->curr_ally_skill = SKILL__NONE;
    state->ally_move_distance = 0;
    state->curr_ally_target_1_tilemap_pos = vec2i(0, 0);
    state->curr_ally_target_2_tilemap_pos = vec2i(0, 0);
    state->curr_skill_animation = NULL;

    state->hero_object = NULL;
    state->minibot_object = NULL;

    for(int i = 0; i < ITEM__COUNT; i++)
    {
        state->hero_item_number[i] = 0;
    }
    for(int i = 0; i < BODY_PART__COUNT; i++)
    {
        state->hero_body_part_augmentation[i] = AUGMENTATION__NONE;
    }
    state->hero_curr_item = ITEM__NONE;

    state->was_minibot_launched = FALSE;
    state->was_throne_used = FALSE;

    state->reset_turn_uses = 0;

    state->curr_ally_draw_below_texture_list = new_list((void (*)(void*)) 0);
    state->curr_ally_draw_below_tilemap_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    state->curr_ally_draw_above_texture_list = new_list((void (*)(void*)) 0);
    state->curr_ally_draw_above_tilemap_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    state->curr_ally_draw_effect_texture_list = new_list((void (*)(void*)) 0);
    state->curr_ally_draw_effect_tilemap_pos_list = new_list((void (*)(void*)) & destroy_vec2i);

    state->mechanism_list = new_list((void (*)(void*)) & destroy_mechanism);
}

void start_state(State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->reset_turn_uses = 3;
    state->game_over_uses = 3;

    state->camera_zoom = 2.0f;
    Vec2f middle_world_iso_pos = cart_pos_to_iso_pos(
        gamemap_pos_to_world_pos(
            vec2f(TILEMAP_LENGTH * 0.5f, TILEMAP_LENGTH * 0.5f)
        )
    );
    middle_world_iso_pos.x += TILE_LENGTH * 0.5f;
    middle_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state->camera_world_pos = middle_world_iso_pos;

    remove_all_list_elements(state->room_list, 1);
    remove_all_list_elements(state->visited_room_list, 0);
    remove_all_list_elements(state->passage_list, 1);
    remove_all_list_elements(state->mechanism_list, 1);

    create_level(state, textures);
    create_mechanisms(state);

    state->hero_object = new_object(OBJECT__HERO);
    state->minibot_object = new_object(OBJECT__MINIBOT_ALLY);

    Room* room = get_room(state, "7_2");
    room_add_object_at(
        room,
        state->hero_object,
        vec2i(7, 2)
    );
    set_curr_room(
        state,
        room
    );
    state->background_color = colors->ally_background;
    state->background_texture = state->curr_room->background_texture;
    add_new_list_element_to_list_end(
        state->visited_room_list,
        room
    );

    Animation* animation_fade_in = new_animation_fade_in_sprite_in_gamemap(
                    textures->object.station_outline,
                    vec2f(1,8),
                    0.5f
                    );
    Animation* animation_fade_out = new_animation_fade_out_sprite_in_gamemap(
                    textures->object.station_outline,
                    vec2f(1,8),
                    0.5f
                    );

    add_animation_to_animation_list(
        state,
        new_animation_flash_sprite_in_gamemap(
            textures->object.exit_stone_right_outline,
            vec2f(9,5),
            1.5f,
            2
        ),
        textures,
        sounds,
        musics,
        colors
    );

    state->hero_item_number[ITEM__CELL] = 0;
    state->hero_item_number[ITEM__DYNAMITE] = 0;
    state->hero_item_number[ITEM__GEMSTONE] = 0;

    // state->hero_item_number[ITEM__CELL] = 5;
    // state->hero_item_number[ITEM__DYNAMITE] = 5;
    // state->hero_item_number[ITEM__GEMSTONE] = 5;

    for(int body_part = 1; body_part < BODY_PART__COUNT; body_part++)
    {
        state->hero_body_part_augmentation[body_part] = AUGMENTATION__NONE;
    }

    // hero_add_augmentation(state, AUGMENTATION__HOOK_HAND);
    // hero_add_augmentation(state, AUGMENTATION__CHAIN_HAND);
    // hero_add_augmentation(state, AUGMENTATION__SPRING_LEG);
    // hero_add_augmentation(state, AUGMENTATION__TRACK_LEG);
    // hero_add_augmentation(state, AUGMENTATION__MINIBOT_TORSO);
    // hero_add_augmentation(state, AUGMENTATION__TELEPORTATION_HEAD);

    // hero_add_augmentation(state, AUGMENTATION__FIST_HAND);
    // hero_add_augmentation(state, AUGMENTATION__SCISSOR_HAND);
    // hero_add_augmentation(state, AUGMENTATION__STRIDER_LEG);
    // hero_add_augmentation(state, AUGMENTATION__BOOT_LEG);
    // hero_add_augmentation(state, AUGMENTATION__WINGS_TORSO);
    // hero_add_augmentation(state, AUGMENTATION__MANIPULATION_HEAD);

    update_enemy_list(state);
    update_all_enemy_order(state);
    for(ListElem* curr_elem = state->enemy_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        update_enemy_attack_dir4(state, curr_enemy);
        update_enemy_attack_targets(state, curr_enemy);
        clear_enemy_attack_actions_and_draw(state, curr_enemy);
        get_enemy_attack_actions_and_draw(state, curr_enemy, textures, sounds);
    }

    update_ally_list(state);
    for(ListElem* curr_elem = state->ally_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Ally* curr_ally = (Ally*) curr_elem->data;
        update_ally_skill_list(state, curr_ally);
        restore_ally_action_points(state, curr_ally);
    }

    state->curr_ally_list_elem = state->ally_list->head;
    state->curr_ally = state->curr_ally_list_elem->data;
}

void change_gamestate(State* state, int new_gamestate)
{
    state->gamestate = new_gamestate;

    // for(int i = 0; i < 100; i++) printf("\n");
    // printf("----------------------------------------\n");
    // if(state->enemy_list->size > 0)
    // {
    //     printf(" ╔═╗╔═╗╔╦╗╔╗ ╔═╗╔╦╗ \n");
    //     printf(" ║  ║ ║║║║╠╩╗╠═╣ ║  \n");
    //     printf(" ╚═╝╚═╝╩ ╩╚═╝╩ ╩ ╩  \n");
    // }
    // else
    // {
    //     printf(" ╔═╗╦═╗╔═╗╔═╗ \n");
    //     printf(" ╠╣ ╠╦╝║╣ ║╣  \n");
    //     printf(" ╚  ╩╚═╚═╝╚═╝ \n");
    // }
    // printf("----------------------------------------\n");
    // printf("gamestate : %s \n", get_gamestate_debug_name(state->gamestate));
    // printf("----------------------------------------\n");
    // printf("curr room : %s \n", state->curr_room->name);
    // printf("----------------------------------------\n");
    // printf("curr ally : %s \n", get_debug_name_from_object_type(state->curr_ally->object->type));
    // printf("----------------------------------------\n");

    // if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    //    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    //    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
    //    state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    // {
    //     if(state->enemy_list->size > 0)
    //     {
    //         int curr_ally_ap = state->curr_ally->object->action_points;
    //         char hero_ap_bar[ALLY_MAX_ACTION_POINTS + 2];
    //         hero_ap_bar[0] = '[';
    //         for(int i = 0; i < ALLY_MAX_ACTION_POINTS; i++)
    //         {
    //             char character = ' ';

    //             if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    //                state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    //             {
    //                 int curr_skill_cost = get_skill_action_points(state->curr_ally_skill);
    //                 if(i < curr_ally_ap - curr_skill_cost) character = '#';
    //                 else if(i < curr_ally_ap) character = '-';
    //             }
    //             else
    //             {
    //                 character = (i < curr_ally_ap) ? '#' : ' ';
    //             }

    //             hero_ap_bar[i + 1] = character;
    //         }
    //         hero_ap_bar[ALLY_MAX_ACTION_POINTS + 1] = ']';
    //         printf("hero ap   : %s %i / %i \n", hero_ap_bar, curr_ally_ap, ALLY_MAX_ACTION_POINTS);
    //     }
    //     if(state->curr_ally->object->type == OBJECT__HERO ||
    //        state->curr_ally->object->type == OBJECT__HERO_FLOATING ||
    //        state->curr_ally->object->type == OBJECT__HERO_FLYING)
    //     {
    //         printf("----------------------------------------\n");
    //         for(int i = 1; i < ITEM__COUNT; i++)
    //         {
    //             printf("%-10s: %i \n",
    //                    get_name_from_item(i),
    //                    state->hero_item_number[i]
    //             );
    //         }
    //         printf("----------------------------------------\n");
    //         for(int i = 1; i < BODY_PART__COUNT; i++)
    //         {
    //             printf("%-10s: %-10s \n",
    //                    get_body_part_name(i),
    //                    get_augmentation_name(state->hero_body_part_augmentation[i])
    //             );
    //         }
    //     }
    //     printf("----------------------------------------\n");
    //     for(int i = 0; i < state->curr_ally->skill_list->size; i++)
    //     {
    //         ListElem* curr_elem = get_nth_list_element(state->curr_ally->skill_list, i);
    //         if(curr_elem != NULL)
    //         {
    //             int curr_skill = (int) curr_elem->data;
    //             char key_char = KEY__NONE;
    //             switch(i)
    //             {
    //                 case 0:  key_char = 'Q'; break;
    //                 case 1:  key_char = 'W'; break;
    //                 case 2:  key_char = 'E'; break;
    //                 case 3:  key_char = 'R'; break;
    //                 case 4:  key_char = 'T'; break;
    //                 case 5:  key_char = 'Y'; break;
    //                 case 6:  key_char = 'U'; break;
    //                 case 7:  key_char = 'I'; break;
    //                 case 8:  key_char = 'O'; break;
    //                 case 9:  key_char = 'P'; break;
    //                 case 10: key_char = 'A'; break;
    //                 case 11: key_char = 'S'; break;
    //                 case 12: key_char = 'D'; break;
    //                 case 13: key_char = 'F'; break;
    //                 case 14: key_char = 'G'; break;
    //                 case 15: key_char = 'H'; break;
    //                 case 16: key_char = 'J'; break;
    //                 case 17: key_char = 'K'; break;
    //                 case 18: key_char = 'L'; break;
    //                 case 19: key_char = 'Z'; break;
    //                 case 20: key_char = 'X'; break;
    //                 case 21: key_char = 'C'; break;
    //                 case 22: key_char = 'V'; break;
    //                 case 23: key_char = 'B'; break;
    //                 case 24: key_char = 'N'; break;
    //                 case 25: key_char = 'M'; break;
    //                 default: break;
    //             }
    //             int curr_skill_cost = get_skill_action_points(curr_skill);
    //             char* curr_skill_name = get_debug_skill_name(curr_skill);
    //             if(curr_skill_cost == -1)
    //             {
    //                 printf("key %-1c : ? : %-10s \n",
    //                        key_char,
    //                        curr_skill_name
    //                 );
    //             }
    //             else
    //             {
    //                 printf("key %-1c : %i : %-10s \n",
    //                        key_char,
    //                        curr_skill_cost,
    //                        curr_skill_name
    //                 );
    //             }
    //         }
    //     }
    //     printf("----------------------------------------\n");
    //     if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL &&
    //        state->enemy_list->size > 0)
    //     {
    //         printf("key ENTER : end turn \n");
    //         printf("----------------------------------------\n");
    //     }
    //     if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1)
    //     {
    //         printf("key ESC   : go back \n");
    //         printf("----------------------------------------\n");
    //     }
    //     if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    //     {
    //         printf("key ESC   : go back \n");
    //         printf("----------------------------------------\n");
    //     }
    // }

    // if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    //    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
    //    state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
    //    state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    // {
    //     printf("curr skill: %s \n", get_debug_skill_name(state->curr_ally_skill));
    //     printf("----------------------------------------\n");
    // }

    // if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
    //    state->gamestate == GAMESTATE__ENEMY_EXECUTING_ANIMATION ||
    //    state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK ||
    //    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE ||
    //    state->gamestate == GAMESTATE__ENEMY_MOVING ||
    //    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET)
    // {
    //     printf("curr enemy: %s \n", get_debug_name_from_object_type(state->curr_enemy->object->type));
    //     printf("----------------------------------------\n");
    //     printf("curr skill: %s \n", get_debug_skill_name(state->curr_enemy->skill));
    //     printf("----------------------------------------\n");
    // }
}

void change_background_color(State* state, Vec3i new_background_color)
{
    state->background_color = new_background_color;
}

// gamemap

void add_room(State* state, Room* room)
{
    List* room_list = state->room_list;

    add_new_list_element_to_list_end(room_list, room);
}

Room* get_room(State* state, char* name)
{
    List* room_list = state->room_list;

    for(ListElem* elem = room_list->head; elem != NULL; elem = elem->next)
    {
        if(elem != NULL)
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

    add_new_list_element_to_list_end(passage_list, passage);
}

Passage* get_passage(State* state, char* from_room_name, Vec2i from_tilemap_pos)
{
    List* passage_list = state->passage_list;

    for(ListElem* elem = passage_list->head; elem != NULL; elem = elem->next)
    {
        if(elem != NULL)
        {
            Passage* passage = (Passage*) elem->data;
            if(passage != NULL)
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
    if(room == NULL) return 0;

    if(!is_tilemap_in_bounds(tilemap_pos)) return 0;

    Object* object = NULL;
    for(ListElem* curr_elem = room->object_list->head;
        curr_elem; curr_elem = curr_elem->next)
    {
        Object* curr_object = (Object*) curr_elem->data;
        if(!curr_object->is_to_be_removed &&
           curr_object->tilemap_pos.x == tilemap_pos.x &&
           curr_object->tilemap_pos.y == tilemap_pos.y)
        {
            object = curr_object;
        }
    }

    return object;
}

void add_sprite_to_gamemap_sprites(State* state, Sprite* new_sprite)
{
    add_new_list_element_to_list_end(state->sprite_list, new_sprite);
}

void remove_sprite_from_gamemap_sprites(State* state, Sprite* sprite)
{
    remove_list_element_of_data(state->sprite_list, sprite, 1);
}

void add_animation_to_animation_list(State* state, Animation* animation, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    add_new_list_element_to_list_end(state->animation_list, animation);
    start_animation(state, animation, textures, sounds, musics, colors);
}

// action

void remove_all_actions_from_action_sequence(Action* action_sequence)
{
    remove_all_list_elements(action_sequence->sequence.action_list, 1);
}

void execute_action_sequence(State* state, Action* action_sequence, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    state->is_executing_actions = TRUE;
    action_sequence->is_finished = FALSE;

    start_action(state, action_sequence, action_sequence, textures, sounds, musics, colors);
}

char* get_gamestate_debug_name(int gamestate)
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
        case GAMESTATE__GAME_START:                 name = "game start";                break;
        case GAMESTATE__GAME_OVER:                  name = "game over";                 break;
        case GAMESTATE__GAME_WON:                   name = "game won";                  break;
        default: break;
    }

    return name;
}

void hero_add_augmentation(State* state, int augmentation)
{
    int body_part = get_augmentation_body_part(augmentation);

    state->hero_body_part_augmentation[body_part] = augmentation;

    if(hero_has_augmentation(state, AUGMENTATION__WINGS_TORSO))
    {
        state->hero_object->type = OBJECT__HERO_FLYING;
    }
    else if(hero_has_augmentation(state, AUGMENTATION__STRIDER_LEG))
    {
        state->hero_object->type = OBJECT__HERO_FLOATING;
    }
    else
    {
        state->hero_object->type = OBJECT__HERO;
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
        case OBJECT__GOLEM_POWERED:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__STOMP);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUSH);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
        }
        break;
        case OBJECT__HERO:
        case OBJECT__HERO_FLOATING:
        case OBJECT__HERO_FLYING:
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

            if(object->type == OBJECT__HERO)
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            }
            if(object->type == OBJECT__HERO_FLOATING)
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE_FLOATING);
            }
            if(object->type == OBJECT__HERO_FLYING)
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
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__PULL_HOOK);
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__DRAG_HOOK);
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
                //
            }
            if(hero_has_augmentation(state, AUGMENTATION__HOOK_HAND) &&
               hero_has_augmentation(state, AUGMENTATION__CHAIN_HAND))
            {
                add_new_list_element_to_list_end(skill_list, (void*) SKILL__DRAG_AND_THROW_HOOK);
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
        case OBJECT__MINIBOT_ALLY:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MINIBOT_MERGE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PICK_ITEM_CLOSE);
        }
        break;
        case OBJECT__MINIBOT_ALLY_CELL:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MINIBOT_MERGE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_CELL_CLOSE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_CELL);
        }
        break;
        case OBJECT__MINIBOT_ALLY_DYNAMITE:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MINIBOT_MERGE);

            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MOVE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__PUT_ITEM_DYNAMITE_CLOSE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__THROW_ITEM_DYNAMITE);
        }
        break;
        case OBJECT__MINIBOT_ALLY_GEMSTONE:
        {
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__USE);
            add_new_list_element_to_list_end(skill_list, (void*) SKILL__MINIBOT_MERGE);

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
    for(ListElem* elem = state->enemy_list->head; elem != NULL; elem = elem->next)
    {
        Enemy* enemy = (Enemy*) elem->data;

        if(enemy->object == object)
        {
            return enemy;
        }
    }

    return 0;
}

Ally* get_ally_of_object(State* state, Object* object)
{
    for(ListElem* elem = state->ally_list->head; elem != NULL; elem = elem->next)
    {
        Ally* ally = (Ally*) elem->data;

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

    while(texture_elem != NULL && tilemap_pos_elem != NULL)
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
    if(state->curr_room != NULL)
    {
        remove_all_list_elements(state->enemy_list, 1);
        for(ListElem* curr_elem = state->curr_room->object_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != NULL && is_object_enemy(curr_object) && !curr_object->is_to_be_removed)
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
    List* environment_enemy_list_list =
        new_list((void(*)(void*))destroy_vec2i);
    List* non_environment_enemy_list_list =
        new_list((void(*)(void*))destroy_vec2i);

    for(ListElem* curr_elem = state->enemy_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        if(curr_enemy != NULL)
        {
            if(is_object_environment(curr_enemy->object))
            {
                add_new_list_element_to_list_end(
                    environment_enemy_list_list,
                    curr_enemy
                );
            }
            else
            {
                add_new_list_element_to_list_end(
                    non_environment_enemy_list_list,
                    curr_enemy
                );
            }
        }
    }

    int curr_order_number = 1;
    for(ListElem* curr_elem = environment_enemy_list_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        if(curr_enemy != NULL)
        {
            curr_enemy->order_number = curr_order_number;
            curr_order_number++;
        }
    }
    for(ListElem* curr_elem = non_environment_enemy_list_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        if(curr_enemy != NULL)
        {
            curr_enemy->order_number = curr_order_number;
            curr_order_number++;
        }
    }

    remove_all_list_elements(
        environment_enemy_list_list,
        0
    );
    destroy_list(environment_enemy_list_list);
    remove_all_list_elements(
        non_environment_enemy_list_list,
        0
    );
    destroy_list(non_environment_enemy_list_list);
}

void clear_enemy_attack_actions_and_draw(
    State* state,
    Enemy* enemy
)
{
    if(enemy != NULL)
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
    Textures* textures,
    Sounds* sounds
)
{
    if(enemy != NULL)
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
            textures,
            sounds
        );
    }
}

// ally

void update_ally_list(State* state)
{
    if(state->curr_room != NULL)
    {
        remove_all_list_elements(state->ally_list, 1);
        for(ListElem* curr_elem = state->curr_room->object_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != NULL && is_object_ally(curr_object))
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
    if(ally != NULL)
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
    if(ally != NULL)
    {
        ally->object->action_points = ALLY_MAX_ACTION_POINTS;
    }
}


void clear_curr_ally_attack_actions_and_draw(
    State* state
)
{
    if(state->curr_ally != NULL)
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
    Textures* textures,
    Sounds* sounds
)
{
    if(state->curr_ally != NULL)
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
            textures,
            sounds
        );
    }
}

// other

void remove_all_object_to_be_removed(State* state)
{
    if(state->curr_room != NULL)
    {
        List* object_to_be_removed_list = new_list((void (*)(void*)) & destroy_object);

        for(ListElem* curr_elem = state->curr_room->object_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != NULL && curr_object->is_to_be_removed)
            {
                add_new_list_element_to_list_end(object_to_be_removed_list, curr_object);
            }
        }

        for(ListElem* curr_elem = object_to_be_removed_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Object* curr_object = (Object*) curr_elem->data;

            if(curr_object != NULL)
            {
                room_remove_object(state->curr_room, curr_object, 1);
            }
        }

        remove_all_list_elements(object_to_be_removed_list, 0);
        destroy_list(object_to_be_removed_list);
    }
}

int is_floor_traversable_for_object(
    int floor,
    Object* object
)
{
    return ((!is_object_floating(object) && !is_object_flying(object) && is_floor_traversable(floor)) ||
            (is_object_floating(object) && is_floor_traversable_for_floating(floor)) ||
            (is_object_flying(object) && is_floor_traversable_for_flying(floor)));
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

// mechanism

void add_mechanism(
    State* state,
    Mechanism* mechanism
)
{
    add_new_list_element_to_list_end(
        state->mechanism_list,
        mechanism
    );
}

void execute_all_mechanisms(
    State* state
)
{
    for(ListElem* curr_mechanism_elem = state->mechanism_list->head;
        curr_mechanism_elem != NULL; curr_mechanism_elem = curr_mechanism_elem->next)
    {
        Mechanism* curr_mechanism = curr_mechanism_elem->data;

        if(curr_mechanism != NULL)
        {
            execute_mechanism(state, curr_mechanism);
        }
    }
}

void execute_mechanism(
    State* state,
    Mechanism* mechanism
)
{
    if(mechanism == NULL) return;

    int is_in_1 = mechanism->is_in_1;
    char* in_1_room_name = mechanism->in_1_room_name;
    Vec2i in_1_tilemap_pos = mechanism->in_1_tilemap_pos;
    int in_1_is_object = mechanism->in_1_is_object;
    int in_1_type = mechanism->in_1_type;
    Room* in_1_room = get_room(state, in_1_room_name);
    Object* in_1_object = room_get_object_at(in_1_room, in_1_tilemap_pos);
    int in_1_floor = room_get_floor_at(in_1_room, in_1_tilemap_pos);

    int is_in_2 = mechanism->is_in_2;
    char* in_2_room_name = mechanism->in_2_room_name;
    Vec2i in_2_tilemap_pos = mechanism->in_2_tilemap_pos;
    int in_2_is_object = mechanism->in_2_is_object;
    int in_2_type = mechanism->in_2_type;
    Room* in_2_room = get_room(state, in_2_room_name);
    Object* in_2_object = room_get_object_at(in_2_room, in_2_tilemap_pos);
    int in_2_floor = room_get_floor_at(in_2_room, in_2_tilemap_pos);

    int is_in_3 = mechanism->is_in_3;
    char* in_3_room_name = mechanism->in_3_room_name;
    Vec2i in_3_tilemap_pos = mechanism->in_3_tilemap_pos;
    int in_3_is_object = mechanism->in_3_is_object;
    int in_3_type = mechanism->in_3_type;
    Room* in_3_room = get_room(state, in_3_room_name);
    Object* in_3_object = room_get_object_at(in_3_room, in_3_tilemap_pos);
    int in_3_floor = room_get_floor_at(in_3_room, in_3_tilemap_pos);

    int is_out = mechanism->is_out;
    char* out_room_name = mechanism->out_room_name;
    Vec2i out_tilemap_pos = mechanism->out_tilemap_pos;
    int out_is_object = mechanism->out_is_object;
    int out_type = mechanism->out_type;
    Room* out_room = get_room(state, out_room_name);
    Object* out_object = room_get_object_at(out_room, out_tilemap_pos);
    int out_floor = room_get_floor_at(out_room, out_tilemap_pos);

    int is_triggered = TRUE;

    if(is_in_1)
    {
        if(in_1_is_object &&
           ((in_1_object == NULL && in_1_type != OBJECT__NONE) ||
            (in_1_object != NULL && in_1_type != in_1_object->type)))
        {
            is_triggered = FALSE;
        }

        if(!in_1_is_object &&
           in_1_type != in_1_floor)
        {
            is_triggered = FALSE;
        }
    }

    if(is_in_2)
    {
        if(in_2_is_object &&
           ((in_2_object == NULL && in_2_type != OBJECT__NONE) ||
            (in_2_object != NULL && in_2_type != in_2_object->type)))
        {
            is_triggered = FALSE;
        }

        if(!in_2_is_object &&
           in_2_type != in_2_floor)
        {
            is_triggered = FALSE;
        }
    }

    if(is_in_3)
    {
        if(in_3_is_object &&
           ((in_3_object == NULL && in_3_type != OBJECT__NONE) ||
            (in_3_object != NULL && in_3_type != in_3_object->type)))
        {
            is_triggered = FALSE;
        }

        if(!in_3_is_object &&
           in_3_type != in_3_floor)
        {
            is_triggered = FALSE;
        }
    }

    if(is_triggered)
    {
        if(is_out)
        {
            if(out_is_object)
            {
                if(out_type == OBJECT__NONE && out_object != NULL)
                {
                    room_remove_object(
                        out_room,
                        out_object,
                        1
                    );
                }
                else if(out_type != OBJECT__NONE && out_object != NULL)
                {
                    out_object->type = out_type;
                }
                else if(out_type != OBJECT__NONE && out_object == NULL)
                {
                    room_add_object_at(
                        out_room,
                        new_object(out_type),
                        out_tilemap_pos
                    );
                }
            }
            else
            {
                room_change_floor_at(
                    out_room,
                    out_floor,
                    out_tilemap_pos
                );
            }
        }
    }
}
