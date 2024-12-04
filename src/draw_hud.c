#include "../inc/game.h"
#include <SDL2/SDL_stdinc.h>
#include <string.h>

void draw_hud(Renderer* renderer, State* state, Textures* textures, Colors* colors, Fonts* fonts)
{
    // game start

    if(state->gamestate == GAMESTATE__GAME_START)
    {
        SDL_SetRenderDrawColor(
            renderer,
            colors->game_start_background.x,
            colors->game_start_background.y,
            colors->game_start_background.z,
            255
        );
        SDL_RenderClear(renderer);

        draw_font_at_screen_pos(
            "Fallen Stalactite",
            renderer,
            fonts->stepalange_150,
            colors->white,
            1.0f,
            vec2i(200, 100),
            1
        );
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.start_game,
            colors->none,
            1.0f,
            vec2i(600, 300),
            2.0f
        );
    }

    // game over

    if(state->gamestate == GAMESTATE__GAME_OVER)
    {
        if(state->game_over_uses > 0)
        {
            draw_font_at_screen_pos(
                "You Died",
                renderer,
                fonts->stepalange_100,
                colors->white,
                1.0f,
                vec2i(500, 100),
                1
            );
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.load_save,
                colors->none,
                1.0f,
                vec2i(600, 300),
                2.0f
            );
        }
        else
        {
            draw_font_at_screen_pos(
                "Game Over",
                renderer,
                fonts->stepalange_100,
                colors->white,
                1.0f,
                vec2i(460, 100),
                1
            );
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_game,
                colors->none,
                1.0f,
                vec2i(600, 300),
                2.0f
            );
        }

        Texture* game_over_texture = NULL;

        if(state->game_over_uses == 3) game_over_texture = textures->hud.reset_turn_3x;
        else if(state->game_over_uses == 2) game_over_texture = textures->hud.reset_turn_2x;
        else if(state->game_over_uses == 1) game_over_texture = textures->hud.reset_turn_1x;

        draw_texture_at_screen_pos(
            renderer,
            game_over_texture,
            colors->none,
            1.0f,
            vec2i(600 + 32, 300 + 64 + 10),
            2.0f
        );
    }

    // game won

    if(state->gamestate == GAMESTATE__GAME_WON)
    {
        draw_font_at_screen_pos(
            "You Won!",
            renderer,
            fonts->stepalange_100,
            colors->white,
            1.0f,
            vec2i(500, 100),
            1
        );
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.restart_with_no_aug,
            colors->none,
            1.0f,
            vec2i(570, 700),
            2.0f
        );

        if(!state->was_secret_aug_unlocked)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->secret_background,
                colors->none,
                1.0f,
                vec2i(600, 550),
                2.0f
            );
            if(state->was_secret_1_taken)
            {
                draw_texture_at_screen_pos(
                    renderer,
                    textures->secret_1,
                    colors->none,
                    1.0f,
                    vec2i(600, 550),
                    2.0f
                );
            }
            if(state->was_secret_2_taken)
            {
                draw_texture_at_screen_pos(
                    renderer,
                    textures->secret_2,
                    colors->none,
                    1.0f,
                    vec2i(600, 550),
                    2.0f
                );
            }
            if(state->was_secret_3_taken)
            {
                draw_texture_at_screen_pos(
                    renderer,
                    textures->secret_3,
                    colors->none,
                    1.0f,
                    vec2i(600, 550),
                    2.0f
                );
            }
            if(state->was_secret_4_taken)
            {
                draw_texture_at_screen_pos(
                    renderer,
                    textures->secret_4,
                    colors->none,
                    1.0f,
                    vec2i(600, 550),
                    2.0f
                );
            }
        }
        else
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.telekinesis_head,
                colors->none,
                1.0f,
                vec2i(550 + 84, 575),
                2.0f
            );
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 84, 575 + 64 + 10),
                2.0f
            );
        }

        int left_hand_augmentation = state->hero_body_part_augmentation[BODY_PART__LEFT_HAND];
        int right_hand_augmentation = state->hero_body_part_augmentation[BODY_PART__RIGHT_HAND];
        int left_leg_augmentation = state->hero_body_part_augmentation[BODY_PART__LEFT_LEG];
        int right_leg_augmentation = state->hero_body_part_augmentation[BODY_PART__RIGHT_LEG];
        int head_augmentation = state->hero_body_part_augmentation[BODY_PART__HEAD];
        int torso_augmentation = state->hero_body_part_augmentation[BODY_PART__TORSO];

        Texture* left_hand_texture = textures->hud.no_augmentation;
        Texture* right_hand_texture = textures->hud.no_augmentation;
        Texture* left_leg_texture = textures->hud.no_augmentation;
        Texture* right_leg_texture = textures->hud.no_augmentation;
        Texture* head_texture = textures->hud.no_augmentation;
        Texture* torso_texture = textures->hud.no_augmentation;

        if(left_hand_augmentation == AUGMENTATION__FIST_HAND) left_hand_texture = textures->hud.fist_hand;
        if(left_hand_augmentation == AUGMENTATION__HOOK_HAND) left_hand_texture = textures->hud.hook_hand;
        if(right_hand_augmentation == AUGMENTATION__CHAIN_HAND) right_hand_texture = textures->hud.chain_hand;
        if(right_hand_augmentation == AUGMENTATION__SCISSOR_HAND) right_hand_texture = textures->hud.scissor_hand;
        if(left_leg_augmentation == AUGMENTATION__SPRING_LEG) left_leg_texture = textures->hud.spring_leg;
        if(left_leg_augmentation == AUGMENTATION__STRIDER_LEG) left_leg_texture = textures->hud.strider_leg;
        if(right_leg_augmentation == AUGMENTATION__TRACK_LEG) right_leg_texture = textures->hud.track_leg;
        if(right_leg_augmentation == AUGMENTATION__BOOT_LEG) right_leg_texture = textures->hud.boot_leg;
        if(torso_augmentation == AUGMENTATION__MINIBOT_TORSO) torso_texture = textures->hud.minibot_torso;
        if(torso_augmentation == AUGMENTATION__WINGS_TORSO) torso_texture = textures->hud.wings_torso;
        if(head_augmentation == AUGMENTATION__MANIPULATION_HEAD) head_texture = textures->hud.manipulation_head;
        if(head_augmentation == AUGMENTATION__TELEPORTATION_HEAD) head_texture = textures->hud.teleportation_head;
        if(head_augmentation == AUGMENTATION__TELEKINESIS_HEAD) head_texture = textures->hud.telekinesis_head;

        int scale = 2;

        draw_texture_at_screen_pos(
            renderer,
            left_hand_texture,
            colors->none,
            1.0f,
            vec2i(550 + 10, 250 + 42),
            scale
        );
        if(left_hand_augmentation != AUGMENTATION__NONE)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 10, 250 + 116),
                scale
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            head_texture,
            colors->none,
            1.0f,
            vec2i(550 + 84, 250 + 10),
            scale
        );
        if(head_augmentation != AUGMENTATION__NONE)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 84, 250 + 84),
                scale
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            right_hand_texture,
            colors->none,
            1.0f,
            vec2i(550 + 158, 250 + 42),
            scale
        );
        if(right_hand_augmentation != AUGMENTATION__NONE)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 158, 250 + 116),
                scale
            );
        }
        
        draw_texture_at_screen_pos(
            renderer,
            left_leg_texture,
            colors->none,
            1.0f,
            vec2i(550 + 10, 250 + 52 + 116),
            scale
        );
        if(left_leg_augmentation != AUGMENTATION__NONE)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 10, 250 + 52 + 190),
                scale
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            torso_texture,
            colors->none,
            1.0f,
            vec2i(550 + 84, 250 + 52 + 84),
            scale
        );
        if(torso_augmentation != AUGMENTATION__NONE)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 84, 250 + 52 + 158),
                scale
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            right_leg_texture,
            colors->none,
            1.0f,
            vec2i(550 + 158, 250 + 52 + 116),
            scale
        );
        if(right_leg_augmentation != AUGMENTATION__NONE)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.restart_with,
                colors->none,
                1.0f,
                vec2i(550 + 158, 250 + 52 + 190),
                scale
            );
        }

        int is_mouse_on_augmentation_texture = FALSE;
        int mouse_augmentation_texture = AUGMENTATION__NONE;

        if(left_hand_augmentation != AUGMENTATION__NONE &&
           state->mouse_screen_pos.x >= 550 + 10 &&
           state->mouse_screen_pos.x <= 550 + 10 + 64 &&
           state->mouse_screen_pos.y >= 250 + 42 &&
           state->mouse_screen_pos.y <= 250 + 42 + 64)
        {
            is_mouse_on_augmentation_texture = TRUE;
            mouse_augmentation_texture = left_hand_augmentation;
        }
        if(head_augmentation != AUGMENTATION__NONE &&
           state->mouse_screen_pos.x >= 550 + 84 &&
           state->mouse_screen_pos.x <= 550 + 84 + 64 &&
           state->mouse_screen_pos.y >= 250 + 10 &&
           state->mouse_screen_pos.y <= 250 + 10 + 64)
        {
            is_mouse_on_augmentation_texture = TRUE;
            mouse_augmentation_texture = head_augmentation;
        }
        if(right_hand_augmentation != AUGMENTATION__NONE &&
           state->mouse_screen_pos.x >= 550 + 158 &&
           state->mouse_screen_pos.x <= 550 + 158 + 64 &&
           state->mouse_screen_pos.y >= 250 + 42 &&
           state->mouse_screen_pos.y <= 250 + 42 + 64)
        {
            is_mouse_on_augmentation_texture = TRUE;
            mouse_augmentation_texture = right_hand_augmentation;
        }
        if(left_leg_augmentation != AUGMENTATION__NONE &&
           state->mouse_screen_pos.x >= 550 + 10 &&
           state->mouse_screen_pos.x <= 550 + 10 + 64 &&
           state->mouse_screen_pos.y >= 250 + 52 + 116 &&
           state->mouse_screen_pos.y <= 250 + 52 + 116 + 64)
        {
            is_mouse_on_augmentation_texture = TRUE;
            mouse_augmentation_texture = left_leg_augmentation;
        }
        if(torso_augmentation != AUGMENTATION__NONE &&
           state->mouse_screen_pos.x >= 550 + 84 &&
           state->mouse_screen_pos.x <= 550 + 84 + 64 &&
           state->mouse_screen_pos.y >= 250 + 52 + 84 &&
           state->mouse_screen_pos.y <= 250 + 52 + 84 + 64)
        {
            is_mouse_on_augmentation_texture = TRUE;
            mouse_augmentation_texture = torso_augmentation;
        }
        if(right_leg_augmentation != AUGMENTATION__NONE &&
           state->mouse_screen_pos.x >= 550 + 158 &&
           state->mouse_screen_pos.x <= 550 + 158 + 64 &&
           state->mouse_screen_pos.y >= 250 + 52 + 116 &&
           state->mouse_screen_pos.y <= 250 + 52 + 116 + 64)
        {
            is_mouse_on_augmentation_texture = TRUE;
            mouse_augmentation_texture = right_leg_augmentation;
        }

        if(is_mouse_on_augmentation_texture)
        {
            draw_font_at_screen_pos(
                get_augmentation_name(mouse_augmentation_texture),
                renderer,
                fonts->bit_operator_30,
                colors->white,
                1.0f,
                vec2i(560, 530),
                1
            );
        }

        if(state->was_secret_aug_unlocked &&
           state->mouse_screen_pos.x >= 550 + 84 &&
           state->mouse_screen_pos.x <= 550 + 84 + 64 &&
           state->mouse_screen_pos.y >= 575 &&
           state->mouse_screen_pos.y <= 575 + 64)
        {
            draw_font_at_screen_pos(
                get_augmentation_name(AUGMENTATION__TELEKINESIS_HEAD),
                renderer,
                fonts->bit_operator_30,
                colors->white,
                1.0f,
                vec2i(560, 530),
                1
            );
        }
    }

    // fps

    // char fps_text[100];
    // sprintf(fps_text, "fps: %i", (int)(1 / state->delta_time));
    // draw_font_at_screen_pos(
    //     fps_text,
    //     renderer,
    //     fonts->font_30,
    //     colors->white,
    //     1.0f,
    //     vec2i(300,10),
    //     1
    //     );

    // gamestate

    if(state->gamestate != GAMESTATE__GAME_START &&
       state->gamestate != GAMESTATE__GAME_OVER &&
       state->gamestate != GAMESTATE__GAME_WON)
    {
        char* gamestate_text = "";

        switch(state->gamestate)
        {
            case GAMESTATE__ALLY_CHOOSING_SKILL:
            {
                if(state->curr_ally->object->action_points > 0)
                {
                    gamestate_text = "choose skill";
                }
                else
                {
                    gamestate_text = "end turn !";
                }
            }
            break;
            case GAMESTATE__ALLY_CHOOSING_TARGET_1:     gamestate_text = "choose target"; break;
            case GAMESTATE__ALLY_CHOOSING_TARGET_2:     gamestate_text = "choose target"; break;
            case GAMESTATE__ALLY_EXECUTING_ANIMATION:   gamestate_text = ""; break;
            case GAMESTATE__ALLY_EXECUTING_SKILL:       gamestate_text = ""; break;
            case GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK:  gamestate_text = "-enemy turn-"; break;
            case GAMESTATE__ENEMY_EXECUTING_ANIMATION:  gamestate_text = "-enemy turn-"; break;
            case GAMESTATE__ENEMY_EXECUTING_ATTACK:     gamestate_text = "-enemy turn-"; break;
            case GAMESTATE__ENEMY_PAUSE_BEFORE_MOVE:    gamestate_text = "-enemy turn-"; break;
            case GAMESTATE__ENEMY_MOVING:               gamestate_text = "-enemy turn-"; break;
            case GAMESTATE__ENEMY_PAUSE_BEFORE_TARGET:  gamestate_text = "-enemy turn-"; break;
            default: break;
        }

        draw_font_at_screen_pos(
            gamestate_text,
            renderer,
            fonts->bit_operator_50,
            colors->white,
            1.0f,
            vec2i(600 - strlen(gamestate_text) * 10, 10),
            1
        );
    }

    // ap bar

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        if(state->enemy_list->size > 0)
        {
            int curr_ally_ap = state->curr_ally->object->action_points;
            char hero_ap_bar[ALLY_MAX_ACTION_POINTS + 2];
            hero_ap_bar[0] = '[';
            for(int i = 0; i < ALLY_MAX_ACTION_POINTS; i++)
            {
                char character = ' ';

                if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
                   state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
                {
                    int curr_skill_cost = get_skill_action_points(state->curr_ally_skill);
                    if(state->curr_ally_skill == SKILL__MOVE ||
                       state->curr_ally_skill == SKILL__MOVE_FLOATING ||
                       state->curr_ally_skill == SKILL__MOVE_FLYING)
                    {
                        curr_skill_cost = state->ally_move_distance;
                    }
                    if(i < curr_ally_ap - curr_skill_cost) character = '#';
                    else if(i < curr_ally_ap) character = '-';
                }
                else
                {
                    character = (i < curr_ally_ap) ? '#' : ' ';
                }

                hero_ap_bar[i + 1] = character;
            }
            hero_ap_bar[ALLY_MAX_ACTION_POINTS + 1] = ']';

            for(int i = 0; i < ALLY_MAX_ACTION_POINTS; i++)
            {
                Vec3i color = colors->none;

                switch(hero_ap_bar[i + 1])
                {
                    case '#': color = colors->blue; break;
                    case '-': color = colors->red; break;
                    case ' ': color = colors->black; break;
                    default: color = colors->black; break;
                }

                draw_texture_at_screen_pos(
                    renderer,
                    textures->hud.bar_part,
                    color,
                    1.0f,
                    vec2i(550 + 32 * i, 100),
                    1
                );
            }
        }
    }

    // augmentations

    if((state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
        state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
        state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
        state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
        state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL) &&
       (state->curr_ally->object->type == OBJECT__HERO ||
        state->curr_ally->object->type == OBJECT__HERO_FLOATING ||
        state->curr_ally->object->type == OBJECT__HERO_FLYING))
    {
        int left_hand_augmentation = state->hero_body_part_augmentation[BODY_PART__LEFT_HAND];
        int right_hand_augmentation = state->hero_body_part_augmentation[BODY_PART__RIGHT_HAND];
        int left_leg_augmentation = state->hero_body_part_augmentation[BODY_PART__LEFT_LEG];
        int right_leg_augmentation = state->hero_body_part_augmentation[BODY_PART__RIGHT_LEG];
        int head_augmentation = state->hero_body_part_augmentation[BODY_PART__HEAD];
        int torso_augmentation = state->hero_body_part_augmentation[BODY_PART__TORSO];

        Texture* left_hand_texture = textures->hud.no_augmentation;
        Texture* right_hand_texture = textures->hud.no_augmentation;
        Texture* left_leg_texture = textures->hud.no_augmentation;
        Texture* right_leg_texture = textures->hud.no_augmentation;
        Texture* head_texture = textures->hud.no_augmentation;
        Texture* torso_texture = textures->hud.no_augmentation;

        if(left_hand_augmentation == AUGMENTATION__FIST_HAND) left_hand_texture = textures->hud.fist_hand;
        if(left_hand_augmentation == AUGMENTATION__HOOK_HAND) left_hand_texture = textures->hud.hook_hand;
        if(right_hand_augmentation == AUGMENTATION__CHAIN_HAND) right_hand_texture = textures->hud.chain_hand;
        if(right_hand_augmentation == AUGMENTATION__SCISSOR_HAND) right_hand_texture = textures->hud.scissor_hand;
        if(left_leg_augmentation == AUGMENTATION__SPRING_LEG) left_leg_texture = textures->hud.spring_leg;
        if(left_leg_augmentation == AUGMENTATION__STRIDER_LEG) left_leg_texture = textures->hud.strider_leg;
        if(right_leg_augmentation == AUGMENTATION__TRACK_LEG) right_leg_texture = textures->hud.track_leg;
        if(right_leg_augmentation == AUGMENTATION__BOOT_LEG) right_leg_texture = textures->hud.boot_leg;
        if(torso_augmentation == AUGMENTATION__MINIBOT_TORSO) torso_texture = textures->hud.minibot_torso;
        if(torso_augmentation == AUGMENTATION__WINGS_TORSO) torso_texture = textures->hud.wings_torso;
        if(head_augmentation == AUGMENTATION__MANIPULATION_HEAD) head_texture = textures->hud.manipulation_head;
        if(head_augmentation == AUGMENTATION__TELEPORTATION_HEAD) head_texture = textures->hud.teleportation_head;
        if(head_augmentation == AUGMENTATION__TELEKINESIS_HEAD) head_texture = textures->hud.telekinesis_head;

        int scale = 2;

        draw_texture_at_screen_pos(
            renderer,
            left_hand_texture,
            colors->none,
            1.0f,
            vec2i(10, 42),
            scale
        );
        draw_texture_at_screen_pos(
            renderer,
            head_texture,
            colors->none,
            1.0f,
            vec2i(84, 10),
            scale
        );
        draw_texture_at_screen_pos(
            renderer,
            right_hand_texture,
            colors->none,
            1.0f,
            vec2i(158, 42),
            scale
        );
        draw_texture_at_screen_pos(
            renderer,
            left_leg_texture,
            colors->none,
            1.0f,
            vec2i(10, 116),
            scale
        );
        draw_texture_at_screen_pos(
            renderer,
            torso_texture,
            colors->none,
            1.0f,
            vec2i(84, 84),
            scale
        );
        draw_texture_at_screen_pos(
            renderer,
            right_leg_texture,
            colors->none,
            1.0f,
            vec2i(158, 116),
            scale
        );

        int is_mouse_on_augmentation = FALSE;
        int mouse_augmentation = AUGMENTATION__NONE;

        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 42 &&
           state->mouse_screen_pos.y <= 42 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = left_hand_augmentation;
        }
        if(state->mouse_screen_pos.x >= 84 &&
           state->mouse_screen_pos.x <= 84 + 64 &&
           state->mouse_screen_pos.y >= 10 &&
           state->mouse_screen_pos.y <= 10 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = head_augmentation;
        }
        if(state->mouse_screen_pos.x >= 158 &&
           state->mouse_screen_pos.x <= 158 + 64 &&
           state->mouse_screen_pos.y >= 42 &&
           state->mouse_screen_pos.y <= 42 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = right_hand_augmentation;
        }
        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 116 &&
           state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = left_leg_augmentation;
        }
        if(state->mouse_screen_pos.x >= 84 &&
           state->mouse_screen_pos.x <= 84 + 64 &&
           state->mouse_screen_pos.y >= 84 &&
           state->mouse_screen_pos.y <= 84 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = torso_augmentation;
        }
        if(state->mouse_screen_pos.x >= 158 &&
           state->mouse_screen_pos.x <= 158 + 64 &&
           state->mouse_screen_pos.y >= 116 &&
           state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = right_leg_augmentation;
        }

        if(is_mouse_on_augmentation)
        {
            draw_font_at_screen_pos(
                get_augmentation_name(mouse_augmentation),
                renderer,
                fonts->bit_operator_30,
                colors->white,
                1.0f,
                vec2i(10, 180),
                1
            );
        }
    }

    // items

    if((state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
        state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
        state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
        state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
        state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL) &&
       (state->curr_ally->object->type == OBJECT__HERO ||
        state->curr_ally->object->type == OBJECT__HERO_FLOATING ||
        state->curr_ally->object->type == OBJECT__HERO_FLYING))
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.cell,
            colors->none,
            1.0f,
            vec2i(10, 120 + 100),
            4
        );
        if(state->hero_item_number[ITEM__CELL] > 9)
        {
            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__CELL] / 10),
                colors->none,
                1.0f,
                vec2i(32, 120 + 100),
                2
            );
            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__CELL] % 10),
                colors->none,
                1.0f,
                vec2i(64, 120 + 100),
                2
            );
        }
        else
        {

            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__CELL]),
                colors->none,
                1.0f,
                vec2i(32, 120 + 100),
                2
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.dynamite,
            colors->none,
            1.0f,
            vec2i(10, 194 + 100),
            4
        );
        if(state->hero_item_number[ITEM__DYNAMITE] > 9)
        {
            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE] / 10),
                colors->none,
                1.0f,
                vec2i(32, 194 + 100),
                2
            );
            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE] % 10),
                colors->none,
                1.0f,
                vec2i(64, 194 + 100),
                2
            );
        }
        else
        {

            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE]),
                colors->none,
                1.0f,
                vec2i(32, 194 + 100),
                2
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.gemstone,
            colors->none,
            1.0f,
            vec2i(10, 268 + 100),
            4
        );
        if(state->hero_item_number[ITEM__GEMSTONE] > 9)
        {
            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE] / 10),
                colors->none,
                1.0f,
                vec2i(32, 268 + 100),
                2
            );
            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE] % 10),
                colors->none,
                1.0f,
                vec2i(64, 268 + 100),
                2
            );
        }
        else
        {

            draw_texture_at_screen_pos(
                renderer,
                get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE]),
                colors->none,
                1.0f,
                vec2i(32, 268 + 100),
                2
            );
        }

        int is_mouse_on_item = FALSE;
        int mouse_item = ITEM__NONE;

        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 120 + 100 &&
           state->mouse_screen_pos.y <= 120 + 100 + 64)
        {
            is_mouse_on_item = TRUE;
            mouse_item = ITEM__CELL;
        }
        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 194 + 100 &&
           state->mouse_screen_pos.y <= 194 + 100 + 64)
        {
            is_mouse_on_item = TRUE;
            mouse_item = ITEM__DYNAMITE;
        }
        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 268 + 100 &&
           state->mouse_screen_pos.y <= 268 + 100 + 64)
        {
            is_mouse_on_item = TRUE;
            mouse_item = ITEM__GEMSTONE;
        }

        if(is_mouse_on_item)
        {
            draw_font_at_screen_pos(
                get_name_from_item(mouse_item),
                renderer,
                fonts->bit_operator_30,
                colors->white,
                1.0f,
                vec2i(10, 180),
                1
            );
        }
    }

    // skill description

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        draw_font_at_screen_pos(
            get_description_from_skill(state->curr_ally_skill, 1),
            renderer,
            fonts->bit_operator_20,
            colors->white,
            1.0f,
            vec2i(10 + 128 + 128 + 10 + 10, 600 + 50),
            1
        );
        
        draw_font_at_screen_pos(
            get_description_from_skill(state->curr_ally_skill, 2),
            renderer,
            fonts->bit_operator_20,
            colors->white,
            1.0f,
            vec2i(10 + 128 + 128 + 10 + 10, 600 + 50 + 30),
            1
        );
        
        draw_font_at_screen_pos(
            get_description_from_skill(state->curr_ally_skill, 3),
            renderer,
            fonts->bit_operator_20,
            colors->white,
            1.0f,
            vec2i(10 + 128 + 128 + 10 + 10, 600 + 50 + 30 + 30),
            1
        );
        
        draw_font_at_screen_pos(
            get_description_from_skill(state->curr_ally_skill, 4),
            renderer,
            fonts->bit_operator_20,
            colors->white,
            1.0f,
            vec2i(10 + 128 + 128 + 10 + 10, 600 + 50 + 30 + 30 + 30),
            1
        );
    }

    // object

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
       state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
       state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        Texture* object_texture = get_hud_texture_from_object(
            state->curr_ally->object,
            textures
        );

        draw_texture_at_screen_pos(
            renderer,
            object_texture,
            colors->none,
            1.0f,
            vec2i(10, 600 + 50),
            4
        );
    }
    else if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
            state->gamestate == GAMESTATE__ENEMY_EXECUTING_ANIMATION ||
            state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK)
    {
        Texture* object_texture = get_hud_texture_from_object(
            state->curr_enemy->object,
            textures
        );

        draw_texture_at_screen_pos(
            renderer,
            object_texture,
            colors->none,
            1.0f,
            vec2i(10, 600 + 50),
            4
        );
    }

    // skills

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL)
    {
        if(state->curr_ally->object->action_points > 0)
        {
            int mouse_hover_skill = SKILL__NONE;

            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    int index = i * 2 + j;

                    if(index < state->curr_ally->skill_list->size)
                    {
                        ListElem* skill_list_elem =
                            get_nth_list_element(
                                state->curr_ally->skill_list,
                                index
                            );

                        if(skill_list_elem != NULL)
                        {
                            int skill = (int) skill_list_elem->data;

                            Texture* skill_texture = get_skill_hud_texture(
                                skill,
                                textures
                            );

                            if(skill_texture == NULL)
                            {
                                skill_texture = textures->hud.no_augmentation;
                            }

                            draw_texture_at_screen_pos(
                                renderer,
                                skill_texture,
                                colors->none,
                                1.0f,
                                vec2i(
                                    138 + 10 * (i + 1) + 64 * i,
                                    600 + 10 * j + 64 * j + 50
                                ),
                                2
                            );

                            if(state->mouse_screen_pos.x >= 138 + 10 * (i + 1) + 64 * i &&
                            state->mouse_screen_pos.x <= 138 + 10 * (i + 1) + 64 * i + 64 &&
                            state->mouse_screen_pos.y >= 600 + 50 + 10 * j + 64 * j &&
                            state->mouse_screen_pos.y <= 600 + 50 + 10 * j + 64 * j + 64)
                            {
                                mouse_hover_skill = skill;
                            }
                        }
                    }
                }
            }

            if(mouse_hover_skill == SKILL__NONE)
            {
                draw_font_at_screen_pos(
                    get_in_game_name_from_object_type(state->curr_ally->object->type),
                    renderer,
                    fonts->bit_operator_30,
                    colors->white,
                    1.0f,
                    vec2i(10, 550 + 50),
                    1
                );
            }
            else
            {
                draw_font_at_screen_pos(
                    get_in_game_skill_name(mouse_hover_skill),
                    renderer,
                    fonts->bit_operator_30,
                    colors->white,
                    1.0f,
                    vec2i(10, 550 + 50),
                    1
                );
            }
        }
        else
        {
            draw_font_at_screen_pos(
                get_in_game_name_from_object_type(state->curr_ally->object->type),
                renderer,
                fonts->bit_operator_30,
                colors->white,
                1.0f,
                vec2i(10, 550 + 50),
                1
            );
        }
    }
    else if(state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
            state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
            state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
            state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        int skill = state->curr_ally_skill;

        draw_font_at_screen_pos(
            get_in_game_skill_name(skill),
            renderer,
            fonts->bit_operator_30,
            colors->white,
            1.0f,
            vec2i(10, 550 + 50),
            1
        );

        Texture* skill_texture = get_skill_hud_texture(
            skill,
            textures
        );

        draw_texture_at_screen_pos(
            renderer,
            skill_texture,
            colors->none,
            1.0f,
            vec2i(148, 600 + 50),
            4
        );
    }
    else if(state->gamestate == GAMESTATE__ENEMY_PAUSE_BEFORE_ATTACK ||
            state->gamestate == GAMESTATE__ENEMY_EXECUTING_ANIMATION ||
            state->gamestate == GAMESTATE__ENEMY_EXECUTING_ATTACK)
    {
        int skill = state->curr_enemy->skill;

        draw_font_at_screen_pos(
            get_in_game_skill_name(skill),
            renderer,
            fonts->bit_operator_30,
            colors->white,
            1.0f,
            vec2i(10, 550 + 50),
            1
        );

        Texture* skill_texture = get_skill_hud_texture(
            skill,
            textures
        );

        draw_texture_at_screen_pos(
            renderer,
            skill_texture,
            colors->none,
            1.0f,
            vec2i(148, 600 + 50),
            4
        );
    }

    // selected floor and object

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    {
        if(is_tilemap_in_bounds(state->mouse_tilemap_pos))
        {
            int floor = room_get_floor_at(
                state->curr_room,
                state->mouse_tilemap_pos
            );
            Object* object = room_get_object_at(
                state->curr_room,
                state->mouse_tilemap_pos
            );

            if(floor != FLOOR__NONE)
            {
                if(object == NULL)
                {
                    if(!is_floor_traversable_for_object(floor, state->curr_ally->object))
                    {
                        draw_texture_at_screen_pos(
                            renderer,
                            textures->hud.status_floor_not_traversable,
                            colors->none,
                            1.0f,
                            vec2i(900 + 100 + 40 * 0, 550 + 50 - 30),
                            1
                        );
                    }

                    if(is_floor_deadly_on_move_for_object(floor, state->curr_ally->object))
                    {
                        draw_texture_at_screen_pos(
                            renderer,
                            textures->hud.status_floor_deadly,
                            colors->none,
                            1.0f,
                            vec2i(900 + 100 + 40 * 2, 550 + 50 - 30),
                            1
                        );
                    }

                    if(is_floor_deadly_on_drop_for_object(floor, state->curr_ally->object))
                    {
                        draw_texture_at_screen_pos(
                            renderer,
                            textures->hud.status_floor_warning,
                            colors->none,
                            1.0f,
                            vec2i(900 + 100 + 40 * 4, 550 + 50 - 30),
                            1
                        );
                    }

                    if(is_floor_manipulatable(floor))
                    {
                        draw_texture_at_screen_pos(
                            renderer,
                            textures->hud.status_floor_manipulatable,
                            colors->none,
                            1.0f,
                            vec2i(900 + 100 + 40 * 6, 550 + 50 - 30),
                            1
                        );
                    }

                    Vec3i color = colors->white;
                
                    if(is_floor_manipulatable(floor))
                    {
                        color = colors->green_light;
                    }
                    if(is_floor_exit(floor))
                    {
                        color = colors->pink_light;
                    }

                    draw_font_at_screen_pos(
                        get_in_game_name_from_floor(floor),
                        renderer,
                        fonts->bit_operator_30,
                        color,
                        1.0f,
                        vec2i(900 + 100, 550 + 50),
                        1
                    );
                }

                Texture* texture = get_texture_1_from_floor_type(floor, textures);

                draw_texture_at_screen_pos(
                    renderer,
                    texture,
                    colors->none,
                    1.0f,
                    vec2i(1050 + 100, 600 + 50),
                    2
                );
            }

            if(object != NULL)
            {
                if(is_object_stone(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_stone,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 0, 550 + 50 - 30),
                        1
                    );
                }
                else if(is_object_metal(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_metal,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 0, 550 + 50 - 30),
                        1
                    );
                }
                else if(is_object_glass(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_glass,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 0, 550 + 50 - 30),
                        1
                    );
                }

                if(is_object_fragile(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_fragile,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 1, 550 + 50 - 30),
                        1
                    );
                }
                
                if(!is_object_movable(object) && is_object_pull_towards(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_stable,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 2, 550 + 50 - 30),
                        1
                    );
                }

                if(!is_object_throw_over(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_high,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 3, 550 + 50 - 30),
                        1
                    );
                }
                
                if(is_object_flying(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_flying,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 4, 550 + 50 - 30),
                        1
                    );
                }
                else if(is_object_floating(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_floating,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 4, 550 + 50 - 30),
                        1
                    );
                }
                
                if(is_object_exit(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_exit,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 5, 550 + 50 - 30),
                        1
                    );
                }
                else if(is_object_wall(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_wall,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 5, 550 + 50 - 30),
                        1
                    );
                }
                
                if(is_object_manipulatable(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_manipulatable,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 6, 550 + 50 - 30),
                        1
                    );
                }
                else if(is_object_station(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        textures->hud.status_station,
                        colors->none,
                        1.0f,
                        vec2i(900 + 100 + 40 * 6, 550 + 50 - 30),
                        1
                    );
                }

                Vec3i color = colors->white;
                
                if(is_object_meltable(object))
                {
                    color = colors->blue_light;
                }
                if(is_object_breakable(object))
                {
                    color = colors->brown_light;
                }
                if(is_object_manipulatable(object))
                {
                    color = colors->green_light;
                }
                if(is_object_exit(object) || 
                is_object_station(object)|| 
                is_object_secret(object) || 
                object->type == OBJECT__THRONE)
                {
                    color = colors->pink_light;
                }

                draw_font_at_screen_pos(
                    get_in_game_name_from_object_type(object->type),
                    renderer,
                    fonts->bit_operator_30,
                    color,
                    1.0f,
                    vec2i(900 + 100, 550 + 50),
                    1
                );

                Texture* texture = get_texture_1_from_object(object, textures);
                Texture* texture_outline = get_texture_1_outline_from_object(object, textures);

                draw_texture_at_screen_pos(
                    renderer,
                    texture,
                    colors->none,
                    1.0f,
                    vec2i(900 + 100, 600 + 50),
                    2
                );

                if(is_object_ally(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        texture_outline,
                        colors->green,
                        1.0f,
                        vec2i(900 + 100, 600 + 50),
                        2
                    );
                }

                if(is_object_enemy(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        texture_outline,
                        colors->red,
                        1.0f,
                        vec2i(900 + 100, 600 + 50),
                        2
                    );
                }
            }
        }
    }

    // reset turn

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL &&
       state->enemy_list->size > 0)
    {
        if(state->reset_turn_uses > 0)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.reset_turn,
                colors->none,
                1.0f,
                vec2i(300, 10),
                2
            );
        }
        else
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.reset_turn_inactive,
                colors->none,
                1.0f,
                vec2i(300, 10),
                2
            );
        }

        Texture* reset_turn_texture = NULL;

        if(state->reset_turn_uses == 3) reset_turn_texture = textures->hud.reset_turn_3x;
        else if(state->reset_turn_uses == 2) reset_turn_texture = textures->hud.reset_turn_2x;
        else if(state->reset_turn_uses == 1) reset_turn_texture = textures->hud.reset_turn_1x;
        else reset_turn_texture = textures->hud.reset_turn_used;

        draw_texture_at_screen_pos(
            renderer,
            reset_turn_texture,
            colors->none,
            1.0f,
            vec2i(300, 10 + 64 + 10),
            2
        );
    }

    // end turn

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL &&
       state->enemy_list->size > 0)
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.end_turn,
            colors->none,
            1.0f,
            vec2i(1200 - 300, 10),
            2
        );
    }

    // show attack order

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL &&
       state->enemy_list->size > 0)
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.show_attack_order,
            colors->none,
            1.0f,
            vec2i(1200 - 64 - 10 + 100, 10),
            2
        );
    }

    // attack order

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
       state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
       state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
       state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        int go_on = TRUE;
        for(int i = 1; i < 10 && go_on; i++)
        {
            Object* object = NULL;

            for(ListElem* curr_elem = state->enemy_list->head;
                curr_elem != NULL; curr_elem = curr_elem->next)
            {
                Enemy* curr_enemy = curr_elem->data;

                if(curr_enemy->order_number == i)
                {
                    object = curr_enemy->object;
                }
            }

            if(object == NULL)
            {
                go_on = FALSE;
            }
            else
            {
                Texture* object_texture = get_hud_texture_from_object(
                    object,
                    textures
                );

                draw_texture_at_screen_pos(
                    renderer,
                    get_texture_order_number(textures, i),
                    colors->none,
                    1.0f,
                    vec2i(
                        1200 - 10 - 64 - 10 - 64 - 16 + 100,
                        10 + 64 + 10 * i + 64 * (i - 1)
                    ),
                    2
                );

                draw_texture_at_screen_pos(
                    renderer,
                    object_texture,
                    colors->none,
                    1.0f,
                    vec2i(
                        1200 - 10 - 64 + 100,
                        10 + 64 + 10 * i + 64 * (i - 1)
                    ),
                    2
                );
            }
        }
    }
}
