#pragma once

#include <dolphin/mtx.h>

#include "event/evt_cmd.h"

typedef struct BattleWorkCamera {
    s32 flags; //0x0
    s32 counter; //0x4, counter when firstAttack is 0 
    s32 priorityLimit; //0x8
    s32 mode; //0xC
    u8 unk10[0x24 - 0x10]; //0x10
    f32 zoom; //0x24
    s16 moveSpeedLevel; //0x28
    s16 zoomSpeedLevel; //0x2A
    u8 unk2C[0x5C - 0x2C]; //0x2C
    Vec offset; //0x5C
    Vec moveSpeed; //0x68
    u8 unk74[0x104 - 0x74]; //0x74
} BattleWorkCamera;
STATIC_ASSERT_SIZEOF(BattleWorkCamera, 0x104);

USER_FUNC(evt_btl_camera_set_prilimit);
