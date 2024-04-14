#include "../inc/game.h"
#include <string.h>

void draw_hud(Renderer* renderer, State* state, Textures* textures, Colors* colors, Fonts* fonts)
{
    // gamestate

    char* gamestate_text = get_gamestate_in_game_name(state->gamestate);

    draw_font_at_screen_pos(
        gamestate_text,
        renderer,
        fonts->font_50,
        colors->white,
        1.0f,
        vec2i(600 - strlen(gamestate_text) * 10,10),
        1
        );

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
                    vec2i(550 + 32 * i,100),
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

        int is_mouse_on_texture = 0;
        int mouse_augmentation = AUGMENTATION__NONE;

        if(state->mouse_screen_pos.x >= 10 &&
        state->mouse_screen_pos.x <= 10 + 64 &&
        state->mouse_screen_pos.y >= 42 &&
        state->mouse_screen_pos.y <= 42 + 64)
        {
            is_mouse_on_texture = 1;
            mouse_augmentation = left_hand_augmentation;
        }
        if(state->mouse_screen_pos.x >= 84 &&
        state->mouse_screen_pos.x <= 84 + 64 &&
        state->mouse_screen_pos.y >= 10 &&
        state->mouse_screen_pos.y <= 10 + 64)
        {
            is_mouse_on_texture = 1;
            mouse_augmentation = head_augmentation;
        }
        if(state->mouse_screen_pos.x >= 158 &&
        state->mouse_screen_pos.x <= 158 + 64 &&
        state->mouse_screen_pos.y >= 42 &&
        state->mouse_screen_pos.y <= 42 + 64)
        {
            is_mouse_on_texture = 1;
            mouse_augmentation = right_hand_augmentation;
        }
        if(state->mouse_screen_pos.x >= 10 &&
        state->mouse_screen_pos.x <= 10 + 64 &&
        state->mouse_screen_pos.y >= 116 &&
        state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_texture = 1;
            mouse_augmentation = left_leg_augmentation;
        }
        if(state->mouse_screen_pos.x >= 84 &&
        state->mouse_screen_pos.x <= 84 + 64 &&
        state->mouse_screen_pos.y >= 84 &&
        state->mouse_screen_pos.y <= 84 + 64)
        {
            is_mouse_on_texture = 1;
            mouse_augmentation = torso_augmentation;
        }
        if(state->mouse_screen_pos.x >= 158 &&
        state->mouse_screen_pos.x <= 158 + 64 &&
        state->mouse_screen_pos.y >= 116 &&
        state->mouse_screen_pos.y <= 116 + 64)
        {
            is_mouse_on_texture = 1;
            mouse_augmentation = right_leg_augmentation;
        }

        if(is_mouse_on_texture)
        {
            draw_font_at_screen_pos(
                get_augmentation_name(mouse_augmentation),
                renderer,
                fonts->font_30,
                colors->white,
                1.0f,
                vec2i(10,180),
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
            vec2i(10, 120 + 74),
            4
            );
        draw_texture_at_screen_pos(
            renderer,
            get_texture_order_number(textures, state->hero_item_number[ITEM__CELL]),
            colors->none,
            1.0f,
            vec2i(32, 120 + 74),
            2
            );

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.dynamite,
            colors->none,
            1.0f,
            vec2i(10, 194 + 74),
            4
            );
        draw_texture_at_screen_pos(
            renderer,
            get_texture_order_number(textures, state->hero_item_number[ITEM__DYNAMITE]),
            colors->none,
            1.0f,
            vec2i(32, 194 + 74),
            2
            );

        draw_texture_at_screen_pos(
            renderer,
            textures->hud.gemstone,
            colors->none,
            1.0f,
            vec2i(10, 268 + 74),
            4
            );
        draw_texture_at_screen_pos(
            renderer,
            get_texture_order_number(textures, state->hero_item_number[ITEM__GEMSTONE]),
            colors->none,
            1.0f,
            vec2i(32, 268 + 74),
            2
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
            vec2i(10, 600 + 150),
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
            vec2i(10, 600 + 150),
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
                fonts->font_30,
                colors->white,
                1.0f,
                vec2i(10,550 + 150),
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

                        if(skill_list_elem != 0)
                        {
                            int skill = (int)skill_list_elem->data;

                            Texture* skill_texture = get_skill_hud_texture(
                                skill,
                                textures
                                );

                            if(skill_texture == 0)
                            {
                                skill_texture = textures->hud.no_augmentation;
                            }

                            draw_texture_at_screen_pos(
                                renderer,
                                skill_texture,
                                colors->none,
                                1.0f,
                                vec2i(
                                    138 + 10 * (i+1) + 64 * i,
                                    600 + 10 * j + 64 * j + 150
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
            fonts->font_30,
            colors->white,
            1.0f,
            vec2i(10,550 + 150),
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
            vec2i(148,600 + 150),
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
            fonts->font_30,
            colors->white,
            1.0f,
            vec2i(10,550 + 150),
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
            vec2i(148,600 + 150),
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
                Texture* texture = get_texture_1_from_floor_type(floor, textures);

                draw_texture_at_screen_pos(
                    renderer,
                    texture,
                    colors->none,
                    1.0f,
                    vec2i(1050 + 100, 600 + 150),
                    2
                    );
            }

            if(object != 0)
            {
                draw_font_at_screen_pos(
                    get_in_game_name_from_object_type(object->type),
                    renderer,
                    fonts->font_30,
                    colors->white,
                    1.0f,
                    vec2i(900 + 100,550 + 150),
                    1
                    );

                Texture* texture = get_texture_1_from_object(object, textures);
                Texture* texture_outline = get_texture_1_outline_from_object(object, textures);

                draw_texture_at_screen_pos(
                    renderer,
                    texture,
                    colors->none,
                    1.0f,
                    vec2i(900 + 100, 600 + 150),
                    2
                    );

                if(is_object_ally(object))
                {
                    draw_texture_at_screen_pos(
                        renderer,
                        texture_outline,
                        colors->green,
                        1.0f,
                        vec2i(900 + 100, 600 + 150),
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
                        vec2i(900 + 100, 600 + 150),
                        2
                        );
                }
            }
        }
    }

    // attack order

    if(state->gamestate == GAMESTATE__ALLY_CHOOSING_SKILL ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_1 ||
    state->gamestate == GAMESTATE__ALLY_CHOOSING_TARGET_2 ||
    state->gamestate == GAMESTATE__ALLY_EXECUTING_ANIMATION ||
    state->gamestate == GAMESTATE__ALLY_EXECUTING_SKILL)
    {
        draw_texture_at_screen_pos(
            renderer,
            textures->hud.end_turn,
            colors->none,
            1.0f,
            vec2i(1200 - 64 - 10 + 100, 10),
            2
            );

        int go_on = 1;
        for(int i = 1; i < 10 && go_on; i++)
        {
            Object* object = 0;

            for(ListElem* curr_elem = state->enemy_list->head;
            curr_elem != 0; curr_elem = curr_elem->next)
            {
                Enemy* curr_enemy = curr_elem->data;

                if(curr_enemy->order_number == i)
                {
                    object = curr_enemy->object;
                }
            }

            if(object == 0)
            {
                go_on = 0;
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
