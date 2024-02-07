#include "../inc/texture.h"

Texture* load_texture_from_filepath(Renderer* renderer, char* filepath)
{
    Texture* texture;

    texture = IMG_LoadTexture(renderer, filepath);

    return texture;
}

void destroy_texture(Texture* texture)
{
    SDL_DestroyTexture(texture);
}

void draw_texture_at_screen_pos(
    Renderer* renderer,
    Texture* texture,
    Vec3i color,
    float transparency,
    Vec2i screen_pos,
    float camera_zoom)
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

    SDL_SetTextureAlphaMod(texture,255 * transparency);
	SDL_RenderCopy(renderer, texture, 0, &dest);
    SDL_SetTextureAlphaMod(texture,255);
}

void draw_texture_at_world_pos(
    Renderer* renderer,
    Texture* texture,
    Vec3i color,
    float transparency,
    Vec2f world_pos,
    Vec2f camera_pos,
    float camera_zoom)
{
    Vec2i screen_pos = world_pos_to_screen_pos(world_pos, camera_pos, camera_zoom);
    draw_texture_at_screen_pos (renderer, texture, color, transparency, screen_pos, camera_zoom);
}

void draw_texture_at_gamemap_pos(
    Renderer* renderer,
    Texture* texture,
    Vec3i color,
    float transparency,
    Vec2f gamemap_pos,
    Vec2f camera_pos,
    float camera_zoom)
{
    Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
    Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);
    draw_texture_at_world_pos (renderer, texture, color, transparency, world_iso_pos, camera_pos, camera_zoom);
}

void draw_texture_at_tilemap_pos(
    Renderer* renderer,
    Texture* texture,
    Vec3i color,
    float transparency,
    Vec2i tilemap_pos,
    Vec2f camera_pos,
    float camera_zoom)
{
    Vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
    draw_texture_at_gamemap_pos (renderer, texture, color, transparency, gamemap_pos, camera_pos, camera_zoom);
}
