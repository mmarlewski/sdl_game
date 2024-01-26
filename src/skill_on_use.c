#include "../inc/state.h"

void skill_on_use(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

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
                int floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);

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
        default:
        break;
    }
}
