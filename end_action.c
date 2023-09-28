#include "state.h"

void end_action(State* state, Action* action, Textures* textures, Sounds* sounds, Musics* musics)
{
    printf("end action:     %s \n", get_action_name_from_type(action->type));

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            //
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_LINE:
        {
            remove_sprite_from_gamemap_sprites(state, action->move_sprite_in_gamemap_in_line.sprite);
        }
        case ACTION_TYPE__MOVE_SPRITE_IN_GAMEMAP_IN_ARCH:
        {
            remove_sprite_from_gamemap_sprites(state, action->move_sprite_in_gamemap_in_arch.sprite);
        }
        break;
        case ACTION_TYPE__SHOW_SPRITE_IN_TILEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, action->show_sprite_in_tilemap.sprite);
        }
        break;
        case ACTION_TYPE__ASCEND_SPRITE_IN_TILEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, action->ascend_sprite_in_tilemap.sprite);
        }
        break;
        case ACTION_TYPE__DESCEND_SPRITE_IN_TILEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, action->descend_sprite_in_tilemap.sprite);
        }
        break;
        case ACTION_TYPE__DROP_SPRITE_IN_TILEMAP:
        {
            remove_sprite_from_gamemap_sprites(state, action->drop_sprite_in_tilemap.sprite);
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_LINE:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_WORLD_IN_ARCH:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_LINE:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE_CAMERA_IN_GAMEMAP_IN_ARCH:
        {
            //
        }
        break;
        case ACTION_TYPE__PLAY_SOUND:
        {
            //
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            if(!action->move.is_move_blocked)
            {
                action->move.object->tilemap_pos = move_vec2i_in_dir4_by(action->move.object->tilemap_pos,action->move.dir4,1);
                end_action(state, action->move.action_move_sprite_in_gamemap, textures, sounds, musics);
            }

            int floor = get_floor_on_tilemap_pos(state, action->move.object->tilemap_pos);
            Action* action_result = get_action_from_floor_on_action(action, floor);
            add_action_after_curr_action(state, action_result);
        }
        break;
        case ACTION_TYPE__PUSH:
        {
            if(!action->push.is_move_blocked)
            {
                action->push.object->tilemap_pos = move_vec2i_in_dir4_by(action->push.object->tilemap_pos,action->push.dir4,1);
                end_action(state, action->push.action_move_sprite_in_gamemap, textures, sounds, musics);
            }
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            end_action(state, action->crash.action_sequence, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DROP:
        {
            end_action(state, action->drop.action_drop_sprite_in_tilemap, textures, sounds, musics);
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            remove_object_from_gamemap_objects(state, action->death.object);
        }
        break;
        default:
        break;
    }
}