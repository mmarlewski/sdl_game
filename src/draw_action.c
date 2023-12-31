#include "../inc/game.h"

void draw_action(Renderer* renderer, State* state, Action* action, Vec3i color, Textures* textures, Colors* colors)
{
    Vec2i tilemap_pos = action->tilemap_pos;
    Vec2f gamemap_pos = tilemap_pos_to_gamemap_pos(tilemap_pos);
    Vec2f world_cart_pos = gamemap_pos_to_world_pos(gamemap_pos);
    Vec2f world_iso_pos = cart_pos_to_iso_pos(world_cart_pos);

    switch(action->type)
    {
        case ACTION_TYPE__NONE:
        {
            //
        }
        break;
        case ACTION_TYPE__SEQUENCE:
        {
            for(ListElem* curr_elem = action->sequence.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*)curr_elem->data;
                draw_action(renderer, state, curr_action, color, textures, colors);
            }
        }
        break;
        case ACTION_TYPE__SIMULTANEOUS:
        {
            for(ListElem* curr_elem = action->simultaneous.action_list->head; curr_elem; curr_elem = curr_elem->next)
            {
                Action* curr_action = (Action*)curr_elem->data;
                draw_action(renderer, state, curr_action, color, textures, colors);
            }
        }
        break;
        case ACTION_TYPE__MOVE:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_move(textures, action->move.dir4),
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__CRASH:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_crash(textures, action->crash.dir4),
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__FALL:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.fall,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__DEATH:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.death,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__BLOW_UP:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.blow_up,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__THROW:
        {
            Vec2i target_tilemap_pos = vec2i_move_in_dir4_by(action->tilemap_pos, action->throw.dir4, action->throw.distance);
            Vec2f target_gamemap_pos = tilemap_pos_to_gamemap_pos(target_tilemap_pos);
            Vec2f target_world_cart_pos = gamemap_pos_to_world_pos(target_gamemap_pos);
            Vec2f target_world_iso_pos = cart_pos_to_iso_pos(target_world_cart_pos);

            draw_texture_at_world_pos(
                renderer,
                get_texture_throw(textures, action->throw.dir4),
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );

            draw_texture_at_world_pos(
                renderer,
                textures->action.drop,
                color,
                target_world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__LIFT:
        {
            draw_texture_at_world_pos(
                renderer,
                get_texture_lift(textures, action->lift.dir4),
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__DROP:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.drop,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__CHANGE_FLOOR:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.change,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__CHANGE_OBJECT:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.change,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__ADD_OBJECT:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.change,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        case ACTION_TYPE__REMOVE_OBJECT:
        {
            draw_texture_at_world_pos(
                renderer,
                textures->action.change,
                color,
                world_iso_pos,
                state->camera.world_pos,
                state->camera.zoom
                );
        }
        break;
        default:
        break;
    }
}
