#include "../inc/state.h"

void skill_on_use(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    Textures* textures,
    Sounds* sounds,
    Musics* musics,
    Colors* colors
)
{
    Object* source_object = room_get_object_at(state->curr_room, source_tilemap_pos);
    Object* target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
    Object* target_2_object = room_get_object_at(state->curr_room, target_2_tilemap_pos);

    switch(skill)
    {
        case SKILL__USE:
        {
            if(target_2_object != NULL)
            {
                if(target_2_object->type == OBJECT__THRONE)
                {
                    state->was_throne_used = TRUE;
                }
                else if(is_object_station(target_2_object))
                {
                    int augmentation =
                        get_station_augmentation(target_2_object);
                    hero_add_augmentation(state, augmentation);
                }
                else if(is_object_exit(target_2_object))
                {
                    Passage* passage = get_passage(
                        state,
                        state->curr_room->name,
                        target_2_tilemap_pos
                    );

                    if(passage != NULL)
                    {
                        Room* room = get_room(state, passage->to_room_name);

                        if(room != NULL)
                        {
                            // travel
                            room_remove_object(
                                state->curr_room,
                                state->curr_ally->object,
                                0);
                            set_curr_room(state, room);
                            state->background_texture = state->curr_room->background_texture;
                            room_add_object_at(
                                room,
                                state->curr_ally->object,
                                passage->to_tilemap_pos);

                            // visited status
                            int was_room_already_visited = is_data_in_list(
                                state->visited_room_list,
                                room
                            );
                            if(!was_room_already_visited)
                            {
                                add_new_list_element_to_list_end(
                                    state->visited_room_list,
                                    room
                                );
                            }

                            // hint animation
                            if(!was_room_already_visited)
                            {
                                if(strcmp(room->name,"7_3") == 0)
                                {
                                    add_animation_to_animation_list(
                                        state,
                                        new_animation_flash_sprite_in_gamemap(
                                            textures->object.station_outline,
                                            vec2f(7,1),
                                            1.5f,
                                            2
                                        ),
                                        textures,
                                        sounds,
                                        musics,
                                        colors
                                    );
                                }
                                else if(strcmp(room->name,"6_3") == 0)
                                {
                                    add_animation_to_animation_list(
                                        state,
                                        new_animation_flash_sprite_in_gamemap(
                                            textures->object.crate_dynamite_item_outline,
                                            vec2f(2,2),
                                            1.5f,
                                            2
                                        ),
                                        textures,
                                        sounds,
                                        musics,
                                        colors
                                    );
                                }
                                else if(strcmp(room->name,"6_1") == 0)
                                {
                                    add_animation_to_animation_list(
                                        state,
                                        new_animation_flash_sprite_in_gamemap(
                                            textures->object.stalactite_outline,
                                            vec2f(2,2),
                                            1.5f,
                                            2
                                        ),
                                        textures,
                                        sounds,
                                        musics,
                                        colors
                                    );
                                }
                            }

                            // all enemies
                            update_enemy_list(state);
                            update_all_enemy_order(state);
                            for(ListElem* curr_elem = state->enemy_list->head;
                                curr_elem != NULL; curr_elem = curr_elem->next)
                            {
                                Enemy* curr_enemy = (Enemy*) curr_elem->data;
                                if(!was_room_already_visited)
                                {
                                    update_enemy_attack_dir4(state, curr_enemy);
                                }
                                update_enemy_attack_targets(state, curr_enemy);
                                clear_enemy_attack_actions_and_draw(state, curr_enemy);
                                get_enemy_attack_actions_and_draw(state, curr_enemy, textures, sounds);
                            }

                            // all allies
                            update_ally_list(state);
                            for(ListElem* curr_elem = state->ally_list->head;
                                curr_elem != NULL; curr_elem = curr_elem->next)
                            {
                                Ally* curr_ally = (Ally*) curr_elem->data;
                                update_ally_skill_list(state, curr_ally);
                            }

                            // curr ally
                            int was_prev_ally_chosen = FALSE;
                            for(ListElem* curr_elem = state->ally_list->head;
                                !was_prev_ally_chosen && curr_elem != NULL;
                                curr_elem = curr_elem->next)
                            {
                                Ally* curr_ally = (Ally*) curr_elem->data;
                                if(curr_ally != NULL)
                                {
                                    if(curr_ally->object != NULL &&
                                       curr_ally->object == state->curr_ally->object)
                                    {
                                        state->curr_ally_list_elem = curr_elem;
                                        state->curr_ally = curr_ally;
                                        was_prev_ally_chosen = TRUE;
                                    }
                                }
                            }
                            if(!was_prev_ally_chosen)
                            {
                                state->curr_ally_list_elem = state->ally_list->head;
                                state->curr_ally = state->curr_ally_list_elem->data;
                            }

                            // save state

                            state->curr_ally->object->action_points--;
                            save_state(state, textures);
                            state->curr_ally->object->action_points++;
                        }
                    }
                }
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

                if(floor != FLOOR__NONE)
                {
                    if(is_floor_exit(floor))
                    {
                        Passage* passage = get_passage(
                            state,
                            state->curr_room->name,
                            target_2_tilemap_pos
                        );

                        if(passage != NULL)
                        {
                            Room* room = get_room(state, passage->to_room_name);

                            if(room != NULL)
                            {
                                // travel
                                room_remove_object(
                                    state->curr_room,
                                    state->curr_ally->object,
                                    0);
                                set_curr_room(state, room);
                                state->background_texture = state->curr_room->background_texture;
                                room_add_object_at(
                                    room,
                                    state->curr_ally->object,
                                    passage->to_tilemap_pos);

                                // visited status
                                int was_room_already_visited = is_data_in_list(
                                    state->visited_room_list,
                                    room
                                );
                                if(!was_room_already_visited)
                                {
                                    add_new_list_element_to_list_end(
                                        state->visited_room_list,
                                        room
                                    );
                                }

                                // all enemies
                                update_enemy_list(state);
                                update_all_enemy_order(state);
                                for(ListElem* curr_elem = state->enemy_list->head;
                                    curr_elem != NULL; curr_elem = curr_elem->next)
                                {
                                    Enemy* curr_enemy = (Enemy*) curr_elem->data;
                                    if(!was_room_already_visited)
                                    {
                                        update_enemy_attack_dir4(state, curr_enemy);
                                    }
                                    update_enemy_attack_targets(state, curr_enemy);
                                    clear_enemy_attack_actions_and_draw(state, curr_enemy);
                                    get_enemy_attack_actions_and_draw(state, curr_enemy, textures, sounds);
                                }

                                // all allies
                                update_ally_list(state);
                                for(ListElem* curr_elem = state->ally_list->head;
                                    curr_elem != NULL; curr_elem = curr_elem->next)
                                {
                                    Ally* curr_ally = (Ally*) curr_elem->data;
                                    update_ally_skill_list(state, curr_ally);
                                }

                                // curr ally
                                int was_prev_ally_chosen = FALSE;
                                for(ListElem* curr_elem = state->ally_list->head;
                                    !was_prev_ally_chosen && curr_elem != NULL;
                                    curr_elem = curr_elem->next)
                                {
                                    Ally* curr_ally = (Ally*) curr_elem->data;
                                    if(curr_ally != NULL)
                                    {
                                        if(curr_ally->object != NULL &&
                                           curr_ally->object == state->curr_ally->object)
                                        {
                                            state->curr_ally_list_elem = curr_elem;
                                            state->curr_ally = curr_ally;
                                            was_prev_ally_chosen = TRUE;
                                        }
                                    }
                                }
                                if(!was_prev_ally_chosen)
                                {
                                    state->curr_ally_list_elem = state->ally_list->head;
                                    state->curr_ally = state->curr_ally_list_elem->data;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            //
        }
        break;
        case SKILL__TELEPORTATION:
        {
            if(target_2_object == NULL)
            {
                source_object->tilemap_pos = target_2_tilemap_pos;
            }
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        case SKILL__PICK_ITEM_FAR:
        {
            int item_type = 0;
            int item_count = 0;

            if(target_2_object != NULL)
            {
                item_type = get_object_item_type(target_2_object);
                item_count = get_object_item_count(target_2_object);
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);
                item_type = get_floor_item_type(floor);
                item_count = get_floor_item_count(floor);
            }

            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                state->hero_item_number[item_type] += item_count;
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY)
            {
                switch(item_type)
                {
                    case ITEM__CELL: source_object->type = OBJECT__MINIBOT_ALLY_CELL; break;
                    case ITEM__DYNAMITE: source_object->type = OBJECT__MINIBOT_ALLY_DYNAMITE; break;
                    case ITEM__GEMSTONE: source_object->type = OBJECT__MINIBOT_ALLY_GEMSTONE; break;
                    default:break;
                }
            }
        }
        break;
        case SKILL__PUT_ITEM_CELL_CLOSE:
        case SKILL__PUT_ITEM_CELL_FAR:
        {
            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                if(state->hero_item_number[ITEM__CELL] >= 1)
                {
                    state->hero_item_number[ITEM__CELL]--;
                }
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY_CELL ||
                    source_object->type == OBJECT__MINIBOT_ALLY_DYNAMITE ||
                    source_object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                source_object->type = OBJECT__MINIBOT_ALLY;
            }
        }
        break;
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        {
            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                if(state->hero_item_number[ITEM__DYNAMITE] >= 1)
                {
                    state->hero_item_number[ITEM__DYNAMITE]--;
                }
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY_CELL ||
                    source_object->type == OBJECT__MINIBOT_ALLY_DYNAMITE ||
                    source_object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                source_object->type = OBJECT__MINIBOT_ALLY;
            }
        }
        break;
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                if(state->hero_item_number[ITEM__GEMSTONE] >= 1)
                {
                    state->hero_item_number[ITEM__GEMSTONE]--;
                }
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY_CELL ||
                    source_object->type == OBJECT__MINIBOT_ALLY_DYNAMITE ||
                    source_object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                source_object->type = OBJECT__MINIBOT_ALLY;
            }
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                if(state->hero_item_number[ITEM__CELL] >= 1)
                {
                    state->hero_item_number[ITEM__CELL]--;
                }
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY_CELL ||
                    source_object->type == OBJECT__MINIBOT_ALLY_DYNAMITE ||
                    source_object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                source_object->type = OBJECT__MINIBOT_ALLY;
            }
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                if(state->hero_item_number[ITEM__DYNAMITE] >= 1)
                {
                    state->hero_item_number[ITEM__DYNAMITE]--;
                }
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY_CELL ||
                    source_object->type == OBJECT__MINIBOT_ALLY_DYNAMITE ||
                    source_object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                source_object->type = OBJECT__MINIBOT_ALLY;
            }
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            if(source_object->type == OBJECT__HERO ||
               source_object->type == OBJECT__HERO_FLOATING ||
               source_object->type == OBJECT__HERO_FLYING)
            {
                if(state->hero_item_number[ITEM__GEMSTONE] >= 1)
                {
                    state->hero_item_number[ITEM__GEMSTONE]--;
                }
            }
            else if(source_object->type == OBJECT__MINIBOT_ALLY_CELL ||
                    source_object->type == OBJECT__MINIBOT_ALLY_DYNAMITE ||
                    source_object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                source_object->type = OBJECT__MINIBOT_ALLY;
            }
        }
        break;
        case SKILL__LAUNCH_MINIBOT:
        {

            state->was_minibot_launched = TRUE;
            state->minibot_object->action_points = ALLY_MAX_ACTION_POINTS;
        }
        break;
        case SKILL__MINIBOT_MERGE:
        {
            if(target_2_object != NULL &&
               (target_2_object->type == OBJECT__HERO ||
                target_2_object->type == OBJECT__HERO_FLOATING ||
                target_2_object->type == OBJECT__HERO_FLYING))
            {
                state->was_minibot_launched = FALSE;

                room_remove_object(
                    state->curr_room,
                    state->minibot_object,
                    0
                );

                if(state->curr_ally->object->type == OBJECT__MINIBOT_ALLY)
                {
                    //
                }
                else if(state->curr_ally->object->type == OBJECT__MINIBOT_ALLY_CELL)
                {
                    state->hero_item_number[ITEM__CELL]++;
                }
                else if(state->curr_ally->object->type == OBJECT__MINIBOT_ALLY_DYNAMITE)
                {
                    state->hero_item_number[ITEM__DYNAMITE]++;
                }
                else if(state->curr_ally->object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
                {
                    state->hero_item_number[ITEM__GEMSTONE]++;
                }
            }
        }
        break;
        case SKILL__PULL_HOOK:
        case SKILL__PULL_SPIDERWEB:
        case SKILL__PULL_TENTACLE:
        case SKILL__PULL_TONGUE:
        case SKILL__DRAG_HOOK:
        case SKILL__DRAG_SPIDERWEB:
        case SKILL__DRAG_TENTACLE:
        case SKILL__DRAG_AND_THROW_HOOK:
        case SKILL__DRAG_AND_THROW_TONGUE:
        {
            play_sound(sounds->throww);
        }
        break;
        case SKILL__STOMP:
        {
            play_sound(sounds->stomp);
        }
        break;
        case SKILL__TURRET_BOMB:
        case SKILL__TURRET_PROJECTILE:
        {
            play_sound(sounds->throww);
        }
        break;
        case SKILL__TURRET_LASER:
        {
            play_sound(sounds->laser);
        }
        break;
        case SKILL__KILL_AROUND:
        {
            play_sound(sounds->kill_around);
        }
        break;
        case SKILL__ENVIRONMENT_FALLING_STALACTITE:
        {
            play_sound(sounds->falling_stalactite);
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_WATER:
        {
            play_sound(sounds->emerge_water);
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_PIT:
        {
            play_sound(sounds->emerge_pit);
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_BURROW:
        {
            play_sound(sounds->emerge_burrow);
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:
        {
            play_sound(sounds->emerge_pipe);
        }
        break;
        case SKILL__ENVIRONMENT_COLLAPSE_BURROW:
        {
            play_sound(sounds->collapse_burrow);
        }
        break;
        case SKILL__ENVIRONMENT_CONV_BELT:
        {
            play_sound(sounds->conv_belt);
        }
        break;
        break;
        default:
        break;
    }
}
