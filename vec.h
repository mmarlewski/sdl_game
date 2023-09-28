#ifndef VEC_H
#define VEC_H

#include "common.h"

typedef struct _vec2i vec2i;
typedef struct _vec2f vec2f;
typedef struct _vec3i vec3i;
typedef struct _vec3f vec3f;
typedef struct _vec4i vec4i;
typedef struct _vec4f vec4f;

struct _vec2i
{
    vec2i* next;
    int x,y;
};

struct _vec2f
{
    vec2f* next;
    float x,y;
};

struct _vec3i
{
    vec3i* next;
    int x,y,z;
};

struct _vec3f
{
    vec3f* next;
    float x,y,z;
};

struct _vec4i
{
    vec4i* next;
    int x,y,z,w;
};

struct _vec4f
{
    vec4f* next;
    float x;
    float y;
    float z;
    float w;
};

vec2i make_vec2i (int x, int y);
vec2i* new_vec2i (int x, int y);
void destroy_vec2i (vec2i* vec);

vec2f make_vec2f (float x, float y);
vec2f* new_vec2f (float x, float y);
void destroy_vec2f (vec2f* vec);

vec3i make_vec3i (int x, int y, int z);
vec3i* new_vec3i (int x, int y, int z);
void destroy_vec3i (vec3i* vec);

vec3f make_vec3f (float x, float y, float z);
vec3f* new_vec3f (float x, float y, float z);
void destroy_vec3f (vec3f* vec);

vec4i make_vec4i (int x, int y, int z, int w);
vec4i* new_vec4i (int x, int y, int z, int w);
void destroy_vec4i (vec4i* vec);

vec4f make_vec4f (float x, float y, float z, float w);
vec4f* new_vec4f (float x, float y, float z, float w);
void destroy_vec4f (vec4f* vec);

vec2i floor_vec2f_to_vec2i(vec2f vec_in);
vec2f vec2i_to_vec2f(vec2i vec_in);

#endif