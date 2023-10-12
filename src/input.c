#include "../inc/input.h"

void init_input (Input* input)
{
    input->is_quit = 0;

    input->is_esc = 0;
    input->was_esc = 0;
    input->is_up = 0;
    input->was_up = 0;
    input->is_down = 0;
    input->was_down = 0;
    input->is_left = 0;
    input->was_left = 0;
    input->is_right = 0;
    input->was_right = 0;

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

void update_input (Input* input)
{
    SDL_Event event;

    // reset some of the input

    input->is_mouse_scrolling = 0;

    // update 'was' from 'is'

    input->was_esc = input->is_esc;
    input->was_up = input->is_up;
    input->was_down = input->is_down;
    input->was_left = input->is_left;
    input->was_right = input->is_right;
    input->was_mouse_left = input->is_mouse_left;
    input->was_mouse_middle = input->is_mouse_middle;
    input->was_mouse_right = input->is_mouse_right;

    while (SDL_PollEvent(&event))
    {
        // event types

        SDL_KeyboardEvent keyboard_event = event.key;

        SDL_MouseButtonEvent mouse_button_event = event.button;
        SDL_MouseMotionEvent mouse_motion_event = event.motion;
        SDL_MouseWheelEvent mouse_wheel_event = event.wheel;

        switch (event.type)
        {
            case SDL_QUIT:
            
            input->is_quit = 1;
            
            break;
            case SDL_KEYDOWN:

            switch (keyboard_event.keysym.scancode)
            {
                case SDL_SCANCODE_ESCAPE: input->is_esc = 1;   break;
                case SDL_SCANCODE_UP:     input->is_up = 1;    break;
                case SDL_SCANCODE_DOWN:   input->is_down = 1;  break;
                case SDL_SCANCODE_LEFT:   input->is_left = 1;  break;
                case SDL_SCANCODE_RIGHT:  input->is_right = 1; break;
                default: break;
            }

			break;
			case SDL_KEYUP:

            switch (keyboard_event.keysym.scancode)
            {
                case SDL_SCANCODE_ESCAPE: input->is_esc = 0;   break;
                case SDL_SCANCODE_UP:     input->is_up = 0;    break;
                case SDL_SCANCODE_DOWN:   input->is_down = 0;  break;
                case SDL_SCANCODE_LEFT:   input->is_left = 0;  break;
                case SDL_SCANCODE_RIGHT:  input->is_right = 0; break;
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