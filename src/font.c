#include "../inc/texture.h"
#include "../inc/font.h"

Font* load_font_from_filepath_of_size(char* filepath, int size)
{
    Font* font = TTF_OpenFont(filepath, size);

    return font;
}

void destroy_font(Font* font)
{
    TTF_CloseFont(font);
}

void draw_font_at_screen_pos(char* text, Renderer* renderer, Font* font, Vec3i color, float transparency, Vec2i screen_pos, int scale)
{
    SDL_Color sdl_color = {255,255,255};

    Surface* surface = TTF_RenderText_Solid(
        font,
        text,
        sdl_color
    );

    Texture* texture = SDL_CreateTextureFromSurface(
        renderer,
        surface
    );

    SDL_FreeSurface(surface);

    draw_texture_at_screen_pos(
        renderer,
        texture,
        color,
        transparency,
        screen_pos,
        scale
    );
}

