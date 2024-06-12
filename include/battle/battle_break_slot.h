#pragma once

#include <dolphin/types.h>

typedef struct BattleWorkBreakSlot {
    u8 unk0[0x134 - 0x0]; //0x0
} BattleWorkBreakSlot;
STATIC_ASSERT_SIZEOF(BattleWorkBreakSlot, 0x134);

void BattleBreakSlot_Init(void);
void BattleBreakSlot_Main(void);
void BattleBreakSlot_End(void);
