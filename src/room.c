#include "../inc/room.h"
#include "../inc/object.h"
#include "../inc/floor.h"

Exit* new_exit(Vec2i from_tilemap_pos, Vec2i to_tilemap_pos, char* to_room_name)
{
    Exit* exit = malloc(sizeof(*exit));

    exit->from_tilemap_pos = from_tilemap_pos;
    exit->to_tilemap_pos = to_tilemap_pos;
    exit->to_room_name = to_room_name;

    return exit;
}

void destroy_exit(Exit* exit)
{
    free(exit);
}

Room* new_empty_room(char* name)
{
    Room* room = malloc(sizeof(*room));

    room->name = name;
    for(int i = 0 ; i < TILEMAP_LENGTH ; i++)
    {
        for(int j = 0 ; j < TILEMAP_LENGTH ; j++)
        {
            room->floor_array[i][j] = FLOOR_TYPE__GRASS;
        }
    }
    room->object_list = new_list((void (*)(void *))&destroy_object);
    room->exit_list = new_list((void (*)(void *))&destroy_exit);

    return room;
}

void destroy_room(Room* room)
{
    remove_all_list_elements(room->object_list, 1);
    destroy_list(room->object_list);

    remove_all_list_elements(room->exit_list, 1);
    destroy_list(room->exit_list);

    free(room);
}
