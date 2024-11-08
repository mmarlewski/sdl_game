#include "../inc/state.h"
#include <stdlib.h>

void add_floor_at_every_room_position(Room* room, int floor)
{
    for(int i = 0; i < TILEMAP_LENGTH; i++)
    {
        for(int j = 0; j < TILEMAP_LENGTH; j++)
        {
            room_change_floor_at(
                room,
                floor,
                vec2i(i, j)
            );
        }
    }
}

void add_walls_around_room(Room* room, int wall_type, List* exclude_tilemap_pos_list)
{
    Vec2i first_room_tilemap_pos = vec2i(0, 0);
    for(int i = 0; i < TILEMAP_LENGTH - 1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
        );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__RIGHT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH - 1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
        );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__DOWN, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH - 1; i++)
    {
        room_add_object_at(
            room,
            new_object(wall_type),
            first_room_tilemap_pos
        );
        first_room_tilemap_pos =
            vec2i_move_in_dir4_by(first_room_tilemap_pos, DIR4__LEFT, 1);
    }
    for(int i = 0; i < TILEMAP_LENGTH - 1; i++)
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
        curr_elem != NULL; curr_elem = curr_elem->next)
    {
        Vec2i* curr_tilemap_pos = (Vec2i*) curr_elem->data;
        room_remove_object_at(room, *curr_tilemap_pos, 1);
    }
}

