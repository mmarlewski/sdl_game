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

void draw_texture_at_screen_pos (Renderer* renderer, Texture* texture, vec3i color, vec2i screen_pos, float camera_zoom)
{
    if(!texture) return;

    SDL_Rect dest;
    dest.x = screen_pos.x;
    dest.y = screen_pos.y;
	SDL_QueryTexture(texture, 0, 0, &dest.w, &dest.h);
    dest.w *= camera_zoom;
    dest.h *= camera_zoom;

    if(color.x != -1 && color.y != -1 && color.z != -1)
    {
        SDL_SetTextureColorMod(texture, color.x, color.y, color.z);
    }

	SDL_RenderCopy(renderer, texture, 0, &dest);
}

void draw_texture_at_world_pos (Renderer* renderer, Texture* texture, vec3i color, vec2f world_pos, vec2f camera_pos, float camera_zoom)
{
    vec2i screen_pos = world_pos_to_screen_pos(world_pos, camera_pos, camera_zoom);
    draw_texture_at_screen_pos (renderer, texture, color, screen_pos, camera_zoom);
}

void draw_texture_at_gamemap_pos (Renderer* renderer, Texture* texture, vec3i color, vec2f gamemap_pos, vec2f camera_pos, float camera_zoom)
{
    vec2f world_pos = gamemap_pos_to_world_pos(gamemap_pos);
    draw_texture_at_world_pos (renderer, texture, color, world_pos, camera_pos, camera_zoom);
}
