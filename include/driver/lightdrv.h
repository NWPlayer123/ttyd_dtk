#pragma once

#include <dolphin/gx.h>
#include <dolphin/mtx.h>

#pragma enumsalwaysint off
typedef enum LightEntryFlags {
    LIGHT_ENABLED = 1 << 0,
    LIGHT_NO_DIST_ATTEN = 1 << 6, //TODO: rename?
    LIGHT_CHARA = 1 << 7,
    LIGHT_POINT = 1 << 12,
    LIGHT_SPOT = 1 << 13,
    LIGHT_DIRECTIONAL = 1 << 14,
    LIGHT_AMBIENT = 1 << 15
} LightEntryFlags;
#pragma enumsalwaysint on

typedef struct LightEntry {
    LightEntryFlags flags; //0x0
    char name[32];         //0x2
    u8 align_22[2];        //0x22
    Vec position;          //0x24
    Vec rotation;          //0x30
    Vec field_0x3C;        //0x3C, some other positional
    GXColor color;         //0x48
    f32 spotAngle;         //0x4C
    f32 attenAngle;        //0x50
    Vec attenDistCoef;     //0x54
} LightEntry;
#ifdef __MWERKS__
STATIC_ASSERT_SIZEOF(LightEntry, 0x60);
#endif

LightEntry* lightGetPaperCraft(void);
