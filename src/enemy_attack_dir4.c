#include "../inc/state.h"

void update_enemy_attack_dir4(State* state, Enemy* enemy)
{
    Object* enemy_object = enemy->object;

    enemy->skill = SKILL__NONE;
    enemy->target_1_tilemap_pos = vec2i(0,0);
    enemy->target_2_tilemap_pos = vec2i(0,0);

    switch(enemy_object->type)
    {
        case OBJECT__GOAT:
        case OBJECT__SPIDER:
        case OBJECT__BULL:
        case OBJECT__FLY:
        case OBJECT__CHAMELEON:
        case OBJECT__SQUID:
        {
            enemy->object->attack_dir4 = rand() % 4 + 1;
        }
        break;
        case OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN:
        {
            enemy->object->attack_dir4 = DIR4__DOWN;
        }
        break;
        default:
        break;
    }
}
