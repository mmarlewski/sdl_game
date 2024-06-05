#include "../inc/input.h"
#include <SDL2/SDL_scancode.h>

void init_input(Input* input)
{
    input->is_quit = FALSE;

    for(int i = 1; i < KEY__COUNT; i++)
    {
        input->is_key[i] = FALSE;
        input->was_key[i] = FALSE;
    }

    input->is_mouse_left = FALSE;
    input->was_mouse_left = FALSE;
    input->is_mouse_middle = FALSE;
    input->was_mouse_middle = FALSE;
    input->is_mouse_right = FALSE;
    input->was_mouse_right = FALSE;

    input->mouse_x = FALSE;
    input->mouse_y = FALSE;

    input->is_mouse_scrolling = FALSE;
    input->mouse_scrolled = FALSE;
}

void update_input(Input* input)
{
    SDL_Event event;

    // reset some of the input

    input->is_mouse_scrolling = FALSE;

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

            input->is_quit = TRUE;

            break;
            case SDL_KEYDOWN:

            switch(keyboard_event.keysym.scancode)
            {
                case SDL_SCANCODE_ESCAPE:   input->is_key[KEY__ESC] = TRUE;     break;
                case SDL_SCANCODE_RETURN:   input->is_key[KEY__ENTER] = TRUE;   break;
                case SDL_SCANCODE_SPACE:    input->is_key[KEY__SPACE] = TRUE;   break;

                case SDL_SCANCODE_UP:       input->is_key[KEY__UP] = TRUE;      break;
                case SDL_SCANCODE_DOWN:     input->is_key[KEY__DOWN] = TRUE;    break;
                case SDL_SCANCODE_LEFT:     input->is_key[KEY__LEFT] = TRUE;    break;
                case SDL_SCANCODE_RIGHT:    input->is_key[KEY__RIGHT] = TRUE;   break;

                case SDL_SCANCODE_1:        input->is_key[KEY__1] = TRUE;       break;
                case SDL_SCANCODE_2:        input->is_key[KEY__2] = TRUE;       break;
                case SDL_SCANCODE_3:        input->is_key[KEY__3] = TRUE;       break;
                case SDL_SCANCODE_4:        input->is_key[KEY__4] = TRUE;       break;
                case SDL_SCANCODE_5:        input->is_key[KEY__5] = TRUE;       break;
                case SDL_SCANCODE_6:        input->is_key[KEY__6] = TRUE;       break;
                case SDL_SCANCODE_7:        input->is_key[KEY__7] = TRUE;       break;
                case SDL_SCANCODE_8:        input->is_key[KEY__8] = TRUE;       break;
                case SDL_SCANCODE_9:        input->is_key[KEY__9] = TRUE;       break;
                case SDL_SCANCODE_0:        input->is_key[KEY__0] = TRUE;       break;

                case SDL_SCANCODE_Q:        input->is_key[KEY__Q] = TRUE;       break;
                case SDL_SCANCODE_W:        input->is_key[KEY__W] = TRUE;       break;
                case SDL_SCANCODE_E:        input->is_key[KEY__E] = TRUE;       break;
                case SDL_SCANCODE_R:        input->is_key[KEY__R] = TRUE;       break;
                case SDL_SCANCODE_T:        input->is_key[KEY__T] = TRUE;       break;
                case SDL_SCANCODE_Y:        input->is_key[KEY__Y] = TRUE;       break;
                case SDL_SCANCODE_U:        input->is_key[KEY__U] = TRUE;       break;
                case SDL_SCANCODE_I:        input->is_key[KEY__I] = TRUE;       break;
                case SDL_SCANCODE_O:        input->is_key[KEY__O] = TRUE;       break;
                case SDL_SCANCODE_P:        input->is_key[KEY__P] = TRUE;       break;

                case SDL_SCANCODE_A:        input->is_key[KEY__A] = TRUE;       break;
                case SDL_SCANCODE_S:        input->is_key[KEY__S] = TRUE;       break;
                case SDL_SCANCODE_D:        input->is_key[KEY__D] = TRUE;       break;
                case SDL_SCANCODE_F:        input->is_key[KEY__F] = TRUE;       break;
                case SDL_SCANCODE_G:        input->is_key[KEY__G] = TRUE;       break;
                case SDL_SCANCODE_H:        input->is_key[KEY__H] = TRUE;       break;
                case SDL_SCANCODE_J:        input->is_key[KEY__J] = TRUE;       break;
                case SDL_SCANCODE_K:        input->is_key[KEY__K] = TRUE;       break;
                case SDL_SCANCODE_L:        input->is_key[KEY__L] = TRUE;       break;

                case SDL_SCANCODE_Z:        input->is_key[KEY__Z] = TRUE;       break;
                case SDL_SCANCODE_X:        input->is_key[KEY__X] = TRUE;       break;
                case SDL_SCANCODE_C:        input->is_key[KEY__C] = TRUE;       break;
                case SDL_SCANCODE_V:        input->is_key[KEY__V] = TRUE;       break;
                case SDL_SCANCODE_B:        input->is_key[KEY__B] = TRUE;       break;
                case SDL_SCANCODE_N:        input->is_key[KEY__N] = TRUE;       break;
                case SDL_SCANCODE_M:        input->is_key[KEY__M] = TRUE;       break;

                default: break;
            }

            break;
            case SDL_KEYUP:

            switch(keyboard_event.keysym.scancode)
            {
                case SDL_SCANCODE_ESCAPE:   input->is_key[KEY__ESC] = FALSE;     break;
                case SDL_SCANCODE_RETURN:   input->is_key[KEY__ENTER] = FALSE;   break;
                case SDL_SCANCODE_SPACE:    input->is_key[KEY__SPACE] = FALSE;   break;

                case SDL_SCANCODE_UP:       input->is_key[KEY__UP] = FALSE;      break;
                case SDL_SCANCODE_DOWN:     input->is_key[KEY__DOWN] = FALSE;    break;
                case SDL_SCANCODE_LEFT:     input->is_key[KEY__LEFT] = FALSE;    break;
                case SDL_SCANCODE_RIGHT:    input->is_key[KEY__RIGHT] = FALSE;   break;

                case SDL_SCANCODE_1:        input->is_key[KEY__1] = FALSE;       break;
                case SDL_SCANCODE_2:        input->is_key[KEY__2] = FALSE;       break;
                case SDL_SCANCODE_3:        input->is_key[KEY__3] = FALSE;       break;
                case SDL_SCANCODE_4:        input->is_key[KEY__4] = FALSE;       break;
                case SDL_SCANCODE_5:        input->is_key[KEY__5] = FALSE;       break;
                case SDL_SCANCODE_6:        input->is_key[KEY__6] = FALSE;       break;
                case SDL_SCANCODE_7:        input->is_key[KEY__7] = FALSE;       break;
                case SDL_SCANCODE_8:        input->is_key[KEY__8] = FALSE;       break;
                case SDL_SCANCODE_9:        input->is_key[KEY__9] = FALSE;       break;
                case SDL_SCANCODE_0:        input->is_key[KEY__0] = FALSE;       break;

                case SDL_SCANCODE_Q:        input->is_key[KEY__Q] = FALSE;       break;
                case SDL_SCANCODE_W:        input->is_key[KEY__W] = FALSE;       break;
                case SDL_SCANCODE_E:        input->is_key[KEY__E] = FALSE;       break;
                case SDL_SCANCODE_R:        input->is_key[KEY__R] = FALSE;       break;
                case SDL_SCANCODE_T:        input->is_key[KEY__T] = FALSE;       break;
                case SDL_SCANCODE_Y:        input->is_key[KEY__Y] = FALSE;       break;
                case SDL_SCANCODE_U:        input->is_key[KEY__U] = FALSE;       break;
                case SDL_SCANCODE_I:        input->is_key[KEY__I] = FALSE;       break;
                case SDL_SCANCODE_O:        input->is_key[KEY__O] = FALSE;       break;
                case SDL_SCANCODE_P:        input->is_key[KEY__P] = FALSE;       break;

                case SDL_SCANCODE_A:        input->is_key[KEY__A] = FALSE;       break;
                case SDL_SCANCODE_S:        input->is_key[KEY__S] = FALSE;       break;
                case SDL_SCANCODE_D:        input->is_key[KEY__D] = FALSE;       break;
                case SDL_SCANCODE_F:        input->is_key[KEY__F] = FALSE;       break;
                case SDL_SCANCODE_G:        input->is_key[KEY__G] = FALSE;       break;
                case SDL_SCANCODE_H:        input->is_key[KEY__H] = FALSE;       break;
                case SDL_SCANCODE_J:        input->is_key[KEY__J] = FALSE;       break;
                case SDL_SCANCODE_K:        input->is_key[KEY__K] = FALSE;       break;
                case SDL_SCANCODE_L:        input->is_key[KEY__L] = FALSE;       break;

                case SDL_SCANCODE_Z:        input->is_key[KEY__Z] = FALSE;       break;
                case SDL_SCANCODE_X:        input->is_key[KEY__X] = FALSE;       break;
                case SDL_SCANCODE_C:        input->is_key[KEY__C] = FALSE;       break;
                case SDL_SCANCODE_V:        input->is_key[KEY__V] = FALSE;       break;
                case SDL_SCANCODE_B:        input->is_key[KEY__B] = FALSE;       break;
                case SDL_SCANCODE_N:        input->is_key[KEY__N] = FALSE;       break;
                case SDL_SCANCODE_M:        input->is_key[KEY__M] = FALSE;       break;

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
                case SDL_BUTTON_LEFT:   input->is_mouse_left = TRUE;   break;
                case SDL_BUTTON_MIDDLE: input->is_mouse_middle = TRUE; break;
                case SDL_BUTTON_RIGHT:  input->is_mouse_right = TRUE;  break;
                default: break;
            }

            break;
            case SDL_MOUSEBUTTONUP:

            switch(mouse_button_event.button)
            {
                case SDL_BUTTON_LEFT:   input->is_mouse_left = FALSE;   break;
                case SDL_BUTTON_MIDDLE: input->is_mouse_middle = FALSE; break;
                case SDL_BUTTON_RIGHT:  input->is_mouse_right = FALSE;  break;
                default: break;
            }

            break;
            case SDL_MOUSEWHEEL:

            input->is_mouse_scrolling = TRUE;
            input->mouse_scrolled = mouse_wheel_event.y;

            break;
            default:
            break;
        }
    }
}
