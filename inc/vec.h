#ifndef VEC_H
#define VEC_H

#include "../inc/common.h"

typedef struct
{
    int x, y;

} Vec2i;

typedef struct
{
    float x, y;

} Vec2f;

typedef struct
{
    int x, y, z;

} Vec3i;

typedef struct
{
    float x, y, z;

} Vec3f;

typedef struct
{
    int x, y, z, w;

} Vec4i;

typedef struct
{
    float x;
    float y;
    float z;
    float w;

} Vec4f;

Vec2i vec2i(int x, int y);
Vec2i* new_vec2i(int x, int y);
Vec2i* new_vec2i_from_vec2i(Vec2i vec);
void destroy_vec2i(Vec2i* vec);

Vec2i vec2i_add(Vec2i vec_1, Vec2i vec_2);
Vec2i vec2i_sub(Vec2i vec_1, Vec2i vec_2);
Vec2i vec2i_mul(Vec2i vec_1, int scalar);
int vec2i_equals(Vec2i vec_1, Vec2i vec_2);

Vec2f vec2f(float x, float y);
Vec2f* new_vec2f(float x, float y);
Vec2f* new_vec2f_from_vec2f(Vec2f vec);
void destroy_vec2f(Vec2f* vec);

Vec2f vec2f_add(Vec2f vec_1, Vec2f vec_2);
Vec2f vec2f_sub(Vec2f vec_1, Vec2f vec_2);
Vec2f vec2f_mul(Vec2f vec_1, float scalar);
int vec2f_equals(Vec2f vec_1, Vec2f vec_2, float epsilon);

Vec3i vec3i(int x, int y, int z);
Vec3i* new_vec3i(int x, int y, int z);
Vec3i* new_vec3i_from_vec3i(Vec3i vec);
void destroy_vec3i(Vec3i* vec);

Vec3i vec3i_add(Vec3i vec_1, Vec3i vec_2);
Vec3i vec3i_sub(Vec3i vec_1, Vec3i vec_2);
Vec3i vec3i_mul(Vec3i vec_1, int scalar);
int vec3i_equals(Vec3i vec_1, Vec3i vec_2);

Vec3f vec3f(float x, float y, float z);
Vec3f* new_vec3f(float x, float y, float z);
Vec3f* new_vec3f_from_vec3f(Vec3f vec);
void destroy_vec3f(Vec3f* vec);

Vec3f vec3f_add(Vec3f vec_1, Vec3f vec_2);
Vec3f vec3f_sub(Vec3f vec_1, Vec3f vec_2);
Vec3f vec3f_mul(Vec3f vec_1, float scalar);
int vec3f_equals(Vec3f vec_1, Vec3f vec_2, float epsilon);

Vec4i vec4i(int x, int y, int z, int w);
Vec4i* new_vec4i(int x, int y, int z, int w);
Vec4i* new_vec4i_from_vec4i(Vec4i vec);
void destroy_vec4i(Vec4i* vec);

Vec4i vec4i_add(Vec4i vec_1, Vec4i vec_2);
Vec4i vec4i_sub(Vec4i vec_1, Vec4i vec_2);
Vec4i vec4i_mul(Vec4i vec_1, int scalar);
int vec4i_equals(Vec4i vec_1, Vec4i vec_2);

Vec4f vec4f(float x, float y, float z, float w);
Vec4f* new_vec4f(float x, float y, float z, float w);
Vec4f* new_vec4f_from_vec4f(Vec4f vec);
void destroy_vec4f(Vec4f* vec);

Vec4f vec4f_add(Vec4f vec_1, Vec4f vec_2);
Vec4f vec4f_sub(Vec4f vec_1, Vec4f vec_2);
Vec4f vec4f_mul(Vec4f vec_1, float scalar);
int vec4f_equals(Vec4f vec_1, Vec4f vec_2, float epsilon);

Vec2i floor_vec2f_to_vec2i(Vec2f vec_in);
Vec2f vec2i_to_vec2f(Vec2i vec_in);

int is_tilemap_in_bounds(Vec2i tilemap_pos);

#endif
