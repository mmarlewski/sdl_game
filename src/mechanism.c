#include "../inc/mechanism.h"

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
)
{
    Mechanism* mechanism = malloc(sizeof(*mechanism));

    mechanism->is_in_1 = is_in_1;
    mechanism->in_1_room_name = in_1_room_name;
    mechanism->in_1_tilemap_pos = in_1_tilemap_pos;
    mechanism->in_1_is_object = in_1_is_object;
    mechanism->in_1_type = in_1_type;

    mechanism->is_in_2 = is_in_2;
    mechanism->in_2_room_name = in_2_room_name;
    mechanism->in_2_tilemap_pos = in_2_tilemap_pos;
    mechanism->in_2_is_object = in_2_is_object;
    mechanism->in_2_type = in_2_type;

    mechanism->is_in_3 = is_in_3;
    mechanism->in_3_room_name = in_3_room_name;
    mechanism->in_3_tilemap_pos = in_3_tilemap_pos;
    mechanism->in_3_is_object = in_3_is_object;
    mechanism->in_3_type = in_3_type;

    mechanism->is_out = is_out;
    mechanism->out_room_name = out_room_name;
    mechanism->out_tilemap_pos = out_tilemap_pos;
    mechanism->out_is_object = out_is_object;
    mechanism->out_type = out_type;

    return mechanism;
}

void destroy_mechanism(Mechanism* mechanism)
{
    free(mechanism);
}
