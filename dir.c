#include "dir.h"

vec2i move_vec2i_in_dir4_by(vec2i pos, int dir4, int by)
{
    switch(dir4)
    {
        case DIR4__UP: pos.y -= by; break;
        case DIR4__RIGHT: pos.x += by; break;
        case DIR4__DOWN: pos.y += by; break;
        case DIR4__LEFT: pos.x -= by; break;
        default: break;
    }

    return pos;
}

vec2f move_vec2f_in_dir4_by(vec2f pos, int dir4, float by)
{
    switch(dir4)
    {
        case DIR4__UP: pos.y -= by; break;
        case DIR4__RIGHT: pos.x += by; break;
        case DIR4__DOWN: pos.y += by; break;
        case DIR4__LEFT: pos.x -= by; break;
        default: break;
    }

    return pos;
}