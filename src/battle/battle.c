#include "battle/battle.h"

#include "battle/battle_ac.h"
#include "battle/battle_ac_help.h"
#include "battle/battle_disp.h"
#include "battle/battle_icon.h"
#include "battle/battle_menu_disp.h"
#include "battle/battle_pad.h"
#include "battle/battle_seq.h"
#include "battle/battle_stage.h"
#include "battle/battle_stage_object.h"
#include "battle/battle_status_effect.h"
#include "mario/mariost.h"

//.sbss
BattleWork* _battleWorkPointer;

// Local Prototypes
BOOL battleSeqEndCheck(void);
BOOL BattleMain(void);

BattleWorkUnit* BattleGetUnitPtr(BattleWork* wp, s32 index);

void BattlePartyInfoWorkInit(BattleWork* wp);

void BattleCheckUnitBroken(BattleWork* wp);

void BattleAfterReactionQueueInit(void);

void battleMain(void) {
    BattleWork* wp = _battleWorkPointer;
    if (wp) {
        if (BattleMain() == FALSE) {
            wp->flags |= 0x80000000;
        }
    }
}

BOOL battleSeqEndCheck(void) {
    return _battleWorkPointer->flags >> 31;
}

// This function only matches with -O4,s and the 0-9 loop unrolled
void BattleInit(FieldBattleInfo* info) {
    BattleWork* wp;
    int i;

    _battleWorkPointer = BattleAlloc(sizeof(BattleWork));
    memset((wp = _battleWorkPointer), 0, sizeof(BattleWork));

    wp->curtainSFXId = -1;
    wp->lectureUnitId = -1;
    wp->info = info;

    BattlePadInit();
    BattleAcHelpInit();
    BattleIconInit();
    BattleActionCommandManagerInit(wp);
    BattleAfterReactionQueueInit();
    BattleStatusChangeMsgWorkInit();
    btlDispInit();
    BattleSetSeq(wp, SEQ_UNKNOWN, 0);
    BattleSetSeq(wp, SEQ_INIT, 0x1000000);

    // Not sure why we're doing all this again when we already memset the entire struct but okay
    wp->endSequenceWork = NULL;
    wp->commandMenu.flags = 0;
    // This also isn't the full amount of cursors so someone oopsied
    wp->commandMenu.cursors[0].absolutePos = 0;
    wp->commandMenu.cursors[0].relativePos = 0;
    wp->commandMenu.cursors[1].absolutePos = 0;
    wp->commandMenu.cursors[1].relativePos = 0;
    wp->commandMenu.cursors[2].absolutePos = 0;
    wp->commandMenu.cursors[2].relativePos = 0;
    wp->commandMenu.cursors[3].absolutePos = 0;
    wp->commandMenu.cursors[3].relativePos = 0;
    wp->commandMenu.cursors[4].absolutePos = 0;
    wp->commandMenu.cursors[4].relativePos = 0;
    wp->commandMenu.cursors[5].absolutePos = 0;
    wp->commandMenu.cursors[5].relativePos = 0;
    wp->commandMenu.cursors[6].absolutePos = 0;
    wp->commandMenu.cursors[6].relativePos = 0;
    wp->commandMenu.cursors[7].absolutePos = 0;
    wp->commandMenu.cursors[7].relativePos = 0;
    wp->commandMenu.cursors[8].absolutePos = 0;
    wp->commandMenu.cursors[8].relativePos = 0;
    wp->commandMenu.cursors[9].absolutePos = 0;
    wp->commandMenu.cursors[9].relativePos = 0;
    wp->commandMenu.menu = NULL;

    wp->turnCount = 0;
    memset(wp->reserveItems, 0, sizeof(wp->reserveItems));
    wp->flags = 0;

    BtlUnit_Init();
    BattlePartyInfoWorkInit(wp);
    BattleStageInit();
    BattleAudience_Init();
    BattleBreakSlot_Init();
}

BOOL BattleMain(void) {
    BattleWork* wp = _battleWorkPointer;

    BattleCheckUnitBroken(wp);
    BattlePadManager();
    BattleSequenceManager();
    BattleActionCommandManager(wp);
    BattleStageObjectMain();
    BattleIconMain();
    BattleStageMain();
    BattleAcHelpMain();
    BattleAudience_Main();
    BattleBreakSlot_Main();
    btlDispMain();

    if (BattleGetSeq(wp, SEQ_UNKNOWN) == 4) {
        return FALSE;
    }

    if ((gp->flags & 0x1000) && (gp->flags & 0x2000) && BattleGetSeq(wp, SEQ_UNKNOWN) == 2) {
        wp->flags |= 0x60;
        BattleSetSeq(wp, SEQ_UNKNOWN, 3);
        BattleSetSeq(wp, SEQ_END, 0x7000000);
        return TRUE; //very good
    }

    return TRUE;
}

void BattleEnd(void) {
    BattleWork* wp = _battleWorkPointer;
    BattleWorkUnit* unit;
    BattleWorkCommandMenu* menu;
    int i;

    for (i = 0; i < 64; i++) {
        unit = BattleGetUnitPtr(wp, i);
        if (unit) {
            BtlUnit_Delete(unit);
        }
    }
    BattleIconEnd();
    battleMenuDispEnd();
    BattleStageEnd();
    BattleAudience_End();
    BattleBreakSlot_End();
    menu = wp->commandMenu.menu;
    if (menu) {
        BattleFree(menu);
    }
    BattleFree(wp);
    _battleWorkPointer = NULL;
}

BOOL Btl_UnitSetup(BattleWork* wp) {
}
