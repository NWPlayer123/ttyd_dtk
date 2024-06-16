#pragma once

#include <dolphin/types.h>

typedef struct BackgroundWork {
    u8 unk0[0x20 - 0x0]; //0x0
} BackgroundWork;

void bgInit(void);
void bgReInit(void);
