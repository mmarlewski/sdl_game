#include "../inc/game.h"
#include <limits.h>

void draw_gamemap(Renderer* renderer, State* state, Textures* textures, Colors* colors, Fonts* fonts)
{
    // i know...
    if(state->gamestate == GAMESTATE__NONE || state->gamestate == GAMESTATE__GAME_START) return;

    // shadow

    draw_texture_at_world_pos(
        renderer,
        textures->shadow,
        colors->none,
        1.0f,
        vec2f(
            -(GAMEMAP_WIDTH * 0.5f) + (TILE_LENGTH * 0.5f),
            (TILE_LENGTH * 0.5f)
        ),
        state->camera_world_pos,
        state->camera_zoom
    );

    // floors, highlights

    for(int i = 0; i < TILEMAP_LENGTH; i++)
    {
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            Vec2i tilemap_pos = vec2i(j, i);
            Vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);
            world_iso_pos.y += TILE_LENGTH * 0.25f;

            int floor = state->curr_room->floor_array[i][j];
            Texture* tile_floor_texture = NULL;
            if(sin(state->time * 3) > 0)
            {
                tile_floor_texture =
                    get_texture_1_from_floor_type(floor, textures);
            }
            else
            {
                tile_floor_texture =
                    get_texture_2_from_floor_type(floor, textures);
            }

            // tile

            draw_texture_at_world_pos(
                renderer,
                tile_floor_texture,
                colors->none,
                1.0f,
                world_iso_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // possible target 1 floor

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1)
    {
        for(ListElem* curr_elem = state->possible_target_1_tilemap_pos_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Vec2i* tilemap_pos = (Vec2i*) curr_elem->data;

            draw_texture_at_tilemap_pos(
                renderer,
                textures->floor.highlight,
                colors->orange,
                0.5f,
                *tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // possible target 2 floor

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        for(ListElem* curr_elem = state->possible_target_2_tilemap_pos_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Vec2i* tilemap_pos = (Vec2i*) curr_elem->data;

            draw_texture_at_tilemap_pos(
                renderer,
                textures->floor.highlight,
                colors->pink,
                0.5f,
                *tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // possible hint floor

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        for(ListElem* curr_elem = state->possible_hint_tilemap_pos_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
        {
            Vec2i* tilemap_pos = (Vec2i*) curr_elem->data;

            draw_texture_at_tilemap_pos(
                renderer,
                textures->floor.highlight,
                colors->white,
                (1.0f - fabs(sin(state->time * 1.0f))),
                *tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // selected floor

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        if(is_tilemap_in_bounds(state->selected_tilemap_pos))
        {
            draw_texture_at_tilemap_pos(
                renderer,
                textures->floor.highlight,
                colors->yellow,
                0.5f,
                state->selected_tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // enemy skill draw below

    if(state->gamestate != GAMESTATE__ALLY_CHOOSING_TARGET_1 &&
       state->gamestate != GAMESTATE__ALLY_CHOOSING_TARGET_2 &&
       state->gamestate != GAMESTATE__ALLY_EXECUTING_ANIMATION &&
       state->gamestate != GAMESTATE__ENEMY_EXECUTING_ANIMATION &&
       state->gamestate != GAMESTATE__ENEMY_EXECUTING_ATTACK &&
       state->gamestate != GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        Object* hover_object = room_get_object_at(
            state->curr_room,
            state->mouse_tilemap_pos
        );
        Enemy* hover_enemy = get_enemy_of_object(
            state,
            hover_object
        );

        if(hover_object != NULL &&
           hover_enemy != NULL &&
           is_object_enemy(hover_object) &&
           !hover_object->is_to_be_removed &&
           hover_object->is_visible &&
           !hover_enemy->performed_attack)
        {
            draw_texture_list(
                renderer,
                state,
                hover_enemy->draw_below_texture_list,
                hover_enemy->draw_below_tilemap_pos_list,
                colors->yellow,
                1.0f
            );
        }
        else
        {
            for(ListElem* curr_elem = state->curr_room->object_list->head; curr_elem != NULL; curr_elem = curr_elem->next)
            {
                Object* curr_object = (Object*) curr_elem->data;
                Enemy* curr_enemy = get_enemy_of_object(state, curr_object);

                if(curr_enemy != NULL)
                {
                    Action* curr_action = curr_enemy->action_sequence;

                    if(!curr_enemy->performed_attack &&
                       !curr_enemy->object->is_to_be_removed)
                    {
                        if(!(state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK &&
                             state->enemy_action_sequence == curr_action) &&
                           !(state->gamestate == GAMESTATE__ENEMY_MOVING &&
                             state->enemy_action_sequence == curr_action))
                        {
                            draw_texture_list(
                                renderer,
                                state,
                                curr_enemy->draw_below_texture_list,
                                curr_enemy->draw_below_tilemap_pos_list,
                                colors->red,
                                1.0f
                            );
                        }
                    }
                }
            }
        }
    }

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK)
    {
        Enemy* curr_enemy = state->curr_enemy;

        if(curr_enemy != NULL &&
           !curr_enemy->object->is_to_be_removed &&
           curr_enemy->object->is_visible)
        {
            draw_texture_list(
                renderer,
                state,
                curr_enemy->draw_below_texture_list,
                curr_enemy->draw_below_tilemap_pos_list,
                colors->yellow,
                1.0f
            );
        }
    }

    // hero skill draw below

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        draw_texture_list(
            renderer,
            state,
            state->curr_ally_draw_below_texture_list,
            state->curr_ally_draw_below_tilemap_pos_list,
            colors->green,
            1.0f
        );
    }

    // objects, sprites

    for(int i = 0; i < TILEMAP_LENGTH; i++)
    {
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            Vec2i tilemap_pos = vec2i(j, i);
            Vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

            // objects

            for(ListElem* curr_elem = state->curr_room->object_list->head; curr_elem != NULL; curr_elem = curr_elem->next)
            {
                Object* curr_object = (Object*) curr_elem->data;
                Enemy* curr_enemy = get_enemy_of_object(state, curr_object);

                if(!curr_object->is_to_be_removed &&
                   curr_object->is_visible &&
                   curr_object->tilemap_pos.x == j &&
                   curr_object->tilemap_pos.y == i)
                {
                    Texture* texture = NULL;
                    if(sin(state->time * 3) > 0)
                    {
                        texture = get_texture_1_from_object(curr_object, textures);
                    }
                    else
                    {
                        texture = get_texture_2_from_object(curr_object, textures);
                    }

                    draw_texture_at_world_pos(
                        renderer,
                        texture,
                        colors->none,
                        1.0f,
                        world_iso_pos,
                        state->camera_world_pos,
                        state->camera_zoom
                    );

                    if(curr_enemy != NULL &&
                       state->show_all_order_numbers)
                    {
                        draw_texture_at_world_pos(
                            renderer,
                            get_texture_order_number(textures, curr_enemy->order_number),
                            colors->yellow,
                            1.0f,
                            world_iso_pos,
                            state->camera_world_pos,
                            state->camera_zoom
                        );
                    }
                }
            }

            // sprites

            for(ListElem* curr_elem = state->sprite_list->head; curr_elem != NULL; curr_elem = curr_elem->next)
            {
                Sprite* curr_sprite = (Sprite*) curr_elem->data;
                Vec2i curr_sprite_tilemap_pos = vec2i(
                    floor(curr_sprite->gamemap_pos.x + 0.4f),
                    floor(curr_sprite->gamemap_pos.y + 0.4f)
                );

                if(curr_sprite_tilemap_pos.x == tilemap_pos.x && curr_sprite_tilemap_pos.y == tilemap_pos.y)
                {
                    Vec2f gamemap_pos = vec2f(curr_sprite->gamemap_pos.x, curr_sprite->gamemap_pos.y);
                    Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
                    Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);
                    world_iso_pos.y += curr_sprite->gamemap_pos.z * (TILE_LENGTH * 0.5f);

                    draw_texture_at_world_pos(
                        renderer,
                        curr_sprite->texture,
                        colors->none,
                        curr_sprite->transparency,
                        world_iso_pos,
                        state->camera_world_pos,
                        state->camera_zoom
                    );
                }
            }
        }
    }

    // enemy skill draw above

    if(state->gamestate != GAMESTATE__ALLY_CHOOSING_TARGET_1 &&
       state->gamestate != GAMESTATE__ALLY_CHOOSING_TARGET_2 &&
       state->gamestate != GAMESTATE__ALLY_EXECUTING_ANIMATION &&
       state->gamestate != GAMESTATE__ENEMY_EXECUTING_ANIMATION &&
       state->gamestate != GAMESTATE__ENEMY_EXECUTING_ATTACK &&
       state->gamestate != GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        Object* hover_object = room_get_object_at(state->curr_room, state->mouse_tilemap_pos);
        Enemy* hover_enemy = get_enemy_of_object(state, hover_object);

        if(hover_object != NULL &&
           hover_enemy != NULL &&
           is_object_enemy(hover_object) &&
           !hover_object->is_to_be_removed &&
           hover_object->is_visible &&
           !hover_enemy->performed_attack)
        {
            draw_texture_list(
                renderer,
                state,
                hover_enemy->draw_above_texture_list,
                hover_enemy->draw_above_tilemap_pos_list,
                colors->yellow,
                1.0f
            );
        }
        else
        {
            for(ListElem* curr_elem = state->curr_room->object_list->head; curr_elem != NULL; curr_elem = curr_elem->next)
            {
                Object* hover_object = (Object*) curr_elem->data;
                Enemy* hover_enemy = get_enemy_of_object(state, hover_object);

                if(hover_enemy != NULL)
                {
                    Action* hover_action = hover_enemy->action_sequence;

                    if(!hover_enemy->performed_attack)
                    {
                        if(!(state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK &&
                             state->enemy_action_sequence == hover_action) &&
                           !(state->gamestate == GAMESTATE__ENEMY_MOVING &&
                             state->enemy_action_sequence == hover_action))
                        {
                            draw_texture_list(
                                renderer,
                                state,
                                hover_enemy->draw_above_texture_list,
                                hover_enemy->draw_above_tilemap_pos_list,
                                colors->red,
                                1.0f
                            );
                        }
                    }
                }
            }
        }
    }

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK)
    {
        Enemy* curr_enemy = state->curr_enemy;

        if(curr_enemy != NULL &&
           !curr_enemy->object->is_to_be_removed &&
           curr_enemy->object->is_visible)
        {
            draw_texture_list(
                renderer,
                state,
                curr_enemy->draw_above_texture_list,
                curr_enemy->draw_above_tilemap_pos_list,
                colors->yellow,
                1.0f
            );

            draw_texture_list(
                renderer,
                state,
                curr_enemy->draw_effect_texture_list,
                curr_enemy->draw_effect_tilemap_pos_list,
                colors->none,
                0.75f
            );
        }
    }

    // hero skill draw above

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        draw_texture_list(
            renderer,
            state,
            state->curr_ally_draw_above_texture_list,
            state->curr_ally_draw_above_tilemap_pos_list,
            colors->green,
            1.0f
        );
    }

    // orange outline

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1)
    {
        for(ListElem* curr_pos_elem = state->possible_target_1_tilemap_pos_list->head;
        curr_pos_elem != NULL; curr_pos_elem = curr_pos_elem->next)
        {
            Vec2i curr_pos = *(Vec2i*)(curr_pos_elem->data);

            Object* curr_object = room_get_object_at(
                state->curr_room, 
                curr_pos
            );

            if(curr_object != NULL)
            {
                Texture* texture_outline = NULL;
                if(sin(state->time * 3) > 0)
                {
                    texture_outline = get_texture_1_outline_from_object(
                        curr_object, textures);
                }
                else
                {
                    texture_outline = get_texture_2_outline_from_object(
                        curr_object, textures);
                }
                draw_texture_at_tilemap_pos(
                    renderer,
                    texture_outline,
                    colors->orange,
                    1.0f,
                    curr_object->tilemap_pos,
                    state->camera_world_pos,
                    state->camera_zoom
                );
            }
        }
    }

    // pink outline

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        for(ListElem* curr_pos_elem = state->possible_target_2_tilemap_pos_list->head;
        curr_pos_elem != NULL; curr_pos_elem = curr_pos_elem->next)
        {
            Vec2i curr_pos = *(Vec2i*)(curr_pos_elem->data);

            Object* curr_object = room_get_object_at(
                state->curr_room, 
                curr_pos
            );

            if(curr_object != NULL)
            {
                Texture* texture_outline = NULL;
                if(sin(state->time * 3) > 0)
                {
                    texture_outline = get_texture_1_outline_from_object(
                        curr_object, textures);
                }
                else
                {
                    texture_outline = get_texture_2_outline_from_object(
                        curr_object, textures);
                }
                draw_texture_at_tilemap_pos(
                    renderer,
                    texture_outline,
                    colors->pink,
                    1.0f,
                    curr_object->tilemap_pos,
                    state->camera_world_pos,
                    state->camera_zoom
                );
            }
        }
    }

    // white outline

    if((state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 && is_skill_two_target(state->curr_ally_skill)) ||
    (state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 && !is_skill_two_target(state->curr_ally_skill)))
    {
        for(ListElem* curr_pos_elem = state->possible_hint_tilemap_pos_list->head;
        curr_pos_elem != NULL; curr_pos_elem = curr_pos_elem->next)
        {
            Vec2i curr_pos = *(Vec2i*)(curr_pos_elem->data);

            Object* curr_object = room_get_object_at(
                state->curr_room, 
                curr_pos
            );

            if(curr_object != NULL)
            {
                Texture* texture_outline = NULL;
                if(sin(state->time * 3) > 0)
                {
                    texture_outline = get_texture_1_outline_from_object(
                        curr_object, textures);
                }
                else
                {
                    texture_outline = get_texture_2_outline_from_object(
                        curr_object, textures);
                }
                draw_texture_at_tilemap_pos(
                    renderer,
                    texture_outline,
                    colors->white,
                    (1.0f - fabs(sin(state->time * 1.0f))),
                    curr_object->tilemap_pos,
                    state->camera_world_pos,
                    state->camera_zoom
                );
            }
        }
    }

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL)
    {
        Object* hover_object = room_get_object_at(state->curr_room, state->mouse_tilemap_pos);
        Enemy* hover_enemy = get_enemy_of_object(state, hover_object);

        if(hover_object != NULL &&
           !hover_object->is_to_be_removed &&
           hover_object->is_visible)
        {
            Vec2i selected_tilemap_pos = state->mouse_tilemap_pos;
            Vec2f selected_gamemap_pos = tilemap_pos_to_gamemap_pos(selected_tilemap_pos);
            Vec2f selected_world_cart_pos = gamemap_pos_to_world_pos(selected_gamemap_pos);
            Vec2f selected_world_iso_pos = cart_pos_to_iso_pos(selected_world_cart_pos);

            Texture* texture_outline = NULL;
            if(sin(state->time * 3) > 0)
            {
                texture_outline = get_texture_1_outline_from_object(hover_object, textures);
            }
            else
            {
                texture_outline = get_texture_2_outline_from_object(hover_object, textures);
            }
            draw_texture_at_world_pos(
                renderer,
                texture_outline,
                colors->yellow,
                1.0f,
                selected_world_iso_pos,
                state->camera_world_pos,
                state->camera_zoom
            );

            if(hover_enemy != NULL)
            {
                draw_texture_at_world_pos(
                    renderer,
                    get_texture_order_number(textures, hover_enemy->order_number),
                    colors->yellow,
                    1.0f,
                    selected_world_iso_pos,
                    state->camera_world_pos,
                    state->camera_zoom
                );
            }
        }
    }

    // red outline

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
       state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE)
    {
        Enemy* enemy = state->curr_enemy;

        if(enemy != NULL &&
           !enemy->object->is_to_be_removed &&
           enemy->object->is_visible)
        {
            Vec2i selected_tilemap_pos = enemy->object->tilemap_pos;
            Vec2f selected_gamemap_pos = tilemap_pos_to_gamemap_pos(selected_tilemap_pos);
            Vec2f selected_world_cart_pos = gamemap_pos_to_world_pos(selected_gamemap_pos);
            Vec2f selected_world_iso_pos = cart_pos_to_iso_pos(selected_world_cart_pos);

            Texture* texture_outline = NULL;
            if(sin(state->time * 3) > 0)
            {
                texture_outline = get_texture_1_outline_from_object(enemy->object, textures);
            }
            else
            {
                texture_outline = get_texture_2_outline_from_object(enemy->object, textures);
            }
            draw_texture_at_world_pos(
                renderer,
                texture_outline,
                colors->red,
                1.0f,
                selected_world_iso_pos,
                state->camera_world_pos,
                state->camera_zoom
            );

            if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK)
            {
                if(state->curr_enemy != NULL && is_tilemap_in_bounds(state->curr_enemy->object->tilemap_pos))
                {
                    draw_texture_at_world_pos(
                        renderer,
                        get_texture_order_number(textures, enemy->order_number),
                        colors->yellow,
                        1.0f,
                        selected_world_iso_pos,
                        state->camera_world_pos,
                        state->camera_zoom
                    );
                }
            }
        }
    }

    // yellow outline

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        Object* selected_object = room_get_object_at(
            state->curr_room,
            state->selected_tilemap_pos
        );

        if(selected_object != NULL)
        {
            Texture* texture_outline = NULL;
            if(sin(state->time * 3) > 0)
            {
                texture_outline = get_texture_1_outline_from_object(selected_object, textures);
            }
            else
            {
                texture_outline = get_texture_2_outline_from_object(selected_object, textures);
            }

            draw_texture_at_tilemap_pos(
                renderer,
                texture_outline,
                colors->yellow,
                1.0f,
                state->selected_tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // green outline

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        Texture* texture_outline = NULL;
        if(sin(state->time * 3) > 0)
        {
            texture_outline = get_texture_1_outline_from_object(state->curr_ally->object, textures);
        }
        else
        {
            texture_outline = get_texture_2_outline_from_object(state->curr_ally->object, textures);
        }
        draw_texture_at_tilemap_pos(
            renderer,
            texture_outline,
            colors->green,
            1.0f,
            state->curr_ally->object->tilemap_pos,
            state->camera_world_pos,
            state->camera_zoom
        );
    }

    // no positions

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1)
    {
        if(state->possible_target_1_tilemap_pos_list->size == 0)
        {
            draw_texture_at_tilemap_pos(
                renderer,
                textures->skill.no_targets,
                colors->none,
                1.0f,
                state->curr_ally->object->tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        if(state->possible_target_2_tilemap_pos_list->size == 0)
        {
            draw_texture_at_tilemap_pos(
                renderer,
                textures->skill.no_targets,
                colors->none,
                1.0f,
                state->curr_ally->object->tilemap_pos,
                state->camera_world_pos,
                state->camera_zoom
            );
        }
    }

    // enemy skill draw effect

    if(state->gamestate != GAMESTATE__ALLY_CHOOSING_TARGET_1 &&
       state->gamestate != GAMESTATE__ALLY_CHOOSING_TARGET_2 &&
       state->gamestate != GAMESTATE__ALLY_EXECUTING_ANIMATION &&
       state->gamestate != GAMESTATE__ENEMY_EXECUTING_ANIMATION &&
       state->gamestate != GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        Object* hover_object = room_get_object_at(state->curr_room, state->mouse_tilemap_pos);
        Enemy* hover_enemy = get_enemy_of_object(state, hover_object);

        if(hover_object != NULL &&
           hover_enemy != NULL &&
           is_object_enemy(hover_object) &&
           !hover_object->is_to_be_removed &&
           hover_object->is_visible &&
           !hover_enemy->performed_attack)
        {
            draw_texture_list(
                renderer,
                state,
                hover_enemy->draw_effect_texture_list,
                hover_enemy->draw_effect_tilemap_pos_list,
                colors->none,
                0.75f
            );
        }
    }

    // hero skill draw effect

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        draw_texture_list(
            renderer,
            state,
            state->curr_ally_draw_effect_texture_list,
            state->curr_ally_draw_effect_tilemap_pos_list,
            colors->none,
            0.75f
        );
    }
}
