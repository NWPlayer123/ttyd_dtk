#include "battle/battle_camera.h"

#include "battle/battle.h"

#pragma optimize_for_size on
void battleCameraInit(void) {
    BattleWork* wp = _battleWorkPointer;
    BattleWorkCamera* camera = &wp->camera;

    memset(camera, 0, sizeof(BattleWorkCamera));
    camera->flags = 0;
    switch (wp->info->firstAttack) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        camera->mode = 15;
        break;
    case 9:
        camera->mode = 16;
        break;
    case 0:
        camera->mode = 14;
        break;
    }
    camera->priorityLimit = 0;
    camera->zoom = 0.0f;
    camera->moveSpeedLevel = 1;
    camera->zoomSpeedLevel = 1;
    camera->offset = (Vec) {0.0f, 0.0f, 0.0f};
    camera->counter = 0;
}
#pragma optimize_for_size off

#pragma dont_inline on
f32 battleCameraGetPosMoveSpeed(void) {
    f32 x, y, z;

    x = _battleWorkPointer->camera.moveSpeed.x;
    y = _battleWorkPointer->camera.moveSpeed.y;
    z = _battleWorkPointer->camera.moveSpeed.z;
    return (f32)sqrt((x * x) + (y * y) + (z * z));
}

#pragma dont_inline on
void btl_camera_set_prilimit(s32 limit) {
    _battleWorkPointer->camera.priorityLimit = limit;
}
#pragma dont_inline reset

USER_FUNC(evt_btl_camera_set_prilimit) {
    s32 limit;

    limit = evtGetValue(event, *event->args);
    btl_camera_set_prilimit(limit);
    return EVT_RETURN_DONE;
}

USER_FUNC(evt_btl_camera_wait_move_end) {
    if (battleCameraGetPosMoveSpeed() >= 2.0f) {
        return EVT_RETURN_BLOCK;
    }
    return EVT_RETURN_DONE;
}
