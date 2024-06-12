#pragma once

#include <dolphin/types.h>

typedef struct BattleWorkAudience {
    u8 unk0[0x13914 - 0x0]; //0x0
} BattleWorkAudience;
STATIC_ASSERT_SIZEOF(BattleWorkAudience, 0x13914);

void BattleAudience_Init(void);
void BattleAudience_Main(void);
void BattleAudience_End(void);
