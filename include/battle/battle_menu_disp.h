#pragma once

#include <dolphin/types.h>

typedef struct BattleWorkCommandMenu {
    u8 unk0[0x124 - 0x0]; //0x0
} BattleWorkCommandMenu;

void battleMenuDispEnd(void);
