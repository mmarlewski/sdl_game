#include "../inc/augmentation.h"

int get_augmentation_body_part(int augmentation)
{
    int body_part = BODY_PART__NONE;

    switch (augmentation)
    {
        case AUGMENTATION__FIST_HAND:           body_part = BODY_PART__LEFT_HAND; break;
        case AUGMENTATION__HOOK_HAND:           body_part = BODY_PART__LEFT_HAND; break;
        case AUGMENTATION__CHAIN_HAND:          body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__SCISSOR_HAND:        body_part = BODY_PART__RIGHT_HAND; break;
        case AUGMENTATION__SPRING_LEG:          body_part = BODY_PART__LEFT_LEG; break;
        case AUGMENTATION__STRIDER_LEG:         body_part = BODY_PART__LEFT_LEG; break;
        case AUGMENTATION__TRACK_LEG:           body_part = BODY_PART__RIGHT_LEG; break;
        case AUGMENTATION__BOOT_LEG:            body_part = BODY_PART__RIGHT_LEG; break;
        case AUGMENTATION__MINIBOT_TORSO:       body_part = BODY_PART__TORSO; break;
        case AUGMENTATION__WINGS_TORSO:         body_part = BODY_PART__TORSO; break;
        case AUGMENTATION__MANIPULATION_HEAD:   body_part = BODY_PART__HEAD; break;
        case AUGMENTATION__TELEPORTATION_HEAD:  body_part = BODY_PART__LEFT_HAND; break;
        default: break;
    }

    return body_part;
}

char* get_body_part_name(int body_part)
{
    char* name = "";

    switch (body_part)
    {
        case BODY_PART__NONE:           name = "none"; break;
        case BODY_PART__LEFT_HAND:      name = "left hand"; break;
        case BODY_PART__RIGHT_HAND:     name = "right hand"; break;
        case BODY_PART__LEFT_LEG:       name = "left leg"; break;
        case BODY_PART__RIGHT_LEG:      name = "right leg"; break;
        case BODY_PART__TORSO:          name = "torso"; break;
        case BODY_PART__HEAD:           name = "head"; break;
        default: break;
    }

    return name;
}

char* get_augmentation_name(int augmentation)
{
    char* name = "";

    switch (augmentation)
    {
        case AUGMENTATION__NONE:                name = "none"; break;
        case AUGMENTATION__FIST_HAND:           name = "fist hand"; break;
        case AUGMENTATION__HOOK_HAND:           name = "hook hand"; break;
        case AUGMENTATION__CHAIN_HAND:          name = "chain hand"; break;
        case AUGMENTATION__SCISSOR_HAND:        name = "scissor hand"; break;
        case AUGMENTATION__SPRING_LEG:          name = "spring leg"; break;
        case AUGMENTATION__STRIDER_LEG:         name = "strider leg"; break;
        case AUGMENTATION__TRACK_LEG:           name = "track leg"; break;
        case AUGMENTATION__BOOT_LEG:            name = "boot leg"; break;
        case AUGMENTATION__MINIBOT_TORSO:       name = "minibot torso"; break;
        case AUGMENTATION__WINGS_TORSO:         name = "wings torso"; break;
        case AUGMENTATION__MANIPULATION_HEAD:   name = "manipulation head"; break;
        case AUGMENTATION__TELEPORTATION_HEAD:  name = "teleportation head"; break;
        default: break;
    }

    return name;
}
