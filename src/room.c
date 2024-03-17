#include "../inc/room.h"
#include "../inc/object.h"
#include "../inc/floor.h"

Room* new_empty_room(char* name)
{
    Room* room = malloc(sizeof(*room));

    room->name = name;
    for(int i = 0 ; i < TILEMAP_LENGTH ; i++)
    {
        for(int j = 0 ; j < TILEMAP_LENGTH ; j++)
        {
            room->floor_array[i][j] = FLOOR__GRASS;
        }
    }
    room->object_list = new_list((void (*)(void *))&destroy_object);

    return room;
}

void destroy_room(Room* room)
{
    remove_all_list_elements(room->object_list, 1);
    destroy_list(room->object_list);

    free(room);
}

int room_get_floor_at(Room* room, Vec2i tilemap_pos)
{
    if(room == 0) return FLOOR__NONE;

    if(is_tilemap_in_bounds(tilemap_pos))
    {
        return room->floor_array[tilemap_pos.y][tilemap_pos.x];
    }

    return FLOOR__NONE;
}

void room_change_floor_at(Room* room, int floor, Vec2i tilemap_pos)
{
    if(room == 0) return;

    if(room != 0 && is_tilemap_in_bounds(tilemap_pos))
    {
        room->floor_array[tilemap_pos.y][tilemap_pos.x] = floor;
    }
}

void room_add_object(Room* room, Object* object)
{
    if(room == 0) return;

    if(room != 0 && room->object_list != 0 && object != 0)
    {
        add_new_list_element_to_list_end(room->object_list, object);
    }
}

void room_add_object_at(Room* room, Object* object, Vec2i tilemap_pos)
{
    if(room == 0) return;

    if(room != 0 && room->object_list != 0 && object != 0)
    {
        object->tilemap_pos = tilemap_pos;
        room_add_object(room, object);
    }
}

void room_remove_object(Room* room, Object* object, int destroy_data)
{
    if(room == 0) return;

    remove_list_element_of_data(room->object_list, object, destroy_data);
}

void room_remove_object_at(Room* room, Vec2i tilemap_pos, int destroy_data)
{
    if(room == 0) return;

    Object* object = room_get_object_at(room, tilemap_pos);
    if(object != 0)
    {
        room_remove_object(room, object, destroy_data);
    }
}

Passage* new_passage(char* from_room_name, char* to_room_name, Vec2i from_tilemap_pos, Vec2i to_tilemap_pos)
{
    Passage* passage = malloc(sizeof(*passage));

    passage->from_room_name = from_room_name;
    passage->to_room_name = to_room_name;
    passage->from_tilemap_pos = from_tilemap_pos;
    passage->to_tilemap_pos = to_tilemap_pos;

    return passage;
}

void destroy_passage(Passage* passage)
{
    free(passage);
}
