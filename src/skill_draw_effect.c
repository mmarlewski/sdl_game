#include "../inc/state.h"

void skill_draw_effect(Renderer* renderer, State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos, Textures* textures, Colors* colors)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

    switch(skill)
    {
        case SKILL__NONE:
        {
            //
        }
        break;
        case SKILL__HERO_INTERACT:
        {
            //
        }
        break;
        case SKILL__HERO_MOVE:
        {
            draw_texture_at_gamemap_pos(
                renderer,
                get_texture_1_from_object(source_object, textures),
                colors->none,
                0.75f,
                tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case SKILL__HERO_THROW_CELL:
        {
            if(target_2_object != 0 && is_object_meltable(target_2_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.melt_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }

            draw_texture_at_gamemap_pos(
                    renderer,
                    get_texture_item(textures, ITEM__CELL, -1),
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
        }
        break;
        case SKILL__HERO_THROW_DYNAMITE:
        {
            if(target_2_object != 0 && is_object_breakable(target_2_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.break_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

                if(is_tilemap_pos_in_tilemap(tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.shake_effect,
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }

            draw_texture_at_gamemap_pos(
                    renderer,
                    get_texture_item(textures, ITEM__DYNAMITE, -1),
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
        }
        break;
        case SKILL__HERO_THROW_GEMSTONE:
        {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.shake_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                draw_texture_at_gamemap_pos(
                    renderer,
                    get_texture_item(textures, ITEM__GEMSTONE, -1),
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
        }
        break;
        case SKILL__CHARGE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

            if(is_floor_deadly_on_move(get_floor_on_tilemap_pos(state, target_2_tilemap_pos)) &&
            !is_object_flying(source_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.break_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
            else if(get_object_on_tilemap_pos(state, target_2_tilemap_pos) == 0)
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    get_texture_1_from_object(source_object, textures),
                    colors->none,
                    0.75f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
            else
            {
                Vec2i just_before_target_2_tilemap_pos =
                    vec2i_move_in_dir4_by(
                        target_2_tilemap_pos,
                        get_opposite_dir4(distance_info.dir4),
                        1
                        );

                draw_texture_at_gamemap_pos(
                    renderer,
                    get_texture_1_from_object(source_object, textures),
                    colors->none,
                    0.75f,
                    tilemap_pos_to_gamemap_pos(just_before_target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.crash_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
        break;
        case SKILL__JUMP:
        {
            if(is_floor_deadly_on_drop(get_floor_on_tilemap_pos(state, target_2_tilemap_pos)) &&
            !is_object_flying(source_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.death_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
            else
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    get_texture_1_from_object(source_object, textures),
                    colors->none,
                    0.75f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
        break;
        case SKILL__CHARGE_AND_PUSH:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                    );

            Vec2i just_before_target_1_tilemap_pos =
                vec2i_move_in_dir4_by(
                    target_1_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1
                    );

            int will_push_after_charge = 1;

            Vec2i charge_curr_tilemap_pos = source_object->tilemap_pos;
            int charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
            Object* charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);

            int charge_go_on = 1;
            for(int i = 0; charge_go_on && i < charge_distance_info.abs_diff; i++)
            {
                if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(source_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(charge_curr_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(is_tilemap_pos_in_tilemap(charge_curr_tilemap_pos) &&
                (is_floor_traversable(charge_curr_floor) ||
                is_object_flying(source_object)) &&
                charge_curr_object == 0)
                {
                    //
                }
                else
                {
                    charge_go_on = 0;
                    will_push_after_charge = 0;
                }

                charge_curr_tilemap_pos = vec2i_move_in_dir4_by(charge_curr_tilemap_pos,charge_distance_info.dir4,1);
                charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
                charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);
            }

            if(!will_push_after_charge)
            {
                Vec2i death_tilemap_pos = vec2i_move_in_dir4_by(
                    charge_curr_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1);

                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.death_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(death_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            if(!is_object_movable(target_1_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            DistanceInfo push_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i push_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_next_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);

            int push_curr_floor = get_floor_on_tilemap_pos(state, push_curr_tilemap_pos);
            int push_next_floor = get_floor_on_tilemap_pos(state, push_next_tilemap_pos);

            Object* push_curr_object = get_object_on_tilemap_pos(state, push_curr_tilemap_pos);
            Object* push_next_object = get_object_on_tilemap_pos(state, push_next_tilemap_pos);

            int push_go_on = 1;
            for(int i = 0; push_go_on && i < push_distance_info.abs_diff + 1; i++)
            {
                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(push_curr_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(is_tilemap_pos_in_tilemap(push_curr_tilemap_pos) &&
                (is_floor_traversable(push_curr_floor) ||
                is_object_flying(target_1_object)) &&
                push_curr_object == 0)
                {
                    //
                }
                else
                {
                    push_go_on = 0;

                    if(!is_floor_traversable(push_curr_floor) &&
                    !is_object_flying(target_1_object))
                    {
                        draw_texture_at_gamemap_pos(
                            renderer,
                            textures->skill.death_effect,
                            colors->none,
                            1.0f,
                            tilemap_pos_to_gamemap_pos(push_curr_tilemap_pos),
                            state->camera.world_pos,
                            state->camera.zoom
                            );
                    }
                }

                push_curr_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);
                push_curr_floor = get_floor_on_tilemap_pos(state, push_curr_tilemap_pos);
                push_curr_object = get_object_on_tilemap_pos(state, push_curr_tilemap_pos);
            }
        }
        break;
        case SKILL__CHARGE_AND_THROW:
        {
            DistanceInfo charge_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_1_tilemap_pos
                    );

            Vec2i just_before_target_1_tilemap_pos =
                vec2i_move_in_dir4_by(
                    target_1_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1
                    );

            int will_throw_after_charge = 1;

            Vec2i charge_curr_tilemap_pos = source_object->tilemap_pos;
            int charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
            Object* charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);

            int charge_go_on = 1;
            for(int i = 0; charge_go_on && i < charge_distance_info.abs_diff; i++)
            {
                if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(charge_curr_tilemap_pos, just_before_target_1_tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(source_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(charge_curr_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(is_tilemap_pos_in_tilemap(charge_curr_tilemap_pos) &&
                (is_floor_traversable(charge_curr_floor) ||
                is_object_flying(source_object)) &&
                charge_curr_object == 0)
                {
                    //
                }
                else
                {
                    charge_go_on = 0;
                    will_throw_after_charge = 0;
                }

                charge_curr_tilemap_pos = vec2i_move_in_dir4_by(charge_curr_tilemap_pos,charge_distance_info.dir4,1);
                charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
                charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);
            }

            if(!will_throw_after_charge)
            {
                Vec2i death_tilemap_pos = vec2i_move_in_dir4_by(
                    charge_curr_tilemap_pos,
                    get_opposite_dir4(charge_distance_info.dir4),
                    1);

                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.death_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(death_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            if(is_object_movable(target_1_object))
            {
                if(is_floor_deadly_on_drop(get_floor_on_tilemap_pos(state, target_2_tilemap_pos)) &&
                !is_object_flying(target_1_object))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.death_effect,
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
            else
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
        break;
        case SKILL__PUSH:
        {
            if(!is_object_movable(target_1_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            DistanceInfo push_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i push_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i push_next_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);

            int push_curr_floor = get_floor_on_tilemap_pos(state, push_curr_tilemap_pos);
            int push_next_floor = get_floor_on_tilemap_pos(state, push_next_tilemap_pos);

            Object* push_curr_object = get_object_on_tilemap_pos(state, push_curr_tilemap_pos);
            Object* push_next_object = get_object_on_tilemap_pos(state, push_next_tilemap_pos);

            int push_go_on = 1;
            for(int i = 0; push_go_on && i < push_distance_info.abs_diff + 1; i++)
            {
                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(push_curr_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(is_tilemap_pos_in_tilemap(push_curr_tilemap_pos) &&
                (is_floor_traversable(push_curr_floor) ||
                is_object_flying(target_1_object)) &&
                push_curr_object == 0)
                {
                    //
                }
                else
                {
                    push_go_on = 0;

                   if(!is_floor_traversable(push_curr_floor) &&
                    !is_object_flying(target_1_object))
                    {
                        draw_texture_at_gamemap_pos(
                            renderer,
                            textures->skill.death_effect,
                            colors->none,
                            1.0f,
                            tilemap_pos_to_gamemap_pos(push_curr_tilemap_pos),
                            state->camera.world_pos,
                            state->camera.zoom
                            );
                    }
                }

                push_curr_tilemap_pos = vec2i_move_in_dir4_by(push_curr_tilemap_pos,push_distance_info.dir4,1);
                push_curr_floor = get_floor_on_tilemap_pos(state, push_curr_tilemap_pos);
                push_curr_object = get_object_on_tilemap_pos(state, push_curr_tilemap_pos);
            }
        }
        break;
        case SKILL__PULL:
        {
            if(!is_object_movable(target_1_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            DistanceInfo pull_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i pull_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_next_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);

            int pull_curr_floor = get_floor_on_tilemap_pos(state, pull_curr_tilemap_pos);
            int pull_next_floor = get_floor_on_tilemap_pos(state, pull_next_tilemap_pos);

            Object* pull_curr_object = get_object_on_tilemap_pos(state, pull_curr_tilemap_pos);
            Object* pull_next_object = get_object_on_tilemap_pos(state, pull_next_tilemap_pos);

            int pull_go_on = 1;
            for(int i = 0; pull_go_on && i < pull_distance_info.abs_diff + 1; i++)
            {
                if(vec2i_equals(pull_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(pull_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(pull_curr_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(is_tilemap_pos_in_tilemap(pull_curr_tilemap_pos) &&
                (is_floor_traversable(pull_curr_floor) ||
                is_object_flying(target_1_object)) &&
                pull_curr_object == 0)
                {
                    //
                }
                else
                {
                    pull_go_on = 0;

                    if(!is_floor_traversable(pull_curr_floor) &&
                    !is_object_flying(target_1_object))
                    {
                        draw_texture_at_gamemap_pos(
                            renderer,
                            textures->skill.death_effect,
                            colors->none,
                            1.0f,
                            tilemap_pos_to_gamemap_pos(pull_curr_tilemap_pos),
                            state->camera.world_pos,
                            state->camera.zoom
                            );
                    }
                }

                pull_curr_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);
                pull_curr_floor = get_floor_on_tilemap_pos(state, pull_curr_tilemap_pos);
                pull_curr_object = get_object_on_tilemap_pos(state, pull_curr_tilemap_pos);
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            if(!is_object_movable(target_1_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            DistanceInfo pull_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    source_tilemap_pos
                    );

            int will_throw_after_pull = 1;

            Vec2i pull_prev_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_curr_tilemap_pos = target_1_tilemap_pos;
            Vec2i pull_next_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);

            int pull_curr_floor = get_floor_on_tilemap_pos(state, pull_curr_tilemap_pos);
            int pull_next_floor = get_floor_on_tilemap_pos(state, pull_next_tilemap_pos);

            Object* pull_curr_object = get_object_on_tilemap_pos(state, pull_curr_tilemap_pos);
            Object* pull_next_object = get_object_on_tilemap_pos(state, pull_next_tilemap_pos);

            int pull_go_on = 1;
            for(int i = 0; pull_go_on && i < pull_distance_info.abs_diff; i++)
            {
                if(vec2i_equals(pull_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    //
                }
                else if(vec2i_equals(pull_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(pull_curr_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(is_tilemap_pos_in_tilemap(pull_curr_tilemap_pos) &&
                (is_floor_traversable(pull_curr_floor) ||
                is_object_flying(target_1_object)) &&
                pull_curr_object == 0)
                {
                    //
                }
                else
                {
                    pull_go_on = 0;
                    will_throw_after_pull = 0;
                }

                pull_curr_tilemap_pos = vec2i_move_in_dir4_by(pull_curr_tilemap_pos,pull_distance_info.dir4,1);
                pull_curr_floor = get_floor_on_tilemap_pos(state, pull_curr_tilemap_pos);
                pull_curr_object = get_object_on_tilemap_pos(state, pull_curr_tilemap_pos);
            }

            if(!will_throw_after_pull)
            {
                Vec2i death_tilemap_pos = vec2i_move_in_dir4_by(
                    pull_curr_tilemap_pos,
                    get_opposite_dir4(pull_distance_info.dir4),
                    1);

                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.death_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(death_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                break;
            }

            if(is_object_movable(target_1_object))
            {
                if(is_floor_deadly_on_drop(get_floor_on_tilemap_pos(state, target_2_tilemap_pos)) &&
                !is_object_flying(target_1_object))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.death_effect,
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else if(target_2_object == 0)
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
            else
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
        break;
        case SKILL__THROW:
        {
            if(is_object_movable(target_1_object))
            {
                if(is_floor_deadly_on_drop(get_floor_on_tilemap_pos(state, target_2_tilemap_pos)) &&
                !is_object_flying(target_1_object))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.death_effect,
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_1_from_object(target_1_object, textures),
                        colors->none,
                        0.75f,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
            else
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.immovable_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }
        }
        break;
        case SKILL__TURRET_LASER:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(source_tilemap_pos, target_2_tilemap_pos);

            if(distance_info.dir4 != DIR4__NONE)
            {
                for(int i = 1; i <= OBJECT_TURRET_RANGE; i++)
                {
                    Vec2i tilemap_pos = vec2i_move_in_dir4_by(source_tilemap_pos, distance_info.dir4, i);

                    if(is_tilemap_pos_in_tilemap(tilemap_pos))
                    {
                        Object* object = get_object_on_tilemap_pos(state, tilemap_pos);

                        if(object != 0)
                        {
                            if(is_object_meltable(object))
                            {
                                draw_texture_at_gamemap_pos(
                                    renderer,
                                    textures->skill.melt_effect,
                                    colors->none,
                                    1.0f,
                                    tilemap_pos_to_gamemap_pos(tilemap_pos),
                                    state->camera.world_pos,
                                    state->camera.zoom
                                    );
                            }
                        }
                    }
                }
            }
        }
        break;
        case SKILL__TURRET_BOMB:
        {
            if(target_2_object != 0 && is_object_breakable(target_2_object))
            {
                draw_texture_at_gamemap_pos(
                    renderer,
                    textures->skill.break_effect,
                    colors->none,
                    1.0f,
                    tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );
            }

            for(int dir4 = 1; dir4 < DIR4__COUNT; dir4++)
            {
                Vec2i tilemap_pos = vec2i_move_in_dir4_by(target_2_tilemap_pos, dir4, 1);

                if(is_tilemap_pos_in_tilemap(tilemap_pos))
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.shake_effect,
                        colors->none,
                        1.0f,
                        tilemap_pos_to_gamemap_pos(tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
        }
        break;
        case SKILL__TURRET_PROJECTILE:
        {
            draw_texture_at_gamemap_pos(
                renderer,
                textures->skill.shake_effect,
                colors->none,
                1.0f,
                tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        default:
        break;
    }
}
