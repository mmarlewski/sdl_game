#include "../inc/state.h"

void update_action(State* state, Action* sequence, Action* action, float delta_time, Textures* textures, Sounds* sounds, Musics* musics, Colors* colors)
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
            action->sequence.was_curr_action_just_finished = 0;

            ListElem* curr_elem = action->sequence.curr_action_list_elem;
            Action* curr_action = (Action*)curr_elem->data;

            if(action->sequence.was_curr_action_finished)
            {
                action->sequence.was_curr_action_finished = 0;

                ListElem* next_elem = curr_elem->next;
                action->sequence.curr_action_list_elem = next_elem;

                if(next_elem != 0)
                {
                    Action* next_action = (Action*)next_elem->data;
                    start_action(state, action, next_action, textures, sounds, musics, colors);
                }
            }
            else if(curr_action->is_finished)
            {
                action->sequence.was_curr_action_finished = 1;
                action->sequence.was_curr_action_just_finished = 1;

                end_action(state, action, curr_action, textures, sounds, musics, colors);
            }
            // else if(curr_action->type == ACTION_TYPE__SEQUENCE && curr_action->sequence.was_curr_action_just_finished)
            // {
            //     action->sequence.was_curr_action_just_finished = 1;

            //     update_action(state, action, curr_action, delta_time, textures, sounds, musics, colors);
            // }
            else
            {
                update_action(state, action, curr_action, delta_time, textures, sounds, musics, colors);
            }

            action->is_finished = (!action->sequence.curr_action_list_elem);
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            ListElem* simultaneous_curr_elem = action->simultaneous.curr_action_list_elem;
            Action* simultaneous_curr_action = (Action*)simultaneous_curr_elem->data;

            int go_to_next_action = 0;
            ListElem* simultaneous_next_elem = simultaneous_curr_elem->next;

            if(simultaneous_curr_action->is_finished)
            {
                go_to_next_action = 1;

                end_action(state, 0, simultaneous_curr_action, textures, sounds, musics, colors);
                remove_list_element_of_data(action->simultaneous.action_list, simultaneous_curr_action, 1);
            }
            else if(simultaneous_curr_action->type == ACTION_TYPE__SEQUENCE)
            {
                if(simultaneous_curr_action->sequence.was_curr_action_just_finished)
                {
                    simultaneous_curr_action->sequence.was_curr_action_just_finished = 0;

                    go_to_next_action = 1;
                }
            }

            if(go_to_next_action)
            {
                if(simultaneous_next_elem == 0)
                {
                    for(ListElem* curr_elem = action->simultaneous.action_list->head;
                    simultaneous_next_elem == 0 && curr_elem != 0;
                    curr_elem = curr_elem->next)
                    {
                        Action* curr_action = (Action*)curr_elem->data;
                        if(!curr_action->is_finished)
                        {
                            simultaneous_next_elem = curr_elem;
                        }
                    }
                }

                if(simultaneous_next_elem == 0)
                {
                    action->is_finished = 1;
                }
                else
                {
                    action->simultaneous.curr_action_list_elem = simultaneous_next_elem;
                    Action* simultaneous_next_action = (Action*)simultaneous_next_elem->data;
                    if(!is_data_in_list(action->simultaneous.started_action_list, simultaneous_next_action))
                    {
                        start_action(state, 0, simultaneous_next_action, textures, sounds, musics, colors);
                        add_new_list_element_to_list_end(action->simultaneous.started_action_list,simultaneous_next_action);
                    }
                }
            }
            else
            {
                update_action(state, 0, simultaneous_curr_action, delta_time, textures, sounds, musics, colors);
            }
        }
        break;
        case 666:
        {
            int are_all_actions_finished = 1;
            List* action_to_be_removed_list = new_list(0);

            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*)curr_elem->data;
                if(curr_action->is_finished)
                {
                    end_action(state, curr_action, curr_action, textures, sounds, musics, colors);
                    add_new_list_element_to_list_end(action_to_be_removed_list, curr_action);
                }
                else
                {
                    update_action(state, curr_action, curr_action, delta_time, textures, sounds, musics, colors);
                    are_all_actions_finished = 0;
                }
            }

            for(ListElem* curr_elem = action_to_be_removed_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                remove_list_element_of_data(action->simultaneous.action_list, curr_elem->data, 1);
            }

            destroy_list(action_to_be_removed_list);

            action->is_finished = (are_all_actions_finished);
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__FALL:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__THROW:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__LIFT:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            action->is_finished = (action->animation->is_finished);
        }
        break;
        case ACTION_TYPE__CHANGE_FLOOR:
        {
            action->is_finished = 1;
        }
        break;
        case ACTION_TYPE__CHANGE_OBJECT:
        {
            action->is_finished = 1;
        }
        break;
        case ACTION_TYPE__ADD_OBJECT:
        {
            action->is_finished = 1;
        }
        break;
        case ACTION_TYPE__REMOVE_OBJECT:
        {
            action->is_finished = 1;
        }
        break;
        default:
        break;
    }
}
