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

    *window = SDL_CreateWindow(
        "sdl_game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        window_flags
        );

    if (!*window)
    {
        printf("can't create window: %s \n",SDL_GetError());
        exit(1);
    }

    // renderer

    int renderer_flags = SDL_RENDERER_ACCELERATED;

    SDL_SetHint(
        SDL_HINT_RENDER_SCALE_QUALITY,
        "linear"
        );

	*renderer = SDL_CreateRenderer(
        *window,
        -1,
        renderer_flags
        );

    if (!*renderer)
    {
        printf("can't create renderer: %s \n",SDL_GetError());
        exit(1);
    }

    SDL_SetHint(
        SDL_HINT_RENDER_SCALE_QUALITY,
        "0"
        );

    // audio

    Mix_OpenAudio(
        MIX_DEFAULT_FREQUENCY,
        MIX_DEFAULT_FORMAT,
        2,
        2048
        );
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
