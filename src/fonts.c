#include "../inc/font.h"
#include "../inc/fonts.h"

void load_fonts (Fonts* fonts)
{
    fonts->font_30 = load_font_from_filepath_of_size( "./res/font/font_1.ttf", 30);
    fonts->font_50 = load_font_from_filepath_of_size( "./res/font/font_1.ttf", 50);
}

void destroy_fonts (Fonts* fonts)
{
    //
}
