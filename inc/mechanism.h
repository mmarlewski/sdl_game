#ifndef MECHANISM_H
#define MECHANISM_H

#include "../inc/common.h"
#include "../inc/vec.h"

typedef struct
{
    int is_in_1;
    char* in_1_room_name;
    Vec2i in_1_tilemap_pos;
    int in_1_is_object;
    int in_1_type;

    int is_in_2;
    char* in_2_room_name;
    Vec2i in_2_tilemap_pos;
    int in_2_is_object;
    int in_2_type;

    int is_in_3;
    char* in_3_room_name;
    Vec2i in_3_tilemap_pos;
    int in_3_is_object;
    int in_3_type;

    int is_out;
    char* out_room_name;
    Vec2i out_tilemap_pos;
    int out_is_object;
    int out_type;

} Mechanism;

Mechanism* new_mechanism(
    int is_in_1,
    char* in_1_room_name,
    Vec2i in_1_tilemap_pos,
    int in_1_is_object,
    int in_1_type,
    int is_in_2,
    char* in_2_room_name,
    Vec2i in_2_tilemap_pos,
    int in_2_is_object,
    int in_2_type,
    int is_in_3,
    char* in_3_room_name,
    Vec2i in_3_tilemap_pos,
    int in_3_is_object,
    int in_3_type,
    int is_out,
    char* out_room_name,
    Vec2i out_tilemap_pos,
    int out_is_object,
    int out_type
);
void destroy_mechanism(Mechanism* mechanism);

#endif
