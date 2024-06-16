#pragma once

#include <dolphin/types.h>

#include "sdk/arc.h"

typedef struct ArchiveEntry {
    u16 flags; //0x0
    u8 align2[2]; //0x2
    ARCHandle handle; //0x4
    void* data; //0x24
    u32 size; //0x24
} ArchiveEntry;

void arcDelete(s32 index);
void* arcOpen(const char* filename, void** address, u32* length);
