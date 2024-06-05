#include "../inc/input.h"
#include <SDL2/SDL_scancode.h>

void init_input(Input* input)
{
    input->is_quit = 0;

    for(int i = 1; i < KEY__COUNT; i++)
    {
        input->is_key[i] = 0;
        input->was_key[i] = 0;
    }

    input->is_mouse_left = 0;
    input->was_mouse_left = 0;
    input->is_mouse_middle = 0;
    input->was_mouse_middle = 0;
    input->is_mouse_right = 0;
    input->was_mouse_right = 0;

    input->mouse_x = 0;
    input->mouse_y = 0;

    input->is_mouse_scrolling = 0;
    input->mouse_scrolled = 0;
}

void update_input(Input* input)
{
    SDL_Event event;

    // reset some of the input

    input->is_mouse_scrolling = 0;

    // update 'was' from 'is'

    for(int i = 1; i < KEY__COUNT; i++)
    {
        input->was_key[i] = input->is_key[i];
    }

    input->was_mouse_left = input->is_mouse_left;
    input->was_mouse_middle = input->is_mouse_middle;
    input->was_mouse_right = input->is_mouse_right;

    while(SDL_PollEvent(&event))
    {
        // event types

        SDL_KeyboardEvent keyboard_event = event.key;

        SDL_MouseButtonEvent mouse_button_event = event.button;
        SDL_MouseMotionEvent mouse_motion_event = event.motion;
        SDL_MouseWheelEvent mouse_wheel_event = event.wheel;

        switch(event.type)
        {
            case SDL_QUIT:

            input->is_quit = 1;

            break;
            case SDL_KEYDOWN:

            switch(keyboard_event.keysym.scancode)
            {
                case SDL_SCANCODE_ESCAPE:   input->is_key[KEY__ESC] = 1;     break;
                case SDL_SCANCODE_RETURN:   input->is_key[KEY__ENTER] = 1;   break;
                case SDL_SCANCODE_SPACE:    input->is_key[KEY__SPACE] = 1;   break;

                case SDL_SCANCODE_UP:       input->is_key[KEY__UP] = 1;      break;
                case SDL_SCANCODE_DOWN:     input->is_key[KEY__DOWN] = 1;    break;
                case SDL_SCANCODE_LEFT:     input->is_key[KEY__LEFT] = 1;    break;
                case SDL_SCANCODE_RIGHT:    input->is_key[KEY__RIGHT] = 1;   break;

                case SDL_SCANCODE_1:        input->is_key[KEY__1] = 1;       break;
                case SDL_SCANCODE_2:        input->is_key[KEY__2] = 1;       break;
                case SDL_SCANCODE_3:        input->is_key[KEY__3] = 1;       break;
                case SDL_SCANCODE_4:        input->is_key[KEY__4] = 1;       break;
                case SDL_SCANCODE_5:        input->is_key[KEY__5] = 1;       break;
                case SDL_SCANCODE_6:        input->is_key[KEY__6] = 1;       break;
                case SDL_SCANCODE_7:        input->is_key[KEY__7] = 1;       break;
                case SDL_SCANCODE_8:        input->is_key[KEY__8] = 1;       break;
                case SDL_SCANCODE_9:        input->is_key[KEY__9] = 1;       break;
                case SDL_SCANCODE_0:        input->is_key[KEY__0] = 1;       break;

                case SDL_SCANCODE_Q:        input->is_key[KEY__Q] = 1;       break;
                case SDL_SCANCODE_W:        input->is_key[KEY__W] = 1;       break;
                case SDL_SCANCODE_E:        input->is_key[KEY__E] = 1;       break;
                case SDL_SCANCODE_R:        input->is_key[KEY__R] = 1;       break;
                case SDL_SCANCODE_T:        input->is_key[KEY__T] = 1;       break;
                case SDL_SCANCODE_Y:        input->is_key[KEY__Y] = 1;       break;
                case SDL_SCANCODE_U:        input->is_key[KEY__U] = 1;       break;
                case SDL_SCANCODE_I:        input->is_key[KEY__I] = 1;       break;
                case SDL_SCANCODE_O:        input->is_key[KEY__O] = 1;       break;
                case SDL_SCANCODE_P:        input->is_key[KEY__P] = 1;       break;

                case SDL_SCANCODE_A:        input->is_key[KEY__A] = 1;       break;
                case SDL_SCANCODE_S:        input->is_key[KEY__S] = 1;       break;
                case SDL_SCANCODE_D:        input->is_key[KEY__D] = 1;       break;
                case SDL_SCANCODE_F:        input->is_key[KEY__F] = 1;       break;
                case SDL_SCANCODE_G:        input->is_key[KEY__G] = 1;       break;
                case SDL_SCANCODE_H:        input->is_key[KEY__H] = 1;       break;
                case SDL_SCANCODE_J:        input->is_key[KEY__J] = 1;       break;
                case SDL_SCANCODE_K:        input->is_key[KEY__K] = 1;       break;
                case SDL_SCANCODE_L:        input->is_key[KEY__L] = 1;       break;

                case SDL_SCANCODE_Z:        input->is_key[KEY__Z] = 1;       break;
                case SDL_SCANCODE_X:        input->is_key[KEY__X] = 1;       break;
                case SDL_SCANCODE_C:        input->is_key[KEY__C] = 1;       break;
                case SDL_SCANCODE_V:        input->is_key[KEY__V] = 1;       break;
                case SDL_SCANCODE_B:        input->is_key[KEY__B] = 1;       break;
                case SDL_SCANCODE_N:        input->is_key[KEY__N] = 1;       break;
                case SDL_SCANCODE_M:        input->is_key[KEY__M] = 1;       break;

                default: break;
            }

            break;
            case SDL_KEYUP:

            switch(keyboard_event.keysym.scancode)
            {
                case SDL_SCANCODE_ESCAPE:   input->is_key[KEY__ESC] = 0;     break;
                case SDL_SCANCODE_RETURN:   input->is_key[KEY__ENTER] = 0;   break;
                case SDL_SCANCODE_SPACE:    input->is_key[KEY__SPACE] = 0;   break;

                case SDL_SCANCODE_UP:       input->is_key[KEY__UP] = 0;      break;
                case SDL_SCANCODE_DOWN:     input->is_key[KEY__DOWN] = 0;    break;
                case SDL_SCANCODE_LEFT:     input->is_key[KEY__LEFT] = 0;    break;
                case SDL_SCANCODE_RIGHT:    input->is_key[KEY__RIGHT] = 0;   break;

                case SDL_SCANCODE_1:        input->is_key[KEY__1] = 0;       break;
                case SDL_SCANCODE_2:        input->is_key[KEY__2] = 0;       break;
                case SDL_SCANCODE_3:        input->is_key[KEY__3] = 0;       break;
                case SDL_SCANCODE_4:        input->is_key[KEY__4] = 0;       break;
                case SDL_SCANCODE_5:        input->is_key[KEY__5] = 0;       break;
                case SDL_SCANCODE_6:        input->is_key[KEY__6] = 0;       break;
                case SDL_SCANCODE_7:        input->is_key[KEY__7] = 0;       break;
                case SDL_SCANCODE_8:        input->is_key[KEY__8] = 0;       break;
                case SDL_SCANCODE_9:        input->is_key[KEY__9] = 0;       break;
                case SDL_SCANCODE_0:        input->is_key[KEY__0] = 0;       break;

                case SDL_SCANCODE_Q:        input->is_key[KEY__Q] = 0;       break;
                case SDL_SCANCODE_W:        input->is_key[KEY__W] = 0;       break;
                case SDL_SCANCODE_E:        input->is_key[KEY__E] = 0;       break;
                case SDL_SCANCODE_R:        input->is_key[KEY__R] = 0;       break;
                case SDL_SCANCODE_T:        input->is_key[KEY__T] = 0;       break;
                case SDL_SCANCODE_Y:        input->is_key[KEY__Y] = 0;       break;
                case SDL_SCANCODE_U:        input->is_key[KEY__U] = 0;       break;
                case SDL_SCANCODE_I:        input->is_key[KEY__I] = 0;       break;
                case SDL_SCANCODE_O:        input->is_key[KEY__O] = 0;       break;
                case SDL_SCANCODE_P:        input->is_key[KEY__P] = 0;       break;

                case SDL_SCANCODE_A:        input->is_key[KEY__A] = 0;       break;
                case SDL_SCANCODE_S:        input->is_key[KEY__S] = 0;       break;
                case SDL_SCANCODE_D:        input->is_key[KEY__D] = 0;       break;
                case SDL_SCANCODE_F:        input->is_key[KEY__F] = 0;       break;
                case SDL_SCANCODE_G:        input->is_key[KEY__G] = 0;       break;
                case SDL_SCANCODE_H:        input->is_key[KEY__H] = 0;       break;
                case SDL_SCANCODE_J:        input->is_key[KEY__J] = 0;       break;
                case SDL_SCANCODE_K:        input->is_key[KEY__K] = 0;       break;
                case SDL_SCANCODE_L:        input->is_key[KEY__L] = 0;       break;

                case SDL_SCANCODE_Z:        input->is_key[KEY__Z] = 0;       break;
                case SDL_SCANCODE_X:        input->is_key[KEY__X] = 0;       break;
                case SDL_SCANCODE_C:        input->is_key[KEY__C] = 0;       break;
                case SDL_SCANCODE_V:        input->is_key[KEY__V] = 0;       break;
                case SDL_SCANCODE_B:        input->is_key[KEY__B] = 0;       break;
                case SDL_SCANCODE_N:        input->is_key[KEY__N] = 0;       break;
                case SDL_SCANCODE_M:        input->is_key[KEY__M] = 0;       break;

                default: break;
            }

            break;
            case SDL_MOUSEMOTION:

            input->mouse_x = mouse_motion_event.x;
            input->mouse_y = mouse_motion_event.y;

            break;
            case SDL_MOUSEBUTTONDOWN:

            switch(mouse_button_event.button)
            {
                case SDL_BUTTON_LEFT:   input->is_mouse_left = 1;   break;
                case SDL_BUTTON_MIDDLE: input->is_mouse_middle = 1; break;
                case SDL_BUTTON_RIGHT:  input->is_mouse_right = 1;  break;
                default: break;
            }

            break;
            case SDL_MOUSEBUTTONUP:

            switch(mouse_button_event.button)
            {
                case SDL_BUTTON_LEFT:   input->is_mouse_left = 0;   break;
                case SDL_BUTTON_MIDDLE: input->is_mouse_middle = 0; break;
                case SDL_BUTTON_RIGHT:  input->is_mouse_right = 0;  break;
                default: break;
            }

            break;
            case SDL_MOUSEWHEEL:

            input->is_mouse_scrolling = 1;
            input->mouse_scrolled = mouse_wheel_event.y;

            break;
            default:
            break;
        }
    }
}
