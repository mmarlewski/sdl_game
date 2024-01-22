#include "../inc/state.h"

void skill_on_use(State* state, int skill)
{
    switch (skill)
    {
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
