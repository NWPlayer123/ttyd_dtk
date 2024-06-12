#include "battle/battle_unit.h"

#include "battle/battle.h"
#include "battle/battle_status_effect.h"
#include "battle/battle_status_icon.h"

#include "mario/mario_pouch.h"

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





BOOL BtlUnit_CheckShadowGuard(BattleWorkUnit* unit) {
    if (unit->attributes & ATTRIBUTE_VEILED) {
        return TRUE;
    }
    
    if (unit->currentType == UNIT_VIVIAN && unit->work[4] > 0) {
        return TRUE;
    }

    return FALSE;
}
