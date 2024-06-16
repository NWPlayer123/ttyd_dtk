#pragma once

#include <dolphin/types.h>

typedef struct {
    f32 x, y, z;
} Vec, *VecPtr, Point3d, *Point3dPtr;

typedef struct {
    s16 x, y, z;
} S16Vec, *S16VecPtr;

typedef struct {
    f32 x, y, z, w;
} Quaternion, *QuaternionPtr, Qtrn, *QtrnPtr;

typedef f32 Mtx[3][4];
typedef f32 Mtx44[4][4];

typedef f32 (*MtxPtr)[4];
typedef f32 (*Mtx44Ptr)[4];

typedef f32 ROMtx[4][3];
typedef f32 (*ROMtxPtr)[3];

//TODO: move elsewhere

#define MTXScale   PSMTXScale
#define MTXMultVec PSMTXMultVec
void PSMTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
void PSMTXMultVec(Mtx44 m, Vec* src, Vec* dst);
