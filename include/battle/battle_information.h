#pragma once

#include <dolphin/types.h>

typedef struct FieldBattleInfo {
    u8 unk0[0x8 - 0x0]; //0x0
    s32 firstAttack; //0x8
    u8 unkC[0x1C - 0xC]; //0xC
} FieldBattleInfo;
STATIC_ASSERT_SIZEOF(FieldBattleInfo, 0x1C);
