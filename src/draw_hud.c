#include "../inc/game.h"
#include <SDL2/SDL_stdinc.h>
#include <math.h>
#include <string.h>

void draw_hud(Renderer* renderer, State* state, Textures* textures, Colors* colors, Fonts* fonts)
{
    // game start

    if(state->gamestate == GAMESTATE__GAME_START)
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->black_box,
            colors->black,
            0.2f,
            vec2i(0, 0),
            150.0f
        );

        draw_font_at_screen_pos(
            "Fallen Stalactite",
            renderer,
            fonts->stepalange_150,
            colors->white,
            1.0f,
            vec2i(200, 100),
            1
        );

        SDL_RWops* file = SDL_RWFromFile( "save_0.save", "r");
        if(file == NULL)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.load_game_inactive,
                colors->none,
                1.0f,
                vec2i(600, 300),
                2.0f
            );
        }
        else
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.load_game,
                colors->none,
                1.0f,
                vec2i(600, 300),
                2.0f
            );
        }

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.new_game,
            colors->none,
            1.0f,
            vec2i(600, 400),
            2.0f
        );

        if(state->show_tutorial)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.show_tutorial_checked,
                colors->none,
                1.0f,
                vec2i(575, 500),
                2.0f
            );
        }
        else
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.show_tutorial,
                colors->none,
                1.0f,
                vec2i(575, 500),
                2.0f
            );
        }
    }

    // game over

    if(state->gamestate == GAMESTATE__GAME_OVER)
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->black_box,
            colors->black,
            0.2f,
            vec2i(0, 0),
            150.0f
        );

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

        // Texture* game_over_texture = NULL;

        // if(state->game_over_uses == 3) game_over_texture = textures->hud.reset_turn_3x;
        // else if(state->game_over_uses == 2) game_over_texture = textures->hud.reset_turn_2x;
        // else if(state->game_over_uses == 1) game_over_texture = textures->hud.reset_turn_1x;

        // draw_texture_at_screen_pos(
        //     renderer,
        //     game_over_texture,
        //     colors->none,
        //     1.0f,
        //     vec2i(600 + 32, 300 + 64 + 10),
        //     2.0f
        // );
    }

    // game won

    // if(state->gamestate == GAMESTATE__GAME_WON)
    // {
    //     draw_texture_at_screen_pos(
    //         renderer,
    //         textures->black_box,
    //         colors->black,
    //         0.2f,
    //         vec2i(0, 0),
    //         150.0f
    //     );

    //     draw_font_at_screen_pos(
    //         "You Won!",
    //         renderer,
    //         fonts->stepalange_100,
    //         colors->white,
    //         1.0f,
    //         vec2i(500, 100),
    //         1
    //     );
    //     draw_texture_at_screen_pos(
    //         renderer,
    //         textures->hud.restart_with_no_aug,
    //         colors->none,
    //         1.0f,
    //         vec2i(570, 700),
    //         2.0f
    //     );

    //     if(!state->was_secret_aug_unlocked &&
    //     (state->was_secret_1_taken ||
    //     state->was_secret_2_taken ||
    //     state->was_secret_3_taken ||
    //     state->was_secret_4_taken))
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->secret_background,
    //             colors->none,
    //             1.0f,
    //             vec2i(600, 550),
    //             2.0f
    //         );
    //         if(state->was_secret_1_taken)
    //         {
    //             draw_texture_at_screen_pos(
    //                 renderer,
    //                 textures->secret_1,
    //                 colors->none,
    //                 1.0f,
    //                 vec2i(600, 550),
    //                 2.0f
    //             );
    //         }
    //         if(state->was_secret_2_taken)
    //         {
    //             draw_texture_at_screen_pos(
    //                 renderer,
    //                 textures->secret_2,
    //                 colors->none,
    //                 1.0f,
    //                 vec2i(600, 550),
    //                 2.0f
    //             );
    //         }
    //         if(state->was_secret_3_taken)
    //         {
    //             draw_texture_at_screen_pos(
    //                 renderer,
    //                 textures->secret_3,
    //                 colors->none,
    //                 1.0f,
    //                 vec2i(600, 550),
    //                 2.0f
    //             );
    //         }
    //         if(state->was_secret_4_taken)
    //         {
    //             draw_texture_at_screen_pos(
    //                 renderer,
    //                 textures->secret_4,
    //                 colors->none,
    //                 1.0f,
    //                 vec2i(600, 550),
    //                 2.0f
    //             );
    //         }
    //     }
        
    //     if(state->was_secret_aug_unlocked)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.aug_telekinesis_head,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 84, 575),
    //             2.0f
    //         );
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 84, 575 + 64 + 10),
    //             2.0f
    //         );
    //     }

    //     int left_hand_augmentation = state->hero_body_part_augmentation[BODY_PART__LEFT_HAND];
    //     int right_hand_augmentation = state->hero_body_part_augmentation[BODY_PART__RIGHT_HAND];
    //     int left_leg_augmentation = state->hero_body_part_augmentation[BODY_PART__LEFT_LEG];
    //     int right_leg_augmentation = state->hero_body_part_augmentation[BODY_PART__RIGHT_LEG];
    //     int head_augmentation = state->hero_body_part_augmentation[BODY_PART__HEAD];
    //     int torso_augmentation = state->hero_body_part_augmentation[BODY_PART__TORSO];

    //     Texture* left_hand_texture = textures->hud.aug_none;
    //     Texture* right_hand_texture = textures->hud.aug_none;
    //     Texture* left_leg_texture = textures->hud.aug_none;
    //     Texture* right_leg_texture = textures->hud.aug_none;
    //     Texture* head_texture = textures->hud.aug_none;
    //     Texture* torso_texture = textures->hud.aug_none;

    //     if(left_hand_augmentation == AUGMENTATION__FIST_HAND) left_hand_texture = textures->hud.aug_fist_hand;
    //     if(left_hand_augmentation == AUGMENTATION__HOOK_HAND) left_hand_texture = textures->hud.aug_hook_hand;
    //     if(right_hand_augmentation == AUGMENTATION__CHAIN_HAND) right_hand_texture = textures->hud.aug_chain_hand;
    //     if(right_hand_augmentation == AUGMENTATION__SCISSOR_HAND) right_hand_texture = textures->hud.aug_scissor_hand;
    //     if(left_leg_augmentation == AUGMENTATION__SPRING_LEG) left_leg_texture = textures->hud.aug_spring_leg;
    //     if(left_leg_augmentation == AUGMENTATION__STRIDER_LEG) left_leg_texture = textures->hud.aug_strider_leg;
    //     if(right_leg_augmentation == AUGMENTATION__TRACK_LEG) right_leg_texture = textures->hud.aug_track_leg;
    //     if(right_leg_augmentation == AUGMENTATION__BOOT_LEG) right_leg_texture = textures->hud.aug_boot_leg;
    //     if(torso_augmentation == AUGMENTATION__MINIBOT_TORSO) torso_texture = textures->hud.aug_minibot_torso;
    //     if(torso_augmentation == AUGMENTATION__WINGS_TORSO) torso_texture = textures->hud.aug_wings_torso;
    //     if(head_augmentation == AUGMENTATION__MANIPULATION_HEAD) head_texture = textures->hud.aug_manipulation_head;
    //     if(head_augmentation == AUGMENTATION__TELEPORTATION_HEAD) head_texture = textures->hud.aug_teleportation_head;
    //     if(head_augmentation == AUGMENTATION__TELEKINESIS_HEAD) head_texture = textures->hud.aug_telekinesis_head;

    //     int scale = 2;

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         left_hand_texture,
    //         colors->none,
    //         1.0f,
    //         vec2i(550 + 10, 250 + 42),
    //         scale
    //     );
    //     if(left_hand_augmentation != AUGMENTATION__NONE)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 10, 250 + 116),
    //             scale
    //         );
    //     }

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         head_texture,
    //         colors->none,
    //         1.0f,
    //         vec2i(550 + 84, 250 + 10),
    //         scale
    //     );
    //     if(head_augmentation != AUGMENTATION__NONE)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 84, 250 + 84),
    //             scale
    //         );
    //     }

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         right_hand_texture,
    //         colors->none,
    //         1.0f,
    //         vec2i(550 + 158, 250 + 42),
    //         scale
    //     );
    //     if(right_hand_augmentation != AUGMENTATION__NONE)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 158, 250 + 116),
    //             scale
    //         );
    //     }
        
    //     draw_texture_at_screen_pos(
    //         renderer,
    //         left_leg_texture,
    //         colors->none,
    //         1.0f,
    //         vec2i(550 + 10, 250 + 52 + 116),
    //         scale
    //     );
    //     if(left_leg_augmentation != AUGMENTATION__NONE)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 10, 250 + 52 + 190),
    //             scale
    //         );
    //     }

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         torso_texture,
    //         colors->none,
    //         1.0f,
    //         vec2i(550 + 84, 250 + 52 + 84),
    //         scale
    //     );
    //     if(torso_augmentation != AUGMENTATION__NONE)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 84, 250 + 52 + 158),
    //             scale
    //         );
    //     }

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         right_leg_texture,
    //         colors->none,
    //         1.0f,
    //         vec2i(550 + 158, 250 + 52 + 116),
    //         scale
    //     );
    //     if(right_leg_augmentation != AUGMENTATION__NONE)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             textures->hud.restart_with,
    //             colors->none,
    //             1.0f,
    //             vec2i(550 + 158, 250 + 52 + 190),
    //             scale
    //         );
    //     }

    //     int is_mouse_on_augmentation_texture = FALSE;
    //     int mouse_augmentation_texture = AUGMENTATION__NONE;

    //     if(left_hand_augmentation != AUGMENTATION__NONE &&
    //        state->mouse_screen_pos.x >= 550 + 10 &&
    //        state->mouse_screen_pos.x <= 550 + 10 + 64 &&
    //        state->mouse_screen_pos.y >= 250 + 42 &&
    //        state->mouse_screen_pos.y <= 250 + 42 + 64)
    //     {
    //         is_mouse_on_augmentation_texture = TRUE;
    //         mouse_augmentation_texture = left_hand_augmentation;
    //     }
    //     if(head_augmentation != AUGMENTATION__NONE &&
    //        state->mouse_screen_pos.x >= 550 + 84 &&
    //        state->mouse_screen_pos.x <= 550 + 84 + 64 &&
    //        state->mouse_screen_pos.y >= 250 + 10 &&
    //        state->mouse_screen_pos.y <= 250 + 10 + 64)
    //     {
    //         is_mouse_on_augmentation_texture = TRUE;
    //         mouse_augmentation_texture = head_augmentation;
    //     }
    //     if(right_hand_augmentation != AUGMENTATION__NONE &&
    //        state->mouse_screen_pos.x >= 550 + 158 &&
    //        state->mouse_screen_pos.x <= 550 + 158 + 64 &&
    //        state->mouse_screen_pos.y >= 250 + 42 &&
    //        state->mouse_screen_pos.y <= 250 + 42 + 64)
    //     {
    //         is_mouse_on_augmentation_texture = TRUE;
    //         mouse_augmentation_texture = right_hand_augmentation;
    //     }
    //     if(left_leg_augmentation != AUGMENTATION__NONE &&
    //        state->mouse_screen_pos.x >= 550 + 10 &&
    //        state->mouse_screen_pos.x <= 550 + 10 + 64 &&
    //        state->mouse_screen_pos.y >= 250 + 52 + 116 &&
    //        state->mouse_screen_pos.y <= 250 + 52 + 116 + 64)
    //     {
    //         is_mouse_on_augmentation_texture = TRUE;
    //         mouse_augmentation_texture = left_leg_augmentation;
    //     }
    //     if(torso_augmentation != AUGMENTATION__NONE &&
    //        state->mouse_screen_pos.x >= 550 + 84 &&
    //        state->mouse_screen_pos.x <= 550 + 84 + 64 &&
    //        state->mouse_screen_pos.y >= 250 + 52 + 84 &&
    //        state->mouse_screen_pos.y <= 250 + 52 + 84 + 64)
    //     {
    //         is_mouse_on_augmentation_texture = TRUE;
    //         mouse_augmentation_texture = torso_augmentation;
    //     }
    //     if(right_leg_augmentation != AUGMENTATION__NONE &&
    //        state->mouse_screen_pos.x >= 550 + 158 &&
    //        state->mouse_screen_pos.x <= 550 + 158 + 64 &&
    //        state->mouse_screen_pos.y >= 250 + 52 + 116 &&
    //        state->mouse_screen_pos.y <= 250 + 52 + 116 + 64)
    //     {
    //         is_mouse_on_augmentation_texture = TRUE;
    //         mouse_augmentation_texture = right_leg_augmentation;
    //     }

    //     if(is_mouse_on_augmentation_texture)
    //     {
    //         draw_font_at_screen_pos(
    //             get_augmentation_name(mouse_augmentation_texture),
    //             renderer,
    //             fonts->bit_operator_30,
    //             colors->white,
    //             1.0f,
    //             vec2i(560, 530),
    //             1
    //         );
    //     }

    //     if(state->was_secret_aug_unlocked &&
    //        state->mouse_screen_pos.x >= 550 + 84 &&
    //        state->mouse_screen_pos.x <= 550 + 84 + 64 &&
    //        state->mouse_screen_pos.y >= 575 &&
    //        state->mouse_screen_pos.y <= 575 + 64)
    //     {
    //         draw_font_at_screen_pos(
    //             get_augmentation_name(AUGMENTATION__TELEKINESIS_HEAD),
    //             renderer,
    //             fonts->bit_operator_30,
    //             colors->white,
    //             1.0f,
    //             vec2i(560, 530),
    //             1
    //         );
    //     }
    // }

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

    // if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    //    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    //    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    // {
    //     if(state->enemy_list->size > 0)
    //     {
    //         int curr_ally_ap = state->curr_ally->object->action_points;
    //         char hero_ap_bar[ALLY_MAX_ACTION_POINTS + 2];
    //         hero_ap_bar[0] = '[';
    //         for(int i = 0; i < ALLY_MAX_ACTION_POINTS; i++)
    //         {
    //             char character = ' ';

    //             if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    //                state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    //                state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2)
    //             {
    //                 int curr_skill_cost = get_skill_action_points(state->curr_ally_skill);
    //                 if(state->curr_ally_skill == SKILL__MOVE ||
    //                    state->curr_ally_skill == SKILL__MOVE_FLOATING ||
    //                    state->curr_ally_skill == SKILL__MOVE_FLYING)
    //                 {
    //                     curr_skill_cost = state->ally_move_distance;
    //                 }
    //                 if(i < curr_ally_ap - curr_skill_cost) character = '#';
    //                 else if(i < curr_ally_ap) character = '-';
    //             }
    //             else
    //             {
    //                 character = (i < curr_ally_ap) ? '#' : ' ';
    //             }

    //             hero_ap_bar[i + 1] = character;
    //         }
    //         hero_ap_bar[ALLY_MAX_ACTION_POINTS + 1] = ']';

    //         for(int i = 0; i < ALLY_MAX_ACTION_POINTS; i++)
    //         {
    //             Vec3i color = colors->none;

    //             switch(hero_ap_bar[i + 1])
    //             {
    //                 case '#': color = colors->blue; break;
    //                 case '-': color = colors->red; break;
    //                 case ' ': color = colors->black; break;
    //                 default: color = colors->black; break;
    //             }

    //             draw_texture_at_screen_pos(
    //                 renderer,
    //                 textures->hud.bar_part,
    //                 color,
    //                 1.0f,
    //                 vec2i(550 + 32 * i, 100),
    //                 1
    //             );
    //         }
    //     }
    // }

    // tutorial

    // no tutorial now
    state->show_tutorial = FALSE;

    if((state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2) &&
    state->show_tutorial && !state->was_tutorial_finished)
    {
        int n = 0;
        char* line_1 = "";
        char* line_2 = "";
        char* line_3 = "";
        char* line_4 = "";

        get_tutorial_line_and_update_tutorial(state, &n, &line_1, &line_2, &line_3, &line_4);

        Vec3i color = colors->green_light;
        char n_str[16] = "";
        sprintf(n_str, " -- %i -- ", n);

        draw_font_at_screen_pos(
            "TUTORIAL", 
            renderer, 
            fonts->bit_operator_20, 
            color, 
            1.0f, 
            vec2i(300, 150 + (0 * 22)), 
            1
        );

        draw_font_at_screen_pos(
            n_str, 
            renderer, 
            fonts->bit_operator_20, 
            color, 
            1.0f, 
            vec2i(300, 150 + (1 * 22)), 
            1
        );

        draw_font_at_screen_pos(
            line_1, 
            renderer, 
            fonts->bit_operator_20, 
            color, 
            1.0f, 
            vec2i(420, 150 + (0 * 22)), 
            1
        );

        draw_font_at_screen_pos(
            line_2, 
            renderer, 
            fonts->bit_operator_20, 
            color, 
            1.0f, 
            vec2i(420, 150 + (1 * 22)), 
            1
        );

        draw_font_at_screen_pos(
            line_3, 
            renderer, 
            fonts->bit_operator_20, 
            color, 
            1.0f, 
            vec2i(420, 150 + (2 * 22)), 
            1
        );

        draw_font_at_screen_pos(
            line_4, 
            renderer, 
            fonts->bit_operator_20, 
            color, 
            1.0f, 
            vec2i(420, 150 + (3 * 22)), 
            1
        );
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
        int tail_augmentation = state->hero_body_part_augmentation[BODY_PART__TAIL];
        int torso_augmentation = state->hero_body_part_augmentation[BODY_PART__TORSO];

        Texture* left_hand_texture = textures->hud.aug_none;
        Texture* right_hand_texture = textures->hud.aug_none;
        Texture* left_leg_texture = textures->hud.aug_none;
        Texture* right_leg_texture = textures->hud.aug_none;
        Texture* tail_texture = textures->hud.aug_none;
        Texture* torso_texture = textures->hud.aug_none;

        if(left_leg_augmentation == AUGMENTATION__SPRING) left_leg_texture = textures->hud.aug_spring;
        if(right_leg_augmentation == AUGMENTATION__TRACK) right_leg_texture = textures->hud.aug_track;
        if(tail_augmentation == AUGMENTATION__TAIL) tail_texture = textures->hud.aug_tail;
        if(torso_augmentation == AUGMENTATION__MINIBOT) torso_texture = textures->hud.aug_minibot;

        if(left_hand_augmentation == AUGMENTATION__ARM) left_hand_texture = textures->hud.weapon_arm;
        if(left_hand_augmentation == AUGMENTATION__DRILL) left_hand_texture = textures->hud.weapon_drill;
        if(left_hand_augmentation == AUGMENTATION__BLADE) left_hand_texture = textures->hud.weapon_blade;
        if(left_hand_augmentation == AUGMENTATION__HAMMER) left_hand_texture = textures->hud.weapon_hammer;
        if(left_hand_augmentation == AUGMENTATION__WHIP) left_hand_texture = textures->hud.weapon_whip;

        if(right_hand_augmentation == AUGMENTATION__GUN) right_hand_texture = textures->hud.weapon_gun;
        if(right_hand_augmentation == AUGMENTATION__SLINGSHOT) right_hand_texture = textures->hud.weapon_slingshot;
        if(right_hand_augmentation == AUGMENTATION__COIL) right_hand_texture = textures->hud.weapon_coil;
        if(right_hand_augmentation == AUGMENTATION__FLAME) right_hand_texture = textures->hud.weapon_flame;
        if(right_hand_augmentation == AUGMENTATION__FREEZE) right_hand_texture = textures->hud.weapon_freeze;
        if(right_hand_augmentation == AUGMENTATION__LASER) right_hand_texture = textures->hud.weapon_laser;

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
            torso_texture,
            colors->none,
            1.0f,
            vec2i(84, 42),
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
            tail_texture,
            colors->none,
            1.0f,
            vec2i(84, 116),
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
           state->mouse_screen_pos.y >= 42 &&
           state->mouse_screen_pos.y <= 42 + 64)
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
        if(state->mouse_screen_pos.x >= 84 &&
           state->mouse_screen_pos.x <= 84 + 64 &&
           state->mouse_screen_pos.y >= 116 &&
           state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_augmentation = TRUE;
            mouse_augmentation = tail_augmentation;
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

    // parameters

    if((state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
        state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
        state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
        state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
        state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL) &&
       (state->curr_ally->object->type == OBJECT__HERO ||
        state->curr_ally->object->type == OBJECT__HERO_FLOATING ||
        state->curr_ally->object->type == OBJECT__HERO_FLYING))
    {
        if(state->is_first_move_free_if_move_only)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.bonus_turn_if_move_only,
                colors->green,
                1.0f,
                vec2i(10, 250),
                1
            );
        }

        if(state->is_move_after_damage_only)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.free_move_if_dam_only,
                colors->red,
                1.0f,
                vec2i(10, 250 + 32 + 10),
                1
            );
        }

        if(state->is_add_turn_after_kill)
        {
            draw_texture_at_screen_pos(
                renderer,
                textures->hud.bonus_turn_after_kill,
                colors->white,
                1.0f,
                vec2i(10, 250 + 32 + 10 + 32 + 10),
                1
            );
        }
    }

    // items

    // if((state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    //     state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    //     state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
    //     state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
    //     state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL) &&
    //    (state->curr_ally->object->type == OBJECT__HERO ||
    //     state->curr_ally->object->type == OBJECT__HERO_FLOATING ||
    //     state->curr_ally->object->type == OBJECT__HERO_FLYING))
    // {
    //     draw_texture_at_screen_pos(
    //         renderer,
    //         textures->hud.cell,
    //         colors->none,
    //         1.0f,
    //         vec2i(10, 120 + 100),
    //         4
    //     );
    //     if(state->hero_item_number[ITEM__CELL] > 9)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__CELL] / 10),
    //             colors->none,
    //             1.0f,
    //             vec2i(32, 120 + 100),
    //             2
    //         );
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__CELL] % 10),
    //             colors->none,
    //             1.0f,
    //             vec2i(64, 120 + 100),
    //             2
    //         );
    //     }
    //     else
    //     {

    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__CELL]),
    //             colors->none,
    //             1.0f,
    //             vec2i(32, 120 + 100),
    //             2
    //         );
    //     }

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         textures->hud.dynamite,
    //         colors->none,
    //         1.0f,
    //         vec2i(10, 194 + 100),
    //         4
    //     );
    //     if(state->hero_item_number[ITEM__DYNAMITE] > 9)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE] / 10),
    //             colors->none,
    //             1.0f,
    //             vec2i(32, 194 + 100),
    //             2
    //         );
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE] % 10),
    //             colors->none,
    //             1.0f,
    //             vec2i(64, 194 + 100),
    //             2
    //         );
    //     }
    //     else
    //     {

    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE]),
    //             colors->none,
    //             1.0f,
    //             vec2i(32, 194 + 100),
    //             2
    //         );
    //     }

    //     draw_texture_at_screen_pos(
    //         renderer,
    //         textures->hud.gemstone,
    //         colors->none,
    //         1.0f,
    //         vec2i(10, 268 + 100),
    //         4
    //     );
    //     if(state->hero_item_number[ITEM__GEMSTONE] > 9)
    //     {
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE] / 10),
    //             colors->none,
    //             1.0f,
    //             vec2i(32, 268 + 100),
    //             2
    //         );
    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE] % 10),
    //             colors->none,
    //             1.0f,
    //             vec2i(64, 268 + 100),
    //             2
    //         );
    //     }
    //     else
    //     {

    //         draw_texture_at_screen_pos(
    //             renderer,
    //             get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE]),
    //             colors->none,
    //             1.0f,
    //             vec2i(32, 268 + 100),
    //             2
    //         );
    //     }

    //     int is_mouse_on_item = FALSE;
    //     int mouse_item = ITEM__NONE;

    //     if(state->mouse_screen_pos.x >= 10 &&
    //        state->mouse_screen_pos.x <= 10 + 64 &&
    //        state->mouse_screen_pos.y >= 120 + 100 &&
    //        state->mouse_screen_pos.y <= 120 + 100 + 64)
    //     {
    //         is_mouse_on_item = TRUE;
    //         mouse_item = ITEM__CELL;
    //     }
    //     if(state->mouse_screen_pos.x >= 10 &&
    //        state->mouse_screen_pos.x <= 10 + 64 &&
    //        state->mouse_screen_pos.y >= 194 + 100 &&
    //        state->mouse_screen_pos.y <= 194 + 100 + 64)
    //     {
    //         is_mouse_on_item = TRUE;
    //         mouse_item = ITEM__DYNAMITE;
    //     }
    //     if(state->mouse_screen_pos.x >= 10 &&
    //        state->mouse_screen_pos.x <= 10 + 64 &&
    //        state->mouse_screen_pos.y >= 268 + 100 &&
    //        state->mouse_screen_pos.y <= 268 + 100 + 64)
    //     {
    //         is_mouse_on_item = TRUE;
    //         mouse_item = ITEM__GEMSTONE;
    //     }

    //     if(is_mouse_on_item)
    //     {
    //         draw_font_at_screen_pos(
    //             get_name_from_item(mouse_item),
    //             renderer,
    //             fonts->bit_operator_30,
    //             colors->white,
    //             1.0f,
    //             vec2i(10, 180),
    //             1
    //         );
    //     }
    // }

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

                            if(state->enemy_list->size > 0)
                            {
                                if(state->is_first_move_free_if_move_only && !state->is_move_only_used && is_skill_move_only(skill))
                                {
                                    draw_texture_at_screen_pos(
                                        renderer,
                                        textures->hud.highlight_skill,
                                        colors->green,
                                        (sinf(state->time * 2.0f) + 1.0f) / 2.0f,
                                        vec2i(
                                            138 + 10 * (i + 1) + 64 * i - 4,
                                            600 + 10 * j + 64 * j + 50 - 4
                                        ),
                                        2
                                    );
                                }
                                else if(state->is_move_after_damage_only && !state->is_damage_only_used && is_skill_damage_only(skill))
                                {
                                    draw_texture_at_screen_pos(
                                        renderer,
                                        textures->hud.highlight_skill,
                                        colors->red,
                                        (sinf(state->time * 2.0f) + 1.0f) / 2.0f,
                                        vec2i(
                                            138 + 10 * (i + 1) + 64 * i - 4,
                                            600 + 10 * j + 64 * j + 50 - 4
                                        ),
                                        2
                                    );
                                }
                            }

                            Texture* skill_texture = get_skill_hud_texture(
                                skill,
                                textures
                            );

                            if(skill_texture == NULL)
                            {
                                skill_texture = textures->hud.aug_none;
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

            // from context menu
            if(state->is_showing_context_menu &&
            state->mouse_screen_pos.x > state->context_menu_screen_position.x &&
            state->mouse_screen_pos.x < state->context_menu_screen_position.x + state->context_menu_skill_list->size * 32 &&
            state->mouse_screen_pos.y > state->context_menu_screen_position.y &&
            state->mouse_screen_pos.y < state->context_menu_screen_position.y + 32)
            {
                int n = (state->mouse_screen_pos.x - state->context_menu_screen_position.x) / 32;
                ListElem* context_menu_skill_elem = get_nth_list_element(state->context_menu_skill_list, n);
                int context_menu_skill = (int)context_menu_skill_elem->data;

                mouse_hover_skill = context_menu_skill;
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
                    char* material_text = "";
                    Vec3i material_color = colors->black;

                    if(is_floor_meltable(floor))
                    {
                        material_text = "metal";
                        material_color = colors->blue_light;
                    }
                    else if(is_floor_breakable(floor))
                    {
                        material_text = "stone";
                        material_color = colors->brown_light;
                    }
                    else if(is_floor_fragile(floor))
                    {
                        material_text = "glass";
                        material_color = colors->white;
                    }
                    else
                    {
                        material_text = "";
                        material_color = colors->black;
                    }

                    draw_font_at_screen_pos(
                        material_text,
                        renderer,
                        fonts->bit_operator_20,
                        material_color,
                        1.0f,
                        vec2i(900 + 100, 550 + 50 - 30),
                        1
                    );

                    char* type_text = "";
                    Vec3i type_color = colors->black;

                    if(is_floor_manipulatable(floor))
                    {
                        type_text = "manipulatable";
                        type_color = colors->green_light;
                    }
                    if(is_floor_exit(floor))
                    {
                        type_text = "exit";
                        type_color = colors->pink_light;
                    }

                    draw_font_at_screen_pos(
                        type_text,
                        renderer,
                        fonts->bit_operator_20,
                        type_color,
                        1.0f,
                        vec2i(900 + 200, 550 + 50 - 30),
                        1
                    );

                    draw_font_at_screen_pos(
                        get_in_game_name_from_floor(floor),
                        renderer,
                        fonts->bit_operator_30,
                        colors->white,
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
                char* material_text = "";
                Vec3i material_color = colors->black;

                if(is_object_stone(object))
                {
                    material_text = "stone";
                    material_color = colors->brown_light;
                }
                else if(is_object_metal(object))
                {
                    material_text = "metal";
                    material_color = colors->blue_light;
                }
                else if(is_object_glass(object))
                {
                    material_text = "glass";
                    material_color = colors->white;
                }

                draw_font_at_screen_pos(
                    material_text,
                    renderer,
                    fonts->bit_operator_20,
                    material_color,
                    1.0f,
                    vec2i(900 + 100, 550 + 50 - 30),
                    1
                );

                char* type_text = "";
                Vec3i type_color = colors->black;

                if(is_object_manipulatable(object))
                {
                    type_text = "manipulatable";
                    type_color = colors->green_light;

                    if(is_object_pull_towards(object) ||
                    !is_object_throw_over(object))
                    {
                        type_text = "manip.";
                    }
                }
                else if(is_object_exit(object))
                {
                    type_text = "exit";
                    type_color = colors->pink_light;
                }
                else if(is_object_station(object))
                {
                    type_text = "station";
                    type_color = colors->pink_light;
                }
                else if(is_object_secret(object))
                {
                    type_text = "secret";
                    type_color = colors->pink_light;
                }
                else if(object->type == OBJECT__THRONE)
                {
                    type_text = "throne";
                    type_color = colors->pink_light;
                }

                draw_font_at_screen_pos(
                    type_text,
                    renderer,
                    fonts->bit_operator_20,
                    type_color,
                    1.0f,
                    vec2i(900 + 200, 550 + 50 - 30),
                    1
                );

                char* high_text = "";
                Vec3i high_color = colors->black;

                if(!is_object_throw_over(object) && !is_object_wall(object))
                {
                    high_text = "high";
                    high_color = colors->white;
                }

                draw_font_at_screen_pos(
                    high_text,
                    renderer,
                    fonts->bit_operator_20,
                    high_color,
                    1.0f,
                    vec2i(900 + 300, 550 + 50 - 50),
                    1
                );

                char* stable_text = "";
                Vec3i stable_color = colors->black;

                if(!is_object_movable(object) && is_object_pull_towards(object))
                {
                    stable_text = "stable";
                    stable_color = colors->white;
                }

                draw_font_at_screen_pos(
                    stable_text,
                    renderer,
                    fonts->bit_operator_20,
                    stable_color,
                    1.0f,
                    vec2i(900 + 300, 550 + 50 - 30),
                    1
                );

                draw_font_at_screen_pos(
                    get_in_game_name_from_object_type(object->type),
                    renderer,
                    fonts->bit_operator_30,
                    colors->white,
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

        // Texture* reset_turn_texture = NULL;

        // if(state->reset_turn_uses == 3) reset_turn_texture = textures->hud.reset_turn_3x;
        // else if(state->reset_turn_uses == 2) reset_turn_texture = textures->hud.reset_turn_2x;
        // else if(state->reset_turn_uses == 1) reset_turn_texture = textures->hud.reset_turn_1x;
        // else reset_turn_texture = textures->hud.reset_turn_used;

        // draw_texture_at_screen_pos(
        //     renderer,
        //     reset_turn_texture,
        //     colors->none,
        //     1.0f,
        //     vec2i(300, 10 + 64 + 10),
        //     2
        // );
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

    // context menu

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL)
    {
        if(state->is_showing_context_menu)
        {
            int i = 0;
            for(ListElem* curr_elem = state->context_menu_skill_list->head;
            curr_elem != NULL; curr_elem = curr_elem->next)
            {
                int skill = (int) curr_elem->data;

                draw_texture_at_screen_pos(
                    renderer,
                    get_skill_hud_texture(skill, textures),
                    colors->none,
                    1.0f,
                    vec2i(state->context_menu_screen_position.x + i * 32, state->context_menu_screen_position.y),
                    1
                );

                i++;
            }
        }
    }
}
