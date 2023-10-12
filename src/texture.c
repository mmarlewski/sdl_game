#include "../inc/texture.h"

Texture* load_texture_from_filepath (Renderer* renderer, char* filepath)
{
    Texture* texture;

    texture = IMG_LoadTexture(renderer, filepath);

    return texture;
}

void destroy_texture (Texture* texture)
{
    SDL_DestroyTexture(texture);
}

void draw_texture_at_screen_pos (Renderer* renderer, Texture* texture, vec2i screen_pos, float camera_zoom)
{
    if(!texture) return;

    SDL_Rect dest;
    dest.x = screen_pos.x;
    dest.y = screen_pos.y;
	SDL_QueryTexture(texture, 0, 0, &dest.w, &dest.h);
    dest.w *= camera_zoom;
    dest.h *= camera_zoom;

	SDL_RenderCopy(renderer, texture, 0, &dest);
}

void draw_texture_at_world_pos (Renderer* renderer, Texture* texture, vec2f world_pos, vec2f camera_pos, float camera_zoom)
{
    if(!texture) return;

    vec2i screen_pos;
    screen_pos = world_pos_to_screen_pos(world_pos, camera_pos, camera_zoom);

    SDL_Rect screen_rect;
    screen_rect.x = screen_pos.x;
    screen_rect.y = screen_pos.y;
	SDL_QueryTexture(texture, 0, 0, &screen_rect.w, &screen_rect.h);
    screen_rect.w *= camera_zoom;
    screen_rect.h *= camera_zoom;

	SDL_RenderCopy(renderer, texture, 0, &screen_rect);
}