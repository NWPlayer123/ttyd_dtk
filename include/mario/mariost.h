#pragma once

#include <dolphin/types.h>

typedef struct GlobalWork {
    s32 flags; //0x0
    u8 unk4[0x13D8 - 0x4]; //0x4
} GlobalWork;

extern GlobalWork* gp;
