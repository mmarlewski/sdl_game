#include "../inc/game.h"

void init_sdl (Window** window, Renderer** renderer)
{
    // sdl

    int sdl_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER;

    if (SDL_Init(sdl_flags) < 0)
    {
        printf("can't init sdl: %s \n", SDL_GetError());
        exit(1);
    }

    // window

    int window_flags = 0;

    *window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

    if (!*window)
    {
        printf("can't create window: %s \n",SDL_GetError());
        exit(1);
    }

    // renderer

    int renderer_flags = SDL_RENDERER_ACCELERATED;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	*renderer = SDL_CreateRenderer(*window, -1, renderer_flags);

    if (!*renderer)
    {
        printf("can't create renderer: %s \n",SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    // audio

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048);
}

void destroy_sdl (Window* window, Renderer* renderer)
{
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void render (Renderer* renderer, State* state, Input* input, Textures* textures)
{
    SDL_SetRenderDrawColor (renderer, state->background_color.x,state->background_color.y,state->background_color.z, 255);
	SDL_RenderClear (renderer);

    draw_gamemap(renderer, state, textures);

    SDL_RenderPresent (renderer);
}

void draw_line (Renderer* renderer, vec2f start, vec2f end)
{
    SDL_RenderDrawLineF (renderer, start.x, start.y, end.x, end.y);
}

void draw_rectangle (Renderer* renderer, vec2f start, vec2f dims)
{
    SDL_FRect rect = {start.x,start.y,dims.x,dims.y};
    SDL_RenderDrawRectF (renderer, &rect);
}

void draw_gamemap(Renderer* renderer, State* state, Textures* textures)
{
    // floors, highlights

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            vec2i tilemap_pos = make_vec2i(j,i);
            vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

            Tile* tile = state->gamemap.tilemap[i][j];
            Texture* tile_floor_texture = get_texture_from_floor_type(tile->floor, textures);

            // tile

            draw_texture_at_world_pos(
                renderer,
                tile_floor_texture,
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
                        textures->highlight.green,
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
                        textures->highlight.teal,
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
                        textures->highlight.yellow,
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
            vec2i tilemap_pos = make_vec2i(j,i);
            vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

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
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom);
                }
            }

            // sprites

            for(ListElem* curr_elem = state->gamemap.sprite_list->head; curr_elem != 0; curr_elem = curr_elem->next)
            {
                Sprite* curr_sprite = (Sprite*)curr_elem->data;
                vec2i curr_sprite_tilemap_pos = make_vec2i(
                    floor(curr_sprite->gamemap_pos.x + 0.4f),
                    floor(curr_sprite->gamemap_pos.y + 0.4f)
                    );

                if(curr_sprite_tilemap_pos.x == tilemap_pos.x && curr_sprite_tilemap_pos.y == tilemap_pos.y)
                {
                    draw_texture_at_world_pos(
                        renderer,
                        curr_sprite->texture,
                        cart_pos_to_iso_pos(gamemap_pos_to_world_pos(curr_sprite->gamemap_pos)),
                        state->camera.world_pos,
                        state->camera.zoom);
                }
            }
        }
    }

    // enemy_action_sequence_list

    if(state->gamestate != GAMESTATE__NONE)
    {
        for(ListElem* curr_elem = state->action.enemy_action_sequence_list->head; curr_elem != 0; curr_elem = curr_elem->next)
        {
            Action* curr_action = (Action*)curr_elem->data;

            if(!(state->gamestate == GAMESTATE__ENEMY_ATTACKING &&
            state->action.enemy_action_sequence == curr_action) &&
            !(state->gamestate == GAMESTATE__ENEMY_MOVING &&
            state->action.enemy_action_sequence == curr_action))
            {
                draw_action(renderer, state, curr_action, textures);
            }
        }
    }

    // main_action_sequence

    if(state->gamestate == GAMESTATE__HERO_CHOOSING_TARGET_2)
    {
        draw_action(renderer, state, state->action.hero_action_sequence, textures);
    }
}

void draw_action(Renderer* renderer, State* state, Action* action, Textures* textures)
{
    vec2i tilemap_pos = action->tilemap_pos;
    vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
    vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
    vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            for(ListElem* curr_elem = action->sequence.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*)curr_elem->data;
                draw_action(renderer, state, curr_action, textures);
            }
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*)curr_elem->data;
                draw_action(renderer, state, curr_action, textures);
            }
        }
        break;
        case ACTION_TYPE__MOVE_GROUND:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_move_ground(textures, action->move_ground.dir4),
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__MOVE_AIR:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_move_air(textures, action->move_air.dir4),
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__CRASH_GROUND:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_crash_ground(textures, action->crash_ground.dir4),
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__CRASH_AIR:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_crash_air(textures, action->crash_air.dir4),
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__FALL:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->fall.fall,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->death.death,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->blow_up.blow_up,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__THROW:
        {
            vec2i target_tilemap_pos = make_vec2i_move_in_dir4_by(action->tilemap_pos, action->throw.dir4, action->throw.distance);
            vec2f target_gamemap_pos = tilemap_pos_to_gamemap_pos(target_tilemap_pos);
            vec2f target_world_cart_pos = gamemap_pos_to_world_pos(target_gamemap_pos);
            vec2f target_world_iso_pos = cart_pos_to_iso_pos(target_world_cart_pos);

            draw_texture_at_world_pos(
                renderer,
                get_texture_throw(textures, action->throw.dir4),
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );

            draw_texture_at_world_pos(
                renderer,
                textures->drop.drop,
                target_world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__DROP:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->drop.drop,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        default:
        break;
    }

}

