#include "../inc/state.h"

void save_state(State* state)
{
    SDL_RWops* file = SDL_RWFromFile( "save.save", "w" );

    List* room_list = state->room_list;
    int room_list_size = room_list->size;

    SDL_RWwrite(file, &room_list_size, sizeof(int), 1);

    for(ListElem* room_elem = room_list->head; room_elem != NULL; room_elem = room_elem->next)
    {
        Room* room = (Room*)room_elem->data;

        char* room_name = room->name;
        int room_name_len = strlen(room_name);
        int** floor_array = (int**)room->floor_array;
        List* room_object_list = room->object_list;
        int room_object_list_size = room_object_list->size;

        SDL_RWwrite(file, &room_name_len, sizeof(int), 1);
        SDL_RWwrite(file, room_name, sizeof(char) * room_name_len, 1);
        SDL_RWwrite(file, floor_array, sizeof(int) * TILEMAP_LENGTH * TILEMAP_LENGTH, 1);
        SDL_RWwrite(file, &room_object_list_size, sizeof(int), 1);

        for(int i = 0; i < room_object_list_size; i++)
        {
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
    }

    SDL_RWclose(file);
}

void load_state(State* state)
{
    remove_all_list_elements(state->room_list, 0);
    printf("rooms: %i \n", state->room_list->size);

    SDL_RWops* file = SDL_RWFromFile( "save.save", "r" );

    int room_list_size = 0;

    SDL_RWread(file, &room_list_size, sizeof(int), 1);

    for(int i = 0; i < room_list_size; i++)
    {
        Room* room = new_empty_room("name", 0);

        char room_name[256];
        int room_name_len = 0;
        int floor_array[TILEMAP_LENGTH][TILEMAP_LENGTH];
        int room_object_list_size = 0;

        SDL_RWread(file, &room_name_len, sizeof(int), 1);

        SDL_RWread(file, room_name, sizeof(char) * room_name_len, 1);
        room_name[room_name_len] = '\0';

        SDL_RWread(file, floor_array, sizeof(int) * TILEMAP_LENGTH * TILEMAP_LENGTH, 1);

        SDL_RWread(file, &room_object_list_size, sizeof(int), 1);

        for(int i = 0; i < room_object_list_size; i++)
        {
            for(int j = 0; j < room_object_list_size; j++)
            {
                Object* object = new_object(OBJECT__NONE);

                int object_is_to_be_removed;
                int object_is_visible;
                int object_type;
                int object_tilemap_pos_x;
                int object_tilemap_pos_y;
                int object_attack_dir4;
                int object_action_points;

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

                add_new_list_element_to_list_end(room->object_list, object);
            }
        }

        room->name = room_name;
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            for(int k = 0; k < TILEMAP_LENGTH; k++)
            {
                room->floor_array[j][k] = floor_array[j][k];
            }
        }
        add_new_list_element_to_list_end(state->room_list, room);
    }

    SDL_RWclose(file);

    printf("rooms: %i \n", state->room_list->size);
}
