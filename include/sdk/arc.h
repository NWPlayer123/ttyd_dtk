#pragma once

#include <dolphin/types.h>

typedef struct ARCHandle {
    void* archiveStartAddr;
    void* FSTStart;
    void* fileStart;
    u32 entryNum;
    char* FSTStringStart;
    u32 FSTLength;
    u32 currDir;
} ARCHandle;

typedef struct ARCFileInfo {
    ARCHandle* handle;
    u32 entryNum;
    u32 location;
    u32 next;
} ARCFileInfo;

BOOL ARCInitHandle(void* data, ARCHandle* handle);
BOOL ARCOpen(ARCHandle* handle, const char* filename, ARCFileInfo* info);
void* ARCGetStartAddrInMem(ARCFileInfo* info);
u32 ARCGetLength(ARCFileInfo* info);
BOOL ARCClose(ARCFileInfo* info);
