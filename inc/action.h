#ifndef ACTION_H
#define ACTION_H

#include "../inc/common.h"
#include "../inc/vec.h"
#include "../inc/dir.h"
#include "../inc/list.h"
#include "../inc/animation.h"
#include "../inc/floor.h"
#include "../inc/object.h"

enum ACTION_TYPE
{
    ACTION__NONE,

    ACTION__SEQUENCE,
    ACTION__SIMULTANEOUS,

    ACTION__MOVE,
    ACTION__MOVE_FLOATING,
    ACTION__MOVE_FLYING,
    ACTION__CRASH,

    ACTION__FALL,
    ACTION__DEATH,
    ACTION__BLOW_UP,

    ACTION__THROW,
    ACTION__LIFT,
    ACTION__DROP,

    ACTION__CHANGE_FLOOR,
    ACTION__CHANGE_OBJECT,

    ACTION__ADD_OBJECT,
    ACTION__REMOVE_OBJECT,

    ACTION__CHANGE_OBJECT_TILEMAP_POS,

    ACTION__MELT,
    ACTION__BREAK,
    ACTION__SHAKE,

    ACTION__COUNT
};

typedef struct _Action Action;

typedef struct
{
} Action_None;

typedef struct
{
    List* action_list;
    ListElem* curr_action_list_elem;

} Action_Sequence;

typedef struct
{
    List* action_list;

} Action_Simultaneous;

typedef struct
{
    int dir4;

    Object* object;

} Action_Move;

typedef struct
{
    int dir4;

    Object* object_crushing;
    Object* object_crushed;

} Action_Crash;

typedef struct
{
    Object* object;

} Action_Fall;

typedef struct
{
    Object* object;

} Action_Death;

typedef struct
{

} Action_BlowUP;

typedef struct
{
    int dir4;
    int distance;

    Object* object_thrown;
    Object* object_on_target;

} Action_Throw;

typedef struct
{
    int dir4;

    Object* object;

} Action_Lift;

typedef struct
{
    int dir4;
    Object* object;

} Action_Drop;

typedef struct
{
    int new_floor_type;

} Action_ChangeFloor;

typedef struct
{
    int new_object_type;

} Action_ChangeObject;

typedef struct
{
    Object* new_object;

} Action_AddObject;

typedef struct
{
    Object* object_to_remove;

} Action_RemoveObject;

typedef struct
{
    Object* object;
    Vec2i new_tilemap_pos;

} Action_ChangeObjectTilemapPos;

typedef struct
{

} Action_Melt;

typedef struct
{

} Action_Break;

typedef struct
{

} Action_Shake;

struct _Action
{
    Animation* animation;
    Vec2i tilemap_pos;
    int is_finished;
    int is_finished_at_start;
    int type;

    union
    {
        Action_None action_none;

        Action_Sequence sequence;
        Action_Simultaneous simultaneous;

        Action_Move move;
        Action_Crash crash;

        Action_Fall fall;
        Action_Death death;
        Action_BlowUP blow_up;

        Action_Throw throw;
        Action_Lift lift;
        Action_Drop drop;

        Action_ChangeFloor change_floor;
        Action_ChangeObject change_object;

        Action_AddObject add_object;
        Action_RemoveObject remove_object;

        Action_ChangeObjectTilemapPos change_object_tilemap_pos;

        Action_Melt melt;
        Action_Break breakk;
        Action_Shake shake;
    };

};

Action* new_action_none();

Action* new_action_sequence();
Action* new_action_sequence_of_1(Action* action_1);
Action* new_action_sequence_of_2(Action* action_1, Action* action_2);
Action* new_action_sequence_of_3(Action* action_1, Action* action_2, Action* action_3);
void add_action_to_end_action_sequence(Action* sequence, Action* new_action);
void add_action_after_curr_action_action_sequence(Action* sequence, Action* new_action);
void remove_all_actions_after_curr_action_action_sequence(Action* sequence);

Action* new_action_simultaneous();
Action* new_action_simultaneous_of_1(Action* action_1);
Action* new_action_simultaneous_of_2(Action* action_1, Action* action_2);
Action* new_action_simultaneous_of_3(Action* action_1, Action* action_2, Action* action_3);
void add_action_sequence_to_action_simultaneous(Action* simultaneous, Action* new_sequence);

Action* new_action_move(Vec2i tilemap_pos, int dir4);
Action* new_action_move_floating(Vec2i tilemap_pos, int dir4);
Action* new_action_move_flying(Vec2i tilemap_pos, int dir4);
Action* new_action_crash(Vec2i tilemap_pos, int dir4);

Action* new_action_fall(Object* object, Vec2i tilemap_pos);
Action* new_action_death(Object* object, Vec2i tilemap_pos);
Action* new_action_blow_up(Vec2i tilemap_pos);

Action* new_action_throw(Vec2i tilemap_pos, int dir4, int distance);
Action* new_action_lift(Vec2i tilemap_pos, int dir4);
Action* new_action_drop(Object* object, Vec2i tilemap_pos, int dir4);

Action* new_action_change_floor(int new_floor_type, Vec2i tilemap_pos);
Action* new_action_change_object(int new_object_type, Vec2i tilemap_pos);

Action* new_action_add_object(Object* new_object, Vec2i tilemap_pos);
Action* new_action_remove_object(Object* object_to_remove, Vec2i tilemap_pos);

Action* new_action_change_object_tilemap_pos(Object* object, Vec2i new_tilemap_pos);

Action* new_action_melt(Vec2i tilemap_pos);
Action* new_action_break(Vec2i tilemap_pos);
Action* new_action_shake(Vec2i tilemap_pos);

void destroy_action(Action* action);

char* get_action_name_from_type(int action_type);

#endif
