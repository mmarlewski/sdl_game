#include "../inc/state.h"

int is_skill_two_target(int skill)
{
    int is = 0;

    switch(skill)
    {
        case SKILL__MOVE: is = 0; break;
        case SKILL__CHARGE: is = 1; break;
        case SKILL__PUSH: is = 1; break;
        case SKILL__PULL: is = 1; break;
        case SKILL__THROW: is = 1; break;
        default: break;
    }

    return is;
}

void skill_add_pos_to_possible_target_1_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    
    switch(skill)
                {
                    case SKILL__MOVE:
                    {
                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
                    }
                    break;
                    case SKILL__CHARGE:
                    {
                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

                        for(int i = 0; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
                    }
                    break;
                    case SKILL__PUSH:
                    {
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1));
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1));
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1));
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1));
                    }
                    break;
                    case SKILL__PULL:
                    {
                        for(int i = 1; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, i+1));

                        for(int i = 1; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, i+1));

                        for(int i = 1; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, i+1));

                        for(int i = 1; i < 5; i++)
                        add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, i+1));
                    }
                    break;
                        case SKILL__THROW:
                        {
                            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__UP, 1));
                            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__RIGHT, 1));
                            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__DOWN, 1));
                            add_pos_to_possible_target_1_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(source_tilemap_pos, DIR4__LEFT, 1));
                        }
                        break;
                    default:
                    break;
                }
}

void skill_add_pos_to_possible_target_2_tilemap_pos_list(State* state, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);

    switch(state->gamemap.curr_skill)
                    {
                        case SKILL__MOVE:
                        {
                            //
                        }
                        break;
                        case SKILL__CHARGE:
                        {
                            int x_diff = get_x_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int y_diff = get_y_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int dir4 = get_dir4_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                            int diff = 0;
                            switch(dir4)
                            {
                                case DIR4__UP: diff = -y_diff; break;
                                case DIR4__RIGHT: diff = x_diff; break;
                                case DIR4__DOWN: diff = y_diff; break;
                                case DIR4__LEFT: diff = -x_diff; break;
                                default: break;
                            }
                            
                            for(int i = 0; i < 5; i++)
                            {
                                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, dir4, i+1));
                            }
                        }
                        break;
                        case SKILL__PUSH:
                        {
                            int x_diff = get_x_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int y_diff = get_y_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int dir4 = get_dir4_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                            int diff = 0;
                            switch(dir4)
                            {
                                case DIR4__UP: diff = -y_diff; break;
                                case DIR4__RIGHT: diff = x_diff; break;
                                case DIR4__DOWN: diff = y_diff; break;
                                case DIR4__LEFT: diff = -x_diff; break;
                                default: break;
                            }
                            
                            for(int i = 0; i < 5; i++)
                            {
                                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, dir4, i+1));
                            }
                        }
                        break;
                        case SKILL__PULL:
                        {
                            int x_diff = get_x_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int y_diff = get_y_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int dir4 = get_dir4_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                            int diff = 0;
                            switch(dir4)
                            {
                                case DIR4__UP: diff = -y_diff; break;
                                case DIR4__RIGHT: diff = x_diff; break;
                                case DIR4__DOWN: diff = y_diff; break;
                                case DIR4__LEFT: diff = -x_diff; break;
                                default: break;
                            }
                            
                            for(int i = 1; i < diff; i++)
                            {
                                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, dir4, -i));
                            }
                        }
                        break;
                        case SKILL__THROW:
                        {
                            int x_diff = get_x_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int y_diff = get_y_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int dir4 = get_dir4_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                            int diff = 0;
                            switch(dir4)
                            {
                                case DIR4__UP: diff = -y_diff; break;
                                case DIR4__RIGHT: diff = x_diff; break;
                                case DIR4__DOWN: diff = y_diff; break;
                                case DIR4__LEFT: diff = -x_diff; break;
                                default: break;
                            }
                            
                            for(int i = 0; i < 5; i++)
                            {
                                add_pos_to_possible_target_2_tilemap_pos_list(state, new_vec2i_move_in_dir4_by(target_1_tilemap_pos, dir4, i+1));
                            }
                        }
                        break;
                        default:
                        break;
                    }
}

