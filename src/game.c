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

    Vec2f middle_world_iso_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(vec2f(TILEMAP_LENGTH * 0.5f,TILEMAP_LENGTH * 0.5f)));
    Vec2f hero_world_iso_pos = cart_pos_to_iso_pos(gamemap_pos_to_world_pos(tilemap_pos_to_gamemap_pos(state.gamemap.object_hero->tilemap_pos)));
    hero_world_iso_pos.x += TILE_LENGTH * 0.5f;
    hero_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state.camera.world_pos = hero_world_iso_pos;

    change_floor_in_tilemap_pos(&state,
     FLOOR_TYPE__METAL_HATCH_OPEN, vec2i(6,7));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__LAVA, vec2i(7,2));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__LAVA, vec2i(4,4));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__STONE_SPIKES_ON, vec2i(1,5));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__STONE_SPIKES_OFF, vec2i(7,6));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ROCK_CRACK_LAVA, vec2i(2,2));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ROCK_CRACK_LAVA, vec2i(2,6));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__WATER, vec2i(3,1));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ICE_CRACK_WATER, vec2i(4,1));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ICE, vec2i(5,1));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__ICE, vec2i(6,1));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__METAL_PISTON, vec2i(3,5));
    change_floor_in_tilemap_pos(&state,
    FLOOR_TYPE__METAL_COVER_BOTTOM, vec2i(6,6));

    Object* object_pillar_1 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_1->tilemap_pos = vec2i(2,1);
    add_object_to_gamemap_objects(&state, object_pillar_1);

    Object* object_pillar_2 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_2->tilemap_pos = vec2i(6,2);
    add_object_to_gamemap_objects(&state, object_pillar_2);

    Object* object_pillar_3 = new_object(OBJECT_TYPE__PIPE);
    object_pillar_3->tilemap_pos = vec2i(4,3);
    add_object_to_gamemap_objects(&state, object_pillar_3);

    Object* object_pillar_4 = new_object(OBJECT_TYPE__PILLAR);
    object_pillar_4->tilemap_pos = vec2i(1,3);
    add_object_to_gamemap_objects(&state, object_pillar_4);

    Object* object_pillar_5 = new_object(OBJECT_TYPE__BALL);
    object_pillar_5->tilemap_pos = vec2i(2,7);
    add_object_to_gamemap_objects(&state, object_pillar_5);

    Object* object_cover = new_object(OBJECT_TYPE__COVER_ROCK);
    object_cover->tilemap_pos = vec2i(6,6);
    add_object_to_gamemap_objects(&state, object_cover);

    Object* object_barrel_1 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_1->tilemap_pos = vec2i(6,4);
    add_object_to_gamemap_objects(&state, object_barrel_1);

    Object* object_barrel_2 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_2->tilemap_pos = vec2i(6,3);
    add_object_to_gamemap_objects(&state, object_barrel_2);

    Object* object_barrel_3 = new_object(OBJECT_TYPE__BARREL);
    object_barrel_3->tilemap_pos = vec2i(6,5);
    add_object_to_gamemap_objects(&state, object_barrel_3);

    Object* object_other = new_object(OBJECT_TYPE__VENDING_DYNAMITE);
    object_other->tilemap_pos = vec2i(7,4);
    add_object_to_gamemap_objects(&state, object_other);

    Object* object_stalactite = new_object(OBJECT_TYPE__STALACTITE);
    object_stalactite->tilemap_pos = vec2i(7,2);
    add_object_to_gamemap_objects(&state, object_stalactite);

    Object* object_goat = new_object(OBJECT_TYPE__GOAT);
    object_goat->is_enemy = 1;
    object_goat->tilemap_pos = vec2i(2,3);
    add_object_to_gamemap_objects(&state, object_goat);

    Object* object_spider = new_object(OBJECT_TYPE__SPIDER);
    object_spider->is_enemy = 1;
    object_spider->tilemap_pos = vec2i(3,4);
    add_object_to_gamemap_objects(&state, object_spider);

    Object* object_bull = new_object(OBJECT_TYPE__BULL);
    object_bull->is_enemy = 1;
    object_bull->tilemap_pos = vec2i(5,4);
    add_object_to_gamemap_objects(&state, object_bull);

    Object* object_fly = new_object(OBJECT_TYPE__FLY);
    object_fly->is_enemy = 1;
    object_fly->tilemap_pos = vec2i(3,3);
    add_object_to_gamemap_objects(&state, object_fly);

    Object* object_chameleon = new_object(OBJECT_TYPE__CHAMELEON);
    object_chameleon->is_enemy = 1;
    object_chameleon->tilemap_pos = vec2i(3,7);
    add_object_to_gamemap_objects(&state, object_chameleon);

    Object* object_turret = new_object(OBJECT_TYPE__TURRET_LASER_DEPLOYED);
    object_turret->is_enemy = 1;
    object_turret->tilemap_pos = vec2i(5,6);
    add_object_to_gamemap_objects(&state, object_turret);

    Vec2i tilemap_pos = vec2i(0,0);
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        Object* object_wall = new_object(OBJECT_TYPE__WALL_ROCK);
        object_wall->tilemap_pos = tilemap_pos;
        add_object_to_gamemap_objects(&state, object_wall);
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__RIGHT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        Object* object_wall = new_object(OBJECT_TYPE__WALL_METAL);
        object_wall->tilemap_pos = tilemap_pos;
        add_object_to_gamemap_objects(&state, object_wall);
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__DOWN, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        Object* object_wall = new_object(OBJECT_TYPE__WALL_ROCK);
        object_wall->tilemap_pos = tilemap_pos;
        add_object_to_gamemap_objects(&state, object_wall);
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__LEFT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-2; i++)
    {
        Object* object_wall = new_object(OBJECT_TYPE__WALL_STONE);
        object_wall->tilemap_pos = tilemap_pos;
        add_object_to_gamemap_objects(&state, object_wall);
        tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, DIR4__UP, 1);
    }

    Object* object_door = new_object(OBJECT_TYPE__EXIT_METAL_BLOCKED_RIGHT);
    object_door->tilemap_pos = tilemap_pos;
    add_object_to_gamemap_objects(&state, object_door);

    for(ListElem* curr_elem = state.gamemap.object_enemy_list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Object* curr_object = (Object*)curr_elem->data;

        if(curr_object->is_enemy)
        {
            curr_object->enemy.attack_dir4 = rand() % 4 + 1;
            remove_all_actions_from_action_sequence(curr_object->enemy.action_sequence);
            object_enemy_prepare_attack(&state, curr_object);
            curr_object->enemy.performed_attack = 0;
        }
    }

    determine_enemy_order(&state);

    state.gamemap.item_number[ITEM__CELL] = 5;
    state.gamemap.item_number[ITEM__DYNAMITE] = 5;
    state.gamemap.item_number[ITEM__GEMSTONE] = 5;

    while (state.is_game_running)
    {
        prev_time = curr_time;
        curr_time = SDL_GetPerformanceCounter ();
        delta_time = (float)(curr_time - prev_time) / SDL_GetPerformanceFrequency ();
        if (delta_time < FPS_CAP_IN_MILISECONDS)
        {
            SDL_Delay (FPS_CAP_IN_MILISECONDS - delta_time);
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
