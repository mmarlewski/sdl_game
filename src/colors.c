#include "../inc/colors.h"

void load_colors (Colors* colors)
{
    colors->red =       vec3i(255, 0, 0);
    colors-> orange =   vec3i(255, 128, 0);
    colors-> yellow =   vec3i(255, 255, 0);
    colors-> green =    vec3i(0, 255, 0);
    colors-> teal =     vec3i(0, 128, 128);
    colors-> blue =     vec3i(0, 0, 255);
    colors-> purple =   vec3i(128, 0, 128);
    colors-> pink =     vec3i(255, 128, 255);

    colors-> grey =     vec3i(128, 128, 128);
    colors-> black =    vec3i(0, 0, 0);
    colors-> white =    vec3i(255, 255, 255);

    colors-> hero_background =  vec3i(100, 160, 220);
    colors-> enemy_background = vec3i(200, 50, 50);

    colors-> none =     vec3i(-1, -1, -1);
}

void destroy_colors (Colors* colors)
{
    //
}
