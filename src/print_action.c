#include "../inc/state.h"

void print_action(Action* action, int depth)
{
    char* action_type = get_action_name_from_type(action->type);
    for(int i = 0; i < depth; i++) printf("  ");
    printf("%s \n", action_type);

    if(action->type != ACTION_TYPE__SEQUENCE && action->type != ACTION_TYPE__SIMULTANEOUS)
    {
        // comment this line if you need to look closely at each single action
        return;
    }

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("[ \n");
            for(ListElem* curr_elem = action->sequence.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                print_action(curr_elem->data, depth + 1);
            }
            for(int i = 0; i < depth; i++) printf("  ");
            printf("] \n");
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("{ \n");
            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                print_action(curr_elem->data, depth + 1);
            }
            for(int i = 0; i < depth; i++) printf("  ");
            printf("} \n");
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object:         %p \n", action->move.object);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("dir4:           %i \n", action->move.dir4);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object_c..ing:  %p \n", action->crash.object_crushing);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object_c..ed:   %p \n", action->crash.object_crushed);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("dir4:           %i \n", action->crash.dir4);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__FALL:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object:         %p \n", action->fall.object);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object:         %p \n", action->death.object);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__THROW:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object_thrown:  %p \n", action->throw.object_thrown);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object_on_t.:   %p \n", action->throw.object_on_target);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("dir4:           %i \n", action->throw.dir4);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("distance:       %i \n", action->throw.distance);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__LIFT:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object:         %p \n", action->lift.object);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("dir4:           %i \n", action->lift.dir4);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        case ACTION_TYPE__DROP:
        {
            for(int i = 0; i < depth; i++) printf("  ");
            printf("( \n");
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("object:         %p \n", action->drop.object);
            for(int i = 0; i < depth + 1; i++) printf("  ");
            printf("dir4:           %i \n", action->drop.dir4);
            for(int i = 0; i < depth; i++) printf("  ");
            printf(") \n");
        }
        break;
        default:
        break;
    }
}
