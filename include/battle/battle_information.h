#pragma once

#include <dolphin/types.h>

typedef struct FieldBattleInfo {
    u8 unk0[0x1C - 0x0]; //0x0
} FieldBattleInfo;
STATIC_ASSERT_SIZEOF(FieldBattleInfo, 0x1C);
