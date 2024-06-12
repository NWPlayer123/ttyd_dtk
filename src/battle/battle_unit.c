#include "battle/battle_unit.h"

#include "battle/battle.h"
#include "battle/battle_status_effect.h"
#include "battle/battle_status_icon.h"
#include "mario/mario_pouch.h"

//.data
s32 _enemy_can_use_item_table[33] = {
    ITEM_THUNDER_BOLT,  ITEM_FIRE_FLOWER,   ITEM_POW_BLOCK,   ITEM_THUNDER_RAGE,
    ITEM_SHOOTING_STAR, ITEM_ICE_STORM,     ITEM_EARTH_QUAKE, ITEM_HP_DRAIN_ITEM,
    ITEM_SLEEPY_SHEEP,  ITEM_STOPWATCH,     ITEM_DIZZY_DIAL,  ITEM_MINI_MR_MINI,
    ITEM_MR_SOFTENER,   ITEM_RUIN_POWDER,   ITEM_POWER_PUNCH, ITEM_COURAGE_SHELL,
    ITEM_BOOS_SHEET,    ITEM_VOLT_SHROOM,   ITEM_REPEL_CAPE,  ITEM_MUSHROOM,
    ITEM_SUPER_SHROOM,  ITEM_ULTRA_SHROOM,  ITEM_LIFE_SHROOM, ITEM_DRIED_SHROOM,
    ITEM_TASTY_TONIC,   ITEM_HONEY_SYRUP,   ITEM_MAPLE_SYRUP, ITEM_JAMMIN_JELLY,
    ITEM_SLOW_SHROOM,   ITEM_GRADUAL_SYRUP, ITEM_HOT_DOG,     ITEM_CAKE,
    ITEM_NULL};

#pragma optimize_for_size on
BOOL BtlUnit_Init(void) {
    int i;
    BattleWork* wp = _battleWorkPointer;

    for (i = 0; i < 64; i++) {
        BattleSetUnitPtr(wp, i, NULL);
    }

    return TRUE;
}
#pragma optimize_for_size off

BattleWorkUnit* BtlUnit_Entry(BattleUnitSetup* setup) {
    BattleWork* wp = _battleWorkPointer;
    BattleWorkUnit* unit;
    BattleUnitType type;
    int i;

    for (i = 0; i < 64; i++) {
        // Loop to find the end of the list
        if (BattleGetUnitPtr(wp, i) == NULL) {
            break;
        }
    }

    // Make sure we even have a slot to add the unit
    if (i >= 64) {
        return NULL;
    }

    // Allocate a new unit, and make sure it's valid
    unit = BattleAlloc(sizeof(BattleWorkUnit));
    if (unit == NULL) {
        return NULL;
    }

    memset(unit, 0, sizeof(BattleWorkUnit));
    BattleSetUnitPtr(wp, i, unit);
    unit->unitId = i;
    unit->data = setup->data;
    unit->dataTable = unit->data->dataTable;
    unit->initialType = setup->data->type;
    unit->currentType = setup->data->type;
    BattleStatusEffectInit(unit);
    BattleStatusIconInit(unit);
    BattleStatusChangeInfoWorkInit(unit);
    unit->groupId = -1;
    unit->alliance = setup->alliance;
    unit->level = unit->data->level;
    type = unit->currentType;
    if (type == UNIT_MARIO || type >= UNIT_PARTNER_MIN && type < UNIT_PARTNER_MAX) {
        unit->level = pouchGetPtr()->level;
    }
    unit->attackPhase = setup->attackPhase;
}

s32 BtlUnit_EnemyItemCanUseCheck(ItemType type) {
    s32 item;
    s32* table;

    table = _enemy_can_use_item_table;
    // If we're just using a badge, return it
    if (type >= BADGE_MIN && type < BADGE_MAX) {
        return type;
    }

    // Otherwise, check the item table to see if it's allowed
    while (item = *table) {
        if (item == type) {
            return type;
        }
        table++;
    }
    return 0;
}

BOOL BtlUnit_CheckShadowGuard(BattleWorkUnit* unit) {
    if (unit->attributes & ATTRIBUTE_VEILED) {
        return TRUE;
    }

    if (unit->currentType == UNIT_VIVIAN && unit->work[4] > 0) {
        return TRUE;
    }

    return FALSE;
}
