#pragma once

#include <dolphin/types.h>

typedef enum ItemType {
    ITEM_COIN = 0x79
} ItemType;

typedef struct PouchData {
    u8 unk0[0x8A - 0x0]; //0x0
    s16 level; //0x8A
    u8 unk8C[0x5D4 - 0x8C]; //0x8C
} PouchData;

PouchData* pouchGetPtr(void);
