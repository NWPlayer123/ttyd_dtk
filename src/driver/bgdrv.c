#include "driver/bgdrv.h"

#include "mario/mariost.h"

#include "driver/arcdrv.h"

//.bss
BackgroundWork work[2];

// Helper Macros
#define bgGetWork() (gp->inBattle ? &work[1] : &work[0])

void bgInit(void) {
    memset(&work[0], 0, sizeof(BackgroundWork));
    memset(&work[1], 0, sizeof(BackgroundWork));
}

void bgReInit(void) {
    BackgroundWork* wp = bgGetWork();
    memset(wp, 0, sizeof(BackgroundWork));
}
