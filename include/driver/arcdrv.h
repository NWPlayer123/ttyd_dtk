#pragma once

#include "sdk/arc.h"

#include <dolphin/types.h>


typedef struct ArchiveEntry {
    u16 flags;        //0x0
    u8 align2[2];     //0x2
    ARCHandle handle; //0x4
    void* data;       //0x24
    u32 size;         //0x24
} ArchiveEntry;

void arcInit(void);
BOOL arcDataCheck(void* address);
void arcEntry(s32 index, void* data, u32 size);
void arcDelete(s32 index);
void* arcOpen(const char* filename, void** address, u32* length);
