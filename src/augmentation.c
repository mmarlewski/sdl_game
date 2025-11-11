#include "../inc/augmentation.h"

int get_augmentation_body_part(int augmentation)
{
    int body_part = BODY_PART__NONE;

    switch(augmentation)
    {
        case AUGMENTATION__SPRING:      body_part = BODY_PART__LEFT_LEG; break;
        case AUGMENTATION__TRACK:       body_part = BODY_PART__RIGHT_LEG; break;
        case AUGMENTATION__TAIL:        body_part = BODY_PART__TAIL; break;
        case AUGMENTATION__MINIBOT:     body_part = BODY_PART__TORSO; break;
        
        case AUGMENTATION__ARM:         body_part = BODY_PART__LEFT_HAND; break;
        case AUGMENTATION__DRILL:       body_part = BODY_PART__LEFT_HAND; break;
        case AUGMENTATION__BLADE:       body_part = BODY_PART__LEFT_HAND; break;
        case AUGMENTATION__HAMMER:      body_part = BODY_PART__LEFT_HAND; break;
        case AUGMENTATION__WHIP:        body_part = BODY_PART__LEFT_HAND; break;

        case AUGMENTATION__GUN:         body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__CROSSBOW:    body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__COIL:        body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__FLAME:       body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__FREEZE:      body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__LASER:       body_part = BODY_PART__RIGHT_HAND; break;

        default: break;
    }

    return body_part;
}

char* get_body_part_name(int body_part)
{
    char* name = "";

    switch(body_part)
    {
        case BODY_PART__NONE:           name = "none"; break;
        case BODY_PART__LEFT_HAND:      name = "left hand"; break;
        case BODY_PART__RIGHT_HAND:     name = "right hand"; break;
        case BODY_PART__LEFT_LEG:       name = "left leg"; break;
        case BODY_PART__RIGHT_LEG:      name = "right leg"; break;
        case BODY_PART__TORSO:          name = "torso"; break;
        case BODY_PART__TAIL:           name = "tail"; break;
        default: break;
    }

    return name;
}

char* get_augmentation_name(int augmentation)
{
    char* name = "";

    switch(augmentation)
    {

        case AUGMENTATION__SPRING:      name = "spring"; break;
        case AUGMENTATION__TRACK:       name = "track"; break;
        case AUGMENTATION__TAIL:        name = "tail"; break;
        case AUGMENTATION__MINIBOT:     name = "minibot"; break;
        case AUGMENTATION__WINGS:       name = "wings"; break;
        
        case AUGMENTATION__ARM:         name = "arm"; break;
        case AUGMENTATION__DRILL:       name = "drill"; break;
        case AUGMENTATION__BLADE:       name = "blade"; break;
        case AUGMENTATION__HAMMER:      name = "hammer"; break;
        case AUGMENTATION__WHIP:        name = "whip"; break;

        case AUGMENTATION__GUN:         name = "gun"; break;
        case AUGMENTATION__CROSSBOW:    name = "crossbow"; break;
        case AUGMENTATION__COIL:        name = "coil"; break;
        case AUGMENTATION__FLAME:       name = "flame"; break;
        case AUGMENTATION__FREEZE:      name = "freeze"; break;
        case AUGMENTATION__LASER:       name = "laser"; break;

        default: break;
    }

    return name;
}
