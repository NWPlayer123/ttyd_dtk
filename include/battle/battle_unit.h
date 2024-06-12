#pragma once

#include <dolphin/types.h>

typedef enum BattleUnitType {
    UNIT_MARIO = 222, //0xDE
    UNIT_SHELL_SHIELD, //0xDF
    UNIT_GOOMBELLA, //0xE0
    UNIT_KOOPS, //0xE1
    UNIT_YOSHI, //0xE2
    UNIT_FLURRIE, //0xE3
    UNIT_VIVIAN, //0xE4
    UNIT_BOBBERY, //0xE5
    UNIT_MS_MOWZ, //0xE6
    UNIT_MAX, //0xE7
} BattleUnitType;
#define UNIT_PARTNER_MIN UNIT_GOOMBELLA
#define UNIT_PARTNER_MAX UNIT_MS_MOWZ+1

typedef enum BattleUnitAttribute {
    ATTRIBUTE_VEILED = (1 << 4)
} BattleUnitAttribute;

typedef struct BattleDataEntry {
    u8 unk0[0x8 - 0x0]; //0x0
} BattleDataEntry;

typedef struct BattleUnitData {
    BattleUnitType type; //0x0
    u8 unk4[0xE - 0x4]; //0x4
    s8 level; //0xE
    u8 unkF[0xC0 - 0xF]; //0xF
    BattleDataEntry* dataTable; //0xC0
} BattleUnitData;
STATIC_ASSERT_SIZEOF(BattleUnitData, 0xC4);

typedef struct BattleWorkUnit {
    s32 unitId; //0x0
    BattleUnitType initialType; //0x4
    BattleUnitType currentType; //0x8
    s8 alliance; //0xC
    s8 level; //0xD
    s8 groupId; //0xE, used when determining if Ms Mowz can steal an item from this unit
    u8 paddingF; //0xF
    BattleUnitData* data; //0x10
    u8 unk14[0x18 - 0x14]; //0x14
    BattleDataEntry* dataTable; //0x18
    s32 flags; //0x1C
    u8 unk20[0x2C - 0x20]; //0x20
    s32 attackPhase; //0x2C
    u8 unk30[0x104 - 0x30]; //0x30
    BattleUnitAttribute attributes; //0x104
    u8 unk108[0x218 - 0x108]; //0x108
    s32 work[16]; //0x218
    u8 unk258[0xB34 - 0x258]; //0x258
} BattleWorkUnit;
STATIC_ASSERT_SIZEOF(BattleWorkUnit, 0xB34);

BOOL BtlUnit_Init(void);

BOOL BtlUnit_Delete(BattleWorkUnit* unit);

void BtlUnit_SetPos(BattleWorkUnit* unit, f32 x, f32 y, f32 z);
