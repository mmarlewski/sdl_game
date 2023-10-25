#include "../inc/colors.h"

void load_colors (Colors* colors)
{
    colors->red =       make_vec3i(255, 0, 0);
    colors-> orange =   make_vec3i(255, 128, 0);
    colors-> yellow =   make_vec3i(255, 255, 0);
    colors-> green =    make_vec3i(0, 255, 0);
    colors-> teal =     make_vec3i(0, 128, 128);
    colors-> blue =     make_vec3i(0, 0, 255);
    colors-> purple =   make_vec3i(128, 0, 128);
    colors-> pink =     make_vec3i(255, 128, 255);

    colors-> grey =     make_vec3i(128, 128, 128);
    colors-> black =    make_vec3i(0, 0, 0);
    colors-> white =    make_vec3i(255, 255, 255);

    colors-> hero_background =  make_vec3i(100, 160, 220);
    colors-> enemy_background = make_vec3i(200, 50, 50);

    colors-> none =     make_vec3i(-1, -1, -1);
}

void destroy_colors (Colors* colors)
{
    //
}
