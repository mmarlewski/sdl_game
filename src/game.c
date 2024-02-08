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

    state.camera_zoom = 5.0f;

    Vec2f middle_world_iso_pos = cart_pos_to_iso_pos(
        gamemap_pos_to_world_pos(
            vec2f(TILEMAP_LENGTH * 0.5f,TILEMAP_LENGTH * 0.5f)
            )
        );
    middle_world_iso_pos.x += TILE_LENGTH * 0.5f;
    middle_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state.camera_world_pos = middle_world_iso_pos;

    // first room

    Room* first_room = new_empty_room("first room");
    add_room(
        &state,
        first_room
        );
    room_add_object_at(
        first_room,
        state.hero_object,
        vec2i(7,5)
        );
    room_add_object_at(
        first_room,
        state.minibot_object,
        vec2i(7,6)
        );
    set_curr_room(&state, first_room);

    for(int i = 0; i < TILEMAP_LENGTH; i++)
    {
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            room_change_floor_at(
                first_room,
                FLOOR_TYPE__ROCK,
                vec2i(i,j)
                );
        }
    }
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__ROCK_CRACK_PIT,
        vec2i(6,7)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__LAVA,
        vec2i(7,2)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__LAVA,
        vec2i(4,4)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__STONE_SPIKES_ON,
        vec2i(1,5)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__STONE_SPIKES_OFF,
        vec2i(7,6)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__ROCK_CRACK_LAVA,
        vec2i(2,2)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__ROCK_CRACK_WATER,
        vec2i(2,6)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__WATER,
        vec2i(3,1)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__ICE_CRACK_WATER,
        vec2i(4,1)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__ICE,
        vec2i(5,1)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__ICE,
        vec2i(6,1)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__METAL_PISTON_CELL,
        vec2i(3,5)
        );
    room_change_floor_at(
        first_room,
        FLOOR_TYPE__METAL_COVER_BOTTOM,
        vec2i(6,6)
        );

        room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(2,1)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(6,2)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__PIPE),
        vec2i(4,3)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(1,3)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__BALL),
        vec2i(2,7)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__COVER_ROCK),
        vec2i(6,6)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__BARREL),
        vec2i(6,4)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__VENDING_DYNAMITE),
        vec2i(6,3)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__ROCK_DAMAGED_ITEM),
        vec2i(6,5)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__STAIRS_ABOVE_ROCK),
        vec2i(7,4)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__STALACTITE),
        vec2i(7,2)
        );

        room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__GOAT),
        vec2i(2,3)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__SPIDER),
        vec2i(3,4)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__BULL),
        vec2i(5,4)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__FLY),
        vec2i(3,3)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__CHAMELEON),
        vec2i(3,7)
        );
    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__TURRET_LASER_DEPLOYED),
        vec2i(5,6)
        );

    Vec2i first_room_tilemap_pos = vec2i(0,0);
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            first_room,
            new_object(OBJECT_TYPE__WALL_ROCK),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos = vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__RIGHT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            first_room,
            new_object(OBJECT_TYPE__WALL_ROCK),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos = vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__DOWN, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            first_room,
            new_object(OBJECT_TYPE__WALL_ROCK),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos = vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__LEFT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-2; i++)
    {
        room_add_object_at(
            first_room,
            new_object(OBJECT_TYPE__WALL_ROCK),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos = vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__UP, 1);
    }

    room_add_object_at(
        first_room,
        new_object(OBJECT_TYPE__EXIT_ROCK_BLOCKED_RIGHT),
        first_room_tilemap_pos
        );

    // second room

    Room* second_room = new_empty_room("second room");
    add_room(
        &state,
        second_room
        );

    for(int i = 0; i < TILEMAP_LENGTH; i++)
    {
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            room_change_floor_at(
                second_room,
                FLOOR_TYPE__STONE,
                vec2i(i,j)
                );
        }
    }
    room_change_floor_at(
        second_room,
        FLOOR_TYPE__ROCK_STAIRS_BELOW,
        vec2i(7,4)
        );

    room_add_object_at(
        second_room,
        new_object(OBJECT_TYPE__STATION_STRIDER_LEG),
        vec2i(3,2)
        );
    room_add_object_at(
        second_room,
        new_object(OBJECT_TYPE__STATION_WINGS_TORSO),
        vec2i(3,3)
        );
    room_add_object_at(
        second_room,
        new_object(OBJECT_TYPE__BULL),
        vec2i(3,4)
        );
    room_add_object_at(
        second_room,
        new_object(OBJECT_TYPE__BULL),
        vec2i(3,5)
        );
    room_add_object_at(
        second_room,
        new_object(OBJECT_TYPE__BULL),
        vec2i(3,6)
        );

    Vec2i second_room_tilemap_pos = vec2i(0,0);
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            second_room,
            new_object(OBJECT_TYPE__WALL_STONE),
            second_room_tilemap_pos
            );
        second_room_tilemap_pos = vec2i_move_in_dir4_by(second_room_tilemap_pos, DIR4__RIGHT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            second_room,
            new_object(OBJECT_TYPE__WALL_STONE),
            second_room_tilemap_pos
            );
        second_room_tilemap_pos = vec2i_move_in_dir4_by(second_room_tilemap_pos, DIR4__DOWN, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            second_room,
            new_object(OBJECT_TYPE__WALL_STONE),
            second_room_tilemap_pos
            );
        second_room_tilemap_pos = vec2i_move_in_dir4_by(second_room_tilemap_pos, DIR4__LEFT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-2; i++)
    {
        room_add_object_at(
            second_room,
            new_object(OBJECT_TYPE__WALL_STONE),
            second_room_tilemap_pos
            );
        second_room_tilemap_pos = vec2i_move_in_dir4_by(second_room_tilemap_pos, DIR4__UP, 1);
    }
    room_add_object_at(
        second_room,
        new_object(OBJECT_TYPE__EXIT_STONE_UNPOWERED_RIGHT),
        second_room_tilemap_pos
        );

    // passages

    add_passage(
        &state,
        new_passage(
            "first room",
            "second room",
            vec2i(7,4),
            vec2i(7,3)
            )
        );
    add_passage(
        &state,
        new_passage(
            "first room",
            "second room",
            vec2i(0,1),
            vec2i(1,1)
            )
        );
    add_passage(
        &state,
        new_passage(
            "second room",
            "first room",
            vec2i(7,4),
            vec2i(7,5)
            )
        );
    add_passage(
        &state,
        new_passage(
            "second room",
            "first room",
            vec2i(0,1),
            vec2i(1,1)
            )
        );

    //

    determine_enemy_list(&state);
    determine_enemy_order(&state);

    for(ListElem* curr_elem = state.enemy_list->head; curr_elem != 0; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;

        if(curr_enemy != 0)
        {
            curr_enemy->attack_dir4 = rand() % 4 + 1;
            remove_all_actions_from_action_sequence(curr_enemy->action_sequence);
            object_enemy_prepare_attack(&state, curr_enemy);
            curr_enemy->performed_attack = 0;
        }
    }

    state.curr_ally = new_ally(state.hero_object);

    state.hero_item_number[ITEM__CELL] = 5;
    state.hero_item_number[ITEM__DYNAMITE] = 5;
    state.hero_item_number[ITEM__GEMSTONE] = 5;

    hero_add_augmentation(&state, AUGMENTATION__HOOK_HAND);
    hero_add_augmentation(&state, AUGMENTATION__CHAIN_HAND);
    hero_add_augmentation(&state, AUGMENTATION__SPRING_LEG);
    hero_add_augmentation(&state, AUGMENTATION__TRACK_LEG);
    hero_add_augmentation(&state, AUGMENTATION__MANIPULATION_HEAD);

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