void skill_get_actions_to_execute(State* state, Action* sequence, int skill, vec2i source_tilemap_pos, vec2i target_1_tilemap_pos, vec2i target_2_tilemap_pos)
{
    Object* source_object = get_object_on_tilemap_pos(state, source_tilemap_pos);
    Object* target_1_object = get_object_on_tilemap_pos(state, target_1_tilemap_pos);
    Object* target_2_object = get_object_on_tilemap_pos(state, target_2_tilemap_pos);

    switch(state->gamemap.curr_skill)
                    {
                        case SKILL__MOVE:
                        {
                            int x_diff = get_x_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int y_diff = get_y_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                            int dir4 = get_dir4_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                            int diff = 0;
                            switch(dir4)
                            {
                                case DIR4__UP: diff = -y_diff; break;
                                case DIR4__RIGHT: diff = x_diff; break;
                                case DIR4__DOWN: diff = y_diff; break;
                                case DIR4__LEFT: diff = -x_diff; break;
                                default: break;
                            }

                            for(int i = 0; i < diff; i++)
                            {
                                add_action_to_end_action_sequence(sequence, new_action_move(source_object,dir4));
                            }
                        }
                        break;
                        case SKILL__CHARGE:
                        {
                            if(target_1_object)
                            {
                                int move_x_diff = get_x_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                                int move_y_diff = get_y_diff_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);
                                int move_dir4 = get_dir4_from_vec2i_to_vec2i(source_tilemap_pos, target_1_tilemap_pos);

                                int move_diff = 0;
                                switch(move_dir4)
                                {
                                    case DIR4__UP: move_diff = -move_y_diff; break;
                                    case DIR4__RIGHT: move_diff = move_x_diff; break;
                                    case DIR4__DOWN: move_diff = move_y_diff; break;
                                    case DIR4__LEFT: move_diff = -move_x_diff; break;
                                    default: break;
                                }

                                for(int i = 0; i < move_diff-1; i++)
                                {
                                    add_action_to_end_action_sequence(sequence, new_action_move(source_object,move_dir4));
                                }
                            
                                int push_x_diff = get_x_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int push_y_diff = get_y_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int push_dir4 = get_dir4_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                                int push_diff = 0;
                                switch(push_dir4)
                                {
                                    case DIR4__UP: push_diff = -push_y_diff; break;
                                    case DIR4__RIGHT: push_diff = push_x_diff; break;
                                    case DIR4__DOWN: push_diff = push_y_diff; break;
                                    case DIR4__LEFT: push_diff = -push_x_diff; break;
                                    default: break;
                                }

                                for(int i = 0; i < push_diff; i++)
                                {
                                    add_action_to_end_action_sequence(sequence, new_action_push(target_1_object,push_dir4));
                                }
                            }
                        }
                        break;
                        case SKILL__PUSH:
                        {
                            if(target_1_object)
                            {
                                int x_diff = get_x_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int y_diff = get_y_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int dir4 = get_dir4_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                                int diff = 0;
                                switch(dir4)
                                {
                                    case DIR4__UP: diff = -y_diff; break;
                                    case DIR4__RIGHT: diff = x_diff; break;
                                    case DIR4__DOWN: diff = y_diff; break;
                                    case DIR4__LEFT: diff = -x_diff; break;
                                    default: break;
                                }

                                for(int i = 0; i < diff; i++)
                                {
                                    add_action_to_end_action_sequence(sequence, new_action_push(target_1_object,dir4));
                                }
                            }
                        }
                        break;
                        case SKILL__PULL:
                        {
                            if(target_1_object)
                            {
                                int x_diff = get_x_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int y_diff = get_y_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int dir4 = get_dir4_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                                int diff = 0;
                                switch(dir4)
                                {
                                    case DIR4__UP: diff = -y_diff; break;
                                    case DIR4__RIGHT: diff = x_diff; break;
                                    case DIR4__DOWN: diff = y_diff; break;
                                    case DIR4__LEFT: diff = -x_diff; break;
                                    default: break;
                                }

                                for(int i = 0; i < diff; i++)
                                {
                                    add_action_to_end_action_sequence(sequence, new_action_push(target_1_object,dir4));
                                }
                            }
                        }
                        break;
                        case SKILL__THROW:
                        {
                            if(target_1_object && !target_2_object)
                            {
                                int x_diff = get_x_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int y_diff = get_y_diff_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);
                                int dir4 = get_dir4_from_vec2i_to_vec2i(target_1_tilemap_pos, target_2_tilemap_pos);

                                int diff = 0;
                                switch(dir4)
                                {
                                    case DIR4__UP: diff = -y_diff; break;
                                    case DIR4__RIGHT: diff = x_diff; break;
                                    case DIR4__DOWN: diff = y_diff; break;
                                    case DIR4__LEFT: diff = -x_diff; break;
                                    default: break;
                                }

                                add_action_to_end_action_sequence(sequence, new_action_throw(target_1_object, target_1_tilemap_pos, dir4, diff));
                            }
                        }
                        break;
                        default:
                        break;
                    }
}

char* get_skill_name(int skill)
{
    char* name = "";

    switch(skill)
    {
        case SKILL__NONE:   name = "none";      break;
        case SKILL__MOVE:   name = "move";      break;
        case SKILL__CHARGE: name = "charge";    break;
        case SKILL__PUSH:   name = "push";      break;
        case SKILL__PULL:   name = "pull";      break;
        case SKILL__THROW:   name = "throw";      break;
        default: break;
    }

    return name;
}