#include "../inc/vec.h"

//
// VEC 2 I
//

Vec2i vec2i(int x, int y)
{
    Vec2i vec;

    vec.x = x;
    vec.y = y;

    return vec;
}
Vec2i* new_vec2i(int x, int y)
{
    Vec2i* vec = malloc(sizeof(*vec));

    vec->x = x;
    vec->y = y;

    return vec;
}
Vec2i* new_vec2i_from_vec2i(Vec2i vec)
{
    return new_vec2i(vec.x, vec.y);
}
void destroy_vec2i(Vec2i* vec)
{
    free(vec);
}
Vec2i vec2i_add(Vec2i vec_1, Vec2i vec_2)
{
    Vec2i vec;

    vec.x = vec_1.x + vec_2.x;
    vec.y = vec_1.y + vec_2.y;

    return vec;
}
Vec2i vec2i_sub(Vec2i vec_1, Vec2i vec_2)
{
    Vec2i vec;

    vec.x = vec_1.x - vec_2.x;
    vec.y = vec_1.y - vec_2.y;

    return vec;
}
Vec2i vec2i_mul(Vec2i vec_1, int scalar)
{
    Vec2i vec;

    vec.x = vec_1.x * scalar;
    vec.y = vec_1.y * scalar;

    return vec;
}
int vec2i_equals(Vec2i vec_1, Vec2i vec_2)
{
    return (vec_1.x == vec_2.x &&
            vec_1.y == vec_2.y);
}

//
// VEC 2 F
//

Vec2f vec2f(float x, float y)
{
    Vec2f vec;

    vec.x = x;
    vec.y = y;

    return vec;
}
Vec2f* new_vec2f(float x, float y)
{
    Vec2f* vec = malloc(sizeof(*vec));

    vec->x = x;
    vec->y = y;

    return vec;
}
Vec2f* new_vec2f_from_vec2f(Vec2f vec)
{
    return new_vec2f(vec.x, vec.y);
}
void destroy_vec2f(Vec2f* vec)
{
    free(vec);
}
Vec2f vec2f_add(Vec2f vec_1, Vec2f vec_2)
{
    Vec2f vec;

    vec.x = vec_1.x + vec_2.x;
    vec.y = vec_1.y + vec_2.y;

    return vec;
}
Vec2f vec2f_sub(Vec2f vec_1, Vec2f vec_2)
{
    Vec2f vec;

    vec.x = vec_1.x - vec_2.x;
    vec.y = vec_1.y - vec_2.y;

    return vec;
}
Vec2f vec2f_mul(Vec2f vec_1, float scalar)
{
    Vec2f vec;

    vec.x = vec_1.x * scalar;
    vec.y = vec_1.y * scalar;

    return vec;
}
int vec2f_equals(Vec2f vec_1, Vec2f vec_2, float epsilon)
{
    return (fabs(vec_1.x - vec_2.x) < epsilon &&
            fabs(vec_1.y - vec_2.y) < epsilon);
}

//
// VEC 3 I
//

Vec3i vec3i(int x, int y, int z)
{
    Vec3i vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;

    return vec;
}
Vec3i* new_vec3i(int x, int y, int z)
{
    Vec3i* vec = malloc(sizeof(*vec));

    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}
Vec3i* new_vec3i_from_vec3i(Vec3i vec)
{
    return new_vec3i(vec.x, vec.y, vec.z);
}
void destroy_vec3i(Vec3i* vec)
{
    free(vec);
}
Vec3i vec3i_add(Vec3i vec_1, Vec3i vec_2)
{
    Vec3i vec;

    vec.x = vec_1.x + vec_2.x;
    vec.y = vec_1.y + vec_2.y;
    vec.z = vec_1.z + vec_2.z;

    return vec;
}
Vec3i vec3i_sub(Vec3i vec_1, Vec3i vec_2)
{
    Vec3i vec;

    vec.x = vec_1.x - vec_2.x;
    vec.y = vec_1.y - vec_2.y;
    vec.z = vec_1.z - vec_2.z;

    return vec;
}
Vec3i vec3i_mul(Vec3i vec_1, int scalar)
{
    Vec3i vec;

    vec.x = vec_1.x * scalar;
    vec.y = vec_1.y * scalar;
    vec.z = vec_1.z * scalar;

    return vec;
}
int vec3i_equals(Vec3i vec_1, Vec3i vec_2)
{
    return (vec_1.x == vec_2.x &&
            vec_1.y == vec_2.y &&
            vec_1.z == vec_2.z);
}

//
// VEC 3 F
//

Vec3f vec3f(float x, float y, float z)
{
    Vec3f vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;

    return vec;
}
Vec3f* new_vec3f(float x, float y, float z)
{
    Vec3f* vec = malloc(sizeof(*vec));

    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}
