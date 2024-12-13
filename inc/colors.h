#ifndef COLORS_H
#define COLORS_H

#include "../inc/common.h"
#include "../inc/vec.h"

typedef struct
{
    Vec3i red;
    Vec3i orange;
    Vec3i yellow;
    Vec3i green;
    Vec3i teal;
    Vec3i blue;
    Vec3i purple;
    Vec3i pink;
    
    Vec3i blue_light;
    Vec3i brown_light;
    Vec3i green_light;
    Vec3i pink_light;
    Vec3i teal_light;

    Vec3i ally_background;
    Vec3i enemy_background;

    Vec3i game_start_background;
    Vec3i game_over_background;
    Vec3i game_won_background;

    Vec3i grey;
    Vec3i black;
    Vec3i white;

    Vec3i none;

} Colors;

void load_colors(Colors* colors);
void destroy_colors(Colors* colors);

#endif
