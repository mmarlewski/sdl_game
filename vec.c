#include "vec.h"

vec2i make_vec2i (int x, int y)
{
    vec2i vec;

    vec.next = 0;
    vec.x = x;
    vec.y = y;

    return vec;
}
vec2i* new_vec2i (int x, int y)
{
    vec2i* vec = malloc(sizeof(*vec));

    vec->next = 0;
    vec->x = x;
    vec->y = y;

    return vec;
}
vec2i* new_vec2i_from_vec2i (vec2i vec)
{
    return new_vec2i(vec.x, vec.y);
}
void destroy_vec2i (vec2i* vec)
{
    free(vec);
}

vec2f make_vec2f (float x, float y)
{
    vec2f vec;

    vec.next = 0;
    vec.x = x;
    vec.y = y;

    return vec;
}
vec2f* new_vec2f (float x, float y)
{
    vec2f* vec = malloc(sizeof(*vec));

    vec->next = 0;
    vec->x = x;
    vec->y = y;

    return vec;
}
vec2f* new_vec2f_from_vec2f (vec2f vec)
{
    return new_vec2f(vec.x, vec.y);
}
void destroy_vec2f (vec2f* vec)
{
    free(vec);
}

vec3i make_vec3i (int x, int y, int z)
{
    vec3i vec;

    vec.next = 0;
    vec.x = x;
    vec.y = y;
    vec.z = z;

    return vec;
}
vec3i* new_vec3i (int x, int y, int z)
{
    vec3i* vec = malloc(sizeof(*vec));

    vec->next = 0;
    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}
vec3i* new_vec3i_from_vec3i (vec3i vec)
{
    return new_vec3i(vec.x, vec.y, vec.z);
}
void destroy_vec3i (vec3i* vec)
{
    free(vec);
}

vec3f make_vec3f (float x, float y, float z)
{
    vec3f vec;

    vec.next = 0;
    vec.x = x;
    vec.y = y;
    vec.z = z;

    return vec;
}
vec3f* new_vec3f (float x, float y, float z)
{
    vec3f* vec = malloc(sizeof(*vec));

    vec->next = 0;
    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}
vec3f* new_vec3f_from_vec3f (vec3f vec)
{
    return new_vec3f(vec.x, vec.y, vec.z);
}
void destroy_vec3f (vec3f* vec)
{
    free(vec);
}

vec4i make_vec4i (int x, int y, int z, int w)
{
    vec4i vec;

    vec.next = 0;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;

    return vec;
}
vec4i* new_vec4i (int x, int y, int z, int w)
{
    vec4i* vec = malloc(sizeof(*vec));

    vec->next = 0;
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;

    return vec;
}
vec4i* new_vec4i_from_vec4i (vec4i vec)
{
    return new_vec4i(vec.x, vec.y, vec.z, vec.w);
}
void destroy_vec4i (vec4i* vec)
{
    free(vec);
}

vec4f make_vec4f (float x, float y, float z, float w)
{
    vec4f vec;

    vec.next = 0;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;

    return vec;
}
vec4f* new_vec4f (float x, float y, float z, float w)
{
    vec4f* vec = malloc(sizeof(*vec));

    vec->next = 0;
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;

    return vec;
}
vec4f* new_vec4f_from_vec4f (vec4f vec)
{
    return new_vec4f(vec.x, vec.y, vec.z, vec.w);
}
void destroy_vec4f (vec4f* vec)
{
    free(vec);
}

vec2i floor_vec2f_to_vec2i(vec2f vec_in)
{
    vec2i vec_out;
    vec_out.x = floor(vec_in.x);
    vec_out.y = floor(vec_in.y);
    return vec_out;
}

vec2f vec2i_to_vec2f(vec2i vec_in)
{
    vec2f vec_out;
    vec_out.x = vec_in.x;
    vec_out.y = vec_in.y;
    return vec_out;
}