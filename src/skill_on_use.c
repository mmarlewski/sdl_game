#include "../inc/state.h"

void skill_on_use(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos)
{
    Object* source_object = room_get_object_at(state->curr_room, source_tilemap_pos);
    Object* target_1_object = room_get_object_at(state->curr_room, target_1_tilemap_pos);
    Object* target_2_object = room_get_object_at(state->curr_room, target_2_tilemap_pos);

    switch (skill)
    {
        case SKILL__HERO_PICK_ITEM_CLOSE:
        case SKILL__HERO_PICK_ITEM_FAR:
        {
            if(target_2_object != 0)
            {
                int item_type = get_object_item_type(target_2_object);
                int item_count = get_object_item_count(target_2_object);

                state->gamemap.item_number[item_type] += item_count;
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

                int item_type = get_floor_item_type(floor);
                int item_count = get_floor_item_count(floor);

                state->gamemap.item_number[item_type] += item_count;
            }
        }
        break;
        case SKILL__HERO_PUT_ITEM_CLOSE:
        case SKILL__HERO_PUT_ITEM_FAR:
        {
            if(state->gamemap.item_number[state->gamemap.curr_item] >= 1)
            {
                state->gamemap.item_number[state->gamemap.curr_item]--;
            }
        }
        break;
        case SKILL__HERO_THROW_CELL:
        {
            if(state->gamemap.item_number[ITEM__CELL] >= 1)
            {
                state->gamemap.item_number[ITEM__CELL]--;
            }
        }
        break;
        case SKILL__HERO_THROW_DYNAMITE:
        {
            if(state->gamemap.item_number[ITEM__DYNAMITE] >= 1)
            {
                state->gamemap.item_number[ITEM__DYNAMITE]--;
            }
        }
        break;
        case SKILL__HERO_THROW_GEMSTONE:
        {
            if(state->gamemap.item_number[ITEM__GEMSTONE] >= 1)
            {
                state->gamemap.item_number[ITEM__GEMSTONE]--;
            }
        }
        break;
        case SKILL__HERO_USE:
        {
            if(target_2_object != 0)
            {
                if(is_object_station(target_2_object))
                {
                    int augmentation = get_station_augmentation(target_2_object);
                    hero_add_augmentation(state, augmentation);
                }
                else if(is_object_exit(target_2_object))
                {
                    Passage* passage = get_passage(
                        state,
                        state->curr_room->name,
                        target_2_tilemap_pos
                        );

                    if(passage != 0)
                    {
                        Room* room = get_room(state, passage->to_room_name);

                        if(room != 0)
                        {
                            room_remove_object(state->curr_room, state->gamemap.object_hero);
                            set_curr_room(state, room);
                            room_add_object_at(room, state->gamemap.object_hero, passage->to_tilemap_pos);
                            determine_enemy_objects(state);
                            determine_enemy_order(state);
                        }
                    }
                }
            }
            else
            {
                int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

                if(floor != FLOOR_TYPE__NONE)
                {
                    if(is_floor_exit(floor))
                    {
                        Passage* passage = get_passage(
                            state,
                            state->curr_room->name,
                            target_2_tilemap_pos
                            );

                        if(passage != 0)
                        {
                            Room* room = get_room(state, passage->to_room_name);

                            if(room != 0)
                            {
                                room_remove_object(state->curr_room, state->gamemap.object_hero);
                                set_curr_room(state, room);
                                room_add_object_at(room, state->gamemap.object_hero, passage->to_tilemap_pos);
                                determine_enemy_objects(state);
                                determine_enemy_order(state);
                            }
                        }
                    }
                }
            }
        }
        break;
        default:
        break;
    }
}
