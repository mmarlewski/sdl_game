#include "../inc/math_utils.h"

Vec2f screen_pos_to_world_pos(Vec2i screen_pos, Vec2f camera_pos, float camera_zoom)
{
    Vec2f world_pos;

    world_pos.x = (screen_pos.x + camera_pos.x * camera_zoom - SCREEN_WIDTH * 0.5f) / camera_zoom;
    world_pos.y = (screen_pos.y + camera_pos.y * camera_zoom - SCREEN_HEIGHT * 0.5f) / camera_zoom;

    return world_pos;
}
Vec2i world_pos_to_screen_pos(Vec2f world_pos, Vec2f camera_pos, float camera_zoom)
{
    Vec2i screen_pos;

    screen_pos.x = SCREEN_WIDTH * 0.5f + world_pos.x * camera_zoom - camera_pos.x * camera_zoom;
    screen_pos.y = SCREEN_HEIGHT * 0.5f + world_pos.y * camera_zoom - camera_pos.y * camera_zoom;

    return screen_pos;
}

Vec2f cart_pos_to_iso_pos(Vec2f cart_pos)
{
    Vec2f iso_pos;

    iso_pos.x = cart_pos.x - cart_pos.y;
    iso_pos.y = cart_pos.x * 0.5f + cart_pos.y * 0.5f;

    return iso_pos;
}
Vec2f iso_pos_to_cart_pos(Vec2f iso_pos)
{
    Vec2f cart_pos;

    cart_pos.x = iso_pos.y + iso_pos.x * 0.5f;
    cart_pos.y = iso_pos.y - iso_pos.x * 0.5f;

    return cart_pos;
}

Vec2f world_pos_to_gamemap_pos(Vec2f world_pos)
{
    Vec2f gamemap_pos;

    gamemap_pos.x = world_pos.x / (TILE_LENGTH * 0.5f);
    gamemap_pos.y = world_pos.y / (TILE_LENGTH * 0.5f);

    return gamemap_pos;
}
Vec2f gamemap_pos_to_world_pos(Vec2f gamemap_pos)
{
    Vec2f world_pos;

    world_pos.x = gamemap_pos.x * (TILE_LENGTH * 0.5f);
    world_pos.y = gamemap_pos.y * (TILE_LENGTH * 0.5f);

    return world_pos;
}

Vec2i gamemap_pos_to_tilemap_pos(Vec2f gamemap_pos)
{
    Vec2i tilemap_pos;

    tilemap_pos = floor_vec2f_to_vec2i(gamemap_pos);
    tilemap_pos.x -= 1;
    tilemap_pos.y -= 1;

    return tilemap_pos;
}
Vec2f tilemap_pos_to_gamemap_pos(Vec2i tilemap_pos)
{
    Vec2f gamemap_pos;

    gamemap_pos = vec2i_to_vec2f(tilemap_pos);

    return gamemap_pos;
}
