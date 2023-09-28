#include "action.h"

Action* new_action_none()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__NONE;

    return action;
}

Action* new_action_sequence()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SEQUENCE;

    action->sequence.curr_action = 0;
    action->sequence.action_head = 0;
    action->sequence.action_tail = 0;

    return action;
}

void add_action_to_end_action_sequence(Action* action_sequence, Action* new_action)
{
    if(action_sequence->sequence.action_head)
    {
        action_sequence->sequence.action_tail->next = new_action;
    }
    else
    {
        action_sequence->sequence.action_head = new_action;
    }

    action_sequence->sequence.action_tail = new_action;
    new_action->next = 0;
}

Action* new_action_simultaneous()
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SIMULTANEOUS;

    action->simultaneous.are_all_actions_finished = 0;
    action->simultaneous.action_head = 0;
    action->simultaneous.action_tail = 0;

    return action;
}

void add_action_to_end_action_simultaneous(Action* action_simultaneous, Action* new_action)
{
    if(action_simultaneous->simultaneous.action_head)
    {
        action_simultaneous->simultaneous.action_tail->next = new_action;
    }
    else
    {
        action_simultaneous->simultaneous.action_head = new_action;
    }

    action_simultaneous->simultaneous.action_tail = new_action;
    new_action->next = 0;
}

//////////

//////////

Action* new_action_move_sprite_in_gamemap_in_line(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE;

    action->move_sprite_in_gamemap_in_line.time = 0.0f;
    action->move_sprite_in_gamemap_in_line.sprite = 0;

    action->move_sprite_in_gamemap_in_line.texture = texture;
    action->move_sprite_in_gamemap_in_line.from_gamemap_pos = from_gamemap_pos;
    action->move_sprite_in_gamemap_in_line.to_gamemap_pos = to_gamemap_pos;
    action->move_sprite_in_gamemap_in_line.seconds = seconds;

    return action;
}

Action* new_action_move_sprite_in_gamemap_in_arch(Texture* texture, vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH;

    action->move_sprite_in_gamemap_in_arch.time = 0.0f;
    action->move_sprite_in_gamemap_in_arch.sprite = 0;

    action->move_sprite_in_gamemap_in_arch.texture = texture;
    action->move_sprite_in_gamemap_in_arch.from_gamemap_pos = from_gamemap_pos;
    action->move_sprite_in_gamemap_in_arch.to_gamemap_pos = to_gamemap_pos;
    action->move_sprite_in_gamemap_in_arch.seconds = seconds;

    return action;
}

//////////

//////////

Action* new_action_show_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__SHOW_SPRITE_IN_TILEMAP;

    action->show_sprite_in_tilemap.time = 0.0f;
    action->show_sprite_in_tilemap.sprite = 0;

    action->show_sprite_in_tilemap.texture = texture;
    action->show_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    action->show_sprite_in_tilemap.seconds = seconds;

    return action;
}

Action* new_action_ascend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__ASCEND_SPRITE_IN_TILEMAP;

    action->ascend_sprite_in_tilemap.time = 0.0f;
    action->ascend_sprite_in_tilemap.sprite = 0;

    action->ascend_sprite_in_tilemap.texture = texture;
    action->ascend_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    action->ascend_sprite_in_tilemap.seconds = seconds;

    return action;
}

Action* new_action_descend_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DESCEND_SPRITE_IN_TILEMAP;

    action->ascend_sprite_in_tilemap.time = 0.0f;
    action->ascend_sprite_in_tilemap.sprite = 0;

    action->ascend_sprite_in_tilemap.texture = texture;
    action->ascend_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    action->ascend_sprite_in_tilemap.seconds = seconds;

    return action;
}

Action* new_action_drop_sprite_in_tilemap(Texture* texture, vec2i tilemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DROP_SPRITE_IN_TILEMAP;

    action->ascend_sprite_in_tilemap.time = 0.0f;
    action->ascend_sprite_in_tilemap.sprite = 0;

    action->ascend_sprite_in_tilemap.texture = texture;
    action->ascend_sprite_in_tilemap.tilemap_pos = tilemap_pos;
    action->ascend_sprite_in_tilemap.seconds = seconds;

    return action;
}

//////////

//////////

Action* new_action_move_camera_in_world_in_line(vec2f from_world_pos, vec2f to_world_pos, float seconds, int start_from_curr)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE;

    action->move_camera_in_world_in_line.time = 0.0f;
    action->move_camera_in_world_in_line.from_world_pos = from_world_pos;
    action->move_camera_in_world_in_line.to_world_pos = to_world_pos;
    action->move_camera_in_world_in_line.seconds = seconds;
    action->move_camera_in_world_in_line.start_from_curr = start_from_curr;

    return action;
}

Action* new_action_move_camera_in_world_in_arch(vec2f from_world_pos, vec2f to_world_pos, float seconds, float sin_mul, int start_from_curr)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH;

    action->move_camera_in_world_in_arch.time = 0.0f;
    action->move_camera_in_world_in_arch.from_world_pos = from_world_pos;
    action->move_camera_in_world_in_arch.to_world_pos = to_world_pos;
    action->move_camera_in_world_in_arch.seconds = seconds;
    action->move_camera_in_world_in_arch.sin_mul = sin_mul;
    action->move_camera_in_world_in_arch.start_from_curr = start_from_curr;

    return action;
}
Action* new_action_move_camera_in_gamemap_in_line(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE;

    action->move_camera_in_gamemap_in_line.time = 0.0f;
    action->move_camera_in_gamemap_in_line.from_gamemap_pos = from_gamemap_pos;
    action->move_camera_in_gamemap_in_line.to_gamemap_pos = to_gamemap_pos;
    action->move_camera_in_gamemap_in_line.seconds = seconds;

    return action;
}

