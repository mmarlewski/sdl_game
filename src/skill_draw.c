#include "../inc/state.h"

void skill_draw(Renderer* renderer, State* state, int skill, Vec2i source_tilemap_pos, Vec2i target_1_tilemap_pos, Vec2i target_2_tilemap_pos, Vec3i color, Textures* textures)
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
        case SKILL__INTERACT:
        {
            draw_texture_at_gamemap_pos(
                renderer,
                textures->skill.change,
                color,
                tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case SKILL__MOVE:
        {
            List* path_pos = new_list((void(*)(void*))destroy_vec2i);
            find_path(
                state,
                source_tilemap_pos,
                target_2_tilemap_pos,
                path_pos
                );

            if(path_pos->size > 0)
            {
                ListElem* prev_elem = 0;
                ListElem* curr_elem = path_pos->head;
                ListElem* next_elem = (curr_elem) ? (curr_elem->next) : (0);

                Vec2i* prev_tilemap_pos = (prev_elem) ? ((Vec2i*)prev_elem->data) : (0);
                Vec2i* curr_tilemap_pos = (curr_elem) ? ((Vec2i*)curr_elem->data) : (0);
                Vec2i* next_tilemap_pos = (next_elem) ? ((Vec2i*)next_elem->data) : (0);

                while(curr_elem != 0)
                {
                    Texture* arrow_texture = 0;

                    if(prev_elem == 0)
                    {
                        arrow_texture = get_texture_arrow_thin_start(
                            textures,
                            get_distance_info_from_vec2i_to_vec2i(
                                *curr_tilemap_pos,
                                *next_tilemap_pos
                                ).dir4
                            );
                    }
                    else if(next_elem == 0)
                    {
                        arrow_texture = get_texture_arrow_thin_end(
                            textures,
                            get_distance_info_from_vec2i_to_vec2i(
                                *curr_tilemap_pos,
                                *prev_tilemap_pos
                                ).dir4
                            );
                    }
                    else
                    {
                        arrow_texture = get_texture_arrow_thin_from_to(
                            textures,
                            get_distance_info_from_vec2i_to_vec2i(
                                *curr_tilemap_pos,
                                *prev_tilemap_pos
                                ).dir4,
                            get_distance_info_from_vec2i_to_vec2i(
                                *curr_tilemap_pos,
                                *next_tilemap_pos
                                ).dir4
                            );
                    }

                    Vec2f curr_gamemap_pos =
                        tilemap_pos_to_gamemap_pos(*curr_tilemap_pos);

                    draw_texture_at_gamemap_pos(
                        renderer,
                        arrow_texture,
                        color,
                        curr_gamemap_pos,
                        state->camera.world_pos,
                        state->camera.zoom
                        );

                    prev_elem = curr_elem;
                    curr_elem = next_elem;
                    next_elem = (curr_elem) ? (curr_elem->next) : (0);

                    prev_tilemap_pos = (prev_elem) ? ((Vec2i*)prev_elem->data) : (0);
                    curr_tilemap_pos = (curr_elem) ? ((Vec2i*)curr_elem->data) : (0);
                    next_tilemap_pos = (next_elem) ? ((Vec2i*)next_elem->data) : (0);
                }
            }

            remove_all_list_elements(path_pos, 1);
            destroy_list(path_pos);
        }
        break;
        case SKILL__CHARGE:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

            Vec2i prev_tilemap_pos = source_object->tilemap_pos;
            Vec2i curr_tilemap_pos = source_object->tilemap_pos;
            Vec2i next_tilemap_pos = vec2i_move_in_dir4_by(curr_tilemap_pos,distance_info.dir4,1);

            int curr_floor = get_floor_on_tilemap_pos(state, curr_tilemap_pos);
            int next_floor = get_floor_on_tilemap_pos(state, next_tilemap_pos);

            Object* curr_object = get_object_on_tilemap_pos(state, curr_tilemap_pos);
            Object* next_object = get_object_on_tilemap_pos(state, next_tilemap_pos);

            int go_on = 1;
            for(int i = 0; go_on && i < distance_info.abs_diff + 1; i++)
            {
                Texture* arrow_texture = 0;

                if(vec2i_equals(curr_tilemap_pos, source_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thin_start(
                            textures,
                            distance_info.dir4
                            );
                }
                else if(vec2i_equals(curr_tilemap_pos, target_2_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thin_end(
                            textures,
                            get_opposite_dir4(distance_info.dir4)
                            );
                }
                else if(is_tilemap_pos_in_tilemap(curr_tilemap_pos) &&
                (is_floor_traversable(curr_floor) ||
                is_object_flying(source_object)) &&
                curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thin_from_to(
                            textures,
                            distance_info.dir4,
                            get_opposite_dir4(distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thin_end(
                            textures,
                            get_opposite_dir4(distance_info.dir4)
                            );

                    go_on = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                prev_tilemap_pos = curr_tilemap_pos;
                curr_tilemap_pos = next_tilemap_pos;
                next_tilemap_pos = vec2i_move_in_dir4_by(next_tilemap_pos,distance_info.dir4,1);

                curr_floor = get_floor_on_tilemap_pos(state, curr_tilemap_pos);
                next_floor = get_floor_on_tilemap_pos(state, next_tilemap_pos);

                curr_object = get_object_on_tilemap_pos(state, curr_tilemap_pos);
                next_object = get_object_on_tilemap_pos(state, next_tilemap_pos);
            }
        }
        break;
        case SKILL__JUMP:
        {
            DistanceInfo distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

            int target_floor = get_floor_on_tilemap_pos(state, target_2_tilemap_pos);
            Object* target_object = target_2_object;

            if(is_tilemap_pos_in_tilemap(target_2_tilemap_pos))
            {
                if(target_object == 0)
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_throw(textures, distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );

                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.drop,
                        color,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_lift(textures, distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
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

            Vec2i charge_prev_tilemap_pos = source_object->tilemap_pos;
            Vec2i charge_curr_tilemap_pos = source_object->tilemap_pos;
            Vec2i charge_next_tilemap_pos = vec2i_move_in_dir4_by(charge_curr_tilemap_pos,charge_distance_info.dir4,1);

            int charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
            int charge_next_floor = get_floor_on_tilemap_pos(state, charge_next_tilemap_pos);

            Object* charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);
            Object* charge_next_object = get_object_on_tilemap_pos(state, charge_next_tilemap_pos);

            int charge_go_on = 1;
            for(int i = 0; charge_go_on && i < charge_distance_info.abs_diff; i++)
            {
                Texture* arrow_texture = 0;

                if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thin_start(
                            textures,
                            charge_distance_info.dir4
                            );
                }
                else if(is_tilemap_pos_in_tilemap(charge_curr_tilemap_pos) &&
                (is_floor_traversable(charge_curr_floor) ||
                is_object_flying(source_object)) &&
                charge_curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thin_from_to(
                            textures,
                            charge_distance_info.dir4,
                            get_opposite_dir4(charge_distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thin_end(
                            textures,
                            get_opposite_dir4(charge_distance_info.dir4)
                            );

                    charge_go_on = 0;
                    will_push_after_charge = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(charge_curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                charge_prev_tilemap_pos = charge_curr_tilemap_pos;
                charge_curr_tilemap_pos = charge_next_tilemap_pos;
                charge_next_tilemap_pos = vec2i_move_in_dir4_by(charge_next_tilemap_pos,charge_distance_info.dir4,1);

                charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
                charge_next_floor = get_floor_on_tilemap_pos(state, charge_next_tilemap_pos);

                charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);
                charge_next_object = get_object_on_tilemap_pos(state, charge_next_tilemap_pos);
            }

            if(!will_push_after_charge || !is_object_movable(target_1_object)) break;

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
                Texture* arrow_texture = 0;

                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_start(
                            textures,
                            push_distance_info.dir4
                            );
                }
                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(push_distance_info.dir4)
                            );
                }
                else if(is_tilemap_pos_in_tilemap(push_curr_tilemap_pos) &&
                (is_floor_traversable(push_curr_floor) ||
                is_object_flying(source_object)) &&
                push_curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thick_from_to(
                            textures,
                            push_distance_info.dir4,
                            get_opposite_dir4(push_distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(push_distance_info.dir4)
                            );

                    push_go_on = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(push_curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                push_prev_tilemap_pos = push_curr_tilemap_pos;
                push_curr_tilemap_pos = push_next_tilemap_pos;
                push_next_tilemap_pos = vec2i_move_in_dir4_by(push_next_tilemap_pos,push_distance_info.dir4,1);

                push_curr_floor = get_floor_on_tilemap_pos(state, push_curr_tilemap_pos);
                push_next_floor = get_floor_on_tilemap_pos(state, push_next_tilemap_pos);

                push_curr_object = get_object_on_tilemap_pos(state, push_curr_tilemap_pos);
                push_next_object = get_object_on_tilemap_pos(state, push_next_tilemap_pos);
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

            Vec2i charge_prev_tilemap_pos = source_object->tilemap_pos;
            Vec2i charge_curr_tilemap_pos = source_object->tilemap_pos;
            Vec2i charge_next_tilemap_pos = vec2i_move_in_dir4_by(charge_curr_tilemap_pos,charge_distance_info.dir4,1);

            int charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
            int charge_next_floor = get_floor_on_tilemap_pos(state, charge_next_tilemap_pos);

            Object* charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);
            Object* charge_next_object = get_object_on_tilemap_pos(state, charge_next_tilemap_pos);

            int charge_go_on = 1;
            for(int i = 0; charge_go_on && i < charge_distance_info.abs_diff; i++)
            {
                Texture* arrow_texture = 0;

                if(vec2i_equals(charge_curr_tilemap_pos, source_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thin_start(
                            textures,
                            charge_distance_info.dir4
                            );
                }
                else if(is_tilemap_pos_in_tilemap(charge_curr_tilemap_pos) &&
                (is_floor_traversable(charge_curr_floor) ||
                is_object_flying(source_object)) &&
                charge_curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thin_from_to(
                            textures,
                            charge_distance_info.dir4,
                            get_opposite_dir4(charge_distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thin_end(
                            textures,
                            get_opposite_dir4(charge_distance_info.dir4)
                            );

                    charge_go_on = 0;
                    will_throw_after_charge = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(charge_curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                charge_prev_tilemap_pos = charge_curr_tilemap_pos;
                charge_curr_tilemap_pos = charge_next_tilemap_pos;
                charge_next_tilemap_pos = vec2i_move_in_dir4_by(charge_next_tilemap_pos,charge_distance_info.dir4,1);

                charge_curr_floor = get_floor_on_tilemap_pos(state, charge_curr_tilemap_pos);
                charge_next_floor = get_floor_on_tilemap_pos(state, charge_next_tilemap_pos);

                charge_curr_object = get_object_on_tilemap_pos(state, charge_curr_tilemap_pos);
                charge_next_object = get_object_on_tilemap_pos(state, charge_next_tilemap_pos);
            }

            if(!will_throw_after_charge || !is_object_movable(target_1_object)) break;

            DistanceInfo throw_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            if(is_object_movable(target_1_object))
            {
                if(target_2_object == 0)
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_throw(textures, throw_distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );

                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.drop,
                        color,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_lift(textures, throw_distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
        }
        break;
        case SKILL__PUSH:
        {
            if(!is_object_movable(target_1_object)) break;

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
                Texture* arrow_texture = 0;

                if(vec2i_equals(push_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_start(
                            textures,
                            push_distance_info.dir4
                            );
                }
                else if(vec2i_equals(push_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(push_distance_info.dir4)
                            );
                }
                else if(is_tilemap_pos_in_tilemap(push_curr_tilemap_pos) &&
                (is_floor_traversable(push_curr_floor) ||
                is_object_flying(source_object)) &&
                push_curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thick_from_to(
                            textures,
                            push_distance_info.dir4,
                            get_opposite_dir4(push_distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(push_distance_info.dir4)
                            );

                    push_go_on = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(push_curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                push_prev_tilemap_pos = push_curr_tilemap_pos;
                push_curr_tilemap_pos = push_next_tilemap_pos;
                push_next_tilemap_pos = vec2i_move_in_dir4_by(push_next_tilemap_pos,push_distance_info.dir4,1);

                push_curr_floor = get_floor_on_tilemap_pos(state, push_curr_tilemap_pos);
                push_next_floor = get_floor_on_tilemap_pos(state, push_next_tilemap_pos);

                push_curr_object = get_object_on_tilemap_pos(state, push_curr_tilemap_pos);
                push_next_object = get_object_on_tilemap_pos(state, push_next_tilemap_pos);
            }
        }
        break;
        case SKILL__PULL:
        {
            if(!is_object_movable(target_1_object)) break;

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
                Texture* arrow_texture = 0;

                if(vec2i_equals(pull_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_start(
                            textures,
                            pull_distance_info.dir4
                            );
                }
                else if(vec2i_equals(pull_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(pull_distance_info.dir4)
                            );
                }
                else if(is_tilemap_pos_in_tilemap(pull_curr_tilemap_pos) &&
                (is_floor_traversable(pull_curr_floor) ||
                is_object_flying(source_object)) &&
                pull_curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thick_from_to(
                            textures,
                            pull_distance_info.dir4,
                            get_opposite_dir4(pull_distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(pull_distance_info.dir4)
                            );

                    pull_go_on = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(pull_curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                pull_prev_tilemap_pos = pull_curr_tilemap_pos;
                pull_curr_tilemap_pos = pull_next_tilemap_pos;
                pull_next_tilemap_pos = vec2i_move_in_dir4_by(pull_next_tilemap_pos,pull_distance_info.dir4,1);

                pull_curr_floor = get_floor_on_tilemap_pos(state, pull_curr_tilemap_pos);
                pull_next_floor = get_floor_on_tilemap_pos(state, pull_next_tilemap_pos);

                pull_curr_object = get_object_on_tilemap_pos(state, pull_curr_tilemap_pos);
                pull_next_object = get_object_on_tilemap_pos(state, pull_next_tilemap_pos);
            }
        }
        break;
        case SKILL__PULL_AND_THROW:
        {
            if(!is_object_movable(target_1_object)) break;

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
                Texture* arrow_texture = 0;

                if(vec2i_equals(pull_curr_tilemap_pos, target_1_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_start(
                            textures,
                            pull_distance_info.dir4
                            );
                }
                else if(vec2i_equals(pull_curr_tilemap_pos, target_2_tilemap_pos))
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(pull_distance_info.dir4)
                            );
                }
                else if(is_tilemap_pos_in_tilemap(pull_curr_tilemap_pos) &&
                (is_floor_traversable(pull_curr_floor) ||
                is_object_flying(source_object)) &&
                pull_curr_object == 0)
                {
                    arrow_texture =
                        get_texture_arrow_thick_from_to(
                            textures,
                            pull_distance_info.dir4,
                            get_opposite_dir4(pull_distance_info.dir4)
                            );
                }
                else
                {
                    arrow_texture =
                        get_texture_arrow_thick_end(
                            textures,
                            get_opposite_dir4(pull_distance_info.dir4)
                            );

                    pull_go_on = 0;
                    will_throw_after_pull = 0;
                }

                draw_texture_at_gamemap_pos(
                    renderer,
                    arrow_texture,
                    color,
                    tilemap_pos_to_gamemap_pos(pull_curr_tilemap_pos),
                    state->camera.world_pos,
                    state->camera.zoom
                    );

                pull_prev_tilemap_pos = pull_curr_tilemap_pos;
                pull_curr_tilemap_pos = pull_next_tilemap_pos;
                pull_next_tilemap_pos = vec2i_move_in_dir4_by(pull_next_tilemap_pos,pull_distance_info.dir4,1);

                pull_curr_floor = get_floor_on_tilemap_pos(state, pull_curr_tilemap_pos);
                pull_next_floor = get_floor_on_tilemap_pos(state, pull_next_tilemap_pos);

                pull_curr_object = get_object_on_tilemap_pos(state, pull_curr_tilemap_pos);
                pull_next_object = get_object_on_tilemap_pos(state, pull_next_tilemap_pos);
            }

            if(!will_throw_after_pull) break;

            DistanceInfo throw_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    source_tilemap_pos,
                    target_2_tilemap_pos
                    );

            if(is_object_movable(target_1_object))
            {
                if(target_2_object == 0)
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_throw(textures, throw_distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );

                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.drop,
                        color,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_lift(textures, throw_distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(source_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
        }
        break;
        case SKILL__THROW:
        {
            DistanceInfo throw_distance_info =
                get_distance_info_from_vec2i_to_vec2i(
                    target_1_tilemap_pos,
                    target_2_tilemap_pos
                    );

            if(is_object_movable(target_1_object))
            {
                if(target_2_object == 0)
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_throw(textures, throw_distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );

                    draw_texture_at_gamemap_pos(
                        renderer,
                        textures->skill.drop,
                        color,
                        tilemap_pos_to_gamemap_pos(target_2_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
                else
                {
                    draw_texture_at_gamemap_pos(
                        renderer,
                        get_texture_lift(textures, throw_distance_info.dir4),
                        color,
                        tilemap_pos_to_gamemap_pos(target_1_tilemap_pos),
                        state->camera.world_pos,
                        state->camera.zoom
                        );
                }
            }
        }
        break;
        default:
        break;
    }
}
