#include "state.h"

void update_action(State* state, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("update  action:     %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            Action_Sequence action_action = action->sequence;

            if(action_action.curr_action)
            {
                update_action(state, action_action.curr_action, delta_time, textures, sounds, musics);
                
                if(action_action.curr_action->is_finished)
                {
                    Action* next_action = action_action.curr_action->next;
                    end_action(state, action_action.curr_action, textures, sounds, musics);
                    destroy_action(action_action.curr_action);
                    action_action.curr_action = next_action;

                    if(action_action.curr_action)
                    {
                        start_action(state, action_action.curr_action, textures, sounds, musics);
                    }
                }
            }

            action->sequence = action_action;

            action->is_finished = (!action->sequence.curr_action);
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            Action_Simultaneous action_action = action->simultaneous;

            int is_any_action_not_finished = 0;
            Action* prev_action = 0;
            Action* curr_action = action_action.action_head;
            Action* next_action = (action_action.action_head) ? (action_action.action_head->next) : (0);
            while(curr_action)
            {
                if(curr_action->is_finished)
                {
                    end_action(state, curr_action, textures, sounds, musics);
                    next_action = curr_action->next;
                    destroy_action(curr_action);
                    
                    if(prev_action)
                    {
                        prev_action->next = next_action;
                    }
                    else
                    {
                        action_action.action_head = next_action;
                    }
                    curr_action = next_action;
                    next_action = (next_action) ? (next_action->next) : (0);
                }
                else
                {
                    is_any_action_not_finished = 1;
                    update_action(state, curr_action, delta_time, textures, sounds, musics);

                    prev_action = curr_action;
                    curr_action = next_action;
                    next_action = (next_action) ? (next_action->next) : (0);
                }
            }
            if(!is_any_action_not_finished)
            {
                action_action.are_all_actions_finished = 1;
            }

            action->simultaneous = action_action;

            action->is_finished = (action->simultaneous.are_all_actions_finished);
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            Action_Move action_action = action->move;

            update_animation(state, action_action.animation_move_sprite_in_gamemap, delta_time, textures, sounds, musics);

            action->move = action_action;

            action->is_finished = (action->move.animation_move_sprite_in_gamemap->is_finished);
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            Action_Push action_action = action->push;

            update_animation(state, action_action.animation_move_sprite_in_gamemap, delta_time, textures, sounds, musics);

            action->push = action_action;

            action->is_finished = (action->push.animation_move_sprite_in_gamemap->is_finished);
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            Action_Crash action_action = action->crash;

            update_animation(state, action_action.animation_sequence, delta_time, textures, sounds, musics);

            action->crash = action_action;

            action->is_finished = (action->crash.animation_sequence->is_finished);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            Action_Drop action_action = action->drop;

            update_animation(state, action_action.animation_drop_sprite_in_tilemap, delta_time, textures, sounds, musics);

            action->drop = action_action;

            action->is_finished = (action->drop.animation_drop_sprite_in_tilemap->is_finished);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            action->is_finished = 1;
        }
        break;
        default:
        break;
    }
}