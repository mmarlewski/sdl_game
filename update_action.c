#include "state.h"

void update_action(State* state, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics)
{
    // printf("update action:      %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            action->is_finished = 1;
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            if(action->sequence.curr_action->is_finished)
            {
                end_action(state, action->sequence.curr_action, textures, sounds, musics);
                Action* next_action = action->sequence.curr_action->next;
                destroy_action(action->sequence.curr_action);
                action->sequence.curr_action = next_action;

                if(action->sequence.curr_action)
                {
                    start_action(state, action->sequence.curr_action, textures, sounds, musics);
                }
            }
            else
            {
                update_action(state, action->sequence.curr_action, delta_time, textures, sounds, musics);
            }

            action->sequence = action->sequence;

            action->is_finished = (!action->sequence.curr_action);
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            int is_any_action_not_finished = 0;
            Action* prev_action = 0;
            Action* curr_action = action->simultaneous.action_head;
            Action* next_action = (curr_action) ? (curr_action->next) : (0);
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
                        action->simultaneous.action_head = next_action;
                    }

                    curr_action = next_action;

                    if(curr_action)
                    {
                        next_action = curr_action->next;
                    }
                    else
                    {
                        action->simultaneous.action_tail = prev_action;
                    }
                }
                else
                {
                    is_any_action_not_finished = 1;
                    update_action(state, curr_action, delta_time, textures, sounds, musics);

                    prev_action = curr_action;
                    curr_action = next_action;
                    next_action = (curr_action) ? (curr_action->next) : (0);
                }
            }

            action->is_finished = (!is_any_action_not_finished);
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__FALL:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            update_animation(state, action->animation, delta_time, textures, sounds, musics);

            action->is_finished = (action->animation->is_finished);
        }
        break;
        default:
        break;
    }
}