Vec3f* new_vec3f_from_vec3f(Vec3f vec)
{
    return new_vec3f(vec.x, vec.y, vec.z);
}
void destroy_vec3f(Vec3f* vec)
{
    free(vec);
}
Vec3f vec3f_add(Vec3f vec_1, Vec3f vec_2)
{
    Vec3f vec;

    vec.x = vec_1.x + vec_2.x;
    vec.y = vec_1.y + vec_2.y;
    vec.z = vec_1.z + vec_2.z;

    return vec;
}
Vec3f vec3f_sub(Vec3f vec_1, Vec3f vec_2)
{
    Vec3f vec;

    vec.x = vec_1.x - vec_2.x;
    vec.y = vec_1.y - vec_2.y;
    vec.z = vec_1.z - vec_2.z;

    return vec;
}
Vec3f vec3f_mul(Vec3f vec_1, float scalar)
{
    Vec3f vec;

    vec.x = vec_1.x * scalar;
    vec.y = vec_1.y * scalar;
    vec.z = vec_1.z * scalar;

    return vec;
}
int vec3f_equals(Vec3f vec_1, Vec3f vec_2, float epsilon)
{
    return (fabs(vec_1.x - vec_2.x) < epsilon &&
            fabs(vec_1.y - vec_2.y) < epsilon &&
            fabs(vec_1.z - vec_2.z) < epsilon);
}

//
// VEC 4 I
//

Vec4i vec4i(int x, int y, int z, int w)
{
    Vec4i vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;

    return vec;
}
Vec4i* new_vec4i(int x, int y, int z, int w)
{
    Vec4i* vec = malloc(sizeof(*vec));

    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;

    return vec;
}
Vec4i* new_vec4i_from_vec4i(Vec4i vec)
{
    return new_vec4i(vec.x, vec.y, vec.z, vec.w);
}
void destroy_vec4i(Vec4i* vec)
{
    free(vec);
}
Vec4i vec4i_add(Vec4i vec_1, Vec4i vec_2)
{
    Vec4i vec;

    vec.x = vec_1.x + vec_2.x;
    vec.y = vec_1.y + vec_2.y;
    vec.x = vec_1.x + vec_2.x;
    vec.w = vec_1.w + vec_2.w;

    return vec;
}
Vec4i vec4i_sub(Vec4i vec_1, Vec4i vec_2)
{
    Vec4i vec;

    vec.x = vec_1.x - vec_2.x;
    vec.y = vec_1.y - vec_2.y;
    vec.x = vec_1.x - vec_2.x;
    vec.w = vec_1.w - vec_2.w;

    return vec;
}
Vec4i vec4i_mul(Vec4i vec_1, int scalar)
{
    Vec4i vec;

    vec.x = vec_1.x * scalar;
    vec.y = vec_1.y * scalar;
    vec.z = vec_1.z * scalar;
    vec.w = vec_1.w * scalar;

    return vec;
}
int vec4i_equals(Vec4i vec_1, Vec4i vec_2)
{
    return (vec_1.x == vec_2.x &&
            vec_1.y == vec_2.y &&
            vec_1.z == vec_2.z &&
            vec_1.w == vec_2.w);
}

//
// VEC 4 F
//

Vec4f vec4f(float x, float y, float z, float w)
{
    Vec4f vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;

    return vec;
}
Vec4f* new_vec4f(float x, float y, float z, float w)
{
    Vec4f* vec = malloc(sizeof(*vec));

    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;

    return vec;
}
Vec4f* new_vec4f_from_vec4f(Vec4f vec)
{
    return new_vec4f(vec.x, vec.y, vec.z, vec.w);
}
void destroy_vec4f(Vec4f* vec)
{
    free(vec);
}
Vec4f vec4f_add(Vec4f vec_1, Vec4f vec_2)
{
    Vec4f vec;

    vec.x = vec_1.x + vec_2.x;
    vec.y = vec_1.y + vec_2.y;
    vec.z = vec_1.z + vec_2.z;
    vec.w = vec_1.w + vec_2.w;

    return vec;
}
Vec4f vec4f_sub(Vec4f vec_1, Vec4f vec_2)
{
    Vec4f vec;

    vec.x = vec_1.x - vec_2.x;
    vec.y = vec_1.y - vec_2.y;
    vec.z = vec_1.z - vec_2.z;
    vec.w = vec_1.w - vec_2.w;

    return vec;
}
Vec4f vec4f_mul(Vec4f vec_1, float scalar)
{
    Vec4f vec;

    vec.x = vec_1.x * scalar;
    vec.y = vec_1.y * scalar;
    vec.z = vec_1.z * scalar;
    vec.w = vec_1.w * scalar;

    return vec;
}
int vec4f_equals(Vec4f vec_1, Vec4f vec_2, float epsilon)
{
    return (fabs(vec_1.x - vec_2.x) < epsilon &&
            fabs(vec_1.y - vec_2.y) < epsilon &&
            fabs(vec_1.z - vec_2.z) < epsilon &&
            fabs(vec_1.w - vec_2.w) < epsilon);
}

//
// OTHER
//

Vec2i floor_vec2f_to_vec2i(Vec2f vec_in)
{
    Vec2i vec_out;
    vec_out.x = floor(vec_in.x);
    vec_out.y = floor(vec_in.y);
    return vec_out;
}
Vec2f vec2i_to_vec2f(Vec2i vec_in)
{
    Vec2f vec_out;
    vec_out.x = vec_in.x;
    vec_out.y = vec_in.y;
    return vec_out;
}

int is_tilemap_in_bounds(Vec2i tilemap_pos)
{
    return (tilemap_pos.x >= 0 && tilemap_pos.x < TILEMAP_LENGTH&&
            tilemap_pos.y >= 0 && tilemap_pos.y < TILEMAP_LENGTH);
}
