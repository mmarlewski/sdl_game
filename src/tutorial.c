#include "../inc/state.h"

void get_tutorial_line_and_update_tutorial(State* state, char** n, char** line_1, char** line_2, char** line_3)
{
    if(!(strcmp(state->curr_room->name, "7_2") == 0 || 
    strcmp(state->curr_room->name, "7_3") == 0 || 
    strcmp(state->curr_room->name, "6_3") == 0 || 
    strcmp(state->curr_room->name, "6_2") == 0 || 
    strcmp(state->curr_room->name, "6_1") == 0))
    {
        // after finishing tutorial, dont show it again
        state->was_tutorial_finished = TRUE;
        state->show_tutorial = FALSE;
    }

    if(state->tutorial__get_past_moles &&
    strcmp(state->curr_room->name, "6_1") == 0)
    {
        *n = "10";
        *line_1 = "You are on your own now, choose where do you want to go.";
        *line_2 = ">> To win the game, find and use the *THRONE* in royal chambers.";
        *line_3 = "";
    }
    else if(state->tutorial__save_cell &&
    strcmp(state->curr_room->name, "6_2") == 0)
    {
        state->tutorial__get_past_moles = TRUE;

        *n = "9";
        *line_1 = "Most enemies choose attack direction after move.";
        *line_2 = "Some, can change direction in response to hero's actions.";
        *line_3 = "Enemies of this kind will be marked with an exclamation point.";
    }
    else if(state->tutorial__unlock_rock_exit &&
    strcmp(state->curr_room->name, "6_3") == 0)
    {
        state->tutorial__save_cell = TRUE;

        *n = "8";
        *line_1 = "You need to put *CELL* to powere stone objects.";
        *line_2 = ">> Save *CRATE* with *CELL* from bull's attack or ";
        *line_3 = "buy it from a *VENDING MACHINE* with *GEMSTONE*.";
    }
    else if(state->tutorial__get_dynamite &&
    (state->hero_item_number[ITEM__DYNAMITE] == 1 ||
    room_get_object_at(state->curr_room, vec2i(4,0))->type == OBJECT__EXIT_ROCK_DOWN))
    {
        state->tutorial__unlock_rock_exit = TRUE;

        *n = "7";
        *line_1 = ">> Throw *DYNAMITE* to open blocked *EXIT*.";
        *line_2 = "";
        *line_3 = "";
    }
    else if(state->tutorial__go_back_for_dynamite &&
    strcmp(state->curr_room->name, "7_2") == 0)
    {
        state->tutorial__get_dynamite = TRUE;

        *n = "6";
        *line_1 = ">> Use new skills to cross lava and pick up *DYNAMITE*.";
        *line_2 = "";
        *line_3 = "";
    }
    else if(state->tutorial__get_chain_aug &&
    hero_has_augmentation(state, AUGMENTATION__CHAIN_HAND))
    {
        state->tutorial__go_back_for_dynamite = TRUE;

        *n = "5";
        *line_1 = "With new augmentations, new skills are available.";
        *line_2 = ">> Go back to previous room to make use of them.";
        *line_3 = "";
    }
    else if(state->tutorial__get_goat_killed &&
    strcmp(state->curr_room->name, "7_3") == 0 &&
    state->enemy_list->size == 0)
    {
        state->tutorial__get_chain_aug = TRUE;

        *n = "4";
        *line_1 = ">> Use *STATION* to add augmentation to hero.";
        *line_2 = "(chain hand in place of right hand)";
        *line_3 = "";
    }
    else if(state->tutorial__use_exit &&
    strcmp(state->curr_room->name, "7_3") == 0)
    {
        state->tutorial__get_goat_killed = TRUE;

        *n = "3";
        *line_1 = "With enemies in room, your movement is limited.";
        *line_2 = "After your turn is finished, enemies will move and attack.";
        *line_3 = ">> Try to get the goat killed.";
    }
    else if(state->tutorial__go_to_exit &&
    vec2i_equals(state->hero_object->tilemap_pos, vec2i(8,5)))
    {
        state->tutorial__use_exit = TRUE;

        *n = "2";
        *line_1 = ">> Travel to another room with *USE* skill.";
        *line_2 = "Some *EXITS* will be blocked or inaccessible.";
        *line_3 = "This one is open.";
    }
    else
    {
        *n = "1";
        *line_1 = "For now, you can't get through lava tiles.";
        *line_2 = ">> Go to room's *EXIT* with *MOVE* skill.";
        *line_3 = "Select skills with mouse or keyboard.";
    }
}
