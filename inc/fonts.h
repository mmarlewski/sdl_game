#ifndef FONTS_H
#define FONTS_H

#include "../inc/common.h"
#include "../inc/vec.h"

typedef struct
{
    Font* bit_operator_30;
    Font* bit_operator_50;
    Font* stepalange_100;
    Font* stepalange_150;

} Fonts;

void load_fonts(Fonts* fonts);
void destroy_fonts(Fonts* fonts);

#endif
