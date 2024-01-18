#include "../inc/state.h"

Animation* skill_get_animation(State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos, Textures* textures)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

    Animation* skill_animation = new_animation_none();

    switch (skill)
    {
        case SKILL__INTERACT:
        {
            Object* object = target_2_object;
            int floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);

            if(object != 0 && is_object_interactable(object))
            {
                skill_animation = object_on_interact_get_animation(
                    state,
                    object,
                    target_2_tilemap_pos,
                    textures
                );
            }
            else if(floor != FLOOR_TYPE__NONE && is_floor_interactable(floor))
            {
                skill_animation = floor_on_interact_get_animation(
                    state,
                    floor,
                    target_2_tilemap_pos,
                    textures
                );
            }
        }
        break;
        case SKILL__PULL:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

            Animation* animation_sequence = new_animation_sequence();

            for(int i = 0; i < distance_info.abs_diff + 1; i++)
            {
                Animation* animation_simultaneous = new_animation_simultaneous();
                Vec2i tilemap_pos = source_tilemap_pos;
                float show_sprite_length_in_seconds = 0.1f;

                for(int j = 0; j <= i; j++)
                {
                    if(vec2i_equals(tilemap_pos, source_tilemap_pos))
                    {
                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                get_texture_hook_start(textures, distance_info.dir4),
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                                )
                            );
                    }
                    else if(vec2i_equals(tilemap_pos, target_1_tilemap_pos))
                    {
                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                get_texture_hook_end(textures, get_opposite_dir4(distance_info.dir4)),
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                                )
                            );
                    }
                    else
                    {
                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                get_texture_hook_from_to(textures, get_opposite_dir4(distance_info.dir4),distance_info.dir4),
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                                )
                            );
                    }

                    tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, distance_info.dir4, 1);
                }

                add_animation_to_end_animation_sequence(
                    animation_sequence,
                    animation_simultaneous
                    );
            }

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__TURRET_LASER:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

            Vec2i range_end_tilemap_pos =
                vec2i_move_in_dir4_by(
                    source_tilemap_pos,
                    distance_info.dir4,
                    OBJECT_TURRET_RANGE
                    );

            Animation* animation_simultaneous = new_animation_simultaneous();
            Vec2i tilemap_pos = source_tilemap_pos;
            float show_sprite_length_in_seconds = 0.5f;

            for(int i = 0; i <= OBJECT_TURRET_RANGE; i++)
            {
                if(vec2i_equals(tilemap_pos, source_tilemap_pos))
                {
                    add_animation_to_end_animation_simultaneous(
                        animation_simultaneous,
                        new_animation_show_sprite_in_gamemap(
                            get_texture_laser(textures, distance_info.dir4),
                            tilemap_pos_to_gamemap_pos(tilemap_pos),
                            show_sprite_length_in_seconds
                            )
                        );
                }
                else if(vec2i_equals(tilemap_pos, range_end_tilemap_pos))
                {
                    add_animation_to_end_animation_simultaneous(
                        animation_simultaneous,
                        new_animation_show_sprite_in_gamemap(
                            get_texture_laser(textures, get_opposite_dir4(distance_info.dir4)),
                            tilemap_pos_to_gamemap_pos(tilemap_pos),
                            show_sprite_length_in_seconds
                            )
                        );
                }
                else if(distance_info.dir4 == DIR4__UP || distance_info.dir4 == DIR4__DOWN)
                {
                    add_animation_to_end_animation_simultaneous(
                        animation_simultaneous,
                        new_animation_show_sprite_in_gamemap(
                            textures->animation.laser_vertical,
                            tilemap_pos_to_gamemap_pos(tilemap_pos),
                            show_sprite_length_in_seconds
                            )
                        );
                }
                else if(distance_info.dir4 == DIR4__RIGHT || distance_info.dir4 == DIR4__LEFT)
                {
                    add_animation_to_end_animation_simultaneous(
                        animation_simultaneous,
                        new_animation_show_sprite_in_gamemap(
                            textures->animation.laser_horizontal,
                            tilemap_pos_to_gamemap_pos(tilemap_pos),
                            show_sprite_length_in_seconds
                            )
                        );
                }

                tilemap_pos = vec2i_move_in_dir4_by(tilemap_pos, distance_info.dir4, 1);
            }

            skill_animation = animation_simultaneous;
        }
        break;
        default:
        break;
    }

    return skill_animation;
}
