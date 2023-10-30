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

void render (Renderer* renderer, State* state, Input* input, Textures* textures, Colors* colors)
{
    SDL_SetRenderDrawColor (renderer, state->background_color.x,state->background_color.y,state->background_color.z, 255);
	SDL_RenderClear (renderer);

    draw_gamemap(renderer, state, textures, colors);

    SDL_RenderPresent (renderer);
}

void draw_line (Renderer* renderer, Vec2f start, Vec2f end)
{
    SDL_RenderDrawLineF (renderer, start.x, start.y, end.x, end.y);
}

void draw_rectangle (Renderer* renderer, Vec2f start, Vec2f dims)
{
    SDL_FRect rect = {start.x,start.y,dims.x,dims.y};
    SDL_RenderDrawRectF (renderer, &rect);
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
    Colors colors;

    int prev_time = 0;
    int curr_time = 0;
    float delta_time = 0.0f;

    init_sdl (&window, &renderer);
    init_input (&input);

    load_textures (renderer, &textures);
    load_sounds (&sounds);
    load_musics (&musics);
    load_colors (&colors);

    init_state (&state, &textures, &sounds, &musics, &colors);

    state.gamestate = GAMESTATE__HERO_CHOOSING_SKILL;

    state.camera.zoom = 5.0f;

    Vec2f middle_world_iso_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(vec2f(TILEMAP_WIDTH * 0.5f,TILEMAP_HEIGHT * 0.5f)));
    Vec2f hero_world_iso_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(tilemap_pos_to_gamemap_pos(state.gamemap.object_hero->tilemap_pos)));
    hero_world_iso_pos.x += TILE_LENGTH * 0.5f;
    hero_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state.camera.world_pos = hero_world_iso_pos;

    change_floor_in_tilemap_pos(&state,
     FLOOR_TYPE__LAVA, vec2i(9,9));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__LAVA, vec2i(8,3));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__LAVA, vec2i(5,5));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__METAL_SPIKES, vec2i(2,6));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__METAL_NO_SPIKES, vec2i(8,7));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__METAL_LAVA_CRACK, vec2i(3,3));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__METAL_LAVA_CRACK, vec2i(3,7));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__WATER, vec2i(4,2));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ICE_WATER_CRACK, vec2i(5,2));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ICE, vec2i(6,2));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ICE, vec2i(7,2));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__HATCH_CLOSED, vec2i(4,6));

    Object* object_pillar_1 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_1->tilemap_pos = vec2i(3,2);
    add_object_to_gamemap_objects(&state, object_pillar_1);

    Object* object_pillar_2 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_2->tilemap_pos = vec2i(7,3);
    add_object_to_gamemap_objects(&state, object_pillar_2);

    Object* object_pillar_3 = new_object(OBJECT_TYPE__PILLAR_SPIKES);
    object_pillar_3->tilemap_pos = vec2i(5,4);
    add_object_to_gamemap_objects(&state, object_pillar_3);

    Object* object_pillar_4 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_4->tilemap_pos = vec2i(1,4);
    add_object_to_gamemap_objects(&state, object_pillar_4);

    Object* object_pillar_5 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_5->tilemap_pos = vec2i(3,8);
    add_object_to_gamemap_objects(&state, object_pillar_5);

    Object* object_pillar_6 = new_object(OBJECT_TYPE__WEIGHT);
    object_pillar_6->tilemap_pos = vec2i(6,7);
    add_object_to_gamemap_objects(&state, object_pillar_6);

    Object* object_pillar_7 = new_object(OBJECT_TYPE__PILLAR_SPIKES);
    object_pillar_7->tilemap_pos = vec2i(9,7);
    add_object_to_gamemap_objects(&state, object_pillar_7);

    Object* object_spring_1 = new_object(OBJECT_TYPE__SPRING);
    object_spring_1->tilemap_pos = vec2i(8,2);
    add_object_to_gamemap_objects(&state, object_spring_1);

    Object* object_spring_2 = new_object(OBJECT_TYPE__SPRING);
    object_spring_2->tilemap_pos = vec2i(9,2);
    add_object_to_gamemap_objects(&state, object_spring_2);

    Object* object_barrel_1 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_1->tilemap_pos = vec2i(7,5);
    add_object_to_gamemap_objects(&state, object_barrel_1);

    Object* object_barrel_2 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_2->tilemap_pos = vec2i(8,5);
    add_object_to_gamemap_objects(&state, object_barrel_2);

    Object* object_goat = new_object(OBJECT_TYPE__GOAT);
    object_goat->tilemap_pos = vec2i(1,2);
    add_object_to_gamemap_objects(&state, object_goat);

    Object* object_spider = new_object(OBJECT_TYPE__SPIDER);
    object_spider->tilemap_pos = vec2i(4,5);
    add_object_to_gamemap_objects(&state, object_spider);

    Object* object_bull = new_object(OBJECT_TYPE__BULL);
    object_bull->tilemap_pos = vec2i(6,5);
    add_object_to_gamemap_objects(&state, object_bull);

    Object* object_fly = new_object(OBJECT_TYPE__FLY);
    object_fly->tilemap_pos = vec2i(4,4);
    add_object_to_gamemap_objects(&state, object_fly);

    Object* object_chameleon = new_object(OBJECT_TYPE__CHAMELEON);
    object_chameleon->tilemap_pos = vec2i(4,8);
    add_object_to_gamemap_objects(&state, object_chameleon);

    int n = 8;
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = vec2i(10-i,10);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = vec2i(10-n,10+i);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = vec2i(10-n+i,10+n);
        add_object_to_gamemap_objects(&state, object_barrel);
    }
    for(int i = 0; i < n; i++)
    {
        Object* object_barrel = new_object(OBJECT_TYPE__BARREL);
        object_barrel->tilemap_pos = vec2i(10,10+n-i);
        add_object_to_gamemap_objects(&state, object_barrel);
    }

    for(ListElem* curr_elem = state.gamemap.object_enemy_list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Object* curr_object = (Object*)curr_elem->data;

        if(is_object_enemy(curr_object->type))
        {
            curr_object->enemy_attack_dir4 = rand() % 4 + 1;
            remove_all_actions_from_action_sequence(curr_object->enemy_action_sequence);
            object_enemy_add_actions_to_action_sequence_attack(&state, curr_object->enemy_action_sequence, curr_object);
            curr_object->enemy_performed_attack = 0;
        }
    }

    determine_enemy_order(&state);

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
        update_state (&input, &state, delta_time, &textures, &sounds, &musics, &colors);
        render (renderer, &state, &input, &textures, &colors);
    }

    destroy_textures(&textures);
    destroy_sounds(&sounds);
    destroy_musics(&musics);
    destroy_colors(&colors);

    destroy_sdl (window, renderer);

    return 0;
}
