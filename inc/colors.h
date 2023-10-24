#ifndef COLORS_H
#define COLORS_H

#include "../inc/common.h"
#include "../inc/vec.h"

typedef struct
{
    vec3i red;
    vec3i orange;
    vec3i yellow;
    vec3i green;
    vec3i teal;
    vec3i blue;
    vec3i purple;
    vec3i pink;
    vec3i grey;
    vec3i black;
    vec3i white;
    vec3i none;

} Colors;

void load_colors (Colors* colors);
void destroy_colors (Colors* colors);

#endif
