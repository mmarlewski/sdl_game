#include "../inc/state.h"

void add_floor_at_every_room_position(Room* room, int floor)
{
    for(int i = 0; i < TILEMAP_LENGTH; i++)
    {
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            room_change_floor_at(
                room,
                floor,
                vec2i(i,j)
                );
        }
    }
}

void add_walls_around_room(Room* room, int wall_type, List* exclude_tilemap_pos_list)
{
    Vec2i first_room_tilemap_pos = vec2i(0,0);
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__RIGHT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__DOWN, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__LEFT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH-1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
            );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__UP, 1);
    }

    for(ListElem* curr_elem = exclude_tilemap_pos_list->head;
    curr_elem != 0; curr_elem = curr_elem->next)
    {
        Vec2i* curr_tilemap_pos = (Vec2i*) curr_elem->data;
        room_remove_object_at(room, *curr_tilemap_pos, 1);
    }
}

void create_level(State* state)
{
    ///////////
    // room_0_0
    ///////////

    Room* room_0_0 = new_empty_room("0_0");
    add_room(
        state,
        room_0_0
        );

    // floors

    add_floor_at_every_room_position(room_0_0, FLOOR_TYPE__OBSIDIAN);
    room_change_floor_at(
        room_0_0,
        FLOOR_TYPE__STONE_SPIKES_ON,
        vec2i(8,5)
        );
    room_change_floor_at(
        room_0_0,
        FLOOR_TYPE__STONE_SPIKES_ON,
        vec2i(8,6)
        );

    // walls

    List* room_0_0_wall_exclude_pos_list = new_list((void (*)(void *))&destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_0_wall_exclude_pos_list,
        new_vec2i(9,2)
        );
    add_new_list_element_to_list_end(
        room_0_0_wall_exclude_pos_list,
        new_vec2i(5,9)
        );
    add_new_list_element_to_list_end(
        room_0_0_wall_exclude_pos_list,
        new_vec2i(7,9)
        );
    add_walls_around_room(
        room_0_0,
        OBJECT_TYPE__WALL_OBSIDIAN,
        room_0_0_wall_exclude_pos_list
        );
    remove_all_list_elements(room_0_0_wall_exclude_pos_list, 1);
    destroy_list(room_0_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(2,2)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(3,2)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(4,2)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(5,2)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(6,2)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(7,2)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(7,3)
        );

    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(1,4)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(2,4)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(3,4)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(4,4)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(5,4)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(5,5)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(6,5)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(7,5)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(7,6)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(7,7)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(6,7)
        );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__WALL_OBSIDIAN),
        vec2i(6,8)
        );

    room_add_object_at(
        room_0_0,
        new_object(OBJECT_TYPE__LEVER_STONE_UNPOWERED),
        vec2i(2,6)
        );

    ///////////
    // room_0_1
    ///////////

    Room* room_0_1 = new_empty_room("0_1");
    add_room(
        state,
        room_0_1
        );

    // floors

    add_floor_at_every_room_position(room_0_1, FLOOR_TYPE__GOLD);
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,1)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__METAL_HATCH_CLOSED,
        vec2i(1,2)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,3)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,4)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,5)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,6)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,7)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__LAVA,
        vec2i(1,8)
        );

    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__WATER,
        vec2i(7,6)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__WATER,
        vec2i(8,6)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__WATER,
        vec2i(7,7)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__WATER,
        vec2i(8,7)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__WATER,
        vec2i(7,8)
        );
    room_change_floor_at(
        room_0_1,
        FLOOR_TYPE__WATER,
        vec2i(8,8)
        );

    // walls

    List* room_0_1_wall_exclude_pos_list = new_list((void (*)(void *))&destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(0,2)
        );
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(9,8)
        );
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(8,9)
        );
    add_walls_around_room(
        room_0_1,
        OBJECT_TYPE__WALL_GOLD,
        room_0_1_wall_exclude_pos_list
        );
    remove_all_list_elements(room_0_1_wall_exclude_pos_list, 1);
    destroy_list(room_0_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_1,
        new_object(OBJECT_TYPE__BALL),
        vec2i(2,7)
        );

    ///////////
    // room_0_2
    ///////////

    Room* room_0_2 = new_empty_room("0_2");
    add_room(
        state,
        room_0_2
        );

    // floors

    add_floor_at_every_room_position(room_0_2, FLOOR_TYPE__GOLD);

    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(4,4)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(5,4)
        );

    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(2,5)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(3,5)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(4,5)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(5,5)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(6,5)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(7,5)
        );

    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(1,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(2,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(3,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(4,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(5,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(6,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(7,6)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(8,6)
        );

    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(1,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(2,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(3,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(4,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(5,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(6,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(7,7)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(8,7)
        );

    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(1,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(2,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(3,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(4,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(5,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(6,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(7,8)
        );
    room_change_floor_at(
        room_0_2,
        FLOOR_TYPE__WATER,
        vec2i(8,8)
        );

    // walls

    List* room_0_2_wall_exclude_pos_list = new_list((void (*)(void *))&destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(0,8)
        );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(1,9)
        );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(9,8)
        );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(8,9)
        );
    add_walls_around_room(
        room_0_2,
        OBJECT_TYPE__WALL_GOLD,
        room_0_2_wall_exclude_pos_list
        );
    remove_all_list_elements(room_0_2_wall_exclude_pos_list, 1);
    destroy_list(room_0_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_2,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(3,1)
        );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(3,2)
        );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(4,2)
        );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(5,2)
        );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(6,2)
        );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(6,1)
        );

    ///////////
    // room_0_3
    ///////////

    Room* room_0_3 = new_empty_room("0_3");
    add_room(
        state,
        room_0_3
        );

    // floors

    add_floor_at_every_room_position(room_0_3, FLOOR_TYPE__GOLD);
    room_change_floor_at(
        room_0_3,
        FLOOR_TYPE__WATER,
        vec2i(1,6)
        );
    room_change_floor_at(
        room_0_3,
        FLOOR_TYPE__WATER,
        vec2i(2,6)
        );
    room_change_floor_at(
        room_0_3,
        FLOOR_TYPE__WATER,
        vec2i(1,7)
        );
    room_change_floor_at(
        room_0_3,
        FLOOR_TYPE__WATER,
        vec2i(2,7)
        );
    room_change_floor_at(
        room_0_3,
        FLOOR_TYPE__WATER,
        vec2i(1,8)
        );
    room_change_floor_at(
        room_0_3,
        FLOOR_TYPE__WATER,
        vec2i(2,8)
        );

    // walls

    List* room_0_3_wall_exclude_pos_list = new_list((void (*)(void *))&destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(0,8)
        );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(1,9)
        );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(9,8)
        );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(8,9)
        );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(9,2)
        );
    add_walls_around_room(
        room_0_3,
        OBJECT_TYPE__WALL_GOLD,
        room_0_3_wall_exclude_pos_list
        );
    remove_all_list_elements(room_0_3_wall_exclude_pos_list, 1);
    destroy_list(room_0_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(5,1)
        );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(5,2)
        );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(5,3)
        );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(5,4)
        );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(6,4)
        );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(7,4)
        );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(8,4)
        );

    ///////////
    // room_0_4
    ///////////

    Room* room_0_4 = new_empty_room("0_4");
    add_room(
        state,
        room_0_4
        );

    // floors

    add_floor_at_every_room_position(room_0_4, FLOOR_TYPE__GOLD);

    // walls

    List* room_0_4_wall_exclude_pos_list = new_list((void (*)(void *))&destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(0,8)
        );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(1,9)
        );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(9,8)
        );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(8,9)
        );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(0,2)
        );
    add_walls_around_room(
        room_0_4,
        OBJECT_TYPE__WALL_GOLD,
        room_0_4_wall_exclude_pos_list
        );
    remove_all_list_elements(room_0_4_wall_exclude_pos_list, 1);
    destroy_list(room_0_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(4,1)
        );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(4,2)
        );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(4,3)
        );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(4,4)
        );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(3,4)
        );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(2,4)
        );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT_TYPE__WALL_GOLD),
        vec2i(1,4)
        );

    ///////////
    // room_0_4
    ///////////

    Room* room_0_5 = new_empty_room("0_5");
    add_room(
        state,
        room_0_5
        );
    room_add_object_at(
        room_0_5,
        state->hero_object,
        vec2i(1,1)
        );
    set_curr_room(state, room_0_5);
    add_new_list_element_to_list_end(
        state->visited_room_list,
        room_0_5
        );

    // floors

    add_floor_at_every_room_position(room_0_5, FLOOR_TYPE__MARBLE);

    // walls

    List* room_0_5_wall_exclude_pos_list = new_list((void (*)(void *))&destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_5_wall_exclude_pos_list,
        new_vec2i(0,2)
        );
    add_new_list_element_to_list_end(
        room_0_5_wall_exclude_pos_list,
        new_vec2i(2,9)
        );
    add_walls_around_room(
        room_0_5,
        OBJECT_TYPE__WALL_MARBLE,
        room_0_5_wall_exclude_pos_list
        );
    remove_all_list_elements(room_0_5_wall_exclude_pos_list, 1);
    destroy_list(room_0_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__LEVER_STONE_UNPOWERED),
        vec2i(7,2)
        );

    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,1)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,2)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,3)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,4)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,5)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,6)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,7)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(3,8)
        );

    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,1)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,2)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,3)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,4)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,5)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,6)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,7)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(4,8)
        );

    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,1)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,2)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,3)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,4)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,5)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,6)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,7)
        );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT_TYPE__PILLAR),
        vec2i(5,8)
        );
}
