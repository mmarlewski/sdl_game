#ifndef ACTION_H
#define ACTION_H

#include "common.h"
#include "vec.h"
#include "dir.h"
#include "animation.h"
#include "floor.h"
#include "object.h"

enum ACTION_TYPE
{
    ACTION_TYPE__NONE,

    ACTION_TYPE__SEQUENCE,
    ACTION_TYPE__SIMULTANEOUS,

    ACTION_TYPE__MOVE,
    ACTION_TYPE__PUSH,
    ACTION_TYPE__CRASH,

    ACTION_TYPE__FALL,
    ACTION_TYPE__DEATH,

    ACTION_TYPE__COUNT
};

typedef struct _Action Action;

typedef struct
{
} Action_None;

typedef struct
{
    Action* curr_action;
    Action* action_head;

} Action_Sequence;

typedef struct
{
    Action* action_head;
    Action* action_tail;

} Action_Simultaneous;

typedef struct
{
    int is_move_blocked;
    
    Object* object;
    int dir4;

} Action_Move;

typedef struct
{
    int is_move_blocked;

    Object* object;
    int dir4;

} Action_Push;

typedef struct
{
    Object* object;
    int dir4;

} Action_Crash;

typedef struct
{
    Object* object;

} Action_Fall;

typedef struct
{
    Object* object;

} Action_Death;

struct _Action
{
    Action* next;
    Animation* animation;
    int is_finished;
    int type;

    union
    {
        Action_None action_none;

        Action_Sequence sequence;
        Action_Simultaneous simultaneous;

        Action_Move move;
        Action_Push push;
        Action_Crash crash;

        Action_Fall fall;
        Action_Death death;
    };

};

Action* new_action_none();

Action* new_action_sequence();
Action* new_action_sequence_of_1(Action* action_1);
Action* new_action_sequence_of_2(Action* action_1, Action* action_2);
Action* new_action_sequence_of_3(Action* action_1, Action* action_2, Action* action_3);
void add_action_after_action(Action* action, Action* new_action);
void add_action_to_end_after_action(Action* action, Action* new_action);
void remove_all_actions_after_action(Action* action);

Action* new_action_simultaneous();
Action* new_action_simultaneous_of_1(Action* action_1);
Action* new_action_simultaneous_of_2(Action* action_1, Action* action_2);
Action* new_action_simultaneous_of_3(Action* action_1, Action* action_2, Action* action_3);
void add_action_sequence_to_action_simultaneous(Action* action_simultaneous, Action* new_action_sequence);

Action* new_action_move(Object* object, int dir4);
Action* new_action_push(Object* object, int dir4);
Action* new_action_crash(Object* object, int dir4);

Action* new_action_fall(Object* object);
Action* new_action_death(Object* object);

void destroy_action(Action* action);

char* get_action_name_from_type(int action_type);

#endif