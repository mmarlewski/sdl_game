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

    // game tutorial

    if(state->gamestate == GAMESTATE__GAME_TUTORIAL)
    {
        SDL_SetRenderDrawColor(
            renderer,
            colors->game_start_background.x,
            colors->game_start_background.y,
            colors->game_start_background.z,
            255
        );
        SDL_RenderClear(renderer);

        draw_texture_at_screen_pos(
            renderer,
            textures->tutorial,
            colors->none,
            1.0f,
            vec2i(0, 0),
            1.0f
        );

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.start_game,
            colors->none,
            1.0f,
            vec2i(1150 - 10, 20 + 10),
            2.0f
        );
    }

    // game over

    if(state->gamestate == GAMESTATE__GAME_OVER)
    {
        SDL_SetRenderDrawColor(
            renderer,
            colors->game_over_background.x,
            colors->game_over_background.y,
            colors->game_over_background.z,
            255
        );
        SDL_RenderClear(renderer);

        draw_font_at_screen_pos(
            "Game Over",
            renderer,
            fonts->stepalange_100,
            colors->white,
            1.0f,
            vec2i(450, 100),
            1
        );
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.start_again,
            colors->none,
            1.0f,
            vec2i(600, 300),
            2.0f
        );
    }

    // game won

    if(state->gamestate == GAMESTATE__GAME_WON)
    {
        SDL_SetRenderDrawColor(
            renderer,
            colors->game_won_background.x,
            colors->game_won_background.y,
            colors->game_won_background.z,
            255
        );
        SDL_RenderClear(renderer);

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
            textures->hud.start_again,
            colors->none,
            1.0f,
            vec2i(600, 300),
            2.0f
        );
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

        int is_mouse_on_texture = FALSE;
        int mouse_augmentation = AUGMENTATION__NONE;

        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 42 &&
           state->mouse_screen_pos.y <= 42 + 64)
        {
            is_mouse_on_texture = TRUE;
            mouse_augmentation = left_hand_augmentation;
        }
        if(state->mouse_screen_pos.x >= 84 &&
           state->mouse_screen_pos.x <= 84 + 64 &&
           state->mouse_screen_pos.y >= 10 &&
           state->mouse_screen_pos.y <= 10 + 64)
        {
            is_mouse_on_texture = TRUE;
            mouse_augmentation = head_augmentation;
        }
        if(state->mouse_screen_pos.x >= 158 &&
           state->mouse_screen_pos.x <= 158 + 64 &&
           state->mouse_screen_pos.y >= 42 &&
           state->mouse_screen_pos.y <= 42 + 64)
        {
            is_mouse_on_texture = TRUE;
            mouse_augmentation = right_hand_augmentation;
        }
        if(state->mouse_screen_pos.x >= 10 &&
           state->mouse_screen_pos.x <= 10 + 64 &&
           state->mouse_screen_pos.y >= 116 &&
           state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_texture = TRUE;
            mouse_augmentation = left_leg_augmentation;
        }
        if(state->mouse_screen_pos.x >= 84 &&
           state->mouse_screen_pos.x <= 84 + 64 &&
           state->mouse_screen_pos.y >= 84 &&
           state->mouse_screen_pos.y <= 84 + 64)
        {
            is_mouse_on_texture = TRUE;
            mouse_augmentation = torso_augmentation;
        }
        if(state->mouse_screen_pos.x >= 158 &&
           state->mouse_screen_pos.x <= 158 + 64 &&
           state->mouse_screen_pos.y >= 116 &&
           state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_texture = TRUE;
            mouse_augmentation = right_leg_augmentation;
        }

        if(is_mouse_on_texture)
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
        draw_texture_at_screen_pos(
            renderer,
            get_texture_order_number(textures, state->hero_item_number[ITEM__CELL]),
            colors->none,
            1.0f,
            vec2i(32, 120 + 100),
            2
        );

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.dynamite,
            colors->none,
            1.0f,
            vec2i(10, 194 + 100),
            4
        );
        draw_texture_at_screen_pos(
            renderer,
            get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE]),
            colors->none,
            1.0f,
            vec2i(32, 194 + 100),
            2
        );

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.gemstone,
            colors->none,
            1.0f,
            vec2i(10, 268 + 100),
            4
        );
        draw_texture_at_screen_pos(
            renderer,
            get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE]),
            colors->none,
            1.0f,
            vec2i(32, 268 + 100),
            2
        );
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
            draw_font_at_screen_pos(
                get_in_game_name_from_object_type(state->curr_ally->object->type),
                renderer,
                fonts->bit_operator_30,
                colors->white,
                1.0f,
                vec2i(10, 550 + 50),
                1
            );

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
                        }
                    }
                }
            }
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
                if(is_object_exit(object) || is_object_station(object) || object->type == OBJECT__THRONE)
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

    // end turn

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL &&
       state->enemy_list->size > 0)
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.end_turn,
            colors->none,
            1.0f,
            vec2i(1200 - 64 - 10 + 100, 10),
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
            vec2i(1200 - 64 - 10 + 100, 10 + 64 + 10),
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
                        10 + 64 + 10 * i + 64 * (i - 1) + 64 + 10
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
                        10 + 64 + 10 * i + 64 * (i - 1) + 64 + 10
                    ),
                    2
                );
            }
        }
    }
}
