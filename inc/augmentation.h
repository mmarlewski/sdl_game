#ifndef AUGMENTATION_H
#define AUGMENTATION_H

#include "../inc/common.h"

enum BODY_PART
{
    BODY_PART__NONE,

    BODY_PART__LEFT_HAND,
    BODY_PART__RIGHT_HAND,
    BODY_PART__LEFT_LEG,
    BODY_PART__RIGHT_LEG,
    BODY_PART__TORSO,
    BODY_PART__HEAD,

    BODY_PART__COUNT
};

enum AUGMENTATION
{
    AUGMENTATION__NONE,

    AUGMENTATION__FIST_HAND,
    AUGMENTATION__HOOK_HAND,
    AUGMENTATION__CHAIN_HAND,
    AUGMENTATION__SCISSOR_HAND,

    AUGMENTATION__SPRING_LEG,
    AUGMENTATION__STRIDER_LEG,
    AUGMENTATION__TRACK_LEG,
    AUGMENTATION__BOOT_LEG,

    AUGMENTATION__MINIBOT_TORSO,
    AUGMENTATION__WINGS_TORSO,

    AUGMENTATION__MANIPULATION_HEAD,
    AUGMENTATION__TELEPORTATION_HEAD,
    AUGMENTATION__TELEKINESIS_HEAD,

    AUGMENTATION__COUNT,
};

int get_augmentation_body_part(int augmentation);
char* get_body_part_name(int body_part);
char* get_augmentation_name(int augmentation);

#endif
