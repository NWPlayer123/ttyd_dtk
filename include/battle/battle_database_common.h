#pragma once

#include <dolphin/types.h>

typedef struct BattleWeapon {
    u8 unk0[0xC0 - 0x0]; //0x0
} BattleWeapon;
STATIC_ASSERT_SIZEOF(BattleWeapon, 0xC0);
