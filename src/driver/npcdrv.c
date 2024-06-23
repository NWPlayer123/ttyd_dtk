#include "driver/npcdrv.h"

#include "mario/mariost.h"

// This is only here to make things easier to reference
typedef struct NPCWork2 {
    NPCWork field;  //0x0
    NPCWork battle; //0x14
} NPCWork2;

NPCWork2 work;

NPCWork* npcGetWorkPtr(void) {
    return gp->inBattle ? &work.battle : &work.field;
}

void npcInit(void) {
    NPCWork* wp = &work.field;
}
