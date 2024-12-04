#include "../inc/state.h"

Animation* skill_get_animation(
    State* state,
    int skill,
    Vec2i source_tilemap_pos,
    Vec2i target_1_tilemap_pos,
    Vec2i target_2_tilemap_pos,
    Textures* textures,
    Colors* colors,
    Sounds* sounds
)
{
    Object* source_object = room_get_object_at(
        state->curr_room,
        source_tilemap_pos
    );
    int source_floor = room_get_floor_at(
        state->curr_room,
        source_tilemap_pos
    );
    Object* target_1_object = room_get_object_at(
        state->curr_room,
        target_1_tilemap_pos
    );
    int target_1_floor = room_get_floor_at(
        state->curr_room,
        target_1_tilemap_pos
    );
    Object* target_2_object = room_get_object_at(
        state->curr_room,
        target_2_tilemap_pos
    );
    int target_2_floor = room_get_floor_at(
        state->curr_room,
        target_2_tilemap_pos
    );

    Animation* skill_animation = new_animation_none();

    switch(skill)
    {
        case SKILL__USE:
        {
            if(target_2_object->type == OBJECT__THRONE)
            {
                skill_animation = new_animation_play_sound(sounds->use_throne);
            }
            else if(is_object_station(target_2_object))
            {
                skill_animation = new_animation_play_sound(sounds->use_station);
            }
            else if(is_object_secret(target_2_object))
            {
                skill_animation = new_animation_play_sound(sounds->use_secret);
            }
            else if(is_object_exit(target_2_object))
            {
                skill_animation = new_animation_play_sound(sounds->use_exit);
            }
        }
        break;
        case SKILL__MANIPULATION:
        {
            Object* object = target_2_object;
            int floor = room_get_floor_at(state->curr_room, target_2_tilemap_pos);

            if(object != NULL && is_object_manipulatable(object))
            {
                skill_animation = new_animation_sequence_of_2(
                    new_animation_play_sound(sounds->manipulation),
                    object_on_manipulate_get_animation(
                        state,
                        object,
                        target_2_tilemap_pos,
                        textures
                    )
                );
            }
            else if(floor != FLOOR__NONE && is_floor_manipulatable(floor))
            {
                skill_animation = new_animation_sequence_of_2(
                    new_animation_play_sound(sounds->manipulation),
                    floor_on_manipulation_get_animation(
                        state,
                        floor,
                        target_2_tilemap_pos,
                        textures,
                        sounds
                    )
                );
            }
        }
        break;
        case SKILL__TELEPORTATION:
        {
            skill_animation = new_animation_play_sound(sounds->teleportation);
        }
        break;
        case SKILL__PICK_ITEM_CLOSE:
        case SKILL__PUT_ITEM_CELL_CLOSE:
        case SKILL__PUT_ITEM_DYNAMITE_CLOSE:
        case SKILL__PUT_ITEM_GEMSTONE_CLOSE:
        {
            Animation* animation_sequence = new_animation_sequence();

            if(skill == SKILL__PICK_ITEM_CLOSE)
            {
                add_animation_to_end_animation_sequence(
                    animation_sequence,
                    new_animation_play_sound(sounds->pick_up_close)
                );
            }
            else
            {
                if(skill == SKILL__PUT_ITEM_GEMSTONE_CLOSE &&
                target_2_object != NULL &&
                (target_2_object->type == OBJECT__VENDING_CELL ||
                target_2_object->type == OBJECT__VENDING_DYNAMITE))
                {
                    add_animation_to_end_animation_sequence(
                        animation_sequence,
                        new_animation_play_sound(sounds->vending)
                    );
                }
                else
                {
                    add_animation_to_end_animation_sequence(
                        animation_sequence,
                        new_animation_play_sound(sounds->put_item)
                    );
                }
            }

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__PICK_ITEM_FAR:
        case SKILL__PUT_ITEM_CELL_FAR:
        case SKILL__PUT_ITEM_DYNAMITE_FAR:
        case SKILL__PUT_ITEM_GEMSTONE_FAR:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

            Animation* animation_sequence = new_animation_sequence();

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_play_sound(sounds->pick_up_far)
            );

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
                                get_texture_scissor_start(textures, distance_info.dir4),
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                            )
                        );
                    }
                    else if(vec2i_equals(tilemap_pos, target_2_tilemap_pos))
                    {
                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                get_texture_scissor_end(textures, get_opposite_dir4(distance_info.dir4)),
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
                                get_texture_scissor_from_to(textures, get_opposite_dir4(distance_info.dir4), distance_info.dir4),
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

            if(skill == SKILL__PICK_ITEM_FAR)
            {
                add_animation_to_end_animation_sequence(
                    animation_sequence,
                    new_animation_play_sound(sounds->pick_up_close)
                );
            }
            else
            {
                if(skill == SKILL__PUT_ITEM_GEMSTONE_FAR &&
                target_2_object != NULL &&
                (target_2_object->type == OBJECT__VENDING_CELL ||
                target_2_object->type == OBJECT__VENDING_DYNAMITE))
                {
                    add_animation_to_end_animation_sequence(
                        animation_sequence,
                        new_animation_play_sound(sounds->vending)
                    );
                }
                else
                {
                    add_animation_to_end_animation_sequence(
                        animation_sequence,
                        new_animation_play_sound(sounds->put_item)
                    );
                }
            }

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__THROW_ITEM_CELL:
        {
            Animation* animation_sequence = new_animation_sequence();

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_play_sound(sounds->throww)
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_move_sprite_in_gamemap_in_arch(
                    textures->animation.cell,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                    1.0f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->skill.melt_effect,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__THROW_ITEM_DYNAMITE:
        {
            Animation* animation_sequence = new_animation_sequence();

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_play_sound(sounds->throww)
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_move_sprite_in_gamemap_in_arch(
                    textures->animation.dynamite,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                    1.0f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->animation.blow_up_1,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->animation.blow_up_2,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__THROW_ITEM_GEMSTONE:
        {
            Animation* animation_sequence = new_animation_sequence();

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_play_sound(sounds->throww)
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_move_sprite_in_gamemap_in_arch(
                    textures->animation.gemstone,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                    1.0f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->skill.shake_effect,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__SHOOT_PROJECTILE_FLY:
        {
            skill_animation = new_animation_move_sprite_in_gamemap_in_line(
                textures->animation.fly_projectile,
                tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                0.2f
            );
        }
        break;
        case SKILL__SHOOT_PROJECTILE_SQUIRREL:
        {
            skill_animation = new_animation_move_sprite_in_gamemap_in_line(
                textures->animation.squirrel_projectile,
                tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                0.2f
            );
        }
        break;
        case SKILL__DRAG_HOOK:
        case SKILL__DRAG_SPIDERWEB:
        case SKILL__DRAG_TENTACLE:
        case SKILL__DRAG_AND_THROW_HOOK:
        case SKILL__DRAG_AND_THROW_TONGUE:
        case SKILL__PULL_HOOK:
        case SKILL__PULL_SPIDERWEB:
        case SKILL__PULL_TENTACLE:
        case SKILL__PULL_TONGUE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos);

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
                        Texture* texture = NULL;
                        switch(skill)
                        {
                            case SKILL__DRAG_HOOK:
                            case SKILL__DRAG_AND_THROW_HOOK:
                            case SKILL__PULL_HOOK:
                            texture = get_texture_hook_start(textures, distance_info.dir4);
                            break;
                            case SKILL__DRAG_SPIDERWEB:
                            case SKILL__PULL_SPIDERWEB:
                            texture = get_texture_spiderweb_start(textures, distance_info.dir4);
                            break;
                            case SKILL__DRAG_TENTACLE:
                            case SKILL__PULL_TENTACLE:
                            texture = get_texture_tentacle_start(textures, distance_info.dir4);
                            break;
                            case SKILL__DRAG_AND_THROW_TONGUE:
                            case SKILL__PULL_TONGUE:
                            texture = get_texture_tongue_start(textures, distance_info.dir4);
                            break;
                            default:
                            break;
                        }

                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                texture,
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                            )
                        );
                    }
                    else if(vec2i_equals(tilemap_pos, target_1_tilemap_pos))
                    {
                        Texture* texture = NULL;
                        switch(skill)
                        {
                            case SKILL__DRAG_HOOK:
                            case SKILL__DRAG_AND_THROW_HOOK:
                            case SKILL__PULL_HOOK:
                            texture = get_texture_hook_end(textures, get_opposite_dir4(distance_info.dir4));
                            break;
                            case SKILL__DRAG_SPIDERWEB:
                            case SKILL__PULL_SPIDERWEB:
                            texture = get_texture_spiderweb_end(textures, get_opposite_dir4(distance_info.dir4));
                            break;
                            case SKILL__DRAG_TENTACLE:
                            case SKILL__PULL_TENTACLE:
                            texture = get_texture_tentacle_end(textures, get_opposite_dir4(distance_info.dir4));
                            break;
                            case SKILL__DRAG_AND_THROW_TONGUE:
                            case SKILL__PULL_TONGUE:
                            texture = get_texture_tongue_end(textures, get_opposite_dir4(distance_info.dir4));
                            break;
                            default:
                            break;
                        }

                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                texture,
                                tilemap_pos_to_gamemap_pos(tilemap_pos),
                                show_sprite_length_in_seconds
                            )
                        );
                    }
                    else
                    {
                        Texture* texture = NULL;
                        switch(skill)
                        {
                            case SKILL__DRAG_HOOK:
                            case SKILL__DRAG_AND_THROW_HOOK:
                            case SKILL__PULL_HOOK:
                            texture = get_texture_hook_from_to(textures, get_opposite_dir4(distance_info.dir4), distance_info.dir4);
                            break;
                            case SKILL__DRAG_SPIDERWEB:
                            case SKILL__PULL_SPIDERWEB:
                            texture = get_texture_spiderweb_from_to(textures, get_opposite_dir4(distance_info.dir4), distance_info.dir4);
                            break;
                            case SKILL__DRAG_TENTACLE:
                            case SKILL__PULL_TENTACLE:
                            texture = get_texture_tentacle_from_to(textures, get_opposite_dir4(distance_info.dir4), distance_info.dir4);
                            break;
                            case SKILL__DRAG_AND_THROW_TONGUE:
                            case SKILL__PULL_TONGUE:
                            texture = get_texture_tongue_from_to(textures, get_opposite_dir4(distance_info.dir4), distance_info.dir4);
                            break;
                            default:
                            break;
                        }

                        add_animation_to_end_animation_simultaneous(
                            animation_simultaneous,
                            new_animation_show_sprite_in_gamemap(
                                texture,
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
        case SKILL__LAUNCH_MINIBOT:
        {
            skill_animation = new_animation_sequence_of_2(
                new_animation_play_sound(sounds->minibot_launch),
                new_animation_move_sprite_in_gamemap_in_arch(
                    textures->animation.minibot,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                    1.0f
                )
            );
        }
        break;
        case SKILL__MINIBOT_MERGE:
        {
            skill_animation = new_animation_play_sound(sounds->minibot_merge);
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
        case SKILL__TURRET_BOMB:
        {
            Animation* animation_sequence = new_animation_sequence();

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_move_sprite_in_gamemap_in_arch(
                    textures->animation.dynamite,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                    1.0f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->animation.blow_up_1,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->animation.blow_up_2,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            Animation* animation_sequence = new_animation_sequence();

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_move_sprite_in_gamemap_in_line(
                    textures->animation.gemstone,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.2f
                )
            );

            add_animation_to_end_animation_sequence(
                animation_sequence,
                new_animation_show_sprite_in_gamemap(
                    textures->skill.shake_effect,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    0.1f
                )
            );

            skill_animation = animation_sequence;
        }
        break;
        case SKILL__ENVIRONMENT_EMERGE_PIPE:
        {
            if(target_2_object != NULL && target_2_object->type == OBJECT__PIPE)
            {
                int is_able_to_emerge = FALSE;
                int emerge_dir4 = DIR4__NONE;
                for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(
                        target_2_tilemap_pos,
                        dir4,
                        1
                    );
                    Object* object = room_get_object_at(
                        state->curr_room,
                        tilemap_pos
                    );
                    if(object == NULL)
                    {
                        is_able_to_emerge = TRUE;
                        emerge_dir4 = dir4;
                    }
                }
                if(is_able_to_emerge)
                {
                    skill_animation = new_animation_move_sprite_in_gamemap_in_arch(
                        textures->animation.minibot_enemy,
                        tilemap_pos_to_gamemap_pos(
                            target_2_tilemap_pos
                        ),
                        tilemap_pos_to_gamemap_pos(
                            vec2i_move_in_dir4_by(
                                target_2_tilemap_pos,
                                emerge_dir4,
                                1
                            )
                        ),
                        ACTION_LENGTH_IN_SECONDS * ACTION_THROW_LENGTH_MODIFIER,
                        1.0f
                    );
                }
            }
        }
        break;
        default:
        break;
    }

    return skill_animation;
}
