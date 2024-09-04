#include "../inc/font.h"
#include "../inc/fonts.h"

void load_fonts(Fonts* fonts)
{
    fonts->bit_operator_20 = load_font_from_filepath_of_size("./res/font/bit_operator.ttf", 20);
    fonts->bit_operator_30 = load_font_from_filepath_of_size("./res/font/bit_operator.ttf", 30);
    fonts->bit_operator_50 = load_font_from_filepath_of_size("./res/font/bit_operator.ttf", 50);
    fonts->stepalange_100 = load_font_from_filepath_of_size("./res/font/stepalange.ttf", 100);
    fonts->stepalange_150 = load_font_from_filepath_of_size("./res/font/stepalange.ttf", 150);
}

void destroy_fonts(Fonts* fonts)
{
    //
}