Action* new_action_move_camera_in_gamemap_in_arch(vec2f from_gamemap_pos, vec2f to_gamemap_pos, float seconds, float sin_mul)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH;

    action->move_camera_in_gamemap_in_arch.time = 0.0f;
    action->move_camera_in_gamemap_in_arch.from_gamemap_pos = from_gamemap_pos;
    action->move_camera_in_gamemap_in_arch.to_gamemap_pos = to_gamemap_pos;
    action->move_camera_in_gamemap_in_arch.seconds = seconds;
    action->move_camera_in_gamemap_in_arch.sin_mul = sin_mul;

    return action;
}

Action* new_action_play_sound(Sound* sound)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__PLAY_SOUND;
    action->play_sound.sound = sound;

    return action;
}

//////////

//////////

Action* new_action_move(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__MOVE;
    
    action->move.action_move_sprite_in_gamemap = 0;
    action->move.is_move_blocked = 0;

    action->move.object = object;
    action->move.dir4 = dir4;

    return action;
}

Action* new_action_push(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__PUSH;
    
    action->push.action_move_sprite_in_gamemap = 0;
    action->push.is_move_blocked = 0;

    action->push.object = object;
    action->push.dir4 = dir4;

    return action;
}

Action* new_action_crash(Object* object, int dir4)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__CRASH;

    action->crash.action_sequence = 0;

    action->crash.object = object;
    action->crash.dir4 = dir4;

    return action;
}

Action* new_action_drop(Object* object)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DROP;

    action->drop.action_drop_sprite_in_tilemap = 0;

    action->drop.object = object;

    return action;
}

Action* new_action_death(Object* object)
{
    Action* action = malloc(sizeof(* action));

    action->next = 0;
    action->is_finished = 0;
    action->type = ACTION_TYPE__DEATH;

    action->death.object = object;

    return action;
}

Action* new_action_camera_shake(int times, float distance, float seconds)
{
    Action* camera_shake = new_action_sequence();

    float seconds_quarter = seconds * 0.25f;
    vec2f to_left_world_pos = make_vec2f(-distance, 0.0f);
    vec2f to_right_world_pos = make_vec2f(distance, 0.0f);

    for(int i = 0; i < times; i++)
    {
        Action* camera_move_1 = new_action_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_left_world_pos,seconds_quarter,1);
        Action* camera_move_2 = new_action_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_right_world_pos,seconds_quarter,1);
        Action* camera_move_3 = new_action_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_right_world_pos,seconds_quarter,1);
        Action* camera_move_4 = new_action_move_camera_in_world_in_line(make_vec2f(0.0f, 0.0f),to_left_world_pos,seconds_quarter,1);

        add_action_to_end_action_sequence(camera_shake,camera_move_1);
        add_action_to_end_action_sequence(camera_shake,camera_move_2);
        add_action_to_end_action_sequence(camera_shake,camera_move_3);
        add_action_to_end_action_sequence(camera_shake,camera_move_4);
    }

    return camera_shake;
}

void destroy_action(Action* action)
{
    free(action);
}

char* get_action_name_from_type(int action_type)
{
    char* name = "";

    switch(action_type)
    {
        case ACTION_TYPE__NONE:                             name = "none";                              break;
        case ACTION_TYPE__SEQUENCE:                         name = "sequence";                          break;
        case ACTION_TYPE__SIMULTANEOUS:                     name = "simultaneous";                      break;
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:   name = "move sprite in gamemap_in_line";    break;
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:   name = "move sprite in gamemap_in_arch";    break;
        case ACTION_TYPE__SHOW_SPRITE_IN_TILEMAP:           name = "show sprite in tilemap";            break;
        case ACTION_TYPE__ASCEND_SPRITE_IN_TILEMAP:         name = "ascend sprite in tilemap";          break;
        case ACTION_TYPE__DESCEND_SPRITE_IN_TILEMAP:        name = "descend sprite in tilemap";         break;
        case ACTION_TYPE__DROP_SPRITE_IN_TILEMAP:           name = "drop sprite in tilemap";            break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:     name = "move camera in world in line";      break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:     name = "move camera in world in arch";      break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:   name = "move camera in gamemap in line";    break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:   name = "move camera in gamemap in arch";    break;
        case ACTION_TYPE__PLAY_SOUND:                       name = "play sound";                        break;
        case ACTION_TYPE__MOVE:                             name = "move";                              break;
        case ACTION_TYPE__PUSH:                             name = "push";                              break;
        case ACTION_TYPE__CRASH:                            name = "crash";                             break;
        case ACTION_TYPE__DROP:                             name = "drop";                              break;
        case ACTION_TYPE__DEATH:                            name = "death";                             break;
        case ACTION_TYPE__COUNT:                            name = "count";                             break;
        default: break;
    }

    return name;
}