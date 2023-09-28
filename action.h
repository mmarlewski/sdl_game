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

    ACTION_TYPE__DROP,
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
    Action* action_tail;

} Action_Sequence;

typedef struct
{
    int are_all_actions_finished;
    Action* action_head;
    Action* action_tail;

} Action_Simultaneous;

typedef struct
{
    Animation* animation_move_sprite_in_gamemap;
    int is_move_blocked;
    
    Object* object;
    int dir4;

} Action_Move;

typedef struct
{
    Animation* animation_move_sprite_in_gamemap;
    int is_move_blocked;

    Object* object;
    int dir4;

} Action_Push;

typedef struct
{
    Animation* animation_sequence;

    Object* object;
    int dir4;

} Action_Crash;

typedef struct
{
    Animation* animation_drop_sprite_in_tilemap;

    Object* object;

} Action_Drop;

typedef struct
{
    Object* object;

} Action_Death;

struct _Action
{
    Action* next;
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

        Action_Drop drop;
        Action_Death death;
    };

};

Action* new_action_none();

Action* new_action_sequence();
void add_action_to_end_action_sequence(Action* action_sequence, Action* new_action);
Action* new_action_simultaneous();
void add_action_to_end_action_simultaneous(Action* action_simultaneous, Action* new_action);

Action* new_action_move(Object* object, int dir4);
Action* new_action_push(Object* object, int dir4);
Action* new_action_crash(Object* object, int dir4);

Action* new_action_drop(Object* object);
Action* new_action_death(Object* object);

void destroy_action(Action* action);

char* get_action_name_from_type(int action_type);

#endif