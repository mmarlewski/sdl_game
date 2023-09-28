#include "game.h"

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
    SDL_SetRenderDrawColor (renderer, 90, 140, 170, 255);
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
    State_Gamemap* gamemap = &state->gamemap;

    // floors, highlights and dangers

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            vec2i tilemap_pos;
            vec2f gamemap_pos;
            vec2f world_cart_pos;
            vec2f world_iso_pos;

            tilemap_pos = make_vec2i(j,i);
            gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

            Tile* tile = gamemap->tilemap[i][j];
            Texture* tile_floor_texture = get_texture_from_floor_type(tile->floor, textures);

            draw_texture_at_world_pos(
                renderer,
                tile_floor_texture,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom);
            
            if(gamemap->highlight_tilemap_pos.x == j && gamemap->highlight_tilemap_pos.y == i)
            {
                draw_texture_at_world_pos(
                    renderer,
                    textures->highlight.yellow,
                    world_iso_pos,
                    state->camera.world_pos,
                    state->camera.zoom);
            }
            
            for(vec2i* curr_pos = gamemap->danger_tilemap_pos_head; curr_pos != 0; curr_pos = curr_pos->next)
            {
                if(curr_pos->x == j && curr_pos->y == i)
                {
                    draw_texture_at_world_pos(
                        renderer,
                        textures->danger.frame_1,
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom);
                }
            }
        }
    }

    // objects and sprites

    for(int i = 0 ; i < TILEMAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < TILEMAP_WIDTH ; j++)
        {
            vec2i tilemap_pos;
            vec2f gamemap_pos;
            vec2f world_cart_pos;
            vec2f world_iso_pos;

            tilemap_pos = make_vec2i(j,i);
            gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
            world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
            world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);
            
            for(Object* curr_object = gamemap->object_head; curr_object != 0; curr_object = curr_object->next)
            {
                if(curr_object->is_visible && curr_object->tilemap_pos.x == j && curr_object->tilemap_pos.y == i)
                {
                    draw_texture_at_world_pos(
                        renderer,
                        get_texture_from_object_type(curr_object->type, textures),
                        world_iso_pos,
                        state->camera.world_pos,
                        state->camera.zoom);
                }
            }

            for(Sprite* curr_sprite = gamemap->sprite_head; curr_sprite != 0; curr_sprite = curr_sprite->next)
            {
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

    state.camera.zoom = 5.0f;

    vec2f middle_gamemap_pos = make_vec2f(TILEMAP_WIDTH * 0.5f,TILEMAP_HEIGHT * 0.5f);
    state.camera.world_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(middle_gamemap_pos));

    change_floor_in_tilemap_pos(&state, FLOOR_TYPE__LAVA, make_vec2i(7,7));

    Object* object_pillar_1 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_1->tilemap_pos = make_vec2i(5,5);
    Object* object_pillar_2 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_2->tilemap_pos = make_vec2i(8,8);
    Object* object_goat = new_object(OBJECT_TYPE__GOAT);
    object_goat->tilemap_pos = make_vec2i(8,5);
    Object* object_spider = new_object(OBJECT_TYPE__SPIDER);
    object_spider->tilemap_pos = make_vec2i(5,8);
    add_object_to_gamemap_objects(&state, object_pillar_1);
    add_object_to_gamemap_objects(&state, object_goat);
    add_object_to_gamemap_objects(&state, object_spider);
    add_object_to_gamemap_objects(&state, object_pillar_2);

    vec2i* pos_1 = new_vec2i(3,3);
    vec2i* pos_2 = new_vec2i(3,4);
    vec2i* pos_3 = new_vec2i(4,4);
    vec2i* pos_4 = new_vec2i(4,5);
    vec2i* pos_5 = new_vec2i(5,5);
    add_pos_to_gamemap_danger_pos(&state, pos_1);
    add_pos_to_gamemap_danger_pos(&state, pos_2);
    add_pos_to_gamemap_danger_pos(&state, pos_3);
    add_pos_to_gamemap_danger_pos(&state, pos_4);
    remove_all_pos_from_gamemap_danger_pos(&state);
    add_pos_to_gamemap_danger_pos(&state, pos_5);

    state.gamemap.object_acting = object_goat;

    while (state.is_game_running)
    {
        // printf

        // printf("is: %i \n", state.is_executing_actions);

        // delta time

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