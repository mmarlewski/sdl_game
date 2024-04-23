#ifndef ROOM_H
#define ROOM_H

#include "../inc/common.h"
#include "../inc/list.h"
#include "../inc/vec.h"
#include "../inc/object.h"

typedef struct
{
    char* name;
    int floor_array[TILEMAP_LENGTH][TILEMAP_LENGTH];
    List* object_list;
    Texture* background_texture;

} Room;

typedef struct
{
    char* from_room_name;
    char* to_room_name;
    Vec2i from_tilemap_pos;
    Vec2i to_tilemap_pos;

} Passage;

Room* new_empty_room(char* name, Texture* background_texture);
void destroy_room(Room* room);
int room_get_floor_at(Room* room, Vec2i tilemap_pos);
void room_change_floor_at(Room* room, int floor, Vec2i tilemap_pos);
Object* room_get_object_at(Room* room, Vec2i tilemap_pos);
void room_add_object(Room* room, Object* object);
void room_add_object_at(Room* room, Object* object, Vec2i tilemap_pos);
void room_remove_object(Room* room, Object* object, int destroy_data);
void room_remove_object_at(Room* room, Vec2i tilemap_pos, int destroy_data);

Passage* new_passage(char* from_room_name, char* to_room_name, Vec2i from_tilemap_pos, Vec2i to_tilemap_pos);
void destroy_passage(Passage* passage);

#endif
