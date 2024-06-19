#pragma once

#include "sound.h"

#include <dolphin/mtx.h>


typedef struct PaperSoundEnv {
    u8 unk0[0x24 - 0x0]; //0x0
} PaperSoundEnv;
STATIC_ASSERT_SIZEOF(PaperSoundEnv, 0x24);

typedef struct PaperSoundEffect {
    u32 listIndex;         //0x0
    u8 unk0[0x6 - 0x4];    //0x4
    u16 unk6;              //0x6
    u8 volume;             //0x8
    u8 unk9[0x14 - 0x9];   //0x9
    u16 pitch;             //0x14
    u8 unk16[0x18 - 0x16]; //0x16
    s32 effectId;          //0x18
    Vec position;          //0x1C
} PaperSoundEffect;
STATIC_ASSERT_SIZEOF(PaperSoundEffect, 0x28);

typedef struct PaperSoundEffectData {
    u8 unk0[0x4 - 0x0];  //0x0
    u32 unk4;            //0x4
    u8 unk8[0x14 - 0x8]; //0x8
} PaperSoundEffectData;
STATIC_ASSERT_SIZEOF(PaperSoundEffectData, 0x14);

typedef struct PaperSoundBGM {
    u8 unk0[0x38 - 0x0]; //0x0
} PaperSoundBGM;
STATIC_ASSERT_SIZEOF(PaperSoundBGM, 0x38);

typedef struct PaperSoundWork {
    u8 unk0[0x60 - 0x0]; //0x0
} PaperSoundWork;
STATIC_ASSERT_SIZEOF(PaperSoundWork, 0x60);

u32 psndSFXOn_3D(s32 lookup, Vec* position);
void psndSFX_vol(u32 index, u8 volume);
void psndSFX_pit(u32 index, u32 pitch);
u8 psndSFX_get_vol(u32 index);
