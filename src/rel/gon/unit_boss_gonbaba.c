#include "gon/unit_boss_gonbaba.h"

#include "battle/battle.h"
#include "battle/battle_sub.h"

#include "driver/lightdrv.h"

#include "event/evt_cmd.h"

// local prototypes
USER_FUNC(_wait_damage_event_end);

#pragma optimize_for_size on
USER_FUNC(_wait_damage_event_end) {
    s32* args = event->args;
    BattleWork* wp = _battleWorkPointer;
    BattleWorkUnit* unit;
    s32 type;
    s32 damageId;

    type = evtGetValue(event, *args++);
    unit = BattleGetUnitPtr(wp, BattleTransID(event, type));
    if (unit == NULL) {
        return EVT_RETURN_DONE;
    }

    damageId = unit->damageEventId;
    if (damageId && evtCheckID(damageId)) {
        return EVT_RETURN_BLOCK;
    }

    return EVT_RETURN_DONE;
}
#pragma optimize_for_size off

USER_FUNC(_set_gonbaba_light) {
    LightEntry* light;
    Mtx mtx;

    light = lightGetPaperCraft();
    light->position = (Vec){-200.0f, 50.0f, 500.0f};
    MTXScale(mtx, 3.0f, 3.0f, 3.0f);
    MTXMultVec(mtx, &light->position, &light->position);

    return EVT_RETURN_DONE;
}

USER_FUNC(_btlgon_get_escape_param) {
    s32* args = event->args;
    f32 x, y;

    

}
