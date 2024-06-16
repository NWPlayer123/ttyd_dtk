#pragma once

#include <dolphin/types.h>

typedef struct EventEntry {
    u8 unk0[0x18 - 0x0]; //0x0
    s32* args; //0x18
    u8 unk1C[0x1B0 - 0x1C]; //0x1C
} EventEntry;
STATIC_ASSERT_SIZEOF(EventEntry, 0x1B0);

BOOL evtCheckID(s32 eventId);
