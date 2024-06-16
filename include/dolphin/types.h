#pragma once

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef __typeof__(sizeof(0)) size_t;

typedef float f32;
typedef double f64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef volatile f32 vf32;
typedef volatile f64 vf64;

typedef int BOOL;
#define TRUE  1
#define FALSE 0

#ifdef __cplusplus
    #define NULL 0
#else
    #define NULL ((void*)0)
#endif

#define ATTRIBUTE_ALIGN(num) __attribute((aligned(num)))

//TODO: move these somewhere better
void* memset(void* dest, int ch, size_t count);
double sqrt(double);
#define STATIC_ASSERT_SIZEOF(type, size)                                                           \
    typedef char static_assert_##type##_size[(sizeof(type) == (size)) ? 1 : -1]
