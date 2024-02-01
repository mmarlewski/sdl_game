#ifndef ROOM_H
#define ROOM_H

#include "../inc/common.h"
#include "../inc/list.h"
#include "../inc/vec.h"

typedef struct
{
    Vec2i from_tilemap_pos;
    Vec2i to_tilemap_pos;
    char* to_room_name;

} Exit;

typedef struct
{
    char* name;
    int floor_array[TILEMAP_LENGTH][TILEMAP_LENGTH];
    List* object_list;
    List* exit_list;

} Room;

Exit* new_exit(Vec2i from_tilemap_pos, Vec2i to_tilemap_pos, char* to_room_name);
void destroy_exit(Exit* exit);

Room* new_empty_room(char* name);
void destroy_room(Room* room);

#endif
