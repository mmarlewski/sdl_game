#include "../inc/game.h"

void draw_gamemap(Renderer* renderer, State* state, Textures* textures, Colors* colors)
{
    // floors, highlights

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            Vec2i tilemap_pos = vec2i(j,i);
            Vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

            Tile* tile = state->gamemap.tilemap[i][j];
            Texture* tile_floor_texture = get_texture_from_floor_type(tile->floor, textures);

            // tile

            draw_texture_at_world_pos(
                renderer,
                tile_floor_texture,
                colors->none,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );

            // possible target 1

            if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_1)
            {
                if(is_tilemap_pos_in_possible_target_1_tilemap_pos_list(state, tilemap_pos))
                {
                    draw_texture_at_world_pos(
                        renderer,
                        textures->highlight.highlight,
                colors->orange,
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }

            // possible target 2

            if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2)
            {
                if(is_tilemap_pos_in_possible_target_2_tilemap_pos_list(state, tilemap_pos))
                {
                    draw_texture_at_world_pos(
                        renderer,
                        textures->highlight.highlight,
                colors->pink,
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }

            // selected

            if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_1 || state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2)
            {
                if(state->gamemap.curr_selected_tilemap_pos.x == j && state->gamemap.curr_selected_tilemap_pos.y == i)
                {
                    draw_texture_at_world_pos(
                        renderer,
                        textures->highlight.highlight,
                colors->yellow,
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
        }
    }

    // objects, sprites

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            Vec2i tilemap_pos = vec2i(j,i);
            Vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

            // objects

            for(ListElem* curr_elem = state->gamemap.object_list->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                Object* curr_object = (Object*)curr_elem->data;
                if(!curr_object->is_dead &&
                curr_object->is_visible &&
                curr_object->tilemap_pos.x == j &&
                curr_object->tilemap_pos.y == i)
                {
                    draw_texture_at_world_pos(
                        renderer,
                        get_texture_from_object_type(curr_object->type, textures),
                colors->none,
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom);

                    if(is_object_enemy(curr_object->type) &&
                    state->gamemap.show_all_order_numbers)
                    {
                        draw_texture_at_world_pos(
                            renderer,
                            get_texture_order_number(textures, curr_object->enemy_order_number),
                colors->none,
                            world_iso_pos,
                            state->camera.world_pos,
                            state->camera.zoom
                            );
                    }
                }
            }

            // sprites

            for(ListElem* curr_elem = state->gamemap.sprite_list->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                Sprite* curr_sprite = (Sprite*)curr_elem->data;
                Vec2i curr_sprite_tilemap_pos = vec2i(
                    floor(curr_sprite->gamemap_pos.x + 0.4f),
                    floor(curr_sprite->gamemap_pos.y + 0.4f)
                    );

                if(curr_sprite_tilemap_pos.x == tilemap_pos.x && curr_sprite_tilemap_pos.y == tilemap_pos.y)
                {
                    Vec2f gamemap_pos = vec2f(curr_sprite->gamemap_pos.x,curr_sprite->gamemap_pos.y);
                    Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
                    Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);
                    world_iso_pos.y += curr_sprite->gamemap_pos.z * (TILE_LENGTH * 0.5f);

                    draw_texture_at_world_pos(
                        renderer,
                        curr_sprite->texture,
                colors->none,
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
        }
    }

    // enemy action sequence

    if(state->gamestate != GAMESTATE__HERO_CHOOSING_TARGET_1 &&
    state->gamestate != GAMESTATE__HERO_CHOOSING_TARGET_2 &&
    state->gamestate != GAMESTATE__HERO_EXECUTING_SKILL)
    {
        Object* hover_object = get_object_on_tilemap_pos(state, state->mouse.tilemap_pos);

        if(hover_object != 0 &&
        is_object_enemy(hover_object->type) &&
        !hover_object->is_dead &&
        hover_object->is_visible)
        {
            draw_action(renderer, state, hover_object->enemy_action_sequence, textures, colors);
        }
        else
        {
            for(ListElem* curr_elem = state->gamemap.object_enemy_list->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                Object* curr_object = (Object*)curr_elem->data;
                Action* curr_action = curr_object->enemy_action_sequence;

                if(!curr_object->enemy_performed_attack)
                {
                    if(!(state->gamestate == GAMESTATE__ENEMY_ATTACKING &&
                    state->action.enemy_action_sequence == curr_action) &&
                    !(state->gamestate == GAMESTATE__ENEMY_MOVING &&
                    state->action.enemy_action_sequence == curr_action))
                    {
                        draw_action(renderer, state, curr_action, textures, colors);
                    }
                }
            }
        }
    }

    // main_action_sequence

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2)
    {
        draw_action(renderer, state, state->action.hero_action_sequence, textures, colors);
    }

    // yellow outline, order number

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_SKILL)
    {
        Object* hover_object = get_object_on_tilemap_pos(state, state->mouse.tilemap_pos);

        if(hover_object != 0 &&
         !hover_object->is_dead &&
        hover_object->is_visible)
        {
            Vec2i selected_tilemap_pos = state->mouse.tilemap_pos;
            Vec2f selected_gamemap_pos = tilemap_pos_to_gamemap_pos(selected_tilemap_pos);
            Vec2f selected_world_cart_pos = gamemap_pos_to_world_pos(selected_gamemap_pos);
            Vec2f selected_world_iso_pos = cart_pos_to_iso_pos(selected_world_cart_pos);

            draw_texture_at_world_pos(
                renderer,
                get_texture_outline_from_object_type(hover_object->type, textures),
                colors->yellow,
                selected_world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );

            if(is_object_enemy(hover_object->type))
            {
                draw_texture_at_world_pos(
                    renderer,
                    get_texture_order_number(textures, hover_object->enemy_order_number),
                    colors->none,
                    selected_world_iso_pos,
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
    }

    // red outline

    if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
    state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE)
    {
        Object* enemy_object = state->gamemap.curr_object_enemy;

        if(enemy_object != 0 &&
         !enemy_object->is_dead &&
        enemy_object->is_visible)
        {
            Vec2i selected_tilemap_pos = enemy_object->tilemap_pos;
            Vec2f selected_gamemap_pos = tilemap_pos_to_gamemap_pos(selected_tilemap_pos);
            Vec2f selected_world_cart_pos = gamemap_pos_to_world_pos(selected_gamemap_pos);
            Vec2f selected_world_iso_pos = cart_pos_to_iso_pos(selected_world_cart_pos);

            draw_texture_at_world_pos(
                renderer,
                get_texture_outline_from_object_type(enemy_object->type, textures),
                colors->red,
                selected_world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );

            if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK)
            {
                draw_texture_at_world_pos(
                    renderer,
                    get_texture_order_number(textures, enemy_object->enemy_order_number),
                colors->none,
                    selected_world_iso_pos,
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
    }
}
