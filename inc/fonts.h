#ifndef FONTS_H
#define FONTS_H

#include "../inc/common.h"
#include "../inc/vec.h"

typedef struct
{
    Font* font_30;
    Font* font_50;

} Fonts;

void load_fonts (Fonts* fonts);
void destroy_fonts (Fonts* fonts);

#endif
