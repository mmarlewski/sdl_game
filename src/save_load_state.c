#include "../inc/state.h"
#include <stdlib.h>

char room_background_texture_to_room_background_char(Texture* room_background_texture, Textures* textures)
{
    if(room_background_texture == textures->background_rock) return 'r';
    else if(room_background_texture == textures->background_stone) return 's';
    else if(room_background_texture == textures->background_metal) return 'm';
    else if(room_background_texture == textures->background_marble) return 'b';
    else if(room_background_texture == textures->background_obsidian) return 'o';
    else if(room_background_texture == textures->background_gold) return 'g';
    else return ' ';
}

Texture* room_background_char_to_room_background_texture(char room_background_char, Textures* textures)
{
    if(room_background_char == 'r') return textures->background_rock;
    if(room_background_char == 's') return textures->background_stone;
    if(room_background_char == 'm') return textures->background_metal;
    if(room_background_char == 'b') return textures->background_marble;
    if(room_background_char == 'o') return textures->background_obsidian;
    if(room_background_char == 'g') return textures->background_gold;
    else return textures->background_rock;
}

void save_state(State* state, Textures* textures)
{
    // write to file

    SDL_RWops* file = SDL_RWFromFile( "save.save", "w" );

    // passages (full info)

    List* passage_list = state->passage_list;
    int passage_list_size = passage_list->size;

    SDL_RWwrite(file, &passage_list_size, sizeof(int), 1);

    for(ListElem* passage_elem = passage_list->head; passage_elem != NULL; passage_elem = passage_elem->next)
    {
        Passage* passage = (Passage*)passage_elem->data;

        char* passage_from_room_name = passage->from_room_name;
        int passage_from_room_name_len = strlen(passage_from_room_name);
        char* passage_to_room_name = passage->to_room_name;
        int passage_to_room_name_len = strlen(passage_to_room_name);

        int passage_from_tilemap_pos_x = passage->from_tilemap_pos.x;
        int passage_from_tilemap_pos_y = passage->from_tilemap_pos.y;
        int passage_to_tilemap_pos_x = passage->to_tilemap_pos.x;
        int passage_to_tilemap_pos_y = passage->to_tilemap_pos.y;

        SDL_RWwrite(file, &passage_from_room_name_len, sizeof(int), 1);
        SDL_RWwrite(file, passage_from_room_name, sizeof(char) * passage_from_room_name_len, 1);
        SDL_RWwrite(file, &passage_to_room_name_len, sizeof(int), 1);
        SDL_RWwrite(file, passage_to_room_name, sizeof(char) * passage_to_room_name_len, 1);

        SDL_RWwrite(file, &passage_from_tilemap_pos_x, sizeof(int), 1);
        SDL_RWwrite(file, &passage_from_tilemap_pos_y, sizeof(int), 1);
        SDL_RWwrite(file, &passage_to_tilemap_pos_x, sizeof(int), 1);
        SDL_RWwrite(file, &passage_to_tilemap_pos_y, sizeof(int), 1);
    }

    // all rooms (full info)

    List* room_list = state->room_list;
    int room_list_size = room_list->size;

    SDL_RWwrite(file, &room_list_size, sizeof(int), 1);

    for(ListElem* room_elem = room_list->head; room_elem != NULL; room_elem = room_elem->next)
    {
        Room* room = (Room*)room_elem->data;

        char* room_name = room->name;
        int room_name_len = strlen(room_name);
        char room_backgrount_char = room_background_texture_to_room_background_char(room->background_texture, textures);
        int** floor_array = (int**)room->floor_array;
        List* room_object_list = room->object_list;
        int room_object_list_size = room_object_list->size;

        SDL_RWwrite(file, &room_name_len, sizeof(int), 1);
        SDL_RWwrite(file, room_name, sizeof(char) * room_name_len, 1);
        SDL_RWwrite(file, &room_backgrount_char, sizeof(char), 1);
        SDL_RWwrite(file, floor_array, sizeof(int) * TILEMAP_LENGTH * TILEMAP_LENGTH, 1);
        SDL_RWwrite(file, &room_object_list_size, sizeof(int), 1);

        for(ListElem* object_elem = room_object_list->head; object_elem != NULL; object_elem = object_elem->next)
        {
            Object* object = (Object*)object_elem->data;

            int object_is_to_be_removed = object->is_to_be_removed;
            int object_is_visible = object->is_visible;
            int object_type = object->type;
            int object_tilemap_pos_x = object->tilemap_pos.x;
            int object_tilemap_pos_y = object->tilemap_pos.y;
            int object_attack_dir4 = object->attack_dir4;
            int object_action_points = object->action_points;

            SDL_RWwrite(file, &object_is_to_be_removed, sizeof(int), 1);
            SDL_RWwrite(file, &object_is_visible, sizeof(int), 1);
            SDL_RWwrite(file, &object_type, sizeof(int), 1);
            SDL_RWwrite(file, &object_tilemap_pos_x, sizeof(int), 1);
            SDL_RWwrite(file, &object_tilemap_pos_y, sizeof(int), 1);
            SDL_RWwrite(file, &object_attack_dir4, sizeof(int), 1);
            SDL_RWwrite(file, &object_action_points, sizeof(int), 1);

            object->is_to_be_removed = object_is_to_be_removed;
            object->is_visible = object_is_visible;
            object->type = object_type;
            object->tilemap_pos.x = object_tilemap_pos_x;
            object->tilemap_pos.y = object_tilemap_pos_y;
            object->attack_dir4 = object_attack_dir4;
            object->action_points = object_action_points;
        }
    }

    // curr_room (only name)

    Room* curr_room = state->curr_room;

    char* curr_room_name = curr_room->name;
    int curr_room_name_len = strlen(curr_room_name);

    SDL_RWwrite(file, &curr_room_name_len, sizeof(int), 1);
    SDL_RWwrite(file, curr_room_name, sizeof(char) * curr_room_name_len, 1);

    // visited rooms (only names)

    List* visited_room_list = state->visited_room_list;
    int visited_room_list_size = visited_room_list->size;

    SDL_RWwrite(file, &visited_room_list_size, sizeof(int), 1);

    for(ListElem* room_elem = visited_room_list->head; room_elem != NULL; room_elem = room_elem->next)
    {
        Room* room = (Room*)room_elem->data;

        char* room_name = room->name;
        int room_name_len = strlen(room_name);

        SDL_RWwrite(file, &room_name_len, sizeof(int), 1);
        SDL_RWwrite(file, room_name, sizeof(char) * room_name_len, 1);
    }

    // hero items

    for(int i = 1; i < ITEM__COUNT; i++)
    {
        int number = state->hero_item_number[i];
        SDL_RWwrite(file, &number, sizeof(int), 1);
    }

    // hero augmentations

    for(int i = 1; i < BODY_PART__COUNT; i++)
    {
        int augmentation = state->hero_body_part_augmentation[i];
        SDL_RWwrite(file, &augmentation, sizeof(int), 1);
    }

    // other

    int hero_action_points = state->hero_object->action_points;
    int minibot_action_points = state->minibot_object->action_points;
    int was_minibot_launched = state->was_minibot_launched;
    int was_throne_used = state->was_throne_used;
    int was_secret_1_taken = state->was_secret_1_taken;
    int was_secret_2_taken = state->was_secret_2_taken;
    int was_secret_3_taken = state->was_secret_3_taken;
    int was_secret_4_taken = state->was_secret_4_taken;
    int was_secret_aug_unlocked = state->was_secret_aug_unlocked;
    int reset_turn_uses = state->reset_turn_uses;
    int game_over_uses = state->game_over_uses;
    int prev_prev_music_index = state->prev_prev_music_index;
    int prev_music_index = state->prev_music_index;
    int curr_music_index = state->curr_music_index;
    float prev_save_time = state->time;
    int show_tutorial = state->show_tutorial;

    SDL_RWwrite(file, &hero_action_points, sizeof(int), 1);
    SDL_RWwrite(file, &minibot_action_points, sizeof(int), 1);
    SDL_RWwrite(file, &was_minibot_launched, sizeof(int), 1);
    SDL_RWwrite(file, &was_throne_used, sizeof(int), 1);
    SDL_RWwrite(file, &was_secret_1_taken, sizeof(int), 1);
    SDL_RWwrite(file, &was_secret_2_taken, sizeof(int), 1);
    SDL_RWwrite(file, &was_secret_3_taken, sizeof(int), 1);
    SDL_RWwrite(file, &was_secret_4_taken, sizeof(int), 1);
    SDL_RWwrite(file, &was_secret_aug_unlocked, sizeof(int), 1);
    SDL_RWwrite(file, &reset_turn_uses, sizeof(int), 1);
    SDL_RWwrite(file, &game_over_uses, sizeof(int), 1);
    SDL_RWwrite(file, &prev_prev_music_index, sizeof(int), 1);
    SDL_RWwrite(file, &prev_music_index, sizeof(int), 1);
    SDL_RWwrite(file, &curr_music_index, sizeof(int), 1);
    SDL_RWwrite(file, &prev_save_time, sizeof(float), 1);
    SDL_RWwrite(file, &show_tutorial, sizeof(float), 1);

    // close file

    SDL_RWclose(file);
}