void create_level(State* state, Textures* textures)
{
    ///////////
    // room_0_0
    ///////////

    Room* room_0_0 = new_empty_room("0_0", textures->background_obsidian);
    add_room(
        state,
        room_0_0
    );

    // floors

    add_floor_at_every_room_position(room_0_0, FLOOR__OBSIDIAN);

    room_change_floor_at(
        room_0_0,
        FLOOR__METAL_SPIKES_ON,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_0_0,
        FLOOR__METAL_SPIKES_ON,
        vec2i(8, 6)
    );

    room_change_floor_at(
        room_0_0,
        FLOOR__STONE_TRAP,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_0_0,
        FLOOR__STONE_TRAP,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_0_0,
        FLOOR__STONE_TRAP,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_0_0,
        FLOOR__STONE_TRAP,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_0_0,
        FLOOR__STONE_TRAP,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_0_0,
        FLOOR__STONE_TRAP,
        vec2i(6, 3)
    );

    room_change_floor_at(
        room_0_0,
        FLOOR__OBSTACLE,
        vec2i(8, 3)
    );

    // walls

    List* room_0_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_0_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_new_list_element_to_list_end(
        room_0_0_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_0_0_wall_exclude_pos_list,
        new_vec2i(7, 9)
    );
    add_walls_around_room(
        room_0_0,
        OBJECT__WALL_OBSIDIAN,
        room_0_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_0_0_wall_exclude_pos_list, 1);
    destroy_list(room_0_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 3)
    );

    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 6)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 8)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 6)
    );

    room_add_object_at(
        room_0_0,
        new_object(OBJECT__VENDING_CELL),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__LEVER_STONE_UNPOWERED),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__OBSTACLE),
        vec2i(8, 3)
    );

    room_add_object_at(
        room_0_0,
        new_object(OBJECT__EXIT_OBSIDIAN_LEFT),
        vec2i(9, 2)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_0_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(7, 9)
    );

    // passages

    add_passage(state, new_passage(
        "0_0",
        "0_1",
        vec2i(9, 2),
        vec2i(1, 2)
    ));
    add_passage(state, new_passage(
        "0_0",
        "1_0",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "0_0",
        "1_0",
        vec2i(7, 9),
        vec2i(7, 1)
    ));

    ///////////
    // room_0_1
    ///////////

    Room* room_0_1 = new_empty_room("0_1", textures->background_gold);
    add_room(
        state,
        room_0_1
    );

    // floors

    add_floor_at_every_room_position(room_0_1, FLOOR__GOLD);

    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 0)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__METAL_HATCH_CLOSED,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__LAVA,
        vec2i(1, 9)
    );

    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(7, 9)
    );

    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(8, 9)
    );

    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(9, 6)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(9, 7)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__WATER,
        vec2i(9, 8)
    );

    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_0_1,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(8, 3)
    );

    // walls

    List* room_0_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(9, 8)
    );
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(8, 9)
    );
    add_new_list_element_to_list_end(
        room_0_1_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_walls_around_room(
        room_0_1,
        OBJECT__WALL_GOLD,
        room_0_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_0_1_wall_exclude_pos_list, 1);
    destroy_list(room_0_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_1,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_0_1,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(8, 9)
    );
    room_add_object_at(
        room_0_1,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 8)
    );
    room_add_object_at(
        room_0_1,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 1)
    );

    // enemies

    room_add_object_at(
        room_0_1,
        new_object(OBJECT__GOAT),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_0_1,
        new_object(OBJECT__GOAT),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_0_1,
        new_object(OBJECT__GOAT),
        vec2i(8, 4)
    );
    room_add_object_at(
        room_0_1,
        new_object(OBJECT__GOAT),
        vec2i(6, 7)
    );

    // passages

    add_passage(state, new_passage(
        "0_1",
        "0_0",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "0_1",
        "1_1",
        vec2i(8, 9),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "0_1",
        "0_2",
        vec2i(9, 8),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "0_1",
        "0_2",
        vec2i(9, 1),
        vec2i(1, 1)
    ));

    ///////////
    // room_0_2
    ///////////

    Room* room_0_2 = new_empty_room("0_2", textures->background_gold);
    add_room(
        state,
        room_0_2
    );

    // floors

    add_floor_at_every_room_position(room_0_2, FLOOR__GOLD);

    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(5, 4)
    );

    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(7, 5)
    );

    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(0, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(9, 6)
    );

    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(0, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(9, 7)
    );

    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(0, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(6, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(9, 8)
    );

    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(1, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(2, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(3, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(4, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(5, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(6, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(7, 9)
    );
    room_change_floor_at(
        room_0_2,
        FLOOR__WATER,
        vec2i(8, 9)
    );

    // walls

    List* room_0_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(0, 8)
    );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(1, 9)
    );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(9, 8)
    );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(8, 9)
    );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_new_list_element_to_list_end(
        room_0_2_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_walls_around_room(
        room_0_2,
        OBJECT__WALL_GOLD,
        room_0_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_0_2_wall_exclude_pos_list, 1);
    destroy_list(room_0_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_2,
        new_object(OBJECT__WALL_GOLD),
        vec2i(3, 1)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__WALL_GOLD),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__WALL_GOLD),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 1)
    );

    room_add_object_at(
        room_0_2,
        new_object(OBJECT__THRONE),
        vec2i(4, 1)
    );

    room_add_object_at(
        room_0_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 8)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(1, 9)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 8)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(8, 9)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 1)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 1)
    );

    // enemies

    room_add_object_at(
        room_0_2,
        new_object(OBJECT__SQUID),
        vec2i(3, 6)
    );
    room_add_object_at(
        room_0_2,
        new_object(OBJECT__ENVIRONMENT_EMERGE_WATER),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "0_2",
        "0_1",
        vec2i(0, 8),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "0_2",
        "1_2",
        vec2i(1, 9),
        vec2i(1, 1)
    ));
    add_passage(state, new_passage(
        "0_2",
        "0_3",
        vec2i(9, 8),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "0_2",
        "1_2",
        vec2i(8, 9),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "0_2",
        "0_1",
        vec2i(0, 1),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "0_2",
        "0_3",
        vec2i(9, 1),
        vec2i(1, 1)
    ));

    ///////////
    // room_0_3
    ///////////

    Room* room_0_3 = new_empty_room("0_3", textures->background_gold);
    add_room(
        state,
        room_0_3
    );

    // floors

    add_floor_at_every_room_position(room_0_3, FLOOR__GOLD);

    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(0, 6)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(0, 7)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(0, 8)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__GOLD,
        vec2i(0, 9)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(1, 9)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__WATER,
        vec2i(2, 9)
    );

    room_change_floor_at(
        room_0_3,
        FLOOR__METAL_PISTON,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__METAL_PISTON,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__METAL_PISTON,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_0_3,
        FLOOR__METAL_PISTON,
        vec2i(4, 4)
    );

    room_change_floor_at(
        room_0_3,
        FLOOR__METAL_PISTON_MIMIC,
        vec2i(6, 5)
    );

    // walls

    List* room_0_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(0, 8)
    );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(1, 9)
    );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(9, 8)
    );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(8, 9)
    );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_new_list_element_to_list_end(
        room_0_3_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_walls_around_room(
        room_0_3,
        OBJECT__WALL_GOLD,
        room_0_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_0_3_wall_exclude_pos_list, 1);
    destroy_list(room_0_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_3,
        new_object(OBJECT__PISTON),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__PISTON),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__PISTON),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__PISTON),
        vec2i(4, 4)
    );

    room_add_object_at(
        room_0_3,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(8, 5)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(6, 8)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(2, 1)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(7, 2)
    );

    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(5, 1)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(8, 4)
    );

    room_add_object_at(
        room_0_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 8)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(1, 9)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__EXIT_GOLD_LOCKED_LEFT),
        vec2i(9, 8)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(8, 9)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 1)
    );
    room_add_object_at(
        room_0_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 1)
    );

    // passages

    add_passage(state, new_passage(
        "0_3",
        "0_2",
        vec2i(0, 8),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "0_3",
        "1_3",
        vec2i(1, 9),
        vec2i(1, 1)
    ));
    add_passage(state, new_passage(
        "0_3",
        "0_4",
        vec2i(9, 8),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "0_3",
        "1_3",
        vec2i(8, 9),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "0_3",
        "0_4",
        vec2i(9, 1),
        vec2i(1, 1)
    ));
    add_passage(state, new_passage(
        "0_3",
        "0_2",
        vec2i(0, 1),
        vec2i(8, 1)
    ));

    ///////////
    // room_0_4
    ///////////

    Room* room_0_4 = new_empty_room("0_4", textures->background_gold);
    add_room(
        state,
        room_0_4
    );

    // floors

    add_floor_at_every_room_position(room_0_4, FLOOR__GOLD);

    for(int i = 2; i <= 7; i++)
    {
        for(int j = 2; j <= 7; j++)
        {
            room_change_floor_at(
                room_0_4,
                FLOOR__COINS,
                vec2i(i, j)
            );
        }
    }

    // walls

    List* room_0_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(0, 8)
    );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(1, 9)
    );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_new_list_element_to_list_end(
        room_0_4_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_walls_around_room(
        room_0_4,
        OBJECT__WALL_GOLD,
        room_0_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_0_4_wall_exclude_pos_list, 1);
    destroy_list(room_0_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__WALL_GOLD),
        vec2i(1, 4)
    );

    room_add_object_at(
        room_0_4,
        new_object(OBJECT__EXIT_GOLD_LOCKED_RIGHT),
        vec2i(0, 8)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(1, 9)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 2)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 1)
    );

    // enemies

    room_add_object_at(
        room_0_4,
        new_object(OBJECT__ENVIRONMENT_EMERGE_BURROW),
        vec2i(-1, -1)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__ENVIRONMENT_EMERGE_BURROW),
        vec2i(-1, -1)
    );
    room_add_object_at(
        room_0_4,
        new_object(OBJECT__ENVIRONMENT_EMERGE_BURROW),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "0_4",
        "0_3",
        vec2i(0, 8),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "0_4",
        "1_4",
        vec2i(1, 9),
        vec2i(1, 1)
    ));
    add_passage(state, new_passage(
        "0_4",
        "0_5",
        vec2i(9, 2),
        vec2i(1, 2)
    ));
    add_passage(state, new_passage(
        "0_4",
        "0_3",
        vec2i(0, 1),
        vec2i(8, 1)
    ));

    ///////////
    // room_0_5
    ///////////

    Room* room_0_5 = new_empty_room("0_5", textures->background_marble);
    add_room(
        state,
        room_0_5
    );

    // floors

    add_floor_at_every_room_position(room_0_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_0_5,
        FLOOR__OBSTACLE,
        vec2i(1, 4)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(2, 7)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(3, 8)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(4, 8)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(5, 8)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(6, 8)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(7, 8)
    );

    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_0_5,
        FLOOR__PIT,
        vec2i(8, 8)
    );

    // walls

    List* room_0_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_0_5_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_0_5_wall_exclude_pos_list,
        new_vec2i(2, 9)
    );
    add_walls_around_room(
        room_0_5,
        OBJECT__WALL_MARBLE,
        room_0_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_0_5_wall_exclude_pos_list, 1);
    destroy_list(room_0_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_0_5,
        new_object(OBJECT__PILLAR),
        vec2i(1, 1)
    );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT__PILLAR),
        vec2i(3, 1)
    );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT__PILLAR),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT__PILLAR),
        vec2i(5, 1)
    );

    room_add_object_at(
        room_0_5,
        new_object(OBJECT__OBSTACLE),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT__LEVER_STONE_UNPOWERED),
        vec2i(7, 2)
    );

    room_add_object_at(
        room_0_5,
        new_object(OBJECT__EXIT_MARBLE_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_0_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(2, 9)
    );

    // passages

    add_passage(state, new_passage(
        "0_5",
        "0_4",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "0_5",
        "1_5",
        vec2i(2, 9),
        vec2i(2, 1)
    ));

    ///////////
    // room_1_0
    ///////////

    Room* room_1_0 = new_empty_room("1_0", textures->background_obsidian);
    add_room(
        state,
        room_1_0
    );

    // floors

    add_floor_at_every_room_position(room_1_0, FLOOR__OBSIDIAN);
    room_change_floor_at(
        room_1_0,
        FLOOR__STONE_TRAP,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__STONE_TRAP,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__STONE_TRAP,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__STONE_TRAP,
        vec2i(8, 5)
    );

    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_RIGHT,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_RIGHT,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_DOWN,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_DOWN,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_DOWN,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_DOWN,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_DOWN,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_LEFT,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_LEFT,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_UP,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_UP,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_UP,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_UP,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_1_0,
        FLOOR__CONV_BELT_UP,
        vec2i(2, 3)
    );

    // walls

    List* room_1_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_1_0_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_1_0_wall_exclude_pos_list,
        new_vec2i(7, 0)
    );
    add_new_list_element_to_list_end(
        room_1_0_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_1_0_wall_exclude_pos_list,
        new_vec2i(7, 9)
    );
    add_walls_around_room(
        room_1_0,
        OBJECT__WALL_OBSIDIAN,
        room_1_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_1_0_wall_exclude_pos_list, 1);
    destroy_list(room_1_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_1_0,
        new_object(OBJECT__ENVIRONMENT_CONV_BELT),
        vec2i(-1, -1)
    );

    room_add_object_at(
        room_1_0,
        new_object(OBJECT__COLUMN),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__COLUMN),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__COLUMN),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__COLUMN),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__COLUMN),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__COLUMN),
        vec2i(4, 6)
    );

    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 3)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 6)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 8)
    );

    room_add_object_at(
        room_1_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(7, 0)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_1_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(7, 9)
    );

    // passages

    add_passage(state, new_passage(
        "1_0",
        "0_0",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "1_0",
        "0_0",
        vec2i(7, 0),
        vec2i(7, 8)
    ));
    add_passage(state, new_passage(
        "1_0",
        "2_0",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "1_0",
        "2_0",
        vec2i(7, 9),
        vec2i(7, 1)
    ));

    ///////////
    // room_1_1
    ///////////

    Room* room_1_1 = new_empty_room("1_1", textures->background_gold);
    add_room(
        state,
        room_1_1
    );

    // floors

    add_floor_at_every_room_position(room_1_1, FLOOR__GOLD);

    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 0)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__LAVA,
        vec2i(1, 9)
    );

    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(7, 0)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(7, 4)
    );

    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(8, 0)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(8, 4)
    );

    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(9, 0)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(9, 1)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(9, 2)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(9, 3)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__WATER,
        vec2i(9, 4)
    );

    room_change_floor_at(
        room_1_1,
        FLOOR__PIT,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__PIT,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_1_1,
        FLOOR__PIT,
        vec2i(5, 6)
    );

    // walls

    List* room_1_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_1_1_wall_exclude_pos_list,
        new_vec2i(8, 0)
    );
    add_new_list_element_to_list_end(
        room_1_1_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_walls_around_room(
        room_1_1,
        OBJECT__WALL_GOLD,
        room_1_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_1_1_wall_exclude_pos_list, 1);
    destroy_list(room_1_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 6)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 3)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 2)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__COLUMN),
        vec2i(4, 5)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(4, 7)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__WALL_GOLD),
        vec2i(8, 5)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__COLUMN),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__COLUMN),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__COLUMN),
        vec2i(4, 6)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__BARREL),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__BARREL),
        vec2i(3, 6)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__PILLAR),
        vec2i(3, 1)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__PIPE),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__PILLAR),
        vec2i(3, 3)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__PIPE),
        vec2i(3, 4)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__VENDING_CELL_DAMAGED_ITEM),
        vec2i(7, 6)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__VENDING_DYNAMITE_DAMAGED_ITEM),
        vec2i(8, 6)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(8, 8)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(7, 8)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(6, 8)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(5, 8)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(4, 8)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(3, 8)
    );

    room_add_object_at(
        room_1_1,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(8, 0)
    );
    room_add_object_at(
        room_1_1,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 1)
    );

    // passages

    add_passage(state, new_passage(
        "1_1",
        "0_1",
        vec2i(8, 0),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "1_1",
        "1_2",
        vec2i(9, 1),
        vec2i(1, 1)
    ));

    ///////////
    // room_1_2
    ///////////

    Room* room_1_2 = new_empty_room("1_2", textures->background_gold);
    add_room(
        state,
        room_1_2
    );

    // floors

    add_floor_at_every_room_position(room_1_2, FLOOR__GOLD);

    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(8, 1)
    );

    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(6, 2)
    );

    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 3)
    );

    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(2, 4)
    );

    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 8)
    );

    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(1, 0)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(0, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(8, 0)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(9, 1)
    );
    room_change_floor_at(
        room_1_2,
        FLOOR__WATER,
        vec2i(4, 9)
    );

    // walls

    List* room_1_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_1_2_wall_exclude_pos_list,
        new_vec2i(1, 0)
    );
    add_new_list_element_to_list_end(
        room_1_2_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_new_list_element_to_list_end(
        room_1_2_wall_exclude_pos_list,
        new_vec2i(8, 0)
    );
    add_new_list_element_to_list_end(
        room_1_2_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_new_list_element_to_list_end(
        room_1_2_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_walls_around_room(
        room_1_2,
        OBJECT__WALL_GOLD,
        room_1_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_1_2_wall_exclude_pos_list, 1);
    destroy_list(room_1_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 6)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__BARREL),
        vec2i(7, 8)
    );

    room_add_object_at(
        room_1_2,
        new_object(OBJECT__DISPLAY),
        vec2i(8, 6)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__DISPLAY),
        vec2i(8, 7)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__DISPLAY),
        vec2i(8, 8)
    );

    room_add_object_at(
        room_1_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_DOWN),
        vec2i(1, 0)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 1)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_DOWN),
        vec2i(8, 0)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 1)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_UP),
        vec2i(4, 9)
    );

    // enemies

    room_add_object_at(
        room_1_2,
        new_object(OBJECT__SHARK),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__SHARK_FIN),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__SHARK),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__SHARK_FIN),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__SHARK),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_1_2,
        new_object(OBJECT__SHARK_FIN),
        vec2i(7, 1)
    );

    // passages

    add_passage(state, new_passage(
        "1_2",
        "0_2",
        vec2i(1, 0),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "1_2",
        "1_1",
        vec2i(0, 1),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "1_2",
        "0_2",
        vec2i(8, 0),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "1_2",
        "1_3",
        vec2i(9, 1),
        vec2i(1, 1)
    ));
    add_passage(state, new_passage(
        "1_2",
        "2_2",
        vec2i(4, 9),
        vec2i(4, 1)
    ));

    ///////////
    // room_1_3
    ///////////

    Room* room_1_3 = new_empty_room("1_3", textures->background_gold);
    add_room(
        state,
        room_1_3
    );

    // floors

    add_floor_at_every_room_position(room_1_3, FLOOR__GOLD);

    room_change_floor_at(
        room_1_3,
        FLOOR__WATER,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__WATER,
        vec2i(2, 1)
    );

    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 8)
    );

    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__PIT,
        vec2i(8, 5)
    );

    room_change_floor_at(
        room_1_3,
        FLOOR__WATER,
        vec2i(1, 0)
    );
    room_change_floor_at(
        room_1_3,
        FLOOR__WATER,
        vec2i(0, 1)
    );

    room_change_floor_at(
        room_1_3,
        FLOOR__PIT_COLUMN,
        vec2i(4, 3)
    );

    // walls

    List* room_1_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_1_3_wall_exclude_pos_list,
        new_vec2i(1, 0)
    );
    add_new_list_element_to_list_end(
        room_1_3_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_new_list_element_to_list_end(
        room_1_3_wall_exclude_pos_list,
        new_vec2i(8, 0)
    );
    add_new_list_element_to_list_end(
        room_1_3_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_walls_around_room(
        room_1_3,
        OBJECT__WALL_GOLD,
        room_1_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_1_3_wall_exclude_pos_list, 1);
    destroy_list(room_1_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__STATION_BOOT_LEG),
        vec2i(3, 6)
    );

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(8, 2)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__COLUMN),
        vec2i(6, 3)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__BARREL),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__BARREL),
        vec2i(8, 3)
    );

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(1, 2)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__COLUMN),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__BARREL),
        vec2i(1, 3)
    );

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__WALL_GOLD),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__COLUMN),
        vec2i(3, 8)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__BARREL),
        vec2i(2, 8)
    );

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(6, 8)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(7, 8)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(8, 8)
    );

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_DOWN),
        vec2i(1, 0)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 1)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_DOWN),
        vec2i(8, 0)
    );
    room_add_object_at(
        room_1_3,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_LEFT),
        vec2i(9, 1)
    );

    // enemies

    room_add_object_at(
        room_1_3,
        new_object(OBJECT__FLY),
        vec2i(7, 7)
    );

    // passages

    add_passage(state, new_passage(
        "1_3",
        "0_3",
        vec2i(1, 0),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "1_3",
        "1_2",
        vec2i(0, 1),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "1_3",
        "0_3",
        vec2i(8, 0),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "1_3",
        "1_4",
        vec2i(9, 1),
        vec2i(1, 1)
    ));

    ///////////
    // room_1_4
    ///////////

    Room* room_1_4 = new_empty_room("1_4", textures->background_gold);
    add_room(
        state,
        room_1_4
    );

    // floors

    add_floor_at_every_room_position(room_1_4, FLOOR__GOLD);

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 1)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 2)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 3)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 4)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 5)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 6)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 7)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(4, 8)
    );

    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(6, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_1_4,
        FLOOR__STONE_TRAP,
        vec2i(8, 5)
    );

    // walls

    List* room_1_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_1_4_wall_exclude_pos_list,
        new_vec2i(1, 0)
    );
    add_new_list_element_to_list_end(
        room_1_4_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_walls_around_room(
        room_1_4,
        OBJECT__WALL_GOLD,
        room_1_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_1_4_wall_exclude_pos_list, 1);
    destroy_list(room_1_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_1_4,
        new_object(OBJECT__STATION_TELEPORTATION_HEAD),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_1_4,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_DOWN),
        vec2i(1, 0)
    );
    room_add_object_at(
        room_1_4,
        new_object(OBJECT__EXIT_GOLD_UNLOCKED_RIGHT),
        vec2i(0, 1)
    );

    // passages

    add_passage(state, new_passage(
        "1_4",
        "0_4",
        vec2i(1, 0),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "1_4",
        "1_3",
        vec2i(0, 1),
        vec2i(8, 1)
    ));

    ///////////
    // room_1_5
    ///////////

    Room* room_1_5 = new_empty_room("1_5", textures->background_marble);
    add_room(
        state,
        room_1_5
    );

    // floors

    add_floor_at_every_room_position(room_1_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(8, 1)
    );

    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_1_5,
        FLOOR__PIT,
        vec2i(6, 8)
    );

    // walls

    List* room_1_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_1_5_wall_exclude_pos_list,
        new_vec2i(2, 0)
    );
    add_new_list_element_to_list_end(
        room_1_5_wall_exclude_pos_list,
        new_vec2i(7, 9)
    );
    add_walls_around_room(
        room_1_5,
        OBJECT__WALL_MARBLE,
        room_1_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_1_5_wall_exclude_pos_list, 1);
    destroy_list(room_1_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_1_5,
        new_object(OBJECT__GOLEM_HALF_POWERED),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 6)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 8)
    );

    room_add_object_at(
        room_1_5,
        new_object(OBJECT__COLUMN),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__DISPLAY),
        vec2i(1, 8)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__DISPLAY),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__DISPLAY),
        vec2i(4, 8)
    );

    room_add_object_at(
        room_1_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(2, 0)
    );
    room_add_object_at(
        room_1_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(7, 9)
    );

    // passages

    add_passage(state, new_passage(
        "1_5",
        "0_5",
        vec2i(2, 0),
        vec2i(2, 8)
    ));
    add_passage(state, new_passage(
        "1_5",
        "2_5",
        vec2i(7, 9),
        vec2i(7, 1)
    ));

    ///////////
    // room_2_0
    ///////////

    Room* room_2_0 = new_empty_room("2_0", textures->background_obsidian);
    add_room(
        state,
        room_2_0
    );

    // floors

    add_floor_at_every_room_position(room_2_0, FLOOR__OBSIDIAN);

    room_change_floor_at(
        room_2_0,
        FLOOR__METAL_TARGET_UNCHECKED,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_2_0,
        FLOOR__METAL_TARGET_UNCHECKED,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_2_0,
        FLOOR__OBSTACLE,
        vec2i(8, 2)
    );

    // walls

    List* room_2_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_2_0_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_2_0_wall_exclude_pos_list,
        new_vec2i(7, 0)
    );
    add_new_list_element_to_list_end(
        room_2_0_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_2_0_wall_exclude_pos_list,
        new_vec2i(7, 9)
    );
    add_walls_around_room(
        room_2_0,
        OBJECT__WALL_OBSIDIAN,
        room_2_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_2_0_wall_exclude_pos_list, 1);
    destroy_list(room_2_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 8)
    );

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 7)
    );

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 7)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 7)
    );

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__OBSTACLE),
        vec2i(8, 2)
    );

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__STALAGMITE),
        vec2i(1, 2)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__STALACTITE),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__STALAGMITE),
        vec2i(1, 6)
    );

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(7, 0)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(7, 9)
    );

    // enemies

    room_add_object_at(
        room_2_0,
        new_object(OBJECT__BULL),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_2_0,
        new_object(OBJECT__GOAT),
        vec2i(7, 5)
    );

    // passages

    add_passage(state, new_passage(
        "2_0",
        "1_0",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "2_0",
        "1_0",
        vec2i(7, 0),
        vec2i(7, 8)
    ));
    add_passage(state, new_passage(
        "2_0",
        "3_0",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "2_0",
        "3_0",
        vec2i(7, 9),
        vec2i(7, 1)
    ));

    ///////////
    // room_2_1
    ///////////

    Room* room_2_1 = new_empty_room("2_1", textures->background_metal);
    add_room(
        state,
        room_2_1
    );

    // floors

    add_floor_at_every_room_position(room_2_1, FLOOR__METAL);

    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(4, 9)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(4, 6)
    );

    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(3, 4)
    );

    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(2, 2)
    );

    room_change_floor_at(
        room_2_1,
        FLOOR__EXT_BRIDGE_SOURCE_OFF_VERTICAL,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_2_1,
        FLOOR__LAVA,
        vec2i(1, 0)
    );

    room_change_floor_at(
        room_2_1,
        FLOOR__METAL_PISTON,
        vec2i(5, 4)
    );

    // walls

    List* room_2_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_2_1_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_new_list_element_to_list_end(
        room_2_1_wall_exclude_pos_list,
        new_vec2i(9, 7)
    );
    add_walls_around_room(
        room_2_1,
        OBJECT__WALL_METAL,
        room_2_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_2_1_wall_exclude_pos_list, 1);
    destroy_list(room_2_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_2_1,
        new_object(OBJECT__STATION_MINIBOT_TORSO),
        vec2i(1, 8)
    );

    room_add_object_at(
        room_2_1,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(3, 8)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__VENDING_DYNAMITE),
        vec2i(3, 7)
    );

    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 9)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 8)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 3)
    );

    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 3)
    );

    room_add_object_at(
        room_2_1,
        new_object(OBJECT__EXIT_METAL_UP),
        vec2i(6, 9)
    );
    room_add_object_at(
        room_2_1,
        new_object(OBJECT__EXIT_METAL_LEFT),
        vec2i(9, 7)
    );

    // passages

    add_passage(state, new_passage(
        "2_1",
        "3_1",
        vec2i(6, 9),
        vec2i(6, 1)
    ));
    add_passage(state, new_passage(
        "2_1",
        "2_2",
        vec2i(9, 7),
        vec2i(1, 7)
    ));

    ///////////
    // room_2_2
    ///////////

    Room* room_2_2 = new_empty_room("2_2", textures->background_metal);
    add_room(
        state,
        room_2_2
    );

    // floors

    add_floor_at_every_room_position(room_2_2, FLOOR__METAL);

    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(8, 2)
    );

    room_change_floor_at(
        room_2_2,
        FLOOR__LAVA,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__LAVA,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__LAVA,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__LAVA,
        vec2i(3, 6)
    );

    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(4, 0)
    );
    room_change_floor_at(
        room_2_2,
        FLOOR__WATER,
        vec2i(9, 2)
    );

    // walls

    List* room_2_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_2_2_wall_exclude_pos_list,
        new_vec2i(0, 7)
    );
    add_new_list_element_to_list_end(
        room_2_2_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_2_2_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_new_list_element_to_list_end(
        room_2_2_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_walls_around_room(
        room_2_2,
        OBJECT__WALL_METAL,
        room_2_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_2_2_wall_exclude_pos_list, 1);
    destroy_list(room_2_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_2_2,
        new_object(OBJECT__HARPOON_GUN_DOWN),
        vec2i(3, 1)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__HARPOON_GUN_UP),
        vec2i(3, 8)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__DISPLAY),

        vec2i(3, 7)
    );

    room_add_object_at(
        room_2_2,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(7, 1)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__DISPLAY_DAMAGED),
        vec2i(8, 1)
    );

    room_add_object_at(
        room_2_2,
        new_object(OBJECT__STATION_SCISSOR_HAND),
        vec2i(6, 6)
    );

    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 8)
    );


    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(4, 6)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(5, 6)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 8)
    );

    room_add_object_at(
        room_2_2,
        new_object(OBJECT__EXIT_METAL_RIGHT),
        vec2i(0, 7)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__EXIT_METAL_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__EXIT_METAL_DOWN),
        vec2i(4, 0)
    );
    room_add_object_at(
        room_2_2,
        new_object(OBJECT__EXIT_METAL_LEFT),
        vec2i(9, 2)
    );

    // passages

    add_passage(state, new_passage(
        "2_2",
        "2_1",
        vec2i(0, 7),
        vec2i(8, 7)
    ));
    add_passage(state, new_passage(
        "2_2",
        "3_2",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "2_2",
        "1_2",
        vec2i(4, 0),
        vec2i(4, 8)
    ));
    add_passage(state, new_passage(
        "2_2",
        "2_3",
        vec2i(9, 2),
        vec2i(1, 2)
    ));

    ///////////
    // room_2_3
    ///////////

    Room* room_2_3 = new_empty_room("2_3", textures->background_stone);
    add_room(
        state,
        room_2_3
    );

    // floors

    add_floor_at_every_room_position(room_2_3, FLOOR__STONE);

    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(6, 8)
    );

    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(0, 2)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__WATER,
        vec2i(6, 9)
    );

    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_2_3,
        FLOOR__STONE_TRAP,
        vec2i(5, 2)
    );

    // walls

    List* room_2_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_2_3_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_2_3_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_new_list_element_to_list_end(
        room_2_3_wall_exclude_pos_list,
        new_vec2i(9, 5)
    );
    add_walls_around_room(
        room_2_3,
        OBJECT__WALL_STONE,
        room_2_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_2_3_wall_exclude_pos_list, 1);
    destroy_list(room_2_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_2_3,
        new_object(OBJECT__GOLEM_UNPOWERED),
        vec2i(7, 3)
    );

    room_add_object_at(
        room_2_3,
        new_object(OBJECT__STALACTITE),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_2_3,
        new_object(OBJECT__STALACTITE),
        vec2i(4, 6)
    );

    room_add_object_at(
        room_2_3,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_2_3,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_2_3,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(2, 6)
    );

    room_add_object_at(
        room_2_3,
        new_object(OBJECT__EXIT_STONE_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_2_3,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(6, 9)
    );
    room_add_object_at(
        room_2_3,
        new_object(OBJECT__EXIT_STONE_LEFT),
        vec2i(9, 5)
    );

    // passages

    add_passage(state, new_passage(
        "2_3",
        "2_2",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "2_3",
        "3_3",
        vec2i(6, 9),
        vec2i(6, 1)
    ));
    add_passage(state, new_passage(
        "2_3",
        "2_4",
        vec2i(9, 5),
        vec2i(1, 5)
    ));

    ///////////
    // room_2_4
    ///////////

    Room* room_2_4 = new_empty_room("2_4", textures->background_stone);
    add_room(
        state,
        room_2_4
    );

    // floors

    add_floor_at_every_room_position(room_2_4, FLOOR__STONE);

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 1)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 2)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(8, 3)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(8, 4)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(8, 5)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(8, 6)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 7)
    );

    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_2_4,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 8)
    );

    // walls

    List* room_2_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_2_4_wall_exclude_pos_list,
        new_vec2i(0, 5)
    );
    add_new_list_element_to_list_end(
        room_2_4_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_2_4_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_walls_around_room(
        room_2_4,
        OBJECT__WALL_STONE,
        room_2_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_2_4_wall_exclude_pos_list, 1);
    destroy_list(room_2_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_2_4,
        new_object(OBJECT__TURRET_BOMB_STANDING),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__TURRET_BOMB_STANDING),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__TURRET_BOMB_STANDING),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__TURRET_BOMB_STANDING),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_2_4,
        new_object(OBJECT__SARCOPHAGUS),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__SARCOPHAGUS),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__SARCOPHAGUS),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__SARCOPHAGUS),
        vec2i(5, 7)
    );

    room_add_object_at(
        room_2_4,
        new_object(OBJECT__EXIT_STONE_RIGHT),
        vec2i(0, 5)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_2_4,
        new_object(OBJECT__EXIT_STONE_LEFT),
        vec2i(9, 2)
    );

    // passages

    add_passage(state, new_passage(
        "2_4",
        "2_3",
        vec2i(0, 5),
        vec2i(8, 5)
    ));
    add_passage(state, new_passage(
        "2_4",
        "3_4",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "2_4",
        "2_5",
        vec2i(9, 2),
        vec2i(1, 2)
    ));

    ///////////
    // room_2_5
    ///////////

    Room* room_2_5 = new_empty_room("2_5", textures->background_marble);
    add_room(
        state,
        room_2_5
    );

    // floors

    add_floor_at_every_room_position(room_2_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(8, 8)
    );

    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(7, 6)
    );

    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(6, 4)
    );

    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_2_5,
        FLOOR__WATER,
        vec2i(5, 2)
    );

    // walls

    List* room_2_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_2_5_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_2_5_wall_exclude_pos_list,
        new_vec2i(7, 0)
    );
    add_walls_around_room(
        room_2_5,
        OBJECT__WALL_MARBLE,
        room_2_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_2_5_wall_exclude_pos_list, 1);
    destroy_list(room_2_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_2_5,
        new_object(OBJECT__SAFE_DAMAGED_ITEM),
        vec2i(2, 7)
    );

    room_add_object_at(
        room_2_5,
        new_object(OBJECT__STALACTITE),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__STALACTITE),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__STALACTITE),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__STALACTITE),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__STALACTITE),
        vec2i(7, 6)
    );

    room_add_object_at(
        room_2_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__EXIT_MARBLE_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(7, 0)
    );

    // enemies

    room_add_object_at(
        room_2_5,
        new_object(OBJECT__FLY),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_2_5,
        new_object(OBJECT__FLY),
        vec2i(4, 5)
    );

    // passages

    add_passage(state, new_passage(
        "2_5",
        "2_4",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "2_5",
        "1_5",
        vec2i(7, 0),
        vec2i(7, 8)
    ));

    ///////////
    // room_3_0
    ///////////

    Room* room_3_0 = new_empty_room("3_0", textures->background_obsidian);
    add_room(
        state,
        room_3_0
    );

    // floors

    add_floor_at_every_room_position(room_3_0, FLOOR__OBSIDIAN);

    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_3_0,
        FLOOR__COINS,
        vec2i(5, 3)
    );

    // walls

    List* room_3_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_3_0_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_3_0_wall_exclude_pos_list,
        new_vec2i(7, 0)
    );
    add_new_list_element_to_list_end(
        room_3_0_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_3_0_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_walls_around_room(
        room_3_0,
        OBJECT__WALL_OBSIDIAN,
        room_3_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_3_0_wall_exclude_pos_list, 1);
    destroy_list(room_3_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__STATION_SPRING_LEG),
        vec2i(8, 4)
    );

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 3)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(8, 3)
    );

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 8)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 7)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 7)
    );

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 2)
    );

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 3)
    );

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(7, 0)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_3_0,
        new_object(OBJECT__EXIT_OBSIDIAN_LEFT),
        vec2i(9, 2)
    );

    // enemies

    room_add_object_at(
        room_3_0,
        new_object(OBJECT__ENVIRONMENT_COLLAPSE_BURROW),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "3_0",
        "2_0",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "3_0",
        "2_0",
        vec2i(7, 0),
        vec2i(7, 8)
    ));
    add_passage(state, new_passage(
        "3_0",
        "4_0",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "3_0",
        "3_1",
        vec2i(9, 2),
        vec2i(1, 2)
    ));

    ///////////
    // room_3_1
    ///////////

    Room* room_3_1 = new_empty_room("3_1", textures->background_metal);
    add_room(
        state,
        room_3_1
    );

    // floors

    add_floor_at_every_room_position(room_3_1, FLOOR__METAL);

    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 8)
    );

    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 8)
    );

    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 0)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_3_1,
        FLOOR__LAVA,
        vec2i(4, 9)
    );

    room_change_floor_at(
        room_3_1,
        FLOOR__METAL_PISTON_CELL,
        vec2i(7, 3)
    );

    // walls

    List* room_3_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_3_1_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_3_1_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_new_list_element_to_list_end(
        room_3_1_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_walls_around_room(
        room_3_1,
        OBJECT__WALL_METAL,
        room_3_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_3_1_wall_exclude_pos_list, 1);
    destroy_list(room_3_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_3_1,
        new_object(OBJECT__VENDING_CELL_DAMAGED),
        vec2i(7, 3)
    );

    room_add_object_at(
        room_3_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_3_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_3_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 6)
    );

    room_add_object_at(
        room_3_1,
        new_object(OBJECT__EXIT_METAL_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_3_1,
        new_object(OBJECT__EXIT_METAL_DOWN),
        vec2i(6, 0)
    );
    room_add_object_at(
        room_3_1,
        new_object(OBJECT__EXIT_METAL_UP),
        vec2i(6, 9)
    );

    // passages

    add_passage(state, new_passage(
        "3_1",
        "3_0",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "3_1",
        "2_1",
        vec2i(6, 0),
        vec2i(6, 8)
    ));
    add_passage(state, new_passage(
        "3_1",
        "4_1",
        vec2i(6, 9),
        vec2i(6, 1)
    ));

    ///////////
    // room_3_2
    ///////////

    Room* room_3_2 = new_empty_room("3_2", textures->background_metal);
    add_room(
        state,
        room_3_2
    );

    // floors

    add_floor_at_every_room_position(room_3_2, FLOOR__METAL);

    room_change_floor_at(
        room_3_2,
        FLOOR__LAVA,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_3_2,
        FLOOR__LAVA,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_3_2,
        FLOOR__LAVA,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_3_2,
        FLOOR__LAVA,
        vec2i(5, 5)
    );

    // walls

    List* room_3_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_3_2_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_walls_around_room(
        room_3_2,
        OBJECT__WALL_METAL,
        room_3_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_3_2_wall_exclude_pos_list, 1);
    destroy_list(room_3_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_3_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(3, 2)
    );

    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(2, 5)
    );

    room_add_object_at(
        room_3_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 6)
    );

    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_3_2,
        new_object(OBJECT__CRATE_CELL),
        vec2i(4, 7)
    );

    room_add_object_at(
        room_3_2,
        new_object(OBJECT__EXIT_METAL_DOWN),
        vec2i(5, 0)
    );

    // passages

    add_passage(state, new_passage(
        "3_2",
        "2_2",
        vec2i(5, 0),
        vec2i(5, 8)
    ));

    ///////////
    // room_3_3
    ///////////

    Room* room_3_3 = new_empty_room("3_3", textures->background_stone);
    add_room(
        state,
        room_3_3
    );

    // floors

    add_floor_at_every_room_position(room_3_3, FLOOR__STONE);

    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(2, 9)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__WATER,
        vec2i(6, 0)
    );

    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(1, 3)
    );

    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_3_3,
        FLOOR__PIT,
        vec2i(6, 8)
    );

    // walls

    List* room_3_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_3_3_wall_exclude_pos_list,
        new_vec2i(2, 9)
    );
    add_new_list_element_to_list_end(
        room_3_3_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_walls_around_room(
        room_3_3,
        OBJECT__WALL_STONE,
        room_3_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_3_3_wall_exclude_pos_list, 1);
    destroy_list(room_3_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_3_3,
        new_object(OBJECT__STATION_FIST_HAND),
        vec2i(8, 8)
    );

    room_add_object_at(
        room_3_3,
        new_object(OBJECT__COLUMN),
        vec2i(7, 6)
    );

    room_add_object_at(
        room_3_3,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(1, 1)
    );
    room_add_object_at(
        room_3_3,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(1, 2)
    );

    room_add_object_at(
        room_3_3,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(2, 9)
    );
    room_add_object_at(
        room_3_3,
        new_object(OBJECT__EXIT_STONE_DOWN),
        vec2i(6, 0)
    );

    // passages

    add_passage(state, new_passage(
        "3_3",
        "4_3",
        vec2i(2, 9),
        vec2i(2, 1)
    ));
    add_passage(state, new_passage(
        "3_3",
        "2_3",
        vec2i(6, 0),
        vec2i(6, 8)
    ));

    ///////////
    // room_3_4
    ///////////

    Room* room_3_4 = new_empty_room("3_4", textures->background_stone);
    add_room(
        state,
        room_3_4
    );

    // floors

    add_floor_at_every_room_position(room_3_4, FLOOR__STONE);

    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(2, 1)
    );

    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(7, 8)
    );

    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(1, 7)
    );

    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_3_4,
        FLOOR__PIT,
        vec2i(8, 2)
    );

    // walls

    List* room_3_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_3_4_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_3_4_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_walls_around_room(
        room_3_4,
        OBJECT__WALL_STONE,
        room_3_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_3_4_wall_exclude_pos_list, 1);
    destroy_list(room_3_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(3, 1)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(1, 3)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(8, 3)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(6, 8)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(8, 6)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(3, 8)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(1, 6)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(7, 6)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(2, 3)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 4)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 5)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(5, 8)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(1, 5)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__BARREL),
        vec2i(1, 4)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__TURRET_PROJECTILE_GROUNDED),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__TURRET_PROJECTILE_GROUNDED),
        vec2i(5, 5)
    );

    room_add_object_at(
        room_3_4,
        new_object(OBJECT__EXIT_STONE_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_3_4,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(4, 9)
    );

    // passages

    add_passage(state, new_passage(
        "3_4",
        "2_4",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "3_4",
        "4_4",
        vec2i(4, 9),
        vec2i(4, 1)
    ));

    ///////////
    // room_3_5
    ///////////

    Room* room_3_5 = new_empty_room("3_5", textures->background_marble);
    add_room(
        state,
        room_3_5
    );

    // floors

    add_floor_at_every_room_position(room_3_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 9)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_3_5,
        FLOOR__WATER,
        vec2i(8, 0)
    );

    // walls

    List* room_3_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_3_5_wall_exclude_pos_list,
        new_vec2i(8, 9)
    );
    add_walls_around_room(
        room_3_5,
        OBJECT__WALL_MARBLE,
        room_3_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_3_5_wall_exclude_pos_list, 1);
    destroy_list(room_3_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE),
        vec2i(5, 6)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__CRATE_GEMSTONE_ITEM),
        vec2i(6, 5)
    );

    room_add_object_at(
        room_3_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_3_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(5, 5)
    );

    room_add_object_at(
        room_3_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(8, 9)
    );

    // passages

    add_passage(state, new_passage(
        "3_5",
        "4_5",
        vec2i(8, 9),
        vec2i(8, 1)
    ));

    ///////////
    // room_4_0
    ///////////

    Room* room_4_0 = new_empty_room("4_0", textures->background_obsidian);
    add_room(
        state,
        room_4_0
    );

    // floors

    add_floor_at_every_room_position(room_4_0, FLOOR__OBSIDIAN);

    room_change_floor_at(
        room_4_0,
        FLOOR__METAL_TARGET_UNCHECKED,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_4_0,
        FLOOR__METAL_TARGET_UNCHECKED,
        vec2i(2, 7)
    );

    room_change_floor_at(
        room_4_0,
        FLOOR__OBSTACLE,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_4_0,
        FLOOR__OBSTACLE,
        vec2i(5, 5)
    );

    // walls

    List* room_4_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_4_0_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_4_0_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_walls_around_room(
        room_4_0,
        OBJECT__WALL_OBSIDIAN,
        room_4_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_4_0_wall_exclude_pos_list, 1);
    destroy_list(room_4_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(1, 5)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(8, 5)
    );

    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 2)
    );

    room_add_object_at(
        room_4_0,
        new_object(OBJECT__OBSTACLE),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__OBSTACLE),
        vec2i(5, 5)
    );

    room_add_object_at(
        room_4_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(4, 9)
    );

    // enemies

    room_add_object_at(
        room_4_0,
        new_object(OBJECT__TURRET_LASER_UNDEPLOYED),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_4_0,
        new_object(OBJECT__BULL),
        vec2i(7, 3)
    );

    // passages

    add_passage(state, new_passage(
        "4_0",
        "3_0",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "4_0",
        "5_0",
        vec2i(4, 9),
        vec2i(4, 1)
    ));

    ///////////
    // room_4_1
    ///////////

    Room* room_4_1 = new_empty_room("4_1", textures->background_metal);
    add_room(
        state,
        room_4_1
    );

    // floors

    add_floor_at_every_room_position(room_4_1, FLOOR__METAL);

    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(4, 0)
    );

    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(5, 0)
    );

    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(6, 3)
    );

    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(7, 9)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(7, 5)
    );

    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(8, 9)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_4_1,
        FLOOR__LAVA,
        vec2i(8, 7)
    );

    // walls

    List* room_4_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_4_1_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_new_list_element_to_list_end(
        room_4_1_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_new_list_element_to_list_end(
        room_4_1_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_walls_around_room(
        room_4_1,
        OBJECT__WALL_METAL,
        room_4_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_4_1_wall_exclude_pos_list, 1);
    destroy_list(room_4_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_4_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_4_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_4_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 6)
    );

    room_add_object_at(
        room_4_1,
        new_object(OBJECT__PIPE),
        vec2i(2, 1)
    );
    room_add_object_at(
        room_4_1,
        new_object(OBJECT__PIPE),
        vec2i(7, 1)
    );

    room_add_object_at(
        room_4_1,
        new_object(OBJECT__EXIT_METAL_DOWN),
        vec2i(6, 0)
    );
    room_add_object_at(
        room_4_1,
        new_object(OBJECT__EXIT_METAL_LEFT),
        vec2i(9, 2)
    );
    room_add_object_at(
        room_4_1,
        new_object(OBJECT__EXIT_METAL_BLOCKED_UP),
        vec2i(5, 9)
    );

    // enemies

    room_add_object_at(
        room_4_1,
        new_object(OBJECT__MINIBOT_ENEMY),
        vec2i(2, 4)
    );

    room_add_object_at(
        room_4_1,
        new_object(OBJECT__ENVIRONMENT_EMERGE_PIPE),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "4_1",
        "3_1",
        vec2i(6, 0),
        vec2i(6, 8)
    ));
    add_passage(state, new_passage(
        "4_1",
        "4_2",
        vec2i(9, 2),
        vec2i(1, 2)
    ));
    add_passage(state, new_passage(
        "4_1",
        "5_1",
        vec2i(5, 9),
        vec2i(5, 1)
    ));

    ///////////
    // room_4_2
    ///////////

    Room* room_4_2 = new_empty_room("4_2", textures->background_metal);
    add_room(
        state,
        room_4_2
    );

    // floors

    add_floor_at_every_room_position(room_4_2, FLOOR__METAL);

    for(int i = 2; i <= 7; i++)
    {
        for(int j = 2; j <= 7; j++)
        {
            room_change_floor_at(
                room_4_2,
                FLOOR__LAVA,
                vec2i(i, j)
            );
        }
    }

    room_change_floor_at(
        room_4_2,
        FLOOR__METAL,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_4_2,
        FLOOR__METAL,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_4_2,
        FLOOR__METAL,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_4_2,
        FLOOR__METAL,
        vec2i(5, 5)
    );

    // walls

    List* room_4_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_4_2_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_4_2_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_walls_around_room(
        room_4_2,
        OBJECT__WALL_METAL,
        room_4_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_4_2_wall_exclude_pos_list, 1);
    destroy_list(room_4_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_4_2,
        new_object(OBJECT__COLUMN),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__COLUMN),
        vec2i(5, 5)
    );

    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(4, 7)
    );

    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 4)
    );

    room_add_object_at(
        room_4_2,
        new_object(OBJECT__EXIT_METAL_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_4_2,
        new_object(OBJECT__EXIT_METAL_UP),
        vec2i(6, 9)
    );

    // passages

    add_passage(state, new_passage(
        "4_2",
        "4_1",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "4_2",
        "5_2",
        vec2i(6, 9),
        vec2i(6, 1)
    ));

    ///////////
    // room_4_3
    ///////////

    Room* room_4_3 = new_empty_room("4_3", textures->background_stone);
    add_room(
        state,
        room_4_3
    );

    // floors

    add_floor_at_every_room_position(room_4_3, FLOOR__STONE);

    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(8, 7)
    );

    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(2, 0)
    );
    room_change_floor_at(
        room_4_3,
        FLOOR__WATER,
        vec2i(9, 7)
    );

    // walls

    List* room_4_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_4_3_wall_exclude_pos_list,
        new_vec2i(2, 0)
    );
    add_new_list_element_to_list_end(
        room_4_3_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_new_list_element_to_list_end(
        room_4_3_wall_exclude_pos_list,
        new_vec2i(9, 7)
    );
    add_walls_around_room(
        room_4_3,
        OBJECT__WALL_STONE,
        room_4_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_4_3_wall_exclude_pos_list, 1);
    destroy_list(room_4_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_4_3,
        new_object(OBJECT__STATION_TRACK_LEG),
        vec2i(6, 2)
    );

    room_add_object_at(
        room_4_3,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_4_3,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_4_3,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 6)
    );
    room_add_object_at(
        room_4_3,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_4_3,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 8)
    );

    room_add_object_at(
        room_4_3,
        new_object(OBJECT__VENDING_DYNAMITE),
        vec2i(2, 3)
    );

    room_add_object_at(
        room_4_3,
        new_object(OBJECT__EXIT_STONE_DOWN),
        vec2i(2, 0)
    );
    room_add_object_at(
        room_4_3,
        new_object(OBJECT__EXIT_STONE_BLOCKED_UP),
        vec2i(4, 9)
    );
    room_add_object_at(
        room_4_3,
        new_object(OBJECT__EXIT_STONE_LEFT),
        vec2i(9, 7)
    );

    // enemies

    room_add_object_at(
        room_4_3,
        new_object(OBJECT__TURRET_LASER_STANDING),
        vec2i(2, 6)
    );

    // passages

    add_passage(state, new_passage(
        "4_3",
        "3_3",
        vec2i(2, 0),
        vec2i(2, 8)
    ));
    add_passage(state, new_passage(
        "4_3",
        "5_3",
        vec2i(4, 9),
        vec2i(4, 1)
    ));
    add_passage(state, new_passage(
        "4_3",
        "4_4",
        vec2i(9, 7),
        vec2i(1, 7)
    ));

    ///////////
    // room_4_4
    ///////////

    Room* room_4_4 = new_empty_room("4_4", textures->background_stone);
    add_room(
        state,
        room_4_4
    );

    // floors

    add_floor_at_every_room_position(room_4_4, FLOOR__STONE);

    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(8, 4)
    );

    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(2, 4)
    );

    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(8, 2)
    );

    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(6, 4)
    );

    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(0, 7)
    );
    room_change_floor_at(
        room_4_4,
        FLOOR__WATER,
        vec2i(9, 4)
    );

    // walls

    List* room_4_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_4_4_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_new_list_element_to_list_end(
        room_4_4_wall_exclude_pos_list,
        new_vec2i(0, 7)
    );
    add_new_list_element_to_list_end(
        room_4_4_wall_exclude_pos_list,
        new_vec2i(5, 9)
    );
    add_new_list_element_to_list_end(
        room_4_4_wall_exclude_pos_list,
        new_vec2i(9, 4)
    );
    add_walls_around_room(
        room_4_4,
        OBJECT__WALL_STONE,
        room_4_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_4_4_wall_exclude_pos_list, 1);
    destroy_list(room_4_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_4_4,
        new_object(OBJECT__EXIT_STONE_DOWN),
        vec2i(4, 0)
    );
    room_add_object_at(
        room_4_4,
        new_object(OBJECT__EXIT_STONE_RIGHT),
        vec2i(0, 7)
    );
    room_add_object_at(
        room_4_4,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(5, 9)
    );
    room_add_object_at(
        room_4_4,
        new_object(OBJECT__EXIT_STONE_LEFT),
        vec2i(9, 4)
    );

    // enemies

    room_add_object_at(
        room_4_4,
        new_object(OBJECT__SQUID),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_4_4,
        new_object(OBJECT__SQUID),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_4_4,
        new_object(OBJECT__SQUID),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_4_4,
        new_object(OBJECT__SQUID),
        vec2i(6, 5)
    );

    // passages

    add_passage(state, new_passage(
        "4_4",
        "3_4",
        vec2i(4, 0),
        vec2i(4, 8)
    ));
    add_passage(state, new_passage(
        "4_4",
        "4_3",
        vec2i(0, 7),
        vec2i(8, 7)
    ));
    add_passage(state, new_passage(
        "4_4",
        "5_4",
        vec2i(5, 9),
        vec2i(5, 1)
    ));
    add_passage(state, new_passage(
        "4_4",
        "4_5",
        vec2i(9, 4),
        vec2i(1, 4)
    ));

    ///////////
    // room_4_5
    ///////////

    Room* room_4_5 = new_empty_room("4_5", textures->background_marble);
    add_room(
        state,
        room_4_5
    );

    // floors

    add_floor_at_every_room_position(room_4_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(0, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(3, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(5, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(6, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__WATER,
        vec2i(8, 0)
    );

    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 4)
    );

    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 5)
    );

    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 6)
    );

    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__ROCK_CRACK_PIT,
        vec2i(7, 3)
    );

    room_change_floor_at(
        room_4_5,
        FLOOR__PIT,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__PIT,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__PIT,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__PIT,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__PIT,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_4_5,
        FLOOR__PIT,
        vec2i(8, 3)
    );

    // walls

    List* room_4_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_4_5_wall_exclude_pos_list,
        new_vec2i(0, 4)
    );
    add_new_list_element_to_list_end(
        room_4_5_wall_exclude_pos_list,
        new_vec2i(8, 0)
    );
    add_new_list_element_to_list_end(
        room_4_5_wall_exclude_pos_list,
        new_vec2i(2, 9)
    );
    add_walls_around_room(
        room_4_5,
        OBJECT__WALL_MARBLE,
        room_4_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_4_5_wall_exclude_pos_list, 1);
    destroy_list(room_4_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_4_5,
        new_object(OBJECT__STALAGMITE),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__STALAGMITE),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__STALAGMITE),
        vec2i(5, 5)
    );

    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(1, 5)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(3, 8)
    );

    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(6, 3)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(6, 6)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(6, 7)
    );

    room_add_object_at(
        room_4_5,
        new_object(OBJECT__STATION_STRIDER_LEG),
        vec2i(2, 2)
    );

    room_add_object_at(
        room_4_5,
        new_object(OBJECT__EXIT_MARBLE_RIGHT),
        vec2i(0, 4)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(8, 0)
    );
    room_add_object_at(
        room_4_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(2, 9)
    );

    // passages

    add_passage(state, new_passage(
        "4_5",
        "4_4",
        vec2i(0, 4),
        vec2i(8, 4)
    ));
    add_passage(state, new_passage(
        "4_5",
        "3_5",
        vec2i(8, 0),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "4_5",
        "5_5",
        vec2i(2, 9),
        vec2i(2, 1)
    ));

    ///////////
    // room_5_0
    ///////////

    Room* room_5_0 = new_empty_room("5_0", textures->background_obsidian);
    add_room(
        state,
        room_5_0
    );

    // floors

    add_floor_at_every_room_position(room_5_0, FLOOR__OBSIDIAN);

    room_change_floor_at(
        room_5_0,
        FLOOR__CONV_BELT_RIGHT,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_5_0,
        FLOOR__LAVA,
        vec2i(3, 2)
    );

    room_change_floor_at(
        room_5_0,
        FLOOR__CONV_BELT_RIGHT,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_5_0,
        FLOOR__LAVA,
        vec2i(3, 4)
    );

    room_change_floor_at(
        room_5_0,
        FLOOR__CONV_BELT_RIGHT,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_5_0,
        FLOOR__LAVA,
        vec2i(3, 6)
    );

    // walls

    List* room_5_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_5_0_wall_exclude_pos_list,
        new_vec2i(3, 9)
    );
    add_new_list_element_to_list_end(
        room_5_0_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_new_list_element_to_list_end(
        room_5_0_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_walls_around_room(
        room_5_0,
        OBJECT__WALL_OBSIDIAN,
        room_5_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_5_0_wall_exclude_pos_list, 1);
    destroy_list(room_5_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_5_0,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(2, 4)
    );

    room_add_object_at(
        room_5_0,
        new_object(OBJECT__ENVIRONMENT_CONV_BELT),
        vec2i(-1, -1)
    );

    room_add_object_at(
        room_5_0,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(7, 2)
    );

    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 8)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 6)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 5)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(8, 5)
    );

    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXT_WALL_PART_VERTICAL),
        vec2i(5, 1)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXT_WALL_SOURCE_ON_VERTICAL),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXT_WALL_PART_VERTICAL),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXT_WALL_PART_VERTICAL),
        vec2i(5, 4)
    );

    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(3, 9)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(6, 9)
    );
    room_add_object_at(
        room_5_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(4, 0)
    );

    // passages

    add_passage(state, new_passage(
        "5_0",
        "6_0",
        vec2i(3, 9),
        vec2i(3, 1)
    ));
    add_passage(state, new_passage(
        "5_0",
        "6_0",
        vec2i(6, 9),
        vec2i(6, 1)
    ));
    add_passage(state, new_passage(
        "5_0",
        "4_0",
        vec2i(4, 0),
        vec2i(4, 8)
    ));

    ///////////
    // room_5_1
    ///////////

    Room* room_5_1 = new_empty_room("5_1", textures->background_metal);
    add_room(
        state,
        room_5_1
    );

    // floors

    add_floor_at_every_room_position(room_5_1, FLOOR__METAL);

    room_change_floor_at(
        room_5_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__METAL_SPIKES_ON,
        vec2i(6, 6)
    );

    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(7, 0)
    );

    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 9)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA,
        vec2i(8, 0)
    );

    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA_COLUMN,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_5_1,
        FLOOR__LAVA_COLUMN,
        vec2i(8, 4)
    );

    // walls

    List* room_5_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_5_1_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_5_1_wall_exclude_pos_list,
        new_vec2i(3, 9)
    );
    add_walls_around_room(
        room_5_1,
        OBJECT__WALL_METAL,
        room_5_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_5_1_wall_exclude_pos_list, 1);
    destroy_list(room_5_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_5_1,
        new_object(OBJECT__DISPLAY),
        vec2i(3, 3)
    );

    room_add_object_at(
        room_5_1,
        new_object(OBJECT__COLUMN),
        vec2i(6, 4)
    );

    room_add_object_at(
        room_5_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 3)
    );
    room_add_object_at(
        room_5_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_5_1,
        new_object(OBJECT__WALL_METAL),
        vec2i(3, 2)
    );

    room_add_object_at(
        room_5_1,
        new_object(OBJECT__EXIT_METAL_BLOCKED_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_5_1,
        new_object(OBJECT__EXIT_METAL_UP),
        vec2i(3, 9)
    );

    // passages

    add_passage(state, new_passage(
        "5_1",
        "4_1",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "5_1",
        "6_1",
        vec2i(3, 9),
        vec2i(3, 1)
    ));

    ///////////
    // room_5_2
    ///////////

    Room* room_5_2 = new_empty_room("5_2", textures->background_metal);
    add_room(
        state,
        room_5_2
    );

    // floors

    add_floor_at_every_room_position(room_5_2, FLOOR__METAL);

    for(int i = 2; i <= 4; i++)
    {
        for(int j = 5; j <= 7; j++)
        {
            room_change_floor_at(
                room_5_2,
                FLOOR__LAVA,
                vec2i(i, j)
            );
        }
    }

    for(int i = 5; i <= 7; i++)
    {
        for(int j = 2; j <= 4; j++)
        {
            room_change_floor_at(
                room_5_2,
                FLOOR__LAVA,
                vec2i(i, j)
            );
        }
    }

    room_change_floor_at(
        room_5_2,
        FLOOR__METAL,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_5_2,
        FLOOR__METAL,
        vec2i(6, 3)
    );

    // walls

    List* room_5_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_5_2_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_new_list_element_to_list_end(
        room_5_2_wall_exclude_pos_list,
        new_vec2i(9, 3)
    );
    add_walls_around_room(
        room_5_2,
        OBJECT__WALL_METAL,
        room_5_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_5_2_wall_exclude_pos_list, 1);
    destroy_list(room_5_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_5_2,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(3, 6)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(6, 3)
    );

    room_add_object_at(
        room_5_2,
        new_object(OBJECT__COLUMN),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__COLUMN),
        vec2i(6, 5)
    );

    room_add_object_at(
        room_5_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(2, 3)
    );

    room_add_object_at(
        room_5_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 7)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__WALL_METAL),
        vec2i(7, 6)
    );

    room_add_object_at(
        room_5_2,
        new_object(OBJECT__EXIT_METAL_DOWN),
        vec2i(6, 0)
    );
    room_add_object_at(
        room_5_2,
        new_object(OBJECT__EXIT_METAL_LEFT),
        vec2i(9, 3)
    );

    // passages

    add_passage(state, new_passage(
        "5_2",
        "4_2",
        vec2i(6, 0),
        vec2i(6, 8)
    ));
    add_passage(state, new_passage(
        "5_2",
        "5_3",
        vec2i(9, 3),
        vec2i(1, 3)
    ));

    ///////////
    // room_5_3
    ///////////

    Room* room_5_3 = new_empty_room("5_3", textures->background_stone);
    add_room(
        state,
        room_5_3
    );

    // floors

    add_floor_at_every_room_position(room_5_3, FLOOR__STONE);

    room_change_floor_at(
        room_5_3,
        FLOOR__WATER,
        vec2i(7, 9)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__WATER,
        vec2i(9, 7)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__WATER,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__WATER,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__WATER,
        vec2i(8, 7)
    );

    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_CLOSED,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_CLOSED,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_5_3,
        FLOOR__METAL_HATCH_OPEN,
        vec2i(7, 1)
    );

    // walls

    List* room_5_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_5_3_wall_exclude_pos_list,
        new_vec2i(0, 3)
    );
    add_new_list_element_to_list_end(
        room_5_3_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_new_list_element_to_list_end(
        room_5_3_wall_exclude_pos_list,
        new_vec2i(8, 9)
    );
    add_new_list_element_to_list_end(
        room_5_3_wall_exclude_pos_list,
        new_vec2i(9, 8)
    );
    add_walls_around_room(
        room_5_3,
        OBJECT__WALL_STONE,
        room_5_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_5_3_wall_exclude_pos_list, 1);
    destroy_list(room_5_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_5_3,
        new_object(OBJECT__PILLAR),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__PILLAR),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__PILLAR),
        vec2i(4, 7)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__PILLAR),
        vec2i(5, 7)
    );

    room_add_object_at(
        room_5_3,
        new_object(OBJECT__DISPLAY),
        vec2i(1, 1)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__DISPLAY),
        vec2i(1, 2)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__DISPLAY),
        vec2i(8, 1)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__DISPLAY),
        vec2i(8, 2)
    );

    room_add_object_at(
        room_5_3,
        new_object(OBJECT__EXIT_STONE_RIGHT),
        vec2i(0, 3)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__EXIT_STONE_BLOCKED_DOWN),
        vec2i(4, 0)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(8, 9)
    );
    room_add_object_at(
        room_5_3,
        new_object(OBJECT__EXIT_STONE_LEFT),
        vec2i(9, 8)
    );

    // enemies

    room_add_object_at(
        room_5_3,
        new_object(OBJECT__CHAMELEON),
        vec2i(4, 4)
    );

    // passages

    add_passage(state, new_passage(
        "5_3",
        "5_2",
        vec2i(0, 3),
        vec2i(8, 3)
    ));
    add_passage(state, new_passage(
        "5_3",
        "4_3",
        vec2i(4, 0),
        vec2i(4, 8)
    ));
    add_passage(state, new_passage(
        "5_3",
        "6_3",
        vec2i(8, 9),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "5_3",
        "5_4",
        vec2i(9, 8),
        vec2i(1, 8)
    ));

    ///////////
    // room_5_4
    ///////////

    Room* room_5_4 = new_empty_room("5_4", textures->background_stone);
    add_room(
        state,
        room_5_4
    );

    // floors

    add_floor_at_every_room_position(room_5_4, FLOOR__STONE);

    room_change_floor_at(
        room_5_4,
        FLOOR__WATER,
        vec2i(0, 7)
    );
    room_change_floor_at(
        room_5_4,
        FLOOR__WATER,
        vec2i(2, 9)
    );
    room_change_floor_at(
        room_5_4,
        FLOOR__WATER,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_5_4,
        FLOOR__WATER,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_5_4,
        FLOOR__WATER,
        vec2i(2, 8)
    );

    // walls

    List* room_5_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_5_4_wall_exclude_pos_list,
        new_vec2i(5, 0)
    );
    add_new_list_element_to_list_end(
        room_5_4_wall_exclude_pos_list,
        new_vec2i(9, 2)
    );
    add_new_list_element_to_list_end(
        room_5_4_wall_exclude_pos_list,
        new_vec2i(0, 8)
    );
    add_new_list_element_to_list_end(
        room_5_4_wall_exclude_pos_list,
        new_vec2i(1, 9)
    );
    add_walls_around_room(
        room_5_4,
        OBJECT__WALL_STONE,
        room_5_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_5_4_wall_exclude_pos_list, 1);
    destroy_list(room_5_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 6)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 7)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(4, 8)
    );

    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 4)
    );

    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(1, 3)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(1, 2)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(1, 1)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(2, 1)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(3, 1)
    );

    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(5, 8)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(6, 8)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(7, 8)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 8)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 7)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 6)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__BARREL),
        vec2i(8, 5)
    );

    room_add_object_at(
        room_5_4,
        new_object(OBJECT__EXIT_STONE_DOWN),
        vec2i(5, 0)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__EXIT_STONE_LEFT),
        vec2i(9, 2)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__EXIT_STONE_RIGHT),
        vec2i(0, 8)
    );
    room_add_object_at(
        room_5_4,
        new_object(OBJECT__EXIT_STONE_UP),
        vec2i(1, 9)
    );

    // passages

    add_passage(state, new_passage(
        "5_4",
        "4_4",
        vec2i(5, 0),
        vec2i(5, 8)
    ));
    add_passage(state, new_passage(
        "5_4",
        "5_5",
        vec2i(9, 2),
        vec2i(1, 2)
    ));
    add_passage(state, new_passage(
        "5_4",
        "5_3",
        vec2i(0, 8),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "5_4",
        "6_4",
        vec2i(1, 9),
        vec2i(1, 1)
    ));

    ///////////
    // room_5_5
    ///////////

    Room* room_5_5 = new_empty_room("5_5", textures->background_marble);
    add_room(
        state,
        room_5_5
    );

    // floors

    add_floor_at_every_room_position(room_5_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(5, 7)
    );

    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(6, 8)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(6, 5)
    );

    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(7, 3)
    );

    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_5_5,
        FLOOR__PIT,
        vec2i(8, 1)
    );

    // walls

    List* room_5_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_5_5_wall_exclude_pos_list,
        new_vec2i(0, 2)
    );
    add_new_list_element_to_list_end(
        room_5_5_wall_exclude_pos_list,
        new_vec2i(2, 0)
    );
    add_new_list_element_to_list_end(
        room_5_5_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_new_list_element_to_list_end(
        room_5_5_wall_exclude_pos_list,
        new_vec2i(8, 9)
    );
    add_walls_around_room(
        room_5_5,
        OBJECT__WALL_MARBLE,
        room_5_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_5_5_wall_exclude_pos_list, 1);
    destroy_list(room_5_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_5_5,
        new_object(OBJECT__STATION_WINGS_TORSO),
        vec2i(8, 7)
    );

    room_add_object_at(
        room_5_5,
        new_object(OBJECT__BARREL),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__BARREL),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__BARREL),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(6, 3)
    );

    room_add_object_at(
        room_5_5,
        new_object(OBJECT__DISPLAY),
        vec2i(1, 5)
    );

    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__WALL_MARBLE),
        vec2i(4, 1)
    );

    room_add_object_at(
        room_5_5,
        new_object(OBJECT__EXIT_MARBLE_RIGHT),
        vec2i(0, 2)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(2, 0)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(4, 9)
    );
    room_add_object_at(
        room_5_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(8, 9)
    );

    // enemies

    room_add_object_at(
        room_5_5,
        new_object(OBJECT__FLY),
        vec2i(2, 7)
    );

    // passages

    add_passage(state, new_passage(
        "5_5",
        "5_4",
        vec2i(0, 2),
        vec2i(8, 2)
    ));
    add_passage(state, new_passage(
        "5_5",
        "4_5",
        vec2i(2, 0),
        vec2i(2, 8)
    ));
    add_passage(state, new_passage(
        "5_5",
        "6_5",
        vec2i(4, 9),
        vec2i(4, 1)
    ));
    add_passage(state, new_passage(
        "5_5",
        "6_5",
        vec2i(8, 9),
        vec2i(8, 1)
    ));

    ///////////
    // room_6_0
    ///////////

    Room* room_6_0 = new_empty_room("6_0", textures->background_obsidian);
    add_room(
        state,
        room_6_0
    );

    // floors

    add_floor_at_every_room_position(room_6_0, FLOOR__OBSIDIAN);

    for(int i = 1; i <= 8; i++)
    {
        room_change_floor_at(
            room_6_0,
            FLOOR__STONE_TRAP,
            vec2i(1, i)
        );
    }

    // walls

    List* room_6_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_6_0_wall_exclude_pos_list,
        new_vec2i(2, 9)
    );
    add_new_list_element_to_list_end(
        room_6_0_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_new_list_element_to_list_end(
        room_6_0_wall_exclude_pos_list,
        new_vec2i(3, 0)
    );
    add_new_list_element_to_list_end(
        room_6_0_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_new_list_element_to_list_end(
        room_6_0_wall_exclude_pos_list,
        new_vec2i(9, 3)
    );
    add_walls_around_room(
        room_6_0,
        OBJECT__WALL_OBSIDIAN,
        room_6_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_6_0_wall_exclude_pos_list, 1);
    destroy_list(room_6_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 3)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 6)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__BARREL),
        vec2i(3, 8)
    );

    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 8)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 7)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 6)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 5)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 1)
    );

    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 8)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 6)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 1)
    );

    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXT_WALL_PART_HORIZONTAL),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXT_WALL_SOURCE_ON_HORIZONTAL),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXT_WALL_PART_HORIZONTAL),
        vec2i(8, 2)
    );

    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(2, 9)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXIT_OBSIDIAN_UP),
        vec2i(6, 9)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__SQUIRREL_EXIT_OBSIDIAN_DOWN),
        vec2i(3, 0)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(6, 0)
    );
    room_add_object_at(
        room_6_0,
        new_object(OBJECT__EXIT_OBSIDIAN_LEFT),
        vec2i(9, 3)
    );

    room_add_object_at(
        room_6_0,
        new_object(OBJECT__MINIBOT_ENEMY_CELL),
        vec2i(7, 7)
    );

    // passages

    add_passage(state, new_passage(
        "6_0",
        "7_0",
        vec2i(2, 9),
        vec2i(2, 1)
    ));
    add_passage(state, new_passage(
        "6_0",
        "7_0",
        vec2i(6, 9),
        vec2i(6, 1)
    ));
    add_passage(state, new_passage(
        "6_0",
        "5_0",
        vec2i(3, 0),
        vec2i(3, 8)
    ));
    add_passage(state, new_passage(
        "6_0",
        "5_0",
        vec2i(6, 0),
        vec2i(6, 8)
    ));
    add_passage(state, new_passage(
        "6_0",
        "6_1",
        vec2i(9, 3),
        vec2i(1, 3)
    ));

    ///////////
    // room_6_1
    ///////////

    Room* room_6_1 = new_empty_room("6_1", textures->background_rock);
    add_room(
        state,
        room_6_1
    );

    // floors

    add_floor_at_every_room_position(room_6_1, FLOOR__ROCK);

    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(2, 1)
    );

    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(4, 1)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__PIT,
        vec2i(1, 1)
    );

    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 9)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__METAL_HATCH_CLOSED,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 1)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__LAVA,
        vec2i(8, 0)
    );

    room_change_floor_at(
        room_6_1,
        FLOOR__METAL_PISTON_DYNAMITE,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_6_1,
        FLOOR__METAL_PISTON_BARREL,
        vec2i(2, 7)
    );

    // walls

    List* room_6_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_6_1_wall_exclude_pos_list,
        new_vec2i(0, 3)
    );
    add_new_list_element_to_list_end(
        room_6_1_wall_exclude_pos_list,
        new_vec2i(3, 0)
    );
    add_new_list_element_to_list_end(
        room_6_1_wall_exclude_pos_list,
        new_vec2i(6, 9)
    );
    add_new_list_element_to_list_end(
        room_6_1_wall_exclude_pos_list,
        new_vec2i(9, 5)
    );
    add_walls_around_room(
        room_6_1,
        OBJECT__WALL_ROCK,
        room_6_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_6_1_wall_exclude_pos_list, 1);
    destroy_list(room_6_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_6_1,
        new_object(OBJECT__STALACTITE),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_6_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(4, 6)
    );

    room_add_object_at(
        room_6_1,
        new_object(OBJECT__EXIT_ROCK_RIGHT),
        vec2i(0, 3)
    );
    room_add_object_at(
        room_6_1,
        new_object(OBJECT__EXIT_ROCK_DOWN),
        vec2i(3, 0)
    );
    room_add_object_at(
        room_6_1,
        new_object(OBJECT__EXIT_ROCK_BLOCKED_UP),
        vec2i(6, 9)
    );
    room_add_object_at(
        room_6_1,
        new_object(OBJECT__EXIT_ROCK_LEFT),
        vec2i(9, 5)
    );

    // passages

    add_passage(state, new_passage(
        "6_1",
        "6_0",
        vec2i(0, 3),
        vec2i(8, 3)
    ));
    add_passage(state, new_passage(
        "6_1",
        "5_1",
        vec2i(3, 0),
        vec2i(3, 8)
    ));
    add_passage(state, new_passage(
        "6_1",
        "7_1",
        vec2i(6, 9),
        vec2i(6, 1)
    ));
    add_passage(state, new_passage(
        "6_1",
        "6_2",
        vec2i(9, 5),
        vec2i(1, 5)
    ));

    ///////////
    // room_6_2
    ///////////

    Room* room_6_2 = new_empty_room("6_2", textures->background_rock);
    add_room(
        state,
        room_6_2
    );

    // floors

    add_floor_at_every_room_position(room_6_2, FLOOR__ROCK);

    for(int i = 3; i <= 7; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            room_change_floor_at(
                room_6_2,
                FLOOR__SAND,
                vec2i(i, j)
            );
        }
    }

    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 9)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__METAL_HATCH_CLOSED,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_6_2,
        FLOOR__LAVA,
        vec2i(1, 0)
    );

    // walls

    List* room_6_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_6_2_wall_exclude_pos_list,
        new_vec2i(0, 5)
    );
    add_new_list_element_to_list_end(
        room_6_2_wall_exclude_pos_list,
        new_vec2i(9, 5)
    );
    add_walls_around_room(
        room_6_2,
        OBJECT__WALL_ROCK,
        room_6_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_6_2_wall_exclude_pos_list, 1);
    destroy_list(room_6_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__SIGN_MOLE_WARNING),
        vec2i(2,2)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(3, 2)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(3, 6)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(4, 1)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(4, 5)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(5, 8)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(6, 3)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(6, 7)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__BALL),
        vec2i(7, 4)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__EXIT_ROCK_RIGHT),
        vec2i(0, 5)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__EXIT_ROCK_LEFT),
        vec2i(9, 5)
    );

    // enemies

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__MOLE),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__MOLE),
        vec2i(7, 1)
    );
    room_add_object_at(
        room_6_2,
        new_object(OBJECT__MOLE),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_6_2,
        new_object(OBJECT__ENVIRONMENT_EMERGE_BURROW),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "6_2",
        "6_1",
        vec2i(0, 5),
        vec2i(8, 5)
    ));
    add_passage(state, new_passage(
        "6_2",
        "6_3",
        vec2i(9, 5),
        vec2i(1, 5)
    ));

    ///////////
    // room_6_3
    ///////////

    Room* room_6_3 = new_empty_room("6_3", textures->background_rock);
    add_room(
        state,
        room_6_3
    );

    // floors

    add_floor_at_every_room_position(room_6_3, FLOOR__ROCK);

    room_change_floor_at(
        room_6_3,
        FLOOR__WATER,
        vec2i(7, 0)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__WATER,
        vec2i(7, 1)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__WATER,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__WATER,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__WATER,
        vec2i(9, 2)
    );

    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ICE,
        vec2i(3, 6)
    );

    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_6_3,
        FLOOR__ROCK_CRACK_WATER,
        vec2i(7, 6)
    );

    // walls

    List* room_6_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_6_3_wall_exclude_pos_list,
        new_vec2i(0, 5)
    );
    add_new_list_element_to_list_end(
        room_6_3_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_new_list_element_to_list_end(
        room_6_3_wall_exclude_pos_list,
        new_vec2i(8, 0)
    );
    add_new_list_element_to_list_end(
        room_6_3_wall_exclude_pos_list,
        new_vec2i(9, 1)
    );
    add_walls_around_room(
        room_6_3,
        OBJECT__WALL_ROCK,
        room_6_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_6_3_wall_exclude_pos_list, 1);
    destroy_list(room_6_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_6_3,
        new_object(OBJECT__CRATE_DYNAMITE_ITEM),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__VENDING_DYNAMITE),
        vec2i(2, 7)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(5, 8)
    );

    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BALL),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BALL_SPIKES),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BALL_SPIKES),
        vec2i(5, 5)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BALL),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BALL),
        vec2i(6, 7)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BALL_SPIKES),
        vec2i(7, 6)
    );

    room_add_object_at(
        room_6_3,
        new_object(OBJECT__EXIT_ROCK_RIGHT),
        vec2i(0, 5)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__EXIT_ROCK_UP),
        vec2i(4, 9)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__EXIT_ROCK_DOWN),
        vec2i(8, 0)
    );
    room_add_object_at(
        room_6_3,
        new_object(OBJECT__EXIT_ROCK_LEFT),
        vec2i(9, 1)
    );

    // enemies

    room_add_object_at(
        room_6_3,
        new_object(OBJECT__BULL),
        vec2i(5, 2)
    );

    // passages

    add_passage(state, new_passage(
        "6_3",
        "6_2",
        vec2i(0, 5),
        vec2i(8, 5)
    ));
    add_passage(state, new_passage(
        "6_3",
        "7_3",
        vec2i(4, 9),
        vec2i(4, 1)
    ));
    add_passage(state, new_passage(
        "6_3",
        "5_3",
        vec2i(8, 0),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "6_3",
        "6_4",
        vec2i(9, 1),
        vec2i(1, 1)
    ));

    ///////////
    // room_6_4
    ///////////

    Room* room_6_4 = new_empty_room("6_4", textures->background_rock);
    add_room(
        state,
        room_6_4
    );

    // floors

    add_floor_at_every_room_position(room_6_4, FLOOR__ROCK);

    room_change_floor_at(
        room_6_4,
        FLOOR__WATER,
        vec2i(0, 2)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__WATER,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__WATER,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__WATER,
        vec2i(3, 2)
    );

    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_6_4,
        FLOOR__PIT,
        vec2i(6, 1)
    );

    // walls

    List* room_6_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_6_4_wall_exclude_pos_list,
        new_vec2i(0, 1)
    );
    add_new_list_element_to_list_end(
        room_6_4_wall_exclude_pos_list,
        new_vec2i(1, 0)
    );
    add_new_list_element_to_list_end(
        room_6_4_wall_exclude_pos_list,
        new_vec2i(4, 9)
    );
    add_walls_around_room(
        room_6_4,
        OBJECT__WALL_ROCK,
        room_6_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_6_4_wall_exclude_pos_list, 1);
    destroy_list(room_6_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_6_4,
        new_object(OBJECT__ROCK),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__ROCK),
        vec2i(2, 5)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__ROCK_DAMAGED),
        vec2i(2, 6)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__ROCK),
        vec2i(2, 7)
    );

    room_add_object_at(
        room_6_4,
        new_object(OBJECT__ROCK),
        vec2i(7, 6)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__ROCK),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_6_4,
        new_object(OBJECT__DISPLAY_DAMAGED),
        vec2i(7, 1)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__DISPLAY),
        vec2i(7, 2)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__DISPLAY_DAMAGED_ITEM),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__DISPLAY_DAMAGED),
        vec2i(7, 4)
    );

    room_add_object_at(
        room_6_4,
        new_object(OBJECT__EXIT_ROCK_RIGHT),
        vec2i(0, 1)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__EXIT_ROCK_DOWN),
        vec2i(1, 0)
    );
    room_add_object_at(
        room_6_4,
        new_object(OBJECT__EXIT_ROCK_UP),
        vec2i(4, 9)
    );

    // enemies

    room_add_object_at(
        room_6_4,
        new_object(OBJECT__SPIDER),
        vec2i(4, 4)
    );

    // passages

    add_passage(state, new_passage(
        "6_4",
        "6_3",
        vec2i(0, 1),
        vec2i(8, 1)
    ));
    add_passage(state, new_passage(
        "6_4",
        "5_4",
        vec2i(1, 0),
        vec2i(1, 8)
    ));
    add_passage(state, new_passage(
        "6_4",
        "7_4",
        vec2i(4, 9),
        vec2i(4, 1)
    ));

    ///////////
    // room_6_5
    ///////////

    Room* room_6_5 = new_empty_room("6_5", textures->background_marble);
    add_room(
        state,
        room_6_5
    );

    // floors

    add_floor_at_every_room_position(room_6_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(3, 5)
    );

    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(4, 3)
    );

    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(5, 1)
    );

    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(6, 1)
    );

    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_6_5,
        FLOOR__PIT,
        vec2i(7, 1)
    );

    // walls

    List* room_6_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_6_5_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_new_list_element_to_list_end(
        room_6_5_wall_exclude_pos_list,
        new_vec2i(8, 0)
    );
    add_new_list_element_to_list_end(
        room_6_5_wall_exclude_pos_list,
        new_vec2i(2, 9)
    );
    add_new_list_element_to_list_end(
        room_6_5_wall_exclude_pos_list,
        new_vec2i(7, 9)
    );
    add_walls_around_room(
        room_6_5,
        OBJECT__WALL_MARBLE,
        room_6_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_6_5_wall_exclude_pos_list, 1);
    destroy_list(room_6_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_6_5,
        new_object(OBJECT__SAFE_DAMAGED),
        vec2i(2, 2)
    );

    room_add_object_at(
        room_6_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(4, 0)
    );
    room_add_object_at(
        room_6_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(8, 0)
    );
    room_add_object_at(
        room_6_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(2, 9)
    );
    room_add_object_at(
        room_6_5,
        new_object(OBJECT__EXIT_MARBLE_UP),
        vec2i(7, 9)
    );

    // enemies

    room_add_object_at(
        room_6_5,
        new_object(OBJECT__ENVIRONMENT_EMERGE_PIT),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "6_5",
        "5_5",
        vec2i(4, 0),
        vec2i(4, 8)
    ));
    add_passage(state, new_passage(
        "6_5",
        "5_5",
        vec2i(8, 0),
        vec2i(8, 8)
    ));
    add_passage(state, new_passage(
        "6_5",
        "7_5",
        vec2i(2, 9),
        vec2i(2, 1)
    ));
    add_passage(state, new_passage(
        "6_5",
        "7_5",
        vec2i(7, 9),
        vec2i(7, 1)
    ));

    ///////////
    // room_7_0
    ///////////

    Room* room_7_0 = new_empty_room("7_0", textures->background_obsidian);
    add_room(
        state,
        room_7_0
    );

    // floors

    add_floor_at_every_room_position(room_7_0, FLOOR__OBSIDIAN);
    //

    // walls

    List* room_7_0_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_7_0_wall_exclude_pos_list,
        new_vec2i(2, 0)
    );
    add_new_list_element_to_list_end(
        room_7_0_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_new_list_element_to_list_end(
        room_7_0_wall_exclude_pos_list,
        new_vec2i(9, 6)
    );
    add_walls_around_room(
        room_7_0,
        OBJECT__WALL_OBSIDIAN,
        room_7_0_wall_exclude_pos_list
    );
    remove_all_list_elements(room_7_0_wall_exclude_pos_list, 1);
    destroy_list(room_7_0_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__STATION_MANIPULATION_HEAD),
        vec2i(7, 2)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 1)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 2)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 3)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(6, 4)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 4)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(8, 4)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 5)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 6)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 6)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 7)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(5, 8)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 5)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 6)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 7)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(1, 2)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 2)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(3, 2)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__WALL_OBSIDIAN),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__VENDING_DYNAMITE),
        vec2i(1, 6)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__VENDING_CELL),
        vec2i(1, 7)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__VENDING_DYNAMITE_DAMAGED_ITEM),
        vec2i(1, 8)
    );

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(2, 0)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__EXIT_OBSIDIAN_DOWN),
        vec2i(6, 0)
    );
    room_add_object_at(
        room_7_0,
        new_object(OBJECT__EXIT_OBSIDIAN_LEFT),
        vec2i(9, 6)
    );

    // enemies

    room_add_object_at(
        room_7_0,
        new_object(OBJECT__ENVIRONMENT_FALLING_STALACTITE),
        vec2i(-1, -1)
    );

    // passages

    add_passage(state, new_passage(
        "7_0",
        "6_0",
        vec2i(2, 0),
        vec2i(2, 8)
    ));
    add_passage(state, new_passage(
        "7_0",
        "6_0",
        vec2i(6, 0),
        vec2i(6, 8)
    ));
    add_passage(state, new_passage(
        "7_0",
        "7_1",
        vec2i(9, 6),
        vec2i(1, 6)
    ));

    ///////////
    // room_7_1
    ///////////

    Room* room_7_1 = new_empty_room("7_1", textures->background_rock);
    add_room(
        state,
        room_7_1
    );

    // floors

    add_floor_at_every_room_position(room_7_1, FLOOR__ROCK);

    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(3, 8)
    );

    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(4, 7)
    );

    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(5, 6)
    );

    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(6, 8)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(6, 5)
    );

    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(7, 4)
    );

    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_7_1,
        FLOOR__PIT,
        vec2i(8, 3)
    );

    // walls

    List* room_7_1_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_7_1_wall_exclude_pos_list,
        new_vec2i(6, 0)
    );
    add_new_list_element_to_list_end(
        room_7_1_wall_exclude_pos_list,
        new_vec2i(0, 6)
    );
    add_walls_around_room(
        room_7_1,
        OBJECT__WALL_ROCK,
        room_7_1_wall_exclude_pos_list
    );
    remove_all_list_elements(room_7_1_wall_exclude_pos_list, 1);
    destroy_list(room_7_1_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_7_1,
        new_object(OBJECT__CRATE_CELL_ITEM),
        vec2i(2, 2)
    );

    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(1, 4)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(2, 4)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(3, 4)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(4, 4)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(4, 3)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(4, 2)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__STALAGNATE),
        vec2i(4, 1)
    );

    room_add_object_at(
        room_7_1,
        new_object(OBJECT__ROCK_DAMAGED_ITEM),
        vec2i(8, 8)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__ROCK_DAMAGED_ITEM),
        vec2i(8, 7)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__ROCK_DAMAGED_ITEM),
        vec2i(7, 8)
    );

    room_add_object_at(
        room_7_1,
        new_object(OBJECT__EXIT_ROCK_BLOCKED_DOWN),
        vec2i(6, 0)
    );
    room_add_object_at(
        room_7_1,
        new_object(OBJECT__EXIT_ROCK_RIGHT),
        vec2i(0, 6)
    );

    // passages

    add_passage(state, new_passage(
        "7_1",
        "6_1",
        vec2i(6, 0),
        vec2i(6, 8)
    ));
    add_passage(state, new_passage(
        "7_1",
        "7_0",
        vec2i(0, 6),
        vec2i(8, 6)
    ));

    ///////////
    // room_7_2
    ///////////

    Room* room_7_2 = new_empty_room("7_2", textures->background_rock);
    add_room(
        state,
        room_7_2
    );

    // floors

    add_floor_at_every_room_position(room_7_2, FLOOR__ROCK);

    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(1, 1)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(1, 0)
    );

    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(2, 1)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(2, 0)
    );

    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 9)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(3, 2)
    );

    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(4, 9)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA,
        vec2i(4, 4)
    );

    room_change_floor_at(
        room_7_2,
        FLOOR__LAVA_STALACTITE_FALLEN,
        vec2i(4, 8)
    );

    room_change_floor_at(
        room_7_2,
        FLOOR__METAL_PISTON_CELL,
        vec2i(5, 2)
    );

    // walls

    List* room_7_2_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_7_2_wall_exclude_pos_list,
        new_vec2i(9, 5)
    );
    add_walls_around_room(
        room_7_2,
        OBJECT__WALL_ROCK,
        room_7_2_wall_exclude_pos_list
    );
    remove_all_list_elements(room_7_2_wall_exclude_pos_list, 1);
    destroy_list(room_7_2_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STATION_HOOK_HAND),
        vec2i(1, 8)
    );

    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STALACTITE),
        vec2i(1, 1)
    );
    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STALACTITE),
        vec2i(1, 6)
    );
    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STALACTITE),
        vec2i(3, 7)
    );
    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STALACTITE),
        vec2i(3, 8)
    );
    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 5)
    );

    room_add_object_at(
        room_7_2,
        new_object(OBJECT__STALAGNATE),
        vec2i(7, 7)
    );

    room_add_object_at(
        room_7_2,
        new_object(OBJECT__EXIT_ROCK_LEFT),
        vec2i(9, 5)
    );

    // passages

    add_passage(state, new_passage(
        "7_2",
        "7_3",
        vec2i(9, 5),
        vec2i(1, 5)
    ));

    ///////////
    // room_7_3
    ///////////

    Room* room_7_3 = new_empty_room("7_3", textures->background_rock);
    add_room(
        state,
        room_7_3
    );

    // floors

    add_floor_at_every_room_position(room_7_3, FLOOR__ROCK);

    room_change_floor_at(
        room_7_3,
        FLOOR__ICE,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__ICE,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__ICE,
        vec2i(8, 1)
    );

    room_change_floor_at(
        room_7_3,
        FLOOR__PIT,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__PIT,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__PIT,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__PIT,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__PIT,
        vec2i(3, 8)
    );

    room_change_floor_at(
        room_7_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_7_3,
        FLOOR__STONE_TRAP,
        vec2i(6, 7)
    );

    // walls

    List* room_7_3_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_7_3_wall_exclude_pos_list,
        new_vec2i(0, 5)
    );
    add_new_list_element_to_list_end(
        room_7_3_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_walls_around_room(
        room_7_3,
        OBJECT__WALL_ROCK,
        room_7_3_wall_exclude_pos_list
    );
    remove_all_list_elements(room_7_3_wall_exclude_pos_list, 1);
    destroy_list(room_7_3_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_7_3,
        new_object(OBJECT__STATION_CHAIN_HAND),
        vec2i(7, 1)
    );

    room_add_object_at(
        room_7_3,
        new_object(OBJECT__WALL_ROCK),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_7_3,
        new_object(OBJECT__WALL_ROCK),
        vec2i(6, 2)
    );
    room_add_object_at(
        room_7_3,
        new_object(OBJECT__WALL_ROCK),
        vec2i(7, 2)
    );

    room_add_object_at(
        room_7_3,
        new_object(OBJECT__ROCK_DAMAGED_ITEM),
        vec2i(2, 2)
    );

    room_add_object_at(
        room_7_3,
        new_object(OBJECT__EXIT_ROCK_RIGHT),
        vec2i(0, 5)
    );
    room_add_object_at(
        room_7_3,
        new_object(OBJECT__EXIT_ROCK_DOWN),
        vec2i(4, 0)
    );

    // enemies

    room_add_object_at(
        room_7_3,
        new_object(OBJECT__GOAT),
        vec2i(5, 2)
    );

    // passages

    add_passage(state, new_passage(
        "7_3",
        "7_2",
        vec2i(0, 5),
        vec2i(8, 5)
    ));
    add_passage(state, new_passage(
        "7_3",
        "6_3",
        vec2i(4, 0),
        vec2i(4, 8)
    ));

    ///////////
    // room_7_4
    ///////////

    Room* room_7_4 = new_empty_room("7_4", textures->background_rock);
    add_room(
        state,
        room_7_4
    );
    room_add_object_at(
        room_7_4,
        state->hero_object,
        vec2i(4, 1)
    );
    set_curr_room(state, room_7_4);
    add_new_list_element_to_list_end(
        state->visited_room_list,
        room_7_4
    );

    // floors

    add_floor_at_every_room_position(room_7_4, FLOOR__ROCK);

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(1, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(2, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(2, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(2, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(2, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(2, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(2, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(2, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(2, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(3, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(3, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(3, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(3, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(3, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(3, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(3, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(3, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(4, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(4, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(4, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(4, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(4, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(4, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(5, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(5, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(5, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(5, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(6, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(6, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(7, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ICE,
        vec2i(7, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(7, 1)
    );

    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__ROCK,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 2)
    );
    room_change_floor_at(
        room_7_4,
        FLOOR__PIT,
        vec2i(8, 1)
    );

    // walls

    List* room_7_4_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_7_4_wall_exclude_pos_list,
        new_vec2i(4, 0)
    );
    add_new_list_element_to_list_end(
        room_7_4_wall_exclude_pos_list,
        new_vec2i(9, 4)
    );
    add_walls_around_room(
        room_7_4,
        OBJECT__WALL_ROCK,
        room_7_4_wall_exclude_pos_list
    );
    remove_all_list_elements(room_7_4_wall_exclude_pos_list, 1);
    destroy_list(room_7_4_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_7_4,
        new_object(OBJECT__EXIT_ROCK_DOWN),
        vec2i(4, 0)
    );
    room_add_object_at(
        room_7_4,
        new_object(OBJECT__EXIT_ROCK_LEFT),
        vec2i(9, 4)
    );

    // passages

    add_passage(state, new_passage(
        "7_4",
        "6_4",
        vec2i(4, 0),
        vec2i(4, 8)
    ));
    add_passage(state, new_passage(
        "7_4",
        "7_5",
        vec2i(9, 4),
        vec2i(1, 4)
    ));

    ///////////
    // room_7_5
    ///////////

    Room* room_7_5 = new_empty_room("7_5", textures->background_marble);
    add_room(
        state,
        room_7_5
    );

    // floors

    add_floor_at_every_room_position(room_7_5, FLOOR__MARBLE);

    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(3, 1)
    );

    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(4, 3)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(4, 2)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(4, 1)
    );

    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(5, 5)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(5, 4)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(5, 3)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(5, 2)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(5, 1)
    );

    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(6, 7)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(6, 6)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(6, 5)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(6, 4)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(6, 3)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(6, 2)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(6, 1)
    );

    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(7, 8)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(7, 7)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(7, 6)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(7, 5)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__ICE,
        vec2i(7, 4)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(7, 3)
    );

    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 8)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 7)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 6)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 5)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 4)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 3)
    );
    room_change_floor_at(
        room_7_5,
        FLOOR__PIT,
        vec2i(8, 2)
    );

    // walls

    List* room_7_5_wall_exclude_pos_list = new_list((void (*)(void*)) & destroy_vec2i);
    add_new_list_element_to_list_end(
        room_7_5_wall_exclude_pos_list,
        new_vec2i(2, 0)
    );
    add_new_list_element_to_list_end(
        room_7_5_wall_exclude_pos_list,
        new_vec2i(7, 0)
    );
    add_new_list_element_to_list_end(
        room_7_5_wall_exclude_pos_list,
        new_vec2i(0, 4)
    );
    add_walls_around_room(
        room_7_5,
        OBJECT__WALL_MARBLE,
        room_7_5_wall_exclude_pos_list
    );
    remove_all_list_elements(room_7_5_wall_exclude_pos_list, 1);
    destroy_list(room_7_5_wall_exclude_pos_list);

    // objects

    room_add_object_at(
        room_7_5,
        new_object(OBJECT__STALACTITE),
        vec2i(6, 1)
    );
    room_add_object_at(
        room_7_5,
        new_object(OBJECT__STALACTITE),
        vec2i(7, 3)
    );
    room_add_object_at(
        room_7_5,
        new_object(OBJECT__STALACTITE),
        vec2i(5, 4)
    );
    room_add_object_at(
        room_7_5,
        new_object(OBJECT__STALACTITE),
        vec2i(8, 7)
    );

    room_add_object_at(
        room_7_5,
        new_object(OBJECT__PILLAR),
        vec2i(1, 2)
    );

    room_add_object_at(
        room_7_5,
        new_object(OBJECT__SAFE),
        vec2i(2, 7)
    );

    room_add_object_at(
        room_7_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(2, 0)
    );
    room_add_object_at(
        room_7_5,
        new_object(OBJECT__EXIT_MARBLE_DOWN),
        vec2i(7, 0)
    );
    room_add_object_at(
        room_7_5,
        new_object(OBJECT__EXIT_MARBLE_RIGHT),
        vec2i(0, 4)
    );

    // passages

    add_passage(state, new_passage(
        "7_5",
        "6_5",
        vec2i(2, 0),
        vec2i(2, 8)
    ));
    add_passage(state, new_passage(
        "7_5",
        "6_5",
        vec2i(7, 0),
        vec2i(7, 8)
    ));
    add_passage(state, new_passage(
        "7_5",
        "7_4",
        vec2i(0, 4),
        vec2i(8, 4)
    ));

    /////////////
    // mechanisms
    /////////////

    // 0_0 lever obstacle
    add_mechanism(state, new_mechanism(
        1,
        "0_0",
        vec2i(2, 6),
        1,
        OBJECT__LEVER_STONE_POWERED,
        1,
        "0_0",
        vec2i(8, 3),
        1,
        OBJECT__OBSTACLE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "0_0",
        vec2i(8, 3),
        1,
        OBJECT__NONE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "0_0",
        vec2i(2, 6),
        1,
        OBJECT__LEVER_STONE_UNPOWERED,
        1,
        "0_0",
        vec2i(8, 3),
        1,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "0_0",
        vec2i(8, 3),
        1,
        OBJECT__OBSTACLE
    ));

    // 2_0 two target obstacle
    add_mechanism(state, new_mechanism(
        1,
        "2_0",
        vec2i(4, 5),
        0,
        FLOOR__METAL_TARGET_CHECKED,
        1,
        "2_0",
        vec2i(5, 4),
        0,
        FLOOR__METAL_TARGET_CHECKED,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__OBSTACLE,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__NONE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "2_0",
        vec2i(4, 5),
        0,
        FLOOR__METAL_TARGET_UNCHECKED,
        1,
        "2_0",
        vec2i(5, 4),
        0,
        FLOOR__METAL_TARGET_CHECKED,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__NONE,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__OBSTACLE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "2_0",
        vec2i(4, 5),
        0,
        FLOOR__METAL_TARGET_CHECKED,
        1,
        "2_0",
        vec2i(5, 4),
        0,
        FLOOR__METAL_TARGET_UNCHECKED,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__NONE,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__OBSTACLE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "2_0",
        vec2i(4, 5),
        0,
        FLOOR__METAL_TARGET_UNCHECKED,
        1,
        "2_0",
        vec2i(5, 4),
        0,
        FLOOR__METAL_TARGET_UNCHECKED,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__NONE,
        1,
        "2_0",
        vec2i(8, 2),
        1,
        OBJECT__OBSTACLE
    ));

    // 4_0 first target obstacle
    add_mechanism(state, new_mechanism(
        1,
        "4_0",
        vec2i(2, 7),
        0,
        FLOOR__METAL_TARGET_CHECKED,
        1,
        "4_0",
        vec2i(5, 5),
        1,
        OBJECT__OBSTACLE,
        0,
        "0_0",
        vec2i(0, 0),
        0,
        0,
        1,
        "4_0",
        vec2i(5, 5),
        1,
        OBJECT__NONE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "4_0",
        vec2i(2, 7),
        0,
        FLOOR__METAL_TARGET_UNCHECKED,
        1,
        "4_0",
        vec2i(5, 5),
        1,
        OBJECT__NONE,
        0,
        "0_0",
        vec2i(0, 0),
        0,
        0,
        1,
        "4_0",
        vec2i(5, 5),
        1,
        OBJECT__OBSTACLE
    ));

    // 4_0 second target obstacle
    add_mechanism(state, new_mechanism(
        1,
        "4_0",
        vec2i(2, 2),
        0,
        FLOOR__METAL_TARGET_CHECKED,
        1,
        "4_0",
        vec2i(5, 2),
        1,
        OBJECT__OBSTACLE,
        0,
        "0_0",
        vec2i(0, 0),
        0,
        0,
        1,
        "4_0",
        vec2i(5, 2),
        1,
        OBJECT__NONE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "4_0",
        vec2i(2, 2),
        0,
        FLOOR__METAL_TARGET_UNCHECKED,
        1,
        "4_0",
        vec2i(5, 2),
        1,
        OBJECT__NONE,
        0,
        "0_0",
        vec2i(0, 0),
        0,
        0,
        1,
        "4_0",
        vec2i(5, 2),
        1,
        OBJECT__OBSTACLE
    ));

    // 0_5 lever obstacle
    add_mechanism(state, new_mechanism(
        1,
        "0_5",
        vec2i(7, 2),
        1,
        OBJECT__LEVER_STONE_POWERED,
        1,
        "0_5",
        vec2i(1, 4),
        1,
        OBJECT__OBSTACLE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "0_5",
        vec2i(1, 4),
        1,
        OBJECT__NONE
    ));
    add_mechanism(state, new_mechanism(
        1,
        "0_5",
        vec2i(7, 2),
        1,
        OBJECT__LEVER_STONE_UNPOWERED,
        1,
        "0_5",
        vec2i(1, 4),
        1,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "0_5",
        vec2i(1, 4),
        1,
        OBJECT__OBSTACLE
    ));

    // 6_1 and 7_1 blocked exit
    add_mechanism(state, new_mechanism(
        1,
        "6_1",
        vec2i(6, 9),
        1,
        OBJECT__EXIT_ROCK_UP,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "7_1",
        vec2i(6, 0),
        1,
        OBJECT__EXIT_ROCK_DOWN
    ));
    add_mechanism(state, new_mechanism(
        1,
        "7_1",
        vec2i(6, 0),
        1,
        OBJECT__EXIT_ROCK_DOWN,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "6_1",
        vec2i(6, 9),
        1,
        OBJECT__EXIT_ROCK_UP
    ));

    // 5_3 and 4_3 blocked exit
    add_mechanism(state, new_mechanism(
        1,
        "5_3",
        vec2i(4, 0),
        1,
        OBJECT__EXIT_STONE_DOWN,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "4_3",
        vec2i(4, 9),
        1,
        OBJECT__EXIT_STONE_UP
    ));
    add_mechanism(state, new_mechanism(
        1,
        "4_3",
        vec2i(4, 9),
        1,
        OBJECT__EXIT_STONE_UP,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "5_3",
        vec2i(4, 0),
        1,
        OBJECT__EXIT_STONE_DOWN
    ));

    // 0_3 and 0_4 blocked exit
    add_mechanism(state, new_mechanism(
        1,
        "0_3",
        vec2i(9, 8),
        1,
        OBJECT__EXIT_GOLD_UNLOCKED_LEFT,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "0_4",
        vec2i(0, 8),
        1,
        OBJECT__EXIT_GOLD_UNLOCKED_RIGHT
    ));
    add_mechanism(state, new_mechanism(
        1,
        "0_4",
        vec2i(0, 8),
        1,
        OBJECT__EXIT_GOLD_UNLOCKED_RIGHT,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "0_3",
        vec2i(9, 8),
        1,
        OBJECT__EXIT_GOLD_UNLOCKED_LEFT
    ));

    // 5_1 and 4_1 blocked exit
    add_mechanism(state, new_mechanism(
        1,
        "5_1",
        vec2i(5, 0),
        1,
        OBJECT__EXIT_METAL_DOWN,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "4_1",
        vec2i(5, 9),
        1,
        OBJECT__EXIT_METAL_UP
    ));
    add_mechanism(state, new_mechanism(
        1,
        "4_1",
        vec2i(5, 9),
        1,
        OBJECT__EXIT_METAL_UP,
        0,
        "",
        vec2i(0, 0),
        0,
        OBJECT__NONE,
        0,
        "",
        vec2i(0, 0),
        0,
        0,
        1,
        "5_1",
        vec2i(5, 0),
        1,
        OBJECT__EXIT_METAL_DOWN
    ));
}