int main (int argc, char* argv[])
{
    Window* window;
    Renderer* renderer;
    Input input;
    State state;

    Textures textures;
    Sounds sounds;
    Musics musics;

    int prev_time = 0;
    int curr_time = 0;
    float delta_time = 0.0f;

    init_sdl (&window, &renderer);
    init_input (&input);

    load_textures (renderer, &textures);
    load_sounds (&sounds);
    load_musics (&musics);

    init_state (&state, &textures, &sounds, &musics);

    state.gamestate = GAMESTATE__HERO_CHOOSING_SKILL;

    state.camera.zoom = 5.0f;

    vec2f middle_world_iso_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(make_vec2f(TILEMAP_WIDTH * 0.5f,TILEMAP_HEIGHT * 0.5f)));
    vec2f hero_world_iso_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(tilemap_pos_to_gamemap_pos(state.gamemap.object_hero->tilemap_pos)));
    hero_world_iso_pos.x += TILE_LENGTH * 0.5f;
    hero_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state.camera.world_pos = hero_world_iso_pos;

    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__LAVA, make_vec2i(5,5));
    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__METAL_SPIKES, make_vec2i(8,7));
    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__METAL_LAVA_CRACK, make_vec2i(8,3));
    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__WATER, make_vec2i(4,2));
    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__ICE_WATER_CRACK, make_vec2i(5,2));
    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__ICE, make_vec2i(6,2));
    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__ICE, make_vec2i(7,2));

    Object* object_pillar_1 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_1->tilemap_pos = make_vec2i(3,2);
    add_object_to_gamemap_objects(&state, object_pillar_1);

    Object* object_pillar_2 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_2->tilemap_pos = make_vec2i(3,3);
    add_object_to_gamemap_objects(&state, object_pillar_2);

    Object* object_pillar_3 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_3->tilemap_pos = make_vec2i(3,4);
    add_object_to_gamemap_objects(&state, object_pillar_3);

    Object* object_pillar_4 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_4->tilemap_pos = make_vec2i(3,5);
    add_object_to_gamemap_objects(&state, object_pillar_4);

    Object* object_pillar_5 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_5->tilemap_pos = make_vec2i(3,6);
    add_object_to_gamemap_objects(&state, object_pillar_5);

    Object* object_pillar_6 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_6->tilemap_pos = make_vec2i(6,7);
    add_object_to_gamemap_objects(&state, object_pillar_6);

    Object* object_pillar_7 = new_object(OBJECT_TYPE__PILLAR_SPIKES);
    object_pillar_7->tilemap_pos = make_vec2i(9,7);
    add_object_to_gamemap_objects(&state, object_pillar_7);

    Object* object_spring_1 = new_object(OBJECT_TYPE__SPRING);
    object_spring_1->tilemap_pos = make_vec2i(8,2);
    add_object_to_gamemap_objects(&state, object_spring_1);

    Object* object_spring_2 = new_object(OBJECT_TYPE__SPRING);
    object_spring_2->tilemap_pos = make_vec2i(9,2);
    add_object_to_gamemap_objects(&state, object_spring_2);

    Object* object_barrel_1 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_1->tilemap_pos = make_vec2i(7,5);
    add_object_to_gamemap_objects(&state, object_barrel_1);

    Object* object_barrel_2 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_2->tilemap_pos = make_vec2i(8,5);
    add_object_to_gamemap_objects(&state, object_barrel_2);

    Object* object_goat = new_object(OBJECT_TYPE__GOAT);
    object_goat->tilemap_pos = make_vec2i(2,2);
    add_object_to_gamemap_objects(&state, object_goat);

    Object* object_spider = new_object(OBJECT_TYPE__SPIDER);
    object_spider->tilemap_pos = make_vec2i(2,3);
    add_object_to_gamemap_objects(&state, object_spider);

    Object* object_bull = new_object(OBJECT_TYPE__BULL);
    object_bull->tilemap_pos = make_vec2i(2,4);
    add_object_to_gamemap_objects(&state, object_bull);

    Object* object_fly = new_object(OBJECT_TYPE__FLY);
    object_fly->tilemap_pos = make_vec2i(2,5);
    add_object_to_gamemap_objects(&state, object_fly);

    Object* object_chameleon = new_object(OBJECT_TYPE__CHAMELEON);
    object_chameleon->tilemap_pos = make_vec2i(2,6);
    add_object_to_gamemap_objects(&state, object_chameleon);

    int n = 8;
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = make_vec2i(10-i,10);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = make_vec2i(10-n,10+i);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = make_vec2i(10-n+i,10+n);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = make_vec2i(10,10+n-i);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    Object* object_barrel_3 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_3->tilemap_pos = make_vec2i(10-(n/2),10-1);
    add_object_to_gamemap_objects(&state, object_barrel_3);
    Object* object_barrel_4 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_4->tilemap_pos = make_vec2i(10-(n/2),10-2);
    add_object_to_gamemap_objects(&state, object_barrel_4);

    while (state.is_game_running)
    {
        prev_time = curr_time;
        curr_time = SDL_GetPerformanceCounter ();
        delta_time = (float)(curr_time - prev_time) / SDL_GetPerformanceFrequency ();
        if (delta_time < FPS_CAP_IN_MILIS)
        {
            SDL_Delay (FPS_CAP_IN_MILIS - delta_time);
            // printf ("delta time: %f s \n", delta_time);
        }

        // game loop

        update_input (&input);
        update_state (&input, &state, delta_time, &textures, &sounds, &musics);
        render (renderer, &state, &input, &textures);
    }

    destroy_textures(&textures);
    destroy_sounds(&sounds);
    destroy_musics(&musics);

    destroy_sdl (window, renderer);

    return 0;
}
