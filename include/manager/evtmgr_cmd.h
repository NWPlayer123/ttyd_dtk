#pragma once

#include <dolphin/types.h>

s32 evtmgrCmd(struct EventEntry* entry);
s32 evtGetValue(struct EventEntry* entry, s32 index);
s32 evtGetNumber(struct EventEntry* entry, s32 index);
s32 evtSetValue(struct EventEntry* entry, s32 index, s32 value);
f32 evtGetFloat(struct EventEntry* entry, s32 index);
f32 evtSetFloat(struct EventEntry* entry, s32 index, f32 value);