void load_state(State* state, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
{
    // clear state

    remove_all_list_elements(state->room_list, 1);
    remove_all_list_elements(state->visited_room_list, 0);
    remove_all_list_elements(state->passage_list, 0);
    state->curr_room = NULL;

    // read from file

    SDL_RWops* file = SDL_RWFromFile( "save.save", "r" );

    // passages (full info)

    int passage_list_size = 0;

    SDL_RWread(file, &passage_list_size, sizeof(int), 1);

    for(int i = 0; i < passage_list_size; i++)
    {
        char* passage_from_room_name = (char*)malloc(64);
        int passage_from_room_name_len = 0;
        char* passage_to_room_name = (char*)malloc(64);
        int passage_to_room_name_len= 0;

        int passage_from_tilemap_pos_x = 0;
        int passage_from_tilemap_pos_y = 0;
        int passage_to_tilemap_pos_x = 0;
        int passage_to_tilemap_pos_y = 0;

        SDL_RWread(file, &passage_from_room_name_len, sizeof(int), 1);
        SDL_RWread(file, passage_from_room_name, sizeof(char) * passage_from_room_name_len, 1);
        passage_from_room_name[passage_from_room_name_len] = '\0';
        SDL_RWread(file, &passage_to_room_name_len, sizeof(int), 1);
        SDL_RWread(file, passage_to_room_name, sizeof(char) * passage_to_room_name_len, 1);
        passage_to_room_name[passage_to_room_name_len] = '\0';


        SDL_RWread(file, &passage_from_tilemap_pos_x, sizeof(int), 1);
        SDL_RWread(file, &passage_from_tilemap_pos_y, sizeof(int), 1);
        SDL_RWread(file, &passage_to_tilemap_pos_x, sizeof(int), 1);
        SDL_RWread(file, &passage_to_tilemap_pos_y, sizeof(int), 1);

        Passage* passage = new_passage(
            passage_from_room_name, 
            passage_to_room_name, 
            vec2i(passage_from_tilemap_pos_x, passage_from_tilemap_pos_y),
            vec2i(passage_to_tilemap_pos_x, passage_to_tilemap_pos_y)
        );

        add_new_list_element_to_list_end(state->passage_list, passage);
    }

    // hero and minibot objects to null

    state->hero_object = NULL;
    state->minibot_object = NULL;

    // all rooms (full info)

    int room_list_size = 0;

    SDL_RWread(file, &room_list_size, sizeof(int), 1);

    for(int i = 0; i < room_list_size; i++)
    {
        Room* room = new_empty_room("name", 0);

        char* room_name = (char*)malloc(64);
        int room_name_len = 0;
        char room_background_char = ' ';
        int floor_array[TILEMAP_LENGTH][TILEMAP_LENGTH];
        int room_object_list_size = 0;

        SDL_RWread(file, &room_name_len, sizeof(int), 1);
        SDL_RWread(file, room_name, sizeof(char) * room_name_len, 1);
        room_name[room_name_len] = '\0';
        SDL_RWread(file, &room_background_char, sizeof(char), 1);
        SDL_RWread(file, floor_array, sizeof(int) * TILEMAP_LENGTH * TILEMAP_LENGTH, 1);
        SDL_RWread(file, &room_object_list_size, sizeof(int), 1);
        
        room->name = room_name;
        room->background_texture = room_background_char_to_room_background_texture(room_background_char, textures);

        for(int j = 0; j < room_object_list_size; j++)
        {
            Object* object = new_object(OBJECT__NONE);

            int object_is_to_be_removed = 0;
            int object_is_visible = 0;
            int object_type = 0;
            int object_tilemap_pos_x = 0;
            int object_tilemap_pos_y = 0;
            int object_attack_dir4 = 0;
            int object_action_points = 0;

            SDL_RWread(file, &object_is_to_be_removed, sizeof(int), 1);
            SDL_RWread(file, &object_is_visible, sizeof(int), 1);
            SDL_RWread(file, &object_type, sizeof(int), 1);
            SDL_RWread(file, &object_tilemap_pos_x, sizeof(int), 1);
            SDL_RWread(file, &object_tilemap_pos_y, sizeof(int), 1);
            SDL_RWread(file, &object_attack_dir4, sizeof(int), 1);
            SDL_RWread(file, &object_action_points, sizeof(int), 1);

            object->is_to_be_removed = object_is_to_be_removed;
            object->is_visible = object_is_visible;
            object->type = object_type;
            object->tilemap_pos.x = object_tilemap_pos_x;
            object->tilemap_pos.y = object_tilemap_pos_y;
            object->attack_dir4 = object_attack_dir4;
            object->action_points = object_action_points;

            // hero and minibot objects

            if(object->type == OBJECT__HERO || 
            object->type == OBJECT__HERO_FLOATING || 
            object->type == OBJECT__HERO_FLYING)
            {
                state->hero_object = object;
            }

            if(object->type == OBJECT__MINIBOT_ALLY || 
            object->type == OBJECT__MINIBOT_ALLY_CELL || 
            object->type == OBJECT__MINIBOT_ALLY_DYNAMITE || 
            object->type == OBJECT__MINIBOT_ALLY_GEMSTONE)
            {
                state->minibot_object = object;
            }

            add_new_list_element_to_list_end(room->object_list, object);
        }

        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            for(int k = 0; k < TILEMAP_LENGTH; k++)
            {
                room->floor_array[j][k] = floor_array[j][k];
            }
        }

        add_new_list_element_to_list_end(state->room_list, room);
    }

    // curr_room (only name)

    char* curr_room_name = (char*)malloc(64);
    int curr_room_name_len = 0;

    SDL_RWread(file, &curr_room_name_len, sizeof(int), 1);
    SDL_RWread(file, curr_room_name, sizeof(char) * curr_room_name_len, 1);
    curr_room_name[curr_room_name_len] = '\0';

    for(ListElem* room_elem = state->room_list->head; room_elem != NULL; room_elem = room_elem->next)
    {
        Room* room = (Room*)room_elem->data;

        if(room != NULL && strcmp(room->name, curr_room_name) == 0)
        {
            state->curr_room = room;
        }
    }

    // visited rooms (only names)

    int visited_room_list_size = 0;

    SDL_RWread(file, &visited_room_list_size, sizeof(int), 1);

    for(int i = 0; i < visited_room_list_size; i++)
    {
        char* room_name = (char*)malloc(64);
        int room_name_len = 0;

        SDL_RWread(file, &room_name_len, sizeof(int), 1);
        SDL_RWread(file, room_name, sizeof(char) * room_name_len, 1);
        room_name[room_name_len] = '\0';

        for(ListElem* room_elem = state->room_list->head; room_elem != NULL; room_elem = room_elem->next)
        {
            Room* room = (Room*)room_elem->data;

            if(room != NULL && strcmp(room->name, room_name) == 0)
            {
                add_new_list_element_to_list_end(state->visited_room_list, room);
            }
        }
    }

    // hero items

    for(int i = 1; i < ITEM__COUNT; i++)
    {
        int number = 0;
        SDL_RWread(file, &number, sizeof(int), 1);
        state->hero_item_number[i] = number;
    }

    // hero augmentations

    for(int i = 1; i < BODY_PART__COUNT; i++)
    {
        int augmentation = 0;
        SDL_RWread(file, &augmentation, sizeof(int), 1);
        state->hero_body_part_augmentation[i] = augmentation;
    }

    // other

    int hero_action_points = 0;
    int minibot_action_points = 0;
    int was_minibot_launched = 0;
    int was_throne_used = 0;
    int was_secret_1_taken = 0;
    int was_secret_2_taken = 0;
    int was_secret_3_taken = 0;
    int was_secret_4_taken = 0;
    int was_secret_aug_unlocked = 0;
    int reset_turn_uses = 0;
    int game_over_uses = 0;
    int prev_prev_music_index = 0;
    int prev_music_index = 0;
    int curr_music_index = 0;
    float prev_save_time = 0;
    int show_tutorial = 0;

    SDL_RWread(file, &hero_action_points, sizeof(int), 1);
    SDL_RWread(file, &minibot_action_points, sizeof(int), 1);
    SDL_RWread(file, &was_minibot_launched, sizeof(int), 1);
    SDL_RWread(file, &was_throne_used, sizeof(int), 1);
    SDL_RWread(file, &was_secret_1_taken, sizeof(int), 1);
    SDL_RWread(file, &was_secret_2_taken, sizeof(int), 1);
    SDL_RWread(file, &was_secret_3_taken, sizeof(int), 1);
    SDL_RWread(file, &was_secret_4_taken, sizeof(int), 1);
    SDL_RWread(file, &was_secret_aug_unlocked, sizeof(int), 1);
    SDL_RWread(file, &reset_turn_uses, sizeof(int), 1);
    SDL_RWread(file, &game_over_uses, sizeof(int), 1);
    SDL_RWread(file, &prev_prev_music_index, sizeof(int), 1);
    SDL_RWread(file, &prev_music_index, sizeof(int), 1);
    SDL_RWread(file, &curr_music_index, sizeof(int), 1);
    SDL_RWread(file, &prev_save_time, sizeof(float), 1);
    SDL_RWread(file, &show_tutorial, sizeof(int), 1);

    if(state->hero_object == NULL)
    {
        state->hero_object = new_object(OBJECT__HERO);
    }
    state->hero_object->action_points = hero_action_points;
    if(state->minibot_object == NULL)
    {
        state->minibot_object = new_object(OBJECT__MINIBOT_ALLY);
    }
    state->minibot_object->action_points = minibot_action_points;
    state->was_minibot_launched = was_minibot_launched;
    state->was_throne_used = was_throne_used;
    state->was_secret_1_taken = was_secret_1_taken;
    state->was_secret_2_taken = was_secret_2_taken;
    state->was_secret_3_taken = was_secret_3_taken;
    state->was_secret_4_taken = was_secret_4_taken;
    state->was_secret_aug_unlocked = was_secret_aug_unlocked;
    state->reset_turn_uses = reset_turn_uses;
    state->game_over_uses = game_over_uses;
    state->prev_prev_music_index = prev_prev_music_index;
    state->prev_music_index = prev_music_index;
    state->curr_music_index = curr_music_index;
    state->prev_save_time = prev_save_time;
    state->show_tutorial = show_tutorial;

    // close file

    SDL_RWclose(file);

    // this is important

    create_mechanisms(state);

    state->camera_zoom = 2.0f;
    Vec2f middle_world_iso_pos = cart_pos_to_iso_pos(
        gamemap_pos_to_world_pos(
            vec2f(TILEMAP_LENGTH * 0.5f, TILEMAP_LENGTH * 0.5f)
        )
    );
    middle_world_iso_pos.x += TILE_LENGTH * 0.5f;
    middle_world_iso_pos.y += TILE_LENGTH * 0.5f;
    state->camera_world_pos = middle_world_iso_pos;

    state->background_color = colors->ally_background;
    state->background_texture = state->curr_room->background_texture;
    add_new_list_element_to_list_end(
        state->visited_room_list,
        state->curr_room
    );

    update_enemy_list(state);
    update_all_enemy_order(state);
    for(ListElem* curr_elem = state->enemy_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Enemy* curr_enemy = (Enemy*) curr_elem->data;
        update_enemy_attack_targets(state, curr_enemy);
        clear_enemy_attack_actions_and_draw(state, curr_enemy);
        get_enemy_attack_actions_and_draw(state, curr_enemy, textures, sounds);
    }

    update_ally_list(state);
    for(ListElem* curr_elem = state->ally_list->head;
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Ally* curr_ally = (Ally*) curr_elem->data;
        update_ally_skill_list(state, curr_ally);
    }

    state->curr_ally_list_elem = state->ally_list->head;
    state->curr_ally = state->curr_ally_list_elem->data;
}